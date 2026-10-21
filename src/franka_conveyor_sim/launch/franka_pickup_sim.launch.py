"""Single Franka world with a free pickup cube and overhead idealized D435."""
import math
from pathlib import Path
import xml.etree.ElementTree as ET

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, EmitEvent, GroupAction, IncludeLaunchDescription,
                            LogInfo, OpaqueFunction, RegisterEventHandler)
from launch.conditions import IfCondition
from launch.event_handlers import OnProcessExit
from launch.events import Shutdown
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node, SetRemap
from franka_conveyor_sim.force_model import configure_force_plugin


def configure(context):
    value = lambda name: context.launch_configurations[name]
    number = lambda name: float(value(name))
    share = Path(get_package_share_directory('franka_conveyor_sim'))
    franka = Path(get_package_share_directory('franka_gazebo_bringup'))
    extension, top = number('upstream_extension'), number('belt_top')
    if not math.isfinite(extension) or extension < 0 or not .2 <= top <= .6:
        raise ValueError('upstream_extension must be nonnegative; belt_top must be in [.2, .6] m')
    # Original belt endpoints [-.4,1.6]; move only the upstream endpoint.
    belt_x, belt_y = .6 - extension/2, number('belt_y')
    block_x, block_y = number('block_x'), number('block_y')
    if not (-.35-extension <= block_x <= 1.55 and abs(block_y-belt_y) <= .14):
        raise ValueError('block must lie inside the conveyor footprint')
    tilt = math.radians(number('camera_tilt_deg'))
    yaw = math.radians(number('camera_yaw_deg'))
    camera_z = number('camera_z')
    if not all(math.isfinite(v) for v in (tilt, yaw, camera_z)) or not 0 <= tilt <= math.radians(30) or camera_z <= top+.3:
        raise ValueError('camera tilt must be 0–30 degrees; camera must clear the surface')
    block_size = number('block_size')
    if not .02 <= block_size <= .10:
        raise ValueError('block_size must be .02–.10 m')
    mode = value('motion_mode')
    if mode not in ('stationary','force'):
        raise ValueError('Pickup-scene motion_mode must be stationary or force')
    block = ET.parse(share/'models'/('box_force' if mode == 'force' else 'box_pickup')/'model.sdf')
    if mode == 'force':
        configure_force_plugin(block.getroot(),belt_x=belt_x,belt_y=belt_y,belt_top=top,belt_yaw=0.,
            belt_length=2+extension,box_size=block_size,initial_speed=number('belt_speed'),
            velocity_gain=number('force_velocity_gain'),integral_gain=number('force_integral_gain'),
            max_acceleration=number('force_max_acceleration'))
    for size in block.findall('.//geometry/box/size'):
        size.text = f'{block_size} {block_size} {block_size}'
    for key in ('ixx', 'iyy', 'izz'):
        block.find(f'.//inertia/{key}').text = str(.20*block_size*block_size/6)
    # Aim at the settled cube top; default yaw points away from robot in +Y.
    distance = (camera_z-(top+block_size))*math.tan(tilt)
    camera_x = (block_x if value('camera_target_x') == 'block' else number('camera_target_x'))-distance*math.cos(yaw)
    camera_y = block_y-distance*math.sin(yaw)
    pitch = math.pi/2-tilt
    belt = ET.parse(share/'models'/('conveyor_force' if mode == 'force' else 'conveyor_pickup')/'model.sdf')
    for size in belt.findall('.//geometry/box/size'):
        size.text = f'{2+extension} 0.4 0.1'
    camera = ET.parse(share/'models/d435/model.sdf')
    sensor = camera.find('.//sensor')
    width, height = int(value('camera_width')), int(value('camera_height'))
    rate = number('camera_rate')
    if not (1 <= width <= 1920 and 1 <= height <= 1080 and 0 < rate <= 60):
        raise ValueError('invalid camera resolution or rate')
    sensor.find('update_rate').text = str(rate)
    sensor.find('camera/image/width').text = str(width)
    sensor.find('camera/image/height').text = str(height)

    goal_x, goal_y, goal_top = (number(k) for k in ('goal_table_x', 'goal_table_y', 'goal_table_top'))
    if not all(math.isfinite(v) for v in (goal_x, goal_y, goal_top)) or not .2 <= goal_top <= .6:
        raise ValueError('goal table pose must be finite; top must be in [.2, .6] m')
    # Reject table/conveyor footprint overlap; arm clearance still needs inspection.
    if goal_x+.25 > -.4-extension and goal_x-.25 < 1.6 and abs(goal_y-belt_y) < .32:
        raise ValueError('goal table footprint overlaps conveyor; change goal_table_x/y')
    table = ET.parse(share/'models/goal_table/model.sdf')
    for element in table.findall('.//link/*'):
        name = element.get('name', '').removesuffix('_collision')
        if name == 'tabletop' or name == 'yellow_goal':
            pose = element.find('pose').text.split()
            pose[2] = str(goal_top-.025 if name == 'tabletop' else goal_top+.0005)
            element.find('pose').text = ' '.join(pose)
        elif name.startswith('leg_'):
            pose = element.find('pose').text.split()
            pose[2] = str((goal_top-.05)/2)
            element.find('pose').text = ' '.join(pose)
            element.find('geometry/box/size').text = f'0.04 0.04 {goal_top-.05}'

    def create(name, *, sdf=None, file=None, xyz=(0, 0, 0), rpy=(0, 0, 0)):
        args = ['-world', 'franka_pickup', '-name', name, '-allow_renaming', 'false']
        args += ['-string', sdf] if sdf is not None else ['-file', str(file)]
        for key, val in zip(('-x', '-y', '-z', '-R', '-P', '-Y'), (*xyz, *rpy)):
            args += [key, str(val)]
        return Node(package='ros_gz_sim', executable='create', arguments=args, output='screen')

    belt_spawn = create('conveyor', sdf=ET.tostring(belt.getroot(), encoding='unicode'),
                        xyz=(belt_x, belt_y, top-.05))
    block_spawn = create('box_pickup', sdf=ET.tostring(block.getroot(), encoding='unicode'),
                         xyz=(block_x, block_y, top+block_size/2+.02))
    camera_spawn = create('d435', sdf=ET.tostring(camera.getroot(), encoding='unicode'),
                          xyz=(camera_x, camera_y, camera_z), rpy=(0, pitch, yaw))

    table_spawn = create('goal_table', sdf=ET.tostring(table.getroot(), encoding='unicode'),
                         xyz=(goal_x, goal_y, 0))
    goal_tf = Node(package='tf2_ros', executable='static_transform_publisher', name='pickup_goal_tf',
                   arguments=['--x', str(goal_x), '--y', str(goal_y), '--z', str(goal_top),
                              '--frame-id', 'world', '--child-frame-id', 'goal_destination'])

    def after_belt(event, _context):
        if event.returncode:
            return [EmitEvent(event=Shutdown(reason='Pickup conveyor creation failed'))]
        return [block_spawn]

    def check_spawn(event, _context):
        if event.returncode:
            return [EmitEvent(event=Shutdown(reason='Pickup model creation failed'))]
        return []

    robot = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(str(franka/'launch/gazebo_franka_arm_example_controller.launch.py')),
        launch_arguments={'load_gripper': 'true', 'controller': 'fr3_arm_controller', 'rviz': 'false',
                          'gz_args': value('gz_args') + ' --physics-engine gz-physics-bullet-featherstone-plugin "' +
                          str(share/'worlds/franka_pickup.sdf') + '"'}.items())
    # Keep the upstream launch unchanged. Redirect only its default bridge node
    # and provide one world-scoped CLOCK-QoS publisher for controller time.
    robot = GroupAction(scoped=False,actions=[SetRemap(src='ros_gz_bridge:/clock',dst='/pickup_legacy_clock'),robot])
    clock_bridge = Node(package='ros_gz_bridge',executable='parameter_bridge',name='pickup_clock_bridge',
        parameters=[{'config_file':str(share/'config/pickup_clock_bridge.yaml')}],output='screen')
    bridge = Node(package='ros_gz_bridge', executable='parameter_bridge', name='pickup_camera_bridge',
                  parameters=[{'config_file': str(share/'config/pickup_camera_bridge.yaml'),
                               'use_sim_time': True}], output='screen')
    camera_tf = Node(package='tf2_ros', executable='static_transform_publisher', name='pickup_camera_tf',
                     arguments=['--x', str(camera_x), '--y', str(camera_y), '--z', str(camera_z),
                                '--roll', '0', '--pitch', str(pitch), '--yaw', str(yaw),
                                '--frame-id', 'world', '--child-frame-id', 'camera_link'])
    optical_tf = Node(package='tf2_ros', executable='static_transform_publisher', name='pickup_optical_tf',
                      arguments=['--roll', str(-math.pi/2), '--pitch', '0', '--yaw', str(-math.pi/2),
                                 '--frame-id', 'camera_link', '--child-frame-id', 'camera_optical_frame'])
    rviz = Node(package='rviz2', executable='rviz2', name='pickup_rviz',
                arguments=['-d', str(share/'config/pickup.rviz')], parameters=[{'use_sim_time': True}],
                condition=IfCondition(value('rviz')))
    return [LogInfo(msg=f'Pickup scene motion={mode}, initial belt speed={value("belt_speed")} m/s; belt top={top}, X=[{-.4-extension},1.6]; free block=({block_x},{block_y}); '
                        f'camera=({camera_x:.3f},{camera_y:.3f},{camera_z}), tilt={value("camera_tilt_deg")} deg'),
            robot, clock_bridge, bridge, camera_tf, optical_tf, goal_tf, rviz,
            RegisterEventHandler(OnProcessExit(target_action=belt_spawn, on_exit=after_belt)),
            RegisterEventHandler(OnProcessExit(target_action=block_spawn, on_exit=check_spawn)),
            RegisterEventHandler(OnProcessExit(target_action=camera_spawn, on_exit=check_spawn)),
            RegisterEventHandler(OnProcessExit(target_action=table_spawn, on_exit=check_spawn)),
            belt_spawn, camera_spawn, table_spawn]


def generate_launch_description():
    defaults = dict(motion_mode='stationary',belt_speed='0.1',force_velocity_gain='10.0',
                    force_integral_gain='2.0',force_max_acceleration='1.0',gz_args='-r -v 3', rviz='true', upstream_extension='1.0', belt_top='0.45',
                    belt_y='0.5', block_size='0.06', block_x='0.15', block_y='0.5', camera_z='1.6',
                    camera_target_x='block', camera_tilt_deg='12.5', camera_yaw_deg='90', camera_width='848',
                    camera_height='480', camera_rate='15.0',
                    goal_table_x='-0.55', goal_table_y='0.15', goal_table_top='0.35')
    return LaunchDescription([DeclareLaunchArgument(k, default_value=v) for k, v in defaults.items()] +
                             [OpaqueFunction(function=configure)])
