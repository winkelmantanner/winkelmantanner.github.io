// must be executed after data.js

const CLOSENESS_TO_1_THRESHOLD = 0.01;

const LOGARITHMIC = 'logarithmic';
const LINEAR = 'linear';
const options = {
  error_threshold: {
    value: 0.01,
    title: "Error Threshold",
    description: "Coincidences whose error is less than this will be reported.",
    max: 0.05,
    min: 0.0005,
    scale: LOGARITHMIC
  },
  duplicate_threshold: {
    value: 0.005,
    title: "Duplicate Threshold",
    description: "If two coincidences have exactly the same error, they are probably different ways of expressing the same thing.  This tool removes such duplicates.  This value is the maximum relative difference between errors that is considered duplicate.",
    max: 0.05,
    min: 0.0005,
    scale: LOGARITHMIC
  },
  max_exponent_magnitude: {
    value: 15,
    title: "Max Exponent Magnitude",
    description: "If the absolute value of the exponent on the 10 is greater than this, the coincidence will not be reported.",
    max: 15,
    min: 0,
    step: 1,
    scale: LINEAR
  },
  require_dimensional_consistency: {
    value: true,
    title: "Require Dimensional Consistency",
    description: "Coincidences that depend on the definition of a unit will only be reported if this is false."
  },
  include_ratios_close_to_1: {
    value: false,
    title: "Include Ratios Close To 1",
    description: "If one of the ratios of two quantities is close to 1, it is likely that the quantities are expected to be very close or equal to each other.  For example, it is expected that Pluto's orbital period is equal to Charon's orbital period since Pluto and Charon are mutually tidally locked.  With this box checked, if either of the divisions in the equation (a/b)=(10^n)*(c/d) is close to 1, the coincidence will not be reported.  This tool considers a ratio close to 1 if abs(ln(ratio)) < " + String(CLOSENESS_TO_1_THRESHOLD) + "."
  },
  allow_zero_error: {
    value: false,
    title: "Allow Zero Error",
    description: "If the error is exactly 0, then it is probably not a coincidence but expected.  For example, this is expected with zero error: (moon radius / moon diameter) = (planet radius / planet diameter).  Coincidences with zero error will be reported only if this box is checked."
  },
  field_enabled: {} // keys should be gotten by get_unique_field_key
};

function is_usable_data_point(value) {
  return typeof value === 'object'
    && value instanceof DataPoint
    && typeof value.value === 'number'
    && value.num_significant_figures >= 2;
}

function get_unique_field_key(table_element_id, attribute_key) {
  return table_element_id + " " + attribute_key;
}

function push_usable_enabled_attributes(usable_data, object, table_element_id) {
  // table_element_id must be the id of the table element in the HTML
  for(const attribute_key in object) {
    if(options.field_enabled[get_unique_field_key(table_element_id, attribute_key)] !== false
      && is_usable_data_point(object[attribute_key])
    ) {
      usable_data.push({
        table_element_id,
        object_name: object.name.value,
        attribute_key,
        base_unit_attribute_key: AstroObject.get_base_unit_attribute_key(attribute_key),
        value: object[attribute_key].value,
        base_unit_value: AstroObject.get_base_unit_value(attribute_key, object[attribute_key].value),
        base_unit: AstroObject.get_base_unit(attribute_key)
      });
    }
  }
}

function find_coincidences() {
  const coincidences = [];
  let num_comparisons = 0;
  for(const moon_name of moon_data.name) {
    const moon = new Moon(moon_name);
    const planet = new Planet(moon.planet.value);
    const star = new Star(planet.star.value);

    const error_values = [];

    const usable_data = [];

    push_usable_enabled_attributes(usable_data, moon, 'moons');
    push_usable_enabled_attributes(usable_data, planet, 'planets');
    push_usable_enabled_attributes(usable_data, star, 'stars');

    for(let l_num_index = 0; l_num_index < usable_data.length; l_num_index++) {
      for(let r_num_index = 1 + l_num_index; r_num_index < usable_data.length; r_num_index++) {
        for(let l_den_index = 0; l_den_index < usable_data.length; l_den_index++) {
          for(let r_den_index = 0; r_den_index < usable_data.length; r_den_index++) {
            if(  l_num_index !== r_num_index
              && l_num_index !== l_den_index
              && r_num_index !== r_den_index
              && l_den_index !== r_den_index
            ) {
              const l_num = usable_data[l_num_index];
              const l_den = usable_data[l_den_index];
              const r_num = usable_data[r_num_index];
              const r_den = usable_data[r_den_index];
              if(!options.require_dimensional_consistency.value
                || (
                  l_num.base_unit === l_den.base_unit
                  && r_num.base_unit === r_den.base_unit
                )
              ) {
                const l_base_unit_value = l_num.base_unit_value / l_den.base_unit_value;
                const r_base_unit_value = r_num.base_unit_value / r_den.base_unit_value;

                // eliminate stuff like (aphelion)/(semimajor axis) and (rotation period)/(length of day) 
                if(options.include_ratios_close_to_1.value
                  || (
                    Math.abs(Math.log(Math.abs(l_base_unit_value))) > CLOSENESS_TO_1_THRESHOLD
                    && Math.abs(Math.log(Math.abs(r_base_unit_value))) > CLOSENESS_TO_1_THRESHOLD
                  )
                ) {
                  let abs_ratio = Math.abs(l_base_unit_value / r_base_unit_value);

                  let n = 0;

                  while(abs_ratio > 5) {
                    abs_ratio /= 10;
                    n++;
                  }
                  while(abs_ratio < 0.2) {
                    abs_ratio *= 10;
                    n--;
                  }

                  num_comparisons++;

                  const error = Math.abs(Math.log(Math.abs(abs_ratio)));

                  if(
                    (
                      error !== 0 // error !== 0 eliminates coincidences caused by duplicate values
                      || options.allow_zero_error.value
                    )
                    && error < options.error_threshold.value
                    && Math.abs(n) <= options.max_exponent_magnitude.value
                  ) {
                    let is_duplicate = false;
                    for(const e_val of error_values) {
                      if(Math.abs(Math.log(e_val / error)) < options.duplicate_threshold.value) {
                        // if they have the same error value, then they are probably duplicate coincidences
                        is_duplicate = true;
                      }
                    }
                    if(!is_duplicate) {
                      coincidences.push({l_num, l_den, r_num, r_den, base_unit_exponent: n, error});
                      error_values.push(error);
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return {coincidences, num_comparisons};
}




module.exports = {
  LINEAR,
  LOGARITHMIC,
  options,
  find_coincidences
};