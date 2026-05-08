from __future__ import print_function

import copy
import time
import numpy as np
import matplotlib.pyplot as plt

import rclpy
from rclpy.parameter import Parameter


class Utils:

    def __init__(self, node=None):
        self.node = node

        self.leg_map = {
            "LF": 0,
            "LH": 1,
            "RF": 2,
            "RH": 3,
        }

        self.crd = {
            "X": 0,
            "Y": 1,
            "Z": 2,
        }

        self.sp_crd = {
            "LX": 0,
            "LY": 1,
            "LZ": 2,
            "AX": 3,
            "AY": 4,
            "AZ": 5,
        }

    def getSegment(self, var, index, size):
        return var[index:index + size]

    def linPart(self, var):
        index = self.sp_crd["LX"]
        return var[index:index + 3]

    def angPart(self, var):
        index = self.sp_crd["AX"]
        return var[index:index + 3]

    # ------------------------------------------------------------------
    # ROS 2 parameter helpers
    # ------------------------------------------------------------------

    def putIntoGlobalParamServer(self, label, data, verbose=False):
        """
        ROS 2 does not have a global parameter server like ROS 1.

        This sets the parameter on the node passed to Utils(node=...).
        """
        if self.node is None:
            raise RuntimeError(
                "ROS 2 parameters belong to a node. "
                "Create Utils(node=self) from inside your rclpy Node."
            )

        if not self.node.has_parameter(label):
            self.node.declare_parameter(label, data)
        else:
            self.node.set_parameters([
                Parameter(label, value=data)
            ])

        if verbose:
            self.node.get_logger().info(
                f"Set parameter {label} on node {self.node.get_name()}"
            )

    def putIntoParamServer(self, data):
        """
        Compatibility wrapper for old ROS 1 code.
        """
        self.putIntoGlobalParamServer("hyq", data, verbose=True)

    # ------------------------------------------------------------------
    # Index utilities
    # ------------------------------------------------------------------

    def getIdx(self, leg, coord, numberOfJointsPerLeg=3):
        return self.leg_map[leg] * numberOfJointsPerLeg + self.crd[coord]

    def setLegJointState(self, legid, input, jointState, numberOfJointsPerLeg=3):
        if isinstance(legid, str):
            start = self.leg_map[legid] * numberOfJointsPerLeg
            jointState[start:start + numberOfJointsPerLeg] = input
        elif isinstance(legid, int):
            start = legid * numberOfJointsPerLeg
            jointState[start:start + numberOfJointsPerLeg] = input

    def getLegJointState(self, legid, jointState, numberOfJointsPerLeg=3):
        if isinstance(legid, str):
            start = self.leg_map[legid] * numberOfJointsPerLeg
            return jointState[start:start + numberOfJointsPerLeg]
        elif isinstance(legid, int):
            start = legid * numberOfJointsPerLeg
            return jointState[start:start + numberOfJointsPerLeg]

    def spy(self, var):
        plt.spy(var)
        plt.show()

    def detectLiftOff(self, swing, idx, leg):
        return swing[leg, idx - 1] == 0 and swing[leg, idx] == 1

    def detectTouchDown(self, swing, idx, leg):
        return swing[leg, idx] == 1 and swing[leg, idx + 1] == 0

    def detectHapticTouchDown(self, grForcesW, leg, force_th):
        grfleg = self.getLegJointState(leg, grForcesW)
        return grfleg[2] >= force_th

    # ------------------------------------------------------------------
    # ROS mapping helpers
    # ------------------------------------------------------------------

    def mapFromRos(self, ros_in):
        return ros_in

    def mapToRos(self, ros_in):
        return ros_in

    def mapIndexToRos(self, index_in):
        return index_in

    def mapLegListToRos(self, input_list):
        return input_list

    # ------------------------------------------------------------------
    # Generic helpers
    # ------------------------------------------------------------------

    @staticmethod
    def get_dict_keys(dictionary):
        names = list(dictionary.keys())
        names.sort()
        return names

    @staticmethod
    def tic():
        global startTime_for_tictoc
        startTime_for_tictoc = time.time()

    @staticmethod
    def toc():
        if "startTime_for_tictoc" in globals():
            print(
                "Elapsed time is "
                + str(time.time() - startTime_for_tictoc)
                + " seconds."
            )
        else:
            print("Toc: start time not set")

    def full_listOfArrays(self, length, rows, cols=0, value=np.nan):
        if cols == 0:
            a = np.full(rows, value)
        else:
            a = np.full((rows, cols), value)

        return self.listOfArrays(length, a)

    def listOfArrays(self, length, array):
        return [copy.deepcopy(array) for _ in range(length)]

    def isShuttingDown(self):
        return not rclpy.ok()