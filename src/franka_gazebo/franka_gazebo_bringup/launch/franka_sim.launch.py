from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    """FR3 + Franka Hand in Gazebo, held still by fr3_arm_controller.

    bullet-featherstone is used because the default dartsim engine does not support the
    hand's mimic finger joint.
    """
    return LaunchDescription([
        IncludeLaunchDescription(
            PathJoinSubstitution([
                FindPackageShare('franka_gazebo_bringup'),
                'launch',
                'gazebo_franka_arm_example_controller.launch.py',
            ]),
            launch_arguments={
                'load_gripper': 'true',
                'controller': 'fr3_arm_controller',
                'gz_args': '-r --physics-engine gz-physics-bullet-featherstone-plugin empty.sdf',
            }.items(),
        ),
    ])
