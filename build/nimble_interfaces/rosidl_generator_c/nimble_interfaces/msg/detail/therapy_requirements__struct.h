// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nimble_interfaces:msg/TherapyRequirements.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__STRUCT_H_
#define NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__STRUCT_H_

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

/// Struct defined in msg/TherapyRequirements in the package nimble_interfaces.
typedef struct nimble_interfaces__msg__TherapyRequirements
{
  std_msgs__msg__Header header;
  double speed;
  double step_length;
  double step_height;
  int32_t min_assist_level;
  int32_t max_assist_level;
} nimble_interfaces__msg__TherapyRequirements;

// Struct for a sequence of nimble_interfaces__msg__TherapyRequirements.
typedef struct nimble_interfaces__msg__TherapyRequirements__Sequence
{
  nimble_interfaces__msg__TherapyRequirements * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nimble_interfaces__msg__TherapyRequirements__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__THERAPY_REQUIREMENTS__STRUCT_H_
