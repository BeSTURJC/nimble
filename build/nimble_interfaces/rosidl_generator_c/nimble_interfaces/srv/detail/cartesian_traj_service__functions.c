// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nimble_interfaces:srv/CartesianTrajService.idl
// generated code does not contain a copyright notice
#include "nimble_interfaces/srv/detail/cartesian_traj_service__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `joints_trajectory`
#include "trajectory_msgs/msg/detail/joint_trajectory__functions.h"
// Member `measurements`
#include "nimble_interfaces/msg/detail/measurements__functions.h"

bool
nimble_interfaces__srv__CartesianTrajService_Request__init(nimble_interfaces__srv__CartesianTrajService_Request * msg)
{
  if (!msg) {
    return false;
  }
  // joints_trajectory
  if (!trajectory_msgs__msg__JointTrajectory__init(&msg->joints_trajectory)) {
    nimble_interfaces__srv__CartesianTrajService_Request__fini(msg);
    return false;
  }
  // measurements
  if (!nimble_interfaces__msg__Measurements__init(&msg->measurements)) {
    nimble_interfaces__srv__CartesianTrajService_Request__fini(msg);
    return false;
  }
  return true;
}

void
nimble_interfaces__srv__CartesianTrajService_Request__fini(nimble_interfaces__srv__CartesianTrajService_Request * msg)
{
  if (!msg) {
    return;
  }
  // joints_trajectory
  trajectory_msgs__msg__JointTrajectory__fini(&msg->joints_trajectory);
  // measurements
  nimble_interfaces__msg__Measurements__fini(&msg->measurements);
}

bool
nimble_interfaces__srv__CartesianTrajService_Request__are_equal(const nimble_interfaces__srv__CartesianTrajService_Request * lhs, const nimble_interfaces__srv__CartesianTrajService_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joints_trajectory
  if (!trajectory_msgs__msg__JointTrajectory__are_equal(
      &(lhs->joints_trajectory), &(rhs->joints_trajectory)))
  {
    return false;
  }
  // measurements
  if (!nimble_interfaces__msg__Measurements__are_equal(
      &(lhs->measurements), &(rhs->measurements)))
  {
    return false;
  }
  return true;
}

bool
nimble_interfaces__srv__CartesianTrajService_Request__copy(
  const nimble_interfaces__srv__CartesianTrajService_Request * input,
  nimble_interfaces__srv__CartesianTrajService_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // joints_trajectory
  if (!trajectory_msgs__msg__JointTrajectory__copy(
      &(input->joints_trajectory), &(output->joints_trajectory)))
  {
    return false;
  }
  // measurements
  if (!nimble_interfaces__msg__Measurements__copy(
      &(input->measurements), &(output->measurements)))
  {
    return false;
  }
  return true;
}

nimble_interfaces__srv__CartesianTrajService_Request *
nimble_interfaces__srv__CartesianTrajService_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__CartesianTrajService_Request * msg = (nimble_interfaces__srv__CartesianTrajService_Request *)allocator.allocate(sizeof(nimble_interfaces__srv__CartesianTrajService_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nimble_interfaces__srv__CartesianTrajService_Request));
  bool success = nimble_interfaces__srv__CartesianTrajService_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nimble_interfaces__srv__CartesianTrajService_Request__destroy(nimble_interfaces__srv__CartesianTrajService_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nimble_interfaces__srv__CartesianTrajService_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__init(nimble_interfaces__srv__CartesianTrajService_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__CartesianTrajService_Request * data = NULL;

  if (size) {
    data = (nimble_interfaces__srv__CartesianTrajService_Request *)allocator.zero_allocate(size, sizeof(nimble_interfaces__srv__CartesianTrajService_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nimble_interfaces__srv__CartesianTrajService_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nimble_interfaces__srv__CartesianTrajService_Request__fini(&data[i - 1]);
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
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__fini(nimble_interfaces__srv__CartesianTrajService_Request__Sequence * array)
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
      nimble_interfaces__srv__CartesianTrajService_Request__fini(&array->data[i]);
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

nimble_interfaces__srv__CartesianTrajService_Request__Sequence *
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__CartesianTrajService_Request__Sequence * array = (nimble_interfaces__srv__CartesianTrajService_Request__Sequence *)allocator.allocate(sizeof(nimble_interfaces__srv__CartesianTrajService_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nimble_interfaces__srv__CartesianTrajService_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__destroy(nimble_interfaces__srv__CartesianTrajService_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nimble_interfaces__srv__CartesianTrajService_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__are_equal(const nimble_interfaces__srv__CartesianTrajService_Request__Sequence * lhs, const nimble_interfaces__srv__CartesianTrajService_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nimble_interfaces__srv__CartesianTrajService_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__copy(
  const nimble_interfaces__srv__CartesianTrajService_Request__Sequence * input,
  nimble_interfaces__srv__CartesianTrajService_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nimble_interfaces__srv__CartesianTrajService_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nimble_interfaces__srv__CartesianTrajService_Request * data =
      (nimble_interfaces__srv__CartesianTrajService_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nimble_interfaces__srv__CartesianTrajService_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nimble_interfaces__srv__CartesianTrajService_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nimble_interfaces__srv__CartesianTrajService_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `cartesian_trajectory`
#include "nimble_interfaces/msg/detail/cartesian_trajectory__functions.h"
// Member `step_target`
#include "nimble_interfaces/msg/detail/therapy_requirements__functions.h"

bool
nimble_interfaces__srv__CartesianTrajService_Response__init(nimble_interfaces__srv__CartesianTrajService_Response * msg)
{
  if (!msg) {
    return false;
  }
  // cartesian_trajectory
  if (!nimble_interfaces__msg__CartesianTrajectory__init(&msg->cartesian_trajectory)) {
    nimble_interfaces__srv__CartesianTrajService_Response__fini(msg);
    return false;
  }
  // step_target
  if (!nimble_interfaces__msg__TherapyRequirements__init(&msg->step_target)) {
    nimble_interfaces__srv__CartesianTrajService_Response__fini(msg);
    return false;
  }
  return true;
}

void
nimble_interfaces__srv__CartesianTrajService_Response__fini(nimble_interfaces__srv__CartesianTrajService_Response * msg)
{
  if (!msg) {
    return;
  }
  // cartesian_trajectory
  nimble_interfaces__msg__CartesianTrajectory__fini(&msg->cartesian_trajectory);
  // step_target
  nimble_interfaces__msg__TherapyRequirements__fini(&msg->step_target);
}

bool
nimble_interfaces__srv__CartesianTrajService_Response__are_equal(const nimble_interfaces__srv__CartesianTrajService_Response * lhs, const nimble_interfaces__srv__CartesianTrajService_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // cartesian_trajectory
  if (!nimble_interfaces__msg__CartesianTrajectory__are_equal(
      &(lhs->cartesian_trajectory), &(rhs->cartesian_trajectory)))
  {
    return false;
  }
  // step_target
  if (!nimble_interfaces__msg__TherapyRequirements__are_equal(
      &(lhs->step_target), &(rhs->step_target)))
  {
    return false;
  }
  return true;
}

bool
nimble_interfaces__srv__CartesianTrajService_Response__copy(
  const nimble_interfaces__srv__CartesianTrajService_Response * input,
  nimble_interfaces__srv__CartesianTrajService_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // cartesian_trajectory
  if (!nimble_interfaces__msg__CartesianTrajectory__copy(
      &(input->cartesian_trajectory), &(output->cartesian_trajectory)))
  {
    return false;
  }
  // step_target
  if (!nimble_interfaces__msg__TherapyRequirements__copy(
      &(input->step_target), &(output->step_target)))
  {
    return false;
  }
  return true;
}

nimble_interfaces__srv__CartesianTrajService_Response *
nimble_interfaces__srv__CartesianTrajService_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__CartesianTrajService_Response * msg = (nimble_interfaces__srv__CartesianTrajService_Response *)allocator.allocate(sizeof(nimble_interfaces__srv__CartesianTrajService_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nimble_interfaces__srv__CartesianTrajService_Response));
  bool success = nimble_interfaces__srv__CartesianTrajService_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nimble_interfaces__srv__CartesianTrajService_Response__destroy(nimble_interfaces__srv__CartesianTrajService_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nimble_interfaces__srv__CartesianTrajService_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__init(nimble_interfaces__srv__CartesianTrajService_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__CartesianTrajService_Response * data = NULL;

  if (size) {
    data = (nimble_interfaces__srv__CartesianTrajService_Response *)allocator.zero_allocate(size, sizeof(nimble_interfaces__srv__CartesianTrajService_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nimble_interfaces__srv__CartesianTrajService_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nimble_interfaces__srv__CartesianTrajService_Response__fini(&data[i - 1]);
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
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__fini(nimble_interfaces__srv__CartesianTrajService_Response__Sequence * array)
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
      nimble_interfaces__srv__CartesianTrajService_Response__fini(&array->data[i]);
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

nimble_interfaces__srv__CartesianTrajService_Response__Sequence *
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__CartesianTrajService_Response__Sequence * array = (nimble_interfaces__srv__CartesianTrajService_Response__Sequence *)allocator.allocate(sizeof(nimble_interfaces__srv__CartesianTrajService_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nimble_interfaces__srv__CartesianTrajService_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__destroy(nimble_interfaces__srv__CartesianTrajService_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nimble_interfaces__srv__CartesianTrajService_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__are_equal(const nimble_interfaces__srv__CartesianTrajService_Response__Sequence * lhs, const nimble_interfaces__srv__CartesianTrajService_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nimble_interfaces__srv__CartesianTrajService_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__copy(
  const nimble_interfaces__srv__CartesianTrajService_Response__Sequence * input,
  nimble_interfaces__srv__CartesianTrajService_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nimble_interfaces__srv__CartesianTrajService_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nimble_interfaces__srv__CartesianTrajService_Response * data =
      (nimble_interfaces__srv__CartesianTrajService_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nimble_interfaces__srv__CartesianTrajService_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nimble_interfaces__srv__CartesianTrajService_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nimble_interfaces__srv__CartesianTrajService_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
