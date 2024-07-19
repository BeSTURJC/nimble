# Cables robot

<div align="center">
    <img width=100px src="https://img.shields.io/badge/lenguage-%20c++-blue" alt="c++">
    <img width=100px src="https://img.shields.io/badge/status-in%20process-orange" alt="In process">
</div>

## Objetivo

Publicación a frecuencia concreta de targets actuales tanto articulares para el exo como cartesianos pelvis: para marco (x) y cables(y,z).

---

## Topics

**Suscribed:**

- `/joints_trajectory` (nimble_interfaces/msg/JointsTrajectory)
  - **Origen:** states_machine
  - Trayectoria articular ideal para paso completo. El numero de puntos depende de la frecuancia de publicacion de setpoints.
  
- `/cartesian_trajectory` (nimble_interfaces/msg/CartesianTrajectory)
  - **Origen:** states_machine
  - Trayectoria cartesiana ideal para paso completo (pelvis, toe, heel, ankle). El numero de puntos depende de la frecuancia de publicacion de setpoints.  
  
- `/therapy_requirements` (nimble_interfaces/msg/TherapyRequirements)
  - **Origen:** hmi
  - objetivo dist y altura de paso, rangos de asistencia,velocidad...  
  
**Publishes:**

- `/pelvis_target` (sensor_msgs/msg/JointState)
  - Objetivo actual de pelvis/ZMP. Posición de marco(x) y cables(y,z) (por definir)
- `/joints_target` (nimble_interfaces/msg/JointsTrajectory)
  - objetivo actual del control MSD (joints_trajectory punto por punto con %marcha asociado)
- `/cartesian_target` (nimble_interfaces/msg/CartesianTrajectory)
  - Objetivo cartesiano actual de todas las articulaciones
