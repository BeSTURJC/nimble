// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nimble_interfaces:msg/Measurements.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__STRUCT_H_
#define NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__STRUCT_H_

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

/// Struct defined in msg/Measurements in the package nimble_interfaces.
typedef struct nimble_interfaces__msg__Measurements
{
  std_msgs__msg__Header header;
  double height;
  double femur;
  double tibia;
  double height_ankle;
  double distance_to_heel;
  double distance_to_toe;
  double depth_pelvis;
  double width_pelvis;
} nimble_interfaces__msg__Measurements;

// Struct for a sequence of nimble_interfaces__msg__Measurements.
typedef struct nimble_interfaces__msg__Measurements__Sequence
{
  nimble_interfaces__msg__Measurements * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nimble_interfaces__msg__Measurements__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__MEASUREMENTS__STRUCT_H_
