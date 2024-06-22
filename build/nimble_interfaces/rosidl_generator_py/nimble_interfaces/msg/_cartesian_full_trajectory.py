# generated from rosidl_generator_py/resource/_idl.py.em
# with input from nimble_interfaces:msg/CartesianFullTrajectory.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CartesianFullTrajectory(type):
    """Metaclass of message 'CartesianFullTrajectory'."""

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
                'nimble_interfaces.msg.CartesianFullTrajectory')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cartesian_full_trajectory
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cartesian_full_trajectory
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cartesian_full_trajectory
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cartesian_full_trajectory
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cartesian_full_trajectory

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

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


class CartesianFullTrajectory(metaclass=Metaclass_CartesianFullTrajectory):
    """Message class 'CartesianFullTrajectory'."""

    __slots__ = [
        '_header',
        '_left_pelvis',
        '_right_pelvis',
        '_base_pelvis',
        '_left_hip',
        '_right_hip',
        '_left_knee',
        '_right_knee',
        '_left_ankle',
        '_right_ankle',
        '_left_heel',
        '_right_heel',
        '_left_toe',
        '_right_toe',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'left_pelvis': 'sequence<geometry_msgs/Point>',
        'right_pelvis': 'sequence<geometry_msgs/Point>',
        'base_pelvis': 'sequence<geometry_msgs/Point>',
        'left_hip': 'sequence<geometry_msgs/Point>',
        'right_hip': 'sequence<geometry_msgs/Point>',
        'left_knee': 'sequence<geometry_msgs/Point>',
        'right_knee': 'sequence<geometry_msgs/Point>',
        'left_ankle': 'sequence<geometry_msgs/Point>',
        'right_ankle': 'sequence<geometry_msgs/Point>',
        'left_heel': 'sequence<geometry_msgs/Point>',
        'right_heel': 'sequence<geometry_msgs/Point>',
        'left_toe': 'sequence<geometry_msgs/Point>',
        'right_toe': 'sequence<geometry_msgs/Point>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.left_pelvis = kwargs.get('left_pelvis', [])
        self.right_pelvis = kwargs.get('right_pelvis', [])
        self.base_pelvis = kwargs.get('base_pelvis', [])
        self.left_hip = kwargs.get('left_hip', [])
        self.right_hip = kwargs.get('right_hip', [])
        self.left_knee = kwargs.get('left_knee', [])
        self.right_knee = kwargs.get('right_knee', [])
        self.left_ankle = kwargs.get('left_ankle', [])
        self.right_ankle = kwargs.get('right_ankle', [])
        self.left_heel = kwargs.get('left_heel', [])
        self.right_heel = kwargs.get('right_heel', [])
        self.left_toe = kwargs.get('left_toe', [])
        self.right_toe = kwargs.get('right_toe', [])

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
        if self.left_pelvis != other.left_pelvis:
            return False
        if self.right_pelvis != other.right_pelvis:
            return False
        if self.base_pelvis != other.base_pelvis:
            return False
        if self.left_hip != other.left_hip:
            return False
        if self.right_hip != other.right_hip:
            return False
        if self.left_knee != other.left_knee:
            return False
        if self.right_knee != other.right_knee:
            return False
        if self.left_ankle != other.left_ankle:
            return False
        if self.right_ankle != other.right_ankle:
            return False
        if self.left_heel != other.left_heel:
            return False
        if self.right_heel != other.right_heel:
            return False
        if self.left_toe != other.left_toe:
            return False
        if self.right_toe != other.right_toe:
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
    def left_pelvis(self):
        """Message field 'left_pelvis'."""
        return self._left_pelvis

    @left_pelvis.setter
    def left_pelvis(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'left_pelvis' field must be a set or sequence and each value of type 'Point'"
        self._left_pelvis = value

    @builtins.property
    def right_pelvis(self):
        """Message field 'right_pelvis'."""
        return self._right_pelvis

    @right_pelvis.setter
    def right_pelvis(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'right_pelvis' field must be a set or sequence and each value of type 'Point'"
        self._right_pelvis = value

    @builtins.property
    def base_pelvis(self):
        """Message field 'base_pelvis'."""
        return self._base_pelvis

    @base_pelvis.setter
    def base_pelvis(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'base_pelvis' field must be a set or sequence and each value of type 'Point'"
        self._base_pelvis = value

    @builtins.property
    def left_hip(self):
        """Message field 'left_hip'."""
        return self._left_hip

    @left_hip.setter
    def left_hip(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'left_hip' field must be a set or sequence and each value of type 'Point'"
        self._left_hip = value

    @builtins.property
    def right_hip(self):
        """Message field 'right_hip'."""
        return self._right_hip

    @right_hip.setter
    def right_hip(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'right_hip' field must be a set or sequence and each value of type 'Point'"
        self._right_hip = value

    @builtins.property
    def left_knee(self):
        """Message field 'left_knee'."""
        return self._left_knee

    @left_knee.setter
    def left_knee(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'left_knee' field must be a set or sequence and each value of type 'Point'"
        self._left_knee = value

    @builtins.property
    def right_knee(self):
        """Message field 'right_knee'."""
        return self._right_knee

    @right_knee.setter
    def right_knee(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'right_knee' field must be a set or sequence and each value of type 'Point'"
        self._right_knee = value

    @builtins.property
    def left_ankle(self):
        """Message field 'left_ankle'."""
        return self._left_ankle

    @left_ankle.setter
    def left_ankle(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'left_ankle' field must be a set or sequence and each value of type 'Point'"
        self._left_ankle = value

    @builtins.property
    def right_ankle(self):
        """Message field 'right_ankle'."""
        return self._right_ankle

    @right_ankle.setter
    def right_ankle(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'right_ankle' field must be a set or sequence and each value of type 'Point'"
        self._right_ankle = value

    @builtins.property
    def left_heel(self):
        """Message field 'left_heel'."""
        return self._left_heel

    @left_heel.setter
    def left_heel(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'left_heel' field must be a set or sequence and each value of type 'Point'"
        self._left_heel = value

    @builtins.property
    def right_heel(self):
        """Message field 'right_heel'."""
        return self._right_heel

    @right_heel.setter
    def right_heel(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'right_heel' field must be a set or sequence and each value of type 'Point'"
        self._right_heel = value

    @builtins.property
    def left_toe(self):
        """Message field 'left_toe'."""
        return self._left_toe

    @left_toe.setter
    def left_toe(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'left_toe' field must be a set or sequence and each value of type 'Point'"
        self._left_toe = value

    @builtins.property
    def right_toe(self):
        """Message field 'right_toe'."""
        return self._right_toe

    @right_toe.setter
    def right_toe(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Point) for v in value) and
                 True), \
                "The 'right_toe' field must be a set or sequence and each value of type 'Point'"
        self._right_toe = value
