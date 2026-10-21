// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from franka_spine_msgs:msg/SpineParameters.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/spine_parameters.hpp"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__BUILDER_HPP_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "franka_spine_msgs/msg/detail/spine_parameters__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace franka_spine_msgs
{

namespace msg
{

namespace builder
{

class Init_SpineParameters_user_limits
{
public:
  Init_SpineParameters_user_limits()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::franka_spine_msgs::msg::SpineParameters user_limits(::franka_spine_msgs::msg::SpineParameters::_user_limits_type arg)
  {
    msg_.user_limits = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::msg::SpineParameters msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::msg::SpineParameters>()
{
  return franka_spine_msgs::msg::builder::Init_SpineParameters_user_limits();
}

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_PARAMETERS__BUILDER_HPP_
