// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cl_arganello_interface:msg/RopeTelemetry.idl
// generated code does not contain a copyright notice
#include "cl_arganello_interface/msg/detail/rope_telemetry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
cl_arganello_interface__msg__RopeTelemetry__init(cl_arganello_interface__msg__RopeTelemetry * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cl_arganello_interface__msg__RopeTelemetry__fini(msg);
    return false;
  }
  // rope_force
  // rope_length
  // rope_velocity
  // current
  // brake_status
  return true;
}

void
cl_arganello_interface__msg__RopeTelemetry__fini(cl_arganello_interface__msg__RopeTelemetry * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // rope_force
  // rope_length
  // rope_velocity
  // current
  // brake_status
}

bool
cl_arganello_interface__msg__RopeTelemetry__are_equal(const cl_arganello_interface__msg__RopeTelemetry * lhs, const cl_arganello_interface__msg__RopeTelemetry * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // rope_force
  if (lhs->rope_force != rhs->rope_force) {
    return false;
  }
  // rope_length
  if (lhs->rope_length != rhs->rope_length) {
    return false;
  }
  // rope_velocity
  if (lhs->rope_velocity != rhs->rope_velocity) {
    return false;
  }
  // current
  if (lhs->current != rhs->current) {
    return false;
  }
  // brake_status
  if (lhs->brake_status != rhs->brake_status) {
    return false;
  }
  return true;
}

bool
cl_arganello_interface__msg__RopeTelemetry__copy(
  const cl_arganello_interface__msg__RopeTelemetry * input,
  cl_arganello_interface__msg__RopeTelemetry * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // rope_force
  output->rope_force = input->rope_force;
  // rope_length
  output->rope_length = input->rope_length;
  // rope_velocity
  output->rope_velocity = input->rope_velocity;
  // current
  output->current = input->current;
  // brake_status
  output->brake_status = input->brake_status;
  return true;
}

cl_arganello_interface__msg__RopeTelemetry *
cl_arganello_interface__msg__RopeTelemetry__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__msg__RopeTelemetry * msg = (cl_arganello_interface__msg__RopeTelemetry *)allocator.allocate(sizeof(cl_arganello_interface__msg__RopeTelemetry), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cl_arganello_interface__msg__RopeTelemetry));
  bool success = cl_arganello_interface__msg__RopeTelemetry__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cl_arganello_interface__msg__RopeTelemetry__destroy(cl_arganello_interface__msg__RopeTelemetry * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cl_arganello_interface__msg__RopeTelemetry__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cl_arganello_interface__msg__RopeTelemetry__Sequence__init(cl_arganello_interface__msg__RopeTelemetry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__msg__RopeTelemetry * data = NULL;

  if (size) {
    data = (cl_arganello_interface__msg__RopeTelemetry *)allocator.zero_allocate(size, sizeof(cl_arganello_interface__msg__RopeTelemetry), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cl_arganello_interface__msg__RopeTelemetry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cl_arganello_interface__msg__RopeTelemetry__fini(&data[i - 1]);
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
cl_arganello_interface__msg__RopeTelemetry__Sequence__fini(cl_arganello_interface__msg__RopeTelemetry__Sequence * array)
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
      cl_arganello_interface__msg__RopeTelemetry__fini(&array->data[i]);
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

cl_arganello_interface__msg__RopeTelemetry__Sequence *
cl_arganello_interface__msg__RopeTelemetry__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__msg__RopeTelemetry__Sequence * array = (cl_arganello_interface__msg__RopeTelemetry__Sequence *)allocator.allocate(sizeof(cl_arganello_interface__msg__RopeTelemetry__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cl_arganello_interface__msg__RopeTelemetry__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cl_arganello_interface__msg__RopeTelemetry__Sequence__destroy(cl_arganello_interface__msg__RopeTelemetry__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cl_arganello_interface__msg__RopeTelemetry__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cl_arganello_interface__msg__RopeTelemetry__Sequence__are_equal(const cl_arganello_interface__msg__RopeTelemetry__Sequence * lhs, const cl_arganello_interface__msg__RopeTelemetry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cl_arganello_interface__msg__RopeTelemetry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cl_arganello_interface__msg__RopeTelemetry__Sequence__copy(
  const cl_arganello_interface__msg__RopeTelemetry__Sequence * input,
  cl_arganello_interface__msg__RopeTelemetry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cl_arganello_interface__msg__RopeTelemetry);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cl_arganello_interface__msg__RopeTelemetry * data =
      (cl_arganello_interface__msg__RopeTelemetry *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cl_arganello_interface__msg__RopeTelemetry__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cl_arganello_interface__msg__RopeTelemetry__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cl_arganello_interface__msg__RopeTelemetry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
