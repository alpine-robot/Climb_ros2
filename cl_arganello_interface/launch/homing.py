from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, TimerAction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch.substitutions import PathJoinSubstitution


def generate_launch_description():

    # 1) bringup
    bringup = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([
                FindPackageShare("cl_arganello_interface"),
                "launch",
                "alpine_low_level_bringup.launch.py",
            ])
        )
    )

    # 2) your homing node
    homing_node = Node(
        package="cl_arganello_interface",
        executable="homing_procedure.py",
        name="homing_procedure",
        output="screen",
        parameters=[{"step_delay": 1.0}],
    )

    return LaunchDescription([
        bringup,

        # wait for services/topics to be ready
        TimerAction(
            period=5.0,
            actions=[homing_node],
        ),
    ])
