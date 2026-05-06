// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cl_arganello_interface:msg/DebugMessage.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__STRUCT_HPP_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cl_arganello_interface__msg__DebugMessage __attribute__((deprecated))
#else
# define DEPRECATED__cl_arganello_interface__msg__DebugMessage __declspec(deprecated)
#endif

namespace cl_arganello_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DebugMessage_
{
  using Type = DebugMessage_<ContainerAllocator>;

  explicit DebugMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->brake = false;
      this->current = 0.0f;
      this->motor_torque = 0.0f;
      this->syncronous_roller_raw_wrapped = 0l;
      this->motor_position = 0.0f;
      this->motor_speed_rev_s = 0.0f;
      this->motor_speed_rad_s = 0.0f;
      this->sync_roller_speed_rev_s = 0.0f;
      this->sync_roller_speed_rad_s = 0.0f;
      this->rope_speed_m_s = 0.0f;
    }
  }

  explicit DebugMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->brake = false;
      this->current = 0.0f;
      this->motor_torque = 0.0f;
      this->syncronous_roller_raw_wrapped = 0l;
      this->motor_position = 0.0f;
      this->motor_speed_rev_s = 0.0f;
      this->motor_speed_rad_s = 0.0f;
      this->sync_roller_speed_rev_s = 0.0f;
      this->sync_roller_speed_rad_s = 0.0f;
      this->rope_speed_m_s = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _brake_type =
    bool;
  _brake_type brake;
  using _current_type =
    float;
  _current_type current;
  using _motor_torque_type =
    float;
  _motor_torque_type motor_torque;
  using _syncronous_roller_raw_wrapped_type =
    int32_t;
  _syncronous_roller_raw_wrapped_type syncronous_roller_raw_wrapped;
  using _motor_position_type =
    float;
  _motor_position_type motor_position;
  using _motor_speed_rev_s_type =
    float;
  _motor_speed_rev_s_type motor_speed_rev_s;
  using _motor_speed_rad_s_type =
    float;
  _motor_speed_rad_s_type motor_speed_rad_s;
  using _sync_roller_speed_rev_s_type =
    float;
  _sync_roller_speed_rev_s_type sync_roller_speed_rev_s;
  using _sync_roller_speed_rad_s_type =
    float;
  _sync_roller_speed_rad_s_type sync_roller_speed_rad_s;
  using _rope_speed_m_s_type =
    float;
  _rope_speed_m_s_type rope_speed_m_s;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__brake(
    const bool & _arg)
  {
    this->brake = _arg;
    return *this;
  }
  Type & set__current(
    const float & _arg)
  {
    this->current = _arg;
    return *this;
  }
  Type & set__motor_torque(
    const float & _arg)
  {
    this->motor_torque = _arg;
    return *this;
  }
  Type & set__syncronous_roller_raw_wrapped(
    const int32_t & _arg)
  {
    this->syncronous_roller_raw_wrapped = _arg;
    return *this;
  }
  Type & set__motor_position(
    const float & _arg)
  {
    this->motor_position = _arg;
    return *this;
  }
  Type & set__motor_speed_rev_s(
    const float & _arg)
  {
    this->motor_speed_rev_s = _arg;
    return *this;
  }
  Type & set__motor_speed_rad_s(
    const float & _arg)
  {
    this->motor_speed_rad_s = _arg;
    return *this;
  }
  Type & set__sync_roller_speed_rev_s(
    const float & _arg)
  {
    this->sync_roller_speed_rev_s = _arg;
    return *this;
  }
  Type & set__sync_roller_speed_rad_s(
    const float & _arg)
  {
    this->sync_roller_speed_rad_s = _arg;
    return *this;
  }
  Type & set__rope_speed_m_s(
    const float & _arg)
  {
    this->rope_speed_m_s = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cl_arganello_interface::msg::DebugMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const cl_arganello_interface::msg::DebugMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cl_arganello_interface::msg::DebugMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cl_arganello_interface::msg::DebugMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cl_arganello_interface::msg::DebugMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cl_arganello_interface::msg::DebugMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cl_arganello_interface::msg::DebugMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cl_arganello_interface::msg::DebugMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cl_arganello_interface::msg::DebugMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cl_arganello_interface::msg::DebugMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cl_arganello_interface__msg__DebugMessage
    std::shared_ptr<cl_arganello_interface::msg::DebugMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cl_arganello_interface__msg__DebugMessage
    std::shared_ptr<cl_arganello_interface::msg::DebugMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DebugMessage_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->brake != other.brake) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    if (this->motor_torque != other.motor_torque) {
      return false;
    }
    if (this->syncronous_roller_raw_wrapped != other.syncronous_roller_raw_wrapped) {
      return false;
    }
    if (this->motor_position != other.motor_position) {
      return false;
    }
    if (this->motor_speed_rev_s != other.motor_speed_rev_s) {
      return false;
    }
    if (this->motor_speed_rad_s != other.motor_speed_rad_s) {
      return false;
    }
    if (this->sync_roller_speed_rev_s != other.sync_roller_speed_rev_s) {
      return false;
    }
    if (this->sync_roller_speed_rad_s != other.sync_roller_speed_rad_s) {
      return false;
    }
    if (this->rope_speed_m_s != other.rope_speed_m_s) {
      return false;
    }
    return true;
  }
  bool operator!=(const DebugMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DebugMessage_

// alias to use template instance with default allocator
using DebugMessage =
  cl_arganello_interface::msg::DebugMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cl_arganello_interface

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__DEBUG_MESSAGE__STRUCT_HPP_
