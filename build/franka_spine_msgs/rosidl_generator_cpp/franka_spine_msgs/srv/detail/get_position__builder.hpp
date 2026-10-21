// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from franka_spine_msgs:srv/GetPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/srv/get_position.hpp"


#ifndef FRANKA_SPINE_MSGS__SRV__DETAIL__GET_POSITION__BUILDER_HPP_
#define FRANKA_SPINE_MSGS__SRV__DETAIL__GET_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "franka_spine_msgs/srv/detail/get_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace franka_spine_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::srv::GetPosition_Request>()
{
  return ::franka_spine_msgs::srv::GetPosition_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPosition_Response_success
{
public:
  explicit Init_GetPosition_Response_success(::franka_spine_msgs::srv::GetPosition_Response & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::srv::GetPosition_Response success(::franka_spine_msgs::srv::GetPosition_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetPosition_Response msg_;
};

class Init_GetPosition_Response_position
{
public:
  Init_GetPosition_Response_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPosition_Response_success position(::franka_spine_msgs::srv::GetPosition_Response::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_GetPosition_Response_success(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetPosition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::srv::GetPosition_Response>()
{
  return franka_spine_msgs::srv::builder::Init_GetPosition_Response_position();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPosition_Event_response
{
public:
  explicit Init_GetPosition_Event_response(::franka_spine_msgs::srv::GetPosition_Event & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::srv::GetPosition_Event response(::franka_spine_msgs::srv::GetPosition_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetPosition_Event msg_;
};

class Init_GetPosition_Event_request
{
public:
  explicit Init_GetPosition_Event_request(::franka_spine_msgs::srv::GetPosition_Event & msg)
  : msg_(msg)
  {}
  Init_GetPosition_Event_response request(::franka_spine_msgs::srv::GetPosition_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetPosition_Event_response(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetPosition_Event msg_;
};

class Init_GetPosition_Event_info
{
public:
  Init_GetPosition_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPosition_Event_request info(::franka_spine_msgs::srv::GetPosition_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetPosition_Event_request(msg_);
  }

private:
  ::franka_spine_msgs::srv::GetPosition_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::srv::GetPosition_Event>()
{
  return franka_spine_msgs::srv::builder::Init_GetPosition_Event_info();
}

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__SRV__DETAIL__GET_POSITION__BUILDER_HPP_
