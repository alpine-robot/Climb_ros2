// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cl_arganello_interface:msg/RopeCommand.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__STRUCT_H_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/RopeCommand in the package cl_arganello_interface.
typedef struct cl_arganello_interface__msg__RopeCommand
{
  std_msgs__msg__Header header;
  float rope_force;
  float rope_position;
  float rope_velocity;
} cl_arganello_interface__msg__RopeCommand;

// Struct for a sequence of cl_arganello_interface__msg__RopeCommand.
typedef struct cl_arganello_interface__msg__RopeCommand__Sequence
{
  cl_arganello_interface__msg__RopeCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cl_arganello_interface__msg__RopeCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__STRUCT_H_
