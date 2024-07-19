#!/bin/python3

import rclpy
from rclpy.node import Node
from nimble_interfaces.msg import Measurements, TherapyRequirements
from std_msgs.msg import Header
import threading
import time
from nimble_interfaces.msg import CartesianTrajectory

from hmi_web.flask_class import FlaskApp

class HmiPublisher(Node):

    def __init__(self):
        super().__init__('hmi_publisher')
        self.publisher_measur_ = self.create_publisher(Measurements, 'measurements', 10)
        self.publisher_th_req_ = self.create_publisher(TherapyRequirements, 'therapy_requirements', 10)


        self.cartesian_target_subscription = self.create_subscription(
            CartesianTrajectory,'cartesian_target',
            self.cartesian_target_callback,10)
        self.cartesian_target_msg = None
        
        self.cartesian_state_subscription = self.create_subscription(
            CartesianTrajectory,'cartesian_state',
            self.cartesian_state_callback,10)
        self.cartesian_state_msg = None

        # TODO: The cartesian_state probably have a buffer, if the buffer is implemented, get only the last element

        # TODO: Clean the parameters if the HMI is confirmed
        self.yamlNamespace = 'hmi'
        self.declare_parameters(
            namespace=self.yamlNamespace,
            parameters=[
                ('height', 1.81),
                ('femur', 0.4),
                ('tibia', 0.4206),
                ('distance_to_heel', 0.04),
                ('distance_to_toe', 0.1065),
                ('height_ankle', 0.0608),
                ('depth_pelvis', 0.0),
                ('width_pelvis', 0.33),
                ('min_assist_level', 10),
                ('max_assist_level', 50),
                ('speed', 0.1),
                ('step_length', 0.5),
                ('step_height', 0.018)
            ]
        )
        self.timer_ = self.create_timer(1.0, self.publisher_callback)

        # Runs the flask app
        self.webHmi = FlaskApp()
        self.flask_thread = threading.Thread(target=self.run_flask)
        self.flask_thread.start()

    def cartesian_target_callback(self, msg):
        if self.cartesian_state_msg is not None:
            multiplier = 100

        

            data1 = self.webHmi.set_articulation_positions( 'exo1', multiplier,
                self.cartesian_state_msg.left_knee[-1],
                self.cartesian_state_msg.right_knee[-1],
                self.cartesian_state_msg.left_pelvis[-1],
                self.cartesian_state_msg.right_pelvis[-1],
                self.cartesian_state_msg.left_hip[-1],
                self.cartesian_state_msg.right_hip[-1],
                self.cartesian_state_msg.left_ankle[-1],
                self.cartesian_state_msg.right_ankle[-1],
                self.cartesian_state_msg.left_heel[-1],
                self.cartesian_state_msg.right_heel[-1],
                self.cartesian_state_msg.left_toe[-1],
                self.cartesian_state_msg.right_toe[-1]
        )

            data2 = self.webHmi.set_articulation_positions( 'exo2', multiplier,
                                                           
                msg.left_knee[0],
                msg.right_knee[0],
                msg.left_pelvis[0],
                msg.right_pelvis[0],
                msg.left_hip[0],
                msg.right_hip[0],
                msg.left_ankle[0],
                msg.right_ankle[0],
                msg.left_heel[0],
                msg.right_heel[0],
                msg.left_toe[0],
                msg.right_toe[0]

                
        )

            data3 = {
                'exo_frame_x': msg.base_pelvis[0].x * multiplier,
                'exo_frame_y': msg.base_pelvis[0].y * multiplier,
                'exo_frame_z': msg.base_pelvis[0].z * multiplier
            }

            self.webHmi.data = {**data1, **data2, **data3}
            
    def cartesian_state_callback(self, msg):
        # Guarda el mensaje recibido para su uso en el callback del cartesian_target
        self.cartesian_state_msg = msg

    # Runs the Flask app
    def run_flask(self):
        self.webHmi.run()

    # Publish measurements and therapy requirements 
    def publisher_callback(self):
        meas_msg = Measurements()
        th_req_msg = TherapyRequirements()

        meas_msg.height = self.get_parameter(self.yamlNamespace + '.height').get_parameter_value().double_value
        meas_msg.femur = self.get_parameter('hmi.femur').get_parameter_value().double_value
        meas_msg.tibia = self.get_parameter('hmi.tibia').get_parameter_value().double_value
        meas_msg.distance_to_heel = self.get_parameter('hmi.distance_to_heel').get_parameter_value().double_value
        meas_msg.distance_to_toe = self.get_parameter('hmi.distance_to_toe').get_parameter_value().double_value
        meas_msg.height_ankle = self.get_parameter('hmi.height_ankle').get_parameter_value().double_value
        meas_msg.depth_pelvis = self.get_parameter('hmi.depth_pelvis').get_parameter_value().double_value
        meas_msg.width_pelvis = self.get_parameter('hmi.width_pelvis').get_parameter_value().double_value
        meas_msg.header = Header()
        meas_msg.header.stamp = self.get_clock().now().to_msg()

        self.publisher_measur_.publish(meas_msg)

        th_req_msg.min_assist_level = self.get_parameter('hmi.min_assist_level').get_parameter_value().integer_value
        th_req_msg.max_assist_level = self.get_parameter('hmi.max_assist_level').get_parameter_value().integer_value
        
        #meas_msg.height = self.get_parameter('speed').get_parameter_value().double_value
        #th_req_msg.step_length = self.get_parameter('step_length').get_parameter_value().double_value
        #th_req_msg.step_height = self.get_parameter('step_height').get_parameter_value().double_value
        th_req_msg.speed = float(self.webHmi.speed)
        th_req_msg.step_length = float(self.webHmi.step_length)
        th_req_msg.step_height = float(self.webHmi.step_height)
        
        th_req_msg.header = Header()
        th_req_msg.header.stamp = self.get_clock().now().to_msg()

        self.publisher_th_req_.publish(th_req_msg)

def main(args=None):

    rclpy.init(args=args)
    hmi_publisher = HmiPublisher()
    rclpy.spin(hmi_publisher)

    hmi_publisher.flask_thread.join()
    hmi_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
