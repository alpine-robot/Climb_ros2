// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from cl_arganello_interface:msg/Imus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "cl_arganello_interface/msg/detail/imus__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace cl_arganello_interface
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Imus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) cl_arganello_interface::msg::Imus(_init);
}

void Imus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<cl_arganello_interface::msg::Imus *>(message_memory);
  typed_message->~Imus();
}

size_t size_function__Imus__imu1(const void * untyped_member)
{
  (void)untyped_member;
  return 11;
}

const void * get_const_function__Imus__imu1(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 11> *>(untyped_member);
  return &member[index];
}

void * get_function__Imus__imu1(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 11> *>(untyped_member);
  return &member[index];
}

void fetch_function__Imus__imu1(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Imus__imu1(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Imus__imu1(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Imus__imu1(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

size_t size_function__Imus__imu2(const void * untyped_member)
{
  (void)untyped_member;
  return 11;
}

const void * get_const_function__Imus__imu2(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 11> *>(untyped_member);
  return &member[index];
}

void * get_function__Imus__imu2(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 11> *>(untyped_member);
  return &member[index];
}

void fetch_function__Imus__imu2(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__Imus__imu2(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__Imus__imu2(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__Imus__imu2(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Imus_message_member_array[3] = {
  {
    "epoch_ms",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(cl_arganello_interface::msg::Imus, epoch_ms),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "imu1",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    11,  // array size
    false,  // is upper bound
    offsetof(cl_arganello_interface::msg::Imus, imu1),  // bytes offset in struct
    nullptr,  // default value
    size_function__Imus__imu1,  // size() function pointer
    get_const_function__Imus__imu1,  // get_const(index) function pointer
    get_function__Imus__imu1,  // get(index) function pointer
    fetch_function__Imus__imu1,  // fetch(index, &value) function pointer
    assign_function__Imus__imu1,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "imu2",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    11,  // array size
    false,  // is upper bound
    offsetof(cl_arganello_interface::msg::Imus, imu2),  // bytes offset in struct
    nullptr,  // default value
    size_function__Imus__imu2,  // size() function pointer
    get_const_function__Imus__imu2,  // get_const(index) function pointer
    get_function__Imus__imu2,  // get(index) function pointer
    fetch_function__Imus__imu2,  // fetch(index, &value) function pointer
    assign_function__Imus__imu2,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Imus_message_members = {
  "cl_arganello_interface::msg",  // message namespace
  "Imus",  // message name
  3,  // number of fields
  sizeof(cl_arganello_interface::msg::Imus),
  Imus_message_member_array,  // message members
  Imus_init_function,  // function to initialize message memory (memory has to be allocated)
  Imus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Imus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Imus_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace cl_arganello_interface


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<cl_arganello_interface::msg::Imus>()
{
  return &::cl_arganello_interface::msg::rosidl_typesupport_introspection_cpp::Imus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, cl_arganello_interface, msg, Imus)() {
  return &::cl_arganello_interface::msg::rosidl_typesupport_introspection_cpp::Imus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
