// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from nimble_interfaces:msg/FrameState.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__FUNCTIONS_H_
#define NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "nimble_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "nimble_interfaces/msg/detail/frame_state__struct.h"

/// Initialize msg/FrameState message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nimble_interfaces__msg__FrameState
 * )) before or use
 * nimble_interfaces__msg__FrameState__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__msg__FrameState__init(nimble_interfaces__msg__FrameState * msg);

/// Finalize msg/FrameState message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__msg__FrameState__fini(nimble_interfaces__msg__FrameState * msg);

/// Create msg/FrameState message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nimble_interfaces__msg__FrameState__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
nimble_interfaces__msg__FrameState *
nimble_interfaces__msg__FrameState__create();

/// Destroy msg/FrameState message.
/**
 * It calls
 * nimble_interfaces__msg__FrameState__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__msg__FrameState__destroy(nimble_interfaces__msg__FrameState * msg);

/// Check for msg/FrameState message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__msg__FrameState__are_equal(const nimble_interfaces__msg__FrameState * lhs, const nimble_interfaces__msg__FrameState * rhs);

/// Copy a msg/FrameState message.
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
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__msg__FrameState__copy(
  const nimble_interfaces__msg__FrameState * input,
  nimble_interfaces__msg__FrameState * output);

/// Initialize array of msg/FrameState messages.
/**
 * It allocates the memory for the number of elements and calls
 * nimble_interfaces__msg__FrameState__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__msg__FrameState__Sequence__init(nimble_interfaces__msg__FrameState__Sequence * array, size_t size);

/// Finalize array of msg/FrameState messages.
/**
 * It calls
 * nimble_interfaces__msg__FrameState__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__msg__FrameState__Sequence__fini(nimble_interfaces__msg__FrameState__Sequence * array);

/// Create array of msg/FrameState messages.
/**
 * It allocates the memory for the array and calls
 * nimble_interfaces__msg__FrameState__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
nimble_interfaces__msg__FrameState__Sequence *
nimble_interfaces__msg__FrameState__Sequence__create(size_t size);

/// Destroy array of msg/FrameState messages.
/**
 * It calls
 * nimble_interfaces__msg__FrameState__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__msg__FrameState__Sequence__destroy(nimble_interfaces__msg__FrameState__Sequence * array);

/// Check for msg/FrameState message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__msg__FrameState__Sequence__are_equal(const nimble_interfaces__msg__FrameState__Sequence * lhs, const nimble_interfaces__msg__FrameState__Sequence * rhs);

/// Copy an array of msg/FrameState messages.
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
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__msg__FrameState__Sequence__copy(
  const nimble_interfaces__msg__FrameState__Sequence * input,
  nimble_interfaces__msg__FrameState__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // NIMBLE_INTERFACES__MSG__DETAIL__FRAME_STATE__FUNCTIONS_H_
