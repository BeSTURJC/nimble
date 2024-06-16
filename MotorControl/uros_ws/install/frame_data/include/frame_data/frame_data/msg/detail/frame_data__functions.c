// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from frame_data:msg/FrameData.idl
// generated code does not contain a copyright notice
#include "frame_data/msg/detail/frame_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
frame_data__msg__FrameData__init(frame_data__msg__FrameData * msg)
{
  if (!msg) {
    return false;
  }
  // contador
  // frame_position
  // frame_speed
  // sensor_dist
  // position_ref
  // speed_ref
  return true;
}

void
frame_data__msg__FrameData__fini(frame_data__msg__FrameData * msg)
{
  if (!msg) {
    return;
  }
  // contador
  // frame_position
  // frame_speed
  // sensor_dist
  // position_ref
  // speed_ref
}

bool
frame_data__msg__FrameData__are_equal(const frame_data__msg__FrameData * lhs, const frame_data__msg__FrameData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // contador
  if (lhs->contador != rhs->contador) {
    return false;
  }
  // frame_position
  if (lhs->frame_position != rhs->frame_position) {
    return false;
  }
  // frame_speed
  if (lhs->frame_speed != rhs->frame_speed) {
    return false;
  }
  // sensor_dist
  if (lhs->sensor_dist != rhs->sensor_dist) {
    return false;
  }
  // position_ref
  if (lhs->position_ref != rhs->position_ref) {
    return false;
  }
  // speed_ref
  if (lhs->speed_ref != rhs->speed_ref) {
    return false;
  }
  return true;
}

bool
frame_data__msg__FrameData__copy(
  const frame_data__msg__FrameData * input,
  frame_data__msg__FrameData * output)
{
  if (!input || !output) {
    return false;
  }
  // contador
  output->contador = input->contador;
  // frame_position
  output->frame_position = input->frame_position;
  // frame_speed
  output->frame_speed = input->frame_speed;
  // sensor_dist
  output->sensor_dist = input->sensor_dist;
  // position_ref
  output->position_ref = input->position_ref;
  // speed_ref
  output->speed_ref = input->speed_ref;
  return true;
}

frame_data__msg__FrameData *
frame_data__msg__FrameData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frame_data__msg__FrameData * msg = (frame_data__msg__FrameData *)allocator.allocate(sizeof(frame_data__msg__FrameData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(frame_data__msg__FrameData));
  bool success = frame_data__msg__FrameData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
frame_data__msg__FrameData__destroy(frame_data__msg__FrameData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    frame_data__msg__FrameData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
frame_data__msg__FrameData__Sequence__init(frame_data__msg__FrameData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frame_data__msg__FrameData * data = NULL;

  if (size) {
    data = (frame_data__msg__FrameData *)allocator.zero_allocate(size, sizeof(frame_data__msg__FrameData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = frame_data__msg__FrameData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        frame_data__msg__FrameData__fini(&data[i - 1]);
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
frame_data__msg__FrameData__Sequence__fini(frame_data__msg__FrameData__Sequence * array)
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
      frame_data__msg__FrameData__fini(&array->data[i]);
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

frame_data__msg__FrameData__Sequence *
frame_data__msg__FrameData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  frame_data__msg__FrameData__Sequence * array = (frame_data__msg__FrameData__Sequence *)allocator.allocate(sizeof(frame_data__msg__FrameData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = frame_data__msg__FrameData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
frame_data__msg__FrameData__Sequence__destroy(frame_data__msg__FrameData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    frame_data__msg__FrameData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
frame_data__msg__FrameData__Sequence__are_equal(const frame_data__msg__FrameData__Sequence * lhs, const frame_data__msg__FrameData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!frame_data__msg__FrameData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
frame_data__msg__FrameData__Sequence__copy(
  const frame_data__msg__FrameData__Sequence * input,
  frame_data__msg__FrameData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(frame_data__msg__FrameData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    frame_data__msg__FrameData * data =
      (frame_data__msg__FrameData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!frame_data__msg__FrameData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          frame_data__msg__FrameData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!frame_data__msg__FrameData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
