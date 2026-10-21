// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from franka_spine_msgs:srv/GetPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/srv/get_position.h"


#ifndef FRANKA_SPINE_MSGS__SRV__DETAIL__GET_POSITION__STRUCT_H_
#define FRANKA_SPINE_MSGS__SRV__DETAIL__GET_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/GetPosition in the package franka_spine_msgs.
typedef struct franka_spine_msgs__srv__GetPosition_Request
{
  uint8_t structure_needs_at_least_one_member;
} franka_spine_msgs__srv__GetPosition_Request;

// Struct for a sequence of franka_spine_msgs__srv__GetPosition_Request.
typedef struct franka_spine_msgs__srv__GetPosition_Request__Sequence
{
  franka_spine_msgs__srv__GetPosition_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__srv__GetPosition_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/GetPosition in the package franka_spine_msgs.
typedef struct franka_spine_msgs__srv__GetPosition_Response
{
  /// Current position
  double position;
  /// True if the REST call succeeded
  bool success;
} franka_spine_msgs__srv__GetPosition_Response;

// Struct for a sequence of franka_spine_msgs__srv__GetPosition_Response.
typedef struct franka_spine_msgs__srv__GetPosition_Response__Sequence
{
  franka_spine_msgs__srv__GetPosition_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__srv__GetPosition_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  franka_spine_msgs__srv__GetPosition_Event__request__MAX_SIZE = 1
};
// response
enum
{
  franka_spine_msgs__srv__GetPosition_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetPosition in the package franka_spine_msgs.
typedef struct franka_spine_msgs__srv__GetPosition_Event
{
  service_msgs__msg__ServiceEventInfo info;
  franka_spine_msgs__srv__GetPosition_Request__Sequence request;
  franka_spine_msgs__srv__GetPosition_Response__Sequence response;
} franka_spine_msgs__srv__GetPosition_Event;

// Struct for a sequence of franka_spine_msgs__srv__GetPosition_Event.
typedef struct franka_spine_msgs__srv__GetPosition_Event__Sequence
{
  franka_spine_msgs__srv__GetPosition_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__srv__GetPosition_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FRANKA_SPINE_MSGS__SRV__DETAIL__GET_POSITION__STRUCT_H_
