(this["webpackJsonpastro-tools"]=this["webpackJsonpastro-tools"]||[]).push([[0],{167:function(e,t,a){"use strict";a.r(t);var n=a(0),r=a.n(n),o=a(57),i=a.n(o),l=(a(67),a(8)),s=a(9),m=a(17),u=a(26),c=a(24),_=a(25),p=a(13),h=a(37),d={name:["sun"],"mass (10^24 kg)":["1988500"],"radius (km)":["695700"],"rotation period (hours)":["609.12"]},f={name:["mercury","venus","earth","mars","jupiter","saturn","uranus","neptune","pluto"],star:["sun","sun","sun","sun","sun","sun","sun","sun","sun"],"mass (10^24 kg)":["0.330","4.87","5.97","0.642","1898","568","86.8","102","0.0146"],"equatorial diameter (km)":["4879","12104","12756","6792","142984","120536","51118","49528","2377"],"polar diameter (km)":["4879","12104","12713.6","6752","133709","108728","49946","48682","2377"],"semimajor axis (10^6 km)":["57.9","108.2","149.6","227.9","778.6","1433.5","2872.5","4495.1","5906.4"],"perihelion (10^6 km)":["46.0","107.5","147.1","206.6","740.5","1352.6","2741.3","4444.5","4436.8"],"aphelion (10^6 km)":["69.8","108.9","152.1","249.2","816.6","1514.5","3003.6","4545.7","7375.9"],"orbital period (earth days)":["88.0","224.7","365.2","687.0","4331","10747","30589","59800","90560"],"orbital velocity (km/s)":["47.4","35.0","29.8","24.1","13.1","9.7","6.8","5.4","4.7"],"rotation period (hours)":["1407.6","-5832.5","23.9","24.6","9.9","10.7","-17.2","16.1","-153.3"],"length of day (hours)":["4222.6","2802.0","24.0","24.7","9.9","10.7","17.2","16.1","153.3"]},g={name:["the moon","phobos","deimos","io","europa","ganymede","callisto","titan","miranda","ariel","umbriel","titania","oberon","triton","charon"],planet:["earth","mars","mars","jupiter","jupiter","jupiter","jupiter","saturn","uranus","uranus","uranus","uranus","uranus","neptune","pluto"],"mass (10^20 kg)":["734.767309","0.000106","0.000024","893.2","480.0","1481.9","1075.9","1345.5","0.66","12.9","12.2","34.2","28.8","214","15.86"],"radius (km)":["1737.4","12","6","1821.5","1560.8","2631.2","2410.3","2575","234","578","584.7","788.9","761.4","1353.4","606"],"semimajor axis (10^3 km)":["384.399","9.378","23.459","421.9","671.1","1070.4","1882.7","1221.83","129.9","190.9","266.0","436.3","583.5","354.76","19.596"],"orbital period (earth days)":["27.321662","0.31891","1.26244","1.769138","3.551181","7.154553","16.689017","15.945421","1.413479","2.520379","4.144176","8.705867","13.463234","-5.876854","6.3872"]},b="0123456789".split("").reduce((function(e,t){return e[t]=!0,e}),{}),v=function(){function e(t){Object(p.a)(this,e),isNaN(t)?(this.value=t,this.num_significant_figures=null):(this.value=Number(t),this.num_significant_figures=e.getNumSignificantFigures(t))}return Object(h.a)(e,[{key:"getScaled",value:function(t){var a=new e("0");return a.value=this.value*t,a.num_significant_figures=this.num_significant_figures,a}}],[{key:"getNumSignificantFigures",value:function(e){for(var t=-1,a=0,n=0,r=-1,o=0;o<e.length;o++){var i=e[o];i in b?("0"!==i&&t<0&&(t=o),t>=0&&(a+=1),"0"!==i&&(n=a),"0"===i&&r>=0&&r<o&&(n=a)):"."===i&&(r=o)}return n}}]),e}(),k=/^.*\((.*)\)$/,E=/^(.*)\(.*\)$/,y=/^10\^(-?[0-9]*)$/,w=function(){function e(t,a){for(var n in Object(p.a)(this,e),a)this[n]=new v(a[n][t]);"rotation period (hours)"in this&&(this["rotation period (days)"]=this["rotation period (hours)"].getScaled(1/24),delete this["rotation period (hours)"]),"length of day (hours)"in this&&(this["length of day (days)"]=this["length of day (hours)"].getScaled(1/24),delete this["length of day (hours)"]);for(var r=0,o=["","polar ","equatorial "];r<o.length;r++){var i=o[r];i+"radius (km)"in this&&!(i+"diameter (km)"in this)?this[i+"diameter (km)"]=this[i+"radius (km)"].getScaled(2):i+"diameter (km)"in this&&!(i+"radius (km)"in this)&&(this[i+"radius (km)"]=this[i+"diameter (km)"].getScaled(.5))}}return Object(h.a)(e,null,[{key:"get_base_unit_value",value:function(t,a){var n=e.get_complete_unit(t).split(" ")[0],r=0;void 0!==n&&y.test(n)&&(r=Number(n.match(y)[1]));var o=a;return 0!==r&&(o=a*Math.pow(10,r)),o}},{key:"get_base_unit_value_nicer",value:function(t,a){return e.get_base_unit_value(a,t[a].value)}},{key:"get_base_unit_attribute_key",value:function(t){return t.match(E)[1]+" ("+e.get_base_unit(t)+")"}},{key:"get_complete_unit",value:function(e){var t=null;return k.test(e)&&(t=e.match(k)[1]),t}},{key:"get_base_unit",value:function(t){var a=null,n=e.get_complete_unit(t);return null!==n&&(a=n.split(" ").reduce((function(e,t){return t}),null)),a}}]),e}(),z=function(e){function t(e){Object(p.a)(this,t);var a=d.name.indexOf(e.toLowerCase());if(-1===a)throw new Error("Star::constructor Unable to find star with name '"+String(e.toLowerCase())+"'");return Object(u.a)(this,Object(c.a)(t).call(this,a,d))}return Object(_.a)(t,e),t}(w),x=function(e){function t(e){Object(p.a)(this,t);var a=f.name.indexOf(e.toLowerCase());if(-1===a)throw new Error("Planet::constructor Unable to find planet with name '"+String(e.toLowerCase())+"'");return Object(u.a)(this,Object(c.a)(t).call(this,a,f))}return Object(_.a)(t,e),t}(w),j=function(e){function t(e){var a;Object(p.a)(this,t);var n=g.name.indexOf(e.toLowerCase());if(-1===n)throw new Error("Moon::constructor Unable to find moon with name '"+String(e.toLowerCase())+"'");if(a=Object(u.a)(this,Object(c.a)(t).call(this,n,g)),"semimajor axis (10^3 km)"in Object(m.a)(a)&&!("orbital velocity (km/s)"in Object(m.a)(a))){var r=new x(a.planet.value);"mass (10^24 kg)"in r&&(a["orbital velocity (km/s)"]=new v("0"),a["orbital velocity (km/s)"].value=Math.sqrt(6.67408e-20*w.get_base_unit_value("mass (10^24 kg)",r["mass (10^24 kg)"].value)/w.get_base_unit_value("semimajor axis (10^3 km)",a["semimajor axis (10^3 km)"].value)),a["orbital velocity (km/s)"].num_significant_figures=3)}return a}return Object(_.a)(t,e),t}(w);function M(e){var t=e.sunSize,a=e.moonSize,n=e.starColor,o=Math.max(t,a),i=50*a/o,l=50*t/o;return r.a.createElement("div",{style:{backgroundColor:"black",verticalAlign:"middle",display:"flex",width:100,height:100,align:"right"}},r.a.createElement("div",{style:{width:50-i}}),r.a.createElement("div",{style:{backgroundColor:"gray",display:"inline-block",height:2*i,width:i,margin:"auto",borderTopLeftRadius:i,borderBottomLeftRadius:i}}),r.a.createElement("div",{style:{backgroundColor:n||"yellow",display:"inline-block",height:2*l,width:l,margin:"auto",borderTopRightRadius:l,borderBottomRightRadius:l}}),r.a.createElement("div",{style:{width:50-l}}))}var S=[["b",.01154775,1.121],["c",.01581512,1.095],["d",.02228038,.784],["e",.02928285,.91],["f",.03853361,1.046],["g",.04687692,1.148],["h",.06193488,.773]];function O(e){return 6378.1*e/1496e5}function C(e){return r.a.createElement("th",{style:{border:"1px solid black"}},e.children)}function R(e){return r.a.createElement("td",{style:{border:"1px solid black"}},e.children)}function T(e){return r.a.createElement("span",{style:{textTransform:"capitalize"}},e.children)}function P(){var e=[];g.name.forEach((function(t){var a={},n=new j(t),r=new x(n.planet.value),o=new z(r.star.value);a.relationship="moon",a.star_color="yellow",a.moon=n,a.moon_apparent_size_from_planet_center=Math.atan(n["radius (km)"].value/w.get_base_unit_value("semimajor axis (10^3 km)",n["semimajor axis (10^3 km)"].value)),a.moon_apparent_size_from_planet_point_closest_to_moon=Math.atan(n["radius (km)"].value/(w.get_base_unit_value("semimajor axis (10^3 km)",n["semimajor axis (10^3 km)"].value)-r["equatorial radius (km)"].value)),a.sun_apparent_size_from_planet_center=Math.atan(o["radius (km)"].value/w.get_base_unit_value("semimajor axis (10^6 km)",r["semimajor axis (10^6 km)"].value)),a.sun_apparent_size_from_planet_point_closest_to_sun=Math.atan(o["radius (km)"].value/(w.get_base_unit_value("semimajor axis (10^6 km)",r["semimajor axis (10^6 km)"].value)-r["equatorial radius (km)"].value)),a.ratio_from_planet_center=a.moon_apparent_size_from_planet_center/a.sun_apparent_size_from_planet_center,a.ratio_from_planet_point_closest_to_moon=a.moon_apparent_size_from_planet_point_closest_to_moon/a.sun_apparent_size_from_planet_point_closest_to_sun,a.min_error=Math.min(Math.abs(Math.log(a.ratio_from_planet_center)),Math.abs(Math.log(a.ratio_from_planet_point_closest_to_moon))),e.push(a)}));for(var t=0;t<S.length;t++)for(var a=0;a<t;a++){var n=S[a],o=S[t],i={relationship:"neighbor",star_color:"red"};i.moon={name:{value:"TRAPPIST-1"+n[0]},planet:{value:"TRAPPIST-1"+o[0]}};var l=o[1]-n[1],s=O(o[2]),m=O(n[2]),u=695700*.121/1496e5;i.moon_apparent_size_from_planet_center=Math.atan(m/l),i.moon_apparent_size_from_planet_point_closest_to_moon=Math.atan(m/(l-s)),i.sun_apparent_size_from_planet_center=Math.atan(u/o[1]),i.sun_apparent_size_from_planet_point_closest_to_sun=Math.atan(u/(o[1]-s)),i.ratio_from_planet_center=i.moon_apparent_size_from_planet_center/i.sun_apparent_size_from_planet_center,i.ratio_from_planet_point_closest_to_moon=i.moon_apparent_size_from_planet_point_closest_to_moon/i.sun_apparent_size_from_planet_point_closest_to_sun,i.min_error=Math.min(Math.abs(Math.log(i.ratio_from_planet_center)),Math.abs(Math.log(i.ratio_from_planet_point_closest_to_moon))),e.push(i)}return e.sort((function(e,t){return e.min_error-t.min_error})),r.a.createElement("div",null,r.a.createElement("table",null,r.a.createElement("thead",null,r.a.createElement("tr",null,r.a.createElement(C,null,"Related Objects"),r.a.createElement(C,null,"From Planet Center"),r.a.createElement(C,null,"From Planet Closest Point To Moon"))),r.a.createElement("tbody",null,e.map((function(e){return r.a.createElement("tr",{key:e.moon.name.value+":"+e.moon.planet.value},r.a.createElement(R,null,r.a.createElement(T,null,e.moon.name.value),r.a.createElement("br",null),e.relationship+" of ",r.a.createElement(T,null,e.moon.planet.value)),r.a.createElement(R,null,r.a.createElement("div",{style:{display:"flex",alignItems:"center"}},r.a.createElement(M,{moonSize:e.moon_apparent_size_from_planet_center,sunSize:e.sun_apparent_size_from_planet_center,starColor:e.star_color}),r.a.createElement("ul",null,r.a.createElement("li",null,r.a.createElement(T,null,e.relationship)," angular diameter: ",(2*e.moon_apparent_size_from_planet_center*180/Math.PI).toFixed(3),"\xb0"),r.a.createElement("li",null,"Star angular diameter: ",(2*e.sun_apparent_size_from_planet_center*180/Math.PI).toFixed(3),"\xb0"),r.a.createElement("li",null,"Ratio: ",(e.moon_apparent_size_from_planet_center/e.sun_apparent_size_from_planet_center).toFixed(3))))),r.a.createElement(R,null,r.a.createElement("div",{style:{display:"flex",alignItems:"center"}},r.a.createElement(M,{moonSize:e.moon_apparent_size_from_planet_point_closest_to_moon,sunSize:e.sun_apparent_size_from_planet_point_closest_to_sun,starColor:e.star_color}),r.a.createElement("ul",null,r.a.createElement("li",null,r.a.createElement(T,null,e.relationship)," angular diameter: ",(2*e.moon_apparent_size_from_planet_point_closest_to_moon*180/Math.PI).toFixed(3),"\xb0"),r.a.createElement("li",null,"Star angular diameter: ",(2*e.sun_apparent_size_from_planet_point_closest_to_sun*180/Math.PI).toFixed(3),"\xb0"),r.a.createElement("li",null,"Ratio: ",(e.moon_apparent_size_from_planet_point_closest_to_moon/e.sun_apparent_size_from_planet_point_closest_to_sun).toFixed(3))))))})))))}function A(e){var t=e.moonDiameterRadians,a=e.sunDiameterRadians;return r.a.createElement("div",{style:{display:"flex",alignItems:"center"}},r.a.createElement(M,{moonSize:t,sunSize:a}),r.a.createElement("ul",null,r.a.createElement("li",null,"Moon angular diameter: ",(2*t*180/Math.PI).toFixed(3),"\xb0"),r.a.createElement("li",null,"Star angular diameter: ",(2*a*180/Math.PI).toFixed(3),"\xb0"),r.a.createElement("li",null,"Ratio: ",(t/a).toFixed(3))))}function B(){var e=new x("earth"),t=new j("the moon"),a=new z("sun"),n=t["radius (km)"].value,o=a["radius (km)"].value,i=e["equatorial radius (km)"].value,l=w.get_base_unit_value_nicer(e,"semimajor axis (10^6 km)"),s=w.get_base_unit_value_nicer(e,"perihelion (10^6 km)"),m=w.get_base_unit_value_nicer(e,"aphelion (10^6 km)"),u={moon:{maximum:n/(363228.9-i),minimum:n/405400,average:n/(w.get_base_unit_value_nicer(t,"semimajor axis (10^3 km)")-i/2)},sun:{maximum:o/s,minimum:o/m,average:o/l}},c=Object.keys(u).reduce((function(e,t){return e[t]=Object.keys(u[t]).reduce((function(e,a){return e[a]=Math.atan(u[t][a]),e}),{}),e}),{});return r.a.createElement("div",null,"Maximum moon size to minimum sun size:",r.a.createElement(A,{moonDiameterRadians:c.moon.maximum,sunDiameterRadians:c.sun.minimum}),"Minimum moon size to maximum sun size:",r.a.createElement(A,{moonDiameterRadians:c.moon.minimum,sunDiameterRadians:c.sun.maximum}),"Average moon size to average sun size:",r.a.createElement(A,{moonDiameterRadians:c.moon.average,sunDiameterRadians:c.sun.average}))}var I=a(58);function F(){var e=new x("earth"),t=new z("sun"),a=new j("the moon"),n=w.get_base_unit_value_nicer(e,"semimajor axis (10^6 km)"),o=a["radius (km)"].value*(n/t["radius (km)"].value),i=a["radius (km)"].value*(n/t["radius (km)"].value)+e["equatorial radius (km)"].value,l=Array(6).fill(0).map((function(e,t,a){return 45e8*(3-t)/3}));return r.a.createElement("div",null,r.a.createElement("h3",null,"Recession of moon and eclipses"),r.a.createElement("p",null,"It is widely accepted that the moon is getting farther from earth over billions of years.  The current generally accepted number is 3.8 centimeters per year.  However, this has been described as anomalously high.  This number came from a NASA measurement in which they had a station on the moon work with a laboratory on earth using a laser to measure distance.  But measurements from other fields, such as palientology and geology, indicate a recession of 2.9 centimeters per year.  Also, if the moon is receding at 3.8 centimeters per year, based on the physics of tidal recession, it would coincide with earth 1.5 billion years ago, much less than the generally accepted 4.5 billion year age of the earth-moon system.  This anomaly may be due to the laser being influenced (",r.a.createElement("a",{href:"https://link.springer.com/article/10.1186/2191-2521-1-1"},"source"),")."),r.a.createElement("p",null,"We live on earth in a window of time in which perfect eclipses are possible.  It is generally accepted that the moon's distance from earth is increasing by 3.8 centimeters per year.  The graph below linearly extrapolates that relative to the generally accepted age of the earth-moon system: ",45e8," years.  ",r.a.createElement("strong",null,"NOTE:")," the history of the moon's recession almost certainly does NOT look like this!  It is not certain what it does look like, but it either went faster or slower in the past.  Also, this ignores:"),r.a.createElement("ul",null,r.a.createElement("li",null,"the possibility of the moon's orbit eccentricity changing"),r.a.createElement("li",null,"the earth's orbit eccentricity"),r.a.createElement("li",null,"the possibility of the sun's radius changing")),r.a.createElement("p",null,"But this shows how unlikely perfect eclipses are."),r.a.createElement(I.a,{data:{labels:l.map((function(e){return e.toFixed(0)})),datasets:[{label:"Moon apogee",data:l.map((function(e){return 405400-38e-6*e})),pointBackgroundColor:"black",pointBorderColor:"black",borderColor:"black",lineTension:0,fill:!1},{label:"Moon perigee",data:l.map((function(e){return 363228.9-38e-6*e})),pointBackgroundColor:"black",pointBorderColor:"black",borderColor:"black",lineTension:0,fill:!1},{label:"Distance at which the moon is the same size as the sun from center of earth",data:l.map((function(e){return o})),pointBackgroundColor:"brown",pointBorderColor:"brown",borderColor:"brown",lineTension:0,fill:!1},{label:"Distance at which the moon is the same size as the sun from point on earth closest to moon",data:l.map((function(e){return i})),pointBackgroundColor:"green",pointBorderColor:"green",borderColor:"green",lineTension:0,fill:!1}]},options:{title:{display:!0,text:"Linear Extrapolation of Moon Recession Compared to Perfect Eclipse Distances"},scales:{yAxes:[{ticks:{beginAtZero:!0},scaleLabel:{labelString:"Moon distance from earth (kilometers)",display:!0}}],xAxes:[{gridLines:{color:l.map((function(e){return 0===e?"black":"rgb(175,175,175)"})),lineWidth:l.map((function(e){return 0===e?2:1}))},ticks:{callback:function(e){return String(e)===String(45e8)?String(45e8)+" (age of moon)":"0"===String(e)?"0 (now)":e}},scaleLabel:{labelString:"Years before present",display:!0}}]}}}))}var L=function(){var e="";return r.a.createElement("div",null,r.a.createElement(l.a,{basename:"/astro-tools"},r.a.createElement(s.c,null,r.a.createElement(s.a,{path:e+"/OtherPlanetEclipseAnalyzer"},r.a.createElement(l.b,{to:e+"/eclipse"},"Back to perfect eclipse analysis tools"),r.a.createElement(P,null)),r.a.createElement(s.a,{path:e+"/ApparentSizeVariance"},r.a.createElement(l.b,{to:e+"/eclipse"},"Back to perfect eclipse analysis tools"),r.a.createElement(B,null)),r.a.createElement(s.a,{path:e+"/RecessionOfMoon"},r.a.createElement(l.b,{to:e+"/eclipse"},"Back to perfect eclipse analysis tools"),r.a.createElement(F,null)),r.a.createElement(s.a,{path:e+"/eclipse"},r.a.createElement("h1",null,"The Perfect Eclipse Coincidence"),r.a.createElement("p",null,"It is a major coincidence that the moon looks almost the exact same size as the sun in earth's sky.  Perfect eclipses are unique to planet earth.  This is interesting since no other planet has intelligent life to observe such a phenomenon.  I was fortunate enough to witness a perfect eclipse on August 21, 2017."),r.a.createElement("p",null,"On average, the angular radius of the moon is about 98% of angular radius of the sun when both are visible.  However, it varies from about 92% to about 107%.  Total eclipses are only possible when it is greater than 100%, which is slightly less than half the time."),r.a.createElement("p",null,"I made some tools to analyze this coincidence.  Click one of these links to go to the tool."),r.a.createElement(l.b,{to:e+"/OtherPlanetEclipseAnalyzer"},"Other Planet Eclipse Analyzer"),r.a.createElement("br",null),r.a.createElement(l.b,{to:e+"/ApparentSizeVariance"},"Maximum and minimum size comparison"),r.a.createElement("br",null),r.a.createElement(l.b,{to:e+"/RecessionOfMoon"},"Recession of Moon")),r.a.createElement(s.a,{path:e+"/"},r.a.createElement("a",{href:"/astro-tools/plainHtmlStuff"},"Moon Coincidence Finder"),r.a.createElement("br",null),r.a.createElement("a",{href:"/astro-tools/plainHtmlStuff?tool=bodesSolver"},"Titius-Bode Solver"),r.a.createElement("br",null),r.a.createElement(l.b,{to:e+"/eclipse"},"The perfect eclipse coincidence")))))};Boolean("localhost"===window.location.hostname||"[::1]"===window.location.hostname||window.location.hostname.match(/^127(?:\.(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)){3}$/));i.a.render(r.a.createElement(L,null),document.getElementById("root")),"serviceWorker"in navigator&&navigator.serviceWorker.ready.then((function(e){e.unregister()})).catch((function(e){console.error(e.message)}))},62:function(e,t,a){e.exports=a(167)},67:function(e,t,a){}},[[62,1,2]]]);
//# sourceMappingURL=main.4a79cb35.chunk.js.map