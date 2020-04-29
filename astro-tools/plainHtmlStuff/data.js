const star_data = {
  "name": [                   "sun"],
  "mass (10^24 kg)": [        "1988500"],
  "radius (km)": [            "695700"],
  "rotation period (hours)": ["609.12"]
};
const planet_data = {
  "name": [                       "mercury", "venus",   "earth",  "mars", "jupiter", "saturn", "uranus", "neptune","pluto"],
  "star": [                       "sun",     "sun",     "sun",    "sun",   "sun",    "sun",    "sun",    "sun",    "sun"],
  "mass (10^24 kg)": [            "0.330",   "4.87",    "5.97",   "0.642", "1898",   "568",    "86.8",   "102",    "0.0146"], // 10^24 kg
  "equatorial diameter (km)": [   "4879",    "12104",   "12756",  "6792",  "142984", "120536", "51118",  "49528",  "2377"], // km
  "polar diameter (km)": [        "4879",    "12104",   "12713.6","6752",  "133709", "108728", "49946",  "48682",  "2377"], // km
  "semimajor axis (10^6 km)": [   "57.9",    "108.2",   "149.6",  "227.9", "778.6",  "1433.5", "2872.5", "4495.1", "5906.4"], // 10^6 km
  "perihelion (10^6 km)": [       "46.0",    "107.5",   "147.1",  "206.6", "740.5",  "1352.6", "2741.3", "4444.5", "4436.8"],
  "aphelion (10^6 km)": [         "69.8",    "108.9",   "152.1",  "249.2", "816.6",  "1514.5", "3003.6", "4545.7", "7375.9"],
  "orbital period (earth days)": ["88.0",    "224.7",   "365.2",  "687.0", "4331",   "10747",  "30589",  "59800",  "90560"], // days
  "orbital velocity (km/s)": [    "47.4",    "35.0",    "29.8",   "24.1",  "13.1",   "9.7",    "6.8",    "5.4",    "4.7"], // km/s
  "rotation period (hours)": [    "1407.6",  "-5832.5", "23.9",   "24.6",  "9.92",    "10.7",   "-17.2",  "16.1",   "-153.3"],
  "length of day (hours)": [      "4222.6",  "2802.0",  "24.0",   "24.7",  "9.92",    "10.7",   "17.2",   "16.1",   "153.3"]
};
const moon_data = {
  "name": [                      "the moon",   "phobos",   "deimos",   "io",      "europa",  "ganymede","callisto", "titan",    "miranda",  "ariel",   "umbriel", "titania", "oberon",    "triton",    "charon"],
  "planet": [                    "earth",      "mars",     "mars",     "jupiter", "jupiter", "jupiter", "jupiter",  "saturn",   "uranus",   "uranus",  "uranus",  "uranus",  "uranus",    "neptune",   "pluto"],
  "mass (10^20 kg)": [           "734.767309", "0.000106", "0.000024", "893.2",   "480.0",   "1481.9",  "1075.9",   "1345.5",   "0.66",     "12.9",    "12.2",    "34.2",    "28.8",      "214",       "15.86"],
  "radius (km)": [               "1737.4",     "12",       "6",        "1821.5",  "1560.8",  "2631.2",  "2410.3",   "2575",     "234",      "578",     "584.7",   "788.9",   "761.4",     "1353.4",    "606"], // volumetric mean for the moon
  "semimajor axis (10^3 km)": [  "384.399",    "9.378",    "23.459",   "421.9",   "671.1",   "1070.4",  "1882.7",   "1221.83",  "129.9",    "190.9",   "266.0",   "436.3",   "583.5",     "354.76",    "19.596"],
  "orbital period (earth days)":["27.321662",  "0.31891",  "1.26244",  "1.769138","3.551181","7.154553","16.689017","15.945421","1.413479", "2.520379","4.144176","8.705867","13.463234", "-5.876854", "6.3872"]
};


// DIGITS is an object like {'0':true, '1':true, ..., '9':true}
const DIGITS = '0123456789'.split('').reduce((acc, char) => {
  acc[char] = true;
  return acc;
}, {});

function randomChoice(arr) {
  return arr[Math.floor(Math.random() * arr.length)];
}

class DataPoint {
  constructor(string) {
    if(isNaN(string)) {
      this.value = string;
      this.num_significant_figures = null;
    } else {
      this.value = Number(string);
      this.num_significant_figures = DataPoint.getNumSignificantFigures(string);
    }
  }

  static getNumSignificantFigures(string) {
    let first_nonzero_index = -1;
    let significant_digit_number = 0;
    let last_significant_digit_number = 0;
    let dp_index = -1;
    for(let index = 0; index < string.length; index++) {
      let char = string[index];
      if(char in DIGITS) {
        if(char !== '0'
          && first_nonzero_index < 0
        ) {
          first_nonzero_index = index;
        }
        if(first_nonzero_index >= 0) {
          significant_digit_number += 1;
        }
        if(char !== '0') {
          last_significant_digit_number = significant_digit_number;
        }
        if(char === '0'
          && dp_index >= 0
          && dp_index < index
        ) {
          last_significant_digit_number = significant_digit_number;
        }
      } else if(char === '.') {
        dp_index = index;
      }
    }
    return last_significant_digit_number;
  }

  truncateToSignificantFigures() {
    this.value = Number(this.value.toPrecision(this.num_significant_figures));
  }

  getScaled(scalar) {
    let d = new DataPoint('0');
    d.value = this.value * scalar;
    d.num_significant_figures = this.num_significant_figures;
    return d;
  }
}


const UNIT_REGEX =     /^.*\((.*)\)$/;
const PRE_UNIT_REGEX = /^(.*)\(.*\)$/;
const SCALE_REGEX = /^10\^(-?[0-9]*)$/;

const GRAVITATIONAL_CONSTANT = 6.67408e-20; // (km^3) / (kg * s^2)

class AstroObject {
  constructor(index, data) {
    this.fill(index, data);
  }

  fill(index, data) {
    for(const key in data) {
      this[key] = new DataPoint(data[key][index]);
    }
  }

  doComputations() {
    if("rotation period (hours)" in this) {
      this["rotation period (days)"] = this["rotation period (hours)"].getScaled(1.0 / 24);
      delete this["rotation period (hours)"];
      this["rotation period (days)"].truncateToSignificantFigures();
    }
    if("length of day (hours)" in this) {
      this["length of day (days)"] = this["length of day (hours)"].getScaled(1.0 / 24);
      delete this["length of day (hours)"];
      this["length of day (days)"].truncateToSignificantFigures();
    }
    for(const prefix of ['', 'polar ', 'equatorial ']) {
      if((prefix + "radius (km)") in this && !((prefix + "diameter (km)") in this)) {
        this[prefix + "diameter (km)"] = this[prefix + "radius (km)"].getScaled(2);
      } else if((prefix + "diameter (km)") in this && !((prefix + "radius (km)") in this)) {
        this[prefix + "radius (km)"] = this[prefix + "diameter (km)"].getScaled(0.5);
      }
    }
  }

  static get_base_unit_value(attribute_key, value) {
    // returns a number giving the value of the quantity in the base unit
    // be sure to pass both parameters:
    //   attribute_key: string
    //   value: number
    const complete_unit = AstroObject.get_complete_unit(attribute_key);
    const scale_part = complete_unit.split(' ')[0];
    let exponent = 0;
    if(scale_part !== undefined && SCALE_REGEX.test(scale_part)) {
      exponent = Number(scale_part.match(SCALE_REGEX)[1]);
    }
    let val = value;
    if(exponent !== 0) {
      val = value * Math.pow(10, exponent)
    }
    return val;
  }
  static get_base_unit_attribute_key(attribute_key) {
    // returns a string giving the attribute key after removing any scale (for example: 10^20)
    // so AstroObject.get_base_unit_attribute_key('z (10^3 q)') would return 'z (q)'
    const pre_unit_string = attribute_key.match(PRE_UNIT_REGEX)[1];
    return pre_unit_string + " (" + AstroObject.get_base_unit(attribute_key) + ")";
  }

  static get_complete_unit(attribute_key) {
    // returns a string giving the unit of the passed attribute key, including the scale
    // so AstroObject.get_complete_unit('z (10^3 q)') would return '10^3 q'
    let complete_unit_string = null;
    if(UNIT_REGEX.test(attribute_key)) {
      complete_unit_string = attribute_key.match(UNIT_REGEX)[1];
    }
    return complete_unit_string;
  }
  static get_base_unit(attribute_key) {
    // returns a string giving the unit of the passed attribute key, excluding the scale
    // so AstroObject.get_base_unit('z (10^3 q)') would return 'q'
    let base_unit = null;
    const complete_unit_string = AstroObject.get_complete_unit(attribute_key);
    if(complete_unit_string !== null) {
      base_unit = complete_unit_string.split(' ').reduce((_, el) => el, null);
    }
    return base_unit;
  }
  messWith() {
    this.name.value = (Math.random() * 1e5).toFixed(0) + "-" + this.name.value;
    for(const key in this) {
      if(typeof this[key].value === 'number') {
        this[key].value = this[key].value * Math.exp(Math.random() - 0.5);
        this[key].truncateToSignificantFigures();
      }
    }
  }
}

class Star extends AstroObject {
  constructor(name, is_random=false) {
    const index = star_data.name.indexOf(name.toLowerCase());
    if(-1 == index) {
      throw "Star::constructor Unable to find star with name '" + String(name.toLowerCase()) + "'";
    }
    super(index, star_data);
    if(is_random) {
      this.messWith();
    }
    this.doComputations();
  }
  static getRandom() {
    return new Star(randomChoice(star_data.name), true);
  }
}
class Planet extends AstroObject {
  constructor(name, is_random=false, star_obj=null) {
    const index = planet_data.name.indexOf(name.toLowerCase());
    if(-1 == index) {
      throw "Planet::constructor Unable to find planet with name '" + String(name.toLowerCase()) + "'";
    }
    super(index, planet_data);
    if(is_random) {
      const eccentricity = (this["aphelion (10^6 km)"].value / this["semimajor axis (10^6 km)"].value) - 1;
      this.messWith();
      if("equatorial diameter (km)" in this) {
        // We need to make the equatorial diameter reasonble given the polar diameter
        const g = // surface gravitational acceleration in meters per second per second
          GRAVITATIONAL_CONSTANT // (km^3) / (kg * s^2)
          * AstroObject.get_base_unit_value("mass (10^24 kg)", this["mass (10^24 kg)"].value) // kg
          / Math.pow(this["polar diameter (km)"].value / 2, 2) // km^2
          * 1000; // m / km
        const a_c = // equatorial centripetal acceleration in m / s / s
          Math.pow((2 * Math.PI * (this["polar diameter (km)"].value / 2) / (this["rotation period (hours)"].value * 60 * 60)), 2) // (km / s)^2
          / (this["polar diameter (km)"].value / 2)
          * 1000; // m / km
        this["equatorial diameter (km)"].value = this["polar diameter (km)"].value * (g / (g - a_c));
        this["equatorial diameter (km)"].truncateToSignificantFigures();
      }
      if("length of day (hours)" in this) {
        this["length of day (hours)"].value = 1 / ((1 / this["rotation period (hours)"].value) - (1 / (this["orbital period (earth days)"].value * 24)));
        this["length of day (hours)"].truncateToSignificantFigures();
      }
      if("orbital period (earth days)" in this) {
        this["orbital period (earth days)"].value =
          2 * Math.PI
          / Math.sqrt(GRAVITATIONAL_CONSTANT * star_obj["mass (10^24 kg)"].value * 1e24) // / sqrt(km^3 / s^2)
          * Math.pow(this["semimajor axis (10^6 km)"].value * 1e6, 1.5) // * km^1.5
          / (24 * 60 * 60); // / (s / day)
        this["orbital period (earth days)"].num_significant_figures = Math.min(this["semimajor axis (10^6 km)"].num_significant_figures, star_obj["mass (10^24 kg)"].num_significant_figures);
        this["orbital period (earth days)"].truncateToSignificantFigures();
      }
      if(star_obj !== null && star_obj !== undefined) {
        this["star"].value = star_obj.name.value;
      }
      this["aphelion (10^6 km)"].value = (1 + eccentricity) * this["semimajor axis (10^6 km)"].value;
      this["perihelion (10^6 km)"].value = (1 / (1 + eccentricity)) * this["semimajor axis (10^6 km)"].value;
      this["aphelion (10^6 km)"].truncateToSignificantFigures();
      this["perihelion (10^6 km)"].truncateToSignificantFigures();
    }
    this.doComputations();
  }
  static getRandom(star_obj) {
    return new Planet(randomChoice(planet_data.name), true, star_obj);
  }
}
class Moon extends AstroObject {
  constructor(name, is_random=false, planet_obj=null) {
    const index = moon_data.name.indexOf(name.toLowerCase());
    if(-1 == index) {
      throw "Moon::constructor Unable to find moon with name '" + String(name.toLowerCase()) + "'";
    }
    super(index, moon_data);
    if(is_random) {
      this.messWith();
    }
    if(is_random) {
      if("orbital period (earth days)" in this) {
        this["orbital period (earth days)"].value =
          2 * Math.PI
          / Math.sqrt(GRAVITATIONAL_CONSTANT * planet_obj["mass (10^24 kg)"].value * 1e24) // / sqrt(km^3 / s^2)
          * Math.pow(this["semimajor axis (10^3 km)"].value * 1e3, 1.5) // * km^1.5
          / (24 * 60 * 60); // / (s / day)
        // The orbital period is going to have a lot more significant figures than the values it is computed from.  Since these are randomly generated objects, I think that is OK.
        this["orbital period (earth days)"].truncateToSignificantFigures();
      }
    }
    this.doComputations();
    if("semimajor axis (10^3 km)" in this
      && !("orbital velocity (km/s)" in this)
    ) {
      const planet = planet_obj || new Planet(this.planet.value);
      if("mass (10^24 kg)" in planet) {
        this["orbital velocity (km/s)"] = new DataPoint('0');
        this["orbital velocity (km/s)"].value = Math.sqrt(
          GRAVITATIONAL_CONSTANT
          * AstroObject.get_base_unit_value("mass (10^24 kg)", planet["mass (10^24 kg)"].value)
          / AstroObject.get_base_unit_value("semimajor axis (10^3 km)", this["semimajor axis (10^3 km)"].value)
        );
        this["orbital velocity (km/s)"].num_significant_figures = Math.min(planet["mass (10^24 kg)"].num_significant_figures, this["semimajor axis (10^3 km)"].num_significant_figures);
        this["orbital velocity (km/s)"].truncateToSignificantFigures();
      }
    }
    if(planet_obj !== null && planet_obj !== undefined) {
      this["planet"].value = planet_obj["name"].value;
    }
  }
  static getRandom(planet) {
    return new Moon(randomChoice(moon_data.name), true, planet);
  }
}

module.exports = {
  star_data,
  planet_data,
  moon_data,
  DIGITS,
  DataPoint,
  AstroObject,
  Star,
  Planet,
  Moon
};