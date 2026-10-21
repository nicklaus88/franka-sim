// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from franka_spine_msgs:srv/SwitchOn.idl
// generated code does not contain a copyright notice

#include "franka_spine_msgs/srv/detail/switch_on__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_franka_spine_msgs
const rosidl_type_hash_t *
franka_spine_msgs__srv__SwitchOn__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x12, 0x22, 0x64, 0xc1, 0xdc, 0xca, 0xc6, 0x15,
      0xf7, 0xde, 0xb4, 0xd8, 0x3b, 0xe3, 0x19, 0x9e,
      0x8e, 0x9f, 0x68, 0xcb, 0xe5, 0x94, 0xff, 0x7f,
      0xea, 0x68, 0xad, 0x4c, 0xa9, 0xe6, 0xdc, 0xb2,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_franka_spine_msgs
const rosidl_type_hash_t *
franka_spine_msgs__srv__SwitchOn_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb3, 0x1d, 0xcd, 0x2d, 0x8a, 0xf1, 0x7a, 0xec,
      0xc1, 0x3b, 0xd0, 0x73, 0xf6, 0x41, 0xf8, 0x00,
      0x19, 0xb2, 0x04, 0x8e, 0x74, 0x88, 0xb4, 0x90,
      0x11, 0xba, 0x94, 0x5e, 0x6f, 0x47, 0x77, 0xe9,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_franka_spine_msgs
const rosidl_type_hash_t *
franka_spine_msgs__srv__SwitchOn_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1d, 0xbf, 0x80, 0x11, 0x5b, 0x78, 0xca, 0xc7,
      0x2c, 0x9e, 0x09, 0xf5, 0x9c, 0x5d, 0x53, 0xc1,
      0x8d, 0x2c, 0xba, 0xa1, 0xec, 0xeb, 0x55, 0x21,
      0xc7, 0x1e, 0x2a, 0x48, 0x01, 0x27, 0xdf, 0xb4,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_franka_spine_msgs
const rosidl_type_hash_t *
franka_spine_msgs__srv__SwitchOn_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xfa, 0x3c, 0xf7, 0xf6, 0x5f, 0x14, 0xe7, 0xce,
      0x26, 0x2f, 0x45, 0x72, 0x4c, 0xed, 0xa1, 0xfd,
      0x42, 0x8c, 0x34, 0x29, 0xd3, 0x83, 0x49, 0x7a,
      0x9a, 0x8f, 0x6f, 0x3c, 0x99, 0x1b, 0xd2, 0x9e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char franka_spine_msgs__srv__SwitchOn__TYPE_NAME[] = "franka_spine_msgs/srv/SwitchOn";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char franka_spine_msgs__srv__SwitchOn_Event__TYPE_NAME[] = "franka_spine_msgs/srv/SwitchOn_Event";
static char franka_spine_msgs__srv__SwitchOn_Request__TYPE_NAME[] = "franka_spine_msgs/srv/SwitchOn_Request";
static char franka_spine_msgs__srv__SwitchOn_Response__TYPE_NAME[] = "franka_spine_msgs/srv/SwitchOn_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char franka_spine_msgs__srv__SwitchOn__FIELD_NAME__request_message[] = "request_message";
static char franka_spine_msgs__srv__SwitchOn__FIELD_NAME__response_message[] = "response_message";
static char franka_spine_msgs__srv__SwitchOn__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field franka_spine_msgs__srv__SwitchOn__FIELDS[] = {
  {
    {franka_spine_msgs__srv__SwitchOn__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_spine_msgs__srv__SwitchOn_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__srv__SwitchOn__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_spine_msgs__srv__SwitchOn_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__srv__SwitchOn__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {franka_spine_msgs__srv__SwitchOn_Event__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription franka_spine_msgs__srv__SwitchOn__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__srv__SwitchOn_Event__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__srv__SwitchOn_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__srv__SwitchOn_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_spine_msgs__srv__SwitchOn__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_spine_msgs__srv__SwitchOn__TYPE_NAME, 30, 30},
      {franka_spine_msgs__srv__SwitchOn__FIELDS, 3, 3},
    },
    {franka_spine_msgs__srv__SwitchOn__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = franka_spine_msgs__srv__SwitchOn_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = franka_spine_msgs__srv__SwitchOn_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = franka_spine_msgs__srv__SwitchOn_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char franka_spine_msgs__srv__SwitchOn_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field franka_spine_msgs__srv__SwitchOn_Request__FIELDS[] = {
  {
    {franka_spine_msgs__srv__SwitchOn_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_spine_msgs__srv__SwitchOn_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_spine_msgs__srv__SwitchOn_Request__TYPE_NAME, 38, 38},
      {franka_spine_msgs__srv__SwitchOn_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char franka_spine_msgs__srv__SwitchOn_Response__FIELD_NAME__state[] = "state";
static char franka_spine_msgs__srv__SwitchOn_Response__FIELD_NAME__success[] = "success";
static char franka_spine_msgs__srv__SwitchOn_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field franka_spine_msgs__srv__SwitchOn_Response__FIELDS[] = {
  {
    {franka_spine_msgs__srv__SwitchOn_Response__FIELD_NAME__state, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__srv__SwitchOn_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__srv__SwitchOn_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_spine_msgs__srv__SwitchOn_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_spine_msgs__srv__SwitchOn_Response__TYPE_NAME, 39, 39},
      {franka_spine_msgs__srv__SwitchOn_Response__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char franka_spine_msgs__srv__SwitchOn_Event__FIELD_NAME__info[] = "info";
static char franka_spine_msgs__srv__SwitchOn_Event__FIELD_NAME__request[] = "request";
static char franka_spine_msgs__srv__SwitchOn_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field franka_spine_msgs__srv__SwitchOn_Event__FIELDS[] = {
  {
    {franka_spine_msgs__srv__SwitchOn_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__srv__SwitchOn_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {franka_spine_msgs__srv__SwitchOn_Request__TYPE_NAME, 38, 38},
    },
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__srv__SwitchOn_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {franka_spine_msgs__srv__SwitchOn_Response__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription franka_spine_msgs__srv__SwitchOn_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__srv__SwitchOn_Request__TYPE_NAME, 38, 38},
    {NULL, 0, 0},
  },
  {
    {franka_spine_msgs__srv__SwitchOn_Response__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
franka_spine_msgs__srv__SwitchOn_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {franka_spine_msgs__srv__SwitchOn_Event__TYPE_NAME, 36, 36},
      {franka_spine_msgs__srv__SwitchOn_Event__FIELDS, 3, 3},
    },
    {franka_spine_msgs__srv__SwitchOn_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = franka_spine_msgs__srv__SwitchOn_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = franka_spine_msgs__srv__SwitchOn_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Switch the spine on (transition to SwitchedOn, enabling motion).\n"
  "---\n"
  "string state    # Spine state after switching on\n"
  "bool success    # True if the transition succeeded\n"
  "string message  # Human-readable status or error description";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
franka_spine_msgs__srv__SwitchOn__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_spine_msgs__srv__SwitchOn__TYPE_NAME, 30, 30},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 232, 232},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
franka_spine_msgs__srv__SwitchOn_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_spine_msgs__srv__SwitchOn_Request__TYPE_NAME, 38, 38},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
franka_spine_msgs__srv__SwitchOn_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_spine_msgs__srv__SwitchOn_Response__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
franka_spine_msgs__srv__SwitchOn_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {franka_spine_msgs__srv__SwitchOn_Event__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_spine_msgs__srv__SwitchOn__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_spine_msgs__srv__SwitchOn__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *franka_spine_msgs__srv__SwitchOn_Event__get_individual_type_description_source(NULL);
    sources[3] = *franka_spine_msgs__srv__SwitchOn_Request__get_individual_type_description_source(NULL);
    sources[4] = *franka_spine_msgs__srv__SwitchOn_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_spine_msgs__srv__SwitchOn_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_spine_msgs__srv__SwitchOn_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_spine_msgs__srv__SwitchOn_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_spine_msgs__srv__SwitchOn_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
franka_spine_msgs__srv__SwitchOn_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *franka_spine_msgs__srv__SwitchOn_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *franka_spine_msgs__srv__SwitchOn_Request__get_individual_type_description_source(NULL);
    sources[3] = *franka_spine_msgs__srv__SwitchOn_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
