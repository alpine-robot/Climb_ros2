from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg_share = FindPackageShare("cl_arganello_interface")

    arganello_config_path = PathJoinSubstitution([
        pkg_share,
        "config",
        "arganelloTelemetry.json",
    ])

    winch_gains_path = PathJoinSubstitution([
        pkg_share,
        "config",
        "winch_position_gains.yaml",
    ])

    return LaunchDescription([
        Node(
            package="cl_arganello_interface",
            executable="telemetry_node.py",
            name="telemetry_node_left",
            parameters=[
                winch_gains_path,
                {
                    "side": "left",
                    "serial_port": "/dev/serial/by-id/usb-1a86_USB_Single_Serial_5970047399-if00",
                    "config_path": arganello_config_path,
                    "debug_mode": True,
                },
            ],
        ),

        Node(
            package="cl_arganello_interface",
            executable="telemetry_node.py",
            name="telemetry_node_right",
            parameters=[
                winch_gains_path,
                {
                    "side": "right",
                    "serial_port": "/dev/serial/by-id/usb-1a86_USB_Single_Serial_5970046081-if00",
                    "config_path": arganello_config_path,
                    "debug_mode": True,
                },
            ],
        ),

        Node(
            package="cl_arganello_interface",
            executable="dongle_node.py",
            name="dongle_node",
            parameters=[{
                "serial_port": "/dev/serial/by-id/usb-1a86_USB_Single_Serial_5A7A010904-if00",
                "baud": 1000000,
                "poll_rate": 100.0,
            }],
        ),

        Node(
            package="cl_arganello_interface",
            executable="jump.py",
            name="jump_node",
            parameters=[{
                "step_left_force": -18.0,
                "step_right_force": 18.0,
                "step_push_ms": 220.0,
                "step_flight_ms": 900.0,
                "hold_force": 10.0,
                "max_abs_rope_force": 25.0,
                "optimized_csv": "/home/andrea/Climb_ros2/optimized_jump.csv",
            }],
        ),
    ])