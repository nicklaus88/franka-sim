// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from franka_msgs:msg/CollisionIndicators.idl
// generated code does not contain a copyright notice
#include "franka_msgs/msg/detail/collision_indicators__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "franka_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "franka_msgs/msg/detail/collision_indicators__struct.h"
#include "franka_msgs/msg/detail/collision_indicators__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/vector3__functions.h"  // is_cartesian_angular_collision, is_cartesian_angular_contact, is_cartesian_linear_collision, is_cartesian_linear_contact

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_geometry_msgs__msg__Vector3(
  const geometry_msgs__msg__Vector3 * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_deserialize_geometry_msgs__msg__Vector3(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__Vector3 * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_geometry_msgs__msg__Vector3(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_geometry_msgs__msg__Vector3(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
bool cdr_serialize_key_geometry_msgs__msg__Vector3(
  const geometry_msgs__msg__Vector3 * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t get_serialized_size_key_geometry_msgs__msg__Vector3(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
size_t max_serialized_size_key_geometry_msgs__msg__Vector3(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_franka_msgs
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Vector3)();


using _CollisionIndicators__ros_msg_type = franka_msgs__msg__CollisionIndicators;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
bool cdr_serialize_franka_msgs__msg__CollisionIndicators(
  const franka_msgs__msg__CollisionIndicators * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: is_cartesian_linear_collision
  {
    cdr_serialize_geometry_msgs__msg__Vector3(
      &ros_message->is_cartesian_linear_collision, cdr);
  }

  // Field name: is_cartesian_angular_collision
  {
    cdr_serialize_geometry_msgs__msg__Vector3(
      &ros_message->is_cartesian_angular_collision, cdr);
  }

  // Field name: is_cartesian_linear_contact
  {
    cdr_serialize_geometry_msgs__msg__Vector3(
      &ros_message->is_cartesian_linear_contact, cdr);
  }

  // Field name: is_cartesian_angular_contact
  {
    cdr_serialize_geometry_msgs__msg__Vector3(
      &ros_message->is_cartesian_angular_contact, cdr);
  }

  // Field name: is_joint_collision
  {
    size_t size = 7;
    auto array_ptr = ros_message->is_joint_collision;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: is_joint_contact
  {
    size_t size = 7;
    auto array_ptr = ros_message->is_joint_contact;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
bool cdr_deserialize_franka_msgs__msg__CollisionIndicators(
  eprosima::fastcdr::Cdr & cdr,
  franka_msgs__msg__CollisionIndicators * ros_message)
{
  // Field name: is_cartesian_linear_collision
  {
    cdr_deserialize_geometry_msgs__msg__Vector3(cdr, &ros_message->is_cartesian_linear_collision);
  }

  // Field name: is_cartesian_angular_collision
  {
    cdr_deserialize_geometry_msgs__msg__Vector3(cdr, &ros_message->is_cartesian_angular_collision);
  }

  // Field name: is_cartesian_linear_contact
  {
    cdr_deserialize_geometry_msgs__msg__Vector3(cdr, &ros_message->is_cartesian_linear_contact);
  }

  // Field name: is_cartesian_angular_contact
  {
    cdr_deserialize_geometry_msgs__msg__Vector3(cdr, &ros_message->is_cartesian_angular_contact);
  }

  // Field name: is_joint_collision
  {
    size_t size = 7;
    auto array_ptr = ros_message->is_joint_collision;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: is_joint_contact
  {
    size_t size = 7;
    auto array_ptr = ros_message->is_joint_contact;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t get_serialized_size_franka_msgs__msg__CollisionIndicators(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CollisionIndicators__ros_msg_type * ros_message = static_cast<const _CollisionIndicators__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: is_cartesian_linear_collision
  current_alignment += get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->is_cartesian_linear_collision), current_alignment);

  // Field name: is_cartesian_angular_collision
  current_alignment += get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->is_cartesian_angular_collision), current_alignment);

  // Field name: is_cartesian_linear_contact
  current_alignment += get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->is_cartesian_linear_contact), current_alignment);

  // Field name: is_cartesian_angular_contact
  current_alignment += get_serialized_size_geometry_msgs__msg__Vector3(
    &(ros_message->is_cartesian_angular_contact), current_alignment);

  // Field name: is_joint_collision
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->is_joint_collision;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: is_joint_contact
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->is_joint_contact;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t max_serialized_size_franka_msgs__msg__CollisionIndicators(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: is_cartesian_linear_collision
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: is_cartesian_angular_collision
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: is_cartesian_linear_contact
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: is_cartesian_angular_contact
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: is_joint_collision
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: is_joint_contact
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = franka_msgs__msg__CollisionIndicators;
    is_plain =
      (
      offsetof(DataType, is_joint_contact) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
bool cdr_serialize_key_franka_msgs__msg__CollisionIndicators(
  const franka_msgs__msg__CollisionIndicators * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: is_cartesian_linear_collision
  {
    cdr_serialize_key_geometry_msgs__msg__Vector3(
      &ros_message->is_cartesian_linear_collision, cdr);
  }

  // Field name: is_cartesian_angular_collision
  {
    cdr_serialize_key_geometry_msgs__msg__Vector3(
      &ros_message->is_cartesian_angular_collision, cdr);
  }

  // Field name: is_cartesian_linear_contact
  {
    cdr_serialize_key_geometry_msgs__msg__Vector3(
      &ros_message->is_cartesian_linear_contact, cdr);
  }

  // Field name: is_cartesian_angular_contact
  {
    cdr_serialize_key_geometry_msgs__msg__Vector3(
      &ros_message->is_cartesian_angular_contact, cdr);
  }

  // Field name: is_joint_collision
  {
    size_t size = 7;
    auto array_ptr = ros_message->is_joint_collision;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: is_joint_contact
  {
    size_t size = 7;
    auto array_ptr = ros_message->is_joint_contact;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t get_serialized_size_key_franka_msgs__msg__CollisionIndicators(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CollisionIndicators__ros_msg_type * ros_message = static_cast<const _CollisionIndicators__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: is_cartesian_linear_collision
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Vector3(
    &(ros_message->is_cartesian_linear_collision), current_alignment);

  // Field name: is_cartesian_angular_collision
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Vector3(
    &(ros_message->is_cartesian_angular_collision), current_alignment);

  // Field name: is_cartesian_linear_contact
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Vector3(
    &(ros_message->is_cartesian_linear_contact), current_alignment);

  // Field name: is_cartesian_angular_contact
  current_alignment += get_serialized_size_key_geometry_msgs__msg__Vector3(
    &(ros_message->is_cartesian_angular_contact), current_alignment);

  // Field name: is_joint_collision
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->is_joint_collision;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: is_joint_contact
  {
    size_t array_size = 7;
    auto array_ptr = ros_message->is_joint_contact;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_franka_msgs
size_t max_serialized_size_key_franka_msgs__msg__CollisionIndicators(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: is_cartesian_linear_collision
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: is_cartesian_angular_collision
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: is_cartesian_linear_contact
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: is_cartesian_angular_contact
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__Vector3(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: is_joint_collision
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: is_joint_contact
  {
    size_t array_size = 7;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = franka_msgs__msg__CollisionIndicators;
    is_plain =
      (
      offsetof(DataType, is_joint_contact) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _CollisionIndicators__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const franka_msgs__msg__CollisionIndicators * ros_message = static_cast<const franka_msgs__msg__CollisionIndicators *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_franka_msgs__msg__CollisionIndicators(ros_message, cdr);
}

static bool _CollisionIndicators__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  franka_msgs__msg__CollisionIndicators * ros_message = static_cast<franka_msgs__msg__CollisionIndicators *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_franka_msgs__msg__CollisionIndicators(cdr, ros_message);
}

static uint32_t _CollisionIndicators__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_franka_msgs__msg__CollisionIndicators(
      untyped_ros_message, 0));
}

static size_t _CollisionIndicators__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_franka_msgs__msg__CollisionIndicators(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CollisionIndicators = {
  "franka_msgs::msg",
  "CollisionIndicators",
  _CollisionIndicators__cdr_serialize,
  _CollisionIndicators__cdr_deserialize,
  _CollisionIndicators__get_serialized_size,
  _CollisionIndicators__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _CollisionIndicators__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CollisionIndicators,
  get_message_typesupport_handle_function,
  &franka_msgs__msg__CollisionIndicators__get_type_hash,
  &franka_msgs__msg__CollisionIndicators__get_type_description,
  &franka_msgs__msg__CollisionIndicators__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, franka_msgs, msg, CollisionIndicators)() {
  return &_CollisionIndicators__type_support;
}

#if defined(__cplusplus)
}
#endif
