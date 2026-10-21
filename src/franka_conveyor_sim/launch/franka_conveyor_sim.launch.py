"""Start one unchanged Franka Gazebo stack and inject the conveyor into its world."""
from pathlib import Path

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
    share = Path(get_package_share_directory('franka_conveyor_sim'))
    franka = Path(get_package_share_directory('franka_gazebo_bringup'))
    defaults = {
        'world': 'empty',
        'gz_args': '-r --physics-engine gz-physics-bullet-featherstone-plugin empty.sdf',
        'rviz': 'true',
        'motion_mode': 'force',
        'belt_speed': '0.1',
        'force_velocity_gain': '10.0', 'force_integral_gain': '2.0', 'force_max_acceleration': '1.0',
        'hover_gap': '0.002',
        'belt_x': '0.6', 'belt_y': '0.5', 'belt_z': '0.45', 'belt_yaw': '0.0',
        'interval': '3.0', 'spawn_local_x': '-0.85', 'spawn_boxes': 'true',
    }
    arguments = [DeclareLaunchArgument(name, default_value=value)
                 for name, value in defaults.items()]
    # Same underlying launch and robot settings as franka_sim.launch.py. Keeping
    # gz_args exposed allows headless checks without modifying the working stack.
    robot = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(str(franka/'launch/gazebo_franka_arm_example_controller.launch.py')),
        launch_arguments={
            'load_gripper': 'true', 'controller': 'fr3_arm_controller',
            'gz_args': LaunchConfiguration('gz_args'), 'rviz': LaunchConfiguration('rviz'),
        }.items())
    # ros_gz_sim create waits for the world's creation service; no fixed delay is
    # needed. add_conveyor starts boxes only after belt creation succeeds.
    conveyor = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(str(share/'launch/add_conveyor.launch.py')),
        launch_arguments={
            **{name: LaunchConfiguration(name) for name in defaults if name not in ('gz_args', 'rviz')},
            'bridge_clock': 'false',
        }.items())
    return LaunchDescription(arguments + [robot, conveyor])
