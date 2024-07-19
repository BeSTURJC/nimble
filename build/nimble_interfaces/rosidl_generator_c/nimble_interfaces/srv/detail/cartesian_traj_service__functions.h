// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from nimble_interfaces:srv/CartesianTrajService.idl
// generated code does not contain a copyright notice

#ifndef NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__FUNCTIONS_H_
#define NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "nimble_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "nimble_interfaces/srv/detail/cartesian_traj_service__struct.h"

/// Initialize srv/CartesianTrajService message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nimble_interfaces__srv__CartesianTrajService_Request
 * )) before or use
 * nimble_interfaces__srv__CartesianTrajService_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__srv__CartesianTrajService_Request__init(nimble_interfaces__srv__CartesianTrajService_Request * msg);

/// Finalize srv/CartesianTrajService message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__srv__CartesianTrajService_Request__fini(nimble_interfaces__srv__CartesianTrajService_Request * msg);

/// Create srv/CartesianTrajService message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nimble_interfaces__srv__CartesianTrajService_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
nimble_interfaces__srv__CartesianTrajService_Request *
nimble_interfaces__srv__CartesianTrajService_Request__create();

/// Destroy srv/CartesianTrajService message.
/**
 * It calls
 * nimble_interfaces__srv__CartesianTrajService_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__srv__CartesianTrajService_Request__destroy(nimble_interfaces__srv__CartesianTrajService_Request * msg);

/// Check for srv/CartesianTrajService message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__srv__CartesianTrajService_Request__are_equal(const nimble_interfaces__srv__CartesianTrajService_Request * lhs, const nimble_interfaces__srv__CartesianTrajService_Request * rhs);

/// Copy a srv/CartesianTrajService message.
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
nimble_interfaces__srv__CartesianTrajService_Request__copy(
  const nimble_interfaces__srv__CartesianTrajService_Request * input,
  nimble_interfaces__srv__CartesianTrajService_Request * output);

/// Initialize array of srv/CartesianTrajService messages.
/**
 * It allocates the memory for the number of elements and calls
 * nimble_interfaces__srv__CartesianTrajService_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__init(nimble_interfaces__srv__CartesianTrajService_Request__Sequence * array, size_t size);

/// Finalize array of srv/CartesianTrajService messages.
/**
 * It calls
 * nimble_interfaces__srv__CartesianTrajService_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__fini(nimble_interfaces__srv__CartesianTrajService_Request__Sequence * array);

/// Create array of srv/CartesianTrajService messages.
/**
 * It allocates the memory for the array and calls
 * nimble_interfaces__srv__CartesianTrajService_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
nimble_interfaces__srv__CartesianTrajService_Request__Sequence *
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__create(size_t size);

/// Destroy array of srv/CartesianTrajService messages.
/**
 * It calls
 * nimble_interfaces__srv__CartesianTrajService_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__destroy(nimble_interfaces__srv__CartesianTrajService_Request__Sequence * array);

/// Check for srv/CartesianTrajService message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__are_equal(const nimble_interfaces__srv__CartesianTrajService_Request__Sequence * lhs, const nimble_interfaces__srv__CartesianTrajService_Request__Sequence * rhs);

/// Copy an array of srv/CartesianTrajService messages.
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
nimble_interfaces__srv__CartesianTrajService_Request__Sequence__copy(
  const nimble_interfaces__srv__CartesianTrajService_Request__Sequence * input,
  nimble_interfaces__srv__CartesianTrajService_Request__Sequence * output);

/// Initialize srv/CartesianTrajService message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * nimble_interfaces__srv__CartesianTrajService_Response
 * )) before or use
 * nimble_interfaces__srv__CartesianTrajService_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__srv__CartesianTrajService_Response__init(nimble_interfaces__srv__CartesianTrajService_Response * msg);

/// Finalize srv/CartesianTrajService message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__srv__CartesianTrajService_Response__fini(nimble_interfaces__srv__CartesianTrajService_Response * msg);

/// Create srv/CartesianTrajService message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * nimble_interfaces__srv__CartesianTrajService_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
nimble_interfaces__srv__CartesianTrajService_Response *
nimble_interfaces__srv__CartesianTrajService_Response__create();

/// Destroy srv/CartesianTrajService message.
/**
 * It calls
 * nimble_interfaces__srv__CartesianTrajService_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__srv__CartesianTrajService_Response__destroy(nimble_interfaces__srv__CartesianTrajService_Response * msg);

/// Check for srv/CartesianTrajService message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__srv__CartesianTrajService_Response__are_equal(const nimble_interfaces__srv__CartesianTrajService_Response * lhs, const nimble_interfaces__srv__CartesianTrajService_Response * rhs);

/// Copy a srv/CartesianTrajService message.
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
nimble_interfaces__srv__CartesianTrajService_Response__copy(
  const nimble_interfaces__srv__CartesianTrajService_Response * input,
  nimble_interfaces__srv__CartesianTrajService_Response * output);

/// Initialize array of srv/CartesianTrajService messages.
/**
 * It allocates the memory for the number of elements and calls
 * nimble_interfaces__srv__CartesianTrajService_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__init(nimble_interfaces__srv__CartesianTrajService_Response__Sequence * array, size_t size);

/// Finalize array of srv/CartesianTrajService messages.
/**
 * It calls
 * nimble_interfaces__srv__CartesianTrajService_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__fini(nimble_interfaces__srv__CartesianTrajService_Response__Sequence * array);

/// Create array of srv/CartesianTrajService messages.
/**
 * It allocates the memory for the array and calls
 * nimble_interfaces__srv__CartesianTrajService_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
nimble_interfaces__srv__CartesianTrajService_Response__Sequence *
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__create(size_t size);

/// Destroy array of srv/CartesianTrajService messages.
/**
 * It calls
 * nimble_interfaces__srv__CartesianTrajService_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
void
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__destroy(nimble_interfaces__srv__CartesianTrajService_Response__Sequence * array);

/// Check for srv/CartesianTrajService message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_nimble_interfaces
bool
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__are_equal(const nimble_interfaces__srv__CartesianTrajService_Response__Sequence * lhs, const nimble_interfaces__srv__CartesianTrajService_Response__Sequence * rhs);

/// Copy an array of srv/CartesianTrajService messages.
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
nimble_interfaces__srv__CartesianTrajService_Response__Sequence__copy(
  const nimble_interfaces__srv__CartesianTrajService_Response__Sequence * input,
  nimble_interfaces__srv__CartesianTrajService_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // NIMBLE_INTERFACES__SRV__DETAIL__CARTESIAN_TRAJ_SERVICE__FUNCTIONS_H_
