// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from franka_spine_msgs:msg/SpinePosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/msg/spine_position.h"


#ifndef FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__STRUCT_H_
#define FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__STRUCT_H_

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

/// Struct defined in msg/SpinePosition in the package franka_spine_msgs.
/**
  * Periodic spine position sample published on ~/position.
  * Subscribe to this instead of polling the GetPosition service in a loop.
 */
typedef struct franka_spine_msgs__msg__SpinePosition
{
  std_msgs__msg__Header header;
  /// Last known position
  double position;
  /// False when the sample is stale because the REST read failed
  bool valid;
} franka_spine_msgs__msg__SpinePosition;

// Struct for a sequence of franka_spine_msgs__msg__SpinePosition.
typedef struct franka_spine_msgs__msg__SpinePosition__Sequence
{
  franka_spine_msgs__msg__SpinePosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__msg__SpinePosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FRANKA_SPINE_MSGS__MSG__DETAIL__SPINE_POSITION__STRUCT_H_
