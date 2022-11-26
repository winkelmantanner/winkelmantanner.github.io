const NXT_WIDTH_PIXELS = 100;
const NXT_HEIGHT_PIXELS = 64;
const NXT_ASPECT_RATIO = NXT_WIDTH_PIXELS * 1.0/*unnecessary in JS, but I find this safer*/ / NXT_HEIGHT_PIXELS;
const NXT_BUTTON_NONE = -1;
const NXT_BUTTON_DOWN = 0;
const NXT_BUTTON_LEFT = 2;
const NXT_BUTTON_RIGHT = 1;
const NXT_BUTTON_UP = 3;

// I'm not sure if these are the right numbers
const NXT_LINE_HEIGHT_PIXELS = 8;
const NXT_LINE_HEIGHT_FONT_SCALAR = 1.15;

const NXT_BACKGROUND_COLOR = "#94bca0";
const NXT_ACTIVE_PIXEL_COLOR = "black";
const ONSCREEN_CONTROL_BACKGROUND_COLOR = "rgba(0,0,0,0)";
const ORANGE_COLOR = "orange";
const NXT_SIDE_BUTTON_COLOR = "gray";
const NXT_BACK_BUTTON_COLOR = "rgb(75,75,75)";
const NXT_TOUCH_SENSOR_INTERIOR_COLOR = "rgb(200,100,50)";


// https://stackoverflow.com/a/60435654
function encodeHex(anyString) {
  return anyString.split("")
    .map(c => c.charCodeAt(0).toString(16).padStart(2, "0"))
    .join("");
}
function decodeHex(hexString) {
  return hexString.split(/(\w\w)/g)
    .filter(p => !!p)
    .map(c => String.fromCharCode(parseInt(c, 16)))
    .join("");
}

function getNxtDisplay() {
  return document.getElementById('nxtDisplay');
}
function getLeftTouchControls() {
  return document.getElementById('leftTouchControls');
}
function getRightTouchControls() {
  return document.getElementById('rightTouchControls');
}
function getNxtDisplayContext() {
  return getNxtDisplay().getContext('2d');
}
function drawPolygon(ctx, w, h, coordPairArray) {
  for(const [idx, vert] of coordPairArray.entries()) {
    const coords = [vert[0] * w, vert[1] * h];
    if(idx === 0) {
      ctx.moveTo(...coords);
    } else {
      ctx.lineTo(...coords);
    }
  }
  ctx.closePath();
}
function fillPolygon(ctx, w, h, coordPairArray) {
  ctx.beginPath();
  drawPolygon(ctx, w, h, coordPairArray);
  ctx.fill();
}
function strokePolygon(ctx, w, h, coordPairArray) {
  ctx.beginPath();
  drawPolygon(ctx, w, h, coordPairArray);
  ctx.stroke();
}
const SQRT_2 = Math.sqrt(2);
const ORANGE_BUTTON_VERTICES = [[0.4, 0.1], [0.6, 0.1], [0.6, 0.3], [0.4, 0.3]];
const LEFT_SIDE_BUTTON_VERTICES = [[0.1, 0.5], [0.3, 0.4], [0.3, 0.6]];
const BACK_BUTTON_VERTICES = [[0.4, 0.8], [0.6, 0.8], [0.6, 0.7], [0.4, 0.7]];
const LINE_WIDTH = 0.01;
const OUTER_CIRCLE_RADIUS = 0.475;
const INNER_CIRCLE_RADIUS = 0.15;
const DIAGONAL_OUTER_END_COORD = 0.5 - (OUTER_CIRCLE_RADIUS / SQRT_2);
const DIAGONAL_INNER_END_COORD = 0.5 - (INNER_CIRCLE_RADIUS / SQRT_2);
const DIAGONAL_VERTICES = [
  [DIAGONAL_OUTER_END_COORD, DIAGONAL_OUTER_END_COORD],
  [DIAGONAL_INNER_END_COORD, DIAGONAL_INNER_END_COORD]
];
function setPressedButtonFx(ctx, isButtonPressed) {
  if(isButtonPressed) {
    ctx.globalAlpha = 1;
    ctx.shadowBlur = 20;
    ctx.shadowColor = ctx.fillStyle;
  } else {
    ctx.globalAlpha = 0.25;
    ctx.shadowBlur = 0;
  }
}
function drawNxtButtons(canvas) {
  const ctx = canvas.getContext('2d');
  const w = canvas.width;
  const h = canvas.height;
  ctx.clearRect(0, 0, w, h);
  ctx.fillStyle = ONSCREEN_CONTROL_BACKGROUND_COLOR;
  ctx.fillRect(0,0,w,h);


  ctx.fillStyle = ORANGE_COLOR;
  setPressedButtonFx(ctx, nNxtButtonPressed === NXT_BUTTON_UP);
  fillPolygon(ctx, w, h, ORANGE_BUTTON_VERTICES);

  ctx.fillStyle = NXT_SIDE_BUTTON_COLOR;
  setPressedButtonFx(ctx, nNxtButtonPressed === NXT_BUTTON_LEFT);
  fillPolygon(ctx, w, h, LEFT_SIDE_BUTTON_VERTICES);
  setPressedButtonFx(ctx, nNxtButtonPressed === NXT_BUTTON_RIGHT);
  fillPolygon(ctx, w, h, LEFT_SIDE_BUTTON_VERTICES.map(([x, y]) => [1 - x, y]));

  ctx.fillStyle = NXT_BACK_BUTTON_COLOR;
  setPressedButtonFx(ctx, nNxtButtonPressed === NXT_BUTTON_DOWN);
  fillPolygon(ctx, w, h, BACK_BUTTON_VERTICES);

  ctx.globalAlpha = 1;
  ctx.shadowBlur = 0;


  ctx.fillStyle = 'gray';
  ctx.strokeStyle = ctx.fillStyle;
  ctx.lineWidth = Math.sqrt(2 * Math.pow(LINE_WIDTH, 2) * w * h);
  strokePolygon(ctx, w, h, DIAGONAL_VERTICES);
  strokePolygon(ctx, w, h, DIAGONAL_VERTICES.map(([x, y]) => [1 - x, y]));
  strokePolygon(ctx, w, h, DIAGONAL_VERTICES.map(([x, y]) => [x, 1 - y]));
  strokePolygon(ctx, w, h, DIAGONAL_VERTICES.map(([x, y]) => [1 - x, 1 - y]));
  ctx.beginPath();
  ctx.ellipse(0.5 * w, 0.5 * h, INNER_CIRCLE_RADIUS * w, INNER_CIRCLE_RADIUS * h, 0, 0, 2 * Math.PI);
  ctx.stroke();
  ctx.beginPath();
  ctx.ellipse(0.5 * w, 0.5 * h, OUTER_CIRCLE_RADIUS * w, OUTER_CIRCLE_RADIUS * h, 0, 0, 2 * Math.PI);
  ctx.stroke();
}
const TOUCH_SENSOR_PLUS_1D_VERTICES = [[0, 0.45], [1, 0.45], [1, 0.55], [0, 0.55]];
const TOUCH_SENSOR_HOLE_1D_VERTICES = [[0.35, 0.45], [0.65, 0.45], [0.65, 0.55], [0.35, 0.55]];
function drawTouchSensor(canvas) {
  const ctx = canvas.getContext('2d');
  const w = canvas.width;
  const h = canvas.height;
  ctx.clearRect(0, 0, w, h);
  ctx.globalAlpha = 1;
  ctx.fillStyle = ONSCREEN_CONTROL_BACKGROUND_COLOR;
  ctx.fillRect(0,0,w,h);
  ctx.globalAlpha = touchSensorPressed ? 1 : 0.25;
  ctx.shadowBlur = touchSensorPressed ? 20 : 0;
  ctx.fillStyle = ctx.shadowColor = ORANGE_COLOR;
  ctx.beginPath();
  drawPolygon(ctx, w, h, TOUCH_SENSOR_PLUS_1D_VERTICES);
  drawPolygon(ctx, w, h, TOUCH_SENSOR_PLUS_1D_VERTICES.map(([x, y]) => [1 - y, x]));
  ctx.ellipse(0.5 * w, 0.5 * h, 0.3 * w, 0.3 * h, 0, 0, 2 * Math.PI);
  ctx.fill();
  ctx.fillStyle = NXT_TOUCH_SENSOR_INTERIOR_COLOR;
  ctx.shadowBlur = 0;
  ctx.beginPath();
  drawPolygon(ctx, w, h, TOUCH_SENSOR_HOLE_1D_VERTICES);
  drawPolygon(ctx, w, h, TOUCH_SENSOR_HOLE_1D_VERTICES.map(([x, y]) => [1 - y, x]));
  ctx.fill();
}

async function onResize() {
  const canvas = getNxtDisplay();
  canvas.width = Math.min(window.innerWidth, window.innerHeight * NXT_ASPECT_RATIO);
  canvas.height = Math.min(window.innerHeight, window.innerWidth / NXT_ASPECT_RATIO);
  erasedisplay();
  drawNxtButtons(getLeftTouchControls());
  drawTouchSensor(getRightTouchControls());
}

let downPressed = false;
let upPressed = false;
let rightPressed = false;
let leftPressed = false;
let touchSensorPressed = false;
let joyButtonsPressed = Object.create(null);
for(let joyBtnNumber = 1; joyBtnNumber <= 12; joyBtnNumber++) {
  joyButtonsPressed[joyBtnNumber] = false;
}
function updateButtonBoolean(event, booleanValue) {
  let doPreventDefault = true;
  if (event.key === "ArrowDown" || event.key === "s") {
    downPressed = booleanValue;
  } else if (event.key === "ArrowRight" || event.key === "d") {
    rightPressed = booleanValue;
  } else if (event.key === "ArrowLeft" || event.key === "a") {
    leftPressed = booleanValue;
  } else if (event.key === "ArrowUp" || event.key === "w") {
    upPressed = booleanValue;
  } else if (event.key === " ") {
    updateTouchSensorPressed(booleanValue);
  } else if (/^\d$/.test(event.key)) {
    let number = event.key;
    if(number === 0) {
      number = 10;
    }
    joyButtonsPressed[number] = booleanValue;
  } else {
    doPreventDefault = false;
  }
  if(doPreventDefault) {
    event.preventDefault();
  }
}
function updatenNxtButtonPressedBasedOnBooleans() {
  // I don't know the priority order used by the actual NXT
  if (downPressed) {
    nNxtButtonPressed = NXT_BUTTON_DOWN;
  } else if (rightPressed) {
    nNxtButtonPressed = NXT_BUTTON_RIGHT;
  } else if (leftPressed) {
    nNxtButtonPressed = NXT_BUTTON_LEFT;
  } else if (upPressed) {
    nNxtButtonPressed = NXT_BUTTON_UP;
  } else {
    nNxtButtonPressed = NXT_BUTTON_NONE;
  }
  drawNxtButtons(getLeftTouchControls());
}
function square(nbr) { return nbr * nbr; }
function distance(x1, y1, x2, y2) {
  return Math.sqrt(square(x1 - x2) + square(y1 - y2));
}
function updatenNxtButtonPressedByTouchableCanvas(arrayOfObjsWithPageCoords, canvas) {
  leftPressed = false;
  downPressed = false;
  upPressed = false;
  rightPressed = false;
  for(const obj of arrayOfObjsWithPageCoords) {
    const tx = (obj.pageX - canvas.offsetLeft) / canvas.width;
    const ty = (obj.pageY - canvas.offsetTop) / canvas.height;
    if(tx >= 0 && tx <= 1 && ty >= 0 && ty <= 1
      && distance(tx, ty, 0.5, 0.5) >= INNER_CIRCLE_RADIUS
      && distance(tx, ty, 0.5, 0.5) <= OUTER_CIRCLE_RADIUS
    ) {
      if(tx < ty) {
        if(tx + ty < 1) {
          leftPressed = true;
        } else {
          downPressed = true;
        }
      } else {
        if(tx + ty < 1) {
          upPressed = true;
        } else {
          rightPressed = true;
        }
      }
    }
  }
  updatenNxtButtonPressedBasedOnBooleans();
}
function updateTouchSensorPressed(newValue) {
  touchSensorPressed = newValue;
  drawTouchSensor(getRightTouchControls());
}
function setupGameModal(gameTitle) {
  const gameFilename = gameTitle + '.c';
  const gameInfoHtml = document.querySelector(`.gameInfoHtml[data-game='${gameTitle}']`).innerHTML;
  document.querySelector(".gameModalHeaderText").textContent = gameFilename;
  document.querySelector(".gameModalBody").innerHTML = gameInfoHtml;
  document.querySelector(".gameModalPlayLink").textContent = "► Play " + gameFilename;
  document.querySelector(".gameModalPlayLink").href = "?" + new URLSearchParams(
    {game: gameFilename, action: 'play'}
  ).toString();
  document.querySelector(".gameModalLink").href = "?" + new URLSearchParams(
    {game: gameFilename}
  ).toString();
}
function setupEventHanlders() {
  for(const gameCardClickable of document.querySelectorAll(".gameCardClickable")) {
    gameCardClickable.addEventListener("click", function(event) {
      const gameTitle = event.target.closest(".gameCardClickable").dataset.game;
      setupGameModal(gameTitle);
    });
  }

  window.addEventListener('keydown', function (event) {
    updateButtonBoolean(event, true);
    updatenNxtButtonPressedBasedOnBooleans();
  });
  window.addEventListener('keyup', function (event) {
    updateButtonBoolean(event, false);
    updatenNxtButtonPressedBasedOnBooleans();
  });

  getLeftTouchControls().addEventListener('mousedown', function(event) {
    event.preventDefault();
    updatenNxtButtonPressedByTouchableCanvas([event], event.target);
  });
  getLeftTouchControls().addEventListener('mousemove', function(event) {
    event.preventDefault();
    if(event.buttons === 0) {
      nNxtButtonPressed = NXT_BUTTON_NONE;
    } else if(event.buttons === 1) {
      updatenNxtButtonPressedByTouchableCanvas([event], event.target);
    }
  });
  getLeftTouchControls().addEventListener('mouseenter', function(event) {
    event.preventDefault();
    if(event.buttons === 0) {
      nNxtButtonPressed = NXT_BUTTON_NONE;
    } else if(event.buttons === 1) {
      updatenNxtButtonPressedByTouchableCanvas([event], event.target);
    }
  });
  getLeftTouchControls().addEventListener('mouseup', function(event) {
    event.preventDefault();
    nNxtButtonPressed = NXT_BUTTON_NONE;
    updatenNxtButtonPressedByTouchableCanvas([], event.target);
  });
  getLeftTouchControls().addEventListener('mouseleave', function(event) {
    event.preventDefault();
    nNxtButtonPressed = NXT_BUTTON_NONE;
    updatenNxtButtonPressedByTouchableCanvas([], event.target);
  });
  getLeftTouchControls().addEventListener('touchstart', function(event) {
    event.preventDefault();
    updatenNxtButtonPressedByTouchableCanvas(event.touches, event.target);
  }, {passive: false});
  getLeftTouchControls().addEventListener('touchmove', function(event) {
    event.preventDefault();
    updatenNxtButtonPressedByTouchableCanvas(event.touches, event.target);
  }, {passive: false});
  getLeftTouchControls().addEventListener('touchend', function(event) {
    event.preventDefault();
    nNxtButtonPressed = NXT_BUTTON_NONE;
    updatenNxtButtonPressedByTouchableCanvas(event.touches, event.target);
  });

  getRightTouchControls().addEventListener('mousedown', function(event) {
    event.preventDefault();
    updateTouchSensorPressed(true);
    updateTouchSensorPressed(true);
  });
  getRightTouchControls().addEventListener('mousemove', function(event) {
    event.preventDefault();
    touchSensorPressed = (event.buttons === 1);
  });
  getRightTouchControls().addEventListener('mouseenter', function(event) {
    event.preventDefault();
    touchSensorPressed = (event.buttons === 1);
  });
  getRightTouchControls().addEventListener('mouseup', function(event) {
    event.preventDefault();
    updateTouchSensorPressed(false);
  });
  getRightTouchControls().addEventListener('mouseleave', function(event) {
    event.preventDefault();
    updateTouchSensorPressed(false);
  });
  getRightTouchControls().addEventListener('touchstart', function(event) {
    event.preventDefault();
    updateTouchSensorPressed(true);
  }, {passive: false});
  getRightTouchControls().addEventListener('touchmove', function(event) {
    event.preventDefault();
    updateTouchSensorPressed(true);
  }, {passive: false});
  getRightTouchControls().addEventListener('touchend', function(event) {
    event.preventDefault();
    updateTouchSensorPressed(false);
  });
}
function renderWebpage() {
  document.getElementById("nonNxtDisplayContainer").classList.remove('d-none');
  for(const gameCardClickable of document.querySelectorAll(".gameCardClickable")) {
    const gameTitle = gameCardClickable.dataset.game;
    gameCardClickable.innerHTML = document.querySelector(".gameCardHtml").innerHTML.replace(
      /{{{gameTitle}}}/g,
      gameTitle
    );
  }
}
function playGame(gameFilename) {
  document.getElementById("nxtDisplayContainer").classList.remove('d-none');
  // This is where the magic happens
  fetch(window.location.pathname + 'robotcPrograms/' + gameFilename)
    .then(response => response.text())
    .then(async text => {
      const AsyncFunction = (async function () {}).constructor; // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/AsyncFunction
      const f = new AsyncFunction(Translator.getJsFromRobotc(text));
      if(!Translator.hasSensorPragma(text)) {
        getRightTouchControls().classList.add('d-none');
      }
      programStartTime = Date.now();
      await f();
    });
}
function onLoad() {
  setupEventHanlders();
  onResize();
  window.addEventListener('resize', onResize);  // this is triggered by zooming in on mobile, which may be undesirable
  const urlSearchParams = new URLSearchParams(window.location.search);
  const game = urlSearchParams.get('game');
  const action = urlSearchParams.get('action');
  if(game === null) {
    renderWebpage();
  } else {
    if(action === 'play') {
      playGame(game);
    } else {
      renderWebpage();
      setupGameModal(game.slice(0, -2));
      jQuery(".gameModal").modal();
    }
  }
}

function getZoomScalar() {
  return Math.min(
    // These two values should be equal, but I am taking the min anyway.
    getNxtDisplay().width / NXT_WIDTH_PIXELS,
    getNxtDisplay().height / NXT_HEIGHT_PIXELS
  );
}
function getTransformedCoords(x_nxt, y_nxt, amount_to_add = 0) {
  // Making amount_to_add 0 puts the coords at the top left of their NXT pixel
  // Making amount_to_add 0.5 centers the coords in their NXT pixel
  // Making amount_to_add 1 puts the coords at the bottom right of their NXT pixel
  return [
    x_nxt, getFlippedY(y_nxt)
  ].map(coord => (coord + amount_to_add) * getZoomScalar());
}
function getXywhFromXyxy(x1, y1, x2, y2) {
  return [x1, y1, x2 - x1, y2 - y1];
}
function getFlippedY(y_from_bottom) {
  return NXT_HEIGHT_PIXELS - 1 - y_from_bottom;
}

function getCanvasRectParametersFromNxtRectCoords(x1, y1, x2, y2, isStroke = false) {
  const [tx1, ty1] = getTransformedCoords(x1, y1);
  const [tx2, ty2] = getTransformedCoords(x2, y2);
  const min_x = Math.min(tx1, tx2);
  const max_x = Math.max(tx1, tx2);
  const min_y = Math.min(ty1, ty2);
  const max_y = Math.max(ty1, ty2);
  if (!isStroke) {
    return getXywhFromXyxy(
      min_x, min_y,
      max_x + getZoomScalar(), max_y + getZoomScalar()
    );
  } else {
    return getXywhFromXyxy(
      min_x + (0.5 * getZoomScalar()), min_y + (0.5 * getZoomScalar()),
      max_x + (0.5 * getZoomScalar()), max_y + (0.5 * getZoomScalar())
    );
  }
}

function getAssembledString(strWithPlaceholders, ...parameters) {
  let s = strWithPlaceholders;
  for (const param of parameters) {
    s = s.replace(/%./, param);
  }
  return s;
}
function drawString(passed_x, passed_y, assembledString, size, isLine, doCenter) {
  // size=1 means normal
  // size=2 means big

  // For a while I had this set to shifting the x by +1.
  // I did that for rpcrnly.c and no other reason.
  // But then I played rpcrnly.c on an actual NXT, and I was surprised to see that the cleared box for the rank text overlaps the right wall line with the default game parameters (width=63).
  // So I changed this to not shift x by +1, which looks messed up in rpcrnly.c, but is how it was in the original.
  const x = passed_x;

  // Shift y by +1 for non-line text; this makes it more like the actual NXT.
  const y = passed_y + (isLine ? 0 : 1);

  const ctx = getNxtDisplayContext();
  const lineHeight = size * NXT_LINE_HEIGHT_PIXELS * getZoomScalar();
  const fontSize = Math.round(lineHeight * NXT_LINE_HEIGHT_FONT_SCALAR);
  ctx.font = `${fontSize}px monospace`;
  ctx.fillStyle = NXT_BACKGROUND_COLOR;
  ctx.fillRect(
    ...getTransformedCoords(
      isLine ? 0 : x,
      y - (NXT_LINE_HEIGHT_PIXELS * 1.125),
      0
    ),
    isLine ? getNxtDisplay().width : ctx.measureText(assembledString).width,
    -lineHeight
  );
  ctx.fillStyle = NXT_ACTIVE_PIXEL_COLOR;
  let [cx, cy] = getTransformedCoords(x, y - NXT_LINE_HEIGHT_PIXELS, 0);
  if(doCenter) {
    cx = (getNxtDisplay().width - ctx.measureText(assembledString).width) / 2;
  }
  ctx.fillText(
    assembledString,
    cx,
    cy
  );
}
function drawTextLine(lineNumber, assembledString, size, doCenter) {
  drawString(
    0,
    NXT_HEIGHT_PIXELS - (lineNumber * NXT_LINE_HEIGHT_PIXELS),
    assembledString,
    size,
    true,
    doCenter
  );
}
function doEllipsePath(ctx, x1, y1, x2, y2) {
  ctx.beginPath();
  const [bx1, by1] = getTransformedCoords(x1, y1, 0.5);
  const [bx2, by2] = getTransformedCoords(x2, y2, 0.5);
  ctx.ellipse((bx1 + bx2) / 2, (by1 + by2) / 2, Math.abs(bx1 - bx2) / 2, Math.abs(by1 - by2) / 2, 0, 0, 2 * Math.PI);
}
function normalize(x, y) {
  const length = Math.sqrt((x*x)+(y*y));
  return [x / length, y / length];
}


// CODE TO BE USED BY THE ROBOTC CODE
var nNxtButtonPressed = -1;
const T1 = "T1"; const T2 = "T2"; const T3 = "T3"; const T4 = "T4";
const S1 = "S1";
function gettouchsensorvalue() {
  return touchSensorPressed ? 1 : 0;
}
function nxtdrawline(xi, yi, xf, yf) {
  const ctx = getNxtDisplayContext();
  ctx.strokeStyle = NXT_ACTIVE_PIXEL_COLOR;
  ctx.lineWidth = getZoomScalar();
  ctx.lineCap = "square";
  ctx.beginPath();
  ctx.moveTo(...getTransformedCoords(xi, yi, 0.5));
  ctx.lineTo(...getTransformedCoords(xf, yf, 0.5));
  ctx.stroke();
}
function nxteraserect(x1, y1, x2, y2) {
  const ctx = getNxtDisplayContext();
  ctx.fillStyle = NXT_BACKGROUND_COLOR;
  ctx.fillRect(...getCanvasRectParametersFromNxtRectCoords(x1, y1, x2, y2));
}
function nxtfillrect(x1, y1, x2, y2) {
  const ctx = getNxtDisplayContext();
  ctx.fillStyle = NXT_ACTIVE_PIXEL_COLOR;
  ctx.fillRect(...getCanvasRectParametersFromNxtRectCoords(x1, y1, x2, y2));
}
function nxtdrawrect(x1, y1, x2, y2) {
  const ctx = getNxtDisplayContext();
  ctx.strokeStyle = NXT_ACTIVE_PIXEL_COLOR;
  ctx.lineWidth = getZoomScalar();
  ctx.strokeRect(...getCanvasRectParametersFromNxtRectCoords(x1, y1, x2, y2, true));
}
function nxtdrawellipse(x1, y1, x2, y2) {
  const ctx = getNxtDisplayContext();
  ctx.strokeStyle = NXT_ACTIVE_PIXEL_COLOR;
  doEllipsePath(ctx, x1, y1, x2, y2);
  ctx.stroke();
}
function nxtfillellipse(x1, y1, x2, y2) {
  const ctx = getNxtDisplayContext();
  ctx.fillStyle = NXT_ACTIVE_PIXEL_COLOR;
  doEllipsePath(ctx, x1, y1, x2, y2);
  ctx.fill();
}
function nxtsetpixel(x, y) {
  const ctx = getNxtDisplayContext();
  ctx.fillStyle = NXT_ACTIVE_PIXEL_COLOR;
  ctx.fillRect(...getCanvasRectParametersFromNxtRectCoords(x, y, x + 1, y + 1));
}
function nxtclearpixel(x, y) {
  const ctx = getNxtDisplayContext();
  ctx.fillStyle = NXT_BACKGROUND_COLOR;
  ctx.fillRect(...getCanvasRectParametersFromNxtRectCoords(x, y, x + 1, y + 1));
}
function erasedisplay() {
  nxteraserect(0, 0, NXT_WIDTH_PIXELS - 1, NXT_HEIGHT_PIXELS - 1);
}
async function wait1msec(numberOfMilliseconds) {
  await new Promise(resolve => { setTimeout(resolve, numberOfMilliseconds); });
}
async function wait10msec(numberOfCentiseconds) {
  await wait1msec(10 * numberOfCentiseconds);
}
function nxtdisplaystringat(x, y, string, ...params) {
  drawString(x, y, getAssembledString(string, ...params), 1, false);
}
function nxtdisplaybigstringat(x, y, string, ...params) {
  drawString(x, y, getAssembledString(string, ...params), 2, false);
}
function nxtdisplaytextline(lineNumber, string, ...params) {
  drawTextLine(lineNumber, getAssembledString(string, ...params), 1, false);
}
function nxtdisplaycenteredtextline(lineNumber, string, ...params) {
  drawTextLine(lineNumber, getAssembledString(string, ...params), 1, true);
}
function nxtdisplaybigtextline(lineNumber, string, ...params) {
  drawTextLine(lineNumber, getAssembledString(string, ...params), 2, false);
}
function nxtdisplaycenteredbigtextline(lineNumber, string, ...params) {
  drawTextLine(lineNumber, getAssembledString(string, ...params), 2, true);
}
function random(maximum) {
  return Math.floor(Math.random() * (maximum + 1));
}
function sqrt(number) {
  return Math.sqrt(number);
}
function floor(number) {
  return Math.floor(number);
}
function starttask(taskToStart) {
  taskToStart();
}
const TIMERS = Object.create(null);
let programStartTime = null;
function time1(timerKey) {
  if(timerKey in TIMERS) {
    return Math.floor(Date.now() - TIMERS[timerKey]);
  } else {
    return Math.floor(Date.now() - programStartTime);
  }
}
function time10(timerKey) {return Math.floor(time1(timerKey) / 10);}
function time100(timerKey) {return Math.floor(time1(timerKey) / 100);}
function cleartimer(timerKey) {
  TIMERS[timerKey] = Date.now();
}
const soundFastUpwardTones = 'sounds/fastUpwardTones.mov';
const soundBlip = 'sounds/blip.mov';
function playsound(sound) {
  var audio = new Audio(sound);
  audio.play();
}
const joystick = {
  joy1_x1: 0,
  joy1_y1: 0
};
function getjoysticksettings(j) {
  j.joy1_x1 = 0;
  j.joy1_y1 = 0;
  switch(nNxtButtonPressed) {
    case NXT_BUTTON_DOWN:
      j.joy1_y1 = -127;
      break;
    case NXT_BUTTON_RIGHT:
      j.joy1_x1 = 127;
      break;
    case NXT_BUTTON_LEFT:
      j.joy1_x1 = -127;
      break;
    case NXT_BUTTON_UP:
      j.joy1_y1 = 127;
      break;
  }
}
function joy1btn(btnNumber) {
  return joyButtonsPressed[btnNumber] ? 1 : 0;
}


