// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from cl_arganello_interface:msg/DebugMessage.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__STRUCT_H_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__STRUCT_H_

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

/// Struct defined in msg/DebugMessage in the package cl_arganello_interface.
/**
  * Timestamp so PlotJuggler can use ROS time
 */
typedef struct cl_arganello_interface__msg__DebugMessage
{
  std_msgs__msg__Header header;
  /// Raw inputs
  /// 1 if engaged
  bool brake;
  /// A (ibus)
  float current;
  /// Nm (as reported by ODrive)
  float motor_torque;
  /// counts [0..CPR)
  int32_t syncronous_roller_raw_wrapped;
  /// revs in [0..1)
  float motor_position;
  /// Derived (you just computed these)
  /// rev/s
  float motor_speed_rev_s;
  /// rad/s
  float motor_speed_rad_s;
  /// rev/s
  float sync_roller_speed_rev_s;
  /// rad/s
  float sync_roller_speed_rad_s;
  /// m/s (roller linear)
  float rope_speed_m_s;
} cl_arganello_interface__msg__DebugMessage;

// Struct for a sequence of cl_arganello_interface__msg__DebugMessage.
typedef struct cl_arganello_interface__msg__DebugMessage__Sequence
{
  cl_arganello_interface__msg__DebugMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} cl_arganello_interface__msg__DebugMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__STRUCT_H_
