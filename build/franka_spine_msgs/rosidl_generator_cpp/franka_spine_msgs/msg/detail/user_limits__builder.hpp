// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from franka_spine_msgs:msg/UserLimits.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/user_limits.hpp"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__BUILDER_HPP_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "franka_spine_msgs/msg/detail/user_limits__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace franka_spine_msgs
{

namespace msg
{

namespace builder
{

class Init_UserLimits_upper_limit
{
public:
  explicit Init_UserLimits_upper_limit(::franka_spine_msgs::msg::UserLimits & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::msg::UserLimits upper_limit(::franka_spine_msgs::msg::UserLimits::_upper_limit_type arg)
  {
    msg_.upper_limit = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::msg::UserLimits msg_;
};

class Init_UserLimits_lower_limit
{
public:
  Init_UserLimits_lower_limit()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UserLimits_upper_limit lower_limit(::franka_spine_msgs::msg::UserLimits::_lower_limit_type arg)
  {
    msg_.lower_limit = std::move(arg);
    return Init_UserLimits_upper_limit(msg_);
  }

private:
  ::franka_spine_msgs::msg::UserLimits msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::msg::UserLimits>()
{
  return franka_spine_msgs::msg::builder::Init_UserLimits_lower_limit();
}

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__USER_LIMITS__BUILDER_HPP_
