// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from franka_spine_msgs:msg/UserLimits.idl
// generated code does not contain a copyright notice
#include "franka_spine_msgs/msg/detail/user_limits__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
franka_spine_msgs__msg__UserLimits__init(franka_spine_msgs__msg__UserLimits * msg)
{
  if (!msg) {
    return false;
  }
  // lower_limit
  // upper_limit
  return true;
}

void
franka_spine_msgs__msg__UserLimits__fini(franka_spine_msgs__msg__UserLimits * msg)
{
  if (!msg) {
    return;
  }
  // lower_limit
  // upper_limit
}

bool
franka_spine_msgs__msg__UserLimits__are_equal(const franka_spine_msgs__msg__UserLimits * lhs, const franka_spine_msgs__msg__UserLimits * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // lower_limit
  if (lhs->lower_limit != rhs->lower_limit) {
    return false;
  }
  // upper_limit
  if (lhs->upper_limit != rhs->upper_limit) {
    return false;
  }
  return true;
}

bool
franka_spine_msgs__msg__UserLimits__copy(
  const franka_spine_msgs__msg__UserLimits * input,
  franka_spine_msgs__msg__UserLimits * output)
{
  if (!input || !output) {
    return false;
  }
  // lower_limit
  output->lower_limit = input->lower_limit;
  // upper_limit
  output->upper_limit = input->upper_limit;
  return true;
}

franka_spine_msgs__msg__UserLimits *
franka_spine_msgs__msg__UserLimits__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__UserLimits * msg = (franka_spine_msgs__msg__UserLimits *)allocator.allocate(sizeof(franka_spine_msgs__msg__UserLimits), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(franka_spine_msgs__msg__UserLimits));
  bool success = franka_spine_msgs__msg__UserLimits__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
franka_spine_msgs__msg__UserLimits__destroy(franka_spine_msgs__msg__UserLimits * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    franka_spine_msgs__msg__UserLimits__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
franka_spine_msgs__msg__UserLimits__Sequence__init(franka_spine_msgs__msg__UserLimits__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__UserLimits * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(franka_spine_msgs__msg__UserLimits)) {
      return false;
    }
    data = (franka_spine_msgs__msg__UserLimits *)allocator.zero_allocate(size, sizeof(franka_spine_msgs__msg__UserLimits), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = franka_spine_msgs__msg__UserLimits__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        franka_spine_msgs__msg__UserLimits__fini(&data[i - 1]);
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
franka_spine_msgs__msg__UserLimits__Sequence__fini(franka_spine_msgs__msg__UserLimits__Sequence * array)
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
      franka_spine_msgs__msg__UserLimits__fini(&array->data[i]);
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

franka_spine_msgs__msg__UserLimits__Sequence *
franka_spine_msgs__msg__UserLimits__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__msg__UserLimits__Sequence * array = (franka_spine_msgs__msg__UserLimits__Sequence *)allocator.allocate(sizeof(franka_spine_msgs__msg__UserLimits__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = franka_spine_msgs__msg__UserLimits__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
franka_spine_msgs__msg__UserLimits__Sequence__destroy(franka_spine_msgs__msg__UserLimits__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    franka_spine_msgs__msg__UserLimits__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
franka_spine_msgs__msg__UserLimits__Sequence__are_equal(const franka_spine_msgs__msg__UserLimits__Sequence * lhs, const franka_spine_msgs__msg__UserLimits__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!franka_spine_msgs__msg__UserLimits__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
franka_spine_msgs__msg__UserLimits__Sequence__copy(
  const franka_spine_msgs__msg__UserLimits__Sequence * input,
  franka_spine_msgs__msg__UserLimits__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(franka_spine_msgs__msg__UserLimits)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(franka_spine_msgs__msg__UserLimits);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    franka_spine_msgs__msg__UserLimits * data =
      (franka_spine_msgs__msg__UserLimits *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!franka_spine_msgs__msg__UserLimits__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          franka_spine_msgs__msg__UserLimits__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!franka_spine_msgs__msg__UserLimits__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
