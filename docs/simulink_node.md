# Simulink node

<div align="center">
    <img width=100px src="https://img.shields.io/badge/lenguage-%20c++-blue" alt="c++">
    <img width=100px src="https://img.shields.io/badge/status-in%20process-orange" alt="In process">
</div>

## Objetivo

Existe un nodo implementado en Simulink fuera de este paquete que gestiona la comunicación entre ROS2 y el Exo H3 (ROS2<=>CAN).

### Suscribed:

- `/assistLevel` (std_msgs/Int32MultiArray)
  - **Origen:** states_machine
  - Vector nivel de asistencia para cada articulación.

- `/executionMode` (std_msgs/Int16)
  - **Origen:** states_machine
  - Modo de ejecución único (release, transparente, etc.).

- `/controlMode` (std_msgs/Int32MultiArray)
  - **Origen:** states_machine
  - Modo de control para cada articulación.

- `/joints_SP` (sensor_msgs/msg/JointState)
  - **Origen:** control_MSD
  - Set points enviados al Exo (posición, velocidad o torque).

### Publishes:

- `/joints_state` (sensor_msgs/msg/JointState)
  - Información actual de las articulaciones del H3.

- `/interactionTorque` (std_msgs/Float32MultiArray)
  - Torque de interacción medido por el H3, 6 elementos: ["hipR", "kneeR", "ankleR", "hipL", "kneeL", "ankleL"].

- `/FSR` (std_msgs/ByteMultiArray)
  - Contacto con el suelo, 4 elementos: [heelR, toeR, heelL, toeL].
