// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nimble_interfaces:msg/FrameState.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__STRUCT_H_
#define NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/FrameState in the package nimble_interfaces.
typedef struct nimble_interfaces__msg__FrameState
{
  std_msgs__msg__Header header;
  double optic_sensor;
  double velocity;
  double position;
} nimble_interfaces__msg__FrameState;

// Struct for a sequence of nimble_interfaces__msg__FrameState.
typedef struct nimble_interfaces__msg__FrameState__Sequence
{
  nimble_interfaces__msg__FrameState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nimble_interfaces__msg__FrameState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__STRUCT_H_
