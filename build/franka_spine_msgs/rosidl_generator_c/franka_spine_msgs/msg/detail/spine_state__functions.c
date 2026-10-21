// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from franka_spine_msgs:msg/SpineState.idl
// generated code does not contain a copyright notice
#include "franka_spine_msgs/msg/detail/spine_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `state`
// Member `error_code`
// Member `error_description`
#include "rosidl_runtime_c/string_functions.h"

bool
franka_spine_msgs__msg__SpineState__init(franka_spine_msgs__msg__SpineState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    franka_spine_msgs__msg__SpineState__fini(msg);
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__init(&msg->state)) {
    franka_spine_msgs__msg__SpineState__fini(msg);
    return false;
  }
  // error_code
  if (!rosidl_runtime_c__String__init(&msg->error_code)) {
    franka_spine_msgs__msg__SpineState__fini(msg);
    return false;
  }
  // error_description
  if (!rosidl_runtime_c__String__init(&msg->error_description)) {
    franka_spine_msgs__msg__SpineState__fini(msg);
    return false;
  }
  // valid
  return true;
}

void
franka_spine_msgs__msg__SpineState__fini(franka_spine_msgs__msg__SpineState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // state
  rosidl_runtime_c__String__fini(&msg->state);
  // error_code
  rosidl_runtime_c__String__fini(&msg->error_code);
  // error_description
  rosidl_runtime_c__String__fini(&msg->error_description);
  // valid
}

bool
franka_spine_msgs__msg__SpineState__are_equal(const franka_spine_msgs__msg__SpineState * lhs, const franka_spine_msgs__msg__SpineState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->state), &(rhs->state)))
  {
    return false;
  }
  // error_code
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_code), &(rhs->error_code)))
  {
    return false;
  }
  // error_description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_description), &(rhs->error_description)))
  {
    return false;
  }
  // valid
  if (lhs->valid != rhs->valid) {
    return false;
  }
  return true;
}

bool
franka_spine_msgs__msg__SpineState__copy(
  const franka_spine_msgs__msg__SpineState * input,
  franka_spine_msgs__msg__SpineState * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__copy(
      &(input->state), &(output->state)))
  {
    return false;
  }
  // error_code
  if (!rosidl_runtime_c__String__copy(
      &(input->error_code), &(output->error_code)))
  {
    return false;
  }
  // error_description
  if (!rosidl_runtime_c__String__copy(
      &(input->error_description), &(output->error_description)))
  {
    return false;
  }
  // valid
  output->valid = input->valid;
  return true;
}

franka_spine_msgs__msg__SpineState *
franka_spine_msgs__msg__SpineState__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__SpineState * msg = (franka_spine_msgs__msg__SpineState *)allocator.allocate(sizeof(franka_spine_msgs__msg__SpineState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(franka_spine_msgs__msg__SpineState));
  bool success = franka_spine_msgs__msg__SpineState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
franka_spine_msgs__msg__SpineState__destroy(franka_spine_msgs__msg__SpineState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    franka_spine_msgs__msg__SpineState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
franka_spine_msgs__msg__SpineState__Sequence__init(franka_spine_msgs__msg__SpineState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__SpineState * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(franka_spine_msgs__msg__SpineState)) {
      return false;
    }
    data = (franka_spine_msgs__msg__SpineState *)allocator.zero_allocate(size, sizeof(franka_spine_msgs__msg__SpineState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = franka_spine_msgs__msg__SpineState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        franka_spine_msgs__msg__SpineState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
franka_spine_msgs__msg__SpineState__Sequence__fini(franka_spine_msgs__msg__SpineState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      franka_spine_msgs__msg__SpineState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

franka_spine_msgs__msg__SpineState__Sequence *
franka_spine_msgs__msg__SpineState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__SpineState__Sequence * array = (franka_spine_msgs__msg__SpineState__Sequence *)allocator.allocate(sizeof(franka_spine_msgs__msg__SpineState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = franka_spine_msgs__msg__SpineState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
franka_spine_msgs__msg__SpineState__Sequence__destroy(franka_spine_msgs__msg__SpineState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    franka_spine_msgs__msg__SpineState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
franka_spine_msgs__msg__SpineState__Sequence__are_equal(const franka_spine_msgs__msg__SpineState__Sequence * lhs, const franka_spine_msgs__msg__SpineState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!franka_spine_msgs__msg__SpineState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
franka_spine_msgs__msg__SpineState__Sequence__copy(
  const franka_spine_msgs__msg__SpineState__Sequence * input,
  franka_spine_msgs__msg__SpineState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(franka_spine_msgs__msg__SpineState)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(franka_spine_msgs__msg__SpineState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    franka_spine_msgs__msg__SpineState * data =
      (franka_spine_msgs__msg__SpineState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!franka_spine_msgs__msg__SpineState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          franka_spine_msgs__msg__SpineState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!franka_spine_msgs__msg__SpineState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
