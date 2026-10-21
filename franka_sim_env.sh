# Source in each terminal used for local Gazebo sim:
#   source ~/franka_ros2_ws/franka_sim_env.sh
#
# Multicast discovery does not work over this laptop's Wi-Fi, so ROS 2 nodes and
# Gazebo can't find each other (ros_gz_sim/create hangs waiting for worlds or for
# /robot_description). This pins both to loopback for the current shell only.

export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
export CYCLONEDDS_URI=file://$HOME/cyclonedds.xml
export GZ_IP=127.0.0.1

source ~/franka_ros2_ws/install/setup.bash
ros2 daemon stop >/dev/null 2>&1
