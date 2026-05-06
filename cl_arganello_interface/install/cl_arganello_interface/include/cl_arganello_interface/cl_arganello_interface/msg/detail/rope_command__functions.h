// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from cl_arganello_interface:msg/RopeCommand.idl
// generated code does not contain a copyright notice

#ifndef CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__FUNCTIONS_H_
#define CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "cl_arganello_interface/msg/rosidl_generator_c__visibility_control.h"

#include "cl_arganello_interface/msg/detail/rope_command__struct.h"

/// Initialize msg/RopeCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * cl_arganello_interface__msg__RopeCommand
 * )) before or use
 * cl_arganello_interface__msg__RopeCommand__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
bool
cl_arganello_interface__msg__RopeCommand__init(cl_arganello_interface__msg__RopeCommand * msg);

/// Finalize msg/RopeCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
void
cl_arganello_interface__msg__RopeCommand__fini(cl_arganello_interface__msg__RopeCommand * msg);

/// Create msg/RopeCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * cl_arganello_interface__msg__RopeCommand__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
cl_arganello_interface__msg__RopeCommand *
cl_arganello_interface__msg__RopeCommand__create();

/// Destroy msg/RopeCommand message.
/**
 * It calls
 * cl_arganello_interface__msg__RopeCommand__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
void
cl_arganello_interface__msg__RopeCommand__destroy(cl_arganello_interface__msg__RopeCommand * msg);

/// Check for msg/RopeCommand message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
bool
cl_arganello_interface__msg__RopeCommand__are_equal(const cl_arganello_interface__msg__RopeCommand * lhs, const cl_arganello_interface__msg__RopeCommand * rhs);

/// Copy a msg/RopeCommand message.
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
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
bool
cl_arganello_interface__msg__RopeCommand__copy(
  const cl_arganello_interface__msg__RopeCommand * input,
  cl_arganello_interface__msg__RopeCommand * output);

/// Initialize array of msg/RopeCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * cl_arganello_interface__msg__RopeCommand__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
bool
cl_arganello_interface__msg__RopeCommand__Sequence__init(cl_arganello_interface__msg__RopeCommand__Sequence * array, size_t size);

/// Finalize array of msg/RopeCommand messages.
/**
 * It calls
 * cl_arganello_interface__msg__RopeCommand__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
void
cl_arganello_interface__msg__RopeCommand__Sequence__fini(cl_arganello_interface__msg__RopeCommand__Sequence * array);

/// Create array of msg/RopeCommand messages.
/**
 * It allocates the memory for the array and calls
 * cl_arganello_interface__msg__RopeCommand__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
cl_arganello_interface__msg__RopeCommand__Sequence *
cl_arganello_interface__msg__RopeCommand__Sequence__create(size_t size);

/// Destroy array of msg/RopeCommand messages.
/**
 * It calls
 * cl_arganello_interface__msg__RopeCommand__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
void
cl_arganello_interface__msg__RopeCommand__Sequence__destroy(cl_arganello_interface__msg__RopeCommand__Sequence * array);

/// Check for msg/RopeCommand message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
bool
cl_arganello_interface__msg__RopeCommand__Sequence__are_equal(const cl_arganello_interface__msg__RopeCommand__Sequence * lhs, const cl_arganello_interface__msg__RopeCommand__Sequence * rhs);

/// Copy an array of msg/RopeCommand messages.
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
ROSIDL_GENERATOR_C_PUBLIC_cl_arganello_interface
bool
cl_arganello_interface__msg__RopeCommand__Sequence__copy(
  const cl_arganello_interface__msg__RopeCommand__Sequence * input,
  cl_arganello_interface__msg__RopeCommand__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // CL_ARGANELLO_INTERFACE__MSG__DETAIL__ROPE_COMMAND__FUNCTIONS_H_
