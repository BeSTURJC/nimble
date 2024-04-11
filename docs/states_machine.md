# States machine

<div align="center">
    <img width=100px src="https://img.shields.io/badge/lenguage-%20python-blue" alt="c++">
    <img width=100px src="https://img.shields.io/badge/status-in%20process-orange" alt="In process">
</div>

## Objetivo

Reclama el servicio de generacion de trayectorias ante cada modificacion de las medidas o requisitos de la terapia. Funciones por definir para la evaluacion de las trayectoria real vs ideal (cartesiana y articular?), el ajuste del nivel de asistencia en consecuencia y quizás añadir la publicacion del estado de la marcha (porcentaje).

---

## Topics

**Suscribed:**

- `/joints_target` (trajectory_msgs/msg/JointTrajectory)
  - **Origen:** states_machin
  - Trayectoria articular ideal

- `/joints_state` (sensor_msgs/msg/JointState)
  - **Origen:** Nodo_Simulink (H3)
  - Información actual de las articulaciones del H3

- `/cables_state` (sensor_msgs/msg/JointState)
  - **Origen:** cables_robot
  - Posición, esfuerzo, etc. de los cables (por definir)

- `/measurements` (nimble_interfaces/msg/Measurements)
  - **Origen:** hmi
  - Medidas físicas del paciente

**Publishes:**

- `/cartesian_target` (nimble_interfaces/msg/CartesianTrajectory)
  - Posiciones xyz para toda la trayectoria ideal tanto de la pelvis como del maleolo.

- `/cartesian_state` (nimble_interfaces/msg/CartesianTrajectory)
  - Posiciones xyz acumuladas hasta el instante actual tanto de la pelvis como del maleolo

- `/step_target` (nimble_interfaces/msg/TherapyRequirements)
  - Altura y longitud de paso buscada