from setuptools import find_packages
from setuptools import setup

setup(
    name='franka_spine_server',
    version='3.6.0',
    packages=find_packages(
        include=('franka_spine_server', 'franka_spine_server.*')),
)
