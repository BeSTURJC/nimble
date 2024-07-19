from launch import LaunchDescription
from launch_ros.actions import Node
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('nimble'),
        'config',
        'paciente.yaml'
        )

    return LaunchDescription([
        Node(
            package="nimble",
            executable="hmi.py",
            name="hmi",
            output="screen",
            emulate_tty=True,
            parameters=[config]
        ),
        Node(
            package="nimble",
            executable="traj_generator_server",
            name="traj_generator_server",
            output="log",
            emulate_tty=True,
            
        ),
        Node(
            package="nimble",
            executable="cartesian_traj_server",
            name="cartesian_traj_server",
            output="log",
            emulate_tty=True,
            
        ),
        Node(
            package="nimble",
            executable="states_machine",
            name="states_machine",
            output="log",
            emulate_tty=True,
            
        ),
        Node(
            package="nimble",
            executable="gait_control",
            name="gait_control",
            output="log",
            emulate_tty=True,
            
        ),
        Node(
            package="nimble",
            executable="kinematic_model",
            name="kinematic_model",
            output="log",
            emulate_tty=True,
            
        ),
                
        Node(
            package="nimble",
            executable="control_MSD",
            name="control_MSD",
            output="log",
            emulate_tty=True,
            
        ),
        Node(
            package="nimble",
            executable="fake_H3_node",
            name="fake_H3_node",
            output="log",
            emulate_tty=True,
            
        ),
        Node(
            package="nimble",
            executable="fake_cables_node",
            name="fake_cables_node",
            output="log",
            emulate_tty=True,
            
        )
        #,
        #Node(
           # package="nimble",
            #executable="control_ZMP",
            #name="control_ZMP",
            #output="log",
            #emulate_tty=True,
            
        #)
    ])
