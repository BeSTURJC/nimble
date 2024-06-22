// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nimble_interfaces:srv/TrajGeneratorService.idl
// generated code does not contain a copyright notice
#include "nimble_interfaces/srv/detail/traj_generator_service__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `measurements`
#include "nimble_interfaces/msg/detail/measurements__functions.h"
// Member `therapy_requirements`
#include "nimble_interfaces/msg/detail/therapy_requirements__functions.h"

bool
nimble_interfaces__srv__TrajGeneratorService_Request__init(nimble_interfaces__srv__TrajGeneratorService_Request * msg)
{
  if (!msg) {
    return false;
  }
  // measurements
  if (!nimble_interfaces__msg__Measurements__init(&msg->measurements)) {
    nimble_interfaces__srv__TrajGeneratorService_Request__fini(msg);
    return false;
  }
  // therapy_requirements
  if (!nimble_interfaces__msg__TherapyRequirements__init(&msg->therapy_requirements)) {
    nimble_interfaces__srv__TrajGeneratorService_Request__fini(msg);
    return false;
  }
  return true;
}

void
nimble_interfaces__srv__TrajGeneratorService_Request__fini(nimble_interfaces__srv__TrajGeneratorService_Request * msg)
{
  if (!msg) {
    return;
  }
  // measurements
  nimble_interfaces__msg__Measurements__fini(&msg->measurements);
  // therapy_requirements
  nimble_interfaces__msg__TherapyRequirements__fini(&msg->therapy_requirements);
}

bool
nimble_interfaces__srv__TrajGeneratorService_Request__are_equal(const nimble_interfaces__srv__TrajGeneratorService_Request * lhs, const nimble_interfaces__srv__TrajGeneratorService_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // measurements
  if (!nimble_interfaces__msg__Measurements__are_equal(
      &(lhs->measurements), &(rhs->measurements)))
  {
    return false;
  }
  // therapy_requirements
  if (!nimble_interfaces__msg__TherapyRequirements__are_equal(
      &(lhs->therapy_requirements), &(rhs->therapy_requirements)))
  {
    return false;
  }
  return true;
}

bool
nimble_interfaces__srv__TrajGeneratorService_Request__copy(
  const nimble_interfaces__srv__TrajGeneratorService_Request * input,
  nimble_interfaces__srv__TrajGeneratorService_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // measurements
  if (!nimble_interfaces__msg__Measurements__copy(
      &(input->measurements), &(output->measurements)))
  {
    return false;
  }
  // therapy_requirements
  if (!nimble_interfaces__msg__TherapyRequirements__copy(
      &(input->therapy_requirements), &(output->therapy_requirements)))
  {
    return false;
  }
  return true;
}

nimble_interfaces__srv__TrajGeneratorService_Request *
nimble_interfaces__srv__TrajGeneratorService_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__TrajGeneratorService_Request * msg = (nimble_interfaces__srv__TrajGeneratorService_Request *)allocator.allocate(sizeof(nimble_interfaces__srv__TrajGeneratorService_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nimble_interfaces__srv__TrajGeneratorService_Request));
  bool success = nimble_interfaces__srv__TrajGeneratorService_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nimble_interfaces__srv__TrajGeneratorService_Request__destroy(nimble_interfaces__srv__TrajGeneratorService_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nimble_interfaces__srv__TrajGeneratorService_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nimble_interfaces__srv__TrajGeneratorService_Request__Sequence__init(nimble_interfaces__srv__TrajGeneratorService_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__TrajGeneratorService_Request * data = NULL;

  if (size) {
    data = (nimble_interfaces__srv__TrajGeneratorService_Request *)allocator.zero_allocate(size, sizeof(nimble_interfaces__srv__TrajGeneratorService_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nimble_interfaces__srv__TrajGeneratorService_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nimble_interfaces__srv__TrajGeneratorService_Request__fini(&data[i - 1]);
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
nimble_interfaces__srv__TrajGeneratorService_Request__Sequence__fini(nimble_interfaces__srv__TrajGeneratorService_Request__Sequence * array)
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
      nimble_interfaces__srv__TrajGeneratorService_Request__fini(&array->data[i]);
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

nimble_interfaces__srv__TrajGeneratorService_Request__Sequence *
nimble_interfaces__srv__TrajGeneratorService_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__TrajGeneratorService_Request__Sequence * array = (nimble_interfaces__srv__TrajGeneratorService_Request__Sequence *)allocator.allocate(sizeof(nimble_interfaces__srv__TrajGeneratorService_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nimble_interfaces__srv__TrajGeneratorService_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nimble_interfaces__srv__TrajGeneratorService_Request__Sequence__destroy(nimble_interfaces__srv__TrajGeneratorService_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nimble_interfaces__srv__TrajGeneratorService_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nimble_interfaces__srv__TrajGeneratorService_Request__Sequence__are_equal(const nimble_interfaces__srv__TrajGeneratorService_Request__Sequence * lhs, const nimble_interfaces__srv__TrajGeneratorService_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nimble_interfaces__srv__TrajGeneratorService_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nimble_interfaces__srv__TrajGeneratorService_Request__Sequence__copy(
  const nimble_interfaces__srv__TrajGeneratorService_Request__Sequence * input,
  nimble_interfaces__srv__TrajGeneratorService_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nimble_interfaces__srv__TrajGeneratorService_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nimble_interfaces__srv__TrajGeneratorService_Request * data =
      (nimble_interfaces__srv__TrajGeneratorService_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nimble_interfaces__srv__TrajGeneratorService_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nimble_interfaces__srv__TrajGeneratorService_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nimble_interfaces__srv__TrajGeneratorService_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `joints_trajectory`
#include "trajectory_msgs/msg/detail/joint_trajectory__functions.h"

bool
nimble_interfaces__srv__TrajGeneratorService_Response__init(nimble_interfaces__srv__TrajGeneratorService_Response * msg)
{
  if (!msg) {
    return false;
  }
  // joints_trajectory
  if (!trajectory_msgs__msg__JointTrajectory__init(&msg->joints_trajectory)) {
    nimble_interfaces__srv__TrajGeneratorService_Response__fini(msg);
    return false;
  }
  return true;
}

void
nimble_interfaces__srv__TrajGeneratorService_Response__fini(nimble_interfaces__srv__TrajGeneratorService_Response * msg)
{
  if (!msg) {
    return;
  }
  // joints_trajectory
  trajectory_msgs__msg__JointTrajectory__fini(&msg->joints_trajectory);
}

bool
nimble_interfaces__srv__TrajGeneratorService_Response__are_equal(const nimble_interfaces__srv__TrajGeneratorService_Response * lhs, const nimble_interfaces__srv__TrajGeneratorService_Response * rhs)
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
  return true;
}

bool
nimble_interfaces__srv__TrajGeneratorService_Response__copy(
  const nimble_interfaces__srv__TrajGeneratorService_Response * input,
  nimble_interfaces__srv__TrajGeneratorService_Response * output)
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
  return true;
}

nimble_interfaces__srv__TrajGeneratorService_Response *
nimble_interfaces__srv__TrajGeneratorService_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__TrajGeneratorService_Response * msg = (nimble_interfaces__srv__TrajGeneratorService_Response *)allocator.allocate(sizeof(nimble_interfaces__srv__TrajGeneratorService_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nimble_interfaces__srv__TrajGeneratorService_Response));
  bool success = nimble_interfaces__srv__TrajGeneratorService_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nimble_interfaces__srv__TrajGeneratorService_Response__destroy(nimble_interfaces__srv__TrajGeneratorService_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nimble_interfaces__srv__TrajGeneratorService_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nimble_interfaces__srv__TrajGeneratorService_Response__Sequence__init(nimble_interfaces__srv__TrajGeneratorService_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__TrajGeneratorService_Response * data = NULL;

  if (size) {
    data = (nimble_interfaces__srv__TrajGeneratorService_Response *)allocator.zero_allocate(size, sizeof(nimble_interfaces__srv__TrajGeneratorService_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nimble_interfaces__srv__TrajGeneratorService_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nimble_interfaces__srv__TrajGeneratorService_Response__fini(&data[i - 1]);
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
nimble_interfaces__srv__TrajGeneratorService_Response__Sequence__fini(nimble_interfaces__srv__TrajGeneratorService_Response__Sequence * array)
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
      nimble_interfaces__srv__TrajGeneratorService_Response__fini(&array->data[i]);
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

nimble_interfaces__srv__TrajGeneratorService_Response__Sequence *
nimble_interfaces__srv__TrajGeneratorService_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__srv__TrajGeneratorService_Response__Sequence * array = (nimble_interfaces__srv__TrajGeneratorService_Response__Sequence *)allocator.allocate(sizeof(nimble_interfaces__srv__TrajGeneratorService_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nimble_interfaces__srv__TrajGeneratorService_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nimble_interfaces__srv__TrajGeneratorService_Response__Sequence__destroy(nimble_interfaces__srv__TrajGeneratorService_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nimble_interfaces__srv__TrajGeneratorService_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nimble_interfaces__srv__TrajGeneratorService_Response__Sequence__are_equal(const nimble_interfaces__srv__TrajGeneratorService_Response__Sequence * lhs, const nimble_interfaces__srv__TrajGeneratorService_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nimble_interfaces__srv__TrajGeneratorService_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nimble_interfaces__srv__TrajGeneratorService_Response__Sequence__copy(
  const nimble_interfaces__srv__TrajGeneratorService_Response__Sequence * input,
  nimble_interfaces__srv__TrajGeneratorService_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nimble_interfaces__srv__TrajGeneratorService_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nimble_interfaces__srv__TrajGeneratorService_Response * data =
      (nimble_interfaces__srv__TrajGeneratorService_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nimble_interfaces__srv__TrajGeneratorService_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nimble_interfaces__srv__TrajGeneratorService_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nimble_interfaces__srv__TrajGeneratorService_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
