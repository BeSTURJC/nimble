# generated from rosidl_generator_py/resource/_idl.py.em
# with input from frame_data:msg/FrameData.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FrameData(type):
    """Metaclass of message 'FrameData'."""

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
            module = import_type_support('frame_data')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'frame_data.msg.FrameData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__frame_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__frame_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__frame_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__frame_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__frame_data

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FrameData(metaclass=Metaclass_FrameData):
    """Message class 'FrameData'."""

    __slots__ = [
        '_contador',
        '_frame_position',
        '_frame_speed',
        '_sensor_dist',
        '_position_ref',
        '_speed_ref',
    ]

    _fields_and_field_types = {
        'contador': 'uint32',
        'frame_position': 'float',
        'frame_speed': 'float',
        'sensor_dist': 'float',
        'position_ref': 'float',
        'speed_ref': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.contador = kwargs.get('contador', int())
        self.frame_position = kwargs.get('frame_position', float())
        self.frame_speed = kwargs.get('frame_speed', float())
        self.sensor_dist = kwargs.get('sensor_dist', float())
        self.position_ref = kwargs.get('position_ref', float())
        self.speed_ref = kwargs.get('speed_ref', float())

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
        if self.contador != other.contador:
            return False
        if self.frame_position != other.frame_position:
            return False
        if self.frame_speed != other.frame_speed:
            return False
        if self.sensor_dist != other.sensor_dist:
            return False
        if self.position_ref != other.position_ref:
            return False
        if self.speed_ref != other.speed_ref:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def contador(self):
        """Message field 'contador'."""
        return self._contador

    @contador.setter
    def contador(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'contador' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'contador' field must be an unsigned integer in [0, 4294967295]"
        self._contador = value

    @builtins.property
    def frame_position(self):
        """Message field 'frame_position'."""
        return self._frame_position

    @frame_position.setter
    def frame_position(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'frame_position' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'frame_position' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._frame_position = value

    @builtins.property
    def frame_speed(self):
        """Message field 'frame_speed'."""
        return self._frame_speed

    @frame_speed.setter
    def frame_speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'frame_speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'frame_speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._frame_speed = value

    @builtins.property
    def sensor_dist(self):
        """Message field 'sensor_dist'."""
        return self._sensor_dist

    @sensor_dist.setter
    def sensor_dist(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'sensor_dist' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'sensor_dist' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._sensor_dist = value

    @builtins.property
    def position_ref(self):
        """Message field 'position_ref'."""
        return self._position_ref

    @position_ref.setter
    def position_ref(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'position_ref' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'position_ref' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._position_ref = value

    @builtins.property
    def speed_ref(self):
        """Message field 'speed_ref'."""
        return self._speed_ref

    @speed_ref.setter
    def speed_ref(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed_ref' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'speed_ref' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._speed_ref = value
