# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target cl_arganello_interface::cl_arganello_interface
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${cl_arganello_interface_TARGETS}.
if(cl_arganello_interface_TARGETS AND NOT TARGET cl_arganello_interface::cl_arganello_interface)
  add_library(cl_arganello_interface::cl_arganello_interface INTERFACE IMPORTED)
  set_target_properties(cl_arganello_interface::cl_arganello_interface PROPERTIES
    INTERFACE_LINK_LIBRARIES "${cl_arganello_interface_TARGETS}")
endif()
