# Install script for directory: /home/andrea/Climb_ros2/cl_arganello_interface

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/andrea/Climb_ros2/cl_arganello_interface/install/cl_arganello_interface")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rosidl_interfaces" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_index/share/ament_index/resource_index/rosidl_interfaces/cl_arganello_interface")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cl_arganello_interface/cl_arganello_interface" TYPE DIRECTORY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_generator_c/cl_arganello_interface/" REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/environment" TYPE FILE FILES "/home/andrea/ros2_humble/build/ament_package/ament_package/template/environment_hook/library_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/environment" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_environment_hooks/library_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/libcl_arganello_interface__rosidl_generator_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_c.so"
         OLD_RPATH "/home/andrea/ros2_humble/install/std_msgs/lib:/home/andrea/ros2_humble/install/builtin_interfaces/lib:/home/andrea/ros2_humble/install/rosidl_runtime_c/lib:/home/andrea/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cl_arganello_interface/cl_arganello_interface" TYPE DIRECTORY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_typesupport_fastrtps_c/cl_arganello_interface/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/libcl_arganello_interface__rosidl_typesupport_fastrtps_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_c.so"
         OLD_RPATH "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface:/home/andrea/ros2_humble/install/std_msgs/lib:/home/andrea/ros2_humble/install/builtin_interfaces/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_fastrtps_cpp/lib:/home/andrea/ros2_humble/install/fastcdr/lib:/home/andrea/ros2_humble/install/rmw/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_fastrtps_c/lib:/home/andrea/ros2_humble/install/rosidl_runtime_c/lib:/home/andrea/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cl_arganello_interface/cl_arganello_interface" TYPE DIRECTORY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_generator_cpp/cl_arganello_interface/" REGEX "/[^/]*\\.hpp$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cl_arganello_interface/cl_arganello_interface" TYPE DIRECTORY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_typesupport_fastrtps_cpp/cl_arganello_interface/" REGEX "/[^/]*\\.cpp$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/libcl_arganello_interface__rosidl_typesupport_fastrtps_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_cpp.so"
         OLD_RPATH "/home/andrea/ros2_humble/install/std_msgs/lib:/home/andrea/ros2_humble/install/builtin_interfaces/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_fastrtps_cpp/lib:/home/andrea/ros2_humble/install/fastcdr/lib:/home/andrea/ros2_humble/install/rmw/lib:/home/andrea/ros2_humble/install/rosidl_runtime_c/lib:/home/andrea/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_fastrtps_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cl_arganello_interface/cl_arganello_interface" TYPE DIRECTORY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_typesupport_introspection_c/cl_arganello_interface/" REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/libcl_arganello_interface__rosidl_typesupport_introspection_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_c.so"
         OLD_RPATH "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface:/home/andrea/ros2_humble/install/std_msgs/lib:/home/andrea/ros2_humble/install/builtin_interfaces/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_introspection_c/lib:/home/andrea/ros2_humble/install/rosidl_runtime_c/lib:/home/andrea/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_c.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_c.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/libcl_arganello_interface__rosidl_typesupport_c.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_c.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_c.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_c.so"
         OLD_RPATH "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface:/home/andrea/ros2_humble/install/std_msgs/lib:/home/andrea/ros2_humble/install/builtin_interfaces/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_c/lib:/home/andrea/ros2_humble/install/rcpputils/lib:/home/andrea/ros2_humble/install/rosidl_runtime_c/lib:/home/andrea/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_c.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cl_arganello_interface/cl_arganello_interface" TYPE DIRECTORY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_typesupport_introspection_cpp/cl_arganello_interface/" REGEX "/[^/]*\\.hpp$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/libcl_arganello_interface__rosidl_typesupport_introspection_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_cpp.so"
         OLD_RPATH "/home/andrea/ros2_humble/install/std_msgs/lib:/home/andrea/ros2_humble/install/builtin_interfaces/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_introspection_cpp/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_introspection_c/lib:/home/andrea/ros2_humble/install/rosidl_runtime_c/lib:/home/andrea/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_introspection_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_cpp.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_cpp.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/libcl_arganello_interface__rosidl_typesupport_cpp.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_cpp.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_cpp.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_cpp.so"
         OLD_RPATH "/home/andrea/ros2_humble/install/std_msgs/lib:/home/andrea/ros2_humble/install/builtin_interfaces/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_cpp/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_c/lib:/home/andrea/ros2_humble/install/rcpputils/lib:/home/andrea/ros2_humble/install/rosidl_runtime_c/lib:/home/andrea/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_typesupport_cpp.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/environment" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_environment_hooks/pythonpath.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/environment" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_environment_hooks/pythonpath.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface-0.0.0-py3.8.egg-info" TYPE DIRECTORY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_python/cl_arganello_interface/cl_arganello_interface.egg-info/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface" TYPE DIRECTORY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_generator_py/cl_arganello_interface/" REGEX "/[^/]*\\.pyc$" EXCLUDE REGEX "/\\_\\_pycache\\_\\_$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(
        COMMAND
        "/usr/bin/python3" "-m" "compileall"
        "/home/andrea/Climb_ros2/cl_arganello_interface/install/cl_arganello_interface/lib/python3.8/site-packages/cl_arganello_interface"
      )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface" TYPE SHARED_LIBRARY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_generator_py/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so"
         OLD_RPATH "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_generator_py/cl_arganello_interface:/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface:/home/andrea/ros2_humble/install/std_msgs/lib:/home/andrea/ros2_humble/install/builtin_interfaces/lib:/home/andrea/ros2_humble/install/rmw/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_fastrtps_c/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_fastrtps_cpp/lib:/home/andrea/ros2_humble/install/fastcdr/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_introspection_cpp/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_introspection_c/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_cpp/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_c/lib:/home/andrea/ros2_humble/install/rosidl_runtime_c/lib:/home/andrea/ros2_humble/install/rcpputils/lib:/home/andrea/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_introspection_c.cpython-38-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface" TYPE SHARED_LIBRARY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_generator_py/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so"
         OLD_RPATH "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_generator_py/cl_arganello_interface:/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface:/home/andrea/ros2_humble/install/std_msgs/lib:/home/andrea/ros2_humble/install/builtin_interfaces/lib:/home/andrea/ros2_humble/install/rmw/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_fastrtps_c/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_fastrtps_cpp/lib:/home/andrea/ros2_humble/install/fastcdr/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_introspection_cpp/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_introspection_c/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_cpp/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_c/lib:/home/andrea/ros2_humble/install/rosidl_runtime_c/lib:/home/andrea/ros2_humble/install/rcpputils/lib:/home/andrea/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_fastrtps_c.cpython-38-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface" TYPE SHARED_LIBRARY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_generator_py/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so"
         OLD_RPATH "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_generator_py/cl_arganello_interface:/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface:/home/andrea/ros2_humble/install/std_msgs/lib:/home/andrea/ros2_humble/install/builtin_interfaces/lib:/home/andrea/ros2_humble/install/rmw/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_fastrtps_c/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_fastrtps_cpp/lib:/home/andrea/ros2_humble/install/fastcdr/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_introspection_cpp/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_introspection_c/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_cpp/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_c/lib:/home/andrea/ros2_humble/install/rosidl_runtime_c/lib:/home/andrea/ros2_humble/install/rcpputils/lib:/home/andrea/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/python3.8/site-packages/cl_arganello_interface/cl_arganello_interface_s__rosidl_typesupport_c.cpython-38-x86_64-linux-gnu.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_py.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_py.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_py.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_generator_py/cl_arganello_interface/libcl_arganello_interface__rosidl_generator_py.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_py.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_py.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_py.so"
         OLD_RPATH "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface:/home/andrea/ros2_humble/install/std_msgs/lib:/home/andrea/ros2_humble/install/builtin_interfaces/lib:/home/andrea/ros2_humble/install/rosidl_typesupport_c/lib:/home/andrea/ros2_humble/install/rosidl_runtime_c/lib:/home/andrea/ros2_humble/install/rcpputils/lib:/home/andrea/ros2_humble/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libcl_arganello_interface__rosidl_generator_py.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/rust_packages" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_index/share/ament_index/resource_index/rust_packages/cl_arganello_interface")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface" TYPE DIRECTORY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_generator_rs/cl_arganello_interface/rust")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/srv" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_adapter/cl_arganello_interface/srv/RopeControlMode.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/msg" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_adapter/cl_arganello_interface/msg/RopeCommand.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/msg" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_adapter/cl_arganello_interface/msg/RopeTelemetry.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/msg" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_adapter/cl_arganello_interface/msg/DebugMessage.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/msg" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_adapter/cl_arganello_interface/msg/Imus.idl")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/srv" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/srv/RopeControlMode.srv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/srv" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_cmake/srv/RopeControlMode_Request.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/srv" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_cmake/srv/RopeControlMode_Response.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/msg" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/msg/RopeCommand.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/msg" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/msg/RopeTelemetry.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/msg" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/msg/DebugMessage.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/msg" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/msg/Imus.msg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cl_arganello_interface" TYPE PROGRAM FILES
    "/home/andrea/Climb_ros2/cl_arganello_interface/cl_arganello_interface/dongle_node.py"
    "/home/andrea/Climb_ros2/cl_arganello_interface/cl_arganello_interface/friction_estimator.py"
    "/home/andrea/Climb_ros2/cl_arganello_interface/cl_arganello_interface/telemetry_node.py"
    "/home/andrea/Climb_ros2/cl_arganello_interface/cl_arganello_interface/jump.py"
    "/home/andrea/Climb_ros2/cl_arganello_interface/cl_arganello_interface/alpine_odometry_node.py"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/" TYPE DIRECTORY FILES "/home/andrea/Climb_ros2/cl_arganello_interface/launch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/cl_arganello_interface")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/cl_arganello_interface")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/environment" TYPE FILE FILES "/home/andrea/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/environment" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/environment" TYPE FILE FILES "/home/andrea/ros2_humble/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/environment" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_index/share/ament_index/resource_index/packages/cl_arganello_interface")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cExport.cmake"
         "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cExport.cmake"
         "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cppExport.cmake"
         "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_cppExport.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cppExport.cmake"
         "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_typesupport_fastrtps_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cExport.cmake"
         "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cExport.cmake"
         "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cppExport.cmake"
         "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_introspection_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cppExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cppExport.cmake"
         "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cppExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cppExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cppExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cppExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/cl_arganello_interface__rosidl_typesupport_cppExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_pyExport.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_pyExport.cmake"
         "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_pyExport.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_pyExport-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_pyExport.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_pyExport.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/CMakeFiles/Export/share/cl_arganello_interface/cmake/export_cl_arganello_interface__rosidl_generator_pyExport-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_cmake/rosidl_cmake-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_export_dependencies/ament_cmake_export_dependencies-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_export_include_directories/ament_cmake_export_include_directories-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_export_libraries/ament_cmake_export_libraries-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_export_targets/ament_cmake_export_targets-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_cmake/rosidl_cmake_export_typesupport_targets-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_cmake/rosidl_cmake_export_typesupport_libraries-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/rosidl_cmake/rosidl_cmake_aggregate_target-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface/cmake" TYPE FILE FILES
    "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_core/cl_arganello_interfaceConfig.cmake"
    "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/ament_cmake_core/cl_arganello_interfaceConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cl_arganello_interface" TYPE FILE FILES "/home/andrea/Climb_ros2/cl_arganello_interface/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/cl_arganello_interface__py/cmake_install.cmake")
  include("/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/cl_arganello_interface__rs/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/andrea/Climb_ros2/cl_arganello_interface/build/cl_arganello_interface/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
