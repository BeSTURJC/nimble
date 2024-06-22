// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from nimble_interfaces:msg/TherapyRequirements.idl
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
#include "nimble_interfaces/msg/detail/therapy_requirements__struct.h"
#include "nimble_interfaces/msg/detail/therapy_requirements__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool nimble_interfaces__msg__therapy_requirements__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[64];
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
    assert(strncmp("nimble_interfaces.msg._therapy_requirements.TherapyRequirements", full_classname_dest, 63) == 0);
  }
  nimble_interfaces__msg__TherapyRequirements * ros_message = _ros_message;
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
  {  // speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // step_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "step_length");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->step_length = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // step_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "step_height");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->step_height = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // min_assist_level
    PyObject * field = PyObject_GetAttrString(_pymsg, "min_assist_level");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->min_assist_level = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // max_assist_level
    PyObject * field = PyObject_GetAttrString(_pymsg, "max_assist_level");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->max_assist_level = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * nimble_interfaces__msg__therapy_requirements__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of TherapyRequirements */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("nimble_interfaces.msg._therapy_requirements");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "TherapyRequirements");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  nimble_interfaces__msg__TherapyRequirements * ros_message = (nimble_interfaces__msg__TherapyRequirements *)raw_ros_message;
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
  {  // speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // step_length
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->step_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "step_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // step_height
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->step_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "step_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // min_assist_level
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->min_assist_level);
    {
      int rc = PyObject_SetAttrString(_pymessage, "min_assist_level", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // max_assist_level
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->max_assist_level);
    {
      int rc = PyObject_SetAttrString(_pymessage, "max_assist_level", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
