

class BodesSolution {
  // Model: a + (c * b^n)
  // a is the constant
  // b is the base
  // c is the power_scalar (the scalar multiplied by the power)
  constructor(constant, power_scalar, base) {
    this.constant = constant;
    this.power_scalar = power_scalar;
    this.base = base;
  }
  static getFromConstantAndSemimajorAxisArray(constant, semimajor_axis_array) {
    let rhs = [
      semimajor_axis_array.reduce((sum, semimajor_axis) => sum + Math.log(semimajor_axis - constant), 0),
      semimajor_axis_array.reduce((sum, semimajor_axis, index) => sum + (index * Math.log(semimajor_axis - constant)), 0)
    ];
    let [
      V,
      U
    ] = rhs;
    const M = semimajor_axis_array.length - 1;
    let coefficient_matrix = [
      [M + 1,             M * (M + 1) / 2],
      [M * (M + 1) / 2,   M * (M + 1) * ((2 * M) + 1) / 6]
    ];
    const [Z, X] = coefficient_matrix[0];
    const [Y, W] = coefficient_matrix[1];
    const ln_base = (U - (Y * V / Z)) / (W - (Y * X / Z));
    const ln_scalar = (rhs[0] - (X * ln_base)) / Z;
    const base = Math.exp(ln_base);
    const scalar = Math.exp(ln_scalar);

    return new BodesSolution(constant, scalar, base);
  }
  getPrediction(n) {
    return this.constant + (this.power_scalar * Math.pow(this.base, n));
  }
  testMercurySemimajorAxis(optional_mercury_semimajor_axis) {
    return optional_mercury_semimajor_axis !== undefined && optional_mercury_semimajor_axis !== null;
  }
  getSumOfSquaredError(semimajor_axis_array, optional_mercury_semimajor_axis) {
    let mercury_unsquared_error = 0;
    if(this.testMercurySemimajorAxis(optional_mercury_semimajor_axis)) {
      mercury_unsquared_error = Math.log(optional_mercury_semimajor_axis) - Math.log(this.getPrediction(-Infinity));
    }
    return (mercury_unsquared_error * mercury_unsquared_error) +
      semimajor_axis_array.reduce((sum, semimajor_axis, index) => {
        const prediction = this.getPrediction(index);
        const unsquared_error = Math.log(semimajor_axis) - Math.log(prediction);
        const squared_error = unsquared_error * unsquared_error;
        return sum + squared_error;
      }, 0);
  }
  getMeanSSE(semimajor_axis_array, optional_mercury_semimajor_axis) {
    const sse = this.getSumOfSquaredError(semimajor_axis_array, optional_mercury_semimajor_axis);
    let count = semimajor_axis_array.length;
    if(this.testMercurySemimajorAxis(optional_mercury_semimajor_axis)) {
      count += 1;
    }
    return Math.sqrt(sse / count);
  }
  toString() {
    return String(this.constant) + " + (" + String(this.power_scalar) + " * " + String(this.base) + "^n)";
  }
}

const THRESHOLD = 0.00001;

const NUM_VALUES_TO_TRY_PER_ITERATION = 9;

function solveBodes(semimajor_axis_array_starting_with_venus, optional_mercury_semimajor_axis) {
  const INITIAL_MIN_A = -2 * semimajor_axis_array_starting_with_venus[0];
  let min_a = INITIAL_MIN_A; // a is my name for the constant added to the exponential.  It is the semimajor axis of Mercury in the Titius-Bode Law.
  let max_a = 2 * semimajor_axis_array_starting_with_venus[0];

  while((max_a - INITIAL_MIN_A) / (min_a - INITIAL_MIN_A) > 1 + THRESHOLD) {
    let a_values = Array(NUM_VALUES_TO_TRY_PER_ITERATION)
      .fill(null)
      .map((_, index, array) => min_a + ((max_a - min_a) * index / (array.length - 1)));
    let errors = a_values
      .map(a => {
        const solution = BodesSolution.getFromConstantAndSemimajorAxisArray(a, semimajor_axis_array_starting_with_venus);
        return solution.getSumOfSquaredError(semimajor_axis_array_starting_with_venus, optional_mercury_semimajor_axis);
      });
    
    // console.log(a_values.map((a, i) => [a, errors[i]]));
    let min_error_index = -1;
    let min_error = Infinity;
    for(const index in a_values) {
      if(errors[index] < min_error) {
        min_error_index = Number(index);
        min_error = errors[index];
      }
    }

    min_a = a_values[Math.max(
      0,
      min_error_index - 1
    )];
    max_a = a_values[Math.min(
      NUM_VALUES_TO_TRY_PER_ITERATION - 1,
      min_error_index + 1
    )];
  }

  return BodesSolution.getFromConstantAndSemimajorAxisArray((max_a + min_a) / 2, semimajor_axis_array_starting_with_venus);
}


const TRAPPIST_1_SEMIMAJOR_AXIS_PAIRS_AU = [
  ['b', 0.01154775],
  ['c', 0.01581512],
  ['d', 0.02228038],
  ['e', 0.02928285],
  ['f', 0.03853361],
  ['g', 0.04687692],
  ['h', 0.06193488]
];
const TRAPPIST_1_SEMIMAJOR_AXES_AU = TRAPPIST_1_SEMIMAJOR_AXIS_PAIRS_AU.map(pair => pair[1]);

const SEMIMAJOR_AXIS_PAIRS_10_6_KM = [
  ['mercury', 57.9],
  ['venus', 108.2],
  ['earth', 149.6],
  ['mars', 227.9],
  ['ceres', 414.3],
  ['jupiter', 778.6],
  ['saturn', 1433.5],
  ['uranus', 2872.5],
  ['neptune', 4495.1],
  ['pluto', 5906.4]
];
const SOLAR_SYSTEM_SEMIMAJOR_AXES_10_6_KM = SEMIMAJOR_AXIS_PAIRS_10_6_KM
  .filter(
    pair => pair[0].toLowerCase() !== 'mercury'
    && pair[0].toLowerCase() !== 'neptune'
    && pair[0].toLowerCase() !== 'pluto'
  )
  .map(pair => pair[1]);
const SOLAR_SYSTEM_SEMIMAJOR_AXES_AU = SOLAR_SYSTEM_SEMIMAJOR_AXES_10_6_KM.map(a => a / 149.6);

const MERCURY_SEMIMAJOR_AXIS_AU = 57.9 / 149.6;



// const solution_without_mercury = solveBodes(SOLAR_SYSTEM_SEMIMAJOR_AXES_AU);
// console.log("Solution without Mercury");
// console.log(solution_without_mercury.toString());
// for(const planet_index in SOLAR_SYSTEM_SEMIMAJOR_AXES_AU) {
//   console.log(solution_without_mercury.getPrediction(planet_index), SOLAR_SYSTEM_SEMIMAJOR_AXES_AU[planet_index]);
// }
// console.log(solution_without_mercury.constant, MERCURY_SEMIMAJOR_AXIS_AU);

// const solution_with_mercury = solveBodes(SOLAR_SYSTEM_SEMIMAJOR_AXES_AU, MERCURY_SEMIMAJOR_AXIS_AU);
// console.log("Solution giving -Infinity to Mercury");
// console.log(solution_with_mercury.toString());
// for(const planet_index in SOLAR_SYSTEM_SEMIMAJOR_AXES_AU) {
//   console.log(solution_with_mercury.getPrediction(planet_index), SOLAR_SYSTEM_SEMIMAJOR_AXES_AU[planet_index]);
// }
// console.log(solution_with_mercury.constant, MERCURY_SEMIMAJOR_AXIS_AU);

function el(type) {
  return document.createElement(type);
}


let bodes_solver_state = {
  semimajor_axes: SOLAR_SYSTEM_SEMIMAJOR_AXES_AU.map(a => a),
  mercury_semimajor_axis: MERCURY_SEMIMAJOR_AXIS_AU
};

const INFO_HTML =
    "<h4 style='margin-top: 15px'>Background</h4>"
  + "The Titius-Bode law (or Titus-Bode rule) relates the semimajor axes of the planets in our solar system.  The semimajor axis of an orbit is half of the longest dimension of the orbit, and is a good approximation to the average distance from the orbiting object to the orbited object unless the orbit is highly elliptical.  The Titius-Bode rule says that <br>semimajor axis = <table style='display: inline;'><tr><td style='border: none; border-bottom:solid black 1px;'>(4 + (3 * 2<sup>n</sup>))</td></tr><tr><td style='border: none; text-align: center;'>10</td>​</tr></table> * semimajor axis of earth<br>where n is an integer associated with the planet.  The ratio can be simplified to 0.4 + (0.3 * 2<sup>n</sup>).  n is consecutive for Venus through Uranus.  n is negative infinity for Mercury.  Note that the largest asteroid, Ceres, must be used for n=3.<br>The Titius-Bode rule was formulated like this in the 1700s.  There is a lot of error is this rule, and Neptune does not follow this rule.  I was curious how accurate the original formulation is."
  + "<h4 style='margin-top: 15px'>What is this tool?</h4>"
  + "This tool finds the best values of a, b, and c to match the semimajor axes with this equation: semimajor axis = a + (b<sup>n</sup> * c).  You can enter the semimajor axes and it will find the best values of a, b, and c.  There are also buttons to automatically enter the data from the solar system and TRAPPIST-1, an exoplanet system with 7 known planets.  If you click the solar system button, it will not include Neptune or Pluto.  Neptune is far closer than the Titius-Bode rule predicts.  The Titius-Bode rule works well if Pluto takes n=7 and Neptune is excluded.  If you wish to include Neptune or Pluto, you can edit the data using the buttons below (here is the data you might need: Neptune: 30.05 AU; Pluto: 39.48 AU).  This program uses a computational search for a and logarithmic regression for b and c."
  + "<h4 style='margin-top: 15px'>Findings</h4>"
  + "For our solar system, if both Pluto and Neptune are excluded, the best solution is 0.3935 + (0.3117 * 1.972<sup>n</sup>).  If Pluto is included for n=7, the best solution is 0.3970 + (0.3054 * 1.9876<sup>n</sup>), which is closer to the original formulation.  With TRAPPIST-1, the base of the exponential is only about 1.2 rather than 2.<br><br>";

function putBodesSolverInDiv(div) {
  const result = el('span');
  const planet_table = el('table');
  const innermost_planet_input_box = el('input');
  innermost_planet_input_box.type = 'text';
  innermost_planet_input_box.addEventListener('input', event => {
    bodes_solver_state.mercury_semimajor_axis = Number(event.target.value);
    result.innerHTML = '';
  });
  const title = el('h3');
  title.textContent = "Titius-Bode Solver";
  const info_span = el('span');
  info_span.innerHTML = INFO_HTML;
  div.appendChild(info_span);
  div.appendChild(title);
  const fill_with_solar_system_data_button = el('button');
  fill_with_solar_system_data_button.textContent = 'Fill with solar system data (default)';
  div.appendChild(fill_with_solar_system_data_button);
  const fill_with_trappist_1_data_button = el('button');
  fill_with_trappist_1_data_button.textContent = 'Fill with TRAPPIST-1 data';
  div.appendChild(fill_with_trappist_1_data_button);
  div.appendChild(el('br'));
  const innermost_planet_label = el('span');
  innermost_planet_label.textContent = 'Mercury semimajor axis (leave blank to exclude):';
  div.appendChild(innermost_planet_label);
  div.appendChild(innermost_planet_input_box);
  div.appendChild(el('br'));
  const other_planets_label = el('span');
  other_planets_label.textContent = 'In the following table, enter the semimajor axes of the rest of the planets.  You may use any unit.  All input must use the same unit.';
  div.appendChild(other_planets_label);
  function renderTable() {
    planet_table.innerHTML = '';
    for(const semimajor_axis_index in bodes_solver_state.semimajor_axes) {
      const semimajor_axis = bodes_solver_state.semimajor_axes[semimajor_axis_index];
      const tr = el('tr');
      const td = el('td');
      const semimajor_axis_input = el('input');
      semimajor_axis_input.type = 'text';
      semimajor_axis_input.value = String(semimajor_axis);
      semimajor_axis_input.addEventListener('input', event => {
        bodes_solver_state.semimajor_axes[semimajor_axis_index] = Number(event.target.value);
        result.innerHTML = '';
      });
      td.appendChild(semimajor_axis_input);
      tr.appendChild(td);
      const delete_button = el('button');
      delete_button.textContent = 'Delete';
      delete_button.addEventListener('click', () => {
        const arr = bodes_solver_state.semimajor_axes;
        bodes_solver_state.semimajor_axes = arr
          .slice(0, Number(semimajor_axis_index))
          .concat(arr.slice(Number(semimajor_axis_index) + 1));
        renderTable();
      });
      td.appendChild(delete_button);
      const insert_button = el('button');
      insert_button.textContent = 'Insert Above';
      insert_button.addEventListener('click', () => {
        const arr = bodes_solver_state.semimajor_axes;
        bodes_solver_state.semimajor_axes = arr
          .slice(0, Number(semimajor_axis_index))
          .concat([''])
          .concat(arr.slice(Number(semimajor_axis_index)));
        renderTable();
      });
      td.appendChild(insert_button);
      planet_table.appendChild(tr);
    }
    const insert_button = el('button');
    insert_button.textContent = 'Insert At End';
    insert_button.addEventListener('click', () => {
      bodes_solver_state.semimajor_axes = bodes_solver_state.semimajor_axes.concat(['']);
      renderTable();
    });
    planet_table.appendChild(insert_button);
    result.innerHTML = '';
  }
  function renderBodesLawEditables() {
    renderTable();
    innermost_planet_input_box.value = String(bodes_solver_state.mercury_semimajor_axis);
  }
  fill_with_solar_system_data_button.addEventListener('click', () => {
    bodes_solver_state = {
      semimajor_axes: SOLAR_SYSTEM_SEMIMAJOR_AXES_AU.map(a => a),
      mercury_semimajor_axis: MERCURY_SEMIMAJOR_AXIS_AU
    };
    renderBodesLawEditables();
  });
  fill_with_trappist_1_data_button.addEventListener('click', () => {
    bodes_solver_state = {
      semimajor_axes: TRAPPIST_1_SEMIMAJOR_AXES_AU.map(a => a),
      mercury_semimajor_axis: ''
    };
    renderBodesLawEditables();
  });
  renderBodesLawEditables();
  div.appendChild(planet_table);
  const solve_button = el('button');
  const graph_container = el('div');
  const residual_graph_container = el('div');
  solve_button.style.fontSize = '30px';
  solve_button.textContent = 'Run Solver';
  solve_button.addEventListener('click', () => {
    const solution = solveBodes(bodes_solver_state.semimajor_axes, innermost_planet_input_box.value === '' ? undefined : Number(innermost_planet_input_box.value));
    const has_mercury_value = innermost_planet_input_box.value !== '';
    bodes_solver_state.mercury_semimajor_axis = has_mercury_value ? Number(innermost_planet_input_box.value) : undefined;
    const mean_log_error = solution.getMeanSSE(bodes_solver_state.semimajor_axes, bodes_solver_state.mercury_semimajor_axis);
    result.innerHTML = "prediction = " + solution.toString() + "<br>sqrt(average(ln(prediction / given value) ^ 2)) = " + String(mean_log_error);
    result.appendChild(graph_container);
    result.appendChild(residual_graph_container);
    graph_container.innerHTML = '';
    residual_graph_container.innerHTML = '';
    const main_given_data = [];
    const main_prediction_data = [];
    const residuals_data = [];
    if(has_mercury_value) {
      main_prediction_data.push([-1, solution.getPrediction(-Infinity),        'prediction for n=-Infinity']);
      main_given_data.push([     -1, Number(innermost_planet_input_box.value), 'given value for n=-Infinity']);
      residuals_data.push([      -1, Math.log(solution.getPrediction(-Infinity) / Number(innermost_planet_input_box.value))]);
    }
    bodes_solver_state.semimajor_axes.forEach((semimajor_axis, index) => {
      const prediction = solution.getPrediction(index);
      main_prediction_data.push([     index, prediction,     'prediction for n=' + String(index)]);
      main_given_data.push([     index, semimajor_axis, 'given value for n=' + String(index)]);
      residuals_data.push([index, Math.log(Number(semimajor_axis) / prediction), 'residual for n=' + String(index)]);
    });

    graph_container.appendChild(getLineGraph(
      [main_given_data, main_prediction_data],
      ['given',         'prediction'],
      ['blue',          'brown'],
      'n',
      'semimajor axis'
    ));
    residual_graph_container.appendChild(getBarGraph(
      [residuals_data],
      ['residuals'],
      ['black'],
      'n',
      'ln( given value / prediction )'
    ));
  });
  div.appendChild(solve_button);
  div.appendChild(el('br'));
  div.appendChild(result);
}

