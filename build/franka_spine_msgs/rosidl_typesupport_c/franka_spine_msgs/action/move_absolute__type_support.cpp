// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from franka_spine_msgs:action/MoveAbsolute.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "franka_spine_msgs/action/detail/move_absolute__struct.h"
#include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
#include "franka_spine_msgs/action/detail/move_absolute__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveAbsolute_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_Goal_type_support_ids_t;

static const _MoveAbsolute_Goal_type_support_ids_t _MoveAbsolute_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_Goal_type_support_symbol_names_t _MoveAbsolute_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_Goal)),
  }
};

typedef struct _MoveAbsolute_Goal_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_Goal_type_support_data_t;

static _MoveAbsolute_Goal_type_support_data_t _MoveAbsolute_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_Goal_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAbsolute_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__action__MoveAbsolute_Goal__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_Goal__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_Goal)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveAbsolute_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_Result_type_support_ids_t;

static const _MoveAbsolute_Result_type_support_ids_t _MoveAbsolute_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_Result_type_support_symbol_names_t _MoveAbsolute_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_Result)),
  }
};

typedef struct _MoveAbsolute_Result_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_Result_type_support_data_t;

static _MoveAbsolute_Result_type_support_data_t _MoveAbsolute_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_Result_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_Result_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_Result_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAbsolute_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__action__MoveAbsolute_Result__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_Result__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_Result)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveAbsolute_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_Feedback_type_support_ids_t;

static const _MoveAbsolute_Feedback_type_support_ids_t _MoveAbsolute_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_Feedback_type_support_symbol_names_t _MoveAbsolute_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_Feedback)),
  }
};

typedef struct _MoveAbsolute_Feedback_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_Feedback_type_support_data_t;

static _MoveAbsolute_Feedback_type_support_data_t _MoveAbsolute_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_Feedback_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAbsolute_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__action__MoveAbsolute_Feedback__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_Feedback__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_Feedback)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveAbsolute_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_SendGoal_Request_type_support_ids_t;

static const _MoveAbsolute_SendGoal_Request_type_support_ids_t _MoveAbsolute_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_SendGoal_Request_type_support_symbol_names_t _MoveAbsolute_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_SendGoal_Request)),
  }
};

typedef struct _MoveAbsolute_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_SendGoal_Request_type_support_data_t;

static _MoveAbsolute_SendGoal_Request_type_support_data_t _MoveAbsolute_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_SendGoal_Request_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAbsolute_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_SendGoal_Request)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveAbsolute_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_SendGoal_Response_type_support_ids_t;

static const _MoveAbsolute_SendGoal_Response_type_support_ids_t _MoveAbsolute_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_SendGoal_Response_type_support_symbol_names_t _MoveAbsolute_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_SendGoal_Response)),
  }
};

typedef struct _MoveAbsolute_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_SendGoal_Response_type_support_data_t;

static _MoveAbsolute_SendGoal_Response_type_support_data_t _MoveAbsolute_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_SendGoal_Response_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAbsolute_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_SendGoal_Response)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveAbsolute_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_SendGoal_Event_type_support_ids_t;

static const _MoveAbsolute_SendGoal_Event_type_support_ids_t _MoveAbsolute_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_SendGoal_Event_type_support_symbol_names_t _MoveAbsolute_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_SendGoal_Event)),
  }
};

typedef struct _MoveAbsolute_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_SendGoal_Event_type_support_data_t;

static _MoveAbsolute_SendGoal_Event_type_support_data_t _MoveAbsolute_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_SendGoal_Event_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAbsolute_SendGoal_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_SendGoal_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__action__MoveAbsolute_SendGoal_Event__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_SendGoal_Event__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_SendGoal_Event)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{
typedef struct _MoveAbsolute_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_SendGoal_type_support_ids_t;

static const _MoveAbsolute_SendGoal_type_support_ids_t _MoveAbsolute_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_SendGoal_type_support_symbol_names_t _MoveAbsolute_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_SendGoal)),
  }
};

typedef struct _MoveAbsolute_SendGoal_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_SendGoal_type_support_data_t;

static _MoveAbsolute_SendGoal_type_support_data_t _MoveAbsolute_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_SendGoal_service_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveAbsolute_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &MoveAbsolute_SendGoal_Request_message_type_support_handle,
  &MoveAbsolute_SendGoal_Response_message_type_support_handle,
  &MoveAbsolute_SendGoal_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    franka_spine_msgs,
    action,
    MoveAbsolute_SendGoal
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    franka_spine_msgs,
    action,
    MoveAbsolute_SendGoal
  ),
  &franka_spine_msgs__action__MoveAbsolute_SendGoal__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_SendGoal__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_SendGoal)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveAbsolute_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_GetResult_Request_type_support_ids_t;

static const _MoveAbsolute_GetResult_Request_type_support_ids_t _MoveAbsolute_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_GetResult_Request_type_support_symbol_names_t _MoveAbsolute_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_GetResult_Request)),
  }
};

typedef struct _MoveAbsolute_GetResult_Request_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_GetResult_Request_type_support_data_t;

static _MoveAbsolute_GetResult_Request_type_support_data_t _MoveAbsolute_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_GetResult_Request_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAbsolute_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__action__MoveAbsolute_GetResult_Request__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_GetResult_Request__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_GetResult_Request)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveAbsolute_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_GetResult_Response_type_support_ids_t;

static const _MoveAbsolute_GetResult_Response_type_support_ids_t _MoveAbsolute_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_GetResult_Response_type_support_symbol_names_t _MoveAbsolute_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_GetResult_Response)),
  }
};

typedef struct _MoveAbsolute_GetResult_Response_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_GetResult_Response_type_support_data_t;

static _MoveAbsolute_GetResult_Response_type_support_data_t _MoveAbsolute_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_GetResult_Response_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAbsolute_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__action__MoveAbsolute_GetResult_Response__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_GetResult_Response__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_GetResult_Response)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveAbsolute_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_GetResult_Event_type_support_ids_t;

static const _MoveAbsolute_GetResult_Event_type_support_ids_t _MoveAbsolute_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_GetResult_Event_type_support_symbol_names_t _MoveAbsolute_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_GetResult_Event)),
  }
};

typedef struct _MoveAbsolute_GetResult_Event_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_GetResult_Event_type_support_data_t;

static _MoveAbsolute_GetResult_Event_type_support_data_t _MoveAbsolute_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_GetResult_Event_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAbsolute_GetResult_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_GetResult_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__action__MoveAbsolute_GetResult_Event__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_GetResult_Event__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_GetResult_Event)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "service_msgs/msg/service_event_info.h"
// already included above
// #include "builtin_interfaces/msg/time.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{
typedef struct _MoveAbsolute_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_GetResult_type_support_ids_t;

static const _MoveAbsolute_GetResult_type_support_ids_t _MoveAbsolute_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_GetResult_type_support_symbol_names_t _MoveAbsolute_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_GetResult)),
  }
};

typedef struct _MoveAbsolute_GetResult_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_GetResult_type_support_data_t;

static _MoveAbsolute_GetResult_type_support_data_t _MoveAbsolute_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_GetResult_service_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t MoveAbsolute_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &MoveAbsolute_GetResult_Request_message_type_support_handle,
  &MoveAbsolute_GetResult_Response_message_type_support_handle,
  &MoveAbsolute_GetResult_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    franka_spine_msgs,
    action,
    MoveAbsolute_GetResult
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    franka_spine_msgs,
    action,
    MoveAbsolute_GetResult
  ),
  &franka_spine_msgs__action__MoveAbsolute_GetResult__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_GetResult__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_GetResult)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__struct.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _MoveAbsolute_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MoveAbsolute_FeedbackMessage_type_support_ids_t;

static const _MoveAbsolute_FeedbackMessage_type_support_ids_t _MoveAbsolute_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _MoveAbsolute_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MoveAbsolute_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MoveAbsolute_FeedbackMessage_type_support_symbol_names_t _MoveAbsolute_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, action, MoveAbsolute_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, action, MoveAbsolute_FeedbackMessage)),
  }
};

typedef struct _MoveAbsolute_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _MoveAbsolute_FeedbackMessage_type_support_data_t;

static _MoveAbsolute_FeedbackMessage_type_support_data_t _MoveAbsolute_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MoveAbsolute_FeedbackMessage_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_MoveAbsolute_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_MoveAbsolute_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_MoveAbsolute_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MoveAbsolute_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MoveAbsolute_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_FeedbackMessage)() {
  return &::franka_spine_msgs::action::rosidl_typesupport_c::MoveAbsolute_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "franka_spine_msgs/action/move_absolute.h"
// already included above
// #include "franka_spine_msgs/action/detail/move_absolute__type_support.h"

static rosidl_action_type_support_t _franka_spine_msgs__action__MoveAbsolute__typesupport_c = {
  NULL, NULL, NULL, NULL, NULL,
  &franka_spine_msgs__action__MoveAbsolute__get_type_hash,
  &franka_spine_msgs__action__MoveAbsolute__get_type_description,
  &franka_spine_msgs__action__MoveAbsolute__get_type_description_sources,
};

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute)()
{
  // Thread-safe by always writing the same values to the static struct
  _franka_spine_msgs__action__MoveAbsolute__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_SendGoal)();
  _franka_spine_msgs__action__MoveAbsolute__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_GetResult)();
  _franka_spine_msgs__action__MoveAbsolute__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _franka_spine_msgs__action__MoveAbsolute__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, franka_spine_msgs, action, MoveAbsolute_FeedbackMessage)();
  _franka_spine_msgs__action__MoveAbsolute__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_franka_spine_msgs__action__MoveAbsolute__typesupport_c;
}

#ifdef __cplusplus
}
#endif
