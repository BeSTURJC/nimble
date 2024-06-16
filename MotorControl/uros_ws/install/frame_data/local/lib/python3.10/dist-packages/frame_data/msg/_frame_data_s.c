// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from frame_data:msg/FrameData.idl
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
#include "frame_data/msg/detail/frame_data__struct.h"
#include "frame_data/msg/detail/frame_data__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool frame_data__msg__frame_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
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
    assert(strncmp("frame_data.msg._frame_data.FrameData", full_classname_dest, 36) == 0);
  }
  frame_data__msg__FrameData * ros_message = _ros_message;
  {  // contador
    PyObject * field = PyObject_GetAttrString(_pymsg, "contador");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->contador = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // frame_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "frame_position");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->frame_position = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // frame_speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "frame_speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->frame_speed = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // sensor_dist
    PyObject * field = PyObject_GetAttrString(_pymsg, "sensor_dist");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->sensor_dist = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // position_ref
    PyObject * field = PyObject_GetAttrString(_pymsg, "position_ref");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->position_ref = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // speed_ref
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed_ref");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed_ref = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * frame_data__msg__frame_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FrameData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("frame_data.msg._frame_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FrameData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  frame_data__msg__FrameData * ros_message = (frame_data__msg__FrameData *)raw_ros_message;
  {  // contador
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->contador);
    {
      int rc = PyObject_SetAttrString(_pymessage, "contador", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // frame_position
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->frame_position);
    {
      int rc = PyObject_SetAttrString(_pymessage, "frame_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // frame_speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->frame_speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "frame_speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // sensor_dist
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->sensor_dist);
    {
      int rc = PyObject_SetAttrString(_pymessage, "sensor_dist", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // position_ref
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->position_ref);
    {
      int rc = PyObject_SetAttrString(_pymessage, "position_ref", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed_ref
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed_ref);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed_ref", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
