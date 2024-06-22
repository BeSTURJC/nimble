// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from nimble_interfaces:srv/TrajGeneratorService.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__STRUCT_H_
#define NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'measurements'
#include "nimble_interfaces/msg/detail/measurements__struct.h"
// Member 'therapy_requirements'
#include "nimble_interfaces/msg/detail/therapy_requirements__struct.h"

/// Struct defined in srv/TrajGeneratorService in the package nimble_interfaces.
typedef struct nimble_interfaces__srv__TrajGeneratorService_Request
{
  nimble_interfaces__msg__Measurements measurements;
  nimble_interfaces__msg__TherapyRequirements therapy_requirements;
} nimble_interfaces__srv__TrajGeneratorService_Request;

// Struct for a sequence of nimble_interfaces__srv__TrajGeneratorService_Request.
typedef struct nimble_interfaces__srv__TrajGeneratorService_Request__Sequence
{
  nimble_interfaces__srv__TrajGeneratorService_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nimble_interfaces__srv__TrajGeneratorService_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'joints_trajectory'
#include "trajectory_msgs/msg/detail/joint_trajectory__struct.h"

/// Struct defined in srv/TrajGeneratorService in the package nimble_interfaces.
typedef struct nimble_interfaces__srv__TrajGeneratorService_Response
{
  trajectory_msgs__msg__JointTrajectory joints_trajectory;
} nimble_interfaces__srv__TrajGeneratorService_Response;

// Struct for a sequence of nimble_interfaces__srv__TrajGeneratorService_Response.
typedef struct nimble_interfaces__srv__TrajGeneratorService_Response__Sequence
{
  nimble_interfaces__srv__TrajGeneratorService_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} nimble_interfaces__srv__TrajGeneratorService_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NIMBLE_INTERFACES__SRV__DETAIL__TRAJ_GENERATOR_SERVICE__STRUCT_H_
