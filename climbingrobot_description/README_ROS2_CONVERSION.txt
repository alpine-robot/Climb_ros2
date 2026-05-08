ROS 2 conversion notes

Converted from ROS 1 catkin/message_generation to ROS 2 ament_cmake/rosidl_default_generators.

Included interfaces:
- msg/RopeCommand.msg
- msg/PropellerCommand.msg
- msg/RopeTelemetry.msg
- msg/AlpineBodyTelemetry.msg
- srv/AlpineBodyCommand.srv
- srv/RopeControlMode.srv

Build:
  cd ~/ros2_ws/src
  unzip climbingrobot_description_ros2_full.zip
  cd ~/ros2_ws
  colcon build --packages-select climbingrobot_description
  source install/setup.bash

Check generated interfaces:
  ros2 interface list | grep climbingrobot_description
