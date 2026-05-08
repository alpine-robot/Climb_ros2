#!/usr/bin/env python3

import time

import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from std_srvs.srv import Trigger
from cl_arganello_interface.msg import RopeCommand
from termcolor import  colored

class WinchStartupSequence(Node):
    def __init__(self):
        super().__init__("winch_startup_sequence")

        self.declare_parameter("step_delay", 1.0)
        self.step_delay = (
            self.get_parameter("step_delay")
            .get_parameter_value()
            .double_value
        )

        self.left_mode_pub = self.create_publisher(
            String,
            "/winch/left/set_motor_mode",
            1,
        )
        self.right_mode_pub = self.create_publisher(
            String,
            "/winch/right/set_motor_mode",
            1,
        )

        self.left_cmd_pub = self.create_publisher(
            RopeCommand,
            "/winch/left/command",
            1,
        )
        self.right_cmd_pub = self.create_publisher(
            RopeCommand,
            "/winch/right/command",
            1,
        )

        self.left_brake_client = self.create_client(
            Trigger,
            "/winch/left/brake_disengage",
        )
        self.right_brake_client = self.create_client(
            Trigger,
            "/winch/right/brake_disengage",
        )
        self.left_zero_client = self.create_client(
            Trigger,
            "/winch/left/rope_zero",
        )
        self.right_zero_client = self.create_client(
            Trigger,
            "/winch/right/rope_zero",
        )

        time.sleep(1.0)

    def sleep_step(self, delay=1.0):
        time.sleep(delay)

    def publish_mode(self, mode):
        self.get_logger().info(f"Setting motor mode: {mode}")

        msg = String()
        msg.data = mode

        self.left_mode_pub.publish(msg)
        self.right_mode_pub.publish(msg)

    def call_trigger(self, client, service_name):
        self.get_logger().info(f"Calling service: {service_name}")

        while not client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info(f"Waiting for service: {service_name}")
        request = Trigger.Request()
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        response = future.result()
        if response is None:
            self.get_logger().error(f"{service_name} call failed")
        elif not response.success:
            self.get_logger().warn(f"{service_name} returned false: {response.message}")


    def publish_command(
        self,
        side,
        rope_force,
        rope_velocity=0.0,
        rope_position=0.0,
    ):
        msg = RopeCommand()
        msg.rope_force = float(rope_force)
        msg.rope_velocity = float(rope_velocity)
        msg.rope_position = float(rope_position)

        if side == "left":
            self.left_cmd_pub.publish(msg)
        elif side == "right":
            self.right_cmd_pub.publish(msg)
        else:
            raise ValueError("side must be 'left' or 'right'")

        self.get_logger().info(
            f"Commanded {side} winch: "
            f"force={rope_force}, "
            f"velocity={rope_velocity}, "
            f"position={rope_position}"
        )

    def run_sequence(self):
        # 2) set position control
        print(colored("closed_loop_position", "red"))
        self.publish_mode("closed_loop_position")

        # 3) disengage brakes
        print(colored("remove brakes", "red"))
        self.call_trigger(
            self.left_brake_client,
            "/winch/left/brake_disengage",
        )
        self.call_trigger(
            self.right_brake_client,
            "/winch/right/brake_disengage",
        )
        self.sleep_step(delay=3.)

        # 4) set torque mode
        print(colored("closed_loop_torque", "red"))
        self.publish_mode("closed_loop_torque")

        # 5) pull left winch up
        print(colored(" left winch up", "red"))
        self.publish_command("left", rope_force=-25)
        self.publish_command("right", rope_force=-5)
        self.sleep_step(delay=10.)
        self.call_trigger( self.left_zero_client, "/winch/left/rope_zero")
        #TODO add to readings 0.7 for sx amd 0.63 for dc

        # 6) pull right winch up
        print(colored(" right winch up", "red"))
        self.publish_command("right", rope_force=-25)
        self.publish_command("left", rope_force=-5)
        self.sleep_step(delay=10.)
        self.call_trigger(self.right_zero_client,"/winch/right/rope_zero")

        # 7) set position mode
        self.publish_mode("closed_loop_position")

        # 8) set default position
        self.publish_command("right",rope_force=0, rope_velocity=0, rope_position=1.)
        self.publish_command("left",rope_force=0, rope_velocity=0,rope_position=1.)
        print(colored("DONE", "red"))
        self.get_logger().info("Winch startup sequence complete.")

def main(args=None):
    rclpy.init(args=args)

    node = WinchStartupSequence()

    try:
        node.run_sequence()

        # 👇 keep node alive until Ctrl+C
        node.get_logger().info("Node is idle. Press Ctrl+C to exit.")
        rclpy.spin(node)

    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
