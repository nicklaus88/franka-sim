"""One force-driven Franka scene: collision-checked approach then velocity tracking."""
from pathlib import Path
import xml.etree.ElementTree as ET

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, OpaqueFunction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch_ros.actions import Node
import xacro
import yaml


def configure(context):
    value = lambda key: context.launch_configurations[key]
    share = Path(get_package_share_directory('franka_conveyor_sim'))
    franka = Path(get_package_share_directory('franka_gazebo_bringup'))
    description = Path(get_package_share_directory('franka_description'))
    config = Path(get_package_share_directory('franka_fr3_moveit_config'))
    defaults = Path(get_package_share_directory('moveit_configs_utils'))/'default_configs'
    # Exact robot xacro/mappings used by the simulation, including its collision
    # geometry. Do not start another hardware node, RSP, or controller manager.
    urdf = xacro.process_file(str(franka/'urdf/franka_arm.gazebo.xacro'),
                              mappings={'robot_type':'fr3','hand':'true','ee_id':'franka_hand','gazebo_effort':'true'}).toxml()
    srdf = ET.fromstring(xacro.process_file(str(description/'robots/fr3/fr3.srdf.xacro'),
                                         mappings={'hand':'true'}).toxml())
    links = {link.get('name') for link in ET.fromstring(urdf).findall('link')}
    # Existing semantic xacro names a nonexistent "base" virtual joint; the sim
    # already has a fixed world root. Remove only that invalid runtime element.
    for joint in list(srdf.findall('virtual_joint')):
        if joint.get('child_link') not in links:
            srdf.remove(joint)
    load = lambda path: yaml.safe_load(path.read_text())
    ompl = load(defaults/'ompl_planning.yaml')
    settings = load(config/'config/ompl_planning.yaml')
    if 'panda_arm' in settings:
        settings['fr3_arm'] = settings.pop('panda_arm')
    settings.pop('panda_arm_hand',None)
    settings['fr3_arm']['default_planner_config'] = 'RRTConnectkConfigDefault'
    settings['fr3_arm']['longest_valid_segment_fraction'] = .005
    ompl.update(settings)
    move_group = Node(package='moveit_ros_move_group',executable='move_group',name='move_group',output='screen',
        parameters=[{'use_sim_time':True,'robot_description':urdf,
                     'robot_description_semantic':ET.tostring(srdf,encoding='unicode'),
                     'robot_description_kinematics':load(config/'config/kinematics.yaml'),
                     'robot_description_planning':load(config/'config/fr3_joint_limits.yaml'),
                     'planning_pipelines':['ompl'],'default_planning_pipeline':'ompl','ompl':ompl,
                     'allow_trajectory_execution':False,'moveit_manage_controllers':False,
                     'moveit_controller_manager':'moveit_simple_controller_manager/MoveItSimpleControllerManager',
                     'moveit_simple_controller_manager':{
                       'controller_names':['fr3_arm_controller'],
                       'fr3_arm_controller':load(config/'config/fr3_controllers.yaml')['fr3_arm_controller']},
                     'publish_robot_description_semantic':True,
                     'publish_planning_scene':True,'publish_geometry_updates':True,
                     'publish_state_updates':True,'publish_transforms_updates':True}])
    geometry = {key:float(value(key)) for key in ('box_size','belt_top','belt_y','upstream_extension',
                 'goal_table_x','goal_table_y','goal_table_top')}
    # Keep the entire cube on the belt, 5 cm inward from its upstream edge.
    block_x = (str(-.4-geometry['upstream_extension']+geometry['box_size']/2+.05)
               if value('block_x') == 'upstream' else value('block_x'))
    simulation = IncludeLaunchDescription(PythonLaunchDescriptionSource(str(share/'launch/franka_pickup_sim.launch.py')),
        launch_arguments={**{key:value(key) for key in ('belt_top','belt_y','upstream_extension','goal_table_x',
                        'goal_table_y','goal_table_top','block_x','block_y','gz_args')},
                        'block_x':block_x, 'block_size':value('box_size'), 'rviz':'false', 'motion_mode':'force','belt_speed':'0.0'}.items(),condition=IfCondition(value('start_sim')))
    rviz = Node(package='rviz2',executable='rviz2',name='pickup_planning_rviz',
                arguments=['-d',str(share/'config/pickup_planning.rviz')],
                parameters=[{'use_sim_time':True,'robot_description':urdf,
                             'robot_description_semantic':ET.tostring(srdf,encoding='unicode')}],
                condition=IfCondition(value('rviz')))
    tracker = Node(package='franka_conveyor_sim',executable='conveyor_tracker',name='conveyor_tracker',output='screen',
        parameters=[geometry,{'use_sim_time':True,'auto_plan':False,'robot_description':urdf,
            'belt_speed':float(value('belt_speed')),'tracking_end_x':float(value('tracking_end_x')),
            **{key:float(value(key)) for key in ('tracking_start_x','tracking_min_x','workspace_step','entry_lead')},
            'result_path':value('result_path'),**{key:float(value(key)) for key in ('clearance','position_gain','prediction_horizon')}}])
    loader = Node(package='controller_manager',executable='spawner',output='screen',
        arguments=['conveyor_velocity_controller','--inactive','--param-file',
                   str(share/'config/tracking_controllers.yaml'),'--controller-manager-timeout','120'])
    return [simulation,move_group,rviz,loader,tracker]


def generate_launch_description():
    defaults = dict(belt_speed='0.1',tracking_start_x='0.0',tracking_end_x='0.24',clearance='0.15',position_gain='5.0',
                    tracking_min_x='-1.4',workspace_step='0.025',entry_lead='0.02',
                    prediction_horizon='0.01',result_path='/tmp/conveyor_tracking.json',
                    start_sim='true',rviz='true',gz_args='-r -v 3',box_size='0.06',belt_top='0.45',
                    belt_y='0.5',upstream_extension='1.0',goal_table_x='-0.55',goal_table_y='0.15',
                    goal_table_top='0.35',block_x='upstream',block_y='0.5')
    return LaunchDescription([DeclareLaunchArgument(k,default_value=v) for k,v in defaults.items()]+
                             [OpaqueFunction(function=configure)])
