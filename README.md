# Nimble

<!--Añadir imagen del logo-->

<div align="center">
<img width=100px src="https://img.shields.io/badge/status-in%20process-orange" alt="In process"></a>
<!-- <img width=100px src="https://img.shields.io/badge/license-Apache-green" alt="explode"></a> -->
</div>

## Índice
1. [Instalación del paquete](#instalación-del-paquete)

2. [Anotaciones](#anotaciones)

3. [Tipos de Mensaje Utilizados](#tipos-de-mensaje-utilizados)

4. [Equipo](#equipo)

---
---

## Instalación del paquete

0. **Requisitos sistema:**
	- Ubuntu 22.04
	- Instalación desktop de ROS2 Humble

1. **Crear una carpeta workspace** (p.e. nimble_ws o ros_ws) y subcarpeta nimble_ws/src. En ella copiaremos los archivos descargandolos directamente o ejecutando:

```bash
git clone https://github.com/jcarballeira/nimble.git
```
 
3. **Compilar:** Situarse en "cd nimble_ws" y ejecutar "colcon build". Rezar a vuestra divinidad favorita.

4. **Cargar la instalación** con "source install/setup.bash" 
	- Este paso hay que realizarlo desde nimble_ws al abrir un nuevo terminal. Para evitarlo, abrir un terminal nuevo, ejecutar "gedit .bashrc"
          Se abrirá un archivo en el que debemos copiar al final la siguiente instrucción:
   ```bash
   source ~/nimble_ws/install/setup.bash
   ```
   
   De esta forma se ejecuta automáticamente al abrir un nuevo terminal. De todas formas, al compilar algo nuevo habrá que reiniciar el terminal para que se 
          actualice ese archivo.

5. **Ejecución del nodo** deseado "ros2 run nimble your_node"

6. En el caso del mainPC existe un fichero launch para ejecutar todos los nodos en una única instrucción. Ejecutar "ros2 launch nimble nimble_launch.py". 

---
---

## Anotaciones
* Existen 2 paquetes diferentes e imprescindibles: 

	- nimble_interfaces: Contiene el servicio para la generacion de trayectorias ideales (NN) y los mensajes creados para almacenar información 	de forma concreta (para el resto se usan msgs predefinidos en ROS2). Al final del documento hay una lista de los tipos de mensaje creados y los distintos campos que contienen
	
	- nimble: Incluye todos los nodos a ejecutar tanto en el mainPC como el los diferentes micros o raspberrys.
	
	
Cada nodo está suscrito a todos los topics indicados y preparado para publicar lo necesario (o eso creo).

Tiene las funciones asociadas a la recepción de cada mensaje (callbacks). En esos callbacks se almacena cada mensaje en una estructura de datos para procesarlos según el objetivo de cada nodo. La estructura está pensada para almacenar los mensajes según lleguen y poder hacer el procesamiento necesario según el nodo. De esta manera se puede comprobar si ya llegó toda la información, subdividirlo en varias funciones de procesamiento si solo se necesitan 2 mensajes, directamente en el callback si solo hace falta un mensaje...según cada nodo.

Además cada nodo tiene un timer (de perido ajustable, default:1000ms) que ejecuta un callback por si se quiere publicar o ejecutar algo periódicamente. Típicamente los sensores se publican cada cierto tiempo, habrá casos en los que solo se quiera publicar si ocurre algo concreto, por ejemplo para enviar un set point. En caso de no usarlo eliminadlo para evitar que entre innecesariamente.

Ahora que cada cual haga sus chapuzas correspondientes en cada nodo. Salud y república. Deslicen hacia abajo para más info interesante, suscribanse y denle a like.

---
---
	
## Nodos			             
Cada nodo está suscrito y publica diferentes topics, descritos de la siguiente forma:
	/nombre_topic  (Tipo de mensaje) Origen: Nodo_de_procedencia

Los tipos de mensaje creados específicamente son del tipo nimble_interfaces/msg/NombreMensaje, que también es la carpeta en la que están guardados. Los predefinidos de ROS varían.

AL FINAL DE ESTE ARCHIVO hay una lista de los tipos de mensaje usados y los distintos campos que contienen.

---
  
### HMI
  
Obj: publica periodicamente las medidas del paciente y los requisitos de la terapia. Se puede sustituir por publicar esos topics directamente en la terminal o creando una interfaz real. Los parámetros pueden modificarse por terminal (en caliente) inicialmente se cargan en el fichero 
launch/nimble_launch.py.
  
		-Suscribed: NONE
		
		-Publishes:
			/measurements (nimble_interfaces/msg/Measurements)
				medidas fisicas paciente
   			/therapy_requirements (nimble_interfaces/msg/TherapyRequirements)
   				niveles de asistencia, requisitos de altura y distancia de paso
   				
---

### States_machine

Obj: Reclama el servicio de generacion de trayectorias ante cada modificacion de las medidas o requisitos de la terapia. Funciones por definir para la evaluacion de las trayectoria real vs ideal (cartesiana y articular?), el ajuste del nivel de asistencia en consecuencia y quizás añadir la publicacion del estado de la marcha (porcentaje).

		-Suscribed: 
			/measurements (nimble_interfaces/msg/Measurements) Origen: hmi
				medidas fisicas paciente
				
			/therapy_requirements (nimble_interfaces/msg/TherapyRequirements) Origen: hmi
				rango de niveles de asistencia, objetivos de altura y distancia de paso
				
			/joints_state (sensor_msgs/msg/JointState) Origen: Nodo_Simulink (H3)
				informacion actual de las articulaciones del H3	
				
			/cartesian_target  (nimble_interfaces/msg/CartesianTrajectory) Origen: kinematic_model
				posiciones xyz para toda la trayectoria ideal tanto de la pelvis como del maleolo.  
				El nodo debe rellenar las componentes y,z despues de recibir la componente x.	
							
			/cartesian_state  (nimble_interfaces/msg/CartesianTrajectory) Origen: kinematic_model
				posiciones xyz reales acumuladas hasta el instante actual tanto de la pelvis como del maleolo
				
			/cables_state  (sensor_msgs/msg/JointState) Origen: cables_robot
				posicion, velocidad, esfuerzo de los cables (por confirmar)
				
			/step_target  (nimble_interfaces/msg/TherapyRequirements) Origen: kinematic_model
				altura y longitud de paso a ejecutar, consecuencia del calculo de la trayectoria articular ideal
				
			/interactionTorque (std_msgs/Float32MultiArray) Origen: Nodo_Simulink (H3)
				torque de interacción medido por el H3, 6 elementos 
				["hipR", "kneeR", "ankleR","hipL", "kneeL", "ankleL"]
			
			/FSR 	(std_msgs/ByteMultiArray) Origen: Nodo_Simulink (H3)
				sensores de contacto con el suelo, 4 elementos [heelR, toeR, heelL, toeL] 				
				
		-Publishes:
							
			/joints_target	(trajectory_msgs/msg/JointTrajectory)
   				trayectoria articular ideal obtenida por servicio (NN: TrajGenerationService)
   				  				
   			/assistLevel  (std_msgs/Int32MultiArray) 
				vector nivel de asistencia para cada articulacion ["hipR", "kneeR", "ankleR","hipL", "kneeL", "ankleL"]
   				
			/executionMode  (std_msgs/Int16)
				modo de ejecucion unico (release, transparent...)
				
    			/controlMode  (std_msgs/Int32MultiArray) uno por cada articulacion
    				modo de control para cada articulacion ["hipR", "kneeR", "ankleR","hipL", "kneeL", "ankleL"]
---			
		
### Kinematic_model

Obj: Paso de espacio articular a cartesiano del Exo, obteniendo posiciones xyz del maleolo y la pelvis, tanto de la trayectoria ideal (con long y alt de paso) como la real en cada instante (acumulando en un vector)

		-Suscribed:
		 	/joints_target  (trajectory_msgs/msg/JointTrajectory) Origen: states_machine
   				trayectoria articular ideal
   				
    			/joints_state  (sensor_msgs/msg/JointState) Origen: Nodo_Simulink (H3)
				informacion actual de las articulaciones del H3
				
    			/cables_state  (sensor_msgs/msg/JointState) Origen: cables_robot
				posicion, esfuerzo....de los cables (por definir)
				
    			/measurements  (nimble_interfaces/msg/Measurements) Origen: hmi
				medidas fisicas paciente
    			
    		-Publishes:
    			/cartesian_target  (nimble_interfaces/msg/CartesianTrajectory)
				posiciones xyz para toda la trayectoria ideal tanto de la pelvis como del maleolo. 
				
				
    			/cartesian_state (nimble_interfaces/msg/CartesianTrajectory)
				posiciones xyz acumuladas hasta el instante actual tanto de la pelvis como del maleolo
				
    			/step_target (nimble_interfaces/msg/TherapyRequirements)
				altura y longitud de paso buscada 
    
---			

### Control_MSD

Obj: control MSD de las articulaciones del Exo H3

		-Suscribed:

			/joints_target  (trajectory_msgs/msg/JointTrajectory) Origen: states_machine
   				trayectoria articular ideal
   				
    			/joints_state  (sensor_msgs/msg/JointState) Origen: Nodo_Simulink (H3)
				informacion actual de las articulaciones del H3
				
   			/assistLevel  (std_msgs/Int32MultiArray) Origen: states_machine
				vector nivel de asistencia para cada articulacion
   			
  			/interactionTorque (std_msgs/Float32MultiArray) Origen: Nodo_Simulink (H3)
				torque de interacción medido por el H3, 6 elementos 
				["hipR", "kneeR", "ankleR","hipL", "kneeL", "ankleL"]
			
			/FSR 	(std_msgs/ByteMultiArray) Origen: Nodo_Simulink (H3)
				contacto con el suelo, 4 elentos [heelR, toeR, heelL, toeL] 
   				
    		-Publishes:
			/joints_SP  (sensor_msgs/msg/JointState)
				set points enviados al Exo (posicion, velocidad o torque)

---

### Control_ZMP

Obj: control de la posición del COG/ZMP a través de la acción del marco/robot cables.
	
		-Suscribed:
			/cartesian_target  (nimble_interfaces/msg/CartesianTrajectory) Origen: kinematic_model
				posiciones xyz para toda la trayectoria ideal tanto de la pelvis como del maleolo. 
				
			/step_target (nimble_interfaces/msg/TherapyRequirements) Origen: kinematic_model
				altura y longitud de paso buscada 
				
			/frame_state (nimble_interfaces/msg/FrameState) Origen: frame
				posicion y velocidad en x del marco, informacion del sensor óptico
				
			/cables_state  (sensor_msgs/msg/JointState) Origen: cables_robot
				posicion, esfuerzo....de los cables (por definir)
				
			/FSR 	(std_msgs/ByteMultiArray) Origen: Nodo_Simulink (H3)
				contacto con el suelo, 4 elentos [heelR, toeR, heelL, toeL] 
				
    		-Publishes:
    		
			/pelvis_SP  (sensor_msgs/msg/JointState)
				setpoints de posicion, velocidad y/o torque en x,y,z. Se usa de forma análoga
				al caso de articulaciones, considerando en este caso cada coordenada como articulacion.
			

---

### Cables_robot

Obj: movimiento de la pelvis del paciente en el plano yz para la descarga de peso en la caminata

		-Suscribed:

			/pelvis_SP  (sensor_msgs/msg/JointState) Origen: control_ZMP
				setpoints de posicion, velocidad y/o torque en x,y,z. Interesan las coordenadas z e y.			
   				
    		-Publishes:
    		
			/cables_state  (sensor_msgs/msg/JointState)
				posicion, esfuerzo....de los cables (por definir)
 		
---

### Frame 

Obj: movimiento del marco en la direccion de avance como acompañamiento e impulso del paciente

		-Suscribed:

			/pelvis_SP  (sensor_msgs/msg/JointState) Origen: control_MSD
				setpoints de posicion, velocidad y/o torque en x,y,z. Interesan la coordenada x.				
   				
    		-Publishes:
			
			/frame_state (nimble_interfaces/msg/FrameState)
				posicion y velocidad en x del marco, informacion del sensor óptico
				
---

### Gamming

Obj: proyeccion de incentivo para el paciente en forma de huellas sobre el suelo

		-Suscribed:
		
			/frame_state (nimble_interfaces/msg/FrameState) Origen: cables_robot
				posicion y velocidad en x del marco, informacion del sensor óptico
				
			/step_target (nimble_interfaces/msg/TherapyRequirements) Origen: kinematic_model
				altura y longitud de paso buscada 

			   				
    		-Publishes: NONE

---

### BONUS TRACK: NODO_SIMULINK

Obj: Existe un nodo implementado en simulink fuera de este paquete que gestiona la comunicacion entre ROS2 y el Exo H3 (ROS2<=>CAN)

		-Suscribed:

   			/assistLevel  (std_msgs/Int32MultiArray) Origen: states_machine
				vector nivel de asistencia para cada articulacion
   				
			/executionMode  (std_msgs/Int16) Origen: states_machine
				modo de ejecucion unico (release, trnasparent...)
				
    			/controlMode  (std_msgs/Int32MultiArray) Origen: states_machine
    				modo de control para cada articulacion
    				
			/joints_SP  (sensor_msgs/msg/JointState) Origen: control_MSD
				set points enviados al Exo (posicion, velocidad o torque)
    				
   				
    		-Publishes:
	
			/joints_state  (sensor_msgs/msg/JointState)
				informacion actual de las articulaciones del H3	
				
			/interactionTorque (std_msgs/Float32MultiArray)
				torque de interacción medido por el H3, 6 elementos 
				["hipR", "kneeR", "ankleR","hipL", "kneeL", "ankleL"]
			
			/FSR 	(std_msgs/ByteMultiArray) 
				contacto con el suelo, 4 elentos [heelR, toeR, heelL, toeL] 

---
---

## TIPOS DE MENSAJE UTILIZADOS

-----Mensajes y servicios custom y los campos que contienen---------------
   
   	-nimble_interfaces/msg/Measurements
		-std_msgs/Header header
		-float64 height
		-float64 femur
		-float64 tibia
		-float64 height_ankle
		-float64 distance_to_heel
		-float64 distance_to_toe
		-float64 depth_pelvis
		-float64 width_pelvis
   		
   	-nimble_interfaces/msg/TherapyRequirements
		-std_msgs/Header header
   		-float64 speed
		-float64 step_length
		-float64 step_height
		-int32 min_assist
		-int32 max_assist
		
   	-nimble_interfaces/msg/FrameState
		-std_msgs/Header header
		-float64 optic_sensor
		-float64 velocity
		-float64 position 			
		
   	-nimble_interfaces/msg/CartesianTrajectory
		-std_msgs/Header header
		-geometry_msgs/Point[] malleolus (vector de vectores [x,y,z])
			float64 x
			float64 y
			float64 z
    		-geometry_msgs/Point[] pelvis    (vector de vectores [x,y,z])
    			float64 x
			float64 y
			float64 z 
   		
	-nimble_interfaces/srv/TrajGeneratorService (a partir de medidas y necesidades de paso genera la trayectoria ideal articulaciones)
		-Request 1: measurements (nimble_interfaces/msg/Measurements)
		-Request 2: therapy_requirements (nimble_interfaces/msg/TherapyRequirements)
		-Response: joints_target (trajectory_msgs/msg/JointTrajectory)	

 ---
 ---

## Mensajes utilizados de los predefinidos en ROS

	-sensor_msgs/msg/JointState
		-std_msgs/Header header
		-string[]  name        seguiremos este orden ["hipR", "kneeR", "ankleR","hipL", "kneeL", "ankleL"]
		-float64[] position    vector de vectores [pos_hipR, pos_kneeR, pos_ankleR, pos_hipL, pos_kneeL, pos_ankleL]
		-float64[] velocity    análogo al anterior con velocidades
		-float64[] effort      análogo al anterior con velocidades
			
	-trajectory_msgs/msg/JointTrajectory
		-std_msgs/Header header
   		-string[] joint_names       seguiremos este orden ["hipR", "kneeR", "ankleR","hipL", "kneeL", "ankleL"]
   		-JointTrajectoryPoint[] points
   			float64[] positions
			float64[] velocities
			float64[] accelerations
			float64[] effort
			duration time_from_start
   		
   	-std_msgs/Int32MultiArray
		-MultiArrayLayout  layout        
		-int32[] data 
		
	-std_msgs/Float32MultiArray
		-MultiArrayLayout  layout
		-float32[] data  
		
   	-std_msgs/Int16
		-int16 data

 ---
 ---
 
## Equipo

		

<!--Licencia???-->
		
		
		
		
		
		
		
