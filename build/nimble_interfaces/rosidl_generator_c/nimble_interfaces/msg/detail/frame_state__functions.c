// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nimble_interfaces:msg/FrameState.idl
// generated code does not contain a copyright notice
#include "nimble_interfaces/msg/detail/frame_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
nimble_interfaces__msg__FrameState__init(nimble_interfaces__msg__FrameState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nimble_interfaces__msg__FrameState__fini(msg);
    return false;
  }
  // optic_sensor
  // velocity
  // position
  return true;
}

void
nimble_interfaces__msg__FrameState__fini(nimble_interfaces__msg__FrameState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // optic_sensor
  // velocity
  // position
}

bool
nimble_interfaces__msg__FrameState__are_equal(const nimble_interfaces__msg__FrameState * lhs, const nimble_interfaces__msg__FrameState * rhs)
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
  // optic_sensor
  if (lhs->optic_sensor != rhs->optic_sensor) {
    return false;
  }
  // velocity
  if (lhs->velocity != rhs->velocity) {
    return false;
  }
  // position
  if (lhs->position != rhs->position) {
    return false;
  }
  return true;
}

bool
nimble_interfaces__msg__FrameState__copy(
  const nimble_interfaces__msg__FrameState * input,
  nimble_interfaces__msg__FrameState * output)
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
  // optic_sensor
  output->optic_sensor = input->optic_sensor;
  // velocity
  output->velocity = input->velocity;
  // position
  output->position = input->position;
  return true;
}

nimble_interfaces__msg__FrameState *
nimble_interfaces__msg__FrameState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__FrameState * msg = (nimble_interfaces__msg__FrameState *)allocator.allocate(sizeof(nimble_interfaces__msg__FrameState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nimble_interfaces__msg__FrameState));
  bool success = nimble_interfaces__msg__FrameState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nimble_interfaces__msg__FrameState__destroy(nimble_interfaces__msg__FrameState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nimble_interfaces__msg__FrameState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nimble_interfaces__msg__FrameState__Sequence__init(nimble_interfaces__msg__FrameState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__FrameState * data = NULL;

  if (size) {
    data = (nimble_interfaces__msg__FrameState *)allocator.zero_allocate(size, sizeof(nimble_interfaces__msg__FrameState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nimble_interfaces__msg__FrameState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nimble_interfaces__msg__FrameState__fini(&data[i - 1]);
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
nimble_interfaces__msg__FrameState__Sequence__fini(nimble_interfaces__msg__FrameState__Sequence * array)
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
      nimble_interfaces__msg__FrameState__fini(&array->data[i]);
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

nimble_interfaces__msg__FrameState__Sequence *
nimble_interfaces__msg__FrameState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__FrameState__Sequence * array = (nimble_interfaces__msg__FrameState__Sequence *)allocator.allocate(sizeof(nimble_interfaces__msg__FrameState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nimble_interfaces__msg__FrameState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nimble_interfaces__msg__FrameState__Sequence__destroy(nimble_interfaces__msg__FrameState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nimble_interfaces__msg__FrameState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nimble_interfaces__msg__FrameState__Sequence__are_equal(const nimble_interfaces__msg__FrameState__Sequence * lhs, const nimble_interfaces__msg__FrameState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nimble_interfaces__msg__FrameState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nimble_interfaces__msg__FrameState__Sequence__copy(
  const nimble_interfaces__msg__FrameState__Sequence * input,
  nimble_interfaces__msg__FrameState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nimble_interfaces__msg__FrameState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nimble_interfaces__msg__FrameState * data =
      (nimble_interfaces__msg__FrameState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nimble_interfaces__msg__FrameState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nimble_interfaces__msg__FrameState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nimble_interfaces__msg__FrameState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
