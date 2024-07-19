# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nimble_interfaces:srv/CartesianTrajService.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CartesianTrajService_Request(type):
    """Metaclass of message 'CartesianTrajService_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('nimble_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'nimble_interfaces.srv.CartesianTrajService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cartesian_traj_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cartesian_traj_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cartesian_traj_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cartesian_traj_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cartesian_traj_service__request

            from nimble_interfaces.msg import Measurements
            if Measurements.__class__._TYPE_SUPPORT is None:
                Measurements.__class__.__import_type_support__()

            from trajectory_msgs.msg import JointTrajectory
            if JointTrajectory.__class__._TYPE_SUPPORT is None:
                JointTrajectory.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CartesianTrajService_Request(metaclass=Metaclass_CartesianTrajService_Request):
    """Message class 'CartesianTrajService_Request'."""

    __slots__ = [
        '_joints_trajectory',
        '_measurements',
    ]

    _fields_and_field_types = {
        'joints_trajectory': 'trajectory_msgs/JointTrajectory',
        'measurements': 'nimble_interfaces/Measurements',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['trajectory_msgs', 'msg'], 'JointTrajectory'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['nimble_interfaces', 'msg'], 'Measurements'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from trajectory_msgs.msg import JointTrajectory
        self.joints_trajectory = kwargs.get('joints_trajectory', JointTrajectory())
        from nimble_interfaces.msg import Measurements
        self.measurements = kwargs.get('measurements', Measurements())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.joints_trajectory != other.joints_trajectory:
            return False
        if self.measurements != other.measurements:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def joints_trajectory(self):
        """Message field 'joints_trajectory'."""
        return self._joints_trajectory

    @joints_trajectory.setter
    def joints_trajectory(self, value):
        if __debug__:
            from trajectory_msgs.msg import JointTrajectory
            assert \
                isinstance(value, JointTrajectory), \
                "The 'joints_trajectory' field must be a sub message of type 'JointTrajectory'"
        self._joints_trajectory = value

    @builtins.property
    def measurements(self):
        """Message field 'measurements'."""
        return self._measurements

    @measurements.setter
    def measurements(self, value):
        if __debug__:
            from nimble_interfaces.msg import Measurements
            assert \
                isinstance(value, Measurements), \
                "The 'measurements' field must be a sub message of type 'Measurements'"
        self._measurements = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_CartesianTrajService_Response(type):
    """Metaclass of message 'CartesianTrajService_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('nimble_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'nimble_interfaces.srv.CartesianTrajService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cartesian_traj_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cartesian_traj_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cartesian_traj_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cartesian_traj_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cartesian_traj_service__response

            from nimble_interfaces.msg import CartesianTrajectory
            if CartesianTrajectory.__class__._TYPE_SUPPORT is None:
                CartesianTrajectory.__class__.__import_type_support__()

            from nimble_interfaces.msg import TherapyRequirements
            if TherapyRequirements.__class__._TYPE_SUPPORT is None:
                TherapyRequirements.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CartesianTrajService_Response(metaclass=Metaclass_CartesianTrajService_Response):
    """Message class 'CartesianTrajService_Response'."""

    __slots__ = [
        '_cartesian_trajectory',
        '_step_target',
    ]

    _fields_and_field_types = {
        'cartesian_trajectory': 'nimble_interfaces/CartesianTrajectory',
        'step_target': 'nimble_interfaces/TherapyRequirements',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['nimble_interfaces', 'msg'], 'CartesianTrajectory'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['nimble_interfaces', 'msg'], 'TherapyRequirements'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from nimble_interfaces.msg import CartesianTrajectory
        self.cartesian_trajectory = kwargs.get('cartesian_trajectory', CartesianTrajectory())
        from nimble_interfaces.msg import TherapyRequirements
        self.step_target = kwargs.get('step_target', TherapyRequirements())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.cartesian_trajectory != other.cartesian_trajectory:
            return False
        if self.step_target != other.step_target:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cartesian_trajectory(self):
        """Message field 'cartesian_trajectory'."""
        return self._cartesian_trajectory

    @cartesian_trajectory.setter
    def cartesian_trajectory(self, value):
        if __debug__:
            from nimble_interfaces.msg import CartesianTrajectory
            assert \
                isinstance(value, CartesianTrajectory), \
                "The 'cartesian_trajectory' field must be a sub message of type 'CartesianTrajectory'"
        self._cartesian_trajectory = value

    @builtins.property
    def step_target(self):
        """Message field 'step_target'."""
        return self._step_target

    @step_target.setter
    def step_target(self, value):
        if __debug__:
            from nimble_interfaces.msg import TherapyRequirements
            assert \
                isinstance(value, TherapyRequirements), \
                "The 'step_target' field must be a sub message of type 'TherapyRequirements'"
        self._step_target = value


class Metaclass_CartesianTrajService(type):
    """Metaclass of service 'CartesianTrajService'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('nimble_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'nimble_interfaces.srv.CartesianTrajService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__cartesian_traj_service

            from nimble_interfaces.srv import _cartesian_traj_service
            if _cartesian_traj_service.Metaclass_CartesianTrajService_Request._TYPE_SUPPORT is None:
                _cartesian_traj_service.Metaclass_CartesianTrajService_Request.__import_type_support__()
            if _cartesian_traj_service.Metaclass_CartesianTrajService_Response._TYPE_SUPPORT is None:
                _cartesian_traj_service.Metaclass_CartesianTrajService_Response.__import_type_support__()


class CartesianTrajService(metaclass=Metaclass_CartesianTrajService):
    from nimble_interfaces.srv._cartesian_traj_service import CartesianTrajService_Request as Request
    from nimble_interfaces.srv._cartesian_traj_service import CartesianTrajService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
