// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from nimble_interfaces:srv/CartesianTrajService.idl
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
#include "nimble_interfaces/srv/detail/cartesian_traj_service__struct.h"
#include "nimble_interfaces/srv/detail/cartesian_traj_service__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool trajectory_msgs__msg__joint_trajectory__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * trajectory_msgs__msg__joint_trajectory__convert_to_py(void * raw_ros_message);
bool nimble_interfaces__msg__measurements__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * nimble_interfaces__msg__measurements__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool nimble_interfaces__srv__cartesian_traj_service__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[75];
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
    assert(strncmp("nimble_interfaces.srv._cartesian_traj_service.CartesianTrajService_Request", full_classname_dest, 74) == 0);
  }
  nimble_interfaces__srv__CartesianTrajService_Request * ros_message = _ros_message;
  {  // joints_trajectory
    PyObject * field = PyObject_GetAttrString(_pymsg, "joints_trajectory");
    if (!field) {
      return false;
    }
    if (!trajectory_msgs__msg__joint_trajectory__convert_from_py(field, &ros_message->joints_trajectory)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // measurements
    PyObject * field = PyObject_GetAttrString(_pymsg, "measurements");
    if (!field) {
      return false;
    }
    if (!nimble_interfaces__msg__measurements__convert_from_py(field, &ros_message->measurements)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * nimble_interfaces__srv__cartesian_traj_service__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CartesianTrajService_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("nimble_interfaces.srv._cartesian_traj_service");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CartesianTrajService_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  nimble_interfaces__srv__CartesianTrajService_Request * ros_message = (nimble_interfaces__srv__CartesianTrajService_Request *)raw_ros_message;
  {  // joints_trajectory
    PyObject * field = NULL;
    field = trajectory_msgs__msg__joint_trajectory__convert_to_py(&ros_message->joints_trajectory);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "joints_trajectory", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // measurements
    PyObject * field = NULL;
    field = nimble_interfaces__msg__measurements__convert_to_py(&ros_message->measurements);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "measurements", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "nimble_interfaces/srv/detail/cartesian_traj_service__struct.h"
// already included above
// #include "nimble_interfaces/srv/detail/cartesian_traj_service__functions.h"

bool nimble_interfaces__msg__cartesian_trajectory__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * nimble_interfaces__msg__cartesian_trajectory__convert_to_py(void * raw_ros_message);
bool nimble_interfaces__msg__therapy_requirements__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * nimble_interfaces__msg__therapy_requirements__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool nimble_interfaces__srv__cartesian_traj_service__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[76];
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
    assert(strncmp("nimble_interfaces.srv._cartesian_traj_service.CartesianTrajService_Response", full_classname_dest, 75) == 0);
  }
  nimble_interfaces__srv__CartesianTrajService_Response * ros_message = _ros_message;
  {  // cartesian_trajectory
    PyObject * field = PyObject_GetAttrString(_pymsg, "cartesian_trajectory");
    if (!field) {
      return false;
    }
    if (!nimble_interfaces__msg__cartesian_trajectory__convert_from_py(field, &ros_message->cartesian_trajectory)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // step_target
    PyObject * field = PyObject_GetAttrString(_pymsg, "step_target");
    if (!field) {
      return false;
    }
    if (!nimble_interfaces__msg__therapy_requirements__convert_from_py(field, &ros_message->step_target)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * nimble_interfaces__srv__cartesian_traj_service__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CartesianTrajService_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("nimble_interfaces.srv._cartesian_traj_service");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CartesianTrajService_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  nimble_interfaces__srv__CartesianTrajService_Response * ros_message = (nimble_interfaces__srv__CartesianTrajService_Response *)raw_ros_message;
  {  // cartesian_trajectory
    PyObject * field = NULL;
    field = nimble_interfaces__msg__cartesian_trajectory__convert_to_py(&ros_message->cartesian_trajectory);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "cartesian_trajectory", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // step_target
    PyObject * field = NULL;
    field = nimble_interfaces__msg__therapy_requirements__convert_to_py(&ros_message->step_target);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "step_target", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
