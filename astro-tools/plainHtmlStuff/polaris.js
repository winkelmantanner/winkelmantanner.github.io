

const NUM_STARS_LIMIT = 5000; // The number of stars visible to the naked eye is about 5000.

const POLARIS_DISTANCE_FROM_POLE_DEGREES = 0.75;
const POLARIS_RANK = 49;

function getProbabilityBetterThanPolaris(num_rounds, include_both_poles, quality_function) {
  // num_rounds: the number of rounds to run to get the probability.  Go at least 10000 for accuracy.

  // include_both_poles: boolean
  //  if true, stars near either pole will be considered
  //  if false, stars near only one pole will be considered even though stars in both hemispheres are included in the ranking of stars

  // quality_function: (rank, radius_squared) => Number
  //   The higher the number, the better the star is as a pole star.
  //   Make sure that if the function is of the form 1 / (rank * radius^N) then N > 1.

  const polaris_quality = quality_function(POLARIS_RANK, Math.pow(POLARIS_DISTANCE_FROM_POLE_DEGREES * Math.PI / 180, 2));

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

        // const r = Math.sqrt((x * x) + (y * y)) / z;

        const quality = quality_function(star_index + 1, ((x * x) + (y * y)) / (z * z));

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

// I have confirmed the number I get in the video, 0.76%.
// That is the probability of one of the top 100 stars in the entire sphere being within 1 degree of the north pole.
// console.log(getProbabilityBetterThanPolaris(10000, false, (rank, radius_squared) => (rank <= 100 && radius_squared < Math.pow(Math.PI / 180, 2)) ? 1 : 0));

console.log(getProbabilityBetterThanPolaris(10000, true, (rank, radius_squared) => 1 / (rank * radius_squared)));

