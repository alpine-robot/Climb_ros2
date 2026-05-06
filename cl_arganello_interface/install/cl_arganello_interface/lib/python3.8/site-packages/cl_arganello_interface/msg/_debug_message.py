# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cl_arganello_interface:msg/DebugMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DebugMessage(type):
    """Metaclass of message 'DebugMessage'."""

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
                'cl_arganello_interface.msg.DebugMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__debug_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__debug_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__debug_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__debug_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__debug_message

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


class DebugMessage(metaclass=Metaclass_DebugMessage):
    """Message class 'DebugMessage'."""

    __slots__ = [
        '_header',
        '_brake',
        '_current',
        '_motor_torque',
        '_syncronous_roller_raw_wrapped',
        '_motor_position',
        '_motor_speed_rev_s',
        '_motor_speed_rad_s',
        '_sync_roller_speed_rev_s',
        '_sync_roller_speed_rad_s',
        '_rope_speed_m_s',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'brake': 'boolean',
        'current': 'float',
        'motor_torque': 'float',
        'syncronous_roller_raw_wrapped': 'int32',
        'motor_position': 'float',
        'motor_speed_rev_s': 'float',
        'motor_speed_rad_s': 'float',
        'sync_roller_speed_rev_s': 'float',
        'sync_roller_speed_rad_s': 'float',
        'rope_speed_m_s': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.brake = kwargs.get('brake', bool())
        self.current = kwargs.get('current', float())
        self.motor_torque = kwargs.get('motor_torque', float())
        self.syncronous_roller_raw_wrapped = kwargs.get('syncronous_roller_raw_wrapped', int())
        self.motor_position = kwargs.get('motor_position', float())
        self.motor_speed_rev_s = kwargs.get('motor_speed_rev_s', float())
        self.motor_speed_rad_s = kwargs.get('motor_speed_rad_s', float())
        self.sync_roller_speed_rev_s = kwargs.get('sync_roller_speed_rev_s', float())
        self.sync_roller_speed_rad_s = kwargs.get('sync_roller_speed_rad_s', float())
        self.rope_speed_m_s = kwargs.get('rope_speed_m_s', float())

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
        if self.brake != other.brake:
            return False
        if self.current != other.current:
            return False
        if self.motor_torque != other.motor_torque:
            return False
        if self.syncronous_roller_raw_wrapped != other.syncronous_roller_raw_wrapped:
            return False
        if self.motor_position != other.motor_position:
            return False
        if self.motor_speed_rev_s != other.motor_speed_rev_s:
            return False
        if self.motor_speed_rad_s != other.motor_speed_rad_s:
            return False
        if self.sync_roller_speed_rev_s != other.sync_roller_speed_rev_s:
            return False
        if self.sync_roller_speed_rad_s != other.sync_roller_speed_rad_s:
            return False
        if self.rope_speed_m_s != other.rope_speed_m_s:
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
    def brake(self):
        """Message field 'brake'."""
        return self._brake

    @brake.setter
    def brake(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'brake' field must be of type 'bool'"
        self._brake = value

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
    def motor_torque(self):
        """Message field 'motor_torque'."""
        return self._motor_torque

    @motor_torque.setter
    def motor_torque(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'motor_torque' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'motor_torque' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._motor_torque = value

    @builtins.property
    def syncronous_roller_raw_wrapped(self):
        """Message field 'syncronous_roller_raw_wrapped'."""
        return self._syncronous_roller_raw_wrapped

    @syncronous_roller_raw_wrapped.setter
    def syncronous_roller_raw_wrapped(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'syncronous_roller_raw_wrapped' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'syncronous_roller_raw_wrapped' field must be an integer in [-2147483648, 2147483647]"
        self._syncronous_roller_raw_wrapped = value

    @builtins.property
    def motor_position(self):
        """Message field 'motor_position'."""
        return self._motor_position

    @motor_position.setter
    def motor_position(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'motor_position' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'motor_position' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._motor_position = value

    @builtins.property
    def motor_speed_rev_s(self):
        """Message field 'motor_speed_rev_s'."""
        return self._motor_speed_rev_s

    @motor_speed_rev_s.setter
    def motor_speed_rev_s(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'motor_speed_rev_s' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'motor_speed_rev_s' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._motor_speed_rev_s = value

    @builtins.property
    def motor_speed_rad_s(self):
        """Message field 'motor_speed_rad_s'."""
        return self._motor_speed_rad_s

    @motor_speed_rad_s.setter
    def motor_speed_rad_s(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'motor_speed_rad_s' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'motor_speed_rad_s' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._motor_speed_rad_s = value

    @builtins.property
    def sync_roller_speed_rev_s(self):
        """Message field 'sync_roller_speed_rev_s'."""
        return self._sync_roller_speed_rev_s

    @sync_roller_speed_rev_s.setter
    def sync_roller_speed_rev_s(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'sync_roller_speed_rev_s' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'sync_roller_speed_rev_s' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._sync_roller_speed_rev_s = value

    @builtins.property
    def sync_roller_speed_rad_s(self):
        """Message field 'sync_roller_speed_rad_s'."""
        return self._sync_roller_speed_rad_s

    @sync_roller_speed_rad_s.setter
    def sync_roller_speed_rad_s(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'sync_roller_speed_rad_s' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'sync_roller_speed_rad_s' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._sync_roller_speed_rad_s = value

    @builtins.property
    def rope_speed_m_s(self):
        """Message field 'rope_speed_m_s'."""
        return self._rope_speed_m_s

    @rope_speed_m_s.setter
    def rope_speed_m_s(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'rope_speed_m_s' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'rope_speed_m_s' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._rope_speed_m_s = value
