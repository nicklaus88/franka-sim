// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from franka_spine_msgs:action/MoveAbsolute.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "franka_spine_msgs/action/move_absolute.h"


#ifndef FRANKA_SPINE_MSGS__ACTION__DETAIL__MOVE_ABSOLUTE__STRUCT_H_
#define FRANKA_SPINE_MSGS__ACTION__DETAIL__MOVE_ABSOLUTE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/MoveAbsolute in the package franka_spine_msgs.
typedef struct franka_spine_msgs__action__MoveAbsolute_Goal
{
  /// Target position
  double position;
  /// Motion velocity, must be > 0
  double velocity;
  /// Motion acceleration, must be > 0
  double acceleration;
  /// Motion deceleration, must be > 0
  double deceleration;
} franka_spine_msgs__action__MoveAbsolute_Goal;

// Struct for a sequence of franka_spine_msgs__action__MoveAbsolute_Goal.
typedef struct franka_spine_msgs__action__MoveAbsolute_Goal__Sequence
{
  franka_spine_msgs__action__MoveAbsolute_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__action__MoveAbsolute_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stop_by'
// Member 'error'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/MoveAbsolute in the package franka_spine_msgs.
typedef struct franka_spine_msgs__action__MoveAbsolute_Result
{
  /// True if the target position was reached
  bool success;
  /// How the motion was stopped (from spine response)
  rosidl_runtime_c__String stop_by;
  /// Error description if success is false
  rosidl_runtime_c__String error;
} franka_spine_msgs__action__MoveAbsolute_Result;

// Struct for a sequence of franka_spine_msgs__action__MoveAbsolute_Result.
typedef struct franka_spine_msgs__action__MoveAbsolute_Result__Sequence
{
  franka_spine_msgs__action__MoveAbsolute_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__action__MoveAbsolute_Result__Sequence;

// Constants defined in the message

/// Struct defined in action/MoveAbsolute in the package franka_spine_msgs.
typedef struct franka_spine_msgs__action__MoveAbsolute_Feedback
{
  /// Current spine position
  double current_position;
} franka_spine_msgs__action__MoveAbsolute_Feedback;

// Struct for a sequence of franka_spine_msgs__action__MoveAbsolute_Feedback.
typedef struct franka_spine_msgs__action__MoveAbsolute_Feedback__Sequence
{
  franka_spine_msgs__action__MoveAbsolute_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__action__MoveAbsolute_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "franka_spine_msgs/action/detail/move_absolute__struct.h"

/// Struct defined in action/MoveAbsolute in the package franka_spine_msgs.
typedef struct franka_spine_msgs__action__MoveAbsolute_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  franka_spine_msgs__action__MoveAbsolute_Goal goal;
} franka_spine_msgs__action__MoveAbsolute_SendGoal_Request;

// Struct for a sequence of franka_spine_msgs__action__MoveAbsolute_SendGoal_Request.
typedef struct franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__Sequence
{
  franka_spine_msgs__action__MoveAbsolute_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/MoveAbsolute in the package franka_spine_msgs.
typedef struct franka_spine_msgs__action__MoveAbsolute_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} franka_spine_msgs__action__MoveAbsolute_SendGoal_Response;

// Struct for a sequence of franka_spine_msgs__action__MoveAbsolute_SendGoal_Response.
typedef struct franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__Sequence
{
  franka_spine_msgs__action__MoveAbsolute_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  franka_spine_msgs__action__MoveAbsolute_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  franka_spine_msgs__action__MoveAbsolute_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/MoveAbsolute in the package franka_spine_msgs.
typedef struct franka_spine_msgs__action__MoveAbsolute_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__Sequence request;
  franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__Sequence response;
} franka_spine_msgs__action__MoveAbsolute_SendGoal_Event;

// Struct for a sequence of franka_spine_msgs__action__MoveAbsolute_SendGoal_Event.
typedef struct franka_spine_msgs__action__MoveAbsolute_SendGoal_Event__Sequence
{
  franka_spine_msgs__action__MoveAbsolute_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__action__MoveAbsolute_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/MoveAbsolute in the package franka_spine_msgs.
typedef struct franka_spine_msgs__action__MoveAbsolute_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} franka_spine_msgs__action__MoveAbsolute_GetResult_Request;

// Struct for a sequence of franka_spine_msgs__action__MoveAbsolute_GetResult_Request.
typedef struct franka_spine_msgs__action__MoveAbsolute_GetResult_Request__Sequence
{
  franka_spine_msgs__action__MoveAbsolute_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__action__MoveAbsolute_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__struct.h"

/// Struct defined in action/MoveAbsolute in the package franka_spine_msgs.
typedef struct franka_spine_msgs__action__MoveAbsolute_GetResult_Response
{
  int8_t status;
  franka_spine_msgs__action__MoveAbsolute_Result result;
} franka_spine_msgs__action__MoveAbsolute_GetResult_Response;

// Struct for a sequence of franka_spine_msgs__action__MoveAbsolute_GetResult_Response.
typedef struct franka_spine_msgs__action__MoveAbsolute_GetResult_Response__Sequence
{
  franka_spine_msgs__action__MoveAbsolute_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__action__MoveAbsolute_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  franka_spine_msgs__action__MoveAbsolute_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  franka_spine_msgs__action__MoveAbsolute_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/MoveAbsolute in the package franka_spine_msgs.
typedef struct franka_spine_msgs__action__MoveAbsolute_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  franka_spine_msgs__action__MoveAbsolute_GetResult_Request__Sequence request;
  franka_spine_msgs__action__MoveAbsolute_GetResult_Response__Sequence response;
} franka_spine_msgs__action__MoveAbsolute_GetResult_Event;

// Struct for a sequence of franka_spine_msgs__action__MoveAbsolute_GetResult_Event.
typedef struct franka_spine_msgs__action__MoveAbsolute_GetResult_Event__Sequence
{
  franka_spine_msgs__action__MoveAbsolute_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__action__MoveAbsolute_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__struct.h"

/// Struct defined in action/MoveAbsolute in the package franka_spine_msgs.
typedef struct franka_spine_msgs__action__MoveAbsolute_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  franka_spine_msgs__action__MoveAbsolute_Feedback feedback;
} franka_spine_msgs__action__MoveAbsolute_FeedbackMessage;

// Struct for a sequence of franka_spine_msgs__action__MoveAbsolute_FeedbackMessage.
typedef struct franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__Sequence
{
  franka_spine_msgs__action__MoveAbsolute_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FRANKA_SPINE_MSGS__ACTION__DETAIL__MOVE_ABSOLUTE__STRUCT_H_
