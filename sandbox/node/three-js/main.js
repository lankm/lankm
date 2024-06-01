import "./style.css";
import * as THREE from "three";

const scene = new THREE.Scene();

// mesh
const geometry = new THREE.SphereGeometry(3, 64, 64);
const material = new THREE.MeshStandardMaterial({ color: "#00ff00" });
const mesh = new THREE.Mesh(geometry, material);
scene.add(mesh);

// light
const light = new THREE.PointLight(0xffffff, 100, 100);
light.position.set(0, 10, 10);
scene.add(light);

// camera
let [vw, vh] = [window.innerWidth, window.innerHeight];
const camera = new THREE.PerspectiveCamera(50, vw / vh, 0.1, 100);
camera.position.z = 10;
scene.add(camera);

// render
const canvas = document.querySelector(".webgl");
const renderer = new THREE.WebGLRenderer({ canvas });
renderer.setSize(vw, vh);

// resize
window.addEventListener("resize", () => {
  [vw, vh] = [window.innerWidth, window.innerHeight];
  camera.aspect = vw / vh;
  camera.updateProjectionMatrix();
  renderer.setSize(vw, vh);
});

// render loop
const loop = () => {
  camera.rotation.z += 0.01;
  renderer.render(scene, camera);
  window.requestAnimationFrame(loop);
};
loop();
