// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cl_arganello_interface:msg/RopeCommand.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__STRUCT_HPP_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__STRUCT_HPP_

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
# define DEPRECATED__cl_arganello_interface__msg__RopeCommand __attribute__((deprecated))
#else
# define DEPRECATED__cl_arganello_interface__msg__RopeCommand __declspec(deprecated)
#endif

namespace cl_arganello_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct RopeCommand_
{
  using Type = RopeCommand_<ContainerAllocator>;

  explicit RopeCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rope_force = 0.0f;
      this->rope_position = 0.0f;
      this->rope_velocity = 0.0f;
    }
  }

  explicit RopeCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->rope_force = 0.0f;
      this->rope_position = 0.0f;
      this->rope_velocity = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _rope_force_type =
    float;
  _rope_force_type rope_force;
  using _rope_position_type =
    float;
  _rope_position_type rope_position;
  using _rope_velocity_type =
    float;
  _rope_velocity_type rope_velocity;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__rope_force(
    const float & _arg)
  {
    this->rope_force = _arg;
    return *this;
  }
  Type & set__rope_position(
    const float & _arg)
  {
    this->rope_position = _arg;
    return *this;
  }
  Type & set__rope_velocity(
    const float & _arg)
  {
    this->rope_velocity = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cl_arganello_interface::msg::RopeCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const cl_arganello_interface::msg::RopeCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cl_arganello_interface::msg::RopeCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cl_arganello_interface::msg::RopeCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cl_arganello_interface::msg::RopeCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cl_arganello_interface::msg::RopeCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cl_arganello_interface::msg::RopeCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cl_arganello_interface::msg::RopeCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cl_arganello_interface::msg::RopeCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cl_arganello_interface::msg::RopeCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cl_arganello_interface__msg__RopeCommand
    std::shared_ptr<cl_arganello_interface::msg::RopeCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cl_arganello_interface__msg__RopeCommand
    std::shared_ptr<cl_arganello_interface::msg::RopeCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RopeCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->rope_force != other.rope_force) {
      return false;
    }
    if (this->rope_position != other.rope_position) {
      return false;
    }
    if (this->rope_velocity != other.rope_velocity) {
      return false;
    }
    return true;
  }
  bool operator!=(const RopeCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RopeCommand_

// alias to use template instance with default allocator
using RopeCommand =
  cl_arganello_interface::msg::RopeCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cl_arganello_interface

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__STRUCT_HPP_
