task main(){int CCCCC = 40;int WWWWW=0;int SPSPSP=0;int jo=0;

nNxtExitClicks = 3;

while(WWWWW==0){eraseDisplay();
  nxtDisplayCenteredTextLine(1,"Choose");
  nxtDisplayCenteredTextLine(2,"world");
nxtDisplayCenteredTextLine(7,"1     2     3");
nxtDrawLine(33,0,33,15);
nxtDrawLine(67,0,67,15);
nxtDrawLine(CCCCC,18,CCCCC,30);
nxtDrawLine(CCCCC,18,CCCCC+4,22);
nxtDrawLine(CCCCC,18,CCCCC-4,22);





if(nNxtButtonPressed==1){CCCCC=CCCCC+1;}
if(nNxtButtonPressed==2){CCCCC=CCCCC-1;}
if(nNxtButtonPressed==3){if(CCCCC>=67){WWWWW=3;}else{if(CCCCC>=33){WWWWW=2;}else{WWWWW=1;}}}
wait10Msec(5);
}
eraseDisplay();
nxtDisplayCenteredBigTextLine(2,"world");
nxtDisplayBigStringAt(40,20,"%d",WWWWW);
while(nNxtButtonPressed>=1){}
wait1Msec(500);

while(SPSPSP==0){eraseDisplay();
  nxtDisplayCenteredTextLine(1,"Choose");
  nxtDisplayCenteredTextLine(2,"speed");
nxtDisplayCenteredTextLine(7,"1   2   3   4");
nxtDrawLine(50,0,50,15);
nxtDrawLine(25,0,25,15);
nxtDrawLine(75,0,75,15);
nxtDrawLine(CCCCC,18,CCCCC,30);
nxtDrawLine(CCCCC,18,CCCCC+4,22);
nxtDrawLine(CCCCC,18,CCCCC-4,22);





if(nNxtButtonPressed==1){CCCCC=CCCCC+1;}
if(nNxtButtonPressed==2){CCCCC=CCCCC-1;}
if(nNxtButtonPressed==3){if(CCCCC>=75){SPSPSP=4;}else{if(CCCCC>=50){SPSPSP=3;}else{if(CCCCC>=25){SPSPSP=2;}else{SPSPSP=1;}}}}
wait10Msec(5);
}


eraseDisplay();
nxtDisplayCenteredBigTextLine(2,"speed");
nxtDisplayBigStringAt(40,20,"%d",SPSPSP);
while(nNxtButtonPressed>=1){}
wait1Msec(500);



while(jo==0){eraseDisplay();
  nxtDisplayCenteredTextLine(1,"Can jumping");
  nxtDisplayCenteredTextLine(2,"on people");
  nxtDisplayCenteredTextLine(3,"get them?");
nxtDisplayCenteredTextLine(7," yes    no ");
nxtDrawLine(50,0,50,15);
nxtDrawLine(CCCCC,18,CCCCC,30);
nxtDrawLine(CCCCC,18,CCCCC+4,22);
nxtDrawLine(CCCCC,18,CCCCC-4,22);





if(nNxtButtonPressed==1){CCCCC=CCCCC+1;}
if(nNxtButtonPressed==2){CCCCC=CCCCC-1;}
if(nNxtButtonPressed==3){if(CCCCC>=50){jo=2;}else{jo=1;}}
wait10Msec(5);
}

eraseDisplay();
nxtDisplayCenteredTextLine(2,"jumping on");
if(jo == 1){
  nxtDisplayCenteredTextLine(3,"people can");
}
if(jo == 2){
  nxtDisplayCenteredTextLine(3,"people can't");
}
nxtDisplayCenteredTextLine(4,"get them");
while(nNxtButtonPressed>=1){}
wait1Msec(500);



eraseDisplay();
nxtDisplayCenteredBigTextLine(3,"Ready!");
wait1Msec(500);
nxtDisplayCenteredBigTextLine(3,"Set!");
wait1Msec(500);
nxtDisplayCenteredBigTextLine(3,"Go!!!");
wait1Msec(500);


ClearTimer(T1);


float PX;float PY;float PX2;float PY2;
float PX3;float PY3;float PX4;float PY4;float PX5;float PY5;float PX6;
float PY6;float PX7;float PY7;float PX8;float PY8;float PX9;float PY9;float PXn;float PYn;float PXq;float PYq;
float PXw;float PYw;float spX = 7;float spY = 50;int out = -1;int outC = -1;int outC2 = -1;
float AAAAAX=0;float AAAAAY=0;int v1;int v2;int v3;int v4;
int length = 45; // length of the battle in seconds
int deaths = 0; // how many times the player has died

 float cntt;int acntt=10;

  if(WWWWW==1){ PX2=22; PY2=20;
 PX3=-22; PY3=20; PX4=0; PY4=40; PX5=-60; PY5=40; PX6=60;
 PY6=40; PX7=45; PY7=10; PX8=-45; PY8=10; PX9=0; PY9=101;PXn=15; PYn=138; PXq=25; PYq=0;
 PXw=-25; PYw=0;}

if(WWWWW==2){  PX2=15; PY2=35;
 PX3=-15; PY3=35; PX4=0; PY4=35; PX5=-50; PY5=20; PX6=50;
 PY6=20; PX7=35; PY7=10; PX8=-35; PY8=10; PX9=0; PY9=101; PXn=15; PYn=138; PXq=25; PYq=0;
 PXw=-25; PYw=0;}

 if(WWWWW==3){ PX2=random(120)-60; PY2=random(65);
 PX3=random(120)-60; PY3=random(65); PX4=random(120)-60; PY4=random(65); PX5=random(120)-60; PY5=random(65); PX6=random(120)-60;
 PY6=random(65); PX7=random(120)-60; PY7=random(65); PX8=random(120)-60; PY8=random(65);
 PXq=random(120)-60; PYq=random(65); PXw=random(120)-60; PYw=random(65); PX9=0; PY9=110; PXn=15; PYn=147; PXq=25; PYq=0;
 PXw=-25; PYw=0;

 }

  bool DJ;bool DJC; int score;float XX=7;float YYY;float XXC=50;
float YYYC=22;float JC;float J;bool CD;bool stC;bool st;int DJN;
bool DJC2;float YYYC2=25;float JC2;bool stC2;float XXC2=75;bool CD2;int sssss;int DDDDD;
int randy;int scorecheck;int hX = 50;int hY = -30;int radius = 20;bool hdv = true;bool hdh = false;
int timeInh;int timeInhC;int timeInhC2;



while(1==1){

  if(randy < 100){
    randy = randy + 1;
  }else{
    randy = 0;
  }



if(nNxtButtonPressed==1){XX=XX+0.2;}
if(nNxtButtonPressed==2){XX=XX-0.2;}J=J-0.002;
if(nNxtButtonPressed==3){ if(st==true){J=0.3;PlaySound(soundBlip);}else{if(DJ==true){J=0.3;DJ=false;DJN=0;PlaySound(soundBlip);}}}else{if(DJN==2){DJN=3;DJ=true;}if(st==true){J=0;}}
if(st==false){if(DJN==1){DJN=2;}}
if(nNxtButtonPressed == 0){
  v4 = v4 + time1(T1);
  while(nNxtButtonPressed != 3){
    eraseDisplay();
    nxtDisplayCenteredTextLine( 0, "game paused");
    nxtDrawLine( 0, 55, 100, 55);
    nxtDisplayCenteredTextLine( 3, "press the");
    nxtDisplayCenteredTextLine( 4, "orange button");
    nxtDisplayCenteredTextLine( 5, "to resume");
    nxtDisplayCenteredTextLine( 6, "the game");
    wait1Msec(30);
  }
  ClearTimer(T1);
}

if(DDDDD<=0){
  eraseDisplay();

  if(score == scorecheck + 1){
    scorecheck = score;
  }
  if(score > scorecheck + 1){
    score = scorecheck + 1;
  }

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

nxtSetPixel(XXC+2,YYYC);
  nxtSetPixel(XXC-2,YYYC);
  nxtSetPixel(XXC+1,YYYC+1);
  nxtSetPixel(XXC-1,YYYC+1);
   nxtSetPixel(XXC,YYYC+2);
   nxtSetPixel(XXC,YYYC+3);
  nxtSetPixel(XXC,YYYC+4);
  nxtSetPixel(XXC,YYYC+5);
  nxtSetPixel(XXC+1,YYYC+4);
  nxtSetPixel(XXC-1,YYYC+4);
  nxtSetPixel(XXC+2,YYYC+4);
  nxtSetPixel(XXC-2,YYYC+4);
  nxtSetPixel(XXC+3,YYYC+4);
  nxtSetPixel(XXC-3,YYYC+4);
  nxtSetPixel(XXC+1,YYYC+5);
  nxtSetPixel(XXC-1,YYYC+5);
  nxtSetPixel(XXC+1,YYYC+6);
  nxtSetPixel(XXC-1,YYYC+6);
nxtSetPixel(XXC+1,YYYC+7);
  nxtSetPixel(XXC-1,YYYC+7);
nxtSetPixel(XXC,YYYC+7);

nxtSetPixel(XXC2+2,YYYC2);
  nxtSetPixel(XXC2-2,YYYC2);
  nxtSetPixel(XXC2+1,YYYC2+1);
  nxtSetPixel(XXC2-1,YYYC2+1);
   nxtSetPixel(XXC2,YYYC2+2);
   nxtSetPixel(XXC2,YYYC2+3);
  nxtSetPixel(XXC2,YYYC2+4);
  nxtSetPixel(XXC2,YYYC2+5);
  nxtSetPixel(XXC2+1,YYYC2+4);
  nxtSetPixel(XXC2-1,YYYC2+4);
  nxtSetPixel(XXC2+2,YYYC2+4);
  nxtSetPixel(XXC2-2,YYYC2+4);
  nxtSetPixel(XXC2+3,YYYC2+4);
  nxtSetPixel(XXC2-3,YYYC2+4);
  nxtSetPixel(XXC2+1,YYYC2+5);
  nxtSetPixel(XXC2-1,YYYC2+5);
  nxtSetPixel(XXC2+1,YYYC2+6);
  nxtSetPixel(XXC2-1,YYYC2+6);
nxtSetPixel(XXC2+1,YYYC2+7);
  nxtSetPixel(XXC2-1,YYYC2+7);
nxtSetPixel(XXC2,YYYC2+7);

nxtDrawLine(PX,PY,PX+15,PY);
nxtDrawLine(PX2,PY2,PX2+15,PY2);
nxtDrawLine(PX3,PY3,PX3+15,PY3);
nxtDrawLine(PX4,PY4,PX4+15,PY4);
nxtDrawLine(PX5,PY5,PX5+15,PY5);
nxtDrawLine(PX6,PY6,PX6+15,PY6);
nxtDrawLine(PX7,PY7,PX7+15,PY7);
nxtDrawLine(PX8,PY8,PX8+15,PY8);
nxtDrawLine(PX9,PY9,PX9+15,PY9);
nxtDrawLine(PXn,PYn,PXn+15,PYn);
nxtDrawLine(PXq,PYq,PXq+15,PYq);
nxtDrawLine(PXw,PYw,PXw+15,PYw);

nxtDrawLine(spX - 6, spY + 6, spX + 6, spY - 6);
nxtDrawLine(spX + 6, spY + 6, spX - 6, spY - 6);
nxtDrawLine(spX + 6, spY, spX - 6, spY);
nxtDrawLine(spX, spY + 6, spX, spY - 6);
nxtDrawLine(spX + 6, spY + 6, spX - 6, spY + 6);
nxtDrawLine(spX + 6, spY - 6, spX - 6, spY - 6);
nxtDrawLine(spX + 6, spY + 6, spX + 6, spY - 6);
nxtDrawLine(spX - 6, spY + 6, spX - 6, spY - 6);

nxtDrawEllipse(hX - radius, hY + radius, hX + radius, hY - radius);

nxtDisplayStringAt( 3, 63 , "%d", length - ((time1[T1] + v4) / 1000));

nxtDisplayStringAt( 3, 45, "%d", score);

nxtDisplayStringAt( 3, 54, "%d", deaths);

nxtDisplayStringAt( 3, 36, "%d", timeInh);

DDDDD=3;}else{DDDDD=DDDDD-1;}

if(WWWWW==3){nxtDisplayStringAt(70,55,"%d",acntt);

if(acntt<=2){nxtDrawRect(68,47,76,57);}

cntt=cntt-0.1;
if(cntt<=-25){acntt=acntt-1;cntt=0;}
if(acntt<=0){acntt=10; PX2=random(120)-60+AAAAAX; PY2=random(65)+AAAAAY;
 PX3=random(120)-60+AAAAAX; PY3=random(65)+AAAAAY; PX4=random(120)-60+AAAAAX; PY4=random(65)+AAAAAY; PX5=random(120)-60+AAAAAX; PY5=random(65)+AAAAAY; PX6=random(120)-60+AAAAAX;
 PY6=random(65)+AAAAAY; PX7=random(120)-60+AAAAAX; PY7=random(65)+AAAAAY; PX8=random(120)-60+AAAAAX; PY8=random(65)+AAAAAY;
 PXq=random(120)-60+AAAAAX; PYq=random(65)+AAAAAY; PXw=random(120)-60+AAAAAX; PYw=random(65)+AAAAAY;}}

if(out < 0){
if(XX<=45){XX=XX+1;PX=PX+1;PX2=PX2+1;PX3=PX3+1;PX4=PX4+1;PX5=PX5+1;PX6=PX6+1;PX7=PX7+1;PX8=PX8+1;PX9=PX9+1;PXn=PXn+1;PXq=PXq+1;PXw=PXw+1;XXC=XXC+1;XXC2=XXC2+1;
AAAAAX=AAAAAX+1;spX = spX + 1;hX = hX + 1;}
if(XX>=55){XX=XX-1;PX=PX-1;PX2=PX2-1;PX3=PX3-1;PX4=PX4-1;PX5=PX5-1;PX6=PX6-1;PX7=PX7-1;PX8=PX8-1;PX9=PX9-1;PXn=PXn-1;PXq=PXq-1;PXw=PXw-1;XXC=XXC-1;XXC2=XXC2-1;
AAAAAX=AAAAAX-1;spX = spX - 1;hX = hX - 1;}
if(YYY<=-20 * J + 20){YYY=YYY+1;PY=PY+1;PY2=PY2+1;PY3=PY3+1;PY4=PY4+1;PY5=PY5+1;PY6=PY6+1;PY7=PY7+1;PY8=PY8+1;PY9=PY9+1;PYn=PYn+1;PYq=PYq+1;PYw=PYw+1;YYYC=YYYC+1;YYYC2=YYYC2+1;
AAAAAY=AAAAAY+1;spY = spY + 1;hY = hY + 1;}
if(YYY>=-20 * J + 25){YYY=YYY-1;PY=PY-1;PY2=PY2-1;PY3=PY3-1;PY4=PY4-1;PY5=PY5-1;PY6=PY6-1;PY7=PY7-1;PY8=PY8-1;PY9=PY9-1;PYn=PYn-1;PYq=PYq-1;PYw=PYw-1;YYYC=YYYC-1;YYYC2=YYYC2-1;
AAAAAY=AAAAAY-1;spY = spY - 1;hY = hY - 1;}
}

if(out >= 0){
if(spX<=48){XX=XX+1;PX=PX+1;PX2=PX2+1;PX3=PX3+1;PX4=PX4+1;PX5=PX5+1;PX6=PX6+1;PX7=PX7+1;PX8=PX8+1;PX9=PX9+1;PXn=PXn+1;PXq=PXq+1;PXw=PXw+1;XXC=XXC+1;XXC2=XXC2+1;
AAAAAX=AAAAAX+1;spX = spX + 1;hX = hX + 1;}
if(spX>=52){XX=XX-1;PX=PX-1;PX2=PX2-1;PX3=PX3-1;PX4=PX4-1;PX5=PX5-1;PX6=PX6-1;PX7=PX7-1;PX8=PX8-1;PX9=PX9-1;PXn=PXn-1;PXq=PXq-1;PXw=PXw-1;XXC=XXC-1;XXC2=XXC2-1;
AAAAAX=AAAAAX-1;spX = spX - 1;hX = hX - 1;}
if(spY<=18){YYY=YYY+1;PY=PY+1;PY2=PY2+1;PY3=PY3+1;PY4=PY4+1;PY5=PY5+1;PY6=PY6+1;PY7=PY7+1;PY8=PY8+1;PY9=PY9+1;PYn=PYn+1;PYq=PYq+1;PYw=PYw+1;YYYC=YYYC+1;YYYC2=YYYC2+1;
AAAAAY=AAAAAY+1;spY = spY + 1;hY = hY + 1;}
if(spY>=22){YYY=YYY-1;PY=PY-1;PY2=PY2-1;PY3=PY3-1;PY4=PY4-1;PY5=PY5-1;PY6=PY6-1;PY7=PY7-1;PY8=PY8-1;PY9=PY9-1;PYn=PYn-1;PYq=PYq-1;PYw=PYw-1;YYYC=YYYC-1;YYYC2=YYYC2-1;
AAAAAY=AAAAAY-1;spY = spY - 1;hY = hY - 1;}
}

st=false;
if(J<=0.01){if(XX>=PX){if(XX<=PX+15){if(YYY>=PY-1){if(YYY<=PY+1){st=true;}}}}
if(XX>=PX2){if(XX<=PX2+15){if(YYY>=PY2-1){if(YYY<=PY2+1){st=true;}}}}
if(XX>=PX3){if(XX<=PX3+15){if(YYY>=PY3-1){if(YYY<=PY3+1){st=true;}}}}
if(XX>=PX4){if(XX<=PX4+15){if(YYY>=PY4-1){if(YYY<=PY4+1){st=true;}}}}
if(XX>=PX5){if(XX<=PX5+15){if(YYY>=PY5-1){if(YYY<=PY5+1){st=true;}}}}
if(XX>=PX6){if(XX<=PX6+15){if(YYY>=PY6-1){if(YYY<=PY6+1){st=true;}}}}
if(XX>=PX7){if(XX<=PX7+15){if(YYY>=PY7-1){if(YYY<=PY7+1){st=true;}}}}
if(XX>=PX8){if(XX<=PX8+15){if(YYY>=PY8-1){if(YYY<=PY8+1){st=true;}}}}
if(XX>=PX9){if(XX<=PX9+15){if(YYY>=PY9-1){if(YYY<=PY9+1){st=true;}}}}
if(XX>=PXn){if(XX<=PXn+15){if(YYY>=PYn-1){if(YYY<=PYn+1){st=true;}}}}
if(XX>=PXq){if(XX<=PXq+15){if(YYY>=PYq-1){if(YYY<=PYq+1){st=true;}}}}
if(XX>=PXw){if(XX<=PXw+15){if(YYY>=PYw-1){if(YYY<=PYw+1){st=true;}}}}}

stC=false;
if(JC<=0.01){if(XXC>=PX){if(XXC<=PX+15){if(YYYC>=PY-1){if(YYYC<=PY+1){stC=true;}}}}
if(XXC>=PX2){if(XXC<=PX2+15){if(YYYC>=PY2-1){if(YYYC<=PY2+1){stC=true;}}}}
if(XXC>=PX3){if(XXC<=PX3+15){if(YYYC>=PY3-1){if(YYYC<=PY3+1){stC=true;}}}}
if(XXC>=PX4){if(XXC<=PX4+15){if(YYYC>=PY4-1){if(YYYC<=PY4+1){stC=true;}}}}
if(XXC>=PX5){if(XXC<=PX5+15){if(YYYC>=PY5-1){if(YYYC<=PY5+1){stC=true;}}}}
if(XXC>=PX6){if(XXC<=PX6+15){if(YYYC>=PY6-1){if(YYYC<=PY6+1){stC=true;}}}}
if(XXC>=PX7){if(XXC<=PX7+15){if(YYYC>=PY7-1){if(YYYC<=PY7+1){stC=true;}}}}
if(XXC>=PX8){if(XXC<=PX8+15){if(YYYC>=PY8-1){if(YYYC<=PY8+1){stC=true;}}}}
if(XXC>=PX9){if(XXC<=PX9+15){if(YYYC>=PY9-1){if(YYYC<=PY9+1){stC=true;}}}}
if(XXC>=PXn){if(XXC<=PXn+15){if(YYYC>=PYn-1){if(YYYC<=PYn+1){stC=true;}}}}
if(XXC>=PXq){if(XXC<=PXq+15){if(YYYC>=PYq-1){if(YYYC<=PYq+1){stC=true;}}}}
if(XXC>=PXw){if(XXC<=PXw+15){if(YYYC>=PYw-1){if(YYYC<=PYw+1){stC=true;}}}}}


stC2=false;
if(JC2<=0.01){if(XXC2>=PX){if(XXC2<=PX+15){if(YYYC2>=PY-1){if(YYYC2<=PY+1){stC2=true;}}}}
if(XXC2>=PX2){if(XXC2<=PX2+15){if(YYYC2>=PY2-1){if(YYYC2<=PY2+1){stC2=true;}}}}
if(XXC2>=PX3){if(XXC2<=PX3+15){if(YYYC2>=PY3-1){if(YYYC2<=PY3+1){stC2=true;}}}}
if(XXC2>=PX4){if(XXC2<=PX4+15){if(YYYC2>=PY4-1){if(YYYC2<=PY4+1){stC2=true;}}}}
if(XXC2>=PX5){if(XXC2<=PX5+15){if(YYYC2>=PY5-1){if(YYYC2<=PY5+1){stC2=true;}}}}
if(XXC2>=PX6){if(XXC2<=PX6+15){if(YYYC2>=PY6-1){if(YYYC2<=PY6+1){stC2=true;}}}}
if(XXC2>=PX7){if(XXC2<=PX7+15){if(YYYC2>=PY7-1){if(YYYC2<=PY7+1){stC2=true;}}}}
if(XXC2>=PX8){if(XXC2<=PX8+15){if(YYYC2>=PY8-1){if(YYYC2<=PY8+1){stC2=true;}}}}
if(XXC2>=PX9){if(XXC2<=PX9+15){if(YYYC2>=PY9-1){if(YYYC2<=PY9+1){stC2=true;}}}}
if(XXC2>=PXn){if(XXC2<=PXn+15){if(YYYC2>=PYn-1){if(YYYC2<=PYn+1){stC2=true;}}}}
if(XXC2>=PXq){if(XXC2<=PXq+15){if(YYYC2>=PYq-1){if(YYYC2<=PYq+1){stC2=true;}}}}
if(XXC2>=PXw){if(XXC2<=PXw+15){if(YYYC2>=PYw-1){if(YYYC2<=PYw+1){stC2=true;}}}}}


if(stC==false){JC=JC-0.002;}else{
  v1 = XXC - hX;
  v1 = v1 * v1;
  v2 = YYYC - hY;
  v2 = v2 * v2;
  if(sqrt(v1 + v2) > radius - 2 && YYYC < hY + radius - 2){
    JC=0.3;
  }else{
    JC = 0;
  }
}
YYYC=YYYC+JC;

if(stC2==false){JC2=JC2-0.002;}else{
  v1 = XXC - hX;
  v1 = v1 * v1;
  v2 = YYYC - hY;
  v2 = v2 * v2;
  if(sqrt(v1 + v2) > radius - 2 && YYYC2 < hY + radius - 2){
    JC2=0.3;
  }else{
    JC2 = 0;
  }
}
YYYC2=YYYC2+JC2;

if(stC==true){DJC=true;}if(stC2==true){DJC2=true;}

  v1 = XXC - hX;
  v1 = v1 * v1;
  v2 = YYYC - hY;
  v2 = v2 * v2;
  if(sqrt(v1 + v2) > radius - 2 || stC == false){
    if(CD==false){XXC=XXC-0.2;}
    if(CD==true){XXC=XXC+0.2;}
  }

  v1 = XXC - hX;
  v1 = v1 * v1;
  v2 = YYYC - hY;
  v2 = v2 * v2;
  if(sqrt(v1 + v2) > radius - 2 || stC == false){
    if(CD2==false){XXC2=XXC2-0.2;}
    if(CD2==true){XXC2=XXC2+0.2;}
  }


if(randy == 5 || randy == 15 || randy == 25 || randy == 35 || randy == 45 || randy == 55 || randy == 65 ||
randy == 75 || randy == 85 || randy == 95){

  if(hdv == true){hY = hY + 1;}
  else{hY = hY - 1;}
  if(hdh == true){hX = hX + 1;}
  else{hX = hX - 1;}

  if(hX < spX - 65){hdh = true;}
  if(hX > spX + 65){hdh = false;}
  if(hY > spY + 20){hdv = false;}
  if(hY < spY - 50){hdv = true;}
}

if(time100[T1] / 10 > v3){

  v3 = v3 + 1;

  v1 = XX - hX;
  v1 = v1 * v1;
  v2 = YYY - hY;
  v2 = v2 * v2;
  if(sqrt(v1 + v2) < radius){
    timeInh = timeInh + 1;
  }

  v1 = XXC - hX;
  v1 = v1 * v1;
  v2 = YYYC - hY;
  v2 = v2 * v2;
  if(sqrt(v1 + v2) < radius){
    timeInhC = timeInhC + 1;
  }

  v1 = XXC2 - hX;
  v1 = v1 * v1;
  v2 = YYYC2 - hY;
  v2 = v2 * v2;
  if(sqrt(v1 + v2) < radius){
    timeInhC2 = timeInhC2 + 1;
  }
}



if(WWWWW<=2){

  if(XXC<=PX5+2){CD=true;}
if(XXC>=PX6+13){CD=false;}

if(XXC2<=PX5+2){CD2=true;}
if(XXC2>=PX6+13){CD2=false;}

if(YYYC<=PY-5){if(DJC==true){JC=0.2;DJC=false;if(XXC>=PX+7){CD=false;}else{CD=true;}}}

if(YYYC2<=PY-5){if(DJC2==true){JC2=0.2;DJC2=false;if(XXC2>=PX+7){CD2=false;}else{CD2=true;}}}
}///////////////////////////////////////////////////////////////////////////////////////////////!!!!!!!!!!!!
else{

    if(XXC<=AAAAAX-50){CD=true;}
if(XXC>=AAAAAX+70){CD=false;}

if(XXC2<=AAAAAX-50){CD2=true;}
if(XXC2>=AAAAAX+70){CD2=false;}

  if(YYYC<=AAAAAY){if(DJC==true){JC=0.23;DJC=false;if(XXC>=AAAAAX){CD=false;}else{CD=true;}}}

if(YYYC2<=AAAAAY){if(DJC2==true){JC2=0.23;DJC2=false;if(XXC2>=AAAAAX){CD2=false;}else{CD2=true;}}}
}


if(XX<=XXC+4){if(XX>=XXC-4){if(YYY<=YYYC+7){if(YYY>=YYYC-7){if(YYY>=YYYC){J=0.23;if(jo == 1){score=score+1;outC = 170;YYYC=spY;XXC=spX;DJC=true;if(randy > 50){CD = true;}else{CD = false;}JC=0;}else if(jo == 2)
{JC = -0.25;}PlaySound(soundFastUpwardTones);}else{J=-0.25;JC=0.25;if(jo == 1){/*YYY=-15;*/ XX = spX; YYY = spY; DJ = true; J = 0; deaths = deaths + 1;out = 190;}}}}}}

if(XX<=XXC2+4){if(XX>=XXC2-4){if(YYY<=YYYC2+7){if(YYY>=YYYC2-7){if(YYY>=YYYC2){J=0.23;if(jo == 1){score=score+1;outC2 = 150;YYYC2=spY;XXC2=spX;DJC2=true;if(randy > 50){CD2 = true;}else{CD2 = false;}JC2=0;}else if(jo == 2)
{JC2 = -0.25;}PlaySound(soundFastUpwardTones);}else{J=-0.25;JC2=0.25;if(jo == 1){/*YYY=-15;*/ XX = spX; YYY = spY; DJ = true; J = 0; deaths = deaths + 1;out = 190;}}}}}}

if(XXC<=XXC2+4){if(XXC>=XXC2-4){if(YYYC<=YYYC2+7){if(YYYC>=YYYC2-7){if(YYYC>=YYYC2){JC=0.23;if(jo == 1){score=score+1;outC2 = 150;YYYC2=spY;XXC2=spX;DJC2=true;if(randy > 50){CD2 = true;}else{CD2 = false;}JC2=0;}else if(jo == 2)
{JC2 = -0.25;}PlaySound(soundFastUpwardTones);}else{JC=0.23;if(jo == 1){score=score+1;outC = 2000;YYYC=spY;XXC=spX;DJC=true;if(randy > 50){CD = true;}else{CD = false;}JC=0;}else if(jo == 2)
{JC = -0.25;}PlaySound(soundFastUpwardTones);}}}}}

if(YYYC < spY - 150){score=score+1;outC = 170;YYYC=spY;XXC=spX;DJC=true;if(random(5)>=1){CD = true;}else{CD = false;}JC=0;PlaySound(soundFastUpwardTones);}

if(YYYC2 < spY - 150){score=score+1;outC2 = 150;YYYC2=spY;XXC2=spX;DJC2=true;if(random(5)>=1){CD2 = true;}else{CD2 = false;}JC2=0;PlaySound(soundFastUpwardTones);}

if(YYY < spY - 150){XX = spX; YYY = spY; DJ = true; J = 0; deaths = deaths + 1;out = 190;}


if(out >= 0){out = out - 1;XX = 500;YYY = spY;}
if(outC >= 0){outC = outC - 1;XXC = 525;YYYC = spY;}
if(outC2 >= 0){outC2 = outC2 - 1;XXC2 = 550;YYYC2 = spY;}

if(out == 0){ out = out - 1; XX = spX; YYY = spY; DJ = true; J = 0;}
if(outC == 0){ outC = outC - 1; XXC = spX; YYYC = spY; DJC = true; JC = 0;}
if(outC2 == 0){ outC2 = outC2 - 1; XXC2 = spX; YYYC2 = spY; DJC = true; JC2 = 0;}


if(PY9<=-5){PY9=64;PX9=PX-15;}if(PYn<=-5){PYn=64;}

if(st==true){DJN=1;DJ=false;}

YYY=YYY+J;


if(randy == 40){
  if(DJC == true){
    if(YYYC < hY + radius){
      if(XXC > hX + 17){
        CD = false;
      }
      if(XXC < hX - 17){
        CD = true;
      }
    }
  }
}
if(randy == 70){
  if(DJC2 == true){
    if(YYYC2 < hY + radius){
      if(XXC2 > hX + 17){
        CD2 = false;
      }
      if(XXC2 < hX - 17){
        CD2 = true;
      }
    }
  }
}

//if(){sssss=100;}else{sssss=sssss-1;}
if(randy == 25 || randy == 90){
  if(YYYC>=YYY){
    if(YYYC<=YYY+25){
      if(JC<=5){
        if(XXC>=XX){
          CD=false;
        }else{
          CD=true;
        }
      }
    }else{
      if(YYYC<=YYY){
        if(YYYC>=YYY-25){
          if(JC<=0){
            if(XXC>=XX){
              CD=false;
            }else{
              CD=true;
            }
          }
        }
      }
    }
    if(YYYC2>=YYY){
        if(YYYC2<=YYY+25){
        if(JC2<=5){
          if(XXC2<=XX){
            CD2=false;
          }else{
            CD2=true;
          }
        }
      }
    }else{
      if(YYYC2<=YYY){
        if(YYYC2>=YYY-25){
          if(JC2<=0){
            if(XXC2<=XX){
              CD2=false;
            }else{
              CD2=true;
            }
          }
        }
      }
    }
  }
}



if(time1[T1] + v4 > 45000){eraseDisplay();nxtDisplayCenteredBigTextLine(1,"Game!");/*nxtDisplayCenteredBigTextLine(4,"Over!");*/nxtDisplayTextLine(7,"tot com deaths");
  nxtDisplayStringAt(90,7,"%d",score);nxtDisplayTextLine(6,"your deaths");nxtDisplayStringAt(90,15,"%d",deaths);
  nxtDisplayTextLine(4,"time in circle");
  nxtDisplayTextLine(5,"P    C    C2");
  nxtDisplayStringAt(10, 23, "%d", timeInh);
  nxtDisplayStringAt(40, 23, "%d", timeInhC);
  nxtDisplayStringAt(80, 23, "%d", timeInhC2);
  wait10Msec(6000);
}

if(SPSPSP==1){wait1Msec(7);}if(SPSPSP==2){wait1Msec(5);}if(SPSPSP==3){wait1Msec(4);}if(SPSPSP==4){wait1Msec(3);}



}




}
