// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cl_arganello_interface:msg/Imus.idl
// generated code does not contain a copyright notice
#include "cl_arganello_interface/msg/detail/imus__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
cl_arganello_interface__msg__Imus__init(cl_arganello_interface__msg__Imus * msg)
{
  if (!msg) {
    return false;
  }
  // epoch_ms
  // imu1
  // imu2
  return true;
}

void
cl_arganello_interface__msg__Imus__fini(cl_arganello_interface__msg__Imus * msg)
{
  if (!msg) {
    return;
  }
  // epoch_ms
  // imu1
  // imu2
}

bool
cl_arganello_interface__msg__Imus__are_equal(const cl_arganello_interface__msg__Imus * lhs, const cl_arganello_interface__msg__Imus * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // epoch_ms
  if (lhs->epoch_ms != rhs->epoch_ms) {
    return false;
  }
  // imu1
  for (size_t i = 0; i < 11; ++i) {
    if (lhs->imu1[i] != rhs->imu1[i]) {
      return false;
    }
  }
  // imu2
  for (size_t i = 0; i < 11; ++i) {
    if (lhs->imu2[i] != rhs->imu2[i]) {
      return false;
    }
  }
  return true;
}

bool
cl_arganello_interface__msg__Imus__copy(
  const cl_arganello_interface__msg__Imus * input,
  cl_arganello_interface__msg__Imus * output)
{
  if (!input || !output) {
    return false;
  }
  // epoch_ms
  output->epoch_ms = input->epoch_ms;
  // imu1
  for (size_t i = 0; i < 11; ++i) {
    output->imu1[i] = input->imu1[i];
  }
  // imu2
  for (size_t i = 0; i < 11; ++i) {
    output->imu2[i] = input->imu2[i];
  }
  return true;
}

cl_arganello_interface__msg__Imus *
cl_arganello_interface__msg__Imus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__msg__Imus * msg = (cl_arganello_interface__msg__Imus *)allocator.allocate(sizeof(cl_arganello_interface__msg__Imus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cl_arganello_interface__msg__Imus));
  bool success = cl_arganello_interface__msg__Imus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cl_arganello_interface__msg__Imus__destroy(cl_arganello_interface__msg__Imus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cl_arganello_interface__msg__Imus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cl_arganello_interface__msg__Imus__Sequence__init(cl_arganello_interface__msg__Imus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__msg__Imus * data = NULL;

  if (size) {
    data = (cl_arganello_interface__msg__Imus *)allocator.zero_allocate(size, sizeof(cl_arganello_interface__msg__Imus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cl_arganello_interface__msg__Imus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cl_arganello_interface__msg__Imus__fini(&data[i - 1]);
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
cl_arganello_interface__msg__Imus__Sequence__fini(cl_arganello_interface__msg__Imus__Sequence * array)
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
      cl_arganello_interface__msg__Imus__fini(&array->data[i]);
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

cl_arganello_interface__msg__Imus__Sequence *
cl_arganello_interface__msg__Imus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__msg__Imus__Sequence * array = (cl_arganello_interface__msg__Imus__Sequence *)allocator.allocate(sizeof(cl_arganello_interface__msg__Imus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cl_arganello_interface__msg__Imus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cl_arganello_interface__msg__Imus__Sequence__destroy(cl_arganello_interface__msg__Imus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cl_arganello_interface__msg__Imus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cl_arganello_interface__msg__Imus__Sequence__are_equal(const cl_arganello_interface__msg__Imus__Sequence * lhs, const cl_arganello_interface__msg__Imus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cl_arganello_interface__msg__Imus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cl_arganello_interface__msg__Imus__Sequence__copy(
  const cl_arganello_interface__msg__Imus__Sequence * input,
  cl_arganello_interface__msg__Imus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cl_arganello_interface__msg__Imus);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cl_arganello_interface__msg__Imus * data =
      (cl_arganello_interface__msg__Imus *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cl_arganello_interface__msg__Imus__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cl_arganello_interface__msg__Imus__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cl_arganello_interface__msg__Imus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
