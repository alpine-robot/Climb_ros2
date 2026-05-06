// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from cl_arganello_interface:msg/Imus.idl
// generated code does not contain a copyright notice
#include "cl_arganello_interface/msg/detail/imus__rosidl_typesupport_fastrtps_cpp.hpp"
#include "cl_arganello_interface/msg/detail/imus__struct.hpp"

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

namespace cl_arganello_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cl_arganello_interface
cdr_serialize(
  const cl_arganello_interface::msg::Imus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: epoch_ms
  cdr << ros_message.epoch_ms;
  // Member: imu1
  {
    cdr << ros_message.imu1;
  }
  // Member: imu2
  {
    cdr << ros_message.imu2;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cl_arganello_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  cl_arganello_interface::msg::Imus & ros_message)
{
  // Member: epoch_ms
  cdr >> ros_message.epoch_ms;

  // Member: imu1
  {
    cdr >> ros_message.imu1;
  }

  // Member: imu2
  {
    cdr >> ros_message.imu2;
  }

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cl_arganello_interface
get_serialized_size(
  const cl_arganello_interface::msg::Imus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: epoch_ms
  {
    size_t item_size = sizeof(ros_message.epoch_ms);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: imu1
  {
    size_t array_size = 11;
    size_t item_size = sizeof(ros_message.imu1[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: imu2
  {
    size_t array_size = 11;
    size_t item_size = sizeof(ros_message.imu2[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_cl_arganello_interface
max_serialized_size_Imus(
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


  // Member: epoch_ms
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: imu1
  {
    size_t array_size = 11;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: imu2
  {
    size_t array_size = 11;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = cl_arganello_interface::msg::Imus;
    is_plain =
      (
      offsetof(DataType, imu2) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Imus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const cl_arganello_interface::msg::Imus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Imus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<cl_arganello_interface::msg::Imus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Imus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const cl_arganello_interface::msg::Imus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Imus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Imus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Imus__callbacks = {
  "cl_arganello_interface::msg",
  "Imus",
  _Imus__cdr_serialize,
  _Imus__cdr_deserialize,
  _Imus__get_serialized_size,
  _Imus__max_serialized_size
};

static rosidl_message_type_support_t _Imus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Imus__callbacks,
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
get_message_type_support_handle<cl_arganello_interface::msg::Imus>()
{
  return &cl_arganello_interface::msg::typesupport_fastrtps_cpp::_Imus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, cl_arganello_interface, msg, Imus)() {
  return &cl_arganello_interface::msg::typesupport_fastrtps_cpp::_Imus__handle;
}

#ifdef __cplusplus
}
#endif
