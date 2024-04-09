(this["webpackJsonpastro-tools"]=this["webpackJsonpastro-tools"]||[]).push([[0],{186:function(e,t,a){"use strict";a.r(t);var n=a(0),o=a.n(n),r=a(66),i=a.n(r),s=(a(76),a(6)),l=a(1);const m={name:["sun"],"mass (10^24 kg)":["1988500"],"radius (km)":["695700"],"rotation period (hours)":["609.12"]},c={name:["mercury","venus","earth","mars","jupiter","saturn","uranus","neptune","pluto"],star:["sun","sun","sun","sun","sun","sun","sun","sun","sun"],"mass (10^24 kg)":["0.330","4.87","5.97","0.642","1898","568","86.8","102","0.0146"],"equatorial diameter (km)":["4879","12104","12756","6792","142984","120536","51118","49528","2377"],"polar diameter (km)":["4879","12104","12713.6","6752","133709","108728","49946","48682","2377"],"semimajor axis (10^6 km)":["57.9","108.2","149.6","227.9","778.6","1433.5","2872.5","4495.1","5906.4"],"perihelion (10^6 km)":["46.0","107.5","147.1","206.6","740.5","1352.6","2741.3","4444.5","4436.8"],"aphelion (10^6 km)":["69.8","108.9","152.1","249.2","816.6","1514.5","3003.6","4545.7","7375.9"],"orbital period (earth days)":["88.0","224.7","365.2","687.0","4331","10747","30589","59800","90560"],"orbital velocity (km/s)":["47.4","35.0","29.8","24.1","13.1","9.7","6.8","5.4","4.7"],"rotation period (hours)":["1407.6","-5832.5","23.9","24.6","9.9","10.7","-17.2","16.1","-153.3"],"length of day (hours)":["4222.6","2802.0","24.0","24.7","9.9","10.7","17.2","16.1","153.3"]},u={name:["the moon","phobos","deimos","io","europa","ganymede","callisto","titan","miranda","ariel","umbriel","titania","oberon","triton","charon"],planet:["earth","mars","mars","jupiter","jupiter","jupiter","jupiter","saturn","uranus","uranus","uranus","uranus","uranus","neptune","pluto"],"mass (10^20 kg)":["734.767309","0.000106","0.000024","893.2","480.0","1481.9","1075.9","1345.5","0.66","12.9","12.2","34.2","28.8","214","15.86"],"radius (km)":["1737.4","12","6","1821.5","1560.8","2631.2","2410.3","2575","234","578","584.7","788.9","761.4","1353.4","606"],"semimajor axis (10^3 km)":["384.399","9.378","23.459","421.9","671.1","1070.4","1882.7","1221.83","129.9","190.9","266.0","436.3","583.5","354.76","19.596"],"orbital period (earth days)":["27.321662","0.31891","1.26244","1.769138","3.551181","7.154553","16.689017","15.945421","1.413479","2.520379","4.144176","8.705867","13.463234","-5.876854","6.3872"]},h="0123456789".split("").reduce((e,t)=>(e[t]=!0,e),{});class p{constructor(e){isNaN(e)?(this.value=e,this.num_significant_figures=null):(this.value=Number(e),this.num_significant_figures=p.getNumSignificantFigures(e))}static getNumSignificantFigures(e){let t=-1,a=0,n=0,o=-1;for(let r=0;r<e.length;r++){let i=e[r];i in h?("0"!==i&&t<0&&(t=r),t>=0&&(a+=1),"0"!==i&&(n=a),"0"===i&&o>=0&&o<r&&(n=a)):"."===i&&(o=r)}return n}getScaled(e){let t=new p("0");return t.value=this.value*e,t.num_significant_figures=this.num_significant_figures,t}}const _=/^.*\((.*)\)$/,d=/^(.*)\(.*\)$/,g=/^10\^(-?[0-9]*)$/;class b{constructor(e,t){for(const a in t)this[a]=new p(t[a][e]);"rotation period (hours)"in this&&(this["rotation period (days)"]=this["rotation period (hours)"].getScaled(1/24),delete this["rotation period (hours)"]),"length of day (hours)"in this&&(this["length of day (days)"]=this["length of day (hours)"].getScaled(1/24),delete this["length of day (hours)"]);for(const a of["","polar ","equatorial "])a+"radius (km)"in this&&!(a+"diameter (km)"in this)?this[a+"diameter (km)"]=this[a+"radius (km)"].getScaled(2):a+"diameter (km)"in this&&!(a+"radius (km)"in this)&&(this[a+"radius (km)"]=this[a+"diameter (km)"].getScaled(.5))}static get_base_unit_value(e,t){const a=b.get_complete_unit(e).split(" ")[0];let n=0;void 0!==a&&g.test(a)&&(n=Number(a.match(g)[1]));let o=t;return 0!==n&&(o=t*Math.pow(10,n)),o}static get_base_unit_value_nicer(e,t){return b.get_base_unit_value(t,e[t].value)}static get_base_unit_attribute_key(e){return e.match(d)[1]+" ("+b.get_base_unit(e)+")"}static get_complete_unit(e){let t=null;return _.test(e)&&(t=e.match(_)[1]),t}static get_base_unit(e){let t=null;const a=b.get_complete_unit(e);return null!==a&&(t=a.split(" ").reduce((e,t)=>t,null)),t}}class f extends b{constructor(e){const t=m.name.indexOf(e.toLowerCase());if(-1===t)throw new Error("Star::constructor Unable to find star with name '"+String(e.toLowerCase())+"'");super(t,m)}}class E extends b{constructor(e){const t=c.name.indexOf(e.toLowerCase());if(-1===t)throw new Error("Planet::constructor Unable to find planet with name '"+String(e.toLowerCase())+"'");super(t,c)}}class y extends b{constructor(e){const t=u.name.indexOf(e.toLowerCase());if(-1===t)throw new Error("Moon::constructor Unable to find moon with name '"+String(e.toLowerCase())+"'");if(super(t,u),"semimajor axis (10^3 km)"in this&&!("orbital velocity (km/s)"in this)){const e=new E(this.planet.value);"mass (10^24 kg)"in e&&(this["orbital velocity (km/s)"]=new p("0"),this["orbital velocity (km/s)"].value=Math.sqrt(6.67408e-20*b.get_base_unit_value("mass (10^24 kg)",e["mass (10^24 kg)"].value)/b.get_base_unit_value("semimajor axis (10^3 km)",this["semimajor axis (10^3 km)"].value)),this["orbital velocity (km/s)"].num_significant_figures=3)}}}function k({sunSize:e,moonSize:t,starColor:a}){const n=Math.max(e,t),r=50*t/n,i=50*e/n;return o.a.createElement("div",{style:{backgroundColor:"black",verticalAlign:"middle",display:"flex",width:100,height:100,align:"right"}},o.a.createElement("div",{style:{width:50-r}}),o.a.createElement("div",{style:{backgroundColor:"gray",display:"inline-block",height:2*r,width:r,margin:"auto",borderTopLeftRadius:r,borderBottomLeftRadius:r}}),o.a.createElement("div",{style:{backgroundColor:a||"yellow",display:"inline-block",height:2*i,width:i,margin:"auto",borderTopRightRadius:i,borderBottomRightRadius:i}}),o.a.createElement("div",{style:{width:50-i}}))}const w=[["b",.01154775,1.121],["c",.01581512,1.095],["d",.02228038,.784],["e",.02928285,.91],["f",.03853361,1.046],["g",.04687692,1.148],["h",.06193488,.773]];function v(e){return 6378.1*e/1496e5}function x(e){return o.a.createElement("th",{style:{border:"1px solid black"}},e.children)}function T(e){return o.a.createElement("td",{style:{border:"1px solid black"}},e.children)}function S(e){return o.a.createElement("span",{style:{textTransform:"capitalize"}},e.children)}function M(){const e=[];u.name.forEach(t=>{const a={},n=new y(t),o=new E(n.planet.value),r=new f(o.star.value);a.relationship="moon",a.star_color="yellow",a.moon=n,a.moon_apparent_size_from_planet_center=Math.atan(n["radius (km)"].value/b.get_base_unit_value("semimajor axis (10^3 km)",n["semimajor axis (10^3 km)"].value)),a.moon_apparent_size_from_planet_point_closest_to_moon=Math.atan(n["radius (km)"].value/(b.get_base_unit_value("semimajor axis (10^3 km)",n["semimajor axis (10^3 km)"].value)-o["equatorial radius (km)"].value)),a.sun_apparent_size_from_planet_center=Math.atan(r["radius (km)"].value/b.get_base_unit_value("semimajor axis (10^6 km)",o["semimajor axis (10^6 km)"].value)),a.sun_apparent_size_from_planet_point_closest_to_sun=Math.atan(r["radius (km)"].value/(b.get_base_unit_value("semimajor axis (10^6 km)",o["semimajor axis (10^6 km)"].value)-o["equatorial radius (km)"].value)),a.ratio_from_planet_center=a.moon_apparent_size_from_planet_center/a.sun_apparent_size_from_planet_center,a.ratio_from_planet_point_closest_to_moon=a.moon_apparent_size_from_planet_point_closest_to_moon/a.sun_apparent_size_from_planet_point_closest_to_sun,a.min_error=Math.min(Math.abs(Math.log(a.ratio_from_planet_center)),Math.abs(Math.log(a.ratio_from_planet_point_closest_to_moon))),e.push(a)});for(let t=0;t<w.length;t++)for(let a=0;a<t;a++){const n=w[a],o=w[t],r={relationship:"neighbor",star_color:"red"};r.moon={name:{value:"TRAPPIST-1"+n[0]},planet:{value:"TRAPPIST-1"+o[0]}};const i=o[1]-n[1],s=v(o[2]),l=v(n[2]),m=695700*.121/1496e5;r.moon_apparent_size_from_planet_center=Math.atan(l/i),r.moon_apparent_size_from_planet_point_closest_to_moon=Math.atan(l/(i-s)),r.sun_apparent_size_from_planet_center=Math.atan(m/o[1]),r.sun_apparent_size_from_planet_point_closest_to_sun=Math.atan(m/(o[1]-s)),r.ratio_from_planet_center=r.moon_apparent_size_from_planet_center/r.sun_apparent_size_from_planet_center,r.ratio_from_planet_point_closest_to_moon=r.moon_apparent_size_from_planet_point_closest_to_moon/r.sun_apparent_size_from_planet_point_closest_to_sun,r.min_error=Math.min(Math.abs(Math.log(r.ratio_from_planet_center)),Math.abs(Math.log(r.ratio_from_planet_point_closest_to_moon))),e.push(r)}return e.sort((e,t)=>e.min_error-t.min_error),o.a.createElement("div",null,o.a.createElement("table",null,o.a.createElement("thead",null,o.a.createElement("tr",null,o.a.createElement(x,null,"Related Objects"),o.a.createElement(x,null,"From Planet Center"),o.a.createElement(x,null,"From Planet Closest Point To Moon"))),o.a.createElement("tbody",null,e.map(e=>o.a.createElement("tr",{key:e.moon.name.value+":"+e.moon.planet.value},o.a.createElement(T,null,o.a.createElement(S,null,e.moon.name.value),o.a.createElement("br",null),e.relationship+" of ",o.a.createElement(S,null,e.moon.planet.value)),o.a.createElement(T,null,o.a.createElement("div",{style:{display:"flex",alignItems:"center"}},o.a.createElement(k,{moonSize:e.moon_apparent_size_from_planet_center,sunSize:e.sun_apparent_size_from_planet_center,starColor:e.star_color}),o.a.createElement("ul",null,o.a.createElement("li",null,o.a.createElement(S,null,e.relationship)," angular diameter: ",(2*e.moon_apparent_size_from_planet_center*180/Math.PI).toFixed(3),"\xb0"),o.a.createElement("li",null,"Star angular diameter: ",(2*e.sun_apparent_size_from_planet_center*180/Math.PI).toFixed(3),"\xb0"),o.a.createElement("li",null,"Ratio: ",(e.moon_apparent_size_from_planet_center/e.sun_apparent_size_from_planet_center).toFixed(3))))),o.a.createElement(T,null,o.a.createElement("div",{style:{display:"flex",alignItems:"center"}},o.a.createElement(k,{moonSize:e.moon_apparent_size_from_planet_point_closest_to_moon,sunSize:e.sun_apparent_size_from_planet_point_closest_to_sun,starColor:e.star_color}),o.a.createElement("ul",null,o.a.createElement("li",null,o.a.createElement(S,null,e.relationship)," angular diameter: ",(2*e.moon_apparent_size_from_planet_point_closest_to_moon*180/Math.PI).toFixed(3),"\xb0"),o.a.createElement("li",null,"Star angular diameter: ",(2*e.sun_apparent_size_from_planet_point_closest_to_sun*180/Math.PI).toFixed(3),"\xb0"),o.a.createElement("li",null,"Ratio: ",(e.moon_apparent_size_from_planet_point_closest_to_moon/e.sun_apparent_size_from_planet_point_closest_to_sun).toFixed(3))))))))))}function C({moonDiameterRadians:e,sunDiameterRadians:t}){return o.a.createElement("div",{style:{display:"flex",alignItems:"center"}},o.a.createElement(k,{moonSize:e,sunSize:t}),o.a.createElement("ul",null,o.a.createElement("li",null,"Moon angular diameter: ",(2*e*180/Math.PI).toFixed(3),"\xb0"),o.a.createElement("li",null,"Star angular diameter: ",(2*t*180/Math.PI).toFixed(3),"\xb0"),o.a.createElement("li",null,"Ratio: ",(e/t).toFixed(3))))}function z(){const e=new E("earth"),t=new y("the moon"),a=new f("sun"),n=t["radius (km)"].value,r=a["radius (km)"].value,i=e["equatorial radius (km)"].value,s=b.get_base_unit_value_nicer(e,"semimajor axis (10^6 km)"),l=b.get_base_unit_value_nicer(e,"perihelion (10^6 km)"),m=b.get_base_unit_value_nicer(e,"aphelion (10^6 km)"),c={moon:{maximum:n/(363228.9-i),minimum:n/405400,average:n/(b.get_base_unit_value_nicer(t,"semimajor axis (10^3 km)")-i/2)},sun:{maximum:r/l,minimum:r/m,average:r/s}},u=Object.keys(c).reduce((e,t)=>(e[t]=Object.keys(c[t]).reduce((e,a)=>(e[a]=Math.atan(c[t][a]),e),{}),e),{});return o.a.createElement("div",null,"Maximum moon size to minimum sun size:",o.a.createElement(C,{moonDiameterRadians:u.moon.maximum,sunDiameterRadians:u.sun.minimum}),"Minimum moon size to maximum sun size:",o.a.createElement(C,{moonDiameterRadians:u.moon.minimum,sunDiameterRadians:u.sun.maximum}),"Average moon size to average sun size:",o.a.createElement(C,{moonDiameterRadians:u.moon.average,sunDiameterRadians:u.sun.average}))}var P=a(70);function j(e,t,a,n){return Math.pow(Math.pow(a,t+1)+(t+1)*Math.pow(a,t)*n*-e,1/(t+1))}function R(e,t,a){const n=e(a);let o=t,r=a,i=1/0,s=0;for(;i>1e-6&&s<1e3;){e((r+o)/2)*n>0?r=(r+o)/2:o=(r+o)/2,i=Math.abs((r-o)/o),s++}return(r+o)/2}function I(e,t){return(e/1e9).toFixed(t||1)+"B"}class q extends o.a.Component{constructor(e){super(e),this.state={distance_exponent:0,recession_rate_cm_per_yr:3.8}}render(){const e=new E("earth"),t=new f("sun"),a=new y("the moon"),n=b.get_base_unit_value_nicer(e,"semimajor axis (10^6 km)"),r=a["radius (km)"].value*(n/t["radius (km)"].value),i=a["radius (km)"].value*(n/t["radius (km)"].value)+e["equatorial radius (km)"].value,s=Array(27).fill(0).map((e,t,a)=>45e8*(15-t)/15),l=this.state.recession_rate_cm_per_yr/100/1e3;return o.a.createElement("div",null,o.a.createElement("h3",null,"Recession of moon and eclipses"),o.a.createElement("p",null,"It is widely accepted that the moon is getting farther from earth over billions of years.  The most well accepted recession rate is 3.8 centimeters per year.  However, this has been described as anomalously high.  This number comes from measurements in which a specially shaped mirror on the moon works with a laboratory on earth using a laser to measure distance.  But measurements from other fields, such as palientology and geology, indicate a slower recession rate.  Also, if the moon is receding at 3.8 centimeters per year, based on the physics of tidal recession, it would coincide with earth 1.5 billion years ago, much less than the generally accepted 4.5 billion year age of the earth-moon system. (",o.a.createElement("a",{href:"https://link.springer.com/article/10.1186/2191-2521-1-1"},"source"),")."),o.a.createElement("p",null,"We live on earth in a window of time in which both total and annular eclipses are possible.  The graph below extrapolates the present recession rate relative to the age of the earth-moon system: ",45e8," years.  The rate of tidal recession can be modelled as k / a^n where k is a constant, a is the distance to the moon, and n is an integer.  So da/dt = k / a^n.  This differential equation solves to a = ((n+1) * (k*t + C)) ^ (1/(n+1)), where C is an arbitrary constant.  When trying to find the value of n, I could only find it from a ",o.a.createElement("a",{href:"https://en.wikipedia.org/wiki/Young_Earth_creationism"},"young-earth creationist")," source (",o.a.createElement("a",{href:"https://creation.com/the-moons-recession-and-age"},"https://creation.com/the-moons-recession-and-age"),").  This source says n=6."),o.a.createElement("p",null,o.a.createElement("strong",null,"NOTE:")," the history of the moon's recession almost certainly does NOT look like the graph below!  It is not certain what it does look like, but it is well accepted that the recession rate was not constant in the past.  This extrapolation also ignores a lot of other parameters that could change (such as the eccentricity of the moon's orbit)."),"Slide these sliders to control some of the parameters.",o.a.createElement("div",{style:{textAlign:"center"}},o.a.createElement("input",{type:"range",onChange:e=>{this.setState({distance_exponent:Number(e.target.value)})},value:this.state.distance_exponent,min:"0",max:"8",step:"1"}),o.a.createElement("br",null),"n=",this.state.distance_exponent),o.a.createElement("br",null),o.a.createElement("div",{style:{textAlign:"center"}},o.a.createElement("input",{type:"range",style:{cursor:"pointer"},onChange:e=>{this.setState({recession_rate_cm_per_yr:Number(e.target.value)})},value:this.state.recession_rate_cm_per_yr,min:"0",max:"6",step:"0.05"}),o.a.createElement("br",null),"present recession rate = ",this.state.recession_rate_cm_per_yr," cm/yr"),"From point closest to moon:",o.a.createElement("ul",null,o.a.createElement("li",null,"Annular eclipses become possible ",I(R(e=>i-j(e,this.state.distance_exponent,405400,l),45e8,-45e8),3)," years ago.",o.a.createElement("br",null)),o.a.createElement("li",null,"Total eclipses become impossible ",I(R(e=>i-j(e,this.state.distance_exponent,363228.9,l),45e8,-45e8),3)," years ago.")),"From point at center of earth:",o.a.createElement("ul",null,o.a.createElement("li",null,"Annular eclipses become possible ",I(R(e=>r-j(e,this.state.distance_exponent,405400,l),45e8,-45e8),3)," years ago."),o.a.createElement("li",null,"Total eclipses become impossible ",I(R(e=>r-j(e,this.state.distance_exponent,363228.9,l),45e8,-45e8),3)," years ago.")),o.a.createElement(P.a,{data:{labels:s.map(e=>e.toFixed(0)),datasets:[{label:"Distance at which the moon is the same size as the sun from center of earth",data:s.map(e=>r),pointBackgroundColor:"brown",pointBorderColor:"brown",borderColor:"brown",lineTension:0,fill:!1},{label:"Distance at which the moon is the same size as the sun from point on earth closest to moon",data:s.map(e=>i),pointBackgroundColor:"green",pointBorderColor:"green",borderColor:"green",lineTension:0,fill:!1},{label:"Moon apogee",data:s.map(e=>j(e,this.state.distance_exponent,405400,l)),pointBackgroundColor:"black",pointBorderColor:"black",borderColor:"black",lineTension:0,fill:!1},{label:"Moon perigee",data:s.map(e=>j(e,this.state.distance_exponent,363228.9,l)),pointBackgroundColor:"black",pointBorderColor:"black",borderColor:"black",lineTension:0,fill:!1},{label:"Moon semimajor axis",data:s.map(e=>j(e,this.state.distance_exponent,384400,l)),pointBackgroundColor:"purple",pointBorderColor:"purple",borderColor:"purple",lineTension:0,fill:!1}]},options:{plugins:{title:{display:!0,text:"Extrapolation of Moon Recession Compared to Eclipse Critical Distances"}},scales:{y:{beginAtZero:!0,title:{text:"Moon distance from earth (kilometers)",display:!0}},x:{grid:{color:s.map(e=>0===e?"black":"rgb(175,175,175)"),lineWidth:s.map(e=>0===e?2:1)},ticks:{callback:e=>{const t=s[e];return String(t)===String(45e8)?I(45e8)+" (age)":"0"===String(t)?"0 (now)":I(t)}},title:{text:"Years before present",display:!0}}}}}))}}class B extends o.a.Component{constructor(e){super(e),this.state={is_showing_text:!1}}render(){return o.a.createElement(o.a.Fragment,null,o.a.createElement("button",{onClick:()=>{this.setState({is_showing_text:!this.state.is_showing_text})}},"?"),this.state.is_showing_text?o.a.createElement(o.a.Fragment,null,o.a.createElement("br",null),this.props.content):null)}}function A(e){return o.a.createElement("div",{style:{border:"2px solid black",borderRadius:5,margin:2}},e.children)}class F extends o.a.Component{constructor(e){super(e),this.state={rank:50,distance_from_pole_degrees:.75,distance_exponent_in_quality:2,num_stars_limit:5e3,num_planets_to_simulate:1e4,include_both_poles:!1,result:null}}getProbabilityBySimulation(e,t,a){const n=a(this.state.rank,this.state.distance_from_pole_degrees*Math.PI/180);let o=0;for(let r=0;r<e;r++){let e=!1;for(let o=0;o<this.state.num_stars_limit;o++){let r=0,i=0,s=0,l=0;for(;r*i*s===0||l>=1;)r=2*Math.random()-1,i=2*Math.random()-1,s=2*Math.random()-1,l=r*r+i*i+s*s;if(t||s>0){if(a(o+1,Math.atan2(Math.sqrt(r*r+i*i),Math.abs(s)))>=n){e=!0;break}}}e&&o++}return 1*o/e}getProbabilityByCalculation(e,t){const a=this.state.distance_from_pole_degrees*Math.PI/180;let n=1;for(let o=1;o<=this.state.num_stars_limit;o++){const r=Math.pow(this.state.rank*Math.pow(a,t)/o,1/t);let i=2*Math.PI*(1-Math.cos(r));e&&(i*=2),n*=1-i/(4*Math.PI)}return 1-n}setStateWithResultReset(e){const t={};for(let a in e)t[a]=e[a];t.result=null,this.setState(t)}runSimulation(){this.setState({result:"running simulation ... this usually takes less than 30 seconds"}),setTimeout(()=>{this.setState({result:{sim:this.getProbabilityBySimulation(this.state.num_planets_to_simulate,this.state.include_both_poles,(e,t)=>1/(e*Math.pow(t,this.state.distance_exponent_in_quality))),calc:this.getProbabilityByCalculation(this.state.include_both_poles,this.state.distance_exponent_in_quality)}})},100)}getRangeOption(e,t,a,n,r,i){return o.a.createElement(A,null,t,o.a.createElement(B,{content:a}),o.a.createElement("br",null),o.a.createElement("input",{type:"range",style:{width:"95%"},onChange:t=>{this.setStateWithResultReset({[e]:Number(t.target.value)})},value:this.state[e],min:n,max:r,step:i}),o.a.createElement("br",null),this.state[e])}render(){return o.a.createElement("div",null,o.a.createElement("h3",null,"Probability of Polaris"),o.a.createElement("h4",null,"Background"),o.a.createElement("p",null,"Astronomical objects can be thought of as points on a giant sphere called the ",o.a.createElement("a",{href:"https://en.wikipedia.org/wiki/Celestial_sphere"},"celestial sphere"),". This sphere rotates roughly once per day as the earth spins. There are 2 points on the sphere that are not moved by this rotation: ",o.a.createElement("a",{href:"https://en.wikipedia.org/wiki/Celestial_pole"},"the celestial poles"),". There happens to be an easily visible star very close to the north celestial pole. Because it is so close to the pole, this star is named Polaris."," ",o.a.createElement("a",{href:"https://en.wikipedia.org/wiki/Polaris"},"Polaris")," is roughly the 50th brightest star in the sky (",o.a.createElement("a",{href:"https://en.wikipedia.org/wiki/List_of_brightest_stars"},"source"),"), and it is currently about 0.75 degrees away from the north celestial pole. The position of the pole moves due to ",o.a.createElement("a",{href:"https://en.wikipedia.org/wiki/Axial_precession"},"axial precession"),". According to ",o.a.createElement("a",{href:"https://earthsky.org/brightest-stars/polaris-the-present-day-north-star"},"this source"),", the north celestial pole will come closest to Polaris on March 24, 2100, when the separation will reach its minimum of 0.4245 degrees."),o.a.createElement("h4",null,"About this Simulation"),o.a.createElement("p",null,"I was curious about the probability of having pole star with the quality of Polaris. After struggling with mathematics for a long time, I finally came up with a computer simulation that can provide a meaningful number. This simulation works by generating a lot of hypothetical planets. For each simulated planet, the simulation generates a number of random stars, each in a random direction from the planet. The distribution of the stars is spherical. For each star, the simulation calculates a number indicating the ",o.a.createElement("i",null,"pole star quality")," (or ",o.a.createElement("i",null,"quality"),") of that star. The higher the quality, the better the star is as a pole star. The simulation counts the number of planets that have at least one star of higher quality than Polaris. If you want to see the code, check out ",o.a.createElement("a",{href:"/astro-tools/polaris.py"},"the python implementation"),"."),o.a.createElement("p",null,"This simulation uses the formula ",o.a.createElement("i",null,"quality = 1 / (r * d",o.a.createElement("sup",null,"n"),")")," where r is the brighness rank of the star (for Polaris it is 50), d is the distance from the pole (for Polaris it is 0.75 degrees), and n is a simulation parameter. If n=1, then if the brightest star in the sky was 30\xb0 from the pole, it would be a better pole star than Polaris. So I like to use n=2, but you should try changing n to see what happens."),o.a.createElement("p",null,"After I got the simulation to work, I found a way to mathematically calculate the probability of having a better pole star than Polaris.  The calculation requires a computer but it is much faster than the simulation and it gets the exact value.  This tool shows results from both the calculation and the simulation, so you can see that they match.  The calculated result is more accurate."),o.a.createElement("h4",null,"Findings"),o.a.createElement("p",null,"The probability of having a better pole star than Polaris is less than 5%.  About 1 in 30 worlds has a better pole star than Polaris."),o.a.createElement("h4",null,"The Tool"),o.a.createElement("div",{style:{textAlign:"left"}},this.getRangeOption("distance_exponent_in_quality","n (distance exponent in quality denominator)",o.a.createElement("span",null,"The pole star quality is calculated by ",o.a.createElement("i",null,"quality = 1 / (r * d",o.a.createElement("sup",null,"n"),")")," where r is the brighness rank of the star (for Polaris it is 50), d is the distance from the pole (for Polaris it is 0.75 degrees), and n is this simulation parameter.  This input is n, the exponent in the denominator of the quality formula.  Higher values of n give more value to being closer to the pole, thus resulting in dimmer stars being the best pole star.  Lower values of n give more value to being brighter than other stars (i.e. having a lower rank)."),0,6,.125),this.getRangeOption("rank","rank",o.a.createElement("span",null,"This is the brightness rank of the pole star.  For Polaris, it is about 50.  In the night sky of earth, the brightest star is ",o.a.createElement("a",{href:"https://en.wikipedia.org/wiki/Sirius"},"Sirius"),", so Sirius has a rank of 1.  Sirius is not near either pole, so it has a lower pole star quality than Polaris."),1,200,1),this.getRangeOption("distance_from_pole_degrees","distance from pole (degrees)",o.a.createElement("span",null,"This is the angle between the celestial pole and the pole star.  This slider is in degrees (not radians), although it is converted to radians for the calculation.  As of 2020, Polaris is about 0.75 degrees from the north celestial pole."),0,5,.05),this.getRangeOption("num_planets_to_simulate","number of planets to simulate",o.a.createElement("span",null,"This is the number of planets to simulate.  If this value is higher, the simulation will take longer but the resulting number will be more accurate."),1,5e4,1),this.getRangeOption("num_stars_limit","number of stars to simulate for each simulated planet",o.a.createElement("span",null,"This is the number of stars to generate for each simulated planet.  The default is 5000 because about 5000 stars are visible to the unaided human eye on earth.  This number also contributes to the amount of time the simulation takes to complete."),1,1e4,1),o.a.createElement(A,null,"include both poles",o.a.createElement(B,{content:"If checked, stars near either pole may be considered better pole stars than Polaris.  If unchecked, only stars near one pole (the north pole) may be considered better pole stars than Polaris."}),o.a.createElement("br",null),o.a.createElement("input",{type:"checkbox",onChange:e=>{this.setStateWithResultReset({include_both_poles:e.target.checked})},value:this.state.include_both_poles}),o.a.createElement("br",null),String(this.state.include_both_poles)),o.a.createElement("br",null),o.a.createElement("button",{style:{fontSize:20},onClick:()=>{this.runSimulation()}},"Run Simulation"),o.a.createElement("div",{style:{height:100}},"Probability of better pole star for ",this.state.include_both_poles?"either celestial pole":"north celestial pole",":",o.a.createElement("br",null),null===this.state.result?o.a.createElement("br",null):"string"==typeof this.state.result?this.state.result:o.a.createElement(o.a.Fragment,null,"By simulation: ",o.a.createElement("span",{style:{fontSize:20}},this.state.result.sim),o.a.createElement("br",null),"By calculation: ",o.a.createElement("span",{style:{fontSize:20}},this.state.result.calc)))))}}function O(){return o.a.createElement("div",null,"These are a some of the best images I have taken of astronomical objects.  With the exception of the eclipse images, these were taken through an Orion XT8g GoTo Dobsonian telescope.  All of these images were captured by a mobile phone camera.",o.a.createElement("br",null),o.a.createElement("h3",null,"The Moon"),"This image was cropped.",o.a.createElement("br",null),o.a.createElement("img",{src:"/astro-tools/moon.jpeg",width:300,alt:"The Moon"}),o.a.createElement("br",null),o.a.createElement("h3",null,"Conjunction of Jupiter and Saturn (2020-12-21)"),"The telescope changed the orientation of the image - Saturn actually appeared higher in the sky than Jupiter.",o.a.createElement("br",null),"5:42:21pm CST (the background light is daylight):",o.a.createElement("br",null),o.a.createElement("img",{src:"/astro-tools/2020-12-21_5:42:21pm.jpeg",width:300,alt:"Conjunction of Jupiter and Saturn"}),o.a.createElement("img",{src:"/astro-tools/2020-12-21_5:42:21pm_annotated.jpg",width:300,alt:"Conjunction of Jupiter and Saturn - annotated"}),o.a.createElement("br",null),"6:03:50pm CST:",o.a.createElement("br",null),o.a.createElement("img",{src:"/astro-tools/2020-12-21_6:03:50pm.jpeg",width:300,alt:"Conjunction of Jupiter and Saturn - annotated"}),o.a.createElement("h3",null,"Total Solar Eclipse of 2024-04-08"),"These images were taken from Jackson, Missouri (37.3948, -89.6640).  These images were taken through binoculars, and the image of the partial eclipse used a solar filter, which was just a sheet of the material that solar eclipse glasses use.",o.a.createElement("br",null),"1:59:33pm CDT:",o.a.createElement("br",null),o.a.createElement("img",{src:"/astro-tools/2024-04-08_1:59:33pm.jpeg",width:300,alt:"2024 Eclipse - Totality"}),o.a.createElement("br",null),"2:15:53pm CDT:",o.a.createElement("br",null),o.a.createElement("img",{src:"/astro-tools/2024-04-08_2:15:53pm.jpeg",width:300,alt:"2024 Eclipse - Partial"}))}var D=function(){return o.a.createElement("div",null,o.a.createElement(s.a,{basename:"/astro-tools"},o.a.createElement(l.c,null,o.a.createElement(l.a,{path:"/OtherPlanetEclipseAnalyzer"},o.a.createElement(s.b,{to:"/eclipse"},"Back to eclipse coincidence analysis tools"),o.a.createElement(M,null)),o.a.createElement(l.a,{path:"/ApparentSizeVariance"},o.a.createElement(s.b,{to:"/eclipse"},"Back to eclipse coincidence analysis tools"),o.a.createElement(z,null)),o.a.createElement(l.a,{path:"/RecessionOfMoon"},o.a.createElement(s.b,{to:"/eclipse"},"Back to eclipse coincidence analysis tools"),o.a.createElement(q,null)),o.a.createElement(l.a,{path:"/eclipse"},o.a.createElement("h1",null,"The Solar Eclipse Coincidence"),o.a.createElement("p",null,"It is a major coincidence that the moon looks almost the exact same size as the sun in earth's sky.  This has major implications for the quality of solar eclipses that occur on earth.  This quality of eclipses is unique to planet earth.  This is interesting since no other planet has intelligent life to observe such a phenomenon.  I was fortunate enough to witness a total solar eclipse on August 21, 2017."),o.a.createElement("p",null,"On average, the angular radius of the moon is about 98% of angular radius of the sun when both are visible.  However, it varies from about 91% to about 106%.  Total eclipses are only possible when it is greater than 100%, which is slightly less than half the time."),o.a.createElement("p",null,"I made some tools to analyze this coincidence.  Click one of these links to go to the tool."),o.a.createElement(s.b,{to:"/OtherPlanetEclipseAnalyzer"},"Other Planet Eclipse Analyzer"),o.a.createElement("br",null),o.a.createElement(s.b,{to:"/ApparentSizeVariance"},"Maximum and minimum size comparison"),o.a.createElement("br",null),o.a.createElement(s.b,{to:"/RecessionOfMoon"},"Recession of Moon")),o.a.createElement(l.a,{path:"/polaris"},o.a.createElement(F,null)),o.a.createElement(l.a,{path:"/images"},o.a.createElement(O,null)),o.a.createElement(l.a,{path:"/"},o.a.createElement("a",{href:"/astro-tools/plainHtmlStuff"},"Moon Coincidence Finder"),o.a.createElement("br",null),o.a.createElement("a",{href:"/astro-tools/plainHtmlStuff?tool=bodesSolver"},"Titius-Bode Solver"),o.a.createElement("br",null),o.a.createElement(s.b,{to:"/eclipse"},"The solar eclipse coincidence"),o.a.createElement("br",null),o.a.createElement(s.b,{to:"/polaris"},"The North Pole Star (Polaris) Coincidence"),o.a.createElement("br",null),o.a.createElement(s.b,{to:"/images"},"Some Telescope Images by Me")))))};Boolean("localhost"===window.location.hostname||"[::1]"===window.location.hostname||window.location.hostname.match(/^127(?:\.(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)){3}$/));i.a.render(o.a.createElement(D,null),document.getElementById("root")),"serviceWorker"in navigator&&navigator.serviceWorker.ready.then(e=>{e.unregister()}).catch(e=>{console.error(e.message)})},71:function(e,t,a){e.exports=a(186)},76:function(e,t,a){}},[[71,1,2]]]);
//# sourceMappingURL=main.ccbba912.chunk.js.map