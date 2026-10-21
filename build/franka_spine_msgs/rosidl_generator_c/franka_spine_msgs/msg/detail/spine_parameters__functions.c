// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from franka_spine_msgs:msg/SpineParameters.idl
// generated code does not contain a copyright notice
#include "franka_spine_msgs/msg/detail/spine_parameters__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `user_limits`
#include "franka_spine_msgs/msg/detail/user_limits__functions.h"

bool
franka_spine_msgs__msg__SpineParameters__init(franka_spine_msgs__msg__SpineParameters * msg)
{
  if (!msg) {
    return false;
  }
  // user_limits
  if (!franka_spine_msgs__msg__UserLimits__init(&msg->user_limits)) {
    franka_spine_msgs__msg__SpineParameters__fini(msg);
    return false;
  }
  return true;
}

void
franka_spine_msgs__msg__SpineParameters__fini(franka_spine_msgs__msg__SpineParameters * msg)
{
  if (!msg) {
    return;
  }
  // user_limits
  franka_spine_msgs__msg__UserLimits__fini(&msg->user_limits);
}

bool
franka_spine_msgs__msg__SpineParameters__are_equal(const franka_spine_msgs__msg__SpineParameters * lhs, const franka_spine_msgs__msg__SpineParameters * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // user_limits
  if (!franka_spine_msgs__msg__UserLimits__are_equal(
      &(lhs->user_limits), &(rhs->user_limits)))
  {
    return false;
  }
  return true;
}

bool
franka_spine_msgs__msg__SpineParameters__copy(
  const franka_spine_msgs__msg__SpineParameters * input,
  franka_spine_msgs__msg__SpineParameters * output)
{
  if (!input || !output) {
    return false;
  }
  // user_limits
  if (!franka_spine_msgs__msg__UserLimits__copy(
      &(input->user_limits), &(output->user_limits)))
  {
    return false;
  }
  return true;
}

franka_spine_msgs__msg__SpineParameters *
franka_spine_msgs__msg__SpineParameters__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__SpineParameters * msg = (franka_spine_msgs__msg__SpineParameters *)allocator.allocate(sizeof(franka_spine_msgs__msg__SpineParameters), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(franka_spine_msgs__msg__SpineParameters));
  bool success = franka_spine_msgs__msg__SpineParameters__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
franka_spine_msgs__msg__SpineParameters__destroy(franka_spine_msgs__msg__SpineParameters * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    franka_spine_msgs__msg__SpineParameters__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
franka_spine_msgs__msg__SpineParameters__Sequence__init(franka_spine_msgs__msg__SpineParameters__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__SpineParameters * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(franka_spine_msgs__msg__SpineParameters)) {
      return false;
    }
    data = (franka_spine_msgs__msg__SpineParameters *)allocator.zero_allocate(size, sizeof(franka_spine_msgs__msg__SpineParameters), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = franka_spine_msgs__msg__SpineParameters__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        franka_spine_msgs__msg__SpineParameters__fini(&data[i - 1]);
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
franka_spine_msgs__msg__SpineParameters__Sequence__fini(franka_spine_msgs__msg__SpineParameters__Sequence * array)
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
      franka_spine_msgs__msg__SpineParameters__fini(&array->data[i]);
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

franka_spine_msgs__msg__SpineParameters__Sequence *
franka_spine_msgs__msg__SpineParameters__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__SpineParameters__Sequence * array = (franka_spine_msgs__msg__SpineParameters__Sequence *)allocator.allocate(sizeof(franka_spine_msgs__msg__SpineParameters__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = franka_spine_msgs__msg__SpineParameters__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
franka_spine_msgs__msg__SpineParameters__Sequence__destroy(franka_spine_msgs__msg__SpineParameters__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    franka_spine_msgs__msg__SpineParameters__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
franka_spine_msgs__msg__SpineParameters__Sequence__are_equal(const franka_spine_msgs__msg__SpineParameters__Sequence * lhs, const franka_spine_msgs__msg__SpineParameters__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!franka_spine_msgs__msg__SpineParameters__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
franka_spine_msgs__msg__SpineParameters__Sequence__copy(
  const franka_spine_msgs__msg__SpineParameters__Sequence * input,
  franka_spine_msgs__msg__SpineParameters__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(franka_spine_msgs__msg__SpineParameters)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(franka_spine_msgs__msg__SpineParameters);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    franka_spine_msgs__msg__SpineParameters * data =
      (franka_spine_msgs__msg__SpineParameters *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!franka_spine_msgs__msg__SpineParameters__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          franka_spine_msgs__msg__SpineParameters__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!franka_spine_msgs__msg__SpineParameters__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
