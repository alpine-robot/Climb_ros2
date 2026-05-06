// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from cl_arganello_interface:msg/DebugMessage.idl
// generated code does not contain a copyright notice
#include "cl_arganello_interface/msg/detail/debug_message__rosidl_typesupport_fastrtps_cpp.hpp"
#include "cl_arganello_interface/msg/detail/debug_message__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace cl_arganello_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cl_arganello_interface
cdr_serialize(
  const cl_arganello_interface::msg::DebugMessage & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: brake
  cdr << (ros_message.brake ? true : false);
  // Member: current
  cdr << ros_message.current;
  // Member: motor_torque
  cdr << ros_message.motor_torque;
  // Member: syncronous_roller_raw_wrapped
  cdr << ros_message.syncronous_roller_raw_wrapped;
  // Member: motor_position
  cdr << ros_message.motor_position;
  // Member: motor_speed_rev_s
  cdr << ros_message.motor_speed_rev_s;
  // Member: motor_speed_rad_s
  cdr << ros_message.motor_speed_rad_s;
  // Member: sync_roller_speed_rev_s
  cdr << ros_message.sync_roller_speed_rev_s;
  // Member: sync_roller_speed_rad_s
  cdr << ros_message.sync_roller_speed_rad_s;
  // Member: rope_speed_m_s
  cdr << ros_message.rope_speed_m_s;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cl_arganello_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  cl_arganello_interface::msg::DebugMessage & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: brake
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.brake = tmp ? true : false;
  }

  // Member: current
  cdr >> ros_message.current;

  // Member: motor_torque
  cdr >> ros_message.motor_torque;

  // Member: syncronous_roller_raw_wrapped
  cdr >> ros_message.syncronous_roller_raw_wrapped;

  // Member: motor_position
  cdr >> ros_message.motor_position;

  // Member: motor_speed_rev_s
  cdr >> ros_message.motor_speed_rev_s;

  // Member: motor_speed_rad_s
  cdr >> ros_message.motor_speed_rad_s;

  // Member: sync_roller_speed_rev_s
  cdr >> ros_message.sync_roller_speed_rev_s;

  // Member: sync_roller_speed_rad_s
  cdr >> ros_message.sync_roller_speed_rad_s;

  // Member: rope_speed_m_s
  cdr >> ros_message.rope_speed_m_s;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cl_arganello_interface
get_serialized_size(
  const cl_arganello_interface::msg::DebugMessage & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: brake
  {
    size_t item_size = sizeof(ros_message.brake);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current
  {
    size_t item_size = sizeof(ros_message.current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: motor_torque
  {
    size_t item_size = sizeof(ros_message.motor_torque);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: syncronous_roller_raw_wrapped
  {
    size_t item_size = sizeof(ros_message.syncronous_roller_raw_wrapped);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: motor_position
  {
    size_t item_size = sizeof(ros_message.motor_position);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: motor_speed_rev_s
  {
    size_t item_size = sizeof(ros_message.motor_speed_rev_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: motor_speed_rad_s
  {
    size_t item_size = sizeof(ros_message.motor_speed_rad_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sync_roller_speed_rev_s
  {
    size_t item_size = sizeof(ros_message.sync_roller_speed_rev_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: sync_roller_speed_rad_s
  {
    size_t item_size = sizeof(ros_message.sync_roller_speed_rad_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: rope_speed_m_s
  {
    size_t item_size = sizeof(ros_message.rope_speed_m_s);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cl_arganello_interface
max_serialized_size_DebugMessage(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: brake
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: current
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: motor_torque
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: syncronous_roller_raw_wrapped
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: motor_position
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: motor_speed_rev_s
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: motor_speed_rad_s
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: sync_roller_speed_rev_s
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: sync_roller_speed_rad_s
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: rope_speed_m_s
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = cl_arganello_interface::msg::DebugMessage;
    is_plain =
      (
      offsetof(DataType, rope_speed_m_s) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _DebugMessage__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const cl_arganello_interface::msg::DebugMessage *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DebugMessage__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<cl_arganello_interface::msg::DebugMessage *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DebugMessage__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const cl_arganello_interface::msg::DebugMessage *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DebugMessage__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DebugMessage(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DebugMessage__callbacks = {
  "cl_arganello_interface::msg",
  "DebugMessage",
  _DebugMessage__cdr_serialize,
  _DebugMessage__cdr_deserialize,
  _DebugMessage__get_serialized_size,
  _DebugMessage__max_serialized_size
};

static rosidl_message_type_support_t _DebugMessage__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DebugMessage__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace cl_arganello_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_cl_arganello_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<cl_arganello_interface::msg::DebugMessage>()
{
  return &cl_arganello_interface::msg::typesupport_fastrtps_cpp::_DebugMessage__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cl_arganello_interface, msg, DebugMessage)() {
  return &cl_arganello_interface::msg::typesupport_fastrtps_cpp::_DebugMessage__handle;
}

#ifdef __cplusplus
}
#endif
