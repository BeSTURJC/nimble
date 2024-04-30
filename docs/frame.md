# Frame

<div align="center">
    <img width=100px src="https://img.shields.io/badge/lenguage-%20c++-blue" alt="c++">
    <img width=100px src="https://img.shields.io/badge/status-in%20process-orange" alt="In process">
</div>

## Objetivo

Movimiento del marco en la direccion de avance como acompañamiento e impulso del paciente

---

## Topics

**Suscribed:**

- `/pelvis_SP` (sensor_msgs/msg/JointState)
  - **Origen:** control_MSD
  - Setpoints de posición, velocidad y/o torque en x,y,z. Interesan la coordenada x.
  
**Publishes:**

- `/frame_state` (nimble_interfaces/msg/FrameState)
  - Posición y velocidad en x del marco, información del sensor óptico
