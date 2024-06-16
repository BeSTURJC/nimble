// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from frame_data:msg/FrameData.idl
// generated code does not contain a copyright notice

#ifndef FRAME_DATA__MSG__DETAIL__FRAME_DATA__STRUCT_H_
#define FRAME_DATA__MSG__DETAIL__FRAME_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/FrameData in the package frame_data.
typedef struct frame_data__msg__FrameData
{
  uint32_t contador;
  float frame_position;
  float frame_speed;
  float sensor_dist;
  float position_ref;
  float speed_ref;
} frame_data__msg__FrameData;

// Struct for a sequence of frame_data__msg__FrameData.
typedef struct frame_data__msg__FrameData__Sequence
{
  frame_data__msg__FrameData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} frame_data__msg__FrameData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // FRAME_DATA__MSG__DETAIL__FRAME_DATA__STRUCT_H_
