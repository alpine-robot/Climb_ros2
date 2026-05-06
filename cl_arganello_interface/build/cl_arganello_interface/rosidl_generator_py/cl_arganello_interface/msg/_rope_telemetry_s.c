// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cl_arganello_interface:msg/RopeTelemetry.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "cl_arganello_interface/msg/detail/rope_telemetry__struct.h"
#include "cl_arganello_interface/msg/detail/rope_telemetry__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cl_arganello_interface__msg__rope_telemetry__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[57];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("cl_arganello_interface.msg._rope_telemetry.RopeTelemetry", full_classname_dest, 56) == 0);
  }
  cl_arganello_interface__msg__RopeTelemetry * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // rope_force
    PyObject * field = PyObject_GetAttrString(_pymsg, "rope_force");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rope_force = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rope_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "rope_length");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rope_length = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // rope_velocity
    PyObject * field = PyObject_GetAttrString(_pymsg, "rope_velocity");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->rope_velocity = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // current
    PyObject * field = PyObject_GetAttrString(_pymsg, "current");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->current = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // brake_status
    PyObject * field = PyObject_GetAttrString(_pymsg, "brake_status");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->brake_status = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cl_arganello_interface__msg__rope_telemetry__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of RopeTelemetry */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cl_arganello_interface.msg._rope_telemetry");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "RopeTelemetry");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cl_arganello_interface__msg__RopeTelemetry * ros_message = (cl_arganello_interface__msg__RopeTelemetry *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rope_force
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rope_force);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rope_force", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rope_length
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rope_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rope_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // rope_velocity
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->rope_velocity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "rope_velocity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // current
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // brake_status
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->brake_status ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "brake_status", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
