# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cl_arganello_interface:msg/Imus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'imu1'
# Member 'imu2'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Imus(type):
    """Metaclass of message 'Imus'."""

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
                'cl_arganello_interface.msg.Imus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__imus
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__imus
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__imus
            cls._TYPE_SUPPORT = module.type_support_msg__msg__imus
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__imus

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Imus(metaclass=Metaclass_Imus):
    """Message class 'Imus'."""

    __slots__ = [
        '_epoch_ms',
        '_imu1',
        '_imu2',
    ]

    _fields_and_field_types = {
        'epoch_ms': 'uint32',
        'imu1': 'float[11]',
        'imu2': 'float[11]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 11),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 11),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.epoch_ms = kwargs.get('epoch_ms', int())
        if 'imu1' not in kwargs:
            self.imu1 = numpy.zeros(11, dtype=numpy.float32)
        else:
            self.imu1 = kwargs.get('imu1')
        if 'imu2' not in kwargs:
            self.imu2 = numpy.zeros(11, dtype=numpy.float32)
        else:
            self.imu2 = kwargs.get('imu2')

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
        if self.epoch_ms != other.epoch_ms:
            return False
        if any(self.imu1 != other.imu1):
            return False
        if any(self.imu2 != other.imu2):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def epoch_ms(self):
        """Message field 'epoch_ms'."""
        return self._epoch_ms

    @epoch_ms.setter
    def epoch_ms(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'epoch_ms' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'epoch_ms' field must be an unsigned integer in [0, 4294967295]"
        self._epoch_ms = value

    @builtins.property
    def imu1(self):
        """Message field 'imu1'."""
        return self._imu1

    @imu1.setter
    def imu1(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'imu1' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 11, \
                "The 'imu1' numpy.ndarray() must have a size of 11"
            self._imu1 = value
            return
        if __debug__:
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
                 len(value) == 11 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'imu1' field must be a set or sequence with length 11 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._imu1 = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def imu2(self):
        """Message field 'imu2'."""
        return self._imu2

    @imu2.setter
    def imu2(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'imu2' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 11, \
                "The 'imu2' numpy.ndarray() must have a size of 11"
            self._imu2 = value
            return
        if __debug__:
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
                 len(value) == 11 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'imu2' field must be a set or sequence with length 11 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._imu2 = numpy.array(value, dtype=numpy.float32)
