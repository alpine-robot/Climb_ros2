# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cl_arganello_interface:msg/RopeTelemetry.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RopeTelemetry(type):
    """Metaclass of message 'RopeTelemetry'."""

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
            module = import_type_support('cl_arganello_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cl_arganello_interface.msg.RopeTelemetry')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__rope_telemetry
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__rope_telemetry
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__rope_telemetry
            cls._TYPE_SUPPORT = module.type_support_msg__msg__rope_telemetry
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__rope_telemetry

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


class RopeTelemetry(metaclass=Metaclass_RopeTelemetry):
    """Message class 'RopeTelemetry'."""

    __slots__ = [
        '_header',
        '_rope_force',
        '_rope_length',
        '_rope_velocity',
        '_current',
        '_brake_status',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'rope_force': 'float',
        'rope_length': 'float',
        'rope_velocity': 'float',
        'current': 'float',
        'brake_status': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.rope_force = kwargs.get('rope_force', float())
        self.rope_length = kwargs.get('rope_length', float())
        self.rope_velocity = kwargs.get('rope_velocity', float())
        self.current = kwargs.get('current', float())
        self.brake_status = kwargs.get('brake_status', bool())

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
        if self.rope_force != other.rope_force:
            return False
        if self.rope_length != other.rope_length:
            return False
        if self.rope_velocity != other.rope_velocity:
            return False
        if self.current != other.current:
            return False
        if self.brake_status != other.brake_status:
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
    def rope_force(self):
        """Message field 'rope_force'."""
        return self._rope_force

    @rope_force.setter
    def rope_force(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rope_force' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rope_force' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rope_force = value

    @builtins.property
    def rope_length(self):
        """Message field 'rope_length'."""
        return self._rope_length

    @rope_length.setter
    def rope_length(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rope_length' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rope_length' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rope_length = value

    @builtins.property
    def rope_velocity(self):
        """Message field 'rope_velocity'."""
        return self._rope_velocity

    @rope_velocity.setter
    def rope_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rope_velocity' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rope_velocity' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rope_velocity = value

    @builtins.property
    def current(self):
        """Message field 'current'."""
        return self._current

    @current.setter
    def current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'current' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'current' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._current = value

    @builtins.property
    def brake_status(self):
        """Message field 'brake_status'."""
        return self._brake_status

    @brake_status.setter
    def brake_status(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'brake_status' field must be of type 'bool'"
        self._brake_status = value
