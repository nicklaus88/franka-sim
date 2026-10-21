// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from franka_spine_msgs:msg/SpinePosition.idl
// generated code does not contain a copyright notice
#include "franka_spine_msgs/msg/detail/spine_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
franka_spine_msgs__msg__SpinePosition__init(franka_spine_msgs__msg__SpinePosition * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    franka_spine_msgs__msg__SpinePosition__fini(msg);
    return false;
  }
  // position
  // valid
  return true;
}

void
franka_spine_msgs__msg__SpinePosition__fini(franka_spine_msgs__msg__SpinePosition * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // position
  // valid
}

bool
franka_spine_msgs__msg__SpinePosition__are_equal(const franka_spine_msgs__msg__SpinePosition * lhs, const franka_spine_msgs__msg__SpinePosition * rhs)
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
  // position
  if (lhs->position != rhs->position) {
    return false;
  }
  // valid
  if (lhs->valid != rhs->valid) {
    return false;
  }
  return true;
}

bool
franka_spine_msgs__msg__SpinePosition__copy(
  const franka_spine_msgs__msg__SpinePosition * input,
  franka_spine_msgs__msg__SpinePosition * output)
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
  // position
  output->position = input->position;
  // valid
  output->valid = input->valid;
  return true;
}

franka_spine_msgs__msg__SpinePosition *
franka_spine_msgs__msg__SpinePosition__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__SpinePosition * msg = (franka_spine_msgs__msg__SpinePosition *)allocator.allocate(sizeof(franka_spine_msgs__msg__SpinePosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(franka_spine_msgs__msg__SpinePosition));
  bool success = franka_spine_msgs__msg__SpinePosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
franka_spine_msgs__msg__SpinePosition__destroy(franka_spine_msgs__msg__SpinePosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    franka_spine_msgs__msg__SpinePosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
franka_spine_msgs__msg__SpinePosition__Sequence__init(franka_spine_msgs__msg__SpinePosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__SpinePosition * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(franka_spine_msgs__msg__SpinePosition)) {
      return false;
    }
    data = (franka_spine_msgs__msg__SpinePosition *)allocator.zero_allocate(size, sizeof(franka_spine_msgs__msg__SpinePosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = franka_spine_msgs__msg__SpinePosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        franka_spine_msgs__msg__SpinePosition__fini(&data[i - 1]);
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
franka_spine_msgs__msg__SpinePosition__Sequence__fini(franka_spine_msgs__msg__SpinePosition__Sequence * array)
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
      franka_spine_msgs__msg__SpinePosition__fini(&array->data[i]);
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

franka_spine_msgs__msg__SpinePosition__Sequence *
franka_spine_msgs__msg__SpinePosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__SpinePosition__Sequence * array = (franka_spine_msgs__msg__SpinePosition__Sequence *)allocator.allocate(sizeof(franka_spine_msgs__msg__SpinePosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = franka_spine_msgs__msg__SpinePosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
franka_spine_msgs__msg__SpinePosition__Sequence__destroy(franka_spine_msgs__msg__SpinePosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    franka_spine_msgs__msg__SpinePosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
franka_spine_msgs__msg__SpinePosition__Sequence__are_equal(const franka_spine_msgs__msg__SpinePosition__Sequence * lhs, const franka_spine_msgs__msg__SpinePosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!franka_spine_msgs__msg__SpinePosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
franka_spine_msgs__msg__SpinePosition__Sequence__copy(
  const franka_spine_msgs__msg__SpinePosition__Sequence * input,
  franka_spine_msgs__msg__SpinePosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(franka_spine_msgs__msg__SpinePosition)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(franka_spine_msgs__msg__SpinePosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    franka_spine_msgs__msg__SpinePosition * data =
      (franka_spine_msgs__msg__SpinePosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!franka_spine_msgs__msg__SpinePosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          franka_spine_msgs__msg__SpinePosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!franka_spine_msgs__msg__SpinePosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
