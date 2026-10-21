// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from franka_spine_msgs:msg/UserLimits.idl
// generated code does not contain a copyright notice
#include "franka_spine_msgs/msg/detail/user_limits__rosidl_typesupport_fastrtps_cpp.hpp"
#include "franka_spine_msgs/msg/detail/user_limits__functions.h"
#include "franka_spine_msgs/msg/detail/user_limits__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace franka_spine_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_franka_spine_msgs
cdr_serialize(
  const franka_spine_msgs::msg::UserLimits & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: lower_limit
  cdr << ros_message.lower_limit;

  // Member: upper_limit
  cdr << ros_message.upper_limit;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_franka_spine_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  franka_spine_msgs::msg::UserLimits & ros_message)
{
  // Member: lower_limit
  cdr >> ros_message.lower_limit;

  // Member: upper_limit
  cdr >> ros_message.upper_limit;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_franka_spine_msgs
get_serialized_size(
  const franka_spine_msgs::msg::UserLimits & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: lower_limit
  {
    size_t item_size = sizeof(ros_message.lower_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: upper_limit
  {
    size_t item_size = sizeof(ros_message.upper_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_franka_spine_msgs
max_serialized_size_UserLimits(
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

  // Member: lower_limit
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // Member: upper_limit
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = franka_spine_msgs::msg::UserLimits;
    is_plain =
      (
      offsetof(DataType, upper_limit) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_franka_spine_msgs
cdr_serialize_key(
  const franka_spine_msgs::msg::UserLimits & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: lower_limit
  cdr << ros_message.lower_limit;

  // Member: upper_limit
  cdr << ros_message.upper_limit;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_franka_spine_msgs
get_serialized_size_key(
  const franka_spine_msgs::msg::UserLimits & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: lower_limit
  {
    size_t item_size = sizeof(ros_message.lower_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: upper_limit
  {
    size_t item_size = sizeof(ros_message.upper_limit);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_franka_spine_msgs
max_serialized_size_key_UserLimits(
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

  // Member: lower_limit
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: upper_limit
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = franka_spine_msgs::msg::UserLimits;
    is_plain =
      (
      offsetof(DataType, upper_limit) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}


static bool _UserLimits__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const franka_spine_msgs::msg::UserLimits *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _UserLimits__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<franka_spine_msgs::msg::UserLimits *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _UserLimits__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const franka_spine_msgs::msg::UserLimits *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _UserLimits__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_UserLimits(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _UserLimits__callbacks = {
  "franka_spine_msgs::msg",
  "UserLimits",
  _UserLimits__cdr_serialize,
  _UserLimits__cdr_deserialize,
  _UserLimits__get_serialized_size,
  _UserLimits__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _UserLimits__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_UserLimits__callbacks,
  get_message_typesupport_handle_function,
  &franka_spine_msgs__msg__UserLimits__get_type_hash,
  &franka_spine_msgs__msg__UserLimits__get_type_description,
  &franka_spine_msgs__msg__UserLimits__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace franka_spine_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_franka_spine_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<franka_spine_msgs::msg::UserLimits>()
{
  return &franka_spine_msgs::msg::typesupport_fastrtps_cpp::_UserLimits__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, franka_spine_msgs, msg, UserLimits)() {
  return &franka_spine_msgs::msg::typesupport_fastrtps_cpp::_UserLimits__handle;
}

#ifdef __cplusplus
}
#endif
