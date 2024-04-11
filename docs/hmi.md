# HMI

<div align="center">
    <img width=100px src="https://img.shields.io/badge/lenguage-%20python-blue" alt="Python">
    <img width=100px src="https://img.shields.io/badge/status-in%20process-orange" alt="In process">
</div>

## Objetivo

Publicar periodicamente las medidas del paciente y los requisitos de la terapia. Se puede sustituir por publicar esos topics directamente en la terminal o creando una interfaz real. Los parámetros pueden modificarse por terminal (en caliente) inicialmente se cargan en el fichero
launch/nimble_launch.py.

---

## Topics
<!-- TODO: Añadir topics del nuevo HMI -->

**Suscribed:**

* NONE
  
**Publishes:**

* `/measurements` (nimble_interfaces/msg/Measurements)
    - Medidas físicas del paciente
* `/therapy_requirements` (nimble_interfaces/msg/TherapyRequirements)
    - Niveles de asistencia, requisitos de altura y distancia de paso


---

## Interfaz gráfica

<figure class="align-center" style="width:60%">
  <img src="https://github.com/jcarballeira/nimble/blob/HMI/docs/assets/images/hmiV1.png" alt="">
  <figcaption>1º Versión de la interfaz gráfica</figcaption>
</figure>

---

## Ejecución

1. Lanzar el launcher general:

```bash
ros2 launch nimble nimble_launch.py
```

2. Abrir navegador predeterminado y acceder a la dirección <http://127.0.0.1:5000>

## Estructura de directorios

```java
hmi_web/
├── flask_class.py
├── package.json
├── package-lock.json
├── sender.py
├── static/
│   ├── main.js
│   ├── node_modules
│   └── style.css
└── templates/
    ├── index.html
    ├── package.json
    └── package-lock.json
```

Los elementos mas importantes son:

* **flask_class.py:** Es la clase que utilizará el nodo de ros para comunicarse con la web.
* **main.js:** Programa de java script donde está todo el código de la animación 3D del exo además de la comunicación de la web con flask.
* **style.cs:** Estilo de la página
* **index.html:** Estructura web del HMI
