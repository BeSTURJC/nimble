from setuptools import find_packages
from setuptools import setup

setup(
    name='frame_data',
    version='0.0.0',
    packages=find_packages(
        include=('frame_data', 'frame_data.*')),
)
