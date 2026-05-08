from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
import xacro


def launch_setup(context, *args, **kwargs):
    robot_name = LaunchConfiguration("robot_name").perform(context)

    xacro_file = PathJoinSubstitution([
        FindPackageShare("climbingrobot_description"),
        "urdf",
        "climbingrobot2.xacro"
    ]).perform(context)

    rviz_config = PathJoinSubstitution([
        FindPackageShare("climbingrobot_description"),
        "rviz",
        "conf.rviz"
    ]).perform(context)

    robot_description = xacro.process_file(
        xacro_file,
        mappings={"robot_name": robot_name}
    ).toxml()

    return [
        Node(
            package="robot_state_publisher",
            executable="robot_state_publisher",
            name="robot_state_publisher",
            output="screen",
            parameters=[{
                "robot_description": robot_description,
                "use_sim_time": False
            }]
        ),

        Node(
            package="rviz2",
            executable="rviz2",
            name="rviz2",
            output="screen",
            arguments=["-d", rviz_config]
        )
    ]


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            "robot_name",
            default_value="climbingrobot2"
        ),
        OpaqueFunction(function=launch_setup),
    ])