// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from franka_spine_msgs:srv/GetSpineState.idl
// generated code does not contain a copyright notice
#include "franka_spine_msgs/srv/detail/get_spine_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
franka_spine_msgs__srv__GetSpineState_Request__init(franka_spine_msgs__srv__GetSpineState_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
franka_spine_msgs__srv__GetSpineState_Request__fini(franka_spine_msgs__srv__GetSpineState_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
franka_spine_msgs__srv__GetSpineState_Request__are_equal(const franka_spine_msgs__srv__GetSpineState_Request * lhs, const franka_spine_msgs__srv__GetSpineState_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
franka_spine_msgs__srv__GetSpineState_Request__copy(
  const franka_spine_msgs__srv__GetSpineState_Request * input,
  franka_spine_msgs__srv__GetSpineState_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

franka_spine_msgs__srv__GetSpineState_Request *
franka_spine_msgs__srv__GetSpineState_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__srv__GetSpineState_Request * msg = (franka_spine_msgs__srv__GetSpineState_Request *)allocator.allocate(sizeof(franka_spine_msgs__srv__GetSpineState_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(franka_spine_msgs__srv__GetSpineState_Request));
  bool success = franka_spine_msgs__srv__GetSpineState_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
franka_spine_msgs__srv__GetSpineState_Request__destroy(franka_spine_msgs__srv__GetSpineState_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    franka_spine_msgs__srv__GetSpineState_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
franka_spine_msgs__srv__GetSpineState_Request__Sequence__init(franka_spine_msgs__srv__GetSpineState_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__srv__GetSpineState_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(franka_spine_msgs__srv__GetSpineState_Request)) {
      return false;
    }
    data = (franka_spine_msgs__srv__GetSpineState_Request *)allocator.zero_allocate(size, sizeof(franka_spine_msgs__srv__GetSpineState_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = franka_spine_msgs__srv__GetSpineState_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        franka_spine_msgs__srv__GetSpineState_Request__fini(&data[i - 1]);
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
franka_spine_msgs__srv__GetSpineState_Request__Sequence__fini(franka_spine_msgs__srv__GetSpineState_Request__Sequence * array)
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
      franka_spine_msgs__srv__GetSpineState_Request__fini(&array->data[i]);
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

franka_spine_msgs__srv__GetSpineState_Request__Sequence *
franka_spine_msgs__srv__GetSpineState_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__srv__GetSpineState_Request__Sequence * array = (franka_spine_msgs__srv__GetSpineState_Request__Sequence *)allocator.allocate(sizeof(franka_spine_msgs__srv__GetSpineState_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = franka_spine_msgs__srv__GetSpineState_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
franka_spine_msgs__srv__GetSpineState_Request__Sequence__destroy(franka_spine_msgs__srv__GetSpineState_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    franka_spine_msgs__srv__GetSpineState_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
franka_spine_msgs__srv__GetSpineState_Request__Sequence__are_equal(const franka_spine_msgs__srv__GetSpineState_Request__Sequence * lhs, const franka_spine_msgs__srv__GetSpineState_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!franka_spine_msgs__srv__GetSpineState_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
franka_spine_msgs__srv__GetSpineState_Request__Sequence__copy(
  const franka_spine_msgs__srv__GetSpineState_Request__Sequence * input,
  franka_spine_msgs__srv__GetSpineState_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(franka_spine_msgs__srv__GetSpineState_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(franka_spine_msgs__srv__GetSpineState_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    franka_spine_msgs__srv__GetSpineState_Request * data =
      (franka_spine_msgs__srv__GetSpineState_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!franka_spine_msgs__srv__GetSpineState_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          franka_spine_msgs__srv__GetSpineState_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!franka_spine_msgs__srv__GetSpineState_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `state`
// Member `error_code`
// Member `error_description`
#include "rosidl_runtime_c/string_functions.h"

bool
franka_spine_msgs__srv__GetSpineState_Response__init(franka_spine_msgs__srv__GetSpineState_Response * msg)
{
  if (!msg) {
    return false;
  }
  // state
  if (!rosidl_runtime_c__String__init(&msg->state)) {
    franka_spine_msgs__srv__GetSpineState_Response__fini(msg);
    return false;
  }
  // error_code
  if (!rosidl_runtime_c__String__init(&msg->error_code)) {
    franka_spine_msgs__srv__GetSpineState_Response__fini(msg);
    return false;
  }
  // error_description
  if (!rosidl_runtime_c__String__init(&msg->error_description)) {
    franka_spine_msgs__srv__GetSpineState_Response__fini(msg);
    return false;
  }
  // success
  return true;
}

void
franka_spine_msgs__srv__GetSpineState_Response__fini(franka_spine_msgs__srv__GetSpineState_Response * msg)
{
  if (!msg) {
    return;
  }
  // state
  rosidl_runtime_c__String__fini(&msg->state);
  // error_code
  rosidl_runtime_c__String__fini(&msg->error_code);
  // error_description
  rosidl_runtime_c__String__fini(&msg->error_description);
  // success
}

bool
franka_spine_msgs__srv__GetSpineState_Response__are_equal(const franka_spine_msgs__srv__GetSpineState_Response * lhs, const franka_spine_msgs__srv__GetSpineState_Response * rhs)
{
  if (!lhs || !rhs) {
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
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
franka_spine_msgs__srv__GetSpineState_Response__copy(
  const franka_spine_msgs__srv__GetSpineState_Response * input,
  franka_spine_msgs__srv__GetSpineState_Response * output)
{
  if (!input || !output) {
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
  // success
  output->success = input->success;
  return true;
}

franka_spine_msgs__srv__GetSpineState_Response *
franka_spine_msgs__srv__GetSpineState_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__srv__GetSpineState_Response * msg = (franka_spine_msgs__srv__GetSpineState_Response *)allocator.allocate(sizeof(franka_spine_msgs__srv__GetSpineState_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(franka_spine_msgs__srv__GetSpineState_Response));
  bool success = franka_spine_msgs__srv__GetSpineState_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
franka_spine_msgs__srv__GetSpineState_Response__destroy(franka_spine_msgs__srv__GetSpineState_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    franka_spine_msgs__srv__GetSpineState_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
franka_spine_msgs__srv__GetSpineState_Response__Sequence__init(franka_spine_msgs__srv__GetSpineState_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__srv__GetSpineState_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(franka_spine_msgs__srv__GetSpineState_Response)) {
      return false;
    }
    data = (franka_spine_msgs__srv__GetSpineState_Response *)allocator.zero_allocate(size, sizeof(franka_spine_msgs__srv__GetSpineState_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = franka_spine_msgs__srv__GetSpineState_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        franka_spine_msgs__srv__GetSpineState_Response__fini(&data[i - 1]);
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
franka_spine_msgs__srv__GetSpineState_Response__Sequence__fini(franka_spine_msgs__srv__GetSpineState_Response__Sequence * array)
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
      franka_spine_msgs__srv__GetSpineState_Response__fini(&array->data[i]);
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

franka_spine_msgs__srv__GetSpineState_Response__Sequence *
franka_spine_msgs__srv__GetSpineState_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__srv__GetSpineState_Response__Sequence * array = (franka_spine_msgs__srv__GetSpineState_Response__Sequence *)allocator.allocate(sizeof(franka_spine_msgs__srv__GetSpineState_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = franka_spine_msgs__srv__GetSpineState_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
franka_spine_msgs__srv__GetSpineState_Response__Sequence__destroy(franka_spine_msgs__srv__GetSpineState_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    franka_spine_msgs__srv__GetSpineState_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
franka_spine_msgs__srv__GetSpineState_Response__Sequence__are_equal(const franka_spine_msgs__srv__GetSpineState_Response__Sequence * lhs, const franka_spine_msgs__srv__GetSpineState_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!franka_spine_msgs__srv__GetSpineState_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
franka_spine_msgs__srv__GetSpineState_Response__Sequence__copy(
  const franka_spine_msgs__srv__GetSpineState_Response__Sequence * input,
  franka_spine_msgs__srv__GetSpineState_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(franka_spine_msgs__srv__GetSpineState_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(franka_spine_msgs__srv__GetSpineState_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    franka_spine_msgs__srv__GetSpineState_Response * data =
      (franka_spine_msgs__srv__GetSpineState_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!franka_spine_msgs__srv__GetSpineState_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          franka_spine_msgs__srv__GetSpineState_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!franka_spine_msgs__srv__GetSpineState_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "franka_spine_msgs/srv/detail/get_spine_state__functions.h"

bool
franka_spine_msgs__srv__GetSpineState_Event__init(franka_spine_msgs__srv__GetSpineState_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    franka_spine_msgs__srv__GetSpineState_Event__fini(msg);
    return false;
  }
  // request
  if (!franka_spine_msgs__srv__GetSpineState_Request__Sequence__init(&msg->request, 0)) {
    franka_spine_msgs__srv__GetSpineState_Event__fini(msg);
    return false;
  }
  // response
  if (!franka_spine_msgs__srv__GetSpineState_Response__Sequence__init(&msg->response, 0)) {
    franka_spine_msgs__srv__GetSpineState_Event__fini(msg);
    return false;
  }
  return true;
}

void
franka_spine_msgs__srv__GetSpineState_Event__fini(franka_spine_msgs__srv__GetSpineState_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  franka_spine_msgs__srv__GetSpineState_Request__Sequence__fini(&msg->request);
  // response
  franka_spine_msgs__srv__GetSpineState_Response__Sequence__fini(&msg->response);
}

bool
franka_spine_msgs__srv__GetSpineState_Event__are_equal(const franka_spine_msgs__srv__GetSpineState_Event * lhs, const franka_spine_msgs__srv__GetSpineState_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!franka_spine_msgs__srv__GetSpineState_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!franka_spine_msgs__srv__GetSpineState_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
franka_spine_msgs__srv__GetSpineState_Event__copy(
  const franka_spine_msgs__srv__GetSpineState_Event * input,
  franka_spine_msgs__srv__GetSpineState_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!franka_spine_msgs__srv__GetSpineState_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!franka_spine_msgs__srv__GetSpineState_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

franka_spine_msgs__srv__GetSpineState_Event *
franka_spine_msgs__srv__GetSpineState_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__srv__GetSpineState_Event * msg = (franka_spine_msgs__srv__GetSpineState_Event *)allocator.allocate(sizeof(franka_spine_msgs__srv__GetSpineState_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(franka_spine_msgs__srv__GetSpineState_Event));
  bool success = franka_spine_msgs__srv__GetSpineState_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
franka_spine_msgs__srv__GetSpineState_Event__destroy(franka_spine_msgs__srv__GetSpineState_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    franka_spine_msgs__srv__GetSpineState_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
franka_spine_msgs__srv__GetSpineState_Event__Sequence__init(franka_spine_msgs__srv__GetSpineState_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__srv__GetSpineState_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(franka_spine_msgs__srv__GetSpineState_Event)) {
      return false;
    }
    data = (franka_spine_msgs__srv__GetSpineState_Event *)allocator.zero_allocate(size, sizeof(franka_spine_msgs__srv__GetSpineState_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = franka_spine_msgs__srv__GetSpineState_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        franka_spine_msgs__srv__GetSpineState_Event__fini(&data[i - 1]);
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
franka_spine_msgs__srv__GetSpineState_Event__Sequence__fini(franka_spine_msgs__srv__GetSpineState_Event__Sequence * array)
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
      franka_spine_msgs__srv__GetSpineState_Event__fini(&array->data[i]);
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

franka_spine_msgs__srv__GetSpineState_Event__Sequence *
franka_spine_msgs__srv__GetSpineState_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  franka_spine_msgs__srv__GetSpineState_Event__Sequence * array = (franka_spine_msgs__srv__GetSpineState_Event__Sequence *)allocator.allocate(sizeof(franka_spine_msgs__srv__GetSpineState_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = franka_spine_msgs__srv__GetSpineState_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
franka_spine_msgs__srv__GetSpineState_Event__Sequence__destroy(franka_spine_msgs__srv__GetSpineState_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    franka_spine_msgs__srv__GetSpineState_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
franka_spine_msgs__srv__GetSpineState_Event__Sequence__are_equal(const franka_spine_msgs__srv__GetSpineState_Event__Sequence * lhs, const franka_spine_msgs__srv__GetSpineState_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!franka_spine_msgs__srv__GetSpineState_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
franka_spine_msgs__srv__GetSpineState_Event__Sequence__copy(
  const franka_spine_msgs__srv__GetSpineState_Event__Sequence * input,
  franka_spine_msgs__srv__GetSpineState_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(franka_spine_msgs__srv__GetSpineState_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(franka_spine_msgs__srv__GetSpineState_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    franka_spine_msgs__srv__GetSpineState_Event * data =
      (franka_spine_msgs__srv__GetSpineState_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!franka_spine_msgs__srv__GetSpineState_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          franka_spine_msgs__srv__GetSpineState_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!franka_spine_msgs__srv__GetSpineState_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
