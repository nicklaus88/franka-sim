// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from franka_spine_msgs:srv/FaultReset.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "franka_spine_msgs/srv/detail/fault_reset__functions.h"
#include "franka_spine_msgs/srv/detail/fault_reset__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _FaultReset_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FaultReset_Request_type_support_ids_t;

static const _FaultReset_Request_type_support_ids_t _FaultReset_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _FaultReset_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FaultReset_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FaultReset_Request_type_support_symbol_names_t _FaultReset_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, franka_spine_msgs, srv, FaultReset_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, franka_spine_msgs, srv, FaultReset_Request)),
  }
};

typedef struct _FaultReset_Request_type_support_data_t
{
  void * data[2];
} _FaultReset_Request_type_support_data_t;

static _FaultReset_Request_type_support_data_t _FaultReset_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FaultReset_Request_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_FaultReset_Request_message_typesupport_ids.typesupport_identifier[0],
  &_FaultReset_Request_message_typesupport_symbol_names.symbol_name[0],
  &_FaultReset_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FaultReset_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FaultReset_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &franka_spine_msgs__srv__FaultReset_Request__get_type_hash,
  &franka_spine_msgs__srv__FaultReset_Request__get_type_description,
  &franka_spine_msgs__srv__FaultReset_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace franka_spine_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<franka_spine_msgs::srv::FaultReset_Request>()
{
  return &::franka_spine_msgs::srv::rosidl_typesupport_cpp::FaultReset_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, franka_spine_msgs, srv, FaultReset_Request)() {
  return get_message_type_support_handle<franka_spine_msgs::srv::FaultReset_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/srv/detail/fault_reset__functions.h"
// already included above
// #include "franka_spine_msgs/srv/detail/fault_reset__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _FaultReset_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FaultReset_Response_type_support_ids_t;

static const _FaultReset_Response_type_support_ids_t _FaultReset_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _FaultReset_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FaultReset_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FaultReset_Response_type_support_symbol_names_t _FaultReset_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, franka_spine_msgs, srv, FaultReset_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, franka_spine_msgs, srv, FaultReset_Response)),
  }
};

typedef struct _FaultReset_Response_type_support_data_t
{
  void * data[2];
} _FaultReset_Response_type_support_data_t;

static _FaultReset_Response_type_support_data_t _FaultReset_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FaultReset_Response_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_FaultReset_Response_message_typesupport_ids.typesupport_identifier[0],
  &_FaultReset_Response_message_typesupport_symbol_names.symbol_name[0],
  &_FaultReset_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FaultReset_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FaultReset_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &franka_spine_msgs__srv__FaultReset_Response__get_type_hash,
  &franka_spine_msgs__srv__FaultReset_Response__get_type_description,
  &franka_spine_msgs__srv__FaultReset_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace franka_spine_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<franka_spine_msgs::srv::FaultReset_Response>()
{
  return &::franka_spine_msgs::srv::rosidl_typesupport_cpp::FaultReset_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, franka_spine_msgs, srv, FaultReset_Response)() {
  return get_message_type_support_handle<franka_spine_msgs::srv::FaultReset_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "franka_spine_msgs/srv/detail/fault_reset__functions.h"
// already included above
// #include "franka_spine_msgs/srv/detail/fault_reset__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _FaultReset_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FaultReset_Event_type_support_ids_t;

static const _FaultReset_Event_type_support_ids_t _FaultReset_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _FaultReset_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FaultReset_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FaultReset_Event_type_support_symbol_names_t _FaultReset_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, franka_spine_msgs, srv, FaultReset_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, franka_spine_msgs, srv, FaultReset_Event)),
  }
};

typedef struct _FaultReset_Event_type_support_data_t
{
  void * data[2];
} _FaultReset_Event_type_support_data_t;

static _FaultReset_Event_type_support_data_t _FaultReset_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FaultReset_Event_message_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_FaultReset_Event_message_typesupport_ids.typesupport_identifier[0],
  &_FaultReset_Event_message_typesupport_symbol_names.symbol_name[0],
  &_FaultReset_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t FaultReset_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FaultReset_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &franka_spine_msgs__srv__FaultReset_Event__get_type_hash,
  &franka_spine_msgs__srv__FaultReset_Event__get_type_description,
  &franka_spine_msgs__srv__FaultReset_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace franka_spine_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<franka_spine_msgs::srv::FaultReset_Event>()
{
  return &::franka_spine_msgs::srv::rosidl_typesupport_cpp::FaultReset_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, franka_spine_msgs, srv, FaultReset_Event)() {
  return get_message_type_support_handle<franka_spine_msgs::srv::FaultReset_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "franka_spine_msgs/srv/detail/fault_reset__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace franka_spine_msgs
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _FaultReset_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _FaultReset_type_support_ids_t;

static const _FaultReset_type_support_ids_t _FaultReset_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _FaultReset_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _FaultReset_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _FaultReset_type_support_symbol_names_t _FaultReset_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, franka_spine_msgs, srv, FaultReset)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, franka_spine_msgs, srv, FaultReset)),
  }
};

typedef struct _FaultReset_type_support_data_t
{
  void * data[2];
} _FaultReset_type_support_data_t;

static _FaultReset_type_support_data_t _FaultReset_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _FaultReset_service_typesupport_map = {
  2,
  "franka_spine_msgs",
  &_FaultReset_service_typesupport_ids.typesupport_identifier[0],
  &_FaultReset_service_typesupport_symbol_names.symbol_name[0],
  &_FaultReset_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t FaultReset_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_FaultReset_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<franka_spine_msgs::srv::FaultReset_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<franka_spine_msgs::srv::FaultReset_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<franka_spine_msgs::srv::FaultReset_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<franka_spine_msgs::srv::FaultReset>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<franka_spine_msgs::srv::FaultReset>,
  &franka_spine_msgs__srv__FaultReset__get_type_hash,
  &franka_spine_msgs__srv__FaultReset__get_type_description,
  &franka_spine_msgs__srv__FaultReset__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace franka_spine_msgs

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<franka_spine_msgs::srv::FaultReset>()
{
  return &::franka_spine_msgs::srv::rosidl_typesupport_cpp::FaultReset_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, franka_spine_msgs, srv, FaultReset)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<franka_spine_msgs::srv::FaultReset>();
}

#ifdef __cplusplus
}
#endif
