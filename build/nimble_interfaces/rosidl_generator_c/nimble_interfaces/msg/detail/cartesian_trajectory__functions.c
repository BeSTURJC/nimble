// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nimble_interfaces:msg/CartesianTrajectory.idl
// generated code does not contain a copyright notice
#include "nimble_interfaces/msg/detail/cartesian_trajectory__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `malleolus`
// Member `pelvis`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
nimble_interfaces__msg__CartesianTrajectory__init(nimble_interfaces__msg__CartesianTrajectory * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // malleolus
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->malleolus, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // pelvis
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->pelvis, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  return true;
}

void
nimble_interfaces__msg__CartesianTrajectory__fini(nimble_interfaces__msg__CartesianTrajectory * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // malleolus
  geometry_msgs__msg__Point__Sequence__fini(&msg->malleolus);
  // pelvis
  geometry_msgs__msg__Point__Sequence__fini(&msg->pelvis);
}

bool
nimble_interfaces__msg__CartesianTrajectory__are_equal(const nimble_interfaces__msg__CartesianTrajectory * lhs, const nimble_interfaces__msg__CartesianTrajectory * rhs)
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
  // malleolus
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->malleolus), &(rhs->malleolus)))
  {
    return false;
  }
  // pelvis
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->pelvis), &(rhs->pelvis)))
  {
    return false;
  }
  return true;
}

bool
nimble_interfaces__msg__CartesianTrajectory__copy(
  const nimble_interfaces__msg__CartesianTrajectory * input,
  nimble_interfaces__msg__CartesianTrajectory * output)
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
  // malleolus
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->malleolus), &(output->malleolus)))
  {
    return false;
  }
  // pelvis
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->pelvis), &(output->pelvis)))
  {
    return false;
  }
  return true;
}

nimble_interfaces__msg__CartesianTrajectory *
nimble_interfaces__msg__CartesianTrajectory__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__CartesianTrajectory * msg = (nimble_interfaces__msg__CartesianTrajectory *)allocator.allocate(sizeof(nimble_interfaces__msg__CartesianTrajectory), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nimble_interfaces__msg__CartesianTrajectory));
  bool success = nimble_interfaces__msg__CartesianTrajectory__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nimble_interfaces__msg__CartesianTrajectory__destroy(nimble_interfaces__msg__CartesianTrajectory * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nimble_interfaces__msg__CartesianTrajectory__Sequence__init(nimble_interfaces__msg__CartesianTrajectory__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__CartesianTrajectory * data = NULL;

  if (size) {
    data = (nimble_interfaces__msg__CartesianTrajectory *)allocator.zero_allocate(size, sizeof(nimble_interfaces__msg__CartesianTrajectory), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nimble_interfaces__msg__CartesianTrajectory__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nimble_interfaces__msg__CartesianTrajectory__fini(&data[i - 1]);
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
nimble_interfaces__msg__CartesianTrajectory__Sequence__fini(nimble_interfaces__msg__CartesianTrajectory__Sequence * array)
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
      nimble_interfaces__msg__CartesianTrajectory__fini(&array->data[i]);
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

nimble_interfaces__msg__CartesianTrajectory__Sequence *
nimble_interfaces__msg__CartesianTrajectory__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__CartesianTrajectory__Sequence * array = (nimble_interfaces__msg__CartesianTrajectory__Sequence *)allocator.allocate(sizeof(nimble_interfaces__msg__CartesianTrajectory__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nimble_interfaces__msg__CartesianTrajectory__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nimble_interfaces__msg__CartesianTrajectory__Sequence__destroy(nimble_interfaces__msg__CartesianTrajectory__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nimble_interfaces__msg__CartesianTrajectory__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nimble_interfaces__msg__CartesianTrajectory__Sequence__are_equal(const nimble_interfaces__msg__CartesianTrajectory__Sequence * lhs, const nimble_interfaces__msg__CartesianTrajectory__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nimble_interfaces__msg__CartesianTrajectory__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nimble_interfaces__msg__CartesianTrajectory__Sequence__copy(
  const nimble_interfaces__msg__CartesianTrajectory__Sequence * input,
  nimble_interfaces__msg__CartesianTrajectory__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nimble_interfaces__msg__CartesianTrajectory);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nimble_interfaces__msg__CartesianTrajectory * data =
      (nimble_interfaces__msg__CartesianTrajectory *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nimble_interfaces__msg__CartesianTrajectory__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nimble_interfaces__msg__CartesianTrajectory__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nimble_interfaces__msg__CartesianTrajectory__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
