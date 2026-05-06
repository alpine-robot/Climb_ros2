// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from cl_arganello_interface:msg/RopeCommand.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__BUILDER_HPP_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "cl_arganello_interface/msg/detail/rope_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace cl_arganello_interface
{

namespace msg
{

namespace builder
{

class Init_RopeCommand_rope_velocity
{
public:
  explicit Init_RopeCommand_rope_velocity(::cl_arganello_interface::msg::RopeCommand & msg)
  : msg_(msg)
  {}
  ::cl_arganello_interface::msg::RopeCommand rope_velocity(::cl_arganello_interface::msg::RopeCommand::_rope_velocity_type arg)
  {
    msg_.rope_velocity = std::move(arg);
    return std::move(msg_);
  }

private:
  ::cl_arganello_interface::msg::RopeCommand msg_;
};

class Init_RopeCommand_rope_position
{
public:
  explicit Init_RopeCommand_rope_position(::cl_arganello_interface::msg::RopeCommand & msg)
  : msg_(msg)
  {}
  Init_RopeCommand_rope_velocity rope_position(::cl_arganello_interface::msg::RopeCommand::_rope_position_type arg)
  {
    msg_.rope_position = std::move(arg);
    return Init_RopeCommand_rope_velocity(msg_);
  }

private:
  ::cl_arganello_interface::msg::RopeCommand msg_;
};

class Init_RopeCommand_rope_force
{
public:
  explicit Init_RopeCommand_rope_force(::cl_arganello_interface::msg::RopeCommand & msg)
  : msg_(msg)
  {}
  Init_RopeCommand_rope_position rope_force(::cl_arganello_interface::msg::RopeCommand::_rope_force_type arg)
  {
    msg_.rope_force = std::move(arg);
    return Init_RopeCommand_rope_position(msg_);
  }

private:
  ::cl_arganello_interface::msg::RopeCommand msg_;
};

class Init_RopeCommand_header
{
public:
  Init_RopeCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RopeCommand_rope_force header(::cl_arganello_interface::msg::RopeCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_RopeCommand_rope_force(msg_);
  }

private:
  ::cl_arganello_interface::msg::RopeCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::cl_arganello_interface::msg::RopeCommand>()
{
  return cl_arganello_interface::msg::builder::Init_RopeCommand_header();
}

}  // namespace cl_arganello_interface

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__BUILDER_HPP_
