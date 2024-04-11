# Cables robot

<div align="center">
    <img width=100px src="https://img.shields.io/badge/lenguage-%20python-blue" alt="c++">
    <img width=100px src="https://img.shields.io/badge/status-in%20process-orange" alt="In process">
</div>

## Objetivo

Movimiento de la pelvis del paciente en el plano yz para la descarga de peso en la caminata

---

## Topics

**Suscribed:**

- `/pelvis_SP` (sensor_msgs/msg/JointState)
  - **Origen:** control_ZMP
  - Setpoints de posición, velocidad y/o torque en x,y,z. Interesan las coordenadas z e y.
  
**Publishes:**

- `/cables_state` (sensor_msgs/msg/JointState)
  - Posición, esfuerzo, etc. de los cables (por definir)
