#!/usr/bin/env python3

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package="YOUR_ROS2_PACKAGE_NAME",
            executable="climbingrobot_controller2_real_ros2",
            name="climbingrobot_controller",
            output="screen",
        )
    ])
