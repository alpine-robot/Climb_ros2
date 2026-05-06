// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cl_arganello_interface:msg/Imus.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__STRUCT_HPP_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__cl_arganello_interface__msg__Imus __attribute__((deprecated))
#else
# define DEPRECATED__cl_arganello_interface__msg__Imus __declspec(deprecated)
#endif

namespace cl_arganello_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Imus_
{
  using Type = Imus_<ContainerAllocator>;

  explicit Imus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->epoch_ms = 0ul;
      std::fill<typename std::array<float, 11>::iterator, float>(this->imu1.begin(), this->imu1.end(), 0.0f);
      std::fill<typename std::array<float, 11>::iterator, float>(this->imu2.begin(), this->imu2.end(), 0.0f);
    }
  }

  explicit Imus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : imu1(_alloc),
    imu2(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->epoch_ms = 0ul;
      std::fill<typename std::array<float, 11>::iterator, float>(this->imu1.begin(), this->imu1.end(), 0.0f);
      std::fill<typename std::array<float, 11>::iterator, float>(this->imu2.begin(), this->imu2.end(), 0.0f);
    }
  }

  // field types and members
  using _epoch_ms_type =
    uint32_t;
  _epoch_ms_type epoch_ms;
  using _imu1_type =
    std::array<float, 11>;
  _imu1_type imu1;
  using _imu2_type =
    std::array<float, 11>;
  _imu2_type imu2;

  // setters for named parameter idiom
  Type & set__epoch_ms(
    const uint32_t & _arg)
  {
    this->epoch_ms = _arg;
    return *this;
  }
  Type & set__imu1(
    const std::array<float, 11> & _arg)
  {
    this->imu1 = _arg;
    return *this;
  }
  Type & set__imu2(
    const std::array<float, 11> & _arg)
  {
    this->imu2 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cl_arganello_interface::msg::Imus_<ContainerAllocator> *;
  using ConstRawPtr =
    const cl_arganello_interface::msg::Imus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cl_arganello_interface::msg::Imus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cl_arganello_interface::msg::Imus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cl_arganello_interface::msg::Imus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cl_arganello_interface::msg::Imus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cl_arganello_interface::msg::Imus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cl_arganello_interface::msg::Imus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cl_arganello_interface::msg::Imus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cl_arganello_interface::msg::Imus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cl_arganello_interface__msg__Imus
    std::shared_ptr<cl_arganello_interface::msg::Imus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cl_arganello_interface__msg__Imus
    std::shared_ptr<cl_arganello_interface::msg::Imus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Imus_ & other) const
  {
    if (this->epoch_ms != other.epoch_ms) {
      return false;
    }
    if (this->imu1 != other.imu1) {
      return false;
    }
    if (this->imu2 != other.imu2) {
      return false;
    }
    return true;
  }
  bool operator!=(const Imus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Imus_

// alias to use template instance with default allocator
using Imus =
  cl_arganello_interface::msg::Imus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cl_arganello_interface

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__STRUCT_HPP_
