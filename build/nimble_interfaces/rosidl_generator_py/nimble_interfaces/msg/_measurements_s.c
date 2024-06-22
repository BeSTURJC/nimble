// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from nimble_interfaces:msg/Measurements.idl
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
#include "nimble_interfaces/msg/detail/measurements__struct.h"
#include "nimble_interfaces/msg/detail/measurements__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool nimble_interfaces__msg__measurements__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[49];
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
    assert(strncmp("nimble_interfaces.msg._measurements.Measurements", full_classname_dest, 48) == 0);
  }
  nimble_interfaces__msg__Measurements * ros_message = _ros_message;
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
  {  // height
    PyObject * field = PyObject_GetAttrString(_pymsg, "height");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->height = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // femur
    PyObject * field = PyObject_GetAttrString(_pymsg, "femur");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->femur = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tibia
    PyObject * field = PyObject_GetAttrString(_pymsg, "tibia");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tibia = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // height_ankle
    PyObject * field = PyObject_GetAttrString(_pymsg, "height_ankle");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->height_ankle = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // distance_to_heel
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance_to_heel");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance_to_heel = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // distance_to_toe
    PyObject * field = PyObject_GetAttrString(_pymsg, "distance_to_toe");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distance_to_toe = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // depth_pelvis
    PyObject * field = PyObject_GetAttrString(_pymsg, "depth_pelvis");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->depth_pelvis = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // width_pelvis
    PyObject * field = PyObject_GetAttrString(_pymsg, "width_pelvis");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->width_pelvis = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * nimble_interfaces__msg__measurements__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Measurements */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("nimble_interfaces.msg._measurements");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Measurements");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  nimble_interfaces__msg__Measurements * ros_message = (nimble_interfaces__msg__Measurements *)raw_ros_message;
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
  {  // height
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // femur
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->femur);
    {
      int rc = PyObject_SetAttrString(_pymessage, "femur", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tibia
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tibia);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tibia", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // height_ankle
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->height_ankle);
    {
      int rc = PyObject_SetAttrString(_pymessage, "height_ankle", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance_to_heel
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance_to_heel);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance_to_heel", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distance_to_toe
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distance_to_toe);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distance_to_toe", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // depth_pelvis
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->depth_pelvis);
    {
      int rc = PyObject_SetAttrString(_pymessage, "depth_pelvis", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // width_pelvis
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->width_pelvis);
    {
      int rc = PyObject_SetAttrString(_pymessage, "width_pelvis", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
