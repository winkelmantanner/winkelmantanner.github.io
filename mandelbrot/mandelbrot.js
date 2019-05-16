
const WIDTH = 500;
const HEIGHT = 500;


const TARGET_RADIUS = 10;
let targetX = -TARGET_RADIUS;
let targetY = -TARGET_RADIUS;

let theCanvas;
let ctx;
let data = {};
let dimensions;

let center_re = 0;
let center_im = 0;
let scale = 0.01;

function complex_multiply([re1, im1], [re2, im2]) {
  return [(re1 * re2) - (im1 * im2), (im1 * re2) + (re1 * im2)];
}

function complex_add([re1, im1], [re2, im2]) {
  return [re1 + re2, im1 + im2];
}

function complex_magnitude_squared([re, im]) {
  return (re * re) + (im * im);
}

function is_in_mandelbrot_set([re, im]) {
  let current = [0, 0];
  let max_magnitude_squared = 0;
  let k = 0;
  let j = 0;
  const CONVERGE_K = 50;
  while(k < CONVERGE_K && j < 200) {
    current = complex_add(complex_multiply(current, current), [re, im]);
    if(!isFinite(current[0]) || !isFinite(current[1])) {
      k = 0;
      break;
    }
    const mag_squared = complex_magnitude_squared(current);
    if(mag_squared > max_magnitude_squared) {
      max_magnitude_squared = mag_squared;
      k = 0;
    }
    k++;
    j++;
  }
  return k >= CONVERGE_K;
}
function compute_mandelbrot_set() {
  for(let x = -WIDTH / 2; x < WIDTH / 2; x++) {
    for(let y = -HEIGHT / 2; y < HEIGHT / 2; y++) {
      const re = x * scale + center_re;
      const im = y * scale + center_im;
      if(!(re in data)) {
        data[re] = {};
      }
      data[re][im] = is_in_mandelbrot_set([re, im]);
    }
  }
  // const min_re = (-WIDTH / 2) * scale;
  // const max_re = (WIDTH / 2) * scale;
  // const min_im = (-HEIGHT / 2) * scale;
  // const max_im = (HEIGHT / 2) * scale;
  // dimensions = {min_re, max_re, min_im, max_im};
}
function draw_mandelbrot_set() {
  ctx.fillStyle = 'rgb(200, 200, 200)';
  ctx.fillRect(0, 0, WIDTH, HEIGHT);
  ctx.fillStyle = 'rgb(0, 0, 0)';
  for(let re in data) {
    for(let im in data[re]) {
      if(data[re][im] === true) {
        let x = (re - center_re) / scale;
        let y = (im - center_im) / scale;
        ctx.fillRect(x + (WIDTH / 2), y + (HEIGHT / 2), 1, 1);
      }
    }
  }
}

function canvasOnClick(event) {
  const x = event.offsetX;
  const y = event.offsetY;
  targetX = x;
  targetY = y;
  ctx.strokeStyle = 'red';
  ctx.clearRect(0,0,WIDTH,HEIGHT);
  draw_mandelbrot_set();
  ctx.beginPath();
  ctx.arc(targetX, targetY, TARGET_RADIUS, 0, 6.28);
  ctx.closePath();
  ctx.stroke();
}

function zoomIn() {
  center_re += (targetX - (WIDTH / 2)) * scale;
  center_im += (targetY - (HEIGHT / 2)) * scale;
  scale = scale / 2;
  compute_mandelbrot_set();
  draw();
}

function draw() {
  ctx.clearRect(0,0,WIDTH,HEIGHT);
  draw_mandelbrot_set();
  document.getElementById('min_re').innerHTML = String(center_re + ((-WIDTH / 2) * scale));
  document.getElementById('max_re').innerHTML = String(center_re + ((WIDTH / 2) * scale));
  document.getElementById('min_im').innerHTML = String(center_im + ((-HEIGHT / 2) * scale));
  document.getElementById('max_im').innerHTML = String(center_im + ((HEIGHT / 2) * scale));
}

window.onload = function() {
  theCanvas = document.getElementById('theCanvas');
  ctx = theCanvas.getContext('2d');
  theCanvas.onclick = canvasOnClick;
  compute_mandelbrot_set();
  draw();
};