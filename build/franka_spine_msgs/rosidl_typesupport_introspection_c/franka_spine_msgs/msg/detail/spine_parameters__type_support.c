// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from franka_spine_msgs:msg/SpineParameters.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "franka_spine_msgs/msg/detail/spine_parameters__rosidl_typesupport_introspection_c.h"
#include "franka_spine_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "franka_spine_msgs/msg/detail/spine_parameters__functions.h"
#include "franka_spine_msgs/msg/detail/spine_parameters__struct.h"


// Include directives for member types
// Member `user_limits`
#include "franka_spine_msgs/msg/user_limits.h"
// Member `user_limits`
#include "franka_spine_msgs/msg/detail/user_limits__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  franka_spine_msgs__msg__SpineParameters__init(message_memory);
}

void franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_fini_function(void * message_memory)
{
  franka_spine_msgs__msg__SpineParameters__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_message_member_array[1] = {
  {
    "user_limits",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(franka_spine_msgs__msg__SpineParameters, user_limits),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_message_members = {
  "franka_spine_msgs__msg",  // message namespace
  "SpineParameters",  // message name
  1,  // number of fields
  sizeof(franka_spine_msgs__msg__SpineParameters),
  false,  // has_any_key_member_
  franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_message_member_array,  // message members
  franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_init_function,  // function to initialize message memory (memory has to be allocated)
  franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_message_type_support_handle = {
  0,
  &franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_message_members,
  get_message_typesupport_handle_function,
  &franka_spine_msgs__msg__SpineParameters__get_type_hash,
  &franka_spine_msgs__msg__SpineParameters__get_type_description,
  &franka_spine_msgs__msg__SpineParameters__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_franka_spine_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, msg, SpineParameters)() {
  franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, msg, UserLimits)();
  if (!franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_message_type_support_handle.typesupport_identifier) {
    franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &franka_spine_msgs__msg__SpineParameters__rosidl_typesupport_introspection_c__SpineParameters_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
