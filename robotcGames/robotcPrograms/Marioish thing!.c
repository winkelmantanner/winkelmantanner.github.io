task main(){
  float XX=50;float YYY=5;float J;float PX=45;float PY;bool st;float PX2=85;float PY2=10;float PX3=120;float PY3=28;float PX4=145;float PY4=10;
  float PX5=175;float PY5=20;float PX6=205;float PY6=20;int score;int S;float EX; float EY; float EJ; int ED;

  while(1==1){eraseDisplay();

    nxtSetPixel(XX+2,YYY);
  nxtSetPixel(XX-2,YYY);
  nxtSetPixel(XX+1,YYY+1);
  nxtSetPixel(XX-1,YYY+1);
   nxtSetPixel(XX,YYY+2);
   nxtSetPixel(XX,YYY+3);
  nxtSetPixel(XX,YYY+4);
  nxtSetPixel(XX,YYY+5);
  nxtSetPixel(XX+1,YYY+4);
  nxtSetPixel(XX-1,YYY+4);
  nxtSetPixel(XX+2,YYY+4);
  nxtSetPixel(XX-2,YYY+4);
  nxtSetPixel(XX+3,YYY+4);
  nxtSetPixel(XX-3,YYY+4);
  nxtSetPixel(XX+1,YYY+5);
  nxtSetPixel(XX-1,YYY+5);
  nxtSetPixel(XX+1,YYY+6);
  nxtSetPixel(XX-1,YYY+6);
nxtSetPixel(XX+1,YYY+7);
  nxtSetPixel(XX-1,YYY+7);
nxtSetPixel(XX,YYY+7);

nxtSetPixel(EX,EY+1);
nxtSetPixel(EX+1,EY+1);
nxtSetPixel(EX-1,EY+1);
nxtSetPixel(EX+2,EY+1);
nxtSetPixel(EX-2,EY+1);
nxtSetPixel(EX+3,EY+1);
nxtSetPixel(EX-3,EY+1);
nxtSetPixel(EX+2,EY+4);
nxtSetPixel(EX-2,EY+4);
nxtDrawRect(EX-4,EY,EX+4,EY+6);


nxtDrawLine(PX,PY,PX+15,PY);nxtDrawLine(PX2,PY2,PX2+25,PY2);nxtDrawLine(PX3,PY3,PX3+15,PY3);nxtDrawLine(PX4,PY4,PX4+35,PY4);nxtDrawLine(PX5,PY5,PX5+20,PY5);nxtDrawLine(PX6,PY6,PX6+15,PY6);

nxtDisplayStringAt(3,55,"%d",score);

  if(nNxtButtonPressed==1){XX=XX+1;}
  if(nNxtButtonPressed==2){XX=XX-1;}
  if(nNxtButtonPressed==3){if(st==true){J=2.8;}}

  YYY=YYY+J-1;
  //
  if(XX>=35){XX=XX-1;PX=PX-1;PX2=PX2-1;PX3=PX3-1;PX4=PX4-1;PX5=PX5-1;PX6=PX6-1;S=S+1;EX=EX-1;}
  if(YYY>=40){YYY=YYY-1;PY=PY-1;PY2=PY2-1;PY3=PY3-1;PY4=PY4-1;PY5=PY5-1;PY6=PY6-1;EY=EY-1;}
  if(YYY<=24){YYY=YYY+1;PY=PY+1;PY2=PY2+1;PY3=PY3+1;PY4=PY4+1;PY5=PY5+1;PY6=PY6+1;EY=EY+1;}
  //

  if(S>=10){score=score+1;S=0;}

  if(st==false){J=J-0.06;}
  if(st==true){if(nNxtButtonPressed!=3){J=1;}}

  st=false;
  if(YYY<=PY+4){if(YYY>=PY-2){if(XX>=PX){if(XX<=PX+15){ st=true; }}}}
  if(YYY<=PY2+4){if(YYY>=PY2-2){if(XX>=PX2){if(XX<=PX2+25){ st=true; }}}}
  if(YYY<=PY3+4){if(YYY>=PY3-2){if(XX>=PX3){if(XX<=PX3+15){ st=true; }}}}
  if(YYY<=PY4+4){if(YYY>=PY4-2){if(XX>=PX4){if(XX<=PX4+35){ st=true; }}}}
  if(YYY<=PY5+4){if(YYY>=PY5-2){if(XX>=PX5){if(XX<=PX5+20){ st=true; }}}}
  if(YYY<=PY6+4){if(YYY>=PY6-2){if(XX>=PX6){if(XX<=PX6+15){ st=true; }}}}

  if(PX<=-14){PX=PX6+random(40)+15;while(PY<=-10){PY=PY6+random(20)-10;}}
  if(PX2<=-24){PX2=PX+random(35)+15;while(PY2>=73){PY2=PY+random(20)-10;}}
  if(PX3<=-14){PX3=PX2+random(35)+25;PY3=PY2+random(25)-14;}
  if(PX4<=-34){PX4=PX3+random(35)+15;while(PY4<=-10){PY4=PY3+random(20)-10;}}
  if(PX5<=-19){PX5=PX4+random(35)+35;while(PY5>=73){PY5=PY4+random(20)-10;}}
  if(PX6<=-14){PX6=PX5+random(35)+20;PY6=PY5+random(20)-13;}

if(ED==0){EX=EX-0.25;}else{EX=EX+0.25;} EY=EY+EJ; EJ=EJ-0.12;
  if(EX>=PX){if(EX<=PX+15){if(EY<=PY+3){if(EY>=PY-1){EJ=0;}}}}
  if(EX>=PX2){if(EX<=PX2+25){if(EY<=PY2+3){if(EY>=PY2-1){EJ=0;}}}}
   if(EX>=PX3){if(EX<=PX3+15){if(EY<=PY3+3){if(EY>=PY3-1){EJ=0;}}}}
   if(EX>=PX4){if(EX<=PX4+35){if(EY<=PY4+3){if(EY>=PY4-1){EJ=0;}}}}
   if(EX>=PX5){if(EX<=PX5+20){if(EY<=PY5+3){if(EY>=PY5-1){EJ=0;}}}}
   if(EX>=PX6){if(EX<=PX6+15){if(EY<=PY6+3){if(EY>=PY6-1){EJ=0;}}}}

  if(EY>=PY-1){if(EY<=PY+3){if(EX==PX+1){ED=1}if(EX==PX+14){ED=0;}}}
    if(EY>=PY2-1){if(EY<=PY2+3){if(EX==PX2+1){ED=1}if(EX==PX2+24){ED=0;}}}
   if(EY>=PY3-1){if(EY<=PY3+3){if(EX==PX3+1){ED=1}if(EX==PX3+14){ED=0;}}}
   if(EY>=PY4-1){if(EY<=PY4+3){if(EX==PX4+1){ED=1}if(EX==PX4+34){ED=0;}}}
      if(EY>=PY5-1){if(EY<=PY5+3){if(EX==PX5+1){ED=1}if(EX==PX5+20){ED=0;}}}
    if(EY>=PY6-1){if(EY<=PY6+3){if(EX==PX6+1){ED=1}if(EX==PX6+14){ED=0;}}}


   if(EX<=-10){EX=135;EY=50;EJ=-1;ED=0;}
 if(EY<=-30){EX=135;EY=50;EJ=-1;ED=0;}

   if(YYY<=EY+6){if(YYY>=EY-6){if(XX>=EX-7){if(XX<=EX+7){if(YYY>=EY+3){EY=-50;if(nNxtButtonPressed==3){J=2.1;}else{J=2;}}else{YYY=-50;}}}}}

  wait1Msec(25);









































}


}
