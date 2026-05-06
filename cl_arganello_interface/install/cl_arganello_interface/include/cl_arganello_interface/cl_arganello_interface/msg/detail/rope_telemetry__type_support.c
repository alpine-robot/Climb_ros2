// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from cl_arganello_interface:msg/RopeTelemetry.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "cl_arganello_interface/msg/detail/rope_telemetry__rosidl_typesupport_introspection_c.h"
#include "cl_arganello_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "cl_arganello_interface/msg/detail/rope_telemetry__functions.h"
#include "cl_arganello_interface/msg/detail/rope_telemetry__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  cl_arganello_interface__msg__RopeTelemetry__init(message_memory);
}

void cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_fini_function(void * message_memory)
{
  cl_arganello_interface__msg__RopeTelemetry__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cl_arganello_interface__msg__RopeTelemetry, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rope_force",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cl_arganello_interface__msg__RopeTelemetry, rope_force),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rope_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cl_arganello_interface__msg__RopeTelemetry, rope_length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "rope_velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cl_arganello_interface__msg__RopeTelemetry, rope_velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "current",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cl_arganello_interface__msg__RopeTelemetry, current),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "brake_status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cl_arganello_interface__msg__RopeTelemetry, brake_status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_message_members = {
  "cl_arganello_interface__msg",  // message namespace
  "RopeTelemetry",  // message name
  6,  // number of fields
  sizeof(cl_arganello_interface__msg__RopeTelemetry),
  cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_message_member_array,  // message members
  cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_init_function,  // function to initialize message memory (memory has to be allocated)
  cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_message_type_support_handle = {
  0,
  &cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cl_arganello_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, cl_arganello_interface, msg, RopeTelemetry)() {
  cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_message_type_support_handle.typesupport_identifier) {
    cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &cl_arganello_interface__msg__RopeTelemetry__rosidl_typesupport_introspection_c__RopeTelemetry_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
