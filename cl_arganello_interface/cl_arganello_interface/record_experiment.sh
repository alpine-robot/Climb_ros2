#!/usr/bin/env bash
set -e

STAMP=$(date +%Y%m%d_%H%M%S)
OUTDIR=${1:-experiment_${STAMP}}

echo "Recording rosbag to: ${OUTDIR}"

ros2 bag record -o "${OUTDIR}"   /winch/left/telemetry   /winch/right/telemetry   /winch/left/telemetry/debug   /winch/right/telemetry/debug   /alpine/dongle/telemetry   /alpine/dongle/telemetry/raw   /alpine/odometry   /alpine/odometry/debug
