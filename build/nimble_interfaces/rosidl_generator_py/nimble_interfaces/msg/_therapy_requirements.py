# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nimble_interfaces:msg/TherapyRequirements.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TherapyRequirements(type):
    """Metaclass of message 'TherapyRequirements'."""

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
                'nimble_interfaces.msg.TherapyRequirements')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__therapy_requirements
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__therapy_requirements
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__therapy_requirements
            cls._TYPE_SUPPORT = module.type_support_msg__msg__therapy_requirements
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__therapy_requirements

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TherapyRequirements(metaclass=Metaclass_TherapyRequirements):
    """Message class 'TherapyRequirements'."""

    __slots__ = [
        '_header',
        '_speed',
        '_step_length',
        '_step_height',
        '_min_assist_level',
        '_max_assist_level',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'speed': 'double',
        'step_length': 'double',
        'step_height': 'double',
        'min_assist_level': 'int32',
        'max_assist_level': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.speed = kwargs.get('speed', float())
        self.step_length = kwargs.get('step_length', float())
        self.step_height = kwargs.get('step_height', float())
        self.min_assist_level = kwargs.get('min_assist_level', int())
        self.max_assist_level = kwargs.get('max_assist_level', int())

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
        if self.header != other.header:
            return False
        if self.speed != other.speed:
            return False
        if self.step_length != other.step_length:
            return False
        if self.step_height != other.step_height:
            return False
        if self.min_assist_level != other.min_assist_level:
            return False
        if self.max_assist_level != other.max_assist_level:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'speed' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._speed = value

    @builtins.property
    def step_length(self):
        """Message field 'step_length'."""
        return self._step_length

    @step_length.setter
    def step_length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'step_length' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'step_length' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._step_length = value

    @builtins.property
    def step_height(self):
        """Message field 'step_height'."""
        return self._step_height

    @step_height.setter
    def step_height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'step_height' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'step_height' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._step_height = value

    @builtins.property
    def min_assist_level(self):
        """Message field 'min_assist_level'."""
        return self._min_assist_level

    @min_assist_level.setter
    def min_assist_level(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'min_assist_level' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'min_assist_level' field must be an integer in [-2147483648, 2147483647]"
        self._min_assist_level = value

    @builtins.property
    def max_assist_level(self):
        """Message field 'max_assist_level'."""
        return self._max_assist_level

    @max_assist_level.setter
    def max_assist_level(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'max_assist_level' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'max_assist_level' field must be an integer in [-2147483648, 2147483647]"
        self._max_assist_level = value
