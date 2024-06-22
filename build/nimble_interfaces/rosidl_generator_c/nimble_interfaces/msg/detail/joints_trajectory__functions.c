// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nimble_interfaces:msg/JointsTrajectory.idl
// generated code does not contain a copyright notice
#include "nimble_interfaces/msg/detail/joints_trajectory__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `phase`
#include "std_msgs/msg/detail/float32_multi_array__functions.h"
// Member `trajectory`
#include "trajectory_msgs/msg/detail/joint_trajectory__functions.h"

bool
nimble_interfaces__msg__JointsTrajectory__init(nimble_interfaces__msg__JointsTrajectory * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nimble_interfaces__msg__JointsTrajectory__fini(msg);
    return false;
  }
  // phase
  if (!std_msgs__msg__Float32MultiArray__init(&msg->phase)) {
    nimble_interfaces__msg__JointsTrajectory__fini(msg);
    return false;
  }
  // trajectory
  if (!trajectory_msgs__msg__JointTrajectory__init(&msg->trajectory)) {
    nimble_interfaces__msg__JointsTrajectory__fini(msg);
    return false;
  }
  return true;
}

void
nimble_interfaces__msg__JointsTrajectory__fini(nimble_interfaces__msg__JointsTrajectory * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // phase
  std_msgs__msg__Float32MultiArray__fini(&msg->phase);
  // trajectory
  trajectory_msgs__msg__JointTrajectory__fini(&msg->trajectory);
}

bool
nimble_interfaces__msg__JointsTrajectory__are_equal(const nimble_interfaces__msg__JointsTrajectory * lhs, const nimble_interfaces__msg__JointsTrajectory * rhs)
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
  // phase
  if (!std_msgs__msg__Float32MultiArray__are_equal(
      &(lhs->phase), &(rhs->phase)))
  {
    return false;
  }
  // trajectory
  if (!trajectory_msgs__msg__JointTrajectory__are_equal(
      &(lhs->trajectory), &(rhs->trajectory)))
  {
    return false;
  }
  return true;
}

bool
nimble_interfaces__msg__JointsTrajectory__copy(
  const nimble_interfaces__msg__JointsTrajectory * input,
  nimble_interfaces__msg__JointsTrajectory * output)
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
  // phase
  if (!std_msgs__msg__Float32MultiArray__copy(
      &(input->phase), &(output->phase)))
  {
    return false;
  }
  // trajectory
  if (!trajectory_msgs__msg__JointTrajectory__copy(
      &(input->trajectory), &(output->trajectory)))
  {
    return false;
  }
  return true;
}

nimble_interfaces__msg__JointsTrajectory *
nimble_interfaces__msg__JointsTrajectory__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__JointsTrajectory * msg = (nimble_interfaces__msg__JointsTrajectory *)allocator.allocate(sizeof(nimble_interfaces__msg__JointsTrajectory), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nimble_interfaces__msg__JointsTrajectory));
  bool success = nimble_interfaces__msg__JointsTrajectory__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nimble_interfaces__msg__JointsTrajectory__destroy(nimble_interfaces__msg__JointsTrajectory * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nimble_interfaces__msg__JointsTrajectory__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nimble_interfaces__msg__JointsTrajectory__Sequence__init(nimble_interfaces__msg__JointsTrajectory__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__JointsTrajectory * data = NULL;

  if (size) {
    data = (nimble_interfaces__msg__JointsTrajectory *)allocator.zero_allocate(size, sizeof(nimble_interfaces__msg__JointsTrajectory), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nimble_interfaces__msg__JointsTrajectory__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nimble_interfaces__msg__JointsTrajectory__fini(&data[i - 1]);
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
nimble_interfaces__msg__JointsTrajectory__Sequence__fini(nimble_interfaces__msg__JointsTrajectory__Sequence * array)
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
      nimble_interfaces__msg__JointsTrajectory__fini(&array->data[i]);
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

nimble_interfaces__msg__JointsTrajectory__Sequence *
nimble_interfaces__msg__JointsTrajectory__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__JointsTrajectory__Sequence * array = (nimble_interfaces__msg__JointsTrajectory__Sequence *)allocator.allocate(sizeof(nimble_interfaces__msg__JointsTrajectory__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nimble_interfaces__msg__JointsTrajectory__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nimble_interfaces__msg__JointsTrajectory__Sequence__destroy(nimble_interfaces__msg__JointsTrajectory__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nimble_interfaces__msg__JointsTrajectory__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nimble_interfaces__msg__JointsTrajectory__Sequence__are_equal(const nimble_interfaces__msg__JointsTrajectory__Sequence * lhs, const nimble_interfaces__msg__JointsTrajectory__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nimble_interfaces__msg__JointsTrajectory__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nimble_interfaces__msg__JointsTrajectory__Sequence__copy(
  const nimble_interfaces__msg__JointsTrajectory__Sequence * input,
  nimble_interfaces__msg__JointsTrajectory__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nimble_interfaces__msg__JointsTrajectory);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nimble_interfaces__msg__JointsTrajectory * data =
      (nimble_interfaces__msg__JointsTrajectory *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nimble_interfaces__msg__JointsTrajectory__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nimble_interfaces__msg__JointsTrajectory__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nimble_interfaces__msg__JointsTrajectory__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
