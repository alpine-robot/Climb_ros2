#!/usr/bin/env python3

import csv
import math
import time
from pathlib import Path

import matplotlib.pyplot as plt

import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from std_srvs.srv import Trigger

from cl_arganello_interface.msg import RopeCommand, RopeTelemetry


class PositionStepTest(Node):
    def __init__(self):
        super().__init__("position_step_test")

        self.declare_parameter("side", "left")
        self.declare_parameter("step_m", -0.02)          # parti piccolo: 2 cm
        self.declare_parameter("hold_0_s", 2.0)
        self.declare_parameter("hold_step_s", 6.0)
        self.declare_parameter("hold_back_s", 4.0)
        self.declare_parameter("rate_hz", 50.0)
        self.declare_parameter("do_rope_zero", True)
        self.declare_parameter("disengage_brake", True)
        self.declare_parameter("output_csv", "/tmp/position_step_test.csv")

        self.side = self.get_parameter("side").value
        self.step_m = float(self.get_parameter("step_m").value)
        self.hold_0_s = float(self.get_parameter("hold_0_s").value)
        self.hold_step_s = float(self.get_parameter("hold_step_s").value)
        self.hold_back_s = float(self.get_parameter("hold_back_s").value)
        self.rate_hz = float(self.get_parameter("rate_hz").value)
        self.do_rope_zero = bool(self.get_parameter("do_rope_zero").value)
        self.disengage_brake = bool(self.get_parameter("disengage_brake").value)
        self.output_csv = str(self.get_parameter("output_csv").value)

        base = f"/winch/{self.side}"

        self.pub_mode = self.create_publisher(String, f"{base}/set_motor_mode", 10)
        self.pub_cmd = self.create_publisher(RopeCommand, f"{base}/command", 10)

        self.sub_tel = self.create_subscription(
            RopeTelemetry,
            f"{base}/telemetry",
            self.telemetry_cb,
            10,
        )

        self.cli_rope_zero = self.create_client(Trigger, f"{base}/rope_zero")
        self.cli_brake_disengage = self.create_client(Trigger, f"{base}/brake_disengage")
        self.cli_brake_engage = self.create_client(Trigger, f"{base}/brake_engage")

        self.latest_tel = None
        self.samples = []

        self.get_logger().info(
            f"Position step test ready on {base}: step_m={self.step_m:.3f} m"
        )

    def telemetry_cb(self, msg: RopeTelemetry):
        self.latest_tel = msg

    def wait_for_telemetry(self, timeout_s=5.0):
        self.get_logger().info("Waiting for telemetry...")
        t0 = time.time()
        while rclpy.ok() and self.latest_tel is None:
            rclpy.spin_once(self, timeout_sec=0.05)
            if time.time() - t0 > timeout_s:
                raise RuntimeError("No RopeTelemetry received")
        self.get_logger().info("Telemetry received")

    def call_trigger(self, client, name, timeout_s=5.0):
        if not client.wait_for_service(timeout_sec=timeout_s):
            raise RuntimeError(f"Service not available: {name}")

        future = client.call_async(Trigger.Request())
        t0 = time.time()

        while rclpy.ok() and not future.done():
            rclpy.spin_once(self, timeout_sec=0.05)
            if time.time() - t0 > timeout_s:
                raise RuntimeError(f"Service timeout: {name}")

        resp = future.result()
        if resp is None or not resp.success:
            msg = "" if resp is None else resp.message
            raise RuntimeError(f"Service failed: {name} {msg}")

        self.get_logger().info(f"{name}: {resp.message}")

    def set_mode(self, mode: str):
        msg = String()
        msg.data = mode
        for _ in range(10):
            self.pub_mode.publish(msg)
            rclpy.spin_once(self, timeout_sec=0.02)
        self.get_logger().info(f"Mode sent: {mode}")

    def send_position(self, position_m: float):
        msg = RopeCommand()
        msg.header.stamp = self.get_clock().now().to_msg()

        # In position mode vogliamo che conti SOLO rope_position.
        # NaN evita di mandare per sbaglio anche force/velocity.
        msg.rope_force = float("nan")
        msg.rope_velocity = float("nan")
        msg.rope_position = float(position_m)

        self.pub_cmd.publish(msg)

    def run_phase(self, ref_m: float, duration_s: float, t_start: float):
        period = 1.0 / max(self.rate_hz, 1.0)
        t_end = time.time() + duration_s

        while rclpy.ok() and time.time() < t_end:
            now = time.time()
            self.send_position(ref_m)
            rclpy.spin_once(self, timeout_sec=0.001)

            if self.latest_tel is not None:
                t = now - t_start
                actual = float(self.latest_tel.rope_length)
                velocity = float(self.latest_tel.rope_velocity)
                current = float(self.latest_tel.current)
                brake = bool(self.latest_tel.brake_status)
                error = ref_m - actual

                self.samples.append({
                    "time_s": t,
                    "reference_m": ref_m,
                    "actual_m": actual,
                    "error_m": error,
                    "velocity_m_s": velocity,
                    "current_A": current,
                    "brake_status": int(brake),
                })

            sleep_time = period - (time.time() - now)
            if sleep_time > 0.0:
                time.sleep(sleep_time)

    def save_csv(self):
        path = Path(self.output_csv)
        path.parent.mkdir(parents=True, exist_ok=True)

        with path.open("w", newline="") as f:
            writer = csv.DictWriter(
                f,
                fieldnames=[
                    "time_s",
                    "reference_m",
                    "actual_m",
                    "error_m",
                    "velocity_m_s",
                    "current_A",
                    "brake_status",
                ],
            )
            writer.writeheader()
            writer.writerows(self.samples)

        self.get_logger().info(f"Saved CSV: {path}")

    def plot(self):
        if not self.samples:
            self.get_logger().warn("No samples to plot")
            return

        t = [s["time_s"] for s in self.samples]
        ref = [s["reference_m"] for s in self.samples]
        act = [s["actual_m"] for s in self.samples]
        err = [s["error_m"] for s in self.samples]

        plt.figure()
        plt.plot(t, ref, label="reference rope_position [m]", linewidth=2)
        plt.plot(t, act, label="actual rope_length [m]", linewidth=2)
        plt.xlabel("time [s]")
        plt.ylabel("rope length [m]")
        plt.title(f"Winch {self.side} position control step")
        plt.grid(True)
        plt.legend()
        plt.tight_layout()
        plt.show()

        plt.figure()
        plt.plot(t, err, label="tracking error [m]", linewidth=2)
        plt.xlabel("time [s]")
        plt.ylabel("error [m]")
        plt.title(f"Winch {self.side} position tracking error")
        plt.grid(True)
        plt.legend()
        plt.tight_layout()
        plt.show()

    def execute(self):
        self.wait_for_telemetry()

        if self.disengage_brake:
            self.call_trigger(self.cli_brake_disengage, f"/winch/{self.side}/brake_disengage")
            time.sleep(1.0)

        if self.do_rope_zero:
            self.call_trigger(self.cli_rope_zero, f"/winch/{self.side}/rope_zero")
            time.sleep(0.5)

        self.set_mode("closed_loop_position")
        time.sleep(0.5)

        t_start = time.time()

        self.get_logger().info("Phase 1: reference = 0.0 m")
        self.run_phase(0.0, self.hold_0_s, t_start)

        self.get_logger().info(f"Phase 2: step reference = {self.step_m:.3f} m")
        self.run_phase(self.step_m, self.hold_step_s, t_start)

        self.get_logger().info("Phase 3: back to reference = 0.0 m")
        self.run_phase(0.0, self.hold_back_s, t_start)

        self.send_position(0.0)
        time.sleep(0.2)

        self.save_csv()
        self.plot()

        self.get_logger().info("Position step test completed")


def main(args=None):
    rclpy.init(args=args)
    node = PositionStepTest()

    try:
        node.execute()
    except Exception as e:
        node.get_logger().error(str(e))
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()