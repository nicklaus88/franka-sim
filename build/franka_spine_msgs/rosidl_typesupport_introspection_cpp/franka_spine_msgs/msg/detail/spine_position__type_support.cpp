// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from franka_spine_msgs:msg/SpinePosition.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "franka_spine_msgs/msg/detail/spine_position__functions.h"
#include "franka_spine_msgs/msg/detail/spine_position__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace franka_spine_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SpinePosition_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) franka_spine_msgs::msg::SpinePosition(_init);
}

void SpinePosition_fini_function(void * message_memory)
{
  auto typed_message = static_cast<franka_spine_msgs::msg::SpinePosition *>(message_memory);
  typed_message->~SpinePosition();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SpinePosition_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(franka_spine_msgs::msg::SpinePosition, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(franka_spine_msgs::msg::SpinePosition, position),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "valid",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(franka_spine_msgs::msg::SpinePosition, valid),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SpinePosition_message_members = {
  "franka_spine_msgs::msg",  // message namespace
  "SpinePosition",  // message name
  3,  // number of fields
  sizeof(franka_spine_msgs::msg::SpinePosition),
  false,  // has_any_key_member_
  SpinePosition_message_member_array,  // message members
  SpinePosition_init_function,  // function to initialize message memory (memory has to be allocated)
  SpinePosition_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SpinePosition_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SpinePosition_message_members,
  get_message_typesupport_handle_function,
  &franka_spine_msgs__msg__SpinePosition__get_type_hash,
  &franka_spine_msgs__msg__SpinePosition__get_type_description,
  &franka_spine_msgs__msg__SpinePosition__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace franka_spine_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<franka_spine_msgs::msg::SpinePosition>()
{
  return &::franka_spine_msgs::msg::rosidl_typesupport_introspection_cpp::SpinePosition_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, franka_spine_msgs, msg, SpinePosition)() {
  return &::franka_spine_msgs::msg::rosidl_typesupport_introspection_cpp::SpinePosition_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
