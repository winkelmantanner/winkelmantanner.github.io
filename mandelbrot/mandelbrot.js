
const WIDTH = 500;
const HEIGHT = 500;

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

function draw_mandelbrot_set([center_re, center_im], scale) {
  let ctx = document.getElementById('theCanvas').getContext('2d');
  ctx.fillStyle = 'rgb(200, 200, 200)';
  ctx.fillRect(0, 0, WIDTH, HEIGHT);
  ctx.fillStyle = 'rgb(0, 0, 0)';
  for(let x = -WIDTH / 2; x < WIDTH / 2; x++) {
    for(let y = -HEIGHT / 2; y < HEIGHT / 2; y++) {
      const re = x * scale + center_re;
      const im = y * scale + center_im;
      if(is_in_mandelbrot_set([re, im])) {
        ctx.fillRect(x + (WIDTH / 2), y + (HEIGHT / 2), 1, 1);
      }
    }
  }
  const min_re = (-WIDTH / 2) * scale;
  const max_re = (WIDTH / 2) * scale;
  const min_im = (-HEIGHT / 2) * scale;
  const max_im = (HEIGHT / 2) * scale;
  return {min_re, max_re, min_im, max_im};
}

window.onload = function() {
  let dimensions = draw_mandelbrot_set([0, 0], 0.005);
  document.getElementById('min_re').innerHTML = String(dimensions.min_re);
  document.getElementById('max_re').innerHTML = String(dimensions.max_re);
  document.getElementById('min_im').innerHTML = String(dimensions.min_im);
  document.getElementById('max_im').innerHTML = String(dimensions.max_im);
};