// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cl_arganello_interface:srv/RopeControlMode.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__SRV__DETAIL__ROPE_CONTROL_MODE__BUILDER_HPP_
#define CL_ARGANELLO_INTERFACE__SRV__DETAIL__ROPE_CONTROL_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cl_arganello_interface/srv/detail/rope_control_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cl_arganello_interface
{

namespace srv
{

namespace builder
{

class Init_RopeControlMode_Request_message
{
public:
  Init_RopeControlMode_Request_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cl_arganello_interface::srv::RopeControlMode_Request message(::cl_arganello_interface::srv::RopeControlMode_Request::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cl_arganello_interface::srv::RopeControlMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cl_arganello_interface::srv::RopeControlMode_Request>()
{
  return cl_arganello_interface::srv::builder::Init_RopeControlMode_Request_message();
}

}  // namespace cl_arganello_interface


namespace cl_arganello_interface
{

namespace srv
{

namespace builder
{

class Init_RopeControlMode_Response_success
{
public:
  Init_RopeControlMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::cl_arganello_interface::srv::RopeControlMode_Response success(::cl_arganello_interface::srv::RopeControlMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cl_arganello_interface::srv::RopeControlMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::cl_arganello_interface::srv::RopeControlMode_Response>()
{
  return cl_arganello_interface::srv::builder::Init_RopeControlMode_Response_success();
}

}  // namespace cl_arganello_interface

#endif  // CL_ARGANELLO_INTERFACE__SRV__DETAIL__ROPE_CONTROL_MODE__BUILDER_HPP_
