// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from franka_spine_msgs:srv/GetSpineState.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "franka_spine_msgs/srv/detail/get_spine_state__struct.h"
#include "franka_spine_msgs/srv/detail/get_spine_state__type_support.h"
#include "franka_spine_msgs/srv/detail/get_spine_state__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetSpineState_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetSpineState_Request_type_support_ids_t;

static const _GetSpineState_Request_type_support_ids_t _GetSpineState_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetSpineState_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetSpineState_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetSpineState_Request_type_support_symbol_names_t _GetSpineState_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, srv, GetSpineState_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, srv, GetSpineState_Request)),
  }
};

typedef struct _GetSpineState_Request_type_support_data_t
{
  void * data[2];
} _GetSpineState_Request_type_support_data_t;

static _GetSpineState_Request_type_support_data_t _GetSpineState_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetSpineState_Request_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_GetSpineState_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GetSpineState_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GetSpineState_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetSpineState_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetSpineState_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__srv__GetSpineState_Request__get_type_hash,
  &franka_spine_msgs__srv__GetSpineState_Request__get_type_description,
  &franka_spine_msgs__srv__GetSpineState_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, srv, GetSpineState_Request)() {
  return &::franka_spine_msgs::srv::rosidl_typesupport_c::GetSpineState_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/srv/detail/get_spine_state__struct.h"
// already included above
// #include "franka_spine_msgs/srv/detail/get_spine_state__type_support.h"
// already included above
// #include "franka_spine_msgs/srv/detail/get_spine_state__functions.h"
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

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetSpineState_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetSpineState_Response_type_support_ids_t;

static const _GetSpineState_Response_type_support_ids_t _GetSpineState_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetSpineState_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetSpineState_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetSpineState_Response_type_support_symbol_names_t _GetSpineState_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, srv, GetSpineState_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, srv, GetSpineState_Response)),
  }
};

typedef struct _GetSpineState_Response_type_support_data_t
{
  void * data[2];
} _GetSpineState_Response_type_support_data_t;

static _GetSpineState_Response_type_support_data_t _GetSpineState_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetSpineState_Response_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_GetSpineState_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GetSpineState_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GetSpineState_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetSpineState_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetSpineState_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__srv__GetSpineState_Response__get_type_hash,
  &franka_spine_msgs__srv__GetSpineState_Response__get_type_description,
  &franka_spine_msgs__srv__GetSpineState_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, srv, GetSpineState_Response)() {
  return &::franka_spine_msgs::srv::rosidl_typesupport_c::GetSpineState_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/srv/detail/get_spine_state__struct.h"
// already included above
// #include "franka_spine_msgs/srv/detail/get_spine_state__type_support.h"
// already included above
// #include "franka_spine_msgs/srv/detail/get_spine_state__functions.h"
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

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _GetSpineState_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetSpineState_Event_type_support_ids_t;

static const _GetSpineState_Event_type_support_ids_t _GetSpineState_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetSpineState_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetSpineState_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetSpineState_Event_type_support_symbol_names_t _GetSpineState_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, srv, GetSpineState_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, srv, GetSpineState_Event)),
  }
};

typedef struct _GetSpineState_Event_type_support_data_t
{
  void * data[2];
} _GetSpineState_Event_type_support_data_t;

static _GetSpineState_Event_type_support_data_t _GetSpineState_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetSpineState_Event_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_GetSpineState_Event_message_typesupport_ids.typesupport_identifier[0],
  &_GetSpineState_Event_message_typesupport_symbol_names.symbol_name[0],
  &_GetSpineState_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GetSpineState_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetSpineState_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &franka_spine_msgs__srv__GetSpineState_Event__get_type_hash,
  &franka_spine_msgs__srv__GetSpineState_Event__get_type_description,
  &franka_spine_msgs__srv__GetSpineState_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, srv, GetSpineState_Event)() {
  return &::franka_spine_msgs::srv::rosidl_typesupport_c::GetSpineState_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/srv/detail/get_spine_state__type_support.h"
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

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _GetSpineState_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GetSpineState_type_support_ids_t;

static const _GetSpineState_type_support_ids_t _GetSpineState_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GetSpineState_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GetSpineState_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GetSpineState_type_support_symbol_names_t _GetSpineState_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_spine_msgs, srv, GetSpineState)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, franka_spine_msgs, srv, GetSpineState)),
  }
};

typedef struct _GetSpineState_type_support_data_t
{
  void * data[2];
} _GetSpineState_type_support_data_t;

static _GetSpineState_type_support_data_t _GetSpineState_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GetSpineState_service_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_GetSpineState_service_typesupport_ids.typesupport_identifier[0],
  &_GetSpineState_service_typesupport_symbol_names.symbol_name[0],
  &_GetSpineState_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GetSpineState_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GetSpineState_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &GetSpineState_Request_message_type_support_handle,
  &GetSpineState_Response_message_type_support_handle,
  &GetSpineState_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    franka_spine_msgs,
    srv,
    GetSpineState
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    franka_spine_msgs,
    srv,
    GetSpineState
  ),
  &franka_spine_msgs__srv__GetSpineState__get_type_hash,
  &franka_spine_msgs__srv__GetSpineState__get_type_description,
  &franka_spine_msgs__srv__GetSpineState__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace franka_spine_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, franka_spine_msgs, srv, GetSpineState)() {
  return &::franka_spine_msgs::srv::rosidl_typesupport_c::GetSpineState_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
