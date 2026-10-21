from setuptools import find_packages
from setuptools import setup

setup(
    name='franka_mobile_fr3_duo_moveit_config',
    version='3.6.0',
    packages=find_packages(
        include=('franka_mobile_fr3_duo_moveit_config', 'franka_mobile_fr3_duo_moveit_config.*')),
)
