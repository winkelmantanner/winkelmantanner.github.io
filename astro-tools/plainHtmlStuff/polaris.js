

const NUM_STARS_LIMIT = 5000; // The number of stars visible to the naked eye is about 5000.

const POLARIS_DISTANCE_FROM_POLE_DEGREES = 0.75;
const POLARIS_RANK = 49;
const POLARIS_DISTANCE_FROM_CIRCLE_DEGREES = 0.45;

const EARTH_TILT_DEGREES = 23.5;

function getProbabilityByCalculation(include_both_poles, N) {
  // include_both_poles: boolean
  //  if true, stars near either pole will be considered
  //  if false, stars near only one pole will be considered even though stars in both hemispheres are included in the ranking of stars

  // N: Number
  //   The pole star quality function must be 1 / (rank * distance_from_pole^N)

  const r_p = POLARIS_DISTANCE_FROM_POLE_DEGREES * Math.PI / 180;
  let p_not = 1;
  for(let rank = 1; rank <= NUM_STARS_LIMIT; rank++) {
    const max_dist_from_pole = Math.pow(POLARIS_RANK * Math.pow(r_p, N) / rank, 1.0 / N);
    const area_within_max_dist = 2 * Math.PI * (1 - Math.cos(max_dist_from_pole));
    p_not *= 1 - (area_within_max_dist / (4 * Math.PI));
  }
  if(include_both_poles) {
    p_not *= p_not;
  }
  return 1 - p_not;
}

function getProbabilityBySimulation(num_rounds, include_both_poles, quality_function) {
  // num_rounds: the number of rounds to run to get the probability.  Go at least 10000 for accuracy.

  // include_both_poles: boolean
  //  if true, stars near either pole will be considered
  //  if false, stars near only one pole will be considered even though stars in both hemispheres are included in the ranking of stars

  // quality_function: (rank, radius) => Number
  //   This function is called for each star.
  //   The higher the number, the better the star is as a pole star.

  const polaris_quality = quality_function(POLARIS_RANK, POLARIS_DISTANCE_FROM_POLE_DEGREES * Math.PI / 180);

  let num_rounds_with_better_pole_star_than_polaris = 0;
  for(let round_index = 0; round_index < num_rounds; round_index++) {
    let found_better_pole_star = false;
    for(let star_index = 0; star_index < NUM_STARS_LIMIT; star_index++) {
      let x = 0;
      let y = 0;
      let z = 0;
      let distance_squared = 0;
      while(x*y*z === 0 || distance_squared >= 1) {
        x = (Math.random() * 2) - 1;
        y = (Math.random() * 2) - 1;
        z = (Math.random() * 2) - 1;
        distance_squared = (x*x) + (y*y) + (z*z);
      }
      // <x, y, z> is now guaranteed to be in the unit sphere.
      // Also, x, y, and z are guaranteed to be nonzero.

      if(include_both_poles || z > 0) {
        const quality = quality_function(star_index + 1, Math.atan2(Math.sqrt((x * x) + (y * y)), Math.abs(z)));
        if(quality >= polaris_quality) {
          found_better_pole_star = true;
          // console.log(x, y, z);
          break;
        }
      }
    }
    if(found_better_pole_star) {
      num_rounds_with_better_pole_star_than_polaris++;
    }
  }

  return num_rounds_with_better_pole_star_than_polaris * 1.0 / num_rounds;
}



function getAllTimeProbByCalculation(include_both_poles, N) {
  // I am not confident that this function gets the right answer.
  let p_not = 1;
  for(let rank = 1; rank <= NUM_STARS_LIMIT; rank++) {
    const max_angle_from_circle = Math.pow(POLARIS_RANK / rank, 1.0 / N) * POLARIS_DISTANCE_FROM_CIRCLE_DEGREES * Math.PI / 180;
    const prob =
      2 * max_angle_from_circle * 2 * Math.PI * Math.sin(EARTH_TILT_DEGREES * Math.PI / 180)
      / (4 * Math.PI)
    ;
    // console.log("rank", rank, "prob", prob, "dist degrees", max_angle_from_circle * 180 / Math.PI);

    p_not *= (1 - prob);
  }
  if(include_both_poles) {
    p_not *= p_not;
  }
  return 1 - p_not;
}

// I have confirmed the number I get in the video, 0.76%.
// That is the probability of one of the top 100 stars in the entire sphere being within 1 degree of the north pole.
// console.log(getProbabilityBySimulation(10000, false, (rank, radius) => rank <= 100 && radius < Math.PI / 180 ? 1 : 0));

const N = 2;
console.log(getProbabilityBySimulation(10000, true, (rank, radius) => 1 / (rank * Math.pow(radius, N))));
console.log(getProbabilityByCalculation(true, N));
// console.log(getAllTimeProbByCalculation(true, N));
