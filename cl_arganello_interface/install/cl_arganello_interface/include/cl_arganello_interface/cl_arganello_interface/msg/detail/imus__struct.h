// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cl_arganello_interface:msg/Imus.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__STRUCT_H_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Imus in the package cl_arganello_interface.
/**
  * alpine_msgs/msg/AlpineDualImu.msg
 */
typedef struct cl_arganello_interface__msg__Imus
{
  uint32_t epoch_ms;
  float imu1[11];
  float imu2[11];
} cl_arganello_interface__msg__Imus;

// Struct for a sequence of cl_arganello_interface__msg__Imus.
typedef struct cl_arganello_interface__msg__Imus__Sequence
{
  cl_arganello_interface__msg__Imus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cl_arganello_interface__msg__Imus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__STRUCT_H_
