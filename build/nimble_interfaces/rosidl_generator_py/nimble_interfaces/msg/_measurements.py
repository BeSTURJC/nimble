# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nimble_interfaces:msg/Measurements.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Measurements(type):
    """Metaclass of message 'Measurements'."""

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
                'nimble_interfaces.msg.Measurements')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__measurements
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__measurements
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__measurements
            cls._TYPE_SUPPORT = module.type_support_msg__msg__measurements
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__measurements

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


class Measurements(metaclass=Metaclass_Measurements):
    """Message class 'Measurements'."""

    __slots__ = [
        '_header',
        '_height',
        '_femur',
        '_tibia',
        '_height_ankle',
        '_distance_to_heel',
        '_distance_to_toe',
        '_depth_pelvis',
        '_width_pelvis',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'height': 'double',
        'femur': 'double',
        'tibia': 'double',
        'height_ankle': 'double',
        'distance_to_heel': 'double',
        'distance_to_toe': 'double',
        'depth_pelvis': 'double',
        'width_pelvis': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.height = kwargs.get('height', float())
        self.femur = kwargs.get('femur', float())
        self.tibia = kwargs.get('tibia', float())
        self.height_ankle = kwargs.get('height_ankle', float())
        self.distance_to_heel = kwargs.get('distance_to_heel', float())
        self.distance_to_toe = kwargs.get('distance_to_toe', float())
        self.depth_pelvis = kwargs.get('depth_pelvis', float())
        self.width_pelvis = kwargs.get('width_pelvis', float())

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
        if self.height != other.height:
            return False
        if self.femur != other.femur:
            return False
        if self.tibia != other.tibia:
            return False
        if self.height_ankle != other.height_ankle:
            return False
        if self.distance_to_heel != other.distance_to_heel:
            return False
        if self.distance_to_toe != other.distance_to_toe:
            return False
        if self.depth_pelvis != other.depth_pelvis:
            return False
        if self.width_pelvis != other.width_pelvis:
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
    def height(self):
        """Message field 'height'."""
        return self._height

    @height.setter
    def height(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'height' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'height' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._height = value

    @builtins.property
    def femur(self):
        """Message field 'femur'."""
        return self._femur

    @femur.setter
    def femur(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'femur' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'femur' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._femur = value

    @builtins.property
    def tibia(self):
        """Message field 'tibia'."""
        return self._tibia

    @tibia.setter
    def tibia(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'tibia' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'tibia' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._tibia = value

    @builtins.property
    def height_ankle(self):
        """Message field 'height_ankle'."""
        return self._height_ankle

    @height_ankle.setter
    def height_ankle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'height_ankle' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'height_ankle' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._height_ankle = value

    @builtins.property
    def distance_to_heel(self):
        """Message field 'distance_to_heel'."""
        return self._distance_to_heel

    @distance_to_heel.setter
    def distance_to_heel(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance_to_heel' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'distance_to_heel' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._distance_to_heel = value

    @builtins.property
    def distance_to_toe(self):
        """Message field 'distance_to_toe'."""
        return self._distance_to_toe

    @distance_to_toe.setter
    def distance_to_toe(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance_to_toe' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'distance_to_toe' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._distance_to_toe = value

    @builtins.property
    def depth_pelvis(self):
        """Message field 'depth_pelvis'."""
        return self._depth_pelvis

    @depth_pelvis.setter
    def depth_pelvis(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'depth_pelvis' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'depth_pelvis' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._depth_pelvis = value

    @builtins.property
    def width_pelvis(self):
        """Message field 'width_pelvis'."""
        return self._width_pelvis

    @width_pelvis.setter
    def width_pelvis(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'width_pelvis' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'width_pelvis' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._width_pelvis = value
