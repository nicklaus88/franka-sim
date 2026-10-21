// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from franka_spine_msgs:msg/UserLimits.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/user_limits.hpp"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__TRAITS_HPP_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "franka_spine_msgs/msg/detail/user_limits__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace franka_spine_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const UserLimits & msg,
  std::ostream & out)
{
  out << "{";
  // member: lower_limit
  {
    out << "lower_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.lower_limit, out);
    out << ", ";
  }

  // member: upper_limit
  {
    out << "upper_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.upper_limit, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UserLimits & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: lower_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "lower_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.lower_limit, out);
    out << "\n";
  }

  // member: upper_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "upper_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.upper_limit, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UserLimits & msg, bool use_flow_style = false)
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
  const franka_spine_msgs::msg::UserLimits & msg,
  std::ostream & out, size_t indentation = 0)
{
  franka_spine_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use franka_spine_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const franka_spine_msgs::msg::UserLimits & msg)
{
  return franka_spine_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<franka_spine_msgs::msg::UserLimits>()
{
  return "franka_spine_msgs::msg::UserLimits";
}

template<>
inline const char * name<franka_spine_msgs::msg::UserLimits>()
{
  return "franka_spine_msgs/msg/UserLimits";
}

template<>
struct has_fixed_size<franka_spine_msgs::msg::UserLimits>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<franka_spine_msgs::msg::UserLimits>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<franka_spine_msgs::msg::UserLimits>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__TRAITS_HPP_
