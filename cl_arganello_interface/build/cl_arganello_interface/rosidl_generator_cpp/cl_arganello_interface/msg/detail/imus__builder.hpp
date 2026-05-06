// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cl_arganello_interface:msg/Imus.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__BUILDER_HPP_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cl_arganello_interface/msg/detail/imus__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cl_arganello_interface
{

namespace msg
{

namespace builder
{

class Init_Imus_imu2
{
public:
  explicit Init_Imus_imu2(::cl_arganello_interface::msg::Imus & msg)
  : msg_(msg)
  {}
  ::cl_arganello_interface::msg::Imus imu2(::cl_arganello_interface::msg::Imus::_imu2_type arg)
  {
    msg_.imu2 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cl_arganello_interface::msg::Imus msg_;
};

class Init_Imus_imu1
{
public:
  explicit Init_Imus_imu1(::cl_arganello_interface::msg::Imus & msg)
  : msg_(msg)
  {}
  Init_Imus_imu2 imu1(::cl_arganello_interface::msg::Imus::_imu1_type arg)
  {
    msg_.imu1 = std::move(arg);
    return Init_Imus_imu2(msg_);
  }

private:
  ::cl_arganello_interface::msg::Imus msg_;
};

class Init_Imus_epoch_ms
{
public:
  Init_Imus_epoch_ms()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Imus_imu1 epoch_ms(::cl_arganello_interface::msg::Imus::_epoch_ms_type arg)
  {
    msg_.epoch_ms = std::move(arg);
    return Init_Imus_imu1(msg_);
  }

private:
  ::cl_arganello_interface::msg::Imus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cl_arganello_interface::msg::Imus>()
{
  return cl_arganello_interface::msg::builder::Init_Imus_epoch_ms();
}

}  // namespace cl_arganello_interface

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__IMUS__BUILDER_HPP_
