// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cl_arganello_interface:msg/DebugMessage.idl
// generated code does not contain a copyright notice
#include "cl_arganello_interface/msg/detail/debug_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
cl_arganello_interface__msg__DebugMessage__init(cl_arganello_interface__msg__DebugMessage * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cl_arganello_interface__msg__DebugMessage__fini(msg);
    return false;
  }
  // brake
  // current
  // motor_torque
  // syncronous_roller_raw_wrapped
  // motor_position
  // motor_speed_rev_s
  // motor_speed_rad_s
  // sync_roller_speed_rev_s
  // sync_roller_speed_rad_s
  // rope_speed_m_s
  return true;
}

void
cl_arganello_interface__msg__DebugMessage__fini(cl_arganello_interface__msg__DebugMessage * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // brake
  // current
  // motor_torque
  // syncronous_roller_raw_wrapped
  // motor_position
  // motor_speed_rev_s
  // motor_speed_rad_s
  // sync_roller_speed_rev_s
  // sync_roller_speed_rad_s
  // rope_speed_m_s
}

bool
cl_arganello_interface__msg__DebugMessage__are_equal(const cl_arganello_interface__msg__DebugMessage * lhs, const cl_arganello_interface__msg__DebugMessage * rhs)
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
  // brake
  if (lhs->brake != rhs->brake) {
    return false;
  }
  // current
  if (lhs->current != rhs->current) {
    return false;
  }
  // motor_torque
  if (lhs->motor_torque != rhs->motor_torque) {
    return false;
  }
  // syncronous_roller_raw_wrapped
  if (lhs->syncronous_roller_raw_wrapped != rhs->syncronous_roller_raw_wrapped) {
    return false;
  }
  // motor_position
  if (lhs->motor_position != rhs->motor_position) {
    return false;
  }
  // motor_speed_rev_s
  if (lhs->motor_speed_rev_s != rhs->motor_speed_rev_s) {
    return false;
  }
  // motor_speed_rad_s
  if (lhs->motor_speed_rad_s != rhs->motor_speed_rad_s) {
    return false;
  }
  // sync_roller_speed_rev_s
  if (lhs->sync_roller_speed_rev_s != rhs->sync_roller_speed_rev_s) {
    return false;
  }
  // sync_roller_speed_rad_s
  if (lhs->sync_roller_speed_rad_s != rhs->sync_roller_speed_rad_s) {
    return false;
  }
  // rope_speed_m_s
  if (lhs->rope_speed_m_s != rhs->rope_speed_m_s) {
    return false;
  }
  return true;
}

bool
cl_arganello_interface__msg__DebugMessage__copy(
  const cl_arganello_interface__msg__DebugMessage * input,
  cl_arganello_interface__msg__DebugMessage * output)
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
  // brake
  output->brake = input->brake;
  // current
  output->current = input->current;
  // motor_torque
  output->motor_torque = input->motor_torque;
  // syncronous_roller_raw_wrapped
  output->syncronous_roller_raw_wrapped = input->syncronous_roller_raw_wrapped;
  // motor_position
  output->motor_position = input->motor_position;
  // motor_speed_rev_s
  output->motor_speed_rev_s = input->motor_speed_rev_s;
  // motor_speed_rad_s
  output->motor_speed_rad_s = input->motor_speed_rad_s;
  // sync_roller_speed_rev_s
  output->sync_roller_speed_rev_s = input->sync_roller_speed_rev_s;
  // sync_roller_speed_rad_s
  output->sync_roller_speed_rad_s = input->sync_roller_speed_rad_s;
  // rope_speed_m_s
  output->rope_speed_m_s = input->rope_speed_m_s;
  return true;
}

cl_arganello_interface__msg__DebugMessage *
cl_arganello_interface__msg__DebugMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__msg__DebugMessage * msg = (cl_arganello_interface__msg__DebugMessage *)allocator.allocate(sizeof(cl_arganello_interface__msg__DebugMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cl_arganello_interface__msg__DebugMessage));
  bool success = cl_arganello_interface__msg__DebugMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cl_arganello_interface__msg__DebugMessage__destroy(cl_arganello_interface__msg__DebugMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cl_arganello_interface__msg__DebugMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cl_arganello_interface__msg__DebugMessage__Sequence__init(cl_arganello_interface__msg__DebugMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__msg__DebugMessage * data = NULL;

  if (size) {
    data = (cl_arganello_interface__msg__DebugMessage *)allocator.zero_allocate(size, sizeof(cl_arganello_interface__msg__DebugMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cl_arganello_interface__msg__DebugMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cl_arganello_interface__msg__DebugMessage__fini(&data[i - 1]);
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
cl_arganello_interface__msg__DebugMessage__Sequence__fini(cl_arganello_interface__msg__DebugMessage__Sequence * array)
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
      cl_arganello_interface__msg__DebugMessage__fini(&array->data[i]);
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

cl_arganello_interface__msg__DebugMessage__Sequence *
cl_arganello_interface__msg__DebugMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cl_arganello_interface__msg__DebugMessage__Sequence * array = (cl_arganello_interface__msg__DebugMessage__Sequence *)allocator.allocate(sizeof(cl_arganello_interface__msg__DebugMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cl_arganello_interface__msg__DebugMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cl_arganello_interface__msg__DebugMessage__Sequence__destroy(cl_arganello_interface__msg__DebugMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cl_arganello_interface__msg__DebugMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cl_arganello_interface__msg__DebugMessage__Sequence__are_equal(const cl_arganello_interface__msg__DebugMessage__Sequence * lhs, const cl_arganello_interface__msg__DebugMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cl_arganello_interface__msg__DebugMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cl_arganello_interface__msg__DebugMessage__Sequence__copy(
  const cl_arganello_interface__msg__DebugMessage__Sequence * input,
  cl_arganello_interface__msg__DebugMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cl_arganello_interface__msg__DebugMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cl_arganello_interface__msg__DebugMessage * data =
      (cl_arganello_interface__msg__DebugMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cl_arganello_interface__msg__DebugMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cl_arganello_interface__msg__DebugMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cl_arganello_interface__msg__DebugMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
