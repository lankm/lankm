import "./style.css";
import * as THREE from "three";
import { OrbitControls } from "three/examples/jsm/controls/OrbitControls.js";

const colors = {
  black: new THREE.Color(0x000000),
  red: new THREE.Color(0xff0000),
  green: new THREE.Color(0x00ff00),
  blue: new THREE.Color(0x0000ff),
  yellow: new THREE.Color(0xffff00),
  magenta: new THREE.Color(0xff00ff),
  cyan: new THREE.Color(0x00ffff),
  white: new THREE.Color(0xffffff),
};
const pi = Math.PI;
let [vw, vh] = [window.innerWidth, window.innerHeight];

function init() {
  const scene = new THREE.Scene();

  // camera
  const camera = new THREE.PerspectiveCamera(50, vw / vh, 0.1, 1000);
  camera.position.set(0, 20, 100);

  // render
  const renderer = new THREE.WebGLRenderer();
  renderer.setSize(vw, vh);
  renderer.setAnimationLoop(animate);
  document.body.appendChild(renderer.domElement);

  // resize
  window.addEventListener("resize", () => {
    [vw, vh] = [window.innerWidth, window.innerHeight];
    camera.aspect = vw / vh;
    camera.updateProjectionMatrix();
    renderer.setSize(vw, vh);
  });

  // orbit movement
  const controls = new OrbitControls(camera, renderer.domElement);
  controls.enableDamping = true;

  return [scene, camera, renderer, controls];
}

const [scene, camera, renderer, controls] = init();

// mesh
const geometry = new THREE.BoxGeometry(10, 10, 10);
const material = new THREE.MeshStandardMaterial({
  color: colors.red,
});
const mesh = new THREE.Mesh(geometry, material);
scene.add(mesh);

const lineMaterial = new THREE.LineBasicMaterial({ color: colors.white });
const points = [];
points.push(new THREE.Vector3(-10, 0, 0));
points.push(new THREE.Vector3(0, 10, 0));
points.push(new THREE.Vector3(10, 0, 0));
const lineGeometry = new THREE.BufferGeometry().setFromPoints(points);
const line = new THREE.Line(lineGeometry, lineMaterial);
scene.add(line);

// light
const light = new THREE.PointLight(0xffffff, 100, 100);
light.position.set(0, 10, 10);
scene.add(light);

// grid
const gridHelper = new THREE.GridHelper(100, 100);
scene.add(gridHelper);

const clock = new THREE.Clock();
function animate() {
  const t = clock.elapsedTime;
  const dt = clock.getDelta();

  controls.update(dt);
  renderer.render(scene, camera);
}
