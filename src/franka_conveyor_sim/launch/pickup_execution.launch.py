"""Add ros2_control execution to an existing pickup planner; starts no simulator."""
from pathlib import Path
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
from launch.conditions import IfCondition
from launch_ros.actions import Node


def configure(context):
    value = lambda key: context.launch_configurations[key]
    share = Path(get_package_share_directory('franka_conveyor_sim'))
    hand = Node(package='controller_manager',executable='spawner',output='screen',
        arguments=['pickup_hand_controller','--controller-manager',value('controller_manager'),
                   '--param-file',str(share/'config/pickup_hand_controller.yaml'),
                   '--controller-manager-timeout','60'],condition=IfCondition(value('spawn_hand_controller')))
    executor = Node(package='franka_conveyor_sim',executable='pickup_executor',output='screen',
        parameters=[{'use_sim_time':True,'plan_path':value('plan_path'),
                     'auto_execute':value('auto_execute').lower()=='true',
                     'grasp_compression':float(value('grasp_compression')),
                     'controller_manager':value('controller_manager'),
                     'arm_controller':value('arm_controller'),'hand_controller':value('hand_controller'),
                     'result_path':value('result_path')}])
    return [hand,executor]


def generate_launch_description():
    defaults = dict(plan_path='/tmp/franka_pickup_plan.json',auto_execute='false',
                    result_path='/tmp/franka_pickup_execution.json',spawn_hand_controller='true',
                    arm_controller='fr3_arm_controller',hand_controller='pickup_hand_controller',
                    controller_manager='/controller_manager',grasp_compression='0.001')
    return LaunchDescription([DeclareLaunchArgument(k,default_value=v) for k,v in defaults.items()]+
                             [OpaqueFunction(function=configure)])
