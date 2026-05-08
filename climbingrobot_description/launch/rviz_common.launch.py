#!/usr/bin/env python3

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, SetEnvironmentVariable
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node


def generate_launch_description():
    pkg_share = get_package_share_directory('climbingrobot_description')

    rviz_conf = LaunchConfiguration('rviz_conf')
    robot_name = LaunchConfiguration('robot_name')
    obstacle = LaunchConfiguration('obstacle')
    wall_inclination = LaunchConfiguration('wall_inclination')
    obstacle_location_x = LaunchConfiguration('obstacle_location_x')
    obstacle_location_y = LaunchConfiguration('obstacle_location_y')
    obstacle_location_z = LaunchConfiguration('obstacle_location_z')
    obstacle_size_x = LaunchConfiguration('obstacle_size_x')
    obstacle_size_y = LaunchConfiguration('obstacle_size_y')
    obstacle_size_z = LaunchConfiguration('obstacle_size_z')
    double_propeller = LaunchConfiguration('double_propeller')

    upload_launch = PathJoinSubstitution([pkg_share, 'launch', 'upload.launch.py'])

    return LaunchDescription([
        DeclareLaunchArgument('rviz_conf', default_value=PathJoinSubstitution([pkg_share, 'rviz', 'conf.rviz'])),
        DeclareLaunchArgument('robot_name', default_value='climbingrobot2'),
        DeclareLaunchArgument('obstacle', default_value='false'),
        DeclareLaunchArgument('wall_inclination', default_value='0.0'),
        DeclareLaunchArgument('obstacle_location_x', default_value='0.0'),
        DeclareLaunchArgument('obstacle_location_y', default_value='0.0'),
        DeclareLaunchArgument('obstacle_location_z', default_value='0.0'),
        DeclareLaunchArgument('obstacle_size_x', default_value='0.0'),
        DeclareLaunchArgument('obstacle_size_y', default_value='0.0'),
        DeclareLaunchArgument('obstacle_size_z', default_value='0.0'),
        DeclareLaunchArgument('double_propeller', default_value='false'),

        SetEnvironmentVariable('GAZEBO_MODEL_PATH', pkg_share),

        IncludeLaunchDescription(
            PythonLaunchDescriptionSource(upload_launch),
            launch_arguments={
                'robot_name': robot_name,
                'wall_inclination': wall_inclination,
                'obstacle': obstacle,
                'obstacle_location_x': obstacle_location_x,
                'obstacle_location_y': obstacle_location_y,
                'obstacle_location_z': obstacle_location_z,
                'obstacle_size_x': obstacle_size_x,
                'obstacle_size_y': obstacle_size_y,
                'obstacle_size_z': obstacle_size_z,
                'double_propeller': double_propeller,
            }.items(),
        ),

        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='world_broadcaster',
            arguments=['0.1', '0', '0', '0', '0', '0', 'wall', 'world'],
            output='screen',
        ),
        Node(
            package='tf2_ros',
            executable='static_transform_publisher',
            name='pillar_broadcaster',
            arguments=['0', '0', '0', '0', '0', '0', 'pillar', 'wall'],
            output='screen',
        ),
        Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui',
            name='joint_state_publisher_gui',
            output='screen',
        ),
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments=['-d', rviz_conf, '-f', 'world'],
            output='screen',
        ),
    ])
