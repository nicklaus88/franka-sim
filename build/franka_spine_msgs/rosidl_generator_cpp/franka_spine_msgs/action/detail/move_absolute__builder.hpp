// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from franka_spine_msgs:action/MoveAbsolute.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/action/move_absolute.hpp"


#ifndef FRANKA_SPINE_MSGS__ACTION__DETAIL__MOVE_ABSOLUTE__BUILDER_HPP_
#define FRANKA_SPINE_MSGS__ACTION__DETAIL__MOVE_ABSOLUTE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "franka_spine_msgs/action/detail/move_absolute__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace franka_spine_msgs
{

namespace action
{

namespace builder
{

class Init_MoveAbsolute_Goal_deceleration
{
public:
  explicit Init_MoveAbsolute_Goal_deceleration(::franka_spine_msgs::action::MoveAbsolute_Goal & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::action::MoveAbsolute_Goal deceleration(::franka_spine_msgs::action::MoveAbsolute_Goal::_deceleration_type arg)
  {
    msg_.deceleration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_Goal msg_;
};

class Init_MoveAbsolute_Goal_acceleration
{
public:
  explicit Init_MoveAbsolute_Goal_acceleration(::franka_spine_msgs::action::MoveAbsolute_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveAbsolute_Goal_deceleration acceleration(::franka_spine_msgs::action::MoveAbsolute_Goal::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return Init_MoveAbsolute_Goal_deceleration(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_Goal msg_;
};

class Init_MoveAbsolute_Goal_velocity
{
public:
  explicit Init_MoveAbsolute_Goal_velocity(::franka_spine_msgs::action::MoveAbsolute_Goal & msg)
  : msg_(msg)
  {}
  Init_MoveAbsolute_Goal_acceleration velocity(::franka_spine_msgs::action::MoveAbsolute_Goal::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_MoveAbsolute_Goal_acceleration(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_Goal msg_;
};

class Init_MoveAbsolute_Goal_position
{
public:
  Init_MoveAbsolute_Goal_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveAbsolute_Goal_velocity position(::franka_spine_msgs::action::MoveAbsolute_Goal::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_MoveAbsolute_Goal_velocity(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::action::MoveAbsolute_Goal>()
{
  return franka_spine_msgs::action::builder::Init_MoveAbsolute_Goal_position();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace action
{

namespace builder
{

class Init_MoveAbsolute_Result_error
{
public:
  explicit Init_MoveAbsolute_Result_error(::franka_spine_msgs::action::MoveAbsolute_Result & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::action::MoveAbsolute_Result error(::franka_spine_msgs::action::MoveAbsolute_Result::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_Result msg_;
};

class Init_MoveAbsolute_Result_stop_by
{
public:
  explicit Init_MoveAbsolute_Result_stop_by(::franka_spine_msgs::action::MoveAbsolute_Result & msg)
  : msg_(msg)
  {}
  Init_MoveAbsolute_Result_error stop_by(::franka_spine_msgs::action::MoveAbsolute_Result::_stop_by_type arg)
  {
    msg_.stop_by = std::move(arg);
    return Init_MoveAbsolute_Result_error(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_Result msg_;
};

class Init_MoveAbsolute_Result_success
{
public:
  Init_MoveAbsolute_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveAbsolute_Result_stop_by success(::franka_spine_msgs::action::MoveAbsolute_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveAbsolute_Result_stop_by(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::action::MoveAbsolute_Result>()
{
  return franka_spine_msgs::action::builder::Init_MoveAbsolute_Result_success();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace action
{

namespace builder
{

class Init_MoveAbsolute_Feedback_current_position
{
public:
  Init_MoveAbsolute_Feedback_current_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::franka_spine_msgs::action::MoveAbsolute_Feedback current_position(::franka_spine_msgs::action::MoveAbsolute_Feedback::_current_position_type arg)
  {
    msg_.current_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::action::MoveAbsolute_Feedback>()
{
  return franka_spine_msgs::action::builder::Init_MoveAbsolute_Feedback_current_position();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace action
{

namespace builder
{

class Init_MoveAbsolute_SendGoal_Request_goal
{
public:
  explicit Init_MoveAbsolute_SendGoal_Request_goal(::franka_spine_msgs::action::MoveAbsolute_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::action::MoveAbsolute_SendGoal_Request goal(::franka_spine_msgs::action::MoveAbsolute_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_SendGoal_Request msg_;
};

class Init_MoveAbsolute_SendGoal_Request_goal_id
{
public:
  Init_MoveAbsolute_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveAbsolute_SendGoal_Request_goal goal_id(::franka_spine_msgs::action::MoveAbsolute_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveAbsolute_SendGoal_Request_goal(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::action::MoveAbsolute_SendGoal_Request>()
{
  return franka_spine_msgs::action::builder::Init_MoveAbsolute_SendGoal_Request_goal_id();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace action
{

namespace builder
{

class Init_MoveAbsolute_SendGoal_Response_stamp
{
public:
  explicit Init_MoveAbsolute_SendGoal_Response_stamp(::franka_spine_msgs::action::MoveAbsolute_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::action::MoveAbsolute_SendGoal_Response stamp(::franka_spine_msgs::action::MoveAbsolute_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_SendGoal_Response msg_;
};

class Init_MoveAbsolute_SendGoal_Response_accepted
{
public:
  Init_MoveAbsolute_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveAbsolute_SendGoal_Response_stamp accepted(::franka_spine_msgs::action::MoveAbsolute_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveAbsolute_SendGoal_Response_stamp(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::action::MoveAbsolute_SendGoal_Response>()
{
  return franka_spine_msgs::action::builder::Init_MoveAbsolute_SendGoal_Response_accepted();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace action
{

namespace builder
{

class Init_MoveAbsolute_SendGoal_Event_response
{
public:
  explicit Init_MoveAbsolute_SendGoal_Event_response(::franka_spine_msgs::action::MoveAbsolute_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::action::MoveAbsolute_SendGoal_Event response(::franka_spine_msgs::action::MoveAbsolute_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_SendGoal_Event msg_;
};

class Init_MoveAbsolute_SendGoal_Event_request
{
public:
  explicit Init_MoveAbsolute_SendGoal_Event_request(::franka_spine_msgs::action::MoveAbsolute_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_MoveAbsolute_SendGoal_Event_response request(::franka_spine_msgs::action::MoveAbsolute_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoveAbsolute_SendGoal_Event_response(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_SendGoal_Event msg_;
};

class Init_MoveAbsolute_SendGoal_Event_info
{
public:
  Init_MoveAbsolute_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveAbsolute_SendGoal_Event_request info(::franka_spine_msgs::action::MoveAbsolute_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoveAbsolute_SendGoal_Event_request(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::action::MoveAbsolute_SendGoal_Event>()
{
  return franka_spine_msgs::action::builder::Init_MoveAbsolute_SendGoal_Event_info();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace action
{

namespace builder
{

class Init_MoveAbsolute_GetResult_Request_goal_id
{
public:
  Init_MoveAbsolute_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::franka_spine_msgs::action::MoveAbsolute_GetResult_Request goal_id(::franka_spine_msgs::action::MoveAbsolute_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::action::MoveAbsolute_GetResult_Request>()
{
  return franka_spine_msgs::action::builder::Init_MoveAbsolute_GetResult_Request_goal_id();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace action
{

namespace builder
{

class Init_MoveAbsolute_GetResult_Response_result
{
public:
  explicit Init_MoveAbsolute_GetResult_Response_result(::franka_spine_msgs::action::MoveAbsolute_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::action::MoveAbsolute_GetResult_Response result(::franka_spine_msgs::action::MoveAbsolute_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_GetResult_Response msg_;
};

class Init_MoveAbsolute_GetResult_Response_status
{
public:
  Init_MoveAbsolute_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveAbsolute_GetResult_Response_result status(::franka_spine_msgs::action::MoveAbsolute_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveAbsolute_GetResult_Response_result(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::action::MoveAbsolute_GetResult_Response>()
{
  return franka_spine_msgs::action::builder::Init_MoveAbsolute_GetResult_Response_status();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace action
{

namespace builder
{

class Init_MoveAbsolute_GetResult_Event_response
{
public:
  explicit Init_MoveAbsolute_GetResult_Event_response(::franka_spine_msgs::action::MoveAbsolute_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::action::MoveAbsolute_GetResult_Event response(::franka_spine_msgs::action::MoveAbsolute_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_GetResult_Event msg_;
};

class Init_MoveAbsolute_GetResult_Event_request
{
public:
  explicit Init_MoveAbsolute_GetResult_Event_request(::franka_spine_msgs::action::MoveAbsolute_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_MoveAbsolute_GetResult_Event_response request(::franka_spine_msgs::action::MoveAbsolute_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoveAbsolute_GetResult_Event_response(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_GetResult_Event msg_;
};

class Init_MoveAbsolute_GetResult_Event_info
{
public:
  Init_MoveAbsolute_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveAbsolute_GetResult_Event_request info(::franka_spine_msgs::action::MoveAbsolute_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoveAbsolute_GetResult_Event_request(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::action::MoveAbsolute_GetResult_Event>()
{
  return franka_spine_msgs::action::builder::Init_MoveAbsolute_GetResult_Event_info();
}

}  // namespace franka_spine_msgs


namespace franka_spine_msgs
{

namespace action
{

namespace builder
{

class Init_MoveAbsolute_FeedbackMessage_feedback
{
public:
  explicit Init_MoveAbsolute_FeedbackMessage_feedback(::franka_spine_msgs::action::MoveAbsolute_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::franka_spine_msgs::action::MoveAbsolute_FeedbackMessage feedback(::franka_spine_msgs::action::MoveAbsolute_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_FeedbackMessage msg_;
};

class Init_MoveAbsolute_FeedbackMessage_goal_id
{
public:
  Init_MoveAbsolute_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveAbsolute_FeedbackMessage_feedback goal_id(::franka_spine_msgs::action::MoveAbsolute_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveAbsolute_FeedbackMessage_feedback(msg_);
  }

private:
  ::franka_spine_msgs::action::MoveAbsolute_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::franka_spine_msgs::action::MoveAbsolute_FeedbackMessage>()
{
  return franka_spine_msgs::action::builder::Init_MoveAbsolute_FeedbackMessage_goal_id();
}

}  // namespace franka_spine_msgs

#endif  // FRANKA_SPINE_MSGS__ACTION__DETAIL__MOVE_ABSOLUTE__BUILDER_HPP_
