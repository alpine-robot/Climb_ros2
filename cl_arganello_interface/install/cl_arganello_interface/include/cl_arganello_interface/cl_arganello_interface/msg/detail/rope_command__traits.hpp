// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cl_arganello_interface:msg/RopeCommand.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__TRAITS_HPP_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cl_arganello_interface/msg/detail/rope_command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace cl_arganello_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const RopeCommand & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: rope_force
  {
    out << "rope_force: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_force, out);
    out << ", ";
  }

  // member: rope_position
  {
    out << "rope_position: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_position, out);
    out << ", ";
  }

  // member: rope_velocity
  {
    out << "rope_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_velocity, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RopeCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: rope_force
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rope_force: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_force, out);
    out << "\n";
  }

  // member: rope_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rope_position: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_position, out);
    out << "\n";
  }

  // member: rope_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "rope_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.rope_velocity, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RopeCommand & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cl_arganello_interface

namespace rosidl_generator_traits
{

[[deprecated("use cl_arganello_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cl_arganello_interface::msg::RopeCommand & msg,
  std::ostream & out, size_t indentation = 0)
{
  cl_arganello_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cl_arganello_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const cl_arganello_interface::msg::RopeCommand & msg)
{
  return cl_arganello_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cl_arganello_interface::msg::RopeCommand>()
{
  return "cl_arganello_interface::msg::RopeCommand";
}

template<>
inline const char * name<cl_arganello_interface::msg::RopeCommand>()
{
  return "cl_arganello_interface/msg/RopeCommand";
}

template<>
struct has_fixed_size<cl_arganello_interface::msg::RopeCommand>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<cl_arganello_interface::msg::RopeCommand>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<cl_arganello_interface::msg::RopeCommand>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__TRAITS_HPP_
