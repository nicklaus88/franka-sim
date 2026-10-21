from setuptools import find_packages
from setuptools import setup

setup(
    name='franka_mobile',
    version='3.6.0',
    packages=find_packages(
        include=('franka_mobile', 'franka_mobile.*')),
)
