

const NUM_STARS_LIMIT = 4000; // ancient astronomers counted the number of stars to be near 4000


function getProbabilityBetterThanPolaris(num_rounds, quality_function) {
  // num_rounds: the number of rounds to run to get the probability.  Go at least 10000 for accuracy.

  // quality_function: (rank, radius_squared) => Number
  //   The higher the number, the better the star is as a pole star.
  //   Make sure that if the function is of the form 1 / (rank * radius^N) then N > 1.

  const polaris_quality = quality_function(48 + 1, Math.pow(0.75 * Math.PI / 180, 2));

  let num_rounds_with_better_pole_star_than_polaris = 0;

  for(let round_index = 0; round_index < num_rounds; round_index++) {
    let found_better_pole_star = false;
    for(let star_index = 0; star_index < NUM_STARS_LIMIT; star_index++) {
      let x = 0;
      let y = 0;
      let z = 0;
      let product = 0;
      while(product === 0 || product >= 1) {
        x = (Math.random() * 2) - 1;
        y = (Math.random() * 2) - 1;
        z = (Math.random() * 2) - 1;
        product = x * y * z;
      }

      if(z > 0) {
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

console.log(getProbabilityBetterThanPolaris(10000, (rank, radius_squared) => (rank <= 100 && radius_squared < Math.pow(Math.PI / 180, 2)) ? 1 : 0/*1 / (rank * radius_squared)*/));

