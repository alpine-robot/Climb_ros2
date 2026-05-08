# -*- coding: utf-8 -*-
"""
ROS 2 conversion of common_functions.py / generated_commons.py helpers.

Converted from ROS 1 APIs:
- rospy -> rclpy
- rospkg -> ament_index_python
- roslaunch / rosrun -> subprocess calls to ros2 launch / ros2 run
- gazebo_ros spawn_model -> gazebo_ros spawn_entity.py
- ROS 1 parameter server usage -> ROS 2 node parameters where applicable
- tf2_ros broadcaster constructors updated for ROS 2

Notes:
- ROS 2 has no global parameter server like ROS 1. Pass a node to functions that need parameters/time.
- Plotting functions are ROS-independent and can be kept from the original file.
"""

import os
import sys
import copy
import subprocess
from operator import itemgetter

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon
from matplotlib.collections import PatchCollection
from termcolor import colored

import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from ament_index_python.packages import get_package_share_directory

import tf2_ros
from geometry_msgs.msg import TransformStamped

import pinocchio
from base_controllers.utils.custom_robot_wrapper import RobotWrapper
from base_controllers.utils.utils import Utils

# make plot interactive
plt.ion()
plt.close()

lw_des = 7
lw_act = 4
marker_size = 0

u = Utils()

labels_ur = ["1 - Shoulder Pan", "2 - Shoulder Lift", "3 - Elbow", "4 - Wrist 1", "5 - Wrist 2", "6 - Wrist 3"]
labels_quadruped = ["LF_HAA", "LF_HFE", "LF_KFE", "LH_HAA", "LH_HFE", "LH_KFE", "RF_HAA", "RF_HFE", "RF_KFE", "RH_HAA", "RH_HFE", "RH_KFE"]
labels_flywheel2 = labels_quadruped + ["left_wheel", "right_wheel"]
labels_flywheel4 = labels_quadruped + ["back_wheel", "front_wheel", "left_wheel", "right_wheel"]


class Twist:
    def __init__(self):
        self.linear = np.empty((3)) * np.nan
        self.angular = np.empty((3)) * np.nan

    def set(self, value):
        self.linear = copy.deepcopy(value[:3])
        self.angular = copy.deepcopy(value[3:])


class Pose:
    def __init__(self):
        self.position = np.empty((3)) * np.nan
        self.orientation = np.empty((3)) * np.nan

    def set(self, value):
        self.position = copy.deepcopy(value[:3])
        self.orientation = copy.deepcopy(value[3:])


class State:
    def __init__(self, desired=False):
        self.pose = Pose()
        self.twist = Twist()
        if desired:
            self.accel = Twist()

    def set(self, value):
        self.pose.set(value.getPose())
        self.twist.set(value.getTwist())

    def getPose(self):
        return np.hstack([self.pose.position, self.pose.orientation])

    def getTwist(self):
        return np.hstack([self.twist.linear, self.twist.angular])


def checkRosMaster():
    """ROS 2 replacement for checking ROS master.

    ROS 2 has no roscore/master. This only checks whether rclpy was initialized.
    """
    if rclpy.ok():
        print(colored("ROS 2 context is initialized", "red"))
    else:
        print(colored("ROS 2 is not initialized. Call rclpy.init() first.", "red"))


def launchFileNode(package, launch_file, additional_args=None):
    """Launch a ROS 2 launch file.

    additional_args example: ["robot_name:=climbingrobot2", "use_sim_time:=true"]
    """
    cmd = ["ros2", "launch", package, launch_file]
    if additional_args is not None:
        cmd.extend(additional_args)
    return subprocess.Popen(cmd)


def launchFileGeneric(launch_file):
    """Launch a ROS 2 launch file by path.

    Prefer launchFileNode(package, launch_file) when possible.
    """
    return subprocess.Popen(["ros2", "launch", launch_file])


def startNode(package, executable, args=None):
    """Start a ROS 2 executable as a subprocess.

    Example:
        startNode("rviz2", "rviz2", ["-d", rviz_config])
    """
    if args is None:
        args = []
    if isinstance(args, str):
        args = args.split()
    cmd = ["ros2", "run", package, executable] + list(args)
    return subprocess.Popen(cmd)


def loadXacro(package_name, model_name, node=None, robots_subdir="robots"):
    """Load a xacro from a ROS 2 package and optionally store it as a node parameter."""
    print(colored(f"Loading xacro for {model_name} inside {package_name}", "blue"))

    package_path = get_package_share_directory(package_name)
    xacro_path = os.path.join(package_path, robots_subdir, model_name + ".urdf.xacro")

    if not os.path.isfile(xacro_path):
        print(colored(f"Xacro file {xacro_path} does not exist!", "red"))
        return None

    command = ["xacro", xacro_path]
    try:
        robot_description = subprocess.check_output(command, stderr=subprocess.STDOUT).decode("utf-8")
    except subprocess.CalledProcessError as process_error:
        print("Failed to run xacro command:")
        print(process_error.output.decode("utf-8", errors="replace"))
        sys.exit(1)

    if node is not None:
        if not node.has_parameter(model_name):
            node.declare_parameter(model_name, robot_description)
        else:
            node.set_parameters([Parameter(model_name, value=robot_description)])

    return robot_description


def spawnModel(package_name, model_name="", spawn_pos=np.array([0.0, 0.0, 0.0]), spawn_orient=np.array([0.0, 0.0, 0.0])):
    """Spawn a URDF/xacro model in Gazebo Classic using ROS 2 gazebo_ros spawn_entity.py."""
    robot_description = loadXacro(package_name, model_name)
    if robot_description is None:
        return None

    urdf_path = f"/tmp/{model_name}.urdf"
    with open(urdf_path, "w") as f:
        f.write(robot_description)

    print(colored(f"Spawning {model_name}", "blue"))

    cmd = [
        "ros2", "run", "gazebo_ros", "spawn_entity.py",
        "-entity", model_name,
        "-file", urdf_path,
        "-x", str(spawn_pos[0]),
        "-y", str(spawn_pos[1]),
        "-z", str(spawn_pos[2]),
        "-R", str(spawn_orient[0]),
        "-P", str(spawn_orient[1]),
        "-Y", str(spawn_orient[2]),
    ]
    return subprocess.Popen(cmd)


def checkRosControllerRunning(controller="", robot_name=""):
    """Check controller_manager state in ROS 2 by calling list_controllers."""
    service_name = f"/{robot_name}/controller_manager/list_controllers" if robot_name else "/controller_manager/list_controllers"
    cmd = [
        "ros2", "service", "call",
        service_name,
        "controller_manager_msgs/srv/ListControllers",
        "{}",
    ]
    try:
        result = subprocess.check_output(cmd).decode()
    except subprocess.CalledProcessError:
        return False
    return controller in result and ("state: active" in result or "active" in result)


def spawnMesh(mesh_x, mesh_y, mesh_z, position=np.array([0, 0, 0]), texture_path=None):
    """Create a runtime mesh and spawn it in Gazebo Classic with ROS 2."""
    try:
        import meshio
    except ImportError:
        raise RuntimeError("You need to install meshio with: pip install meshio")

    print(colored("Spawning mesh", "red"))

    n_z = mesh_x.shape[0]
    n_y = mesh_y.shape[0]

    triangles = []
    for j in range(n_y - 1):
        for i in range(n_z - 1):
            p1 = j * n_z + i
            p2 = p1 + 1
            p3 = p1 + n_z
            p4 = p3 + 1
            triangles.append([p3, p2, p1])
            triangles.append([p3, p4, p2])

    triangles = np.array(triangles)
    points = np.column_stack((mesh_x.flatten(), mesh_y.flatten(), mesh_z.flatten()))

    tmp_stl_path = "/tmp/runtime_mesh.stl"
    mesh = meshio.Mesh(points=points, cells=[("triangle", triangles)])
    mesh.write(tmp_stl_path)

    if texture_path is not None:
        tmp_obj_path = "/tmp/runtime_mesh.obj"
        write_textured_obj(points, triangles, tmp_obj_path, texture_path)
        visual_uri = f"file://{tmp_obj_path}"
        material_block = ""
    else:
        visual_uri = f"file://{tmp_stl_path}"
        material_block = """
        <material>
          <ambient>0.545 0.271 0.075 1.0</ambient>
          <diffuse>0.545 0.271 0.075 1.0</diffuse>
          <specular>0.1 0.1 0.1 1.0</specular>
          <emissive>0.4 0.2 0.1 1.0</emissive>
        </material>
        """

    sdf_template = f"""
<sdf version="1.6">
  <model name="runtime_mesh">
    <static>true</static>
    <link name="link">
      <visual name="visual">
        <geometry>
          <mesh>
            <uri>{visual_uri}</uri>
          </mesh>
        </geometry>
        {material_block}
      </visual>
      <collision name="collision">
        <geometry>
          <mesh>
            <uri>file://{tmp_stl_path}</uri>
          </mesh>
        </geometry>
      </collision>
    </link>
  </model>
</sdf>
"""

    sdf_path = "/tmp/runtime_mesh.sdf"
    with open(sdf_path, "w") as f:
        f.write(sdf_template)

    cmd = [
        "ros2", "run", "gazebo_ros", "spawn_entity.py",
        "-file", sdf_path,
        "-entity", "runtime_mesh",
        "-x", str(position[0]),
        "-y", str(position[1]),
        "-z", str(position[2]),
    ]
    return subprocess.Popen(cmd)


def write_textured_obj(points, triangles, obj_path, texture_path):
    import shutil

    obj_dir = os.path.dirname(obj_path)
    base = os.path.splitext(os.path.basename(obj_path))[0]
    mtl_name = base + ".mtl"
    mtl_path = os.path.join(obj_dir, mtl_name)

    tex_name = os.path.basename(texture_path)
    tex_dst = os.path.join(obj_dir, tex_name)
    if os.path.abspath(texture_path) != os.path.abspath(tex_dst):
        shutil.copy(texture_path, tex_dst)

    x, y = points[:, 0], points[:, 1]
    x0, x1 = x.min(), x.max()
    y0, y1 = y.min(), y.max()
    tex_u = (x - x0) / max(x1 - x0, 1e-6)
    tex_v = 1.0 - (y - y0) / max(y1 - y0, 1e-6)
    uvs = np.column_stack([tex_u, tex_v])

    normals = compute_vertex_normals(points, triangles)

    with open(mtl_path, "w") as f:
        f.write("newmtl rock_material\n")
        f.write("Ka 1.0 1.0 1.0\n")
        f.write("Kd 1.0 1.0 1.0\n")
        f.write("Ks 0.2 0.2 0.2\n")
        f.write("Ns 50.0\n")
        f.write(f"map_Kd {tex_name}\n")

    with open(obj_path, "w") as f:
        f.write(f"mtllib {mtl_name}\n")
        f.write("usemtl rock_material\n")
        for p in points:
            f.write(f"v {p[0]} {p[1]} {p[2]}\n")
        for uv in uvs:
            f.write(f"vt {uv[0]} {uv[1]}\n")
        for n in normals:
            f.write(f"vn {n[0]} {n[1]} {n[2]}\n")
        for tri in triangles:
            a, b, c = tri + 1
            f.write(f"f {a}/{a}/{a} {b}/{b}/{b} {c}/{c}/{c}\n")


def compute_vertex_normals(points, triangles):
    normals = np.zeros_like(points)
    for tri in triangles:
        p0, p1, p2 = points[tri]
        n = np.cross(p1 - p0, p2 - p0)
        norm = np.linalg.norm(n)
        if norm > 1e-12:
            n /= norm
        for idx in tri:
            normals[idx] += n
    norms = np.linalg.norm(normals, axis=1)
    norms[norms == 0] = 1.0
    normals /= norms[:, None]
    return normals


def sendStaticTransform(parent, child, x_pos=np.zeros(3), quat=np.array([0, 0, 0, 1]), static_broadcaster=None, node=None):
    """Send a static transform in ROS 2. A node is required."""
    if node is None:
        raise RuntimeError("ROS 2 requires a node for time and TF broadcasting")

    msg = TransformStamped()
    msg.header.stamp = node.get_clock().now().to_msg()
    msg.header.frame_id = parent
    msg.child_frame_id = child
    msg.transform.translation.x = float(x_pos[0])
    msg.transform.translation.y = float(x_pos[1])
    msg.transform.translation.z = float(x_pos[2])
    msg.transform.rotation.x = float(quat[0])
    msg.transform.rotation.y = float(quat[1])
    msg.transform.rotation.z = float(quat[2])
    msg.transform.rotation.w = float(quat[3])

    if static_broadcaster is None:
        static_broadcaster = tf2_ros.StaticTransformBroadcaster(node)
    static_broadcaster.sendTransform(msg)
    return static_broadcaster


def _get_node_param(node, name, default=None):
    if node is None:
        return default
    if node.has_parameter(name):
        return node.get_parameter(name).value
    return default


def getRobotModelFloating(robot_name="hyq", node=None):
    ERROR_MSG = 'You should set the environment variable LOCOSIM_DIR\n'
    path = os.environ.get("LOCOSIM_DIR", ERROR_MSG)

    urdf = _get_node_param(node, "robot_description", None)
    if urdf is None:
        urdf = _get_node_param(node, f"{robot_name}.robot_description", None)

    if urdf is not None:
        os.makedirs(path + "/robot_urdf/generated_urdf/", exist_ok=True)
        urdf_location = path + "/robot_urdf/generated_urdf/" + robot_name + ".urdf"
        with open(urdf_location, "w") as text_file:
            text_file.write(urdf)
        robot = RobotWrapper.BuildFromURDF(urdf_location, root_joint=pinocchio.JointModelFreeFlyer())
    else:
        urdf_location = path + "/robot_urdf/generated_urdf/" + robot_name + ".urdf"
        robot = RobotWrapper.BuildFromURDF(urdf_location, root_joint=pinocchio.JointModelFreeFlyer())

    return robot


def getRobotModel(robot_name="hyq", generate_urdf=False, xacro_path=None, additional_urdf_args=None, floating_base=False):
    ERROR_MSG = 'You should set the environment variable LOCOSIM_DIR\n'
    path = os.environ.get("LOCOSIM_DIR", ERROR_MSG)
    srdf = path + "/robot_urdf/" + robot_name + ".srdf"

    if generate_urdf:
        try:
            if xacro_path is None:
                package_path = get_package_share_directory(robot_name + "_description")
                xacro_path = os.path.join(package_path, "robots", robot_name + ".urdf.xacro")

            urdf_location = path + "/robot_urdf/generated_urdf/" + robot_name + ".urdf"
            os.makedirs(os.path.dirname(urdf_location), exist_ok=True)

            cmd = ["xacro", xacro_path, "-o", urdf_location]
            if additional_urdf_args is not None:
                if isinstance(additional_urdf_args, str):
                    cmd.extend(additional_urdf_args.split())
                else:
                    cmd.extend(additional_urdf_args)

            subprocess.run(cmd, check=True)
            print("URDF generated")
            print(urdf_location)

            if floating_base:
                robot = RobotWrapper.BuildFromURDF(urdf_location, root_joint=pinocchio.JointModelFreeFlyer())
            else:
                robot = RobotWrapper.BuildFromURDF(urdf_location)
            print("URDF loaded in Pinocchio")
        except Exception as exc:
            print("Issues in URDF generation for Pinocchio, did not succeed")
            print(exc)
            robot = None
    else:
        urdf = path + "/robot_urdf/" + robot_name + ".urdf"
        robot = RobotWrapper.BuildFromURDF(urdf, [path, srdf])

    return robot


class SafeTFBroadcaster:
    """Avoid repeated TF messages with the same payload."""

    def __init__(self, node):
        self.node = node
        self.br = tf2_ros.TransformBroadcaster(node)
        self.last_stamp = None
        self.last_payload = None

    def sendTransform(self, trans, quat, stamp=None, child="base_link", parent="world"):
        if stamp is None:
            stamp = self.node.get_clock().now().to_msg()

        trans = np.asarray(trans).flatten()
        if trans.shape[0] != 3:
            raise ValueError(f"Translation must have 3 elements, got {trans}")

        if hasattr(quat, "coeffs"):
            quat = quat.coeffs()
        if len(quat) == 1 and isinstance(quat[0], (tuple, list, np.ndarray)):
            quat = quat[0]

        quat = np.asarray(quat).flatten()
        if quat.shape[0] != 4:
            raise ValueError(f"Quaternion must have 4 elements x,y,z,w, got {quat}")

        norm = np.linalg.norm(quat)
        if not np.isclose(norm, 1.0, atol=1e-6) and norm > 0:
            quat = quat / norm

        payload = tuple(trans) + tuple(quat)
        if self.last_payload == payload:
            return

        msg = TransformStamped()
        msg.header.stamp = stamp
        msg.header.frame_id = parent
        msg.child_frame_id = child
        msg.transform.translation.x = float(trans[0])
        msg.transform.translation.y = float(trans[1])
        msg.transform.translation.z = float(trans[2])
        msg.transform.rotation.x = float(quat[0])
        msg.transform.rotation.y = float(quat[1])
        msg.transform.rotation.z = float(quat[2])
        msg.transform.rotation.w = float(quat[3])

        self.br.sendTransform(msg)
        self.last_stamp = stamp
        self.last_payload = payload


# --------------------------
# Plotting utilities
# --------------------------
# These are ROS-independent. Keep your original plotting functions below this line if needed.
# The most commonly used ones are included here.


def subplot(n_rows, n_cols, n_subplot, sharex=False, sharey=False, ax_to_share=None):
    if sharex and sharey:
        ax = plt.subplot(n_rows, n_cols, n_subplot, sharex=ax_to_share, sharey=ax_to_share)
    elif sharex and not sharey:
        ax = plt.subplot(n_rows, n_cols, n_subplot, sharex=ax_to_share)
    elif not sharex and sharey:
        ax = plt.subplot(n_rows, n_cols, n_subplot, sharey=ax_to_share)
    else:
        ax = plt.subplot(n_rows, n_cols, n_subplot)
    return ax


def plotJoint(name, time_log, q_log=None, q_des_log=None, qd_log=None, qd_des_log=None, qdd_log=None, qdd_des_log=None, tau_log=None, tau_ffwd_log=None, tau_des_log=None, joint_names=None, q_adm=None, sharex=True, sharey=False, start=0, end=-1, title=None, subset_index=None):
    plot_var_log = None
    plot_var_des_log = None
    unit = ""

    if name == "position":
        unit = "[rad]"
        plot_var_log = q_log
        plot_var_des_log = q_des_log
    elif name == "velocity":
        unit = "[rad/s]"
        plot_var_log = qd_log
        plot_var_des_log = qd_des_log
    elif name == "acceleration":
        unit = "[rad/s^2]"
        plot_var_log = qdd_log
        plot_var_des_log = qdd_des_log
    elif name == "torque":
        unit = "[Nm]"
        plot_var_log = tau_log
        plot_var_des_log = tau_des_log

    dt = np.round(time_log[1] - time_log[0], 3)
    if type(start) == str:
        start = max(0, int(float(start) / dt + 1))
    if type(end) == str:
        end = min(int(float(end) / dt + 1), time_log.shape[0])

    if plot_var_log is not None:
        njoints = min(plot_var_log.shape)
    elif plot_var_des_log is not None:
        njoints = min(plot_var_des_log.shape)
    else:
        print("no log var has been defined")
        return None

    figure_id = 1 if len(plt.get_fignums()) == 0 else max(plt.get_fignums()) + 1
    fig = plt.figure(figure_id)
    fig.suptitle(title if title is not None else name, fontsize=20)

    if joint_names is None:
        if njoints <= 6:
            labels = labels_ur
        elif njoints == 12:
            labels = labels_quadruped
        elif njoints == 14:
            labels = labels_flywheel2
        elif njoints == 16:
            labels = labels_flywheel4
        else:
            labels = [f"joint_{i}" for i in range(njoints)]
        subset_index = range(njoints)
    else:
        if subset_index is None:
            njoints = len(joint_names)
            subset_index = range(njoints)
            labels = joint_names
        else:
            njoints = len(subset_index)
            labels = itemgetter(*subset_index)(joint_names)

    if njoints % 3 == 0:
        n_rows = int(njoints / 3)
        n_cols = 3
    elif njoints % 2 == 0:
        n_rows = int(njoints / 2)
        n_cols = 2
    else:
        n_rows = njoints
        n_cols = 1

    for jidx in range(njoints):
        if jidx == 0:
            ax = subplot(n_rows, n_cols, jidx + 1)
        else:
            subplot(n_rows, n_cols, jidx + 1, sharex=sharex, sharey=sharey, ax_to_share=ax)

        if jidx + n_cols >= njoints:
            plt.xlabel("Time [s]")

        plt.ylabel(labels[jidx] + " " + unit)

        if name == "torque" and tau_ffwd_log is not None:
            plt.plot(time_log[start:end], tau_ffwd_log[subset_index[jidx], start:end], linestyle="-", marker="o", markersize=marker_size, lw=lw_des, color="green")
        if plot_var_des_log is not None:
            plt.plot(time_log[start:end], plot_var_des_log[subset_index[jidx], start:end], linestyle="-", marker="o", markersize=marker_size, lw=lw_des, color="red")
        if plot_var_log is not None:
            plt.plot(time_log[start:end], plot_var_log[subset_index[jidx], start:end], linestyle="-", marker="o", markersize=marker_size, lw=lw_act, color="blue")
        if q_adm is not None:
            plt.plot(time_log[start:end], q_adm[subset_index[jidx], start:end], linestyle="-", marker="o", markersize=marker_size, lw=lw_act, color="black")
        plt.grid()

    return fig


def plotFrameLinear(name, time_log, des_Pose_log=None, Pose_log=None, des_Twist_log=None, Twist_log=None, des_Acc_log=None, Acc_log=None, des_Wrench_log=None, Wrench_log=None, title=None, frame=None, sharex=True, sharey=False, start=0, end=-1, wrapp_labels=None, custom_labels=None):
    plot_var_log = None
    plot_var_des_log = None
    labels = ["", "", ""]
    lin_unit = ""

    if name == "position":
        labels = ["x", "y", "z"]
        lin_unit = "[m]"
        if Pose_log is not None:
            plot_var_log = u.linPart(Pose_log) if Pose_log.shape[0] == 6 else Pose_log
        if des_Pose_log is not None:
            plot_var_des_log = u.linPart(des_Pose_log) if des_Pose_log.shape[0] == 6 else des_Pose_log
    elif name == "velocity":
        labels = ["x", "y", "z"]
        lin_unit = "[m/s]"
        if Twist_log is not None:
            plot_var_log = u.linPart(Twist_log) if Twist_log.shape[0] == 6 else Twist_log
        if des_Twist_log is not None:
            plot_var_des_log = u.linPart(des_Twist_log) if des_Twist_log.shape[0] == 6 else des_Twist_log
    elif name == "acceleration":
        labels = ["x", "y", "z"]
        lin_unit = "[m/s^2]"
        if Acc_log is not None:
            plot_var_log = u.linPart(Acc_log) if Acc_log.shape[0] == 6 else Acc_log
        if des_Acc_log is not None:
            plot_var_des_log = u.linPart(des_Acc_log) if des_Acc_log.shape[0] == 6 else des_Acc_log
    elif name == "wrench":
        labels = ["FX", "FY", "FZ"]
        lin_unit = "[N]"
        if Wrench_log is not None:
            plot_var_log = u.linPart(Wrench_log) if Wrench_log.shape[0] == 6 else Wrench_log
        if des_Wrench_log is not None:
            plot_var_des_log = u.linPart(des_Wrench_log) if des_Wrench_log.shape[0] == 6 else des_Wrench_log
    else:
        print("wrong choice")

    if custom_labels is not None:
        labels = custom_labels

    plot_title = name if title is None else title + " " + name
    if frame is not None:
        plot_title += " " + frame

    dt = np.round(time_log[1] - time_log[0], 3)
    if type(start) == str:
        start = max(0, int(float(start) / dt + 1))
    if type(end) == str:
        end = min(int(float(end) / dt + 1), time_log.shape[0])

    figure_id = 1 if len(plt.get_fignums()) == 0 else max(plt.get_fignums()) + 1
    fig = plt.figure(figure_id)
    fig.suptitle(plot_title, fontsize=20)
    ax = subplot(3, 1, 1)

    for i in range(3):
        subplot(3, 1, i + 1, sharex=sharex if i else False, sharey=sharey if i else False, ax_to_share=ax if i else None)
        plt.ylabel(labels[i] + " " + lin_unit)
        if i == 2:
            plt.xlabel("Time [s]")
        if plot_var_des_log is not None:
            plt.plot(time_log[start:end], plot_var_des_log[i, start:end], linestyle="-", marker="o", markersize=marker_size, lw=lw_des, color="red")
        if plot_var_log is not None:
            plt.plot(time_log[start:end], plot_var_log[i, start:end], linestyle="-", marker="o", markersize=marker_size, lw=lw_act, color="blue")
        plt.grid()

    return fig



def plotFrameAngular(name, time_log, des_Pose_log=None, Pose_log=None, des_Twist_log=None, Twist_log=None, des_Acc_log=None, Acc_log=None,
                    des_Wrench_log=None, Wrench_log=None, title=None, frame=None, sharex=True, sharey=True, start=0, end=-1):
    plot_var_log = None
    plot_var_des_log = None
    if name == 'position':
        labels = ["R", "P", "Y"]
        ang_unit = '[rad]'
        if Pose_log is not None:
            if Pose_log.shape[0] == 6:
                plot_var_log = u.angPart(Pose_log)
            elif Pose_log.shape[0] == 3:
                plot_var_log = Pose_log
        if (des_Pose_log is not None):
            if des_Pose_log.shape[0] == 6:
                plot_var_des_log = u.angPart(des_Pose_log)
            elif des_Pose_log.shape[0] == 3:
                plot_var_des_log = Pose_log

    elif name == 'velocity':
        labels = ["R", "P", "Y"]
        ang_unit = '[rad]'
        if Twist_log is not None:
            if Twist_log.shape[0] == 6:
                plot_var_log = u.angPart(Twist_log)
            elif Twist_log.shape[0] == 3:
                plot_var_log = Twist_log
        if (des_Twist_log is not None):
            if des_Twist_log.shape[0] == 6:
                plot_var_des_log = u.angPart(des_Twist_log)
            elif des_Twist_log.shape[0] == 3:
                plot_var_des_log = Twist_log

    elif name == 'acceleration':
        labels = ["R", "P", "Y"]
        ang_unit = '[rad]'
        if Acc_log is not None:
            if Acc_log.shape[0] == 6:
                plot_var_log = u.angPart(Acc_log)
            elif Acc_log.shape[0] == 3:
                plot_var_log = Acc_log
        if (des_Acc_log is not None):
            if des_Acc_log.shape[0] == 6:
                plot_var_des_log = u.angPart(des_Acc_log)
            elif des_Acc.shape[0] == 3:
                plot_var_des_log = des_Acc_log

    elif name == 'wrench':
        labels = ["MX", "MY", "MZ"]
        ang_unit = '[Nm]'
        if Wrench_log is not None:
            if Wrench_log.shape[0] == 6:
                plot_var_log = u.angPart(Wrench_log)
            elif Wrench_log.shape[0] == 3:
                plot_var_log = Wrench_log
        if (des_Wrench_log is not None):
            if des_Wrench_log.shape[0] == 6:
                plot_var_des_log = u.angPart(des_Wrench_log)
            elif des_Wrench_log.shape[0] == 3:
                plot_var_des_log = des_Wrench_log
    else:
        print("wrong choice")

    if title is None:
        title = name
    else:
        title = title + ' ' + name
    if frame is not None:
        title += ' ' + frame

    dt = np.round(time_log[1] - time_log[0], 3)
    if type(start) == str:
        start = max(0, int(float(start) / dt + 1))
    if type(end) == str:
        end = min(int(float(end) / dt + 1), time_log.shape[0])

    if len(plt.get_fignums()) == 0:
        figure_id = 1
    else:
        figure_id = max(plt.get_fignums()) + 1
    fig = plt.figure(figure_id)
    fig.suptitle(title, fontsize=20)
    ax = subplot(3, 1, 1, sharex=False, sharey=False, ax_to_share=None)
    plt.ylabel(labels[0] + " " + ang_unit)
    if (plot_var_des_log is not None):
        plt.plot(time_log[start:end], plot_var_des_log[0, start:end], linestyle='-', marker="o", markersize=marker_size,
                 lw=lw_des, color='red')
    if plot_var_log is not None:
        plt.plot(time_log[start:end], plot_var_log[0, start:end], linestyle='-', marker="o", markersize=marker_size,
                 lw=lw_act, color='blue')
    plt.grid()

    subplot(3, 1, 2, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel(labels[1] + " " + ang_unit)
    if (plot_var_des_log is not None):
        plt.plot(time_log[start:end], plot_var_des_log[1, start:end], linestyle='-', lw=lw_des, color='red')
    if plot_var_log is not None:
        plt.plot(time_log[start:end], plot_var_log[1, start:end], linestyle='-', marker="o", markersize=marker_size,
                 lw=lw_act,
                 color='blue')
    plt.grid()

    subplot(3, 1, 3, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel(labels[2] + " " + ang_unit)
    plt.xlabel("Time [s]")
    if (plot_var_des_log is not None):
        plt.plot(time_log[start:end], plot_var_des_log[2, start:end], linestyle='-', lw=lw_des, color='red')
    if plot_var_log is not None:
        plt.plot(time_log[start:end], plot_var_log[2, start:end], linestyle='-', marker="o", markersize=marker_size,
                 lw=lw_act,
                 color='blue')
    plt.grid()

    fig.align_ylabels(fig.axes[:3])

    return fig


def plotContacts(name, time_log, des_LinPose_log=None, LinPose_log=None, des_LinTwist_log=None, LinTwist_log=None, des_Forces_log=None,
                 Forces_log=None, gt_Forces_log=None, contact_states=None, frame=None, sharex=True, sharey=True, start=0, end=-1, title=None):
    # %% Input plots
    plot_var_log = None
    plot_var_des_log = None
    if name == 'position':
        unit = '[m]'
        if LinPose_log is not None:
            plot_var_log = LinPose_log
        if (des_LinPose_log is not None):
            plot_var_des_log = des_LinPose_log

    elif name == 'velocity':
        unit = '[m/s]'
        if LinTwist_log is not None:
            plot_var_log = LinTwist_log
        if (des_LinTwist_log is not None):
            plot_var_des_log = des_LinTwist_log

    elif name == 'GRFs':
        labels = ["FX", "FY", "FZ"]
        unit = '[N]'
        if Forces_log is not None:
            plot_var_log = Forces_log
        if (des_Forces_log is not None):
            plot_var_des_log = des_Forces_log
    else:
        print("wrong choice")

    if title is None:
        title = 'Contacts ' + name
        if frame is not None:
            title += ' ' + frame

    dt = np.round(time_log[1] - time_log[0], 3)
    if type(start) == str:
        start = max(0, int(float(start) / dt + 1))
    if type(end) == str:
        end = min(int(float(end) / dt + 1), time_log.shape[0])

    if len(plt.get_fignums()) == 0:
        figure_id = 1
    else:
        figure_id = max(plt.get_fignums())+1
    fig = plt.figure(figure_id)
    fig.suptitle(title, fontsize=20)

    ##########
    # LF leg #
    ##########
    # x
    idx = u.leg_map['LF']
    ax = subplot(6, 2, 1)
    plt.ylabel("$LF_x " + unit +"$", fontsize=10)
    if contact_states is not None:
        ax2 = ax.twinx()
        ax2.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])
    if plot_var_des_log is not None:
        ax.plot(time_log[start:end], plot_var_des_log[3 * idx, start:end], linestyle='-', lw=lw_des, color='red')
    if plot_var_log is not None:
        ax.plot(time_log[start:end], plot_var_log[3 * idx, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax.plot(time_log[start:end], gt_Forces_log[3*idx, start:end], linestyle='-', lw=lw_act, color='green')
    ax.grid()


    # y
    ax1 = subplot(6, 2, 3, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel("$LF_y " + unit +"$", fontsize=10)
    if contact_states is not None:
        ax2 = ax1.twinx()
        ax2.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])
    if plot_var_des_log is not None:
        ax1.plot(time_log[start:end], plot_var_des_log[3*idx + 1, start:end], linestyle='-', lw=lw_des, color = 'red')
    if plot_var_log is not None:
        ax1.plot(time_log[start:end], plot_var_log[3*idx + 1, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax1.plot(time_log[start:end], gt_Forces_log[3*idx + 1, start:end], linestyle='-', lw=lw_act, color='green')
    ax1.grid()


    # z
    ax1 = subplot(6, 2, 5, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel("$LF_z " + unit +"$", fontsize=10)
    if contact_states is not None:
        ax2 = ax1.twinx()
        plt.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])

    if plot_var_des_log is not None:
        ax1.plot(time_log[start:end], plot_var_des_log[3*idx + 2, start:end], linestyle='-', lw=lw_des, color = 'red')
    if plot_var_log is not None:
        ax1.plot(time_log[start:end], plot_var_log[3*idx + 2, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax1.plot(time_log[start:end], gt_Forces_log[3*idx + 2, start:end], linestyle='-', lw=lw_act, color='green')
    ax1.grid()

    ##########
    # RF leg #
    ##########
    # x
    idx = u.leg_map['RF']
    ax1 = subplot(6,2,2, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel("$RF_x " + unit +"$", fontsize=10)
    if contact_states is not None:
        ax2 = ax1.twinx()
        plt.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])
    if plot_var_des_log is not None:
        ax1.plot(time_log[start:end], plot_var_des_log[3*idx, start:end], linestyle='-', lw=lw_des, color = 'red')
    if plot_var_log is not None:
        ax1.plot(time_log[start:end], plot_var_log[3*idx, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax1.plot(time_log[start:end], gt_Forces_log[3*idx, start:end], linestyle='-', lw=lw_act, color='green')
    ax1.grid()


    # y
    ax1 = subplot(6,2,4, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel("$RF_y " + unit +"$", fontsize=10)
    if contact_states is not None:
        ax2 = ax1.twinx()
        plt.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])
    if plot_var_des_log is not None:
        ax1.plot(time_log[start:end], plot_var_des_log[3*idx + 1, start:end], linestyle='-', lw=lw_des, color = 'red')
    if plot_var_log is not None:
        ax1.plot(time_log[start:end], plot_var_log[3*idx + 1, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax1.plot(time_log[start:end], gt_Forces_log[3*idx + 1, start:end], linestyle='-', lw=lw_act, color='green')
    ax1.grid()


    # z
    ax1 = subplot(6,2,6, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel("$RF_z " + unit +"$", fontsize=10)
    if contact_states is not None:
        ax2 = ax1.twinx()
        plt.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])
    if plot_var_des_log is not None:
        ax1.plot(time_log[start:end], plot_var_des_log[3*idx + 2, start:end], linestyle='-', lw=lw_des, color = 'red')
    if plot_var_log is not None:
        ax1.plot(time_log[start:end], plot_var_log[3*idx + 2, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax1.plot(time_log[start:end], gt_Forces_log[3*idx + 2, start:end], linestyle='-', lw=lw_act, color='green')
    ax1.grid()


    ##########
    # LH leg #
    ##########
    # x
    idx = u.leg_map['LH']
    ax1 = subplot(6,2,7, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel("$LH_x " + unit +"$", fontsize=10)
    if contact_states is not None:
        ax2 = ax1.twinx()
        plt.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])
    if plot_var_des_log is not None:
        ax1.plot(time_log[start:end], plot_var_des_log[3 * idx, start:end], linestyle='-', lw=lw_des, color='red')
    if plot_var_log is not None:
        ax1.plot(time_log[start:end], plot_var_log[3*idx, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax1.plot(time_log[start:end], gt_Forces_log[3*idx, start:end], linestyle='-', lw=lw_act, color='green')
    ax1.grid()


    # y
    ax1 = subplot(6,2,9, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel("$LH_y " + unit +"$", fontsize=10)
    if contact_states is not None:
        ax2 = ax1.twinx()
        plt.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])
    if plot_var_des_log is not None:
        ax1.plot(time_log[start:end], plot_var_des_log[3*idx + 1, start:end], linestyle='-', lw=lw_des, color = 'red')
    if plot_var_log is not None:
        ax1.plot(time_log[start:end], plot_var_log[3*idx + 1, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax1.plot(time_log[start:end], gt_Forces_log[3*idx + 1, start:end], linestyle='-', lw=lw_act, color='green')
    ax1.grid()


    # z
    ax1 = subplot(6, 2, 11, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel("$LH_z " + unit +"$", fontsize=10)
    plt.xlabel("Time [s]")
    if contact_states is not None:
        ax2 = ax1.twinx()
        plt.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])
    if plot_var_des_log is not None:
        ax1.plot(time_log[start:end], plot_var_des_log[3*idx + 2, start:end], linestyle='-', lw=lw_des, color = 'red')
    if plot_var_log is not None:
        ax1.plot(time_log[start:end], plot_var_log[3*idx + 2, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax1.plot(time_log[start:end], gt_Forces_log[3*idx + 2, start:end], linestyle='-', lw=lw_act, color='green')
    ax1.grid()


    ##########
    # RH leg #
    ##########
    # x
    idx = u.leg_map['RH']
    ax1 = subplot(6, 2, 8, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel("$RH_x " + unit +"$", fontsize=10)
    if contact_states is not None:
        ax2 = ax1.twinx()
        plt.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])
    if plot_var_des_log is not None:
        ax1.plot(time_log[start:end], plot_var_des_log[3*idx, start:end], linestyle='-', lw=lw_des, color = 'red')
    if plot_var_log is not None:
        ax1.plot(time_log[start:end], plot_var_log[3*idx, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax1.plot(time_log[start:end], gt_Forces_log[3*idx, start:end], linestyle='-', lw=lw_act, color='green')
    ax1.grid()


    # y
    ax1 = subplot(6, 2, 10, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel("$RH_y " + unit +"$", fontsize=10)
    if contact_states is not None:
        ax2 = ax1.twinx()
        plt.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])
    if plot_var_des_log is not None:
        ax1.plot(time_log[start:end], plot_var_des_log[3*idx + 1, start:end], linestyle='-', lw=lw_des, color = 'red')
    if plot_var_log is not None:
        ax1.plot(time_log[start:end], plot_var_log[3*idx + 1, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax1.plot(time_log[start:end], gt_Forces_log[3*idx + 1, start:end], linestyle='-', lw=lw_act, color='green')
    ax1.grid()


    # z
    ax1 = subplot(6, 2, 12, sharex=sharex, sharey=sharey, ax_to_share=ax)
    plt.ylabel("$RH_z " + unit +"$", fontsize=10)
    plt.xlabel("Time [s]")
    if contact_states is not None:
        ax2 = ax1.twinx()
        plt.plot(time_log[start:end], contact_states[idx, start:end], linestyle='-', lw=2, color='black')
        ax2.set_ylim([-1.5, 1.5])
        ax2.set_yticks([0, 1])
    if plot_var_des_log is not None:
        ax1.plot(time_log[start:end], plot_var_des_log[3*idx + 2, start:end], linestyle='-', lw=lw_des, color = 'red')
    if plot_var_log is not None:
        ax1.plot(time_log[start:end], plot_var_log[3*idx + 2, start:end], linestyle='-', lw=lw_act, color='blue')
    if name == 'GRFs' and gt_Forces_log is not None:
        ax1.plot(time_log[start:end], gt_Forces_log[3*idx + 2, start:end], linestyle='-', lw=lw_act, color='green')
    ax1.grid()



    # axes = fig.axes
    # for i in range(6):
    #     yticks = axes[i].get_yticks()
    #     ymin = min(-0.01, min(yticks))
    #     ymax = max(0.01, max(yticks))
    #     axes[i].set_ylim([ymin, ymax])
    #     yticks = axes[i].get_yticks()
    #     axes[i].set_yticks(np.unique(np.around(yticks, 2)))


    fig.align_ylabels(fig.axes[0:12:4])
    fig.align_ylabels(fig.axes[1:12:4])
    fig.align_ylabels(fig.axes[2:12:4])
    fig.align_ylabels(fig.axes[3:12:4])

    return fig



def plotConstraitViolation(figure_id,constr_viol_log):
    fig = plt.figure(figure_id)
    plt.plot(constr_viol_log[0,:],label="LF")
    plt.plot(constr_viol_log[1,:],label="RF")
    plt.plot(constr_viol_log[2,:],label="LH")
    plt.plot(constr_viol_log[3,:],label="RH")
    plt.legend(bbox_to_anchor=(0., 1.02, 1., .102), loc=3, ncol=2, mode="expand", borderaxespad=0.)
    plt.ylabel("Constr violation", fontsize=10)
    plt.grid()

def plotEndeffImpedance(name, figure_id, x_log, x_des_log, f_log):

    title=""

    if name == 'position':
        title="Force vs Displacement"
    elif name == 'velocity':
        title="Force vs Velocity"
    elif name == 'acceleration':
        title="Force vs Acceleration"
    else:
        print("wrong choice in impedance plotting")

    lw_act=4
    lw_des=7

#    fig = plt.figure(figure_id)
    fig, axs = plt.subplots(3, 3)
    fig.suptitle(title, fontsize=20)

    axs[0, 0].plot((x_log[0,:].T-x_des_log[0,:].T), f_log[0,:].T, lw=lw_act, color = 'blue')
    axs[0, 0].set_title('Fx vs X')
    axs[0, 0].grid()

    axs[0, 1].plot((x_log[1,:].T-x_des_log[1,:].T), f_log[0,:].T, lw=lw_act, color = 'blue')
    axs[0, 1].set_title('Fx vs Y')
    axs[0, 1].grid()

    axs[0, 2].plot((x_log[2,:].T-x_des_log[2,:].T), f_log[0,:].T, lw=lw_act, color = 'blue')
    axs[0, 2].set_title('Fx vs Z')
    axs[0, 2].grid()

    axs[1, 0].plot((x_log[0,:].T-x_des_log[0,:].T), f_log[1,:].T, lw=lw_act, color = 'blue')
    axs[1, 0].set_title('Fy vs X')
    axs[1, 0].grid()

    axs[1, 1].plot((x_log[1,:].T-x_des_log[1,:].T), f_log[1,:].T, lw=lw_act, color = 'blue')
    axs[1, 1].set_title('Fy vs Y')
    axs[1, 1].grid()

    axs[1, 2].plot((x_log[2,:].T-x_des_log[2,:].T), f_log[1,:].T, lw=lw_act, color = 'blue')
    axs[1, 2].set_title('Fy vs Z')
    axs[1, 2].grid()

    axs[2, 0].plot((x_log[0,:].T-x_des_log[0,:].T), f_log[2,:].T, lw=lw_act, color = 'blue')
    axs[2, 0].set_title('Fz vs X')
    axs[2, 0].grid()

    axs[2, 1].plot((x_log[1,:].T-x_des_log[1,:].T), f_log[2,:].T, lw=lw_act, color = 'blue')
    axs[2, 1].set_title('Fz vs Y')
    axs[2, 1].grid()

    axs[2, 2].plot((x_log[2,:].T-x_des_log[2,:].T), f_log[2,:].T, lw=lw_act, color = 'blue')
    axs[2, 2].set_title('Fz vs Z')
    axs[2, 2].grid()

    return fig

def plotJointImpedance(name, q_log, q_des_log, tau_log):

    title=""

    if name == 'position':
        title="Torque vs Angular Displacement"
    elif name == 'velocity':
        title="Torue vs Angular Velocity"
    elif name == 'acceleration':
        title="Torque vs Angular Acceleration"
    else:
        print("wrong choice in impedance plotting")

    lw_act=4
    lw_des=3

    #Number of joints
    njoints = q_log.shape[0]

    #neet to transpose the matrix other wise it cannot be plot with numpy array
    fig = plt.figure()
    fig.suptitle(name, fontsize=20)
    labels_ur = ["1 - Shoulder Pan", "2 - Shoulder Lift","3 - Elbow","4 - Wrist 1","5 - Wrist 2","6 - Wrist 3"]
    labels_hyq = ["LF_HAA", "LF_HFE","LF_KFE","RF_HAA", "RF_HFE","RF_KFE","LH_HAA", "LH_HFE","LH_KFE","RH_HAA", "RH_HFE","RH_KFE"]

    if njoints == 6:
        labels = labels_ur
    if njoints == 12:
        labels = labels_hyq


    for jidx in range(njoints):

        plt.subplot(njoints/2,2,jidx+1)
        plt.ylabel(labels[jidx])
        plt.plot(q_log[jidx,:].T-q_des_log[jidx,:].T, tau_log[jidx,:].T, linestyle='-', lw=lw_des,color = 'blue')
        plt.grid()


def polar_chart(name, figure_id, phase_deg, mag_solid, mag_dashed, legend = None):
    import matplotlib as mpl
    mpl.use('pgf')
    from matplotlib.lines import Line2D
    from matplotlib.patches import Patch
    import logging
    logging.basicConfig(level=logging.DEBUG)


    # size_font = 16
    # mpl.rcdefaults()
    # mpl.rcParams['lines.linewidth'] = 10
    # mpl.rcParams['lines.markersize'] = 6
    # #mpl.rcParams['patch.linewidth'] = 4
    # mpl.rcParams['axes.grid'] = True
    # mpl.rcParams['axes.labelsize'] = 20
    # mpl.rcParams['font.family'] = 'sans-serif'
    # mpl.rcParams['font.size'] = 20
    # mpl.rcParams['font.serif'] = ['Times New Roman', 'Times', 'Bitstream Vera Serif', 'DejaVu Serif',
    #                               'New Century Schoolbook',
    #                               'Century Schoolbook L', 'Utopia', 'ITC Bookman', 'Bookman', 'Nimbus Roman No9 L',
    #                               'Palatino',
    #                               'Charter', 'serif']
    # mpl.rcParams['text.usetex'] = False
    # mpl.rcParams['legend.fontsize'] = 20
    # plt.rcParams['legend.title_fontsize'] = 20
    # mpl.rcParams['legend.loc'] = 'best'
    # mpl.rcParams['figure.facecolor'] = 'white'
    # mpl.rcParams['figure.figsize'] = 10,6
    # mpl.rcParams['savefig.format'] = 'pdf'

    size_font = 16
    mpl.rcdefaults()
    mpl.rcParams['lines.linewidth'] = 2
    # mpl.rcParams['lines.markersize'] = 6
    # mpl.rcParams['patch.linewidth'] = 4
    mpl.rcParams['axes.grid'] = True
    mpl.rcParams['axes.labelsize'] = size_font
    mpl.rcParams['font.family'] = 'sans-serif'
    mpl.rcParams['font.size'] = size_font
    mpl.rcParams['legend.fontsize'] = size_font - 2
    mpl.rcParams['legend.title_fontsize'] = size_font - 2
    mpl.rcParams['legend.loc'] = 'best'
    mpl.rcParams['figure.facecolor'] = 'white'
    mpl.rcParams['figure.figsize'] = 6, 4
    mpl.rcParams['savefig.format'] = 'pdf'
    mpl.rcParams['font.serif'] = ['Times New Roman', 'Times', 'Bitstream Vera Serif', 'DejaVu Serif',
                                  'New Century Schoolbook',
                                  'Century Schoolbook L', 'Utopia', 'ITC Bookman', 'Bookman', 'Nimbus Roman No9 L',
                                  'Palatino',
                                  'Charter', 'serif']

    # mpl.rcParams['mathtext.fontset'] = 'dejavuserif'
    # mpl.rcParams['mathtext.bf'] = 'serif:bold'
    plt.rcParams.update(
        {
            "text.usetex": True,
            "pgf.texsystem": "pdflatex",
            "text.latex.preamble": r"\usepackage{bm}",

            # Enforce default LaTeX font.
            # "font.family": "serif",
            "font.serif": ["Computer Modern"],
        }
    )


    phase_rad = []
    for deg in phase_deg:
        rad = deg * np.pi/180
        phase_rad.append(rad)

    patches_solid = []
    for mag in mag_solid:
        if mag is not None:
            poly = np.zeros((len(phase_rad), 2))
            for i in range(len(phase_rad)):
                poly[i, :] = np.array([phase_rad[i], mag[i]])
            patches_solid.append(Polygon(poly))

    patches_dashed = []
    for mag in mag_dashed:
        if mag is not None:
            poly = np.zeros((len(phase_rad), 2))
            for i in range(len(phase_rad)):
                poly[i, :] = np.array([phase_rad[i], mag[i]])
            patches_dashed.append(Polygon(poly))

    fig, ax = plt.subplots(subplot_kw={'projection': 'polar'})
    # plt.subplots_adjust(left=0.04, bottom=0.04, top=0.96, right=0.96)


    fcolors = ['none']*3
    ecolors = ['darkgreen', 'b', 'r', 'orange']

    p_solid = PatchCollection(patches_solid, alpha=1, linewidth=4)
    p_solid.set_edgecolor(ecolors)
    p_solid.set_facecolor(fcolors)

    p_dashed = PatchCollection(patches_dashed, alpha=1, linestyles='--', linewidth=4)
    p_dashed.set_edgecolor(ecolors)
    p_dashed.set_facecolor(fcolors)



    ax.set_rmax(3)
    step = np.abs(phase_deg[0]-phase_deg[1])
    phase_rad =np.arange(0,360, step)*np.pi/180
    ax.set_xticks(phase_rad)
    ax.tick_params(axis='x', which='major', pad=12)

    rticks = np.arange(0,4,0.5)
    ax.set_rticks(rticks)

    #rticks_show = np.arange(0, 4, 1)
    ax.set_yticklabels(['0', '', '1', '', '2', '', '3', 'm/s'])
    ax.add_collection(p_solid)
    ax.add_collection(p_dashed)

    if legend is not None:
        legend_elements = [Line2D([0], [0], color=ecolors[i], lw=4, label=legend[i]) for i in range(len(legend))]
        ax.legend(handles=legend_elements, loc='center left', bbox_to_anchor=(1.2, 0.5), ncol=1, title="drop height [m]")

    fig.suptitle(name)


    fig.tight_layout()
    plt.show()
    return fig, ax


def plotWrenches(name, figure_id, time_log, des_Wrench_fb_log=None, des_Wrench_ffwd_log=None, des_Wrench_g_log=None):
    labels = ["FX", "FY", "FZ", "MX", "MY", "MZ"]
    lin_unit = '[N]'
    ang_unit = '[Nm]'
    plot_var_des_log = None
    if name=='feedback' or name=='fb':
        plot_var_des_log = des_Wrench_fb_log
    elif name=='feedforward' or name=='ffwd':
        plot_var_des_log = des_Wrench_ffwd_log
    elif name=='gravity' or name=='g':
        plot_var_des_log = des_Wrench_g_log

    # neet to transpose the matrix other wise it cannot be plot with numpy array
    fig = plt.figure(figure_id)
    fig.suptitle('Wrench ' + name, fontsize=20)
    plt.subplot(3, 2, 1)
    plt.ylabel(labels[0])
    plt.plot(time_log, plot_var_des_log[0, :], linestyle='-', marker="o", markersize=marker_size, lw=lw_des, color='red')
    plt.grid()

    plt.subplot(3, 2, 3)
    plt.ylabel(labels[1])
    plt.plot(time_log, plot_var_des_log[1, :], linestyle='-', marker="o", markersize=marker_size, lw=lw_des, color='red')
    plt.grid()

    plt.subplot(3, 2, 5)
    plt.ylabel(labels[2])
    plt.xlabel("Time [s]")
    plt.plot(time_log, plot_var_des_log[2, :], linestyle='-', marker="o", markersize=marker_size, lw=lw_des, color='red')
    plt.grid()

    plt.subplot(3, 2, 2)
    plt.ylabel(labels[3] )
    plt.plot(time_log, plot_var_des_log[3, :], linestyle='-', marker="o", markersize=marker_size, lw=lw_des, color='red')
    plt.grid()

    plt.subplot(3, 2, 4)
    plt.ylabel(labels[4] )
    plt.plot(time_log, plot_var_des_log[4, :], linestyle='-', marker="o", markersize=marker_size, lw=lw_des, color='red')
    plt.grid()

    plt.subplot(3, 2, 6)
    plt.ylabel(labels[5] )
    plt.xlabel("Time [s]")
    plt.plot(time_log, plot_var_des_log[5, :], linestyle='-', marker="o", markersize=marker_size, lw=lw_des, color='red')
    plt.grid()

    fig.align_ylabels(fig.axes[:3])
    fig.align_ylabels(fig.axes[3:])

    return fig
