#!/usr/bin/env python3
import math
from typing import Optional, Tuple

import numpy as np
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Point, PoseStamped, TransformStamped, Vector3
from nav_msgs.msg import Odometry
from std_msgs.msg import Float32MultiArray
from tf2_ros import TransformBroadcaster

from cl_arganello_interface.msg import RopeTelemetry


def quat_to_rot(qxyzw: np.ndarray) -> np.ndarray:
    x, y, z, w = qxyzw
    xx, yy, zz = x * x, y * y, z * z
    xy, xz, yz = x * y, x * z, y * z
    wx, wy, wz = w * x, w * y, w * z
    return np.array([
        [1.0 - 2.0 * (yy + zz), 2.0 * (xy - wz),       2.0 * (xz + wy)],
        [2.0 * (xy + wz),       1.0 - 2.0 * (xx + zz), 2.0 * (yz - wx)],
        [2.0 * (xz - wy),       2.0 * (yz + wx),       1.0 - 2.0 * (xx + yy)],
    ], dtype=float)


def normalize(v: np.ndarray, fallback: Optional[np.ndarray] = None) -> np.ndarray:
    n = np.linalg.norm(v)
    if n < 1e-9:
        return fallback.copy() if fallback is not None else np.array([1.0, 0.0, 0.0], dtype=float)
    return v / n


class AlpineOdometryNode(Node):
    """
    Odometry node for ALPINE using:
      - left rope telemetry
      - right rope telemetry
      - dongle telemetry: [epoch_ms, imu1[11], imu2[11]]

    Assumed IMU ordering from onboard firmware:
      imu1 = body IMU
      imu2 = rope IMU

    Each IMU block format comes from Movella::printCSV():
      q0,q1,q2,q3,ax,ay,az,gx,gy,gz,id

    Geometry used here:
      - left hoist comes from left anchor + left rope direction * l1
      - body pose/orientation comes from body IMU + known body offset from left hoist
      - right hoist is reconstructed from body +Y direction and right rope length
    """

    def __init__(self):
        super().__init__('alpine_odometry_node')

        # Frames / pubs
        self.declare_parameter('world_frame', 'world')
        self.declare_parameter('base_frame', 'base_link')
        self.declare_parameter('publish_tf', True)
        self.declare_parameter('publish_rate_hz', 100.0)

        # Anchors in world
        self.declare_parameter('anchor_left_xyz', [0.0, 0.0, 0.0])
        self.declare_parameter('anchor_right_xyz', [0.0, 5.0, 0.0])

        # Robot geometry
        self.declare_parameter('base_width_m', 0.10)
        self.declare_parameter('body_origin_from_left_hoist_xyz', [0.0, 0.05, 0.10])

        # Rope convention / homing
        self.declare_parameter('left_home_offset_m', 0.0)
        self.declare_parameter('right_home_offset_m', 0.0)
        self.declare_parameter('right_is_zeroed', False)

        # Rope IMU axis along the rope
        self.declare_parameter('left_rope_axis', 'x')

        # Topics
        self.declare_parameter('left_rope_topic', '/winch/left/telemetry')
        self.declare_parameter('right_rope_topic', '/winch/right/telemetry')
        self.declare_parameter('dongle_topic', '/alpine/dongle/telemetry')

        # Read params
        self.world_frame = str(self.get_parameter('world_frame').value)
        self.base_frame = str(self.get_parameter('base_frame').value)
        self.publish_tf = bool(self.get_parameter('publish_tf').value)
        self.publish_rate_hz = float(self.get_parameter('publish_rate_hz').value)

        self.anchor_left = np.array(self.get_parameter('anchor_left_xyz').value, dtype=float)
        self.anchor_right = np.array(self.get_parameter('anchor_right_xyz').value, dtype=float)

        self.base_width = float(self.get_parameter('base_width_m').value)
        self.body_origin_from_left_hoist = np.array(
            self.get_parameter('body_origin_from_left_hoist_xyz').value, dtype=float
        )

        self.left_home_offset_m = float(self.get_parameter('left_home_offset_m').value)
        self.right_home_offset_m = float(self.get_parameter('right_home_offset_m').value)
        self.right_is_zeroed = bool(self.get_parameter('right_is_zeroed').value)

        self.left_rope_axis = str(self.get_parameter('left_rope_axis').value)

        left_rope_topic = str(self.get_parameter('left_rope_topic').value)
        right_rope_topic = str(self.get_parameter('right_rope_topic').value)
        dongle_topic = str(self.get_parameter('dongle_topic').value)

        # State
        self.left_rope_msg: Optional[RopeTelemetry] = None
        self.right_rope_msg: Optional[RopeTelemetry] = None
        self.epoch_ms: Optional[float] = None

        self.body_quat_xyzw: Optional[np.ndarray] = None
        self.body_acc: Optional[np.ndarray] = None
        self.body_gyro: Optional[np.ndarray] = None

        self.rope_quat_xyzw: Optional[np.ndarray] = None
        self.rope_acc: Optional[np.ndarray] = None
        self.rope_gyro: Optional[np.ndarray] = None

        self.last_base_pos: Optional[np.ndarray] = None
        self.last_stamp_s: Optional[float] = None

        # IO
        self.create_subscription(RopeTelemetry, left_rope_topic, self._cb_left_rope, 10)
        self.create_subscription(RopeTelemetry, right_rope_topic, self._cb_right_rope, 10)
        self.create_subscription(Float32MultiArray, dongle_topic, self._cb_dongle, 10)

        self.pub_odom = self.create_publisher(Odometry, '/odom', 10)
        self.pub_pose = self.create_publisher(PoseStamped, '/alpine/odometry/pose', 10)
        self.pub_debug = self.create_publisher(Float32MultiArray, '/alpine/odometry/debug', 10)
        self.tf_broadcaster = TransformBroadcaster(self) if self.publish_tf else None

        dt = max(1.0 / max(self.publish_rate_hz, 1.0), 0.001)
        self.timer = self.create_timer(dt, self._update)

        self.get_logger().info('alpine_odometry_node started')
        self.get_logger().info('Expected dongle layout: [epoch_ms, imu1(11)=body, imu2(11)=rope]')

    def _cb_left_rope(self, msg: RopeTelemetry):
        self.left_rope_msg = msg

    def _cb_right_rope(self, msg: RopeTelemetry):
        self.right_rope_msg = msg

    def _parse_imu_block(self, vals: np.ndarray) -> Tuple[np.ndarray, np.ndarray, np.ndarray]:
        # q0,q1,q2,q3,ax,ay,az,gx,gy,gz,id
        # Firmware pitch function uses getQuaternion(q) as WXYZ.
        q_wxyz = vals[0:4].astype(float)
        acc = vals[4:7].astype(float)
        gyro = vals[7:10].astype(float)

        q_xyzw = np.array([q_wxyz[1], q_wxyz[2], q_wxyz[3], q_wxyz[0]], dtype=float)
        return q_xyzw, acc, gyro

    def _cb_dongle(self, msg: Float32MultiArray):
        data = np.array(msg.data, dtype=float)
        if data.size < 23:
            return

        self.epoch_ms = float(data[0])

        imu1 = data[1:12]
        imu2 = data[12:23]

        self.body_quat_xyzw, self.body_acc, self.body_gyro = self._parse_imu_block(imu1)
        self.rope_quat_xyzw, self.rope_acc, self.rope_gyro = self._parse_imu_block(imu2)

    def _effective_lengths(self) -> Tuple[float, float]:
        l1 = 0.0 if self.left_rope_msg is None else float(self.left_rope_msg.rope_length)
        l2 = 0.0 if self.right_rope_msg is None else float(self.right_rope_msg.rope_length)

        l1_eff = l1 + self.left_home_offset_m
        l2_eff = l2 + self.right_home_offset_m if self.right_is_zeroed else l2 + self.right_home_offset_m
        return l1_eff, l2_eff

    def _axis_vector_from_rot(self, R: np.ndarray, axis_name: str) -> np.ndarray:
        axis_name = axis_name.strip().lower()
        mapping = {
            'x': R[:, 0],
            '-x': -R[:, 0],
            'y': R[:, 1],
            '-y': -R[:, 1],
            'z': R[:, 2],
            '-z': -R[:, 2],
        }
        return normalize(mapping.get(axis_name, R[:, 0]))

    def _solve_right_hoist(self, hoist_l: np.ndarray, R_body: np.ndarray, l2_eff: float) -> Tuple[np.ndarray, float]:
        d = normalize(R_body[:, 1], fallback=np.array([0.0, 1.0, 0.0], dtype=float))
        p = hoist_l - self.anchor_right

        a = float(np.dot(d, d))
        b = 2.0 * float(np.dot(p, d))
        c = float(np.dot(p, p) - l2_eff * l2_eff)

        disc = b * b - 4.0 * a * c
        if disc < 0.0:
            t = self.base_width
            return hoist_l + t * d, float('nan')

        sqrt_disc = math.sqrt(disc)
        t1 = (-b + sqrt_disc) / (2.0 * a)
        t2 = (-b - sqrt_disc) / (2.0 * a)

        candidates = [t1, t2]
        positive = [t for t in candidates if t >= 0.0]
        if positive:
            t = min(positive, key=lambda x: abs(x - self.base_width))
        else:
            t = min(candidates, key=lambda x: abs(x - self.base_width))

        return hoist_l + t * d, t

    def _update(self):
        if (
            self.left_rope_msg is None or
            self.right_rope_msg is None or
            self.body_quat_xyzw is None or
            self.rope_quat_xyzw is None
        ):
            return

        l1_eff, l2_eff = self._effective_lengths()

        R_body = quat_to_rot(self.body_quat_xyzw)
        R_rope = quat_to_rot(self.rope_quat_xyzw)

        rope_dir_l = self._axis_vector_from_rot(R_rope, self.left_rope_axis)
        hoist_l = self.anchor_left + rope_dir_l * l1_eff
        hoist_r, solved_width = self._solve_right_hoist(hoist_l, R_body, l2_eff)

        base_pos = hoist_l + (R_body @ self.body_origin_from_left_hoist)

        stamp_s = (self.epoch_ms or 0.0) * 1e-3
        lin_vel = np.zeros(3, dtype=float)
        if self.last_base_pos is not None and self.last_stamp_s is not None:
            dt = stamp_s - self.last_stamp_s
            if dt > 1e-4:
                lin_vel = (base_pos - self.last_base_pos) / dt

        self.last_base_pos = base_pos.copy()
        self.last_stamp_s = stamp_s

        now = self.get_clock().now().to_msg()

        pose = PoseStamped()
        pose.header.stamp = now
        pose.header.frame_id = self.world_frame
        pose.pose.position = Point(x=float(base_pos[0]), y=float(base_pos[1]), z=float(base_pos[2]))
        pose.pose.orientation.x = float(self.body_quat_xyzw[0])
        pose.pose.orientation.y = float(self.body_quat_xyzw[1])
        pose.pose.orientation.z = float(self.body_quat_xyzw[2])
        pose.pose.orientation.w = float(self.body_quat_xyzw[3])
        self.pub_pose.publish(pose)

        odom = Odometry()
        odom.header.stamp = now
        odom.header.frame_id = self.world_frame
        odom.child_frame_id = self.base_frame
        odom.pose.pose = pose.pose
        odom.twist.twist.linear = Vector3(x=float(lin_vel[0]), y=float(lin_vel[1]), z=float(lin_vel[2]))
        if self.body_gyro is not None:
            odom.twist.twist.angular = Vector3(
                x=float(self.body_gyro[0]), y=float(self.body_gyro[1]), z=float(self.body_gyro[2])
            )
        self.pub_odom.publish(odom)

        if self.tf_broadcaster is not None:
            t = TransformStamped()
            t.header.stamp = now
            t.header.frame_id = self.world_frame
            t.child_frame_id = self.base_frame
            t.transform.translation.x = float(base_pos[0])
            t.transform.translation.y = float(base_pos[1])
            t.transform.translation.z = float(base_pos[2])
            t.transform.rotation = pose.pose.orientation
            self.tf_broadcaster.sendTransform(t)

        hoist_dist = float(np.linalg.norm(hoist_r - hoist_l))
        width_error = hoist_dist - self.base_width
        right_anchor_error = abs(float(np.linalg.norm(hoist_r - self.anchor_right)) - l2_eff)

        dbg = Float32MultiArray()
        dbg.data = [
            float(self.epoch_ms or 0.0),
            float(l1_eff), float(l2_eff),
            float(hoist_l[0]), float(hoist_l[1]), float(hoist_l[2]),
            float(hoist_r[0]), float(hoist_r[1]), float(hoist_r[2]),
            float(base_pos[0]), float(base_pos[1]), float(base_pos[2]),
            float(hoist_dist),
            float(width_error),
            float(solved_width) if math.isfinite(solved_width) else float('nan'),
            float(right_anchor_error),
        ]
        self.pub_debug.publish(dbg)


def main(args=None):
    rclpy.init(args=args)
    node = AlpineOdometryNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
