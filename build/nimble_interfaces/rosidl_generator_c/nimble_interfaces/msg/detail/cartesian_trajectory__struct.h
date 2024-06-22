// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nimble_interfaces:msg/CartesianTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__STRUCT_H_
#define NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__STRUCT_H_

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
// Member 'malleolus'
// Member 'pelvis'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/CartesianTrajectory in the package nimble_interfaces.
typedef struct nimble_interfaces__msg__CartesianTrajectory
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Point__Sequence malleolus;
  /// Tobillo
  geometry_msgs__msg__Point__Sequence pelvis;
} nimble_interfaces__msg__CartesianTrajectory;

// Struct for a sequence of nimble_interfaces__msg__CartesianTrajectory.
typedef struct nimble_interfaces__msg__CartesianTrajectory__Sequence
{
  nimble_interfaces__msg__CartesianTrajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nimble_interfaces__msg__CartesianTrajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_TRAJECTORY__STRUCT_H_
