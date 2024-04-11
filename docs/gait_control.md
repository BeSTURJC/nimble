# Gait_control

<div align="center">
    <img width=100px src="https://img.shields.io/badge/lenguage-%20python-blue" alt="c++">
    <img width=100px src="https://img.shields.io/badge/status-in%20process-orange" alt="In process">
</div>

## Objetivo

A partir de la trayectoria articular ideal y la trayectoria cartesiana ideal, interpola esos valores para publicar a una frecuencia constante manteniendo una velocidad de caminata determinada por el fisioterapeuta y/o modificada por la máquina de estados.

---

## Topics

**Suscribed:**

- `/joints_trajectory` (nimble_interfaces/msg/JointsTrajectory)
  - **Origen:** states_machine
  - Trayectoria articular ideal
   
- `/cartesian_trajectory` (nimble_interfaces/msg/CartesianTrajectory)
  - **Origen:** kinematic_model
  - Posiciones xyz para toda la trayectoria ideal tanto de la pelvis como del maleolo
  
- `/step_target` (nimble_interfaces/msg/TherapyRequirements)
  - Altura y longitud de paso buscada 

- `/therapy_requirements` (nimble_interfaces/msg/TherapyRequirements)
  - **Origen:** hmi
  - Rango de niveles de asistencia, velocidad, objetivos de altura y distancia de paso
			
**Publishes:**

- `/joints_target` (nimble_interfaces/msg/JointsTrajectory) 
  - Objetivo actual de las articulaciones según fase de marcha

- `/cartesian_target` (nimble_interfaces/msg/CartesianTrajectory)
