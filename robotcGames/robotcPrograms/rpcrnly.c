
// 0 - comX
// 1 - comYreallyBig
// 2 - comYBig
// 3 - comYlittle
// 4 - comSpeedReallyBig
// 5 - comSpeedBig
// 6 - comSpeed
// 7 - comShotX
// 8 - comShotYbig
// 9 - comShotYlittle




task main(){
char comdata [180];
float com1y;
float com2y;
float com3y;
float com4y;
float com5y;
float com6y;
float com7y;
float com8y;
float com9y;
float com10y;
float com11y;
float com12y;
float com13y;
float com14y;
float com15y;
float com16y;
float com17y;
float com18y;
//float com1o;
//float com2o;
//float com3o;
//float com4o;
//float com5o;
//float com6o;
//float com7o;
//float com8o;
//float com9o;
//float com10o;
//float com11o;
//float com12o;
//float com13o;
//float com14o;
//float com15o;
//float com16o;
//float com17o;
//float com18o;
float com1q;
float com2q;
float com3q;
float com4q;
float com5q;
float com6q;
float com7q;
float com8q;
float com9q;
float com10q;
float com11q;
float com12q;
float com13q;
float com14q;
float com15q;
float com16q;
float com17q;
float com18q;
short px = 15;
int py = -30000;
bool cont = false;
int scroll = -30765;
float speed = 0;
int linedraw = -30765;
int shotX = 70;
int shotY = -29000;
int n;
float m;
float o;
float p;
int q;
int n2;
float m2;
float o2;
float o2s;
int q2;
int pSideCollision;
//bool pchinkbreak = false;
//bool cChinkbreak = false;
bool comAIbool1 = false;
bool comAIbool2 = false;
int lastn; //  if com:n  if player:99
long lastnY; // Y of last placer
int countforAI;
int trackwidth = 63;
int numberOfComs = 7;
int yourRank;
int nearShotYDif = 100;
int shotspeed = 18;
int racelength = 60;//time
int score = 0;
int count100 = 0;
int cheatyness = 0;
bool cheaty = false;
bool exit = false;
char pointsForPlace[9];
char comRanks[18];
char comScores[18];
char AIbools [18];
nNxtExitClicks = 5;

comdata [0] = 15;
comdata [10] = 15;
comdata [20] = 15;
comdata [30] = 15;
comdata [40] = 15;
comdata [50] = 15;
comdata [60] = 15;
comdata [70] = 15;

comdata [1] = 0;
comdata [11] = 0;
comdata [21] = 0;
comdata [31] = 0;
comdata [41] = 0;
comdata [51] = 0;
comdata [61] = 0;
comdata [71] = 0;

comdata [2] = 24;
comdata [12] = 28;
comdata [22] = 29;
comdata [32] = 23;
comdata [42] = 26;
comdata [52] = 25;
comdata [62] = 22;
comdata [72] = 21;

comdata [3] = 70;
comdata [13] = 80;
comdata [23] = 80;
comdata [33] = 80;
comdata [43] = 80;
comdata [53] = 80;
comdata [63] = 80;
comdata [73] = 80;

comdata [7] = 50;
comdata [17] = 20;
comdata [27] = 20;
comdata [37] = 20;
comdata [47] = 20;
comdata [57] = 20;
comdata [67] = 20;
comdata [77] = 20;

comdata [8] = 0;
comdata [18] = 0;
comdata [28] = 0;
comdata [38] = 0;
comdata [48] = 0;
comdata [58] = 0;
comdata [68] = 0;
comdata [78] = 0;

comdata [9] = 0;
comdata [19] = 0;
comdata [29] = 0;
comdata [39] = 0;
comdata [49] = 0;
comdata [59] = 0;
comdata [69] = 0;
comdata [79] = 0;



pointsForPlace[1] = 10;
pointsForPlace[2] = 6;
pointsForPlace[3] = 5;
pointsForPlace[4] = 4;
pointsForPlace[5] = 3;
pointsForPlace[6] = 2;
pointsForPlace[7] = 1;
pointsForPlace[8] = 0;




nxtDisplayBigStringAt(10, 40, "RPCRNLY");
wait1Msec(1000);

while(cont == false){

  if(nNxtButtonPressed == 1){
    m = 1;
  }else if(m == 1){
    n = n + 1;
    m = 0;
  }
  if(nNxtButtonPressed == 2){
    m = 2;
  }else if(m == 2){
    n = n - 1;
    m = 0;
  }



  if(nNxtButtonPressed == 3){
    if(n == 0){
      cont = true;
    }
    if(n == 1){
      exit = true;
      cont = true;
    }
    if(n == 2){

      while(nNxtButtonPressed == 3){
        eraseDisplay();
        nxtDisplayBigStringAt(10, 35, "okay");
        wait1Msec(20);
      }

      while(nNxtButtonPressed != 3){
        if(nNxtButtonPressed == 1){
          trackwidth = trackwidth + 1;
        }
        if(nNxtButtonPressed == 2){
          trackwidth = trackwidth - 1;
        }
        if(trackwidth > 95){
          trackwidth = 95;
        }
        if(trackwidth < 23){
          trackwidth = 23;
        }
        eraseDisplay();
        nxtDisplayStringAt(10, 50, "choose the");
        nxtDisplayStringAt(10, 40, "track width");
        nxtDisplayStringAt(10, 30, "23-95");
        nxtDisplayBigStringAt(10, 20, "%d", trackwidth);
        wait1Msec(100);
      }

      while(nNxtButtonPressed == 3){
        eraseDisplay();
        nxtDisplayBigStringAt(10, 35, "okay");
        wait1Msec(20);
      }

      while(nNxtButtonPressed != 3){
        if(nNxtButtonPressed == 1){
          numberOfComs = numberOfComs + 1;
        }
        if(nNxtButtonPressed == 2){
          numberOfComs = numberOfComs - 1;
        }
        if(numberOfComs > 7){
          numberOfComs = 7;
        }
        if(numberOfComs < 0){
          numberOfComs = 0;
        }
        eraseDisplay();
        nxtDisplayStringAt(10, 50, "choose the");
        nxtDisplayStringAt(10, 40, "number of coms");
        nxtDisplayStringAt(10, 30, "0-7");
        nxtDisplayBigStringAt(10, 20, "%d", numberOfComs);
        wait1Msec(100);
      }

      while(nNxtButtonPressed == 3){
        eraseDisplay();
        nxtDisplayBigStringAt(10, 35, "okay");
        wait1Msec(20);
      }

      while(nNxtButtonPressed != 3){
        if(nNxtButtonPressed == 1){
          shotspeed = shotspeed + 1;
        }
        if(nNxtButtonPressed == 2){
          shotspeed = shotspeed - 1;
        }
        if(shotspeed > 40){
          shotspeed = 40;
        }
        if(shotspeed < 15){
          shotspeed = 15;
        }
        eraseDisplay();
        nxtDisplayStringAt(10, 50, "choose the");
        nxtDisplayStringAt(10, 40, "speed of shots");
        nxtDisplayStringAt(10, 30, "15-40");
        nxtDisplayBigStringAt(10, 20, "%d", shotspeed);
        wait1Msec(100);
      }

      while(nNxtButtonPressed == 3){
        eraseDisplay();
        nxtDisplayBigStringAt(10, 35, "okay");
        wait1Msec(20);
      }


      while(nNxtButtonPressed != 3){
        if(nNxtButtonPressed == 1){
          cheatyness = cheatyness + 1;
        }
        if(nNxtButtonPressed == 2){
          cheatyness = cheatyness - 1;
        }
        if(cheatyness > 100){
          cheatyness = 100;
        }
        if(cheatyness < 0){
          cheatyness = 0;
        }
        eraseDisplay();
        nxtDisplayStringAt(10, 50, "choose the");
        nxtDisplayStringAt(10, 40, "cheatyness");
        nxtDisplayStringAt(10, 30, "0-100");
        nxtDisplayBigStringAt(10, 20, "%d", cheatyness);
        wait1Msec(100);
      }

      if(cheatyness <= 0){
        cheaty = false;
      }else{
        cheaty = true;
      }

      while(nNxtButtonPressed == 3){
        eraseDisplay();
        nxtDisplayBigStringAt(10, 35, "okay");
        wait1Msec(20);
      }

    }
    if(n == 3){

      while(nNxtButtonPressed == 3){
        eraseDisplay();
        nxtDisplayBigStringAt(10, 35, "okay");
        wait1Msec(20);
      }

      while(nNxtButtonPressed != 3 && nNxtButtonPressed != 0){
        if(nNxtButtonPressed == 1){
          m = 1;
        }else if(m == 1){
          o = o + 1;
          m = 0;
        }
        if(nNxtButtonPressed == 2){
          m = 2;
        }else if(m == 2){
          o = o - 1;
          m = 0;
        }

        if(o < 0){
          o = 0;
        }
        if(o > 3){
          o = 3;
        }

        eraseDisplay();
        nxtDisplayCenteredTextLine(0, "info");
        if(o == 0){
          nxtDisplayTextLine(1, "Rpcrnly is");
          nxtDisplayTextLine(2, "a cheat code");
          nxtDisplayTextLine(3, "for the");
          nxtDisplayTextLine(4, "original");
          nxtDisplayTextLine(5, "LEGO racers");
          nxtDisplayTextLine(6, "game for PC.");
          nxtDisplayTextLine(7, "This NXT game");
        }
        if(o == 1){
          nxtDisplayTextLine(1, "is based on");
          nxtDisplayTextLine(2, "what it does.");
          nxtDisplayTextLine(3, "In this NXT game,");
          nxtDisplayTextLine(4, "the player is");
          nxtDisplayTextLine(5, "the larger");
          nxtDisplayTextLine(6, "rectangle that");
          nxtDisplayTextLine(7, "is not filled.");
        }
        if(o == 2){
          nxtDisplayTextLine(1, "The player and");
          nxtDisplayTextLine(2, "the opponents");
          nxtDisplayTextLine(3, "can shoot smaller");
          nxtDisplayTextLine(4, "rectangles.");
          nxtDisplayTextLine(5, "If one of these");
          nxtDisplayTextLine(6, "hits someone");
          nxtDisplayTextLine(7, "that didn't");
        }
        if(o == 3){
          nxtDisplayTextLine(1, "shoot it, it will");
          nxtDisplayTextLine(2, "grab what it hits");
          nxtDisplayTextLine(3, "and pull them");
          nxtDisplayTextLine(4, "backward");
          nxtDisplayTextLine(5, "while pulling");
          nxtDisplayTextLine(6, "whoever shot it");
          nxtDisplayTextLine(7, "forward.");
        }

        nxtDrawLine(0, 55, 100, 55);

        wait1Msec(20);
      }
      while(nNxtButtonPressed == 3){
        wait1Msec(20);
      }

    }
  }



  if(n < 0){
    n = 3;
  }
  if(n > 3){
    n = 0;
  }

  eraseDisplay();
  nxtDisplayCenteredTextLine(0, "rpcrnly");
  nxtDrawLine(0, 55, 100, 55);
  if(n == 0){
    nxtDisplayStringAt(20, 30, "Play");
  }
  if(n == 1){
    nxtDisplayStringAt(20, 30, "Exit");
  }
  if(n == 2){
    nxtDisplayStringAt(20, 30, "Edit");
    nxtDisplayStringAt(20, 20, "Parameters");
  }
  if(n == 3){
    nxtDisplayStringAt(20, 30, "Info");
  }
  //nxtDisplayCenteredTextLine(1, "choose what");
  //nxtDisplayCenteredTextLine(2, "you want");
	//nxtDisplayCenteredTextLine(3, "to do");
  //nxtDisplayCenteredTextLine(2, "to do");

  nxtDrawLine(3, 25, 15, 35);
  nxtDrawLine(3, 25, 15, 15);
  nxtDrawLine(15, 35, 15, 15);

  nxtDrawLine(97, 25, 85, 35);
  nxtDrawLine(97, 25, 85, 15);
  nxtDrawLine(85, 35, 85, 15);

  wait1Msec(50);
}

while(nNxtButtonPressed == 3){
  eraseDisplay();
  nxtDisplayBigStringAt(10, 35, "okay");
  wait1Msec(20);
}

if(exit == true){
  cont = false;
}




ClearTimer(T2);




while(cont == true){

  if(nNxtButtonPressed == 1){
    if(pSideCollision != 2){
      px = px + 1;
    }
  }
  if(nNxtButtonPressed == 2){
    if(pSideCollision != 1){
      px = px - 1;
    }
  }

  speed = speed + 2;
  speed = speed - (0.01 * speed);

  if(nNxtButtonPressed == 0 && speed > -40){
    while(nNxtButtonPressed != 3){
      eraseDisplay();
      nxtDisplayCenteredTextLine(0, "paused");
      nxtDisplayCenteredTextLine(1, "press the");
      nxtDisplayCenteredTextLine(2, "orange button");
      nxtDisplayCenteredTextLine(3, "to continue");
      nxtDisplayCenteredTextLine(5, "press the grey");
      nxtDisplayCenteredTextLine(6, "button a bunch");
      nxtDisplayCenteredTextLine(7, "to quit");
      nxtDrawLine(0, 55, 100, 55);
      wait1Msec(100);
    }
    while(nNxtButtonPressed == 3){
      wait1Msec(50);
    }
  }
  if(px > trackwidth - 3){
    px = px - 1;
  }
  if(px < 8){
    px = px + 1;
  }
  while(py > scroll + 300){
    scroll = scroll + 10;
  }

  if(nNxtButtonPressed == 3 && shotY - py >= 1000){
    shotX = px;
    shotY = py;
  }


  if(lastn == 99){
    speed = speed + 3;
  }

  py = speed / 20 + py;


  shotY = shotY + shotspeed;


  if(count100 == 50){
    score = score + pointsForPlace[yourRank];
  }


  if(time100[T2] / 10 >= racelength){
    cont = false;
  }




  if(count100 >= 100){
    count100 = 0;
  }

  count100 = count100 + 1;




  nearShotYDif = 1000;

  if(countforAI >= 5){
    countforAI = 0;
  }else{
    countforAI = countforAI + 1;
  }

  yourRank = 1;

  lastn = 99;//  99 - player
  lastnY = py + 32768;

  pSideCollision = 0;
  n = 0;
  while(n <= numberOfComs * 10 - 1){

    if(AIbools[n / 10] == 0){
      comAIbool1 = false;
      comAIbool2 = false;
    }
    if(AIbools[n / 10] == 1){
      comAIbool1 = true;
      comAIbool2 = false;
    }
    if(AIbools[n / 10] == 2){
      comAIbool1 = false;
      comAIbool2 = true;
    }


    q = comdata [n + 8];
    q = q * 100;
    q = q + comdata [n + 9];

    q = q + shotspeed;



    o = comdata [n + 4];
    o = o * 10;
    o = o + (0.1 * comdata [n + 5]);
    o = o + (0.001 * comdata [n + 6]);

    o = o + 2;
    o = o - (0.01 * o);



    m = comdata [n + 1];
    m = m * 10000;
    m = m + (100 * comdata [n + 2]);
    m = m + comdata [n + 3];

    m = o / 20 + m;
    q = -(o / 20) + q;




    if(q > 9999){
      q = 9000;
    }




    if(m < lastnY){
      lastn = n;
      lastnY = m;
    }




    if(m - 32768 > py){
      yourRank = yourRank + 1;
    }



    if(count100 == 50){
      comScores[n / 10] = comScores[n / 10] + pointsForPlace[comRanks[n / 10]];
    }



    if(m - 32768 <= py + 60){
      if(m - 32768 >= py - 60){
        if(comdata[n] <= px + 11){
          if(comdata[n] >= px + 10){
            pSideCollision = 2;
          }
        }
        if(comdata[n] >= px - 11){
          if(comdata[n] <= px - 10){
            pSideCollision = 1;
          }
        }
      }
    }

    //pchinkbreak = false;
    //cChinkbreak = false;
    if(m - 32768 <= py + 60){
      if(m - 32768 >= py - 60){
        if(comdata[n] <= px + 9){
          if(comdata[n] >= px - 9){
            p = speed;
            speed = o;
            o = p;

            m = o / 20 + m;
            q = o / 20 + q;

            py = speed / 20 + py;

            if(py > m - 32768){
              py = py + 5;
              m = m - 5;
            }else{
              py = py - 5;
              m = m + 5;
            }

            //pchinkbreak = true;
            //cChinkbreak = true;
          }
        }
      }
    }








    if(shotY - py <= 1000){
      if(shotY + 32768 <= m + 50){
        if(shotY + 32768 >= m - 50){
          if(shotX <= comdata[n] + 5){
            if(shotX >= comdata[n] - 5){
              if(m - 32768 > py){
                shotX = comdata[n];
                shotY = m - 32768;
                speed = speed + 5;
                o = o - 5;
                //if(pchinkbreak == true){
                //  shotX = 120;
                //  shotY = py + 1500;
                //}
              }
              else{
                shotX = 120;
                shotY = py + 1500;
              }
            }
          }
        }
      }
    }




    if(q <= 1000){
      if(q + m - 32768 <= py + 50){
        if(q + m - 32768 >= py - 50){
          if(comdata[n + 7] <= px + 5){
            if(comdata[n + 7] >= px - 5){
              if(py + 32768 > m){
                comdata[n + 7] = px;
                q = py + 32768 - m;
                o = o + 5;
                speed = speed - 5;

                //if(cChinkbreak == true){
                //  comdata[n + 7] = 120;
                //  q = 1500;
                //}
              }
              else{
                comdata[n + 7] = 120;
                q = 1500;
              }
            }
          }
        }
      }
    }





    if(countforAI == 3){
      if(py - m + 32768 <= 300){               // AI
        if(py - m + 32768 > 0){
          if(px <= comdata[n] + 4){
            if(px >= comdata[n] - 4){
              if(q > 1000){
                q = 2;
                comdata[n + 7] = comdata[n];
              }
            }
          }
        }
      }



      if(comAIbool1 == false && comAIbool2 == false){/////////com n aim for com n2  (AI)
        if(m + 60 < py + 32768){
          if(m > py + 32768 - 300){
            if(comdata[n] < px){
              comAIbool2 = true;
            }else{
              comAIbool1 = true;
            }
          }
        }
      }


      if(comdata[n] >= trackwidth - 18){///////////////com n get space from right wall  (AI)
        comAIbool1 = true;
        comAIbool2 = false;
      }
      if(comdata[n] <= 25){///////////////com n get space from left wall  (AI)
        comAIbool1 = false;
        comAIbool2 = true;
      }
    }



    if(cheaty == true){
      if(m < py + 32768 - 1400 + (cheatyness * 10)){
        m = m + 1;
        q = q - 1;

        o = o + 3;
      }
    }



    comRanks[n / 10] = 1;



    n2 = 0;
    while(n2 <= numberOfComs * 10 - 1){

      if(n2 == n){
        n2 = n2 + 10;
        if(n2 > 59){
          break;
        }
      }

      q2 = comdata [n2 + 8] * 100 + comdata [n2 + 9];

      m2 = comdata [n2 + 1];
      m2 = m2 * 10000;
      m2 = m2 + (100 * comdata [n2 + 2]);
      m2 = m2 + comdata [n2 + 3];

      o2 = comdata [n2 + 4];
      o2 = o2 * 10;
      o2 = o2 + (0.1 * comdata [n2 + 5]);
      o2 = o2 + (0.001 * comdata [n2 + 6]);





      if(m < m2){
        comRanks[n / 10] = comRanks[n / 10] + 1;
      }




      if(countforAI == 3){
        if(m2 - m <= 300){                                            // AI
          if(m2 - m > 0){
            if(comdata[n2] <= comdata[n] + 7){
              if(comdata[n2] >= comdata[n] - 7){
                if(q > 1000){
                  q = 2;
                  comdata[n + 7] = comdata[n];
                }
              }
            }
          }
        }
      }







      if(m <= m2 + 60){
        if(m >= m2 - 60){
          if(comdata[n] <= comdata[n2] + 9){
            if(comdata[n] >= comdata[n2] - 9){
              p = o2;
              o2 = o;
              o = p;

              //m = o / 20 + m;
              //q = -(o / 20) + q;
              //m = o / 20 + m;
              //q = -(o / 20) + q;

              //m2 = o2 / 20 + m2;
              //m2 = o2 / 20 + m2;


              if(m < m2){
                m = m - 11;
              }else{
                m = m + 11;
              }


              o2s = o2;
              p = 0;
              while(o2s >= 100){
                p = p + 10;
                o2s = o2s - 100;
              }
              while(o2s >= 10){
                p = p + 1;
                o2s = o2s - 10;
              }
              comdata [n2 + 4] = p;
              p = 0;
              while(o2s >= 1){
                p = p + 10;
                o2s = o2s - 1;
              }
              while(o2s >= 0.1){
                p = p + 1;
                o2s = o2s - 0.1;
              }
              comdata [n2 + 5] = p;
              p = 0;
              while(o2s >= 0.01){
                p = p + 10;
                o2s = o2s - 0.01;
              }
              while(o2s >= 0.001){
                p = p + 1;
                o2s = o2s - 0.001;
              }
              comdata [n2 + 6] = p;


              //cChinkbreak = true;
            }
          }
        }
      }






      if(q <= 1000){
        if(q + m <= m2 + 50){
          if(q + m >= m2 - 50){
            if(comdata[n + 7] <= comdata[n2] + 5){
              if(comdata[n + 7] >= comdata[n2] - 5){
                if(m2 >= m){
                  comdata[n + 7] = comdata[n2];
                  q = m2 - m;
                  o = o + 5;
                  o2 = o2 - 5;

                  if(o2 < 0){
                    o2 = 0;
                  }

                  p = 0;
                  while(o2 >= 100){
                    p = p + 10;
                    o2 = o2 - 100;
                  }
                  while(o2 >= 10){
                    p = p + 1;
                    o2 = o2 - 10;
                  }
                  comdata [n2 + 4] = p;
                  p = 0;
                  while(o2 >= 1){
                    p = p + 10;
                    o2 = o2 - 1;
                  }
                  while(o2 >= 0.1){
                    p = p + 1;
                    o2 = o2 - 0.1;
                  }
                  comdata [n2 + 5] = p;
                  p = 0;
                  while(o2 >= 0.01){
                    p = p + 10;
                    o2 = o2 - 0.01;
                  }
                  while(o2 >= 0.001){
                    p = p + 1;
                    o2 = o2 - 0.001;
                  }
                  comdata [n2 + 6] = p;


                }
                else{
                  comdata[n + 7] = 120;
                  q = 1500;
                }
              }
            }
          }
        }
      }

      if(q2 <= 1000){
        if(q2 + m2 <= m + 50){
          if(q2 + m2 >= m - 50){
            if(comdata[n2 + 7] <= comdata[n] + 5){
              if(comdata[n2 + 7] >= comdata[n] - 5){
                if(m > m2){
                  //comdata[n2 + 7] = comdata[n];
                  //q = m2 - m;
                  //o = o + 5;
                  o = o - 5;
                }
                //else{
                  //comdata[n + 7] = 120;
                  //q = 1500;
                //}
              }
            }
          }
        }
      }



      if(countforAI == 3){
        if(comAIbool1 == false && comAIbool2 == false){/////////com n aim for com n2  (AI)
          if(m + 60 < m2){
            if(m > m2 - 300){
              if(comdata[n] < comdata[n2]){
                comAIbool2 = true;
              }else{
                comAIbool1 = true;
              }
            }
          }
        }


        if(q2 + m2 < m + 60){/////////////////com n dodge com n2's shot   (AI)
          if(q2 + m2 >= m - 300){
            if(comdata[n2 + 7] < comdata[n] + 15){
              if(comdata[n2 + 7] > comdata[n] - 15){
                if(m - (q2 + m2) < nearShotYDif){
                  nearShotYDif = m - (q2 + m2);
                  if(comdata[n2 + 7] > comdata[n]){
                    comAIbool1 = true;
                    comAIbool2 = false;
                  }else if(comdata[n2 + 7] < comdata[n]){
                    comAIbool1 = false;
                    comAIbool2 = true;
                  }else if(comdata[n2 + 7] == comdata[n]){
                    if(random(100) > 50){
                      comAIbool1 = true;
                      comAIbool2 = false;
                    }else{
                      comAIbool1 = false;
                      comAIbool2 = true;
                    }
                  }
                }
              }
            }
          }
        }



        if(o > o2 + 20){///////////////////////com n steer around com n2
          if(m <= m2 + 40){
            if(m >= m2 - 250){
              if(comdata[n] <= comdata[n2] + 20){
                if(comdata[n] >= comdata[n2] - 20){
                  if(comdata[n] > comdata[n2]){
                    comAIbool1 = false;
                    comAIbool2 = true;
                  }else{
                    comAIbool1 = true;
                    comAIbool2 = false;
                  }
                }
              }
            }
          }
        }
      }



      if(m <= m2 + 60){
        if(m >= m2 - 60){
          if(comdata[n] <= comdata[n2] + 11){
            if(comdata[n] >= comdata[n2] - 11){
              if(comdata[n] >= comdata[n2] + 10){
                if(comAIbool1 == true){
                  comAIbool1 = false;
                }
              }
              if(comdata[n] <= comdata[n2] - 10){
                if(comAIbool2 == true){
                  comAIbool2 = false;
                }
              }
            }
          }
        }
      }




      n2 = n2 + 10;
    }



    if(countforAI == 3){
      if(shotY + 32768 < m + 60){/////////////////com n dodge player's shot   (AI)
        if(shotY + 32768 >= m - 300){
          if(shotX < comdata[n] + 15){
            if(shotX > comdata[n] - 15){
              if(m - (shotY + 32768) < nearShotYDif){
                nearShotYDif = m - shotY + 32768;
                if(shotX > comdata[n]){
                  comAIbool1 = true;
                  comAIbool2 = false;
                }else if(shotX < comdata[n]){
                  comAIbool1 = false;
                  comAIbool2 = true;
                }else if(shotX == comdata[n]){
                  if(random(100) > 50){
                    comAIbool1 = true;
                    comAIbool2 = false;
                  }else{
                    comAIbool1 = false;
                    comAIbool2 = true;
                  }
                }
              }
            }
          }
        }
      }


      if(o > speed + 20){///////////////////////com n steer around player
        if(m <= py + 32768 + 40){
          if(m >= py + 32768 - 250){
            if(comdata[n] <= px + 20){
              if(comdata[n] >= px - 20){
                if(comdata[n] > px){
                  comAIbool1 = false;
                  comAIbool2 = true;
                }else{
                  comAIbool1 = true;
                  comAIbool2 = false;
                }
              }
            }
          }
        }
      }
    }




    if(m <= py + 32768 + 60){
      if(m >= py + 32768 - 60){
        if(comdata[n] <= px + 11){
          if(comdata[n] >= px - 11){
            if(comdata[n] >= px + 10){
              if(comAIbool1 == true){
                comAIbool1 = false;
              }
            }
            if(comdata[n] <= px - 10){
              if(comAIbool2 == true){
                comAIbool2 = false;
              }
            }
          }
        }
      }
    }


    if(comAIbool2 == true){
      if(comdata[n] >= trackwidth - 3){
        comAIbool2 = false;
      }
    }
    if(comAIbool1 == true){
      if(comdata[n] <= 8){
        comAIbool1 = false;
      }
    }


    if(comAIbool1 == false){                             // r/l AI active steps
      if(comAIbool2 == false){
        // nothing happens
      }else{ // if(comAIbool2 == true){
        comdata[n] = comdata[n] + 1;
      }
    }
    if(comAIbool1 == true){
      if(comAIbool2 == false){
        comdata[n] = comdata[n] - 1;
      }else{ // if(comAIbool2 == true){
        // this shouldn't happen
      }
    }

    if(comAIbool1 == false && comAIbool2 == false){
      AIbools[n / 10] = 0;
    }
    if(comAIbool1 == true && comAIbool2 == false){
      AIbools[n / 10] = 1;
    }
    if(comAIbool1 == false && comAIbool2 == true){
      AIbools[n / 10] = 2;
    }







    p = o;
    o = 0;
    while(p >= 100){
      o = o + 10;
      p = p - 100;
      if(p > 500){
        o = o + 50;
        p = p - 500;
      }
    }
    while(p >= 10){
      o = o + 1;
      p = p - 10;
      if(p > 50){
        o = o + 5;
        p = p - 50;
      }
    }
    comdata [n + 4] = o;
    o = 0;
    if(p >= 5){
        o = o + 50;
        p = p - 5;
    }
    while(p >= 1){
      o = o + 10;
      p = p - 1;
    }
    if(p >= 0.5){
        o = o + 5;
        p = p - 0.5;
    }
    while(p >= 0.1){
      o = o + 1;
      p = p - 0.1;
    }
    comdata [n + 5] = o;
    o = 0;
    if(p >= 0.05){
        o = o + 50;
        p = p - 0.05;
    }
    while(p >= 0.01){
      o = o + 10;
      p = p - 0.01;
    }
    if(p >= 0.005){
        o = o + 5;
        p = p - 0.005;
    }
    while(p >= 0.001){
      o = o + 1;
      p = p - 0.001;
    }
    comdata [n + 6] = o;


    o = 0;
    if(m >= 50000){
        o = o + 5;
        m = m - 50000;
    }
    while(m >= 10000){
      o = o + 1;
      m = m - 10000;
    }
    comdata [n + 1] = o;
    o = 0;
    if(m >= 5000){
        o = o + 50;
        m = m - 5000;
    }
    while(m >= 1000){
      o = o + 10;
      m = m - 1000;
    }
    if(m >= 500){
        o = o + 5;
        m = m - 500;
    }
    while(m >= 100){
      o = o + 1;
      m = m - 100;
    }
    comdata [n + 2] = o;
    o = 0;
    if(m >= 50){
        o = o + 50;
        m = m - 50;
    }
    while(m >= 10){
      o = o + 10;
      m = m - 10;
    }
    if(m >= 5){
        o = o + 5;
        m = m - 5;
    }
    while(m >= 1){
      o = o + 1;
      m = m - 1;
    }
    comdata [n + 3] = o;


    o = 0;
    if(q >= 5000){
        o = o + 50;
        q = q - 5000;
    }
    while(q >= 1000){
      o = o + 10;
      q = q - 1000;
    }
    if(q >= 500){
        o = o + 5;
        q = q - 500;
    }
    while(q >= 100){
      o = o + 1;
      q = q - 100;
    }
    comdata [n + 8] = o;
    o = 0;
    if(q >= 50){
        o = o + 50;
        q = q - 50;
    }
    while(q >= 10){
      o = o + 10;
      q = q - 10;
    }
    if(q >= 5){
        o = o + 5;
        q = q - 5;
    }
    while(q >= 1){
      o = o + 1;
      q = q - 1;
    }
    comdata [n + 9] = o;



    n = n + 10;
  }




  comdata[lastn + 5] = comdata[lastn + 5] + 30;




  eraseDisplay();
  nxtDrawRect(px - 5, (py - scroll) / 10 + 3, px + 5, (py - scroll) / 10 - 3);
  nxtEraseRect(92, 0, 100, 10);
  nxtDrawLine(92, 0, 92, 10);
  nxtDrawLine(100, 10, 93, 10);
  if(shotY - py < 1000){
    nxtDrawRect(shotX + 1, (shotY - scroll) / 10 + 2, shotX - 1, (shotY - scroll) / 10 - 2);
  }else{
    nxtDrawRect(96 + 1, 5 + 2, 96 - 1, 5 - 2);
  }
  nxtDrawLine( trackwidth + 2, 64, trackwidth + 2, 0);
  nxtDrawLine( 3, 64, 3, 0);
  while(linedraw < py + 600){
  linedraw = linedraw + 100;
  nxtDrawLine(0, (linedraw - scroll) / 10, 3, (linedraw - scroll) / 10);
  }
  linedraw = linedraw - 1000;

  n = 0;
  while(n <= numberOfComs * 10 - 1){
    m = comdata [n + 1];
    m = m * 10000;
    m = m + (100 * comdata [n + 2]);
    m = m + comdata [n + 3];

    q = comdata [n + 8];
    q = q * 100;
    q = q + comdata [n + 9];

    nxtFillRect(comdata [n] - 5, (m - 32768 - scroll) / 10 + 3, comdata [n] + 5,
    (m - 32768 - scroll) / 10 - 3);
    if(q <= 1000){
      nxtFillRect(comdata [n + 7] - 1, (m + q - 32768 - scroll) / 10 + 2, comdata [n + 7] + 1, (m + q - 32768 - scroll) / 10 - 2);
    }
    if(shotY - py <= 1000){
      if(shotY + 32768 <= m + 50){
        if(shotY + 32768 >= m - 50){
          if(shotX <= comdata[n] + 5){
            if(shotX >= comdata[n] - 5){
              if(m - 32768 > py){
                nxtDrawLine(shotX, (shotY - scroll) / 10, px, (py - scroll) / 10);
              }
            }
          }
        }
      }
    }

    if(q <= 1000){
      if(q + m - 32768 <= py + 50){
        if(q + m - 32768 >= py - 50){
          if(comdata[n + 7] <= px + 5){
            if(comdata[n + 7] >= px - 5){
              if(py + 32768 > m){
                nxtDrawLine(comdata[n + 7], (q + m - 32768 - scroll) / 10, comdata[n], (m - 32768 - scroll) / 10);
              }
            }
          }
        }
      }
    }

    n2 = 0;
    while(n2 <= numberOfComs * 10 - 1){

      m2 = comdata [n2 + 1];
      m2 = m2 * 10000;
      m2 = m2 + (100 * comdata [n2 + 2]);
      m2 = m2 + comdata [n2 + 3];

      //o2 = comdata [n2 + 4];
      //o2 = o2 * 10;
      //o2 = o2 + (0.1 * comdata [n2 + 5]);
      //o2 = o2 + (0.001 * comdata [n2 + 6]);

      if(q <= 1000){
        if(q + m <= m2 + 50){
          if(q + m >= m2 - 50){
            if(comdata[n + 7] <= comdata[n2] + 5){
              if(comdata[n + 7] >= comdata[n2] - 5){
                if(m2 > m){
                  nxtDrawLine(comdata[n + 7], (q + m - 32768 - scroll) / 10, comdata[n], (m - 32768 - scroll) / 10);
                }
              }
            }
          }
        }
      }

      n2 = n2 + 10;
    }

    n = n + 10;
  }

  if(lastn == 99){
    nxtDrawEllipse(px + 10, (lastnY - 32768 - scroll) / 10 + 10, px - 10, (lastnY - 32768 - scroll) / 10 - 10);
  }else{
    nxtDrawEllipse(comdata[lastn] + 10, (lastnY - 32768 - scroll) / 10 + 10,
    comdata[lastn] - 10, (lastnY - 32768 - scroll) / 10 - 10);
  }



  nxtDisplayBigStringAt( 65, 30, "%d/%d", yourRank, numberOfComs + 1);
  nxtDisplayStringAt( 80, 55, "%d", racelength - (time100[T2]/10));
  nxtDisplayStringAt( 80, 10, "%d", score);



  while(time1[T1] < 50){
    wait1Msec(4);
  }
  nxtDisplayStringAt(60, 60, "%d", time1[T1]);
  ClearTimer(T1);
}




//eraseDisplay();
//nxtDisplayStringAt(10, 12, "%i", 1234);
//nxtDisplayBigStringAt(10, 42, "%i", 1234);
//nxtDisplayBigTextLine(1, "%i", 1234);
//nxtDisplayTextLine(5, "%i", 1234);
//nxtDisplayStringAt( 60, 50, "%d", 1234);
//nxtDisplayStringAt( 60, 40, "%d", linedraw);
//wait1Msec(5000);



if(exit != true){
  cont = true;
}else{
  cont = false;
}
while(cont == true){

  eraseDisplay();

  yourRank = 1;

  n = 0;
  while(n <= numberOfComs * 10 - 1){

    comRanks[n / 10] = 1;

    n2 = 0;
    while(n2 <= numberOfComs * 10 - 1){
      if(n == n2){
        n2 = n2 + 10;
      }

      if(comScores[n2 / 10] > comScores[n / 10]){
        comRanks[n / 10] = comRanks[n / 10] + 1;
      }
      if(comScores[n / 10] == comScores[n2 / 10]){
        m = comdata [n + 1];
        m = m * 10000;
        m = m + (100 * comdata [n + 2]);
        m = m + comdata [n + 3];

        m2 = comdata [n2 + 1];
        m2 = m2 * 10000;
        m2 = m2 + (100 * comdata [n2 + 2]);
        m2 = m2 + comdata [n2 + 3];

        if(m < m2){
          comRanks[n / 10] = comRanks[n / 10] + 1;
        }
      }

      if(n2 + 10 == n){
        n2 = n2 + 10;
      }
      n2 = n2 + 10;
    }

    if(score > comScores[n / 10]){
      comRanks[n / 10] = comRanks[n / 10] + 1;
    }else{
      yourRank = yourRank + 1;
    }


    o = comRanks[n / 10] * 8;
    p = comRanks[n / 10];
    linedraw = p;
    nxtDisplayStringAt( 5, 71 - o, "%d", linedraw);
    linedraw = n / 10 + 1;
    nxtDisplayStringAt(30, 71 - o, "com%i", linedraw);
    m = comScores[n / 10];
    linedraw = m;
    nxtDisplayStringAt(60, 71 - o, "%i", linedraw);

    //nxtDisplayStringAt(12, 10, "%i", 555);

    n = n + 10;
  }

  o = yourRank * 8;
  linedraw = yourRank;
  nxtDisplayStringAt( 5, 71 - o, "%d", linedraw);
  nxtDisplayStringAt( 30, 71 - o, "p");
  linedraw = score;
  nxtDisplayStringAt( 60, 71 - o, "%d", linedraw);



  wait1Msec(100);
}
}
