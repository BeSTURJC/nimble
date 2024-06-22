// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nimble_interfaces:msg/TherapyRequirements.idl
// generated code does not contain a copyright notice
#include "nimble_interfaces/msg/detail/therapy_requirements__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
nimble_interfaces__msg__TherapyRequirements__init(nimble_interfaces__msg__TherapyRequirements * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nimble_interfaces__msg__TherapyRequirements__fini(msg);
    return false;
  }
  // speed
  // step_length
  // step_height
  // min_assist_level
  // max_assist_level
  return true;
}

void
nimble_interfaces__msg__TherapyRequirements__fini(nimble_interfaces__msg__TherapyRequirements * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // speed
  // step_length
  // step_height
  // min_assist_level
  // max_assist_level
}

bool
nimble_interfaces__msg__TherapyRequirements__are_equal(const nimble_interfaces__msg__TherapyRequirements * lhs, const nimble_interfaces__msg__TherapyRequirements * rhs)
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
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // step_length
  if (lhs->step_length != rhs->step_length) {
    return false;
  }
  // step_height
  if (lhs->step_height != rhs->step_height) {
    return false;
  }
  // min_assist_level
  if (lhs->min_assist_level != rhs->min_assist_level) {
    return false;
  }
  // max_assist_level
  if (lhs->max_assist_level != rhs->max_assist_level) {
    return false;
  }
  return true;
}

bool
nimble_interfaces__msg__TherapyRequirements__copy(
  const nimble_interfaces__msg__TherapyRequirements * input,
  nimble_interfaces__msg__TherapyRequirements * output)
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
  // speed
  output->speed = input->speed;
  // step_length
  output->step_length = input->step_length;
  // step_height
  output->step_height = input->step_height;
  // min_assist_level
  output->min_assist_level = input->min_assist_level;
  // max_assist_level
  output->max_assist_level = input->max_assist_level;
  return true;
}

nimble_interfaces__msg__TherapyRequirements *
nimble_interfaces__msg__TherapyRequirements__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__TherapyRequirements * msg = (nimble_interfaces__msg__TherapyRequirements *)allocator.allocate(sizeof(nimble_interfaces__msg__TherapyRequirements), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nimble_interfaces__msg__TherapyRequirements));
  bool success = nimble_interfaces__msg__TherapyRequirements__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nimble_interfaces__msg__TherapyRequirements__destroy(nimble_interfaces__msg__TherapyRequirements * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nimble_interfaces__msg__TherapyRequirements__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nimble_interfaces__msg__TherapyRequirements__Sequence__init(nimble_interfaces__msg__TherapyRequirements__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__TherapyRequirements * data = NULL;

  if (size) {
    data = (nimble_interfaces__msg__TherapyRequirements *)allocator.zero_allocate(size, sizeof(nimble_interfaces__msg__TherapyRequirements), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nimble_interfaces__msg__TherapyRequirements__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nimble_interfaces__msg__TherapyRequirements__fini(&data[i - 1]);
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
nimble_interfaces__msg__TherapyRequirements__Sequence__fini(nimble_interfaces__msg__TherapyRequirements__Sequence * array)
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
      nimble_interfaces__msg__TherapyRequirements__fini(&array->data[i]);
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

nimble_interfaces__msg__TherapyRequirements__Sequence *
nimble_interfaces__msg__TherapyRequirements__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__TherapyRequirements__Sequence * array = (nimble_interfaces__msg__TherapyRequirements__Sequence *)allocator.allocate(sizeof(nimble_interfaces__msg__TherapyRequirements__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nimble_interfaces__msg__TherapyRequirements__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nimble_interfaces__msg__TherapyRequirements__Sequence__destroy(nimble_interfaces__msg__TherapyRequirements__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nimble_interfaces__msg__TherapyRequirements__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nimble_interfaces__msg__TherapyRequirements__Sequence__are_equal(const nimble_interfaces__msg__TherapyRequirements__Sequence * lhs, const nimble_interfaces__msg__TherapyRequirements__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nimble_interfaces__msg__TherapyRequirements__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nimble_interfaces__msg__TherapyRequirements__Sequence__copy(
  const nimble_interfaces__msg__TherapyRequirements__Sequence * input,
  nimble_interfaces__msg__TherapyRequirements__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nimble_interfaces__msg__TherapyRequirements);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nimble_interfaces__msg__TherapyRequirements * data =
      (nimble_interfaces__msg__TherapyRequirements *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nimble_interfaces__msg__TherapyRequirements__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nimble_interfaces__msg__TherapyRequirements__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nimble_interfaces__msg__TherapyRequirements__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
