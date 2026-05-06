// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cl_arganello_interface:srv/RopeControlMode.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__SRV__DETAIL__ROPE_CONTROL_MODE__TRAITS_HPP_
#define CL_ARGANELLO_INTERFACE__SRV__DETAIL__ROPE_CONTROL_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cl_arganello_interface/srv/detail/rope_control_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace cl_arganello_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const RopeControlMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RopeControlMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RopeControlMode_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cl_arganello_interface

namespace rosidl_generator_traits
{

[[deprecated("use cl_arganello_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cl_arganello_interface::srv::RopeControlMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  cl_arganello_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cl_arganello_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const cl_arganello_interface::srv::RopeControlMode_Request & msg)
{
  return cl_arganello_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cl_arganello_interface::srv::RopeControlMode_Request>()
{
  return "cl_arganello_interface::srv::RopeControlMode_Request";
}

template<>
inline const char * name<cl_arganello_interface::srv::RopeControlMode_Request>()
{
  return "cl_arganello_interface/srv/RopeControlMode_Request";
}

template<>
struct has_fixed_size<cl_arganello_interface::srv::RopeControlMode_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cl_arganello_interface::srv::RopeControlMode_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cl_arganello_interface::srv::RopeControlMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace cl_arganello_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const RopeControlMode_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RopeControlMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RopeControlMode_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace cl_arganello_interface

namespace rosidl_generator_traits
{

[[deprecated("use cl_arganello_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cl_arganello_interface::srv::RopeControlMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  cl_arganello_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cl_arganello_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const cl_arganello_interface::srv::RopeControlMode_Response & msg)
{
  return cl_arganello_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<cl_arganello_interface::srv::RopeControlMode_Response>()
{
  return "cl_arganello_interface::srv::RopeControlMode_Response";
}

template<>
inline const char * name<cl_arganello_interface::srv::RopeControlMode_Response>()
{
  return "cl_arganello_interface/srv/RopeControlMode_Response";
}

template<>
struct has_fixed_size<cl_arganello_interface::srv::RopeControlMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<cl_arganello_interface::srv::RopeControlMode_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<cl_arganello_interface::srv::RopeControlMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<cl_arganello_interface::srv::RopeControlMode>()
{
  return "cl_arganello_interface::srv::RopeControlMode";
}

template<>
inline const char * name<cl_arganello_interface::srv::RopeControlMode>()
{
  return "cl_arganello_interface/srv/RopeControlMode";
}

template<>
struct has_fixed_size<cl_arganello_interface::srv::RopeControlMode>
  : std::integral_constant<
    bool,
    has_fixed_size<cl_arganello_interface::srv::RopeControlMode_Request>::value &&
    has_fixed_size<cl_arganello_interface::srv::RopeControlMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<cl_arganello_interface::srv::RopeControlMode>
  : std::integral_constant<
    bool,
    has_bounded_size<cl_arganello_interface::srv::RopeControlMode_Request>::value &&
    has_bounded_size<cl_arganello_interface::srv::RopeControlMode_Response>::value
  >
{
};

template<>
struct is_service<cl_arganello_interface::srv::RopeControlMode>
  : std::true_type
{
};

template<>
struct is_service_request<cl_arganello_interface::srv::RopeControlMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<cl_arganello_interface::srv::RopeControlMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CL_ARGANELLO_INTERFACE__SRV__DETAIL__ROPE_CONTROL_MODE__TRAITS_HPP_
