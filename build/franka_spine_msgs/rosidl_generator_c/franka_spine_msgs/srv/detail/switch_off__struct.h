// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from franka_spine_msgs:srv/SwitchOff.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/srv/switch_off.h"


#ifndef FRANKA_SPINE_MSGS__SRV__DETAIL__SWITCH_OFF__STRUCT_H_
#define FRANKA_SPINE_MSGS__SRV__DETAIL__SWITCH_OFF__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SwitchOff in the package franka_spine_msgs.
typedef struct franka_spine_msgs__srv__SwitchOff_Request
{
  uint8_t structure_needs_at_least_one_member;
} franka_spine_msgs__srv__SwitchOff_Request;

// Struct for a sequence of franka_spine_msgs__srv__SwitchOff_Request.
typedef struct franka_spine_msgs__srv__SwitchOff_Request__Sequence
{
  franka_spine_msgs__srv__SwitchOff_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__srv__SwitchOff_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'state'
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SwitchOff in the package franka_spine_msgs.
typedef struct franka_spine_msgs__srv__SwitchOff_Response
{
  /// Spine state after switching off
  rosidl_runtime_c__String state;
  /// True if the transition succeeded
  bool success;
  /// Human-readable status or error description
  rosidl_runtime_c__String message;
} franka_spine_msgs__srv__SwitchOff_Response;

// Struct for a sequence of franka_spine_msgs__srv__SwitchOff_Response.
typedef struct franka_spine_msgs__srv__SwitchOff_Response__Sequence
{
  franka_spine_msgs__srv__SwitchOff_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__srv__SwitchOff_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  franka_spine_msgs__srv__SwitchOff_Event__request__MAX_SIZE = 1
};
// response
enum
{
  franka_spine_msgs__srv__SwitchOff_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/SwitchOff in the package franka_spine_msgs.
typedef struct franka_spine_msgs__srv__SwitchOff_Event
{
  service_msgs__msg__ServiceEventInfo info;
  franka_spine_msgs__srv__SwitchOff_Request__Sequence request;
  franka_spine_msgs__srv__SwitchOff_Response__Sequence response;
} franka_spine_msgs__srv__SwitchOff_Event;

// Struct for a sequence of franka_spine_msgs__srv__SwitchOff_Event.
typedef struct franka_spine_msgs__srv__SwitchOff_Event__Sequence
{
  franka_spine_msgs__srv__SwitchOff_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__srv__SwitchOff_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FRANKA_SPINE_MSGS__SRV__DETAIL__SWITCH_OFF__STRUCT_H_
