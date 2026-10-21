"""Inject into an explicitly selected existing world; never start Gazebo here."""
import os
from pathlib import Path
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction, SetEnvironmentVariable, RegisterEventHandler, EmitEvent, LogInfo
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown
from launch_ros.actions import Node


def configure(context):
    value = lambda key: context.launch_configurations[key]
    if not value('world').strip():
        raise RuntimeError('world is required; inspect gz service -l')
    mode = value('motion_mode')
    if mode not in ('physical', 'slider', 'force'):
        raise RuntimeError('motion_mode must be physical, slider or force')
    belt_model = {'slider':'conveyor_stationary','force':'conveyor_force','physical':'conveyor'}[mode]
    share = Path(get_package_share_directory('franka_conveyor_sim'))
    args = ['-world', value('world'), '-file', str(share/'models'/belt_model/'model.sdf'),
            '-name', 'conveyor', '-allow_renaming', 'false']
    for option, key in [('-x', 'belt_x'), ('-y', 'belt_y'), ('-z', 'belt_z'), ('-Y', 'belt_yaw')]:
        args += [option, value(key)]
    spawn = Node(package='ros_gz_sim', executable='create', arguments=args, output='screen')
    params = {'use_sim_time': True, 'world': value('world'), 'motion_mode': mode}
    for key in ('belt_x', 'belt_y', 'belt_z', 'belt_yaw', 'interval', 'spawn_local_x', 'hover_gap', 'belt_speed',
                'force_velocity_gain', 'force_integral_gain', 'force_max_acceleration'):
        params[key] = float(value(key))
    spawner = Node(package='franka_conveyor_sim', executable='box_spawner',
                   parameters=[str(share/'config/conveyor.yaml'), params], output='screen')

    def after_spawn(event, _context):
        if event.returncode:
            return [LogInfo(msg='Conveyor creation failed; box spawner will not start'), EmitEvent(event=Shutdown(reason='Conveyor creation failed'))]
        return [spawner] if value('spawn_boxes').lower() == 'true' else []

    actions = [SetEnvironmentVariable('GZ_SIM_RESOURCE_PATH', str(share/'models') + os.pathsep + os.environ.get('GZ_SIM_RESOURCE_PATH', ''))]
    if value('bridge_clock').lower() == 'true':
        actions.append(Node(package='ros_gz_bridge', executable='parameter_bridge',
                            arguments=[f"/world/{value('world')}/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock"],
                            remappings=[(f"/world/{value('world')}/clock", '/clock')], output='screen'))
    return actions + [RegisterEventHandler(OnProcessExit(target_action=spawn, on_exit=after_spawn)), spawn]


def generate_launch_description():
    defaults = dict(world=None, motion_mode='physical', belt_speed='0.1',
                    force_velocity_gain='10.0',force_integral_gain='2.0',force_max_acceleration='1.0', hover_gap='0.002', belt_x='0.6', belt_y='0.5', belt_z='0.45', belt_yaw='0.0',
                    interval='3.0', spawn_local_x='-0.85', spawn_boxes='true', bridge_clock='false')
    return LaunchDescription([DeclareLaunchArgument(k, **({} if v is None else {'default_value': v}))
                              for k, v in defaults.items()] + [OpaqueFunction(function=configure)])
