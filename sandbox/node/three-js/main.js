import "./style.css";
import * as THREE from "three";
import { OrbitControls } from "three/examples/jsm/controls/OrbitControls.js";
import { FlyControls } from 'three/addons/controls/FlyControls.js';

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
  const camera = new THREE.OrthographicCamera( vw / - 2, vw / 2, vh / 2, vh / - 2);
  camera.position.set(0, 1000, 1000);

  // render
  const renderer = new THREE.WebGLRenderer();
  renderer.setSize(vw, vh);
  renderer.setAnimationLoop(animate);
  document.body.appendChild(renderer.domElement);

  // resize
  window.addEventListener("resize", () => {
    [vw, vh] = [window.innerWidth, window.innerHeight];
    camera.left   = vw / -2;
    camera.right  = vw / 2;
    camera.top    = vh / 2;
    camera.bottom = vh / -2;
    camera.updateProjectionMatrix();
    renderer.setSize(vw, vh);
  });

  // orbit movement
  const controls = new OrbitControls(camera, renderer.domElement);

  return [scene, camera, renderer, controls];
}

const [scene, camera, renderer, controls] = init();

// mesh
const geometry = new THREE.SphereGeometry(10)
const material = new THREE.MeshStandardMaterial({
  color: colors.yellow,
});
const mesh = new THREE.Mesh(geometry, material);
scene.add(mesh);

const curve3 = new THREE.EllipseCurve(
  0,
  75, // ax, aY
  75,
  150, // xRadius, yRadius
);

const points3 = curve3.getPoints(50);
const geometry3 = new THREE.BufferGeometry().setFromPoints(points3);
const material3 = new THREE.LineBasicMaterial({ color: colors.white });

// Create the final object to add to the scene
const ellipse = new THREE.Line(geometry3, material3);
scene.add(ellipse);

// light
const light = new THREE.PointLight(0xffffff, 10000, 1000);
light.position.set(0, 100, 100);
scene.add(light);


const clock = new THREE.Clock();
function animate() {
  const t = clock.elapsedTime;
  const dt = clock.getDelta();

  controls.update(dt);
  renderer.render(scene, camera);
}
