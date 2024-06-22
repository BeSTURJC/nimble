// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from nimble_interfaces:msg/Measurements.idl
// generated code does not contain a copyright notice
#include "nimble_interfaces/msg/detail/measurements__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
nimble_interfaces__msg__Measurements__init(nimble_interfaces__msg__Measurements * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    nimble_interfaces__msg__Measurements__fini(msg);
    return false;
  }
  // height
  // femur
  // tibia
  // height_ankle
  // distance_to_heel
  // distance_to_toe
  // depth_pelvis
  // width_pelvis
  return true;
}

void
nimble_interfaces__msg__Measurements__fini(nimble_interfaces__msg__Measurements * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // height
  // femur
  // tibia
  // height_ankle
  // distance_to_heel
  // distance_to_toe
  // depth_pelvis
  // width_pelvis
}

bool
nimble_interfaces__msg__Measurements__are_equal(const nimble_interfaces__msg__Measurements * lhs, const nimble_interfaces__msg__Measurements * rhs)
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
  // height
  if (lhs->height != rhs->height) {
    return false;
  }
  // femur
  if (lhs->femur != rhs->femur) {
    return false;
  }
  // tibia
  if (lhs->tibia != rhs->tibia) {
    return false;
  }
  // height_ankle
  if (lhs->height_ankle != rhs->height_ankle) {
    return false;
  }
  // distance_to_heel
  if (lhs->distance_to_heel != rhs->distance_to_heel) {
    return false;
  }
  // distance_to_toe
  if (lhs->distance_to_toe != rhs->distance_to_toe) {
    return false;
  }
  // depth_pelvis
  if (lhs->depth_pelvis != rhs->depth_pelvis) {
    return false;
  }
  // width_pelvis
  if (lhs->width_pelvis != rhs->width_pelvis) {
    return false;
  }
  return true;
}

bool
nimble_interfaces__msg__Measurements__copy(
  const nimble_interfaces__msg__Measurements * input,
  nimble_interfaces__msg__Measurements * output)
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
  // height
  output->height = input->height;
  // femur
  output->femur = input->femur;
  // tibia
  output->tibia = input->tibia;
  // height_ankle
  output->height_ankle = input->height_ankle;
  // distance_to_heel
  output->distance_to_heel = input->distance_to_heel;
  // distance_to_toe
  output->distance_to_toe = input->distance_to_toe;
  // depth_pelvis
  output->depth_pelvis = input->depth_pelvis;
  // width_pelvis
  output->width_pelvis = input->width_pelvis;
  return true;
}

nimble_interfaces__msg__Measurements *
nimble_interfaces__msg__Measurements__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__Measurements * msg = (nimble_interfaces__msg__Measurements *)allocator.allocate(sizeof(nimble_interfaces__msg__Measurements), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(nimble_interfaces__msg__Measurements));
  bool success = nimble_interfaces__msg__Measurements__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
nimble_interfaces__msg__Measurements__destroy(nimble_interfaces__msg__Measurements * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    nimble_interfaces__msg__Measurements__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
nimble_interfaces__msg__Measurements__Sequence__init(nimble_interfaces__msg__Measurements__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__Measurements * data = NULL;

  if (size) {
    data = (nimble_interfaces__msg__Measurements *)allocator.zero_allocate(size, sizeof(nimble_interfaces__msg__Measurements), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = nimble_interfaces__msg__Measurements__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        nimble_interfaces__msg__Measurements__fini(&data[i - 1]);
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
nimble_interfaces__msg__Measurements__Sequence__fini(nimble_interfaces__msg__Measurements__Sequence * array)
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
      nimble_interfaces__msg__Measurements__fini(&array->data[i]);
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

nimble_interfaces__msg__Measurements__Sequence *
nimble_interfaces__msg__Measurements__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  nimble_interfaces__msg__Measurements__Sequence * array = (nimble_interfaces__msg__Measurements__Sequence *)allocator.allocate(sizeof(nimble_interfaces__msg__Measurements__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = nimble_interfaces__msg__Measurements__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
nimble_interfaces__msg__Measurements__Sequence__destroy(nimble_interfaces__msg__Measurements__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    nimble_interfaces__msg__Measurements__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
nimble_interfaces__msg__Measurements__Sequence__are_equal(const nimble_interfaces__msg__Measurements__Sequence * lhs, const nimble_interfaces__msg__Measurements__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!nimble_interfaces__msg__Measurements__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
nimble_interfaces__msg__Measurements__Sequence__copy(
  const nimble_interfaces__msg__Measurements__Sequence * input,
  nimble_interfaces__msg__Measurements__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(nimble_interfaces__msg__Measurements);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    nimble_interfaces__msg__Measurements * data =
      (nimble_interfaces__msg__Measurements *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!nimble_interfaces__msg__Measurements__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          nimble_interfaces__msg__Measurements__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!nimble_interfaces__msg__Measurements__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
