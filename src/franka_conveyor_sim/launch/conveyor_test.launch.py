"""Standalone test server. Do not run this to add models to Franka."""
import os
from pathlib import Path
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, OpaqueFunction, SetEnvironmentVariable
from launch.launch_description_sources import PythonLaunchDescriptionSource


def configure(context):
    share = Path(get_package_share_directory('franka_conveyor_sim'))
    ros_gz = Path(get_package_share_directory('ros_gz_sim'))
    value = lambda key: context.launch_configurations[key]
    return [
        SetEnvironmentVariable('GZ_SIM_RESOURCE_PATH', str(share/'models') + os.pathsep + os.environ.get('GZ_SIM_RESOURCE_PATH', '')),
        IncludeLaunchDescription(PythonLaunchDescriptionSource(str(ros_gz/'launch/gz_sim.launch.py')),
                                 launch_arguments={'gz_args': value('gz_args') + ' ' + str(share/'worlds/conveyor_test.sdf')}.items()),
        IncludeLaunchDescription(PythonLaunchDescriptionSource(str(share/'launch/add_conveyor.launch.py')),
                                 launch_arguments={'world': 'conveyor_test', 'bridge_clock': 'true',
                                                   'motion_mode': value('motion_mode'), 'hover_gap': value('hover_gap'),
                                                   'spawn_boxes': value('spawn_boxes'), 'belt_y': '0.0',
                                                   **{k:value(k) for k in ('belt_speed','force_velocity_gain','force_integral_gain','force_max_acceleration')}}.items())]


def generate_launch_description():
    return LaunchDescription([DeclareLaunchArgument('motion_mode', default_value='physical'),
                              DeclareLaunchArgument('belt_speed',default_value='0.1'),
                              DeclareLaunchArgument('force_velocity_gain',default_value='10.0'),
                              DeclareLaunchArgument('force_integral_gain',default_value='2.0'),
                              DeclareLaunchArgument('force_max_acceleration',default_value='1.0'),
                              DeclareLaunchArgument('hover_gap', default_value='0.002'),
                              DeclareLaunchArgument('gz_args', default_value='-r -v 4'),
                              DeclareLaunchArgument('spawn_boxes', default_value='true'),
                              OpaqueFunction(function=configure)])
