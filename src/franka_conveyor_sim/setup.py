from setuptools import setup
from pathlib import Path
name = 'franka_conveyor_sim'
data = [('share/ament_index/resource_index/packages', ['resource/' + name]), ('share/' + name, ['package.xml', 'README.md', 'RESUME.md'])]
for directory in ('models', 'worlds', 'config', 'launch', 'test/results'):
    for parent in sorted({str(f.parent) for f in Path(directory).rglob('*') if f.is_file() and '__pycache__' not in f.parts}):
        data.append(('share/' + name + '/' + parent, [str(f) for f in Path(parent).iterdir() if f.is_file() and f.suffix != '.pyc']))
setup(name=name, version='0.1.0', packages=[name], data_files=data,
      maintainer='Franka conveyor contributors', maintainer_email='maintainer@example.com',
      description='Physical Gazebo Harmonic conveyor environment', license='Apache-2.0',
      entry_points={'console_scripts': ['box_spawner = franka_conveyor_sim.box_spawner:main',
          'box_pose_estimator = franka_conveyor_sim.box_pose_estimator:main',
          'conveyor_tracker = franka_conveyor_sim.conveyor_tracker:main',
          'pickup_planner = franka_conveyor_sim.pickup_planner:main',
          'pickup_executor = franka_conveyor_sim.pickup_executor:main']})
