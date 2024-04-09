# Kinetic model

<div align="center">
    <img width=100px src="https://img.shields.io/badge/lenguage-%20python-blue" alt="Python">
    <img width=100px src="https://img.shields.io/badge/status-in%20process-orange" alt="In process">
</div>

## Objetivo

Paso de espacio articular a cartesiano del Exo, obteniendo posiciones xyz del maleolo y la pelvis, tanto de la trayectoria ideal (con long y alt de paso) como la real en cada instante (acumulando en un vector)

---

## Topics

Suscribed:

* /joints_target  (trajectory_msgs/msg/JointTrajectory) Origen: states_machin trayectoria articular ideal

* /joints_state  (sensor_msgs/msg/JointState) Origen: Nodo_Simulink (H3)
    informacion actual de las articulaciones del H3

* /cables_state  (sensor_msgs/msg/JointState) Origen: cables_robot
    posicion, esfuerzo....de los cables (por definir)

* /measurements  (nimble_interfaces/msg/Measurements) Origen: hmi
    medidas fisicas paciente

Publishes:

* /cartesian_target  (nimble_interfaces/msg/CartesianTrajectory)
    posiciones xyz para toda la trayectoria ideal tanto de la pelvis como del maleolo.

* /cartesian_state (nimble_interfaces/msg/CartesianTrajectory)
    posiciones xyz acumuladas hasta el instante actual tanto de la pelvis como del maleolo

* /step_target (nimble_interfaces/msg/TherapyRequirements)
    altura y longitud de paso buscada
