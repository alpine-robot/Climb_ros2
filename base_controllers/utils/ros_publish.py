import rclpy
from rclpy.node import Node
from builtin_interfaces.msg import Duration

from sensor_msgs.msg import JointState
from visualization_msgs.msg import Marker, MarkerArray
from geometry_msgs.msg import Point

import numpy as np
import pinocchio as pin


class RosPub:
    def __init__(
        self,
        robot_name="solo",
        only_visual=False,
        visual_frame="world",
        markers_time_to_live=0.0,
        node=None,
    ):
        print("Starting ROS 2 pub ---------------------------------------------------------------")

        self.owns_node = False

        if node is None:
            if not rclpy.ok():
                rclpy.init()
            self.node = Node("sub_pub_node_python")
            self.owns_node = True
        else:
            self.node = node

        self.markers_time_to_live = markers_time_to_live
        self.visual_frame = visual_frame
        self.fixedBaseRobot = False

        qos = 1

        if not only_visual:
            self.joint_pub = self.node.create_publisher(
                JointState,
                "/joint_states",
                qos
            )

        self.marker_pub = self.node.create_publisher(MarkerArray, "/vis", qos)
        self.arrow_pub = self.node.create_publisher(MarkerArray, "/arrow", qos)
        self.polygon_pub = self.node.create_publisher(MarkerArray, "/support_polygon", qos)
        self.mesh_pub = self.node.create_publisher(MarkerArray, "/mesh", qos)
        self.marker_fixed_pub = self.node.create_publisher(MarkerArray, "/point_fixed", qos)

        self.markerArray = MarkerArray()
        self.markerArray_arrows = MarkerArray()
        self.markerArray_polygon = MarkerArray()
        self.markerArrayFixed = MarkerArray()
        self.markerArray_mesh = MarkerArray()

        self.id = 0
        self.id_arrow = 0
        self.id_polygon = 0
        self.id_fixed = 0
        self.id_mesh = 0

        print("Initialized ROS 2 pub ---------------------------------------------------------------")

    def _duration(self):
        sec = int(self.markers_time_to_live)
        nanosec = int((self.markers_time_to_live - sec) * 1e9)
        return Duration(sec=sec, nanosec=nanosec)

    def _stamp(self):
        return self.node.get_clock().now().to_msg()

    def _set_color(self, marker, color, alpha=1.0):
        if isinstance(color, np.ndarray):
            marker.color.r = float(color[0])
            marker.color.g = float(color[1])
            marker.color.b = float(color[2])
        else:
            colors = {
                "red": (1.0, 0.0, 0.0),
                "green": (0.0, 1.0, 0.0),
                "blue": (0.0, 0.0, 1.0),
                "purple": (0.7, 0.0, 1.0),
                "white": (1.0, 1.0, 1.0),
                "black": (0.0, 0.0, 0.0),
            }
            r, g, b = colors.get(color, (1.0, 0.0, 0.0))
            marker.color.r = r
            marker.color.g = g
            marker.color.b = b

        marker.color.a = float(alpha)

    def publish(self, robot, q, qd=None, tau=None):
        if qd is None:
            qd = np.zeros(robot.nv)
        if tau is None:
            tau = np.zeros(robot.nv)

        msg = JointState()
        msg.header.stamp = self._stamp()

        all_names = [name for name in robot.model.names]

        try:
            self.fixedBaseRobot = robot.nq == robot.nv
        except Exception:
            self.fixedBaseRobot = True

        msg.name = all_names[-robot.na:]
        msg.position = list(q)
        msg.velocity = list(qd)
        msg.effort = list(tau)

        self.joint_pub.publish(msg)
        self.publishVisual()

    def publishVisual(self, delete_markers=True):
        if len(self.markerArray.markers) > 0:
            self.marker_pub.publish(self.markerArray)
            self.markerArray.markers.clear()
            self.id = 0

        if len(self.markerArray_arrows.markers) > 0:
            self.arrow_pub.publish(self.markerArray_arrows)
            self.markerArray_arrows.markers.clear()
            self.id_arrow = 0

        if len(self.markerArray_polygon.markers) > 0:
            self.polygon_pub.publish(self.markerArray_polygon)
            self.markerArray_polygon.markers.clear()
            self.id_polygon = 0

        if len(self.markerArrayFixed.markers) > 0:
            self.marker_fixed_pub.publish(self.markerArrayFixed)
            self.markerArrayFixed.markers.clear()
            self.id_fixed = 0

        if len(self.markerArray_mesh.markers) > 0:
            self.mesh_pub.publish(self.markerArray_mesh)
            self.markerArray_mesh.markers.clear()
            self.id_mesh = 0

        if delete_markers:
            self.delete_all_markers()

    def add_marker(self, pos, radius=0.1, color="red", alpha=0.5):
        marker = Marker()
        marker.header.frame_id = self.visual_frame
        marker.header.stamp = self._stamp()
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD
        marker.scale.x = float(radius)
        marker.scale.y = float(radius)
        marker.scale.z = float(radius)
        self._set_color(marker, color, alpha)

        marker.pose.orientation.w = 1.0
        marker.pose.position.x = float(pos[0])
        marker.pose.position.y = float(pos[1])
        marker.pose.position.z = float(pos[2])
        marker.lifetime = self._duration()

        marker.id = self.id
        self.id += 1
        self.markerArray.markers.append(marker)

    def add_plane(self, pos=np.array([0, 0, 0]), orient=np.array([0, 0, 0]), color="red", alpha=0.5):
        marker = Marker()
        marker.header.frame_id = self.visual_frame
        marker.header.stamp = self._stamp()
        marker.type = Marker.CUBE
        marker.action = Marker.ADD

        marker.scale.x = 100.0
        marker.scale.y = 100.0
        marker.scale.z = 0.1

        self._set_color(marker, color, alpha)

        quaternion = pin.Quaternion(pin.rpy.rpyToMatrix(orient))
        marker.pose.orientation.x = float(quaternion.x)
        marker.pose.orientation.y = float(quaternion.y)
        marker.pose.orientation.z = float(quaternion.z)
        marker.pose.orientation.w = float(quaternion.w)

        marker.pose.position.x = float(pos[0])
        marker.pose.position.y = float(pos[1])
        marker.pose.position.z = float(pos[2])
        marker.lifetime = self._duration()

        marker.id = self.id
        self.id += 1
        self.markerArray.markers.append(marker)

    def add_marker_fixed(self, pos, radius=0.01, color="red"):
        marker = Marker()
        marker.header.frame_id = self.visual_frame
        marker.header.stamp = self._stamp()
        marker.type = Marker.SPHERE
        marker.action = Marker.ADD

        marker.scale.x = float(radius)
        marker.scale.y = float(radius)
        marker.scale.z = float(radius)

        self._set_color(marker, color, 0.5)

        marker.pose.orientation.w = 1.0
        marker.pose.position.x = float(pos[0])
        marker.pose.position.y = float(pos[1])
        marker.pose.position.z = float(pos[2])
        marker.lifetime = self._duration()

        marker.id = self.id_fixed
        self.id_fixed += 1
        self.markerArrayFixed.markers.append(marker)

    def add_arrow(self, start, vector, color="green", scale=1.0, alpha=1.0):
        marker = Marker()
        marker.header.frame_id = self.visual_frame
        marker.header.stamp = self._stamp()
        marker.type = Marker.ARROW
        marker.action = Marker.ADD

        self._set_color(marker, color, alpha)

        marker.points.append(Point(x=float(start[0]), y=float(start[1]), z=float(start[2])))
        marker.points.append(Point(
            x=float(start[0] + vector[0]),
            y=float(start[1] + vector[1]),
            z=float(start[2] + vector[2]),
        ))

        marker.scale.x = 0.02 * scale
        marker.scale.y = 0.04 * scale
        marker.scale.z = 0.02 * scale

        marker.lifetime = self._duration()
        marker.pose.orientation.w = 1.0

        marker.id = self.id_arrow
        self.id_arrow += 1
        self.markerArray_arrows.markers.append(marker)

    def add_mesh(self, package=None, mesh_path="", position=np.zeros(3), color="green", alpha=1.0):
        marker = Marker()
        marker.header.frame_id = self.visual_frame
        marker.header.stamp = self._stamp()
        marker.type = Marker.MESH_RESOURCE
        marker.action = Marker.ADD

        if color is None:
            self._set_color(marker, "white", 1.0)
        else:
            self._set_color(marker, color, alpha)

        if package is not None:
            marker.mesh_resource = "package://" + package + mesh_path
        else:
            marker.mesh_resource = "file://" + mesh_path

        marker.mesh_use_embedded_materials = True

        marker.scale.x = 1.0
        marker.scale.y = 1.0
        marker.scale.z = 1.0

        marker.pose.position.x = float(position[0])
        marker.pose.position.y = float(position[1])
        marker.pose.position.z = float(position[2])
        marker.pose.orientation.w = 1.0

        marker.lifetime = self._duration()

        marker.id = self.id_mesh
        self.id_mesh += 1
        self.markerArray_mesh.markers.append(marker)

    def add_polygon(self, points, color="green", scale=1.0, visual_frame="world"):
        marker = Marker()
        marker.header.frame_id = self.visual_frame if visual_frame is None else visual_frame
        marker.header.stamp = self._stamp()
        marker.type = Marker.LINE_STRIP
        marker.action = Marker.ADD

        self._set_color(marker, color, 1.0)

        for p in points:
            marker.points.append(Point(x=float(p[0]), y=float(p[1]), z=float(p[2])))

        marker.scale.x = 0.01 * scale
        marker.scale.y = 0.01 * scale
        marker.scale.z = 0.01 * scale

        marker.lifetime = self._duration()
        marker.pose.orientation.w = 1.0

        marker.id = self.id_polygon
        self.id_polygon += 1
        self.markerArray_polygon.markers.append(marker)

    def delete_all_markers(self):
        marker_array_msg = MarkerArray()
        marker = Marker()
        marker.action = Marker.DELETEALL
        marker_array_msg.markers.append(marker)

        self.marker_pub.publish(marker_array_msg)
        self.arrow_pub.publish(marker_array_msg)
        self.polygon_pub.publish(marker_array_msg)
        self.mesh_pub.publish(marker_array_msg)

    def add_cone(self, origin, normal, friction_coeff, height=0.05, color="green"):
        radius = friction_coeff * height
        tail_end = origin + normal * height

        marker = Marker()
        marker.header.frame_id = self.visual_frame
        marker.header.stamp = self._stamp()
        marker.type = Marker.ARROW
        marker.action = Marker.ADD

        self._set_color(marker, color, 0.7)

        marker.points.append(Point(x=float(tail_end[0]), y=float(tail_end[1]), z=float(tail_end[2])))
        marker.points.append(Point(x=float(origin[0]), y=float(origin[1]), z=float(origin[2])))

        marker.scale.x = 0.0
        marker.scale.y = 2.0 * radius
        marker.scale.z = height

        marker.lifetime = self._duration()
        marker.pose.orientation.w = 1.0

        marker.id = self.id
        self.id += 1
        self.markerArray.markers.append(marker)

    def deregister_node(self):
        print("---------------------------------------------------------------")
        if self.owns_node:
            self.node.destroy_node()
            rclpy.shutdown()

    def isShuttingDown(self):
        return not rclpy.ok()