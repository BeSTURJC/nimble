// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nimble_interfaces:msg/CartesianFullTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__STRUCT_H_
#define NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__STRUCT_H_

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
// Member 'left_pelvis'
// Member 'right_pelvis'
// Member 'base_pelvis'
// Member 'left_hip'
// Member 'right_hip'
// Member 'left_knee'
// Member 'right_knee'
// Member 'left_ankle'
// Member 'right_ankle'
// Member 'left_heel'
// Member 'right_heel'
// Member 'left_toe'
// Member 'right_toe'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/CartesianFullTrajectory in the package nimble_interfaces.
typedef struct nimble_interfaces__msg__CartesianFullTrajectory
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Point__Sequence left_pelvis;
  geometry_msgs__msg__Point__Sequence right_pelvis;
  geometry_msgs__msg__Point__Sequence base_pelvis;
  geometry_msgs__msg__Point__Sequence left_hip;
  geometry_msgs__msg__Point__Sequence right_hip;
  geometry_msgs__msg__Point__Sequence left_knee;
  geometry_msgs__msg__Point__Sequence right_knee;
  geometry_msgs__msg__Point__Sequence left_ankle;
  geometry_msgs__msg__Point__Sequence right_ankle;
  geometry_msgs__msg__Point__Sequence left_heel;
  geometry_msgs__msg__Point__Sequence right_heel;
  geometry_msgs__msg__Point__Sequence left_toe;
  geometry_msgs__msg__Point__Sequence right_toe;
} nimble_interfaces__msg__CartesianFullTrajectory;

// Struct for a sequence of nimble_interfaces__msg__CartesianFullTrajectory.
typedef struct nimble_interfaces__msg__CartesianFullTrajectory__Sequence
{
  nimble_interfaces__msg__CartesianFullTrajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nimble_interfaces__msg__CartesianFullTrajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__CARTESIAN_FULL_TRAJECTORY__STRUCT_H_
