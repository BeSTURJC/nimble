from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="nimble",
            executable="hmi",
            name="hmi",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"height": 1.8},
                {"femur": 0.42},
                {"tibia": 0.35},
                {"foot": 0.25},
                {"speed": 1.0},
                {"assistance_level": 0.1},
                {"step_length": 0.6},
                {"step_height": 0.12},
                
            ]
        ),
        Node(
            package="nimble",
            executable="traj_generator_server",
            name="traj_generator_server",
            output="screen",
            emulate_tty=True,
            
        ),
        Node(
            package="nimble",
            executable="states_machine",
            name="states_machine",
            output="screen",
            emulate_tty=True,
            
        ),
        Node(
            package="nimble",
            executable="kinematic_model",
            name="kinematic_model",
            output="screen",
            emulate_tty=True,
            
        ),
                
        Node(
            package="nimble",
            executable="control_MSD",
            name="control_MSD",
            output="screen",
            emulate_tty=True,
            
        ),
        Node(
            package="nimble",
            executable="control_ZMP",
            name="control_ZMP",
            output="screen",
            emulate_tty=True,
            
        )
    ])
