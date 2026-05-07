from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os


def generate_launch_description():
    pkg_share = get_package_share_directory('cl_arganello_interface')

    # Path assoluto usato perché il file config non sempre viene installato nel package share.
    config_path = '/home/andrea/Climb_ros2/cl_arganello_interface/config/arganelloTelemetry.json'

    # Parametri comuni per entrambe le winch.
    # closed_loop_position viene realizzato come outer loop su rope_length + ODrive velocity mode.
    common_winch_params = {
        'config_path': config_path,
        'debug_mode': True,
        'rope_position_outer_loop_enabled': True,
        'rope_position_kp': 6.0,
        'rope_position_max_vel_m_s': 0.10,
        'rope_position_deadband_m': 0.0015,
        # Convenzione richiesta:
        # rope_position negativo => tira su / riavvolge, sia left sia right.
        'rope_direction_sign': 1.0,

        # Profilo di posizione: zona near SOLO negli ultimi millimetri.
        'rope_position_motor_vel_scale': 0.75,
        'rope_position_up_near_vel_m_s': 0.008,
        'rope_position_up_far_vel_m_s': 0.040,
        'rope_position_down_near_vel_m_s': 0.110,
        'rope_position_down_far_vel_m_s': 0.180,
        'rope_position_profile_zone_m': 0.004,
    }

    return LaunchDescription([
        # Left telemetry node
        Node(
            package='cl_arganello_interface',
            executable='telemetry_node.py',
            name='telemetry_node_left',
            parameters=[{
                **common_winch_params,
                'side': 'left',
                'serial_port': '/dev/serial/by-id/usb-1a86_USB_Single_Serial_5970047399-if00',
            }]
        ),

        # Right telemetry node
        Node(
            package='cl_arganello_interface',
            executable='telemetry_node.py',
            name='telemetry_node_right',
            parameters=[{
                **common_winch_params,
                'side': 'right',
                'serial_port': '/dev/serial/by-id/usb-1a86_USB_Single_Serial_5970046081-if00',
            }]
        ),

        # Dongle node
        Node(
            package='cl_arganello_interface',
            executable='dongle_node.py',
            name='dongle_node',
            parameters=[{
                'serial_port': '/dev/serial/by-id/usb-1a86_USB_Single_Serial_5A7A010904-if00',
                'baud': 1000000,
                'poll_rate': 100.0,
            }]
        ),

        # Jump node: SAFE, non manda comandi finché non viene chiamato /alpine/jump.
        Node(
            package='cl_arganello_interface',
            executable='jump.py',
            name='jump_node',
            parameters=[{
                'step_left_force': -18.0,
                'step_right_force': 18.0,
                'step_push_ms': 220.0,
                'step_flight_ms': 900.0,
                'hold_force': 10.0,
                'max_abs_rope_force': 25.0,
                'optimized_csv': '/home/andrea/Climb_ros2/optimized_jump.csv',
            }]
        ),
    ])