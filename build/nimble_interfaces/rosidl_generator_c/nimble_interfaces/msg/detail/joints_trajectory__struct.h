// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nimble_interfaces:msg/JointsTrajectory.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__STRUCT_H_
#define NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__STRUCT_H_

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
// Member 'phase'
#include "std_msgs/msg/detail/float32_multi_array__struct.h"
// Member 'trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.h"

/// Struct defined in msg/JointsTrajectory in the package nimble_interfaces.
typedef struct nimble_interfaces__msg__JointsTrajectory
{
  std_msgs__msg__Header header;
  std_msgs__msg__Float32MultiArray phase;
  trajectory_msgs__msg__JointTrajectory trajectory;
  bool new_indicator;
} nimble_interfaces__msg__JointsTrajectory;

// Struct for a sequence of nimble_interfaces__msg__JointsTrajectory.
typedef struct nimble_interfaces__msg__JointsTrajectory__Sequence
{
  nimble_interfaces__msg__JointsTrajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nimble_interfaces__msg__JointsTrajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__JOINTS_TRAJECTORY__STRUCT_H_
