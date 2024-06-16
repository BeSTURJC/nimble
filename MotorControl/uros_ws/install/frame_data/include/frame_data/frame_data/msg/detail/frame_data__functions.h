// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from frame_data:msg/FrameData.idl
// generated code does not contain a copyright notice

#ifndef FRAME_DATA__MSG__DETAIL__FRAME_DATA__FUNCTIONS_H_
#define FRAME_DATA__MSG__DETAIL__FRAME_DATA__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "frame_data/msg/rosidl_generator_c__visibility_control.h"

#include "frame_data/msg/detail/frame_data__struct.h"

/// Initialize msg/FrameData message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * frame_data__msg__FrameData
 * )) before or use
 * frame_data__msg__FrameData__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
bool
frame_data__msg__FrameData__init(frame_data__msg__FrameData * msg);

/// Finalize msg/FrameData message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
void
frame_data__msg__FrameData__fini(frame_data__msg__FrameData * msg);

/// Create msg/FrameData message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * frame_data__msg__FrameData__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
frame_data__msg__FrameData *
frame_data__msg__FrameData__create();

/// Destroy msg/FrameData message.
/**
 * It calls
 * frame_data__msg__FrameData__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
void
frame_data__msg__FrameData__destroy(frame_data__msg__FrameData * msg);

/// Check for msg/FrameData message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
bool
frame_data__msg__FrameData__are_equal(const frame_data__msg__FrameData * lhs, const frame_data__msg__FrameData * rhs);

/// Copy a msg/FrameData message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
bool
frame_data__msg__FrameData__copy(
  const frame_data__msg__FrameData * input,
  frame_data__msg__FrameData * output);

/// Initialize array of msg/FrameData messages.
/**
 * It allocates the memory for the number of elements and calls
 * frame_data__msg__FrameData__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
bool
frame_data__msg__FrameData__Sequence__init(frame_data__msg__FrameData__Sequence * array, size_t size);

/// Finalize array of msg/FrameData messages.
/**
 * It calls
 * frame_data__msg__FrameData__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
void
frame_data__msg__FrameData__Sequence__fini(frame_data__msg__FrameData__Sequence * array);

/// Create array of msg/FrameData messages.
/**
 * It allocates the memory for the array and calls
 * frame_data__msg__FrameData__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
frame_data__msg__FrameData__Sequence *
frame_data__msg__FrameData__Sequence__create(size_t size);

/// Destroy array of msg/FrameData messages.
/**
 * It calls
 * frame_data__msg__FrameData__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
void
frame_data__msg__FrameData__Sequence__destroy(frame_data__msg__FrameData__Sequence * array);

/// Check for msg/FrameData message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
bool
frame_data__msg__FrameData__Sequence__are_equal(const frame_data__msg__FrameData__Sequence * lhs, const frame_data__msg__FrameData__Sequence * rhs);

/// Copy an array of msg/FrameData messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_frame_data
bool
frame_data__msg__FrameData__Sequence__copy(
  const frame_data__msg__FrameData__Sequence * input,
  frame_data__msg__FrameData__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // FRAME_DATA__MSG__DETAIL__FRAME_DATA__FUNCTIONS_H_
