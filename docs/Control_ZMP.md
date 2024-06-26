# Control ZMP

<div align="center">
    <img width=100px src="https://img.shields.io/badge/lenguage-%20c++-blue" alt="c++">
    <img width=100px src="https://img.shields.io/badge/status-in%20process-orange" alt="In process">
</div>

## Objetivo

Control de la posición del COG/ZMP a través de la acción del marco/robot cables.



---

## Topics

**Suscribed:**

- `/cartesian_target` (nimble_interfaces/msg/CartesianTrajectory)
  - **Origen:** gait_control
  - Objetivo actual de posición de la pelvis según fase de marcha

- `/cartesian_state` (nimble_interfaces/msg/CartesianTrajectory)
  - **Origen:** kinematic_model
  - Posiciones xyz acumuladas hasta el instante actual tanto de la pelvis como del maleolo
  
- `/step_target` (nimble_interfaces/msg/TherapyRequirements)
  - **Origen:** states_machine
  - Altura y longitud de paso buscada 

- `/frame_state` (nimble_interfaces/msg/FrameState)
  - **Origen:** frame
  - Posición y velocidad en x del marco, información del sensor óptico
  
- `/cables_state` (sensor_msgs/msg/JointState)
  - **Origen:** cables_robot
  - Posición, esfuerzo, etc. de los cables (por definir)

- `/FSR` (std_msgs/ByteMultiArray)
  - **Origen:** Nodo_Simulink (H3)
  - Contacto con el suelo, 4 elementos [heelR, toeR, heelL, toeL] 

**Publishes:**

- `/pelvis_SP` (sensor_msgs/msg/JointState)
  - Setpoints de posición, velocidad y/o torque en x,y,z. Se usa de forma análoga al caso de articulaciones, considerando en este caso cada coordenada como articulación.
