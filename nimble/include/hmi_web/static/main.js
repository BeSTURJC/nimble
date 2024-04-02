import * as THREE from "https://cdn.jsdelivr.net/npm/three@0.132.2/build/three.module.js";

class ThreeDScene {
    constructor() {
      // Create a scene
      this.scene = new THREE.Scene();

      // Create a camera
      this.camera = new THREE.PerspectiveCamera(
          75,
          window.innerWidth / window.innerHeight,
          0.1,
          1000
      );
      
      // Camera position
      this.camera.position.x = 100;
      this.camera.position.y = 60;
      this.camera.position.z = -30;
      
      this.camera.lookAt(0, 0, -30);
      this.camera.rotateZ(Math.PI/2);

      // Create a renderer
      this.renderer = new THREE.WebGLRenderer();
      // this.renderer.setSize(window.innerWidth / 2, window.innerHeight / 2);
      this.renderer.setSize(window.innerWidth, window.innerHeight);
      document.body.appendChild(this.renderer.domElement);
      
      //! Concept of assist level percent
      this.text = document.createElement('div');
      this.text.style.position = 'absolute';
      this.text.style.width = 100;
      this.text.style.height = 100;
      this.text.style.color = 'green';
      this.text.innerHTML = '10%';
      this.text.style.top = '285px';
      this.text.style.left = '1010px';
      document.body.appendChild(this.text);


      // Creates a ground
      const groundGeometry = new THREE.BoxGeometry(400, 0.1, 100);
      const groundMaterial = new THREE.MeshBasicMaterial({ color: 0x333333 }); 
      const ground = new THREE.Mesh(groundGeometry, groundMaterial);
      ground.position.z = -76.0; 
      ground.rotateX(Math.PI/2);
      
      // Adds the ground to the scene
      this.scene.add(ground);

      // Sphere for joint representation
      const radius = 2;
      const widthSegments = 32;
      const heightSegments = 32;
      const geometry = new THREE.SphereGeometry(radius, widthSegments, heightSegments);
      const material = new THREE.MeshStandardMaterial({ color: 0xffffff, metalness: 1 });

      // Creates the box
      this.createBox();
      
      // Creates the joints
      this.base_pelvis = new THREE.Mesh(geometry, material);
      this.left_pelvis = new THREE.Mesh(geometry, material);
      this.right_pelvis = new THREE.Mesh(geometry, material);

      this.left_hip = new THREE.Mesh(geometry, material);
      this.right_hip = new THREE.Mesh(geometry, material);

      this.left_knee = new THREE.Mesh(geometry, material);
      this.right_knee = new THREE.Mesh(geometry, material);

      this.left_ankle = new THREE.Mesh(geometry, material);
      this.right_ankle = new THREE.Mesh(geometry, material);

      this.left_heel = new THREE.Mesh(geometry, material);
      this.right_heel = new THREE.Mesh(geometry, material);

      this.left_toe = new THREE.Mesh(geometry, material);
      this.right_toe = new THREE.Mesh(geometry, material);

         
      // Add the joints to the scene
      this.scene.add(this.base_pelvis);
      this.scene.add(this.left_pelvis);
      this.scene.add(this.right_pelvis);
      
      this.scene.add(this.left_hip);
      this.scene.add(this.right_hip);
      
      this.scene.add(this.left_knee);
      this.scene.add(this.right_knee);
      
      this.scene.add(this.left_ankle);
      this.scene.add(this.right_ankle);
      
      this.scene.add(this.left_heel);
      this.scene.add(this.right_heel);
      
      this.scene.add(this.left_toe);
      this.scene.add(this.right_toe);
      
      // Add lighting
      this.addDirectionalLight(this.scene, new THREE.Vector3(10, 10, 10), 1);
      this.addDirectionalLight(this.scene, new THREE.Vector3(-10, 10, -10), 2);
      this.addDirectionalLight(this.scene, new THREE.Vector3(-10, -10, -10), 1);
  
      // Add event listeners for mouse movement
      this.isDragging = false;
      this.previousMousePosition = {
        x: 0,
        y: 0,
      };
  
      document.addEventListener("mousemove", this.onMouseMove.bind(this));
      document.addEventListener("mousedown", this.onMouseDown.bind(this));
      document.addEventListener("mouseup", this.onMouseUp.bind(this));
  
      // Animation function
      this.animate();

      // Initial call to fetch data for ROS
      this.fetchData();
    }

    createBox() {
      // Sphere for joint representation
      const radius = 3;
      const widthSegments = 32;
      const heightSegments = 32;
      const geometry = new THREE.SphereGeometry(radius, widthSegments, heightSegments);
      const material = new THREE.MeshStandardMaterial({ color: 0xffffff, metalness: 1 });
  
      // Define object positions
      const positions = [
          { x: 50, y: -40, z: -73 },
          { x: 50, y: 40, z: -73 },
          { x: -50, y: -40, z: -73 },
          { x: -50, y: 40, z: -73 },
          { x: 50, y: -40, z: 50 },
          { x: 50, y: 40, z: 50 },
          { x: -50, y: -40, z: 50 },
          { x: -50, y: 40, z: 50 }
      ];
  
      // Array to store created meshes
      const boxes = [];
  
      // Create meshes and add them to the scene
      for (const position of positions) {
          const box = new THREE.Mesh(geometry, material);
          box.position.set(position.x, position.y, position.z);
          this.scene.add(box);
          boxes.push(box);
      }
  
      // Animate joints between meshes
      this.animateBone(this.p1, boxes[0], boxes[1]);
      this.animateBone(this.p2, boxes[0], boxes[2]);
      this.animateBone(this.p3, boxes[1], boxes[3]);
      this.animateBone(this.p4, boxes[3], boxes[2]);
  
      this.animateBone(this.p5, boxes[0], boxes[4]);
      this.animateBone(this.p6, boxes[1], boxes[5]);
      this.animateBone(this.p7, boxes[2], boxes[6]);
      this.animateBone(this.p8, boxes[3], boxes[7]);
  
      this.animateBone(this.p9, boxes[5], boxes[4]);
      this.animateBone(this.p10, boxes[6], boxes[4]);
      this.animateBone(this.p11, boxes[6], boxes[7]);
      this.animateBone(this.p12, boxes[7], boxes[5]);
  }
  
    onMouseMove(event) {
      if (this.isDragging) {
        const deltaMove = {
          x: event.offsetX - this.previousMousePosition.x,
          y: event.offsetY - this.previousMousePosition.y,
        };
    
        if (event.buttons === 1 && event.shiftKey) { // Left button pressed with Shift key
          // Adjust camera rotation based on mouse movement
          this.camera.rotation.y -= deltaMove.x * 0.01;
          this.camera.rotation.x -= deltaMove.y * 0.01;
        } else if (event.buttons === 1) { // Left button pressed
          // Adjust camera position based on mouse movement
          this.camera.position.x -= deltaMove.x * 0.1;
          this.camera.position.y += deltaMove.y * 0.1;
        } else if (event.buttons === 4) { // Middle button pressed
          // Adjust camera zoom based on mouse movement
          this.camera.position.x -= deltaMove.y * 0.1;
          this.camera.position.y -= deltaMove.y * 0.1;
          this.camera.position.z -= deltaMove.y * 0.1;
        }
    
        this.previousMousePosition = {
          x: event.offsetX,
          y: event.offsetY,
        };
      }
    }
    
    
    onMouseDown(event) {
      this.isDragging = true;
      this.previousMousePosition = {
        x: event.offsetX,
        y: event.offsetY,
      };
    }
    
    onMouseUp(event) {
      this.isDragging = false;
    }

    createCylinder(joint1, joint2) {
      // Calculate the midpoint position between joint1 and joint2
      const centerX = (joint1.position.x + joint2.position.x) / 2;
      const centerY = (joint1.position.y + joint2.position.y) / 2;
      const centerZ = (joint1.position.z + joint2.position.z) / 2;
  
      // Calculate the height of the cylinder
      const distance = joint1.position.distanceTo(joint2.position);
  
      // Define parameters for the cylinder
      const radiusTop = 1;
      const radiusBottom = 1; 
      const height = distance;
      const radialSegments = 32;
      const heightSegments = 1;
      const openEnded = false;
  
      // Create cylinder geometry
      const geometry = new THREE.CylinderGeometry(radiusTop, radiusBottom, height, radialSegments, heightSegments, openEnded);
  
      // Create material
      const material = new THREE.MeshStandardMaterial({ color: 0xffffff, metalness: 1 });
  
      // Create the cylinder
      const cylinder = new THREE.Mesh(geometry, material);
  
      // Calculate the direction from joint2 towards joint1
      const direction = new THREE.Vector3().subVectors(joint1.position, joint2.position).normalize();
  
      // Calculate cylinder position
      cylinder.position.set(centerX, centerY, centerZ);
  
      // Orient the cylinder
      cylinder.quaternion.setFromUnitVectors(new THREE.Vector3(0, 1, 0), direction);
  
      return cylinder;
  }

    addDirectionalLight(scene, position, intensity) {
      const light = new THREE.DirectionalLight(0xffffff, intensity);

      // Set light position
      light.position.copy(position); 

      // Enable shadow casting
      light.castShadow = true; 
      scene.add(light);
    }

    animateBone(con, joint1, joint2) {
      // Delete the previous cylinder
      if (con) {
        this.scene.remove(con);
      }

      // Adds to the scene the new cylinder
      con = this.createCylinder(joint1, joint2);
      this.scene.add(con); 

      return con
    }

    updateTextPosition() {
      // const vector = new THREE.Vector3();
      // vector.setFromMatrixPosition(this.camera.matrixWorld);
      // vector.project(this.camera);
  
      // const widthHalf = window.innerWidth / 2;
      // const heightHalf = window.innerHeight / 2;
  
      // const style = getComputedStyle(this.text);
      // this.text.style.transform = `translate(${vector.x * widthHalf + widthHalf - parseFloat(style.width) / 2}px, ${-vector.y * heightHalf + heightHalf - parseFloat(style.height) / 2}px)`;
    }

    animate() {
      
      requestAnimationFrame(this.animate.bind(this));
      this.updateTextPosition();

      // Animates the connections between joints
      this.base2PelvisR = this.animateBone(this.base2PelvisR, this.base_pelvis, this.right_hip);
      this.base2PelvisL = this.animateBone(this.base2PelvisL, this.base_pelvis, this.left_hip);

      this.pelvis2hipR = this.animateBone(this.pelvis2hipR, this.right_pelvis, this.right_hip);
      this.pelvis2hipL = this.animateBone(this.pelvis2hipL, this.left_pelvis, this.left_hip);
      
      this.hip2KneeR = this.animateBone(this.hip2KneeR, this.right_hip, this.right_knee);
      this.hip2KneeL = this.animateBone(this.hip2KneeL, this.left_hip, this.left_knee);

      this.knee2AnkleR = this.animateBone(this.knee2AnkleR, this.right_knee, this.right_ankle);
      this.knee2AnkleL = this.animateBone(this.knee2AnkleL, this.left_knee, this.left_ankle);

      this.ankle2HeelR = this.animateBone(this.ankle2HeelR, this.right_ankle, this.right_heel);
      this.ankle2HeelL = this.animateBone(this.ankle2HeelL, this.left_ankle, this.left_heel);

      this.heel2ToeR = this.animateBone(this.heel2ToeR, this.right_heel, this.right_toe);
      this.heel2ToeL = this.animateBone(this.heel2ToeL, this.left_heel, this.left_toe);

      this.toe2AnkleR = this.animateBone(this.toe2AnkleR, this.right_toe, this.right_ankle);
      this.toe2AnkleL = this.animateBone(this.toe2AnkleL, this.left_toe, this.left_ankle);

      this.renderer.render(this.scene, this.camera);
    }
  
    //** Fetching data functions **/

    // Function to update the position of each joint
    updateData(data) {
       document.getElementById("data-display").textContent = "X =  " + 
       data.right_pelvis_z.toFixed(2);

        // Sets each articulation coord 
        const joints = ['pelvis', 'hip', 'knee', 'ankle', 'heel', 'toe'];
        const sides = ['left', 'right'];
    
        for (const side of sides) {
            for (const joint of joints) {
                for (const axis of ['x', 'y', 'z']) {
                    const propertyName = `${side}_${joint}_${axis}`;
                    const position = data[propertyName];
                    this[`${side}_${joint}`].position[axis] = position;
                }
            }
        }
    }

    // Function to continuously fetch data from the flask server
    fetchData() { 
        // Fetch data
        fetch("/get_data")
            .then((response) => response.json())
            .then((data) => {this.updateData(data);})
            .catch((error) => console.error("Error:", error));
                
        setTimeout(() => this.fetchData(), 100); // Milliseconds
    }
}



// Starts all the program
const threeDScene = new ThreeDScene();
