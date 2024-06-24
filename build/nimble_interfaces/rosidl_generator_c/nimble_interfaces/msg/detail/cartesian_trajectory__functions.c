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
// Member `left_pelvis`
// Member `right_pelvis`
// Member `base_pelvis`
// Member `left_hip`
// Member `right_hip`
// Member `left_knee`
// Member `right_knee`
// Member `left_ankle`
// Member `right_ankle`
// Member `left_heel`
// Member `right_heel`
// Member `left_toe`
// Member `right_toe`
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
  // left_pelvis
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->left_pelvis, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // right_pelvis
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->right_pelvis, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // base_pelvis
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->base_pelvis, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // left_hip
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->left_hip, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // right_hip
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->right_hip, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // left_knee
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->left_knee, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // right_knee
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->right_knee, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // left_ankle
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->left_ankle, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // right_ankle
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->right_ankle, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // left_heel
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->left_heel, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // right_heel
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->right_heel, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // left_toe
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->left_toe, 0)) {
    nimble_interfaces__msg__CartesianTrajectory__fini(msg);
    return false;
  }
  // right_toe
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->right_toe, 0)) {
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
  // left_pelvis
  geometry_msgs__msg__Point__Sequence__fini(&msg->left_pelvis);
  // right_pelvis
  geometry_msgs__msg__Point__Sequence__fini(&msg->right_pelvis);
  // base_pelvis
  geometry_msgs__msg__Point__Sequence__fini(&msg->base_pelvis);
  // left_hip
  geometry_msgs__msg__Point__Sequence__fini(&msg->left_hip);
  // right_hip
  geometry_msgs__msg__Point__Sequence__fini(&msg->right_hip);
  // left_knee
  geometry_msgs__msg__Point__Sequence__fini(&msg->left_knee);
  // right_knee
  geometry_msgs__msg__Point__Sequence__fini(&msg->right_knee);
  // left_ankle
  geometry_msgs__msg__Point__Sequence__fini(&msg->left_ankle);
  // right_ankle
  geometry_msgs__msg__Point__Sequence__fini(&msg->right_ankle);
  // left_heel
  geometry_msgs__msg__Point__Sequence__fini(&msg->left_heel);
  // right_heel
  geometry_msgs__msg__Point__Sequence__fini(&msg->right_heel);
  // left_toe
  geometry_msgs__msg__Point__Sequence__fini(&msg->left_toe);
  // right_toe
  geometry_msgs__msg__Point__Sequence__fini(&msg->right_toe);
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
  // left_pelvis
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->left_pelvis), &(rhs->left_pelvis)))
  {
    return false;
  }
  // right_pelvis
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->right_pelvis), &(rhs->right_pelvis)))
  {
    return false;
  }
  // base_pelvis
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->base_pelvis), &(rhs->base_pelvis)))
  {
    return false;
  }
  // left_hip
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->left_hip), &(rhs->left_hip)))
  {
    return false;
  }
  // right_hip
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->right_hip), &(rhs->right_hip)))
  {
    return false;
  }
  // left_knee
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->left_knee), &(rhs->left_knee)))
  {
    return false;
  }
  // right_knee
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->right_knee), &(rhs->right_knee)))
  {
    return false;
  }
  // left_ankle
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->left_ankle), &(rhs->left_ankle)))
  {
    return false;
  }
  // right_ankle
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->right_ankle), &(rhs->right_ankle)))
  {
    return false;
  }
  // left_heel
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->left_heel), &(rhs->left_heel)))
  {
    return false;
  }
  // right_heel
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->right_heel), &(rhs->right_heel)))
  {
    return false;
  }
  // left_toe
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->left_toe), &(rhs->left_toe)))
  {
    return false;
  }
  // right_toe
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->right_toe), &(rhs->right_toe)))
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
  // left_pelvis
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->left_pelvis), &(output->left_pelvis)))
  {
    return false;
  }
  // right_pelvis
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->right_pelvis), &(output->right_pelvis)))
  {
    return false;
  }
  // base_pelvis
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->base_pelvis), &(output->base_pelvis)))
  {
    return false;
  }
  // left_hip
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->left_hip), &(output->left_hip)))
  {
    return false;
  }
  // right_hip
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->right_hip), &(output->right_hip)))
  {
    return false;
  }
  // left_knee
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->left_knee), &(output->left_knee)))
  {
    return false;
  }
  // right_knee
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->right_knee), &(output->right_knee)))
  {
    return false;
  }
  // left_ankle
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->left_ankle), &(output->left_ankle)))
  {
    return false;
  }
  // right_ankle
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->right_ankle), &(output->right_ankle)))
  {
    return false;
  }
  // left_heel
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->left_heel), &(output->left_heel)))
  {
    return false;
  }
  // right_heel
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->right_heel), &(output->right_heel)))
  {
    return false;
  }
  // left_toe
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->left_toe), &(output->left_toe)))
  {
    return false;
  }
  // right_toe
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->right_toe), &(output->right_toe)))
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
