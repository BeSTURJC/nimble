# Link = http://127.0.0.1:5000/

from flask import Flask, render_template, request, jsonify, send_from_directory
import os
import logging
from functools import partial
from geometry_msgs.msg import Point


class FlaskApp:
    def __init__(self):
        self.app = Flask(__name__)

        # Simulation positions
        self.debug = 0
        self.left_malleolus = Point(x=0.0, y=0.0, z=0.0)
        self.right_malleolus = Point(x=0.0, y=0.0, z=0.0)
        self.left_pelvis = Point(x=0.0, y=0.0, z=0.0)
        self.right_pelvis = Point(x=0.0, y=0.0, z=0.0)

        self.page_data = {}  # Additional data for the page

        # Disable Flask's default logger
        self.app.logger.disabled = True
        
        # Disable Werkzeug's logger
        log = logging.getLogger('werkzeug')
        log.disabled = True

        # Patient measurements
        self.speed = 0.3
        self.step_length = 0.6
        self.step_height = 0.12

        self.setup_routes()
        self.it = 0

    def setup_routes(self):
        self.app.route('/')(self.index)
        self.app.route('/static/<path:filename>')(self.serve_static)
        self.app.route('/node_modules/<path:filename>')(self.serve_node_modules)
        self.app.route('/get_data', methods=['GET'])(self.send_data)
        self.app.route('/data_speed', methods=['GET'])(self.get_data_speed)
        self.app.route('/data_step_length', methods=['GET'])(self.get_data_step_length)
        self.app.route('/data_step_height', methods=['GET'])(self.get_data_step_height)


    def index(self):
        return render_template('index.html')

    def serve_static(self, filename):
        return self.app.send_static_file(filename)

    
    def set_articulation_positions(self, left_knee: Point, right_knee: Point,
                                    left_pelvis: Point, right_pelvis: Point,
                                    left_hip: Point, right_hip: Point,
                                    left_ankle: Point, right_ankle: Point,
                                    left_heel: Point, right_heel: Point,
                                    left_toe: Point, right_toe: Point):

        # Saves the data into a dictionary
        multiplier = 100
        self.data = {
            'left_pelvis_x': left_pelvis.x * multiplier,
            'left_pelvis_y': left_pelvis.y * multiplier,
            'left_pelvis_z': left_pelvis.z * multiplier,

            'right_pelvis_x': right_pelvis.x * multiplier,
            'right_pelvis_y': right_pelvis.y * multiplier,
            'right_pelvis_z': right_pelvis.z * multiplier,

            'left_hip_x': left_hip.x * multiplier,
            'left_hip_y': left_hip.y * multiplier,
            'left_hip_z': left_hip.z * multiplier,

            'right_hip_x': right_hip.x * multiplier,
            'right_hip_y': right_hip.y * multiplier,
            'right_hip_z': right_hip.z * multiplier,

            'left_knee_x': left_knee.x * multiplier,
            'left_knee_y': left_knee.y * multiplier,
            'left_knee_z': left_knee.z * multiplier,

            'right_knee_x': right_knee.x * multiplier,
            'right_knee_y': right_knee.y * multiplier,
            'right_knee_z': right_knee.z * multiplier,

            'left_ankle_x': left_ankle.x * multiplier,
            'left_ankle_y': left_ankle.y * multiplier,
            'left_ankle_z': left_ankle.z * multiplier,

            'right_ankle_x': right_ankle.x * multiplier,
            'right_ankle_y': right_ankle.y * multiplier,
            'right_ankle_z': right_ankle.z * multiplier,

            'left_heel_x': left_heel.x * multiplier,
            'left_heel_y': left_heel.y * multiplier,
            'left_heel_z': left_heel.z * multiplier,

            'right_heel_x': right_heel.x * multiplier,
            'right_heel_y': right_heel.y * multiplier,
            'right_heel_z': right_heel.z * multiplier,

            'left_toe_x': left_toe.x * multiplier,
            'left_toe_y': left_toe.y * multiplier,
            'left_toe_z': left_toe.z * multiplier,

            'right_toe_x': right_toe.x * multiplier,
            'right_toe_y': right_toe.y * multiplier,
            'right_toe_z': right_toe.z * multiplier
        }
        

    def serve_node_modules(self, filename):
        root_dir = os.path.dirname(os.path.abspath(__file__))
        static_dir = os.path.join(root_dir, 'static')
        node_modules_dir = os.path.join(static_dir, 'node_modules')
        return send_from_directory(node_modules_dir, filename)


    def send_data(self):
        
        return jsonify(self.data)

    ## Page getters
    def get_data_speed(self):
        # Get the value sent from the webpage
        value = request.args.get('value', type=float)

        if value is not None:
            self.speed = value

        # Returns a json with the updated value
        return jsonify({'value': value})

    def get_data_step_length(self):
        # Get the value sent from the webpage
        value = request.args.get('value', type=float)

        if value is not None:
            self.step_length = value
            
        # Returns a json with the updated value
        return jsonify({'value': value})
            
    def get_data_step_height(self):
        # Get the value sent from the webpage
        value = request.args.get('value', type=float)

        if value is not None:
            self.step_height = value
            
        # Returns a json with the updated value
        return jsonify({'value': value})

    
    def run(self):
        self.app.run(debug=False)

if __name__ == '__main__':
    my_app = FlaskApp()
    my_app.run()
