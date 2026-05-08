#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
ROS 2 conversion of climbingrobot_controller2_real.py.

Notes:
- This is a best-effort ROS 2 port of the ROS 1 script.
- Core robotics/MPC/base_controllers logic is preserved where possible.
- You must update message/service package names if your ROS 2 interfaces live in
  cl_arganello_interface instead of climbingrobot_description.
- ROS 1-only helpers such as rosnode/rosmaster/rospkg/tf are replaced or removed.
"""

import os
import sys
import math
import signal
import numpy as np
from numpy import nan

import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from rclpy.executors import MultiThreadedExecutor
from std_msgs.msg import String
from geometry_msgs.msg import Vector3, TransformStamped
from std_srvs.srv import Trigger

from tf2_ros import TransformBroadcaster
import subprocess
import os
from ament_index_python.packages import get_package_share_directory



# If your ROS 2 package is cl_arganello_interface, replace these imports with:
# from cl_arganello_interface.msg import RopeCommand, PropellerCommand, RopeTelemetry, AlpineBodyTelemetry
# from cl_arganello_interface.srv import AlpineBodyCommand, RopeControlMode
from climbingrobot_description.msg import RopeCommand
from climbingrobot_description.msg import PropellerCommand
from climbingrobot_description.msg import RopeTelemetry
from climbingrobot_description.msg import AlpineBodyTelemetry
from climbingrobot_description.srv import AlpineBodyCommand
from climbingrobot_description.srv import RopeControlMode

# Project-specific dependencies preserved from ROS 1 version.
from base_controllers.utils.math_tools import *
from base_controllers.utils.math_tools import quaternion_matrix
from base_controllers.utils.ros_publish import RosPub
from base_controllers.utils.common_functions import plotJoint
from base_controllers.utils.common_functions import plotFrameLinear
from base_controllers.utils.matlab_conversions import mat_vector2python, mat_matrix2python
import base_controllers.params as conf

from termcolor import colored
import matplotlib.pyplot as plt
import scipy.io.matlab as mio

#TODO
#import matlab.engine

from base_controllers.orientation_controller import OrientationController

np.set_printoptions(threshold=np.inf, precision=5, linewidth=10000, suppress=True)

robotName = "climbingrobot2"


class ClimbingrobotController(Node):
    def __init__(self, robot_name=robotName):
        Node.__init__(self, "climbingrobot_controller")

        self.u = Utils()
        self.math_utils = Math()


        self.robot_name = robot_name
        self.EXTERNAL_FORCE = False
        self.landing = True
        self.MPC_control = True
        self.PLOT_MPC = False
        self.SAVE_BAG = False
        self.rope_index = np.array([2, 8])
        self.leg_index = np.array([12, 13, 14])
        self.wheel_index = np.array([16, 18])
        self.hip_pitch_joint = 12
        self.hip_roll_joint = 13
        self.base_passive_joints = np.array([3, 4, 5, 9, 10, 11])
        self.anchor_passive_joints = np.array([0, 1, 6, 7])
        self.OBSTACLE_AVOIDANCE = "mesh"

        #TODO
        # if self.MPC_control:
        #     sys.path.insert(0, "./codegen_mpc")
        #
        # if self.OBSTACLE_AVOIDANCE == "mesh":
        #     sys.path.insert(0, "./codegen_mesh")
        #     from base_controllers.components.terrain_manager import TerrainManager
        #     wall_depth = 1
        #     grid_size = 100
        #     max_ridge_depth = 0.5
        #     seed = "default"
        #     Lz = -20
        #     Ly = 5
        #     self.terrainManager = TerrainManager()
        #     self.mesh_x, self.mesh_y, self.mesh_z = self.terrainManager.generate_rock_wall_map(
        #         Lz, Ly, grid_size, wall_depth, max_ridge_depth, seed, x_offset=-0.5
        #     )
        # else:
        #     sys.path.insert(0, "./codegen")

        self.force_scale = 60.0
        self.mountain_thickness = 0.1
        self.r_leg = 0.3
        self.real_robot = conf.robot_params[robot_name]["real_robot"]



        self.qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            history=HistoryPolicy.KEEP_LAST,
            depth=1,
        )

        self.broadcaster = TransformBroadcaster(self)
        self.initVars()
        self.startRealRobotPublisherSubscribers()

        self.get_logger().info("Initialized ROS 2 climbingrobot controller")

    # ---------------- ROS 2 compatibility helpers ----------------

    def now_msg(self):
        return self.get_clock().now().to_msg()

    def call_service_sync(self, client, request, timeout_sec=3.0):
        if not client.wait_for_service(timeout_sec=timeout_sec):
            self.get_logger().error(f"Service not available: {client.srv_name}")
            return None
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self, future, timeout_sec=timeout_sec)
        if future.done():
            try:
                return future.result()
            except Exception as exc:
                self.get_logger().error(f"Service call failed: {exc}")
                return None
        self.get_logger().error(f"Service call timed out: {client.srv_name}")
        return None

    def send_transform(self, translation, rotation_xyzw, child_frame_id, parent_frame_id="world"):
        t = TransformStamped()
        t.header.stamp = self.now_msg()
        t.header.frame_id = parent_frame_id.strip("/")
        t.child_frame_id = child_frame_id.strip("/")
        t.transform.translation.x = float(translation[0])
        t.transform.translation.y = float(translation[1])
        t.transform.translation.z = float(translation[2])
        t.transform.rotation.x = float(rotation_xyzw[0])
        t.transform.rotation.y = float(rotation_xyzw[1])
        t.transform.rotation.z = float(rotation_xyzw[2])
        t.transform.rotation.w = float(rotation_xyzw[3])
        self.broadcaster.sendTransform(t)

    # ---------------- Original control methods ----------------

    def apply_propeller_command(self, prop_thrusts=None):
        if prop_thrusts is None:
            prop_thrusts = [0.0, 0.0, 0.0, 0.0]

        for i in range(4):
            self.ros_pub.add_arrow(
                self.base_pos + self.w_R_b @ self.orientControl.b_propeller_pos[i],
                self.orientControl.b_propeller_axes[i] * prop_thrusts[i] / self.force_scale,
                "blue",
                scale=1.5,
            )

        msg = PropellerCommand()
        msg.propeller_thrust_0 = float(prop_thrusts[0])
        msg.propeller_thrust_1 = float(prop_thrusts[1])
        msg.propeller_thrust_2 = float(prop_thrusts[2])
        msg.propeller_thrust_3 = float(prop_thrusts[3])
        self.pub_propeller_command.publish(msg)

    def getRobotMass(self):
        return 5.0

    def estimateRobotVelFromStates(self, l1, l2, psi, l1d, l2d, psid):
        if l1 != 0 and l2 != 0:
            px = l1 * np.sin(psi) * np.sqrt(
                1 - (self.anchor_distance_y ** 2 + l1 ** 2 - l2 ** 2) ** 2 /
                (4 * self.anchor_distance_y ** 2 * l1 ** 2)
            )
            py = (self.anchor_distance_y ** 2 + l1 ** 2 - l2 ** 2) / (2 * self.anchor_distance_y)
            pz = -l1 * np.cos(psi) * np.sqrt(
                1 - (self.anchor_distance_y ** 2 + l1 ** 2 - l2 ** 2) ** 2 /
                (4 * self.anchor_distance_y ** 2 * l1 ** 2)
            )
            px_l1 = px / l1
            n_pz_l1 = -pz / l1
            px_l1_sinpsi = px / l1 / math.sin(psi + 0.00001)
            py2b = py * 2 * self.anchor_distance_y
            pdx = l1d * px_l1 + l1 * n_pz_l1 * psid + (
                py2b * math.sin(psi) *
                (l1d * self.anchor_distance_y ** 2 - l1d * l1 ** 2 + 2 * l2d * l1 * l2 - l1d * l2 ** 2)
            ) / (4 * self.anchor_distance_y ** 2 * l1 ** 2 * px_l1_sinpsi)
            pdy = (l1 * l1d - l2 * l2d) / self.anchor_distance_y
            pdz = l1 * psid * px_l1 - l1d * n_pz_l1 - (
                py2b * math.cos(psi) *
                (l1d * self.anchor_distance_y ** 2 - l1d * l1 ** 2 + 2 * l2d * l1 * l2 - l1d * l2 ** 2)
            ) / (4 * self.anchor_distance_y ** 2 * l1 ** 2 * px_l1_sinpsi)
            return np.array([pdx, pdy, pdz])
        return np.zeros(3)

    def updateKinematicsDynamics(self):
        self.w_R_rope = quaternion_matrix(self.rope_l_imu_orientation)[:3, :3]
        self.w_R_b = quaternion_matrix(self.body_imu_orientation)[:3, :3]
        self.w_omega_b = self.body_imu_angular_velocity

        self.anchor_pos = np.array([
            conf.robot_params[self.robot_name]["spawn_x"],
            conf.robot_params[self.robot_name]["spawn_y"],
            conf.robot_params[self.robot_name]["spawn_z"],
        ])
        self.anchor_pos2 = np.array([
            conf.robot_params[self.robot_name]["spawn_2x"],
            conf.robot_params[self.robot_name]["spawn_2y"],
            conf.robot_params[self.robot_name]["spawn_2z"],
        ])
        self.anchor_distance_y = conf.robot_params[self.robot_name]["spawn_2y"] - conf.robot_params[self.robot_name]["spawn_y"]

        base_width = 0.1
        com_offset = self.w_R_b[2] * 0.1
        leg_length = 0.3
        x_rope_l_attach = self.anchor_pos + self.w_R_rope[0] * self.l_1
        self.base_pos = x_rope_l_attach + self.w_R_b[1] * (base_width / 2) + com_offset
        self.base_rpy = self.math_utils.rot2eul(self.w_R_b)
        self.x_ee = self.base_pos - self.w_R_b[0] * leg_length
        self.hoist_l_pos = self.base_pos + self.w_R_b.dot(np.array([0.0, -base_width / 2, 0.0]))
        self.hoist_r_pos = self.base_pos + self.w_R_b.dot(np.array([0.0, base_width / 2, 0.0]))

        self.rope_direction = (self.hoist_l_pos - self.anchor_pos) / np.linalg.norm(self.hoist_l_pos - self.anchor_pos)
        self.rope_direction2 = (self.hoist_r_pos - self.anchor_pos2) / np.linalg.norm(self.hoist_r_pos - self.anchor_pos2)

        self.mat2Gazebo = self.anchor_pos
        self.base_pos_mat = self.base_pos - self.mat2Gazebo
        self.hoist_distance = np.linalg.norm(self.hoist_l_pos - self.hoist_r_pos)

        self.psi = math.atan2(
            self.w_R_rope[0, 2],
            np.sqrt(self.w_R_rope[0, 0] ** 2 + self.w_R_rope[0, 1] ** 2),
        )
        extr_roll = math.atan2(-self.w_R_rope[1, 2], self.w_R_rope[2, 2])
        self.psi_d = np.cos(extr_roll) * self.w_omega_b[1] - np.sin(extr_roll) * self.w_omega_b[2]
        self.base_vel = self.estimateRobotVelFromStates(self.l_1, self.l_2, self.psi, self.l_1d, self.l_2d, self.psi_d)

        n_par = (self.anchor_pos - self.anchor_pos2) / np.linalg.norm(self.anchor_pos - self.anchor_pos2)
        rope2_axis = (self.base_pos - self.anchor_pos2) / np.linalg.norm(self.base_pos - self.anchor_pos2)
        self.n_bar = np.cross(n_par, rope2_axis) / np.linalg.norm(np.cross(n_par, rope2_axis))

        mountain_pos = np.array([-self.mountain_thickness / 2, conf.robot_params[self.robot_name]["spawn_y"], 0.0])
        self.send_transform(mountain_pos, [0.0, 0.0, 0.0, 1.0], "wall")
        self.send_transform(self.base_pos, self.body_imu_orientation, "base_link")

    def initVars(self):
        self.n_joints = len(conf.robot_params[self.robot_name]["joint_names"])
        self.q = np.zeros(self.n_joints)
        self.qd = np.zeros(self.n_joints)
        self.tau = np.zeros(self.n_joints)
        self.q_des = np.zeros(self.n_joints)
        self.qd_des = np.zeros(self.n_joints)
        self.tau_ffwd = np.zeros(self.n_joints)
        self.l_1 = 0.0
        self.l_2 = 0.0
        self.l_1d = 0.0
        self.l_2d = 0.0
        self.g = np.zeros(self.n_joints)
        self.x_ee = np.zeros(3)
        self.x_ee_des = np.zeros(3)
        self.contactForceW = np.zeros(3)
        self.contactMomentW = np.zeros(3)
        self.time = 0.0
        self.rope_l_imu_orientation = np.array([0, 0, 0, 1])
        self.rope_l_imu_angular_velocity = np.zeros(3)
        self.rope_l_imu_rpy = np.zeros(3)
        self.rope_l_imu_rpy_d = np.zeros(3)
        self.body_imu_orientation = np.array([0, 0, 0, 1])
        self.body_imu_rpy = np.zeros(3)
        self.body_imu_angular_velocity = np.zeros(3)
        self.w_base_vel = np.zeros(3)
        self.log_counter = 0
        self.qdd_des = np.zeros(self.n_joints)
        self.base_accel = np.zeros(3)
        self.base_rpy = np.zeros(3)
        self.Fr_l_fbk = 0.0
        self.Fr_r_fbk = 0.0
        self.Fr_l = 0.0
        self.Fr_r = 0.0
        self.prop_force_x = 0.0
        self.touch_down_detected_l = False
        self.touch_down_detected_r = False
        self.optimal_control_traj_finished = False
        self.MPC_tracking_error = []

        buffer_size = conf.robot_params[self.robot_name]["buffer_size"]
        self.q_des_log = np.empty((self.n_joints, buffer_size)) * nan
        self.q_log = np.empty((self.n_joints, buffer_size)) * nan
        self.qd_des_log = np.empty((self.n_joints, buffer_size)) * nan
        self.qd_log = np.empty((self.n_joints, buffer_size)) * nan
        self.tau_ffwd_log = np.empty((self.n_joints, buffer_size)) * nan
        self.tau_log = np.empty((self.n_joints, buffer_size)) * nan
        self.x_ee_log = np.empty((3, buffer_size)) * nan
        self.x_ee_des_log = np.empty((3, buffer_size)) * nan
        self.time_log = np.empty(buffer_size) * nan
        self.com_log = np.empty((3, buffer_size)) * nan
        self.simp_model_state_log = np.empty((3, buffer_size)) * nan
        self.base_pos_log = np.empty((3, buffer_size)) * nan
        self.base_rpy_log = np.empty((3, buffer_size)) * nan
        self.time_jump_log = np.empty(buffer_size) * nan
        self.Fr_l_log = np.empty(buffer_size) * nan
        self.Fr_r_log = np.empty(buffer_size) * nan
        self.Fr_l_fbk_log = np.empty(buffer_size) * nan
        self.Fr_r_fbk_log = np.empty(buffer_size) * nan
        self.l_1d_log = np.empty(buffer_size) * nan
        self.l_2d_log = np.empty(buffer_size) * nan
        self.psid_log = np.empty(buffer_size) * nan
        self.base_vel_log = np.empty((3, buffer_size)) * nan
        self.prop_force_x_log = np.empty(buffer_size) * nan
        self.contactForceW_log = np.empty((3, buffer_size)) * nan
        self.prop_thrusts = [0.0] * 4
        self.prop_thrusts_log = np.empty((4, buffer_size)) * nan

        self.q_des_q0 = conf.robot_params[self.robot_name]["q_0"]
        w_R_wall = self.math_utils.eul2Rot(np.array([0, -conf.robot_params[self.robot_name]["wall_inclination"], 0]))
        self.wall_normal = w_R_wall[:, 0].copy()
        self.mpc_index = 0
        self.mpc_index_old = 0
        self.mpc_index_ffwd = 0
        self.targetReceived = True

        propeller_orient = np.array([0.25 * np.pi, 0.75 * np.pi, np.pi + 0.25 * np.pi, np.pi + 0.75 * np.pi])
        self.orientControl = OrientationController(base_line_x=0.1, base_line_y=0.2, propeller_orient=propeller_orient)

    def logData(self):
        if self.log_counter < conf.robot_params[self.robot_name]["buffer_size"]:
            self.simp_model_state_log[:, self.log_counter] = np.array([self.psi, self.l_1, self.l_2])
            self.base_pos_log[:, self.log_counter] = self.base_pos
            self.base_rpy_log[:, self.log_counter] = self.base_rpy
            self.Fr_l_log[self.log_counter] = self.Fr_l
            self.Fr_r_log[self.log_counter] = self.Fr_r
            self.Fr_l_fbk_log[self.log_counter] = self.Fr_l_fbk
            self.Fr_r_fbk_log[self.log_counter] = self.Fr_r_fbk
            self.l_1d_log[self.log_counter] = self.l_1d
            self.l_2d_log[self.log_counter] = self.l_2d
            self.psid_log[self.log_counter] = self.psi_d
            self.base_vel_log[:, self.log_counter] = self.w_base_vel
            self.prop_force_x_log[self.log_counter] = self.prop_force_x
            self.prop_thrusts_log[:, self.log_counter] = self.prop_thrusts
        BaseControllerFixed.logData(self)

    def startRealRobot(self):
        self.get_logger().info("ROBOT IS REAL")

        #loads robot_description and launches the robot_state publisher
        self.launch_process = subprocess.Popen([
            "ros2", "launch",
            "climbingrobot_description",
            "upload_and_rviz.launch.py"
        ], preexec_fn=os.setsid)
        #subprocess.Popen(...), it is a separate OS process should be killed in finally
        # # rviz RViz does not require parameters to start
        # rviz_config = os.path.join(
        #     get_package_share_directory('climbingrobot_description'),
        #     'rviz',
        #     'conf.rviz'
        # )
        # self.rviz_process = subprocess.Popen([
        #     "ros2", "run",
        #     "rviz2", "rviz2",
        #     "-d", rviz_config
        # ])

    def startRealRobotPublisherSubscribers(self):
        self.ros_pub = RosPub(
            self.robot_name,
            only_visual=True,
            markers_time_to_live=0.0,
            node=self
        )
        # TODO
        #self.eng = matlab.engine.start_matlab()

        #TODO
        # if self.OBSTACLE_AVOIDANCE == "mesh":
        #     self.eng.addpath("./codegen_mesh", nargout=0)
        # else:
        #     self.eng.addpath("./codegen", nargout=0)
        # if self.MPC_control:
        #     self.eng.addpath("./codegen_mpc", nargout=0)

        self.sub_rope_telemetry_l = self.create_subscription(
            RopeTelemetry, "/winch/left/telemetry", self._receive_rope_telemetry_l, self.qos
        )
        self.sub_rope_telemetry_r = self.create_subscription(
            RopeTelemetry, "/winch/right/telemetry", self._receive_rope_telemetry_r, self.qos
        )
        self.pub_rope_command_l = self.create_publisher(RopeCommand, "/winch/left/command", self.qos)
        self.pub_rope_command_r = self.create_publisher(RopeCommand, "/winch/right/command", self.qos)

        self.rope_control_mode_l = self.create_client(RopeControlMode, "/winch/left/set_control_mode")
        self.rope_control_mode_r = self.create_client(RopeControlMode, "/winch/right/set_control_mode")

        self.sub_des_target = self.create_subscription(
            Vector3, "/planner/desired_target", self._receive_target, self.qos
        )
        self.pub_goal_status = self.create_publisher(String, "/planner/goal_status", self.qos)

        self.sub_alpine_telemetry = self.create_subscription(
            AlpineBodyTelemetry, "/alpine_body/telemetry", self._receive_alpine_telemetry, self.qos
        )
        self.pub_propeller_command = self.create_publisher(
            PropellerCommand, "/alpine_body/propeller_command", self.qos
        )
        self.alpine_command_service = self.create_client(AlpineBodyCommand, "/alpine_body/command")

    def _receive_rope_telemetry_l(self, msg):
        self.Fr_l_meas = msg.rope_force
        self.l_1 = msg.rope_length
        self.l_1d = msg.rope_velocity
        self.brake_status_l = msg.brake_status
        self.q[self.rope_index[1]] = self.l_1 + self.hoist_distance / 2 - self.anchor_distance_y / 2
        self.qd[self.rope_index[1]] = self.l_1d

    def _receive_rope_telemetry_r(self, msg):
        self.Fr_r_meas = msg.rope_force
        self.l_2 = msg.rope_length
        self.l_2d = msg.rope_velocity
        self.brake_status_r = msg.brake_status
        self.q[self.rope_index[0]] = self.l_2 + self.hoist_distance / 2 - self.anchor_distance_y / 2
        self.qd[self.rope_index[0]] = self.l_2d

    def _receive_target(self, msg):
        self.target = np.array([msg.x, msg.y, msg.z])
        self.targetReceived = True
        self.get_logger().info(f"received target {self.target}")

    def _receive_alpine_telemetry(self, msg):
        self.rope_l_imu_orientation = np.array([
            msg.rope_imu_orientation.x,
            msg.rope_imu_orientation.y,
            msg.rope_imu_orientation.z,
            msg.rope_imu_orientation.w,
        ])
        self.rope_l_imu_angular_velocity = np.array([
            msg.rope_imu_angular_velocity.x,
            msg.rope_imu_angular_velocity.y,
            msg.rope_imu_angular_velocity.z,
        ])
        self.rope_l_imu_rpy = np.array([msg.rope_imu_rpy.x, msg.rope_imu_rpy.y, msg.rope_imu_rpy.z])
        self.rope_l_imu_rpy_d = np.array([msg.rope_imu_rpy_d.x, msg.rope_imu_rpy_d.y, msg.rope_imu_rpy_d.z])
        self.body_imu_orientation = np.array([
            msg.body_imu_orientation.x,
            msg.body_imu_orientation.y,
            msg.body_imu_orientation.z,
            msg.body_imu_orientation.w,
        ])
        self.body_imu_rpy = np.array([msg.body_imu_rpy.x, msg.body_imu_rpy.y, msg.body_imu_rpy.z])
        self.body_imu_angular_velocity = np.array([
            msg.body_imu_angular_velocity.x,
            msg.body_imu_angular_velocity.y,
            msg.body_imu_angular_velocity.z,
        ])

    def print_message(self, message="", decimate=1000):
        if not hasattr(self, "print_counter"):
            self.print_counter = 0
        if np.mod(self.print_counter, decimate) == 0:
            self.get_logger().info(message)
        self.print_counter += 1

    def setRopeControlMode(self, mode="idle"):
        req = RopeControlMode.Request()
        req.mode = mode
        resp_l = self.call_service_sync(self.rope_control_mode_l, req)
        resp_r = self.call_service_sync(self.rope_control_mode_r, req)
        ok = resp_l is not None and resp_r is not None
        if ok:
            self.get_logger().info(f"Set rope control mode: {mode}")
        return ok

    def send_des_jstate(self, q_des, qd_des, tau_ffwd):
        if not self.real_robot:
            return

        msg_l = RopeCommand()
        msg_l.rope_force = float(tau_ffwd[self.rope_index[1]])
        msg_l.rope_position = float(q_des[self.rope_index[1]])
        msg_l.rope_velocity = float(qd_des[self.rope_index[1]])
        if hasattr(msg_l, "stamp"):
            msg_l.stamp = self.now_msg()
        self.pub_rope_command_l.publish(msg_l)

        msg_r = RopeCommand()
        msg_r.rope_force = float(tau_ffwd[self.rope_index[0]])
        msg_r.rope_position = float(q_des[self.rope_index[0]])
        msg_r.rope_velocity = float(qd_des[self.rope_index[0]])
        if hasattr(msg_r, "stamp"):
            msg_r.stamp = self.now_msg()
        self.pub_rope_command_r.publish(msg_r)

    def resetRope(self):
        self.get_logger().info("Start Position Mode")
        self.q_des[self.rope_index[0]] = np.copy(self.q[self.rope_index[0]])
        self.q_des[self.rope_index[1]] = np.copy(self.q[self.rope_index[1]])
        self.Fr_r = 0.0
        self.Fr_l = 0.0
        self.tau_ffwd[self.rope_index] = np.zeros(2)
        self.setRopeControlMode("closed_loop_position")

    # Keep your existing computeJointVariables, initOptim, computeMPC, plotting functions
    # from the ROS 1 file below this point. They are mostly ROS-version independent,
    # except where they call ros.loginfo, ros.Time.now, or ROS 1 publishers/services.


def main(args=None):
    rclpy.init(args=args)
    node = ClimbingrobotController(robotName)
    node.startRealRobot()

    # Initial setup from original talker().
    p0 = np.array([0.28, 2.5, -6.10104])
    node.target = np.array([0.28, 4.0, -4.0])
    node.q_des = np.copy(node.q_des_q0)

    dt = conf.robot_params[node.robot_name]["dt"]
    rate = node.create_rate(1.0 / dt)

    node.updateKinematicsDynamics()
    node.startJump = 2.5
    node.stateMachine = "idle"
    node.jumpNumber = 0
    node.numberOfJumps = 1
    node.start_logging = np.inf

    # Uncomment after adding computeJointVariables from original file.
    # node.q_des[:12] = node.computeJointVariables(p0)
    node.setRopeControlMode("closed_loop_position")

    executor = MultiThreadedExecutor()
    executor.add_node(node)

    try:
        while rclpy.ok():
            executor.spin_once(timeout_sec=0.0)
            node.updateKinematicsDynamics()
            print("AAA")
            node.send_des_jstate(node.q_des, node.qd_des, node.tau_ffwd)
            node.time = np.round(node.time + np.array([dt]), 4)

            if node.time > node.start_logging:
                node.logData()

            rate.sleep()

    except KeyboardInterrupt:
        pass

    finally:
        try:
            executor.remove_node(node)
        except Exception:
            pass

        try:
            node.destroy_node()
        except Exception:
            pass

        try:
            if rclpy.get_default_context().ok():
                rclpy.shutdown()
        except Exception:
            pass

if __name__ == "__main__":
    main()
