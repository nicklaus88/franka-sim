// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from franka_spine_msgs:msg/SpineParameters.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/spine_parameters.hpp"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__TRAITS_HPP_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "franka_spine_msgs/msg/detail/spine_parameters__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'user_limits'
#include "franka_spine_msgs/msg/detail/user_limits__traits.hpp"

namespace franka_spine_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const SpineParameters & msg,
  std::ostream & out)
{
  out << "{";
  // member: user_limits
  {
    out << "user_limits: ";
    to_flow_style_yaml(msg.user_limits, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SpineParameters & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: user_limits
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "user_limits:\n";
    to_block_style_yaml(msg.user_limits, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SpineParameters & msg, bool use_flow_style = false)
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

}  // namespace franka_spine_msgs

namespace rosidl_generator_traits
{

[[deprecated("use franka_spine_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const franka_spine_msgs::msg::SpineParameters & msg,
  std::ostream & out, size_t indentation = 0)
{
  franka_spine_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use franka_spine_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const franka_spine_msgs::msg::SpineParameters & msg)
{
  return franka_spine_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<franka_spine_msgs::msg::SpineParameters>()
{
  return "franka_spine_msgs::msg::SpineParameters";
}

template<>
inline const char * name<franka_spine_msgs::msg::SpineParameters>()
{
  return "franka_spine_msgs/msg/SpineParameters";
}

template<>
struct has_fixed_size<franka_spine_msgs::msg::SpineParameters>
  : std::integral_constant<bool, has_fixed_size<franka_spine_msgs::msg::UserLimits>::value> {};

template<>
struct has_bounded_size<franka_spine_msgs::msg::SpineParameters>
  : std::integral_constant<bool, has_bounded_size<franka_spine_msgs::msg::UserLimits>::value> {};

template<>
struct is_message<franka_spine_msgs::msg::SpineParameters>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__TRAITS_HPP_
