// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cl_arganello_interface:srv/RopeControlMode.idl
// generated code does not contain a copyright notice
#include "cl_arganello_interface/srv/detail/rope_control_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
cl_arganello_interface__srv__RopeControlMode_Request__init(cl_arganello_interface__srv__RopeControlMode_Request * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    cl_arganello_interface__srv__RopeControlMode_Request__fini(msg);
    return false;
  }
  return true;
}

void
cl_arganello_interface__srv__RopeControlMode_Request__fini(cl_arganello_interface__srv__RopeControlMode_Request * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
cl_arganello_interface__srv__RopeControlMode_Request__are_equal(const cl_arganello_interface__srv__RopeControlMode_Request * lhs, const cl_arganello_interface__srv__RopeControlMode_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
cl_arganello_interface__srv__RopeControlMode_Request__copy(
  const cl_arganello_interface__srv__RopeControlMode_Request * input,
  cl_arganello_interface__srv__RopeControlMode_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

cl_arganello_interface__srv__RopeControlMode_Request *
cl_arganello_interface__srv__RopeControlMode_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__srv__RopeControlMode_Request * msg = (cl_arganello_interface__srv__RopeControlMode_Request *)allocator.allocate(sizeof(cl_arganello_interface__srv__RopeControlMode_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cl_arganello_interface__srv__RopeControlMode_Request));
  bool success = cl_arganello_interface__srv__RopeControlMode_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cl_arganello_interface__srv__RopeControlMode_Request__destroy(cl_arganello_interface__srv__RopeControlMode_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cl_arganello_interface__srv__RopeControlMode_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cl_arganello_interface__srv__RopeControlMode_Request__Sequence__init(cl_arganello_interface__srv__RopeControlMode_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__srv__RopeControlMode_Request * data = NULL;

  if (size) {
    data = (cl_arganello_interface__srv__RopeControlMode_Request *)allocator.zero_allocate(size, sizeof(cl_arganello_interface__srv__RopeControlMode_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cl_arganello_interface__srv__RopeControlMode_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cl_arganello_interface__srv__RopeControlMode_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cl_arganello_interface__srv__RopeControlMode_Request__Sequence__fini(cl_arganello_interface__srv__RopeControlMode_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cl_arganello_interface__srv__RopeControlMode_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cl_arganello_interface__srv__RopeControlMode_Request__Sequence *
cl_arganello_interface__srv__RopeControlMode_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__srv__RopeControlMode_Request__Sequence * array = (cl_arganello_interface__srv__RopeControlMode_Request__Sequence *)allocator.allocate(sizeof(cl_arganello_interface__srv__RopeControlMode_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cl_arganello_interface__srv__RopeControlMode_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cl_arganello_interface__srv__RopeControlMode_Request__Sequence__destroy(cl_arganello_interface__srv__RopeControlMode_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cl_arganello_interface__srv__RopeControlMode_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cl_arganello_interface__srv__RopeControlMode_Request__Sequence__are_equal(const cl_arganello_interface__srv__RopeControlMode_Request__Sequence * lhs, const cl_arganello_interface__srv__RopeControlMode_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cl_arganello_interface__srv__RopeControlMode_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cl_arganello_interface__srv__RopeControlMode_Request__Sequence__copy(
  const cl_arganello_interface__srv__RopeControlMode_Request__Sequence * input,
  cl_arganello_interface__srv__RopeControlMode_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cl_arganello_interface__srv__RopeControlMode_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cl_arganello_interface__srv__RopeControlMode_Request * data =
      (cl_arganello_interface__srv__RopeControlMode_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cl_arganello_interface__srv__RopeControlMode_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cl_arganello_interface__srv__RopeControlMode_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cl_arganello_interface__srv__RopeControlMode_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
cl_arganello_interface__srv__RopeControlMode_Response__init(cl_arganello_interface__srv__RopeControlMode_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
cl_arganello_interface__srv__RopeControlMode_Response__fini(cl_arganello_interface__srv__RopeControlMode_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
cl_arganello_interface__srv__RopeControlMode_Response__are_equal(const cl_arganello_interface__srv__RopeControlMode_Response * lhs, const cl_arganello_interface__srv__RopeControlMode_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
cl_arganello_interface__srv__RopeControlMode_Response__copy(
  const cl_arganello_interface__srv__RopeControlMode_Response * input,
  cl_arganello_interface__srv__RopeControlMode_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

cl_arganello_interface__srv__RopeControlMode_Response *
cl_arganello_interface__srv__RopeControlMode_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__srv__RopeControlMode_Response * msg = (cl_arganello_interface__srv__RopeControlMode_Response *)allocator.allocate(sizeof(cl_arganello_interface__srv__RopeControlMode_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cl_arganello_interface__srv__RopeControlMode_Response));
  bool success = cl_arganello_interface__srv__RopeControlMode_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cl_arganello_interface__srv__RopeControlMode_Response__destroy(cl_arganello_interface__srv__RopeControlMode_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cl_arganello_interface__srv__RopeControlMode_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cl_arganello_interface__srv__RopeControlMode_Response__Sequence__init(cl_arganello_interface__srv__RopeControlMode_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__srv__RopeControlMode_Response * data = NULL;

  if (size) {
    data = (cl_arganello_interface__srv__RopeControlMode_Response *)allocator.zero_allocate(size, sizeof(cl_arganello_interface__srv__RopeControlMode_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cl_arganello_interface__srv__RopeControlMode_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cl_arganello_interface__srv__RopeControlMode_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cl_arganello_interface__srv__RopeControlMode_Response__Sequence__fini(cl_arganello_interface__srv__RopeControlMode_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cl_arganello_interface__srv__RopeControlMode_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cl_arganello_interface__srv__RopeControlMode_Response__Sequence *
cl_arganello_interface__srv__RopeControlMode_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__srv__RopeControlMode_Response__Sequence * array = (cl_arganello_interface__srv__RopeControlMode_Response__Sequence *)allocator.allocate(sizeof(cl_arganello_interface__srv__RopeControlMode_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cl_arganello_interface__srv__RopeControlMode_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cl_arganello_interface__srv__RopeControlMode_Response__Sequence__destroy(cl_arganello_interface__srv__RopeControlMode_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cl_arganello_interface__srv__RopeControlMode_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cl_arganello_interface__srv__RopeControlMode_Response__Sequence__are_equal(const cl_arganello_interface__srv__RopeControlMode_Response__Sequence * lhs, const cl_arganello_interface__srv__RopeControlMode_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cl_arganello_interface__srv__RopeControlMode_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cl_arganello_interface__srv__RopeControlMode_Response__Sequence__copy(
  const cl_arganello_interface__srv__RopeControlMode_Response__Sequence * input,
  cl_arganello_interface__srv__RopeControlMode_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cl_arganello_interface__srv__RopeControlMode_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cl_arganello_interface__srv__RopeControlMode_Response * data =
      (cl_arganello_interface__srv__RopeControlMode_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cl_arganello_interface__srv__RopeControlMode_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cl_arganello_interface__srv__RopeControlMode_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cl_arganello_interface__srv__RopeControlMode_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
