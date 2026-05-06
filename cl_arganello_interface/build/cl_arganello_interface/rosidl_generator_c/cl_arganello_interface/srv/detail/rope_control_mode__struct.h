// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cl_arganello_interface:srv/RopeControlMode.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__SRV__DETAIL__ROPE_CONTROL_MODE__STRUCT_H_
#define CL_ARGANELLO_INTERFACE__SRV__DETAIL__ROPE_CONTROL_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RopeControlMode in the package cl_arganello_interface.
typedef struct cl_arganello_interface__srv__RopeControlMode_Request
{
  rosidl_runtime_c__String message;
} cl_arganello_interface__srv__RopeControlMode_Request;

// Struct for a sequence of cl_arganello_interface__srv__RopeControlMode_Request.
typedef struct cl_arganello_interface__srv__RopeControlMode_Request__Sequence
{
  cl_arganello_interface__srv__RopeControlMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cl_arganello_interface__srv__RopeControlMode_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/RopeControlMode in the package cl_arganello_interface.
typedef struct cl_arganello_interface__srv__RopeControlMode_Response
{
  bool success;
} cl_arganello_interface__srv__RopeControlMode_Response;

// Struct for a sequence of cl_arganello_interface__srv__RopeControlMode_Response.
typedef struct cl_arganello_interface__srv__RopeControlMode_Response__Sequence
{
  cl_arganello_interface__srv__RopeControlMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cl_arganello_interface__srv__RopeControlMode_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CL_ARGANELLO_INTERFACE__SRV__DETAIL__ROPE_CONTROL_MODE__STRUCT_H_
