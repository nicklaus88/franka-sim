// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from franka_spine_msgs:msg/SpineState.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/spine_state.h"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_STATE__STRUCT_H_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'state'
// Member 'error_code'
// Member 'error_description'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/SpineState in the package franka_spine_msgs.
/**
  * Periodic spine state sample published on ~/state.
  * Subscribe to this instead of polling the GetSpineState service in a loop.
  * Possible states: NotReadyToSwitchOn, SwitchedOff, ReadyToSwitchOn,
  *   MotorOff, SwitchedOn, QuickStopActive, FaultReactionActive, Fault, Unknown.
 */
typedef struct franka_spine_msgs__msg__SpineState
{
  std_msgs__msg__Header header;
  /// Current spine state
  rosidl_runtime_c__String state;
  /// Error code (empty when no error)
  rosidl_runtime_c__String error_code;
  /// Human-readable error description
  rosidl_runtime_c__String error_description;
  /// False when the sample is stale because the REST read failed
  bool valid;
} franka_spine_msgs__msg__SpineState;

// Struct for a sequence of franka_spine_msgs__msg__SpineState.
typedef struct franka_spine_msgs__msg__SpineState__Sequence
{
  franka_spine_msgs__msg__SpineState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__msg__SpineState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_STATE__STRUCT_H_
