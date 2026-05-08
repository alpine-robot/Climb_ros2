#!/usr/bin/env python3
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import PathJoinSubstitution


def generate_launch_description():
    pkg = get_package_share_directory('climbingrobot_description')
    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(PathJoinSubstitution([pkg, 'launch', 'rviz_common.launch.py'])),
            launch_arguments={
                'rviz_conf': PathJoinSubstitution([pkg, 'rviz', 'conf_paper.rviz']),
                'robot_name': 'climbingrobot2',
            }.items(),
        )
    ])
