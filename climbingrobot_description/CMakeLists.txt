cmake_minimum_required(VERSION 3.8)
project(climbingrobot_description)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/RopeCommand.msg"
  "msg/PropellerCommand.msg"
  "msg/RopeTelemetry.msg"
  "msg/AlpineBodyTelemetry.msg"
  "srv/AlpineBodyCommand.srv"
  "srv/RopeControlMode.srv"
  DEPENDENCIES std_msgs geometry_msgs
)

install(DIRECTORY
  config
  gazebo
  launch
  rviz
  meshes
  urdf
  media
  DESTINATION share/${PROJECT_NAME}
  OPTIONAL
)

install(PROGRAMS
  scripts/go0
  DESTINATION lib/${PROJECT_NAME}
  OPTIONAL
)

ament_export_dependencies(rosidl_default_runtime std_msgs geometry_msgs)
ament_package()
