

float X=50;
float Y=100;
float J=0;
bool st;
bool DJ;
bool E;
int S;
//int rg;
float L1X=50;
float L1Y=30;
int L1R=random(12)+2;
float L2X=110;
float L2Y=40;
int L2R=random(12)+2;
float L3X=210;
float L3Y=30;
int L3R=random(12)+2;
float L4X=240;
float L4Y=40;
int L4R=random(12)+2;
float L5X=300;
float L5Y=30;
int L5R=random(12)+2;
float L6X=330;
float L6Y=40;
int L6R=random(12)+2;
float B1X=80;
float B1Y=25;
int B1H=random(12)+2;
int B1W=random(12)+2;
float B2X=140;
float B2Y=30;
int B2H=random(12)+2;
int B2W=random(12)+2;
float B3X=280;
float B3Y=25;
int B3H=random(12)+2;
int B3W=random(12)+2;
float B4X=310;
float B4Y=30;
int B4H=random(12)+2;
int B4W=random(12)+2;
float B5X=400;
float B5Y=30;
int B5H=random(12)+2;
int B5W=random(12)+2;
float B6X=400;
float B6Y=30;
int B6H=random(12)+2;
int B6W=random(12)+2;
float c1X=500;
float c1Y=70;
int c1R=random(20)+10;
bool c1L=true;
float c2X=530;
float c2Y=70;
int c2R=random(20)+10;
bool c2L=true;
float c3X=560;
float c3Y=70;
int c3R=random(20)+10;
bool c3L=true;
float c4X=590;
float c4Y=70;
int c4R=random(20)+10;
bool c4L=true;
float F1X=150;
float F1Y=0;
bool F1U=true;
bool F1R=false;
float T1X=170;
float T1Y=50;
float P1X=150;
float P1Y=64;
int score=0;


void drawconveyors(float CX,float CY,int CR,bool CL){
nxtDrawLine(cX-cR,cY,cX+cR,cY);
if(cL==true){
nxtDrawLine(cX-cR,cY-3,cX-cR+5,cY-3);
nxtDrawLine(cX-cR,cY-3,cX-cR+2,cY);
nxtDrawLine(cX-cR,cY-3,cX-cR+2,cY-5);
nxtDrawLine(cX+cR-5,cY-3,cX+cR,cY-3);
nxtDrawLine(cX+cR-5,cY-3,cX+cR-2,cY);
nxtDrawLine(cX+cR-5,cY-3,cX+cR-2,cY-5);
}else{
  nxtDrawLine(cX-cR,cY-3,cX-cR+5,cY-3);
nxtDrawLine(cX-cR+5,cY-3,cX-cR+2,cY);
nxtDrawLine(cX-cR+5,cY-3,cX-cR+2,cY-5);
nxtDrawLine(cX+cR-5,cY-3,cX+cR,cY-3);
nxtDrawLine(cX+cR,cY-3,cX+cR-2,cY);
nxtDrawLine(cX+cR,cY-3,cX+cR-2,cY-5);
}
}

task main(){

  nNxtExitClicks=3;


  nxtDisplayBigTextLine(3,"XD thing!");
  wait1Msec(500);

  while(1==1){
    eraseDisplay();

    nxtDrawEllipse(X+2,Y+2,X-2,Y-2);

    nxtDrawLine(L1X-L1R,L1Y,L1X+L1R,L1Y);
    nxtDrawLine(L2X-L2R,L2Y,L2X+L2R,L2Y);
    nxtDrawLine(L3X-L3R,L3Y,L3X+L3R,L3Y);
    nxtDrawLine(L4X-L4R,L4Y,L4X+L4R,L4Y);
    nxtDrawLine(L5X-L5R,L5Y,L5X+L5R,L5Y);
    nxtDrawLine(L6X-L6R,L6Y,L6X+L6R,L6Y);
nxtFillRect(B1X+B1W,B1Y+B1H,B1X-B1W,B1Y-B1H);
nxtFillRect(B2X+B2W,B2Y+B2H,B2X-B2W,B2Y-B2H);
nxtFillRect(B3X+B3W,B3Y+B3H,B3X-B3W,B3Y-B3H);
nxtFillRect(B4X+B4W,B4Y+B4H,B4X-B4W,B4Y-B4H);
nxtFillRect(B5X+B5W,B5Y+B5H,B5X-B5W,B5Y-B5H);
nxtFillRect(B6X+B6W,B6Y+B6H,B6X-B6W,B6Y-B6H);
nxtDrawRect(T1X+5,T1Y+5,T1X-5,T1Y-5);
nxtDrawLine(T1X,T1Y+3,T1X,T1Y-3);
nxtDrawLine(T1X,T1Y+3,T1X-3,T1Y);
nxtDrawLine(T1X,T1Y+3,T1X+3,T1Y);
nxtDrawLine(P1X-4,P1Y+4,P1X-1,P1Y-4);
nxtDrawLine(P1X-4,P1Y-4,P1X-1,P1Y+4);
nxtDrawLine(P1X+1,P1Y+4,P1X+4,P1Y);
nxtDrawLine(P1X+1,P1Y-4,P1X+4,P1Y);
nxtDrawLine(P1X+1,P1Y-4,P1X+1,P1Y+4);


drawconveyors(c1X,c1Y,c1R,c1L);
drawconveyors(c2X,c2Y,c2R,c2L);
drawconveyors(c3X,c3Y,c3R,c3L);
drawconveyors(c4X,c4Y,c4R,c4L);


nxtDrawRect(F1X-5,F1Y-5,F1X+5,F1Y+5);
nxtDrawLine(F1X-2,F1Y,F1X+2,F1Y);
nxtDrawLine(F1X,F1Y-1,F1X,F1Y+1);



   Y=Y+J;


  J=J-0.01;

  if(L1X<=-30){
    L1X=random(70)+120;
L1Y=random(64)+5;
L1R=random(12)+2;
//rg=70;
}
if(L2X<=-30){
    L2X=random(70)+120;
L2Y=random(64)+5;
L2R=random(12)+2;
//rg=70;
}
if(L3X<=-30){
    L3X=random(70)+120;
L3Y=random(64)+5;
L3R=random(12)+2;
//rg=70;
}
if(L4X<=-30){
    L4X=random(70)+120;
L4Y=random(64)+5;
L4R=random(12)+2;
//rg=70;
}
if(L5X<=-30){
    L5X=random(70)+120;
L5Y=random(64)+5;
L5R=random(12)+2;
//rg=70;
}
if(L6X<=-30){
    L6X=random(70)+120;
L6Y=random(64)+5;
L6R=random(12)+2;
//rg=70;
}

if(B1X<=-30){
    B1X=random(70)+120;
B1Y=random(64)+5;
B1W=random(12)+2;
B1H=random(12)+2;
//rg=70;
}
if(B2X<=-30){
    B2X=random(70)+120;
B2Y=random(64)+5;
B2W=random(12)+2;
B2H=random(12)+2;
//rg=70;
}
if(B3X<=-30){
    B3X=random(70)+120;
B3Y=random(64)+5;
B3W=random(12)+2;
B3H=random(12)+2;
//rg=70;
}
if(B4X<=-30){
    B4X=random(70)+120;
B4Y=random(64)+5;
B4W=random(12)+2;
B4H=random(12)+2;
//rg=70;
}
if(B5X<=-30){
    B5X=random(70)+120;
B5Y=random(64)+5;
B5W=random(12)+2;
B5H=random(12)+2;
//rg=70;
}
if(B6X<=-30){
    B6X=random(70)+120;
B6Y=random(64)+5;
B6W=random(12)+2;
B6H=random(12)+2;
//rg=70;
}
if(F1X<=-20){
  F1X=random(70)+120;
  F1Y=random(50)-30;
  F1U=true;
  F1R=false;
  //rg=70;
}

if(c1X<=-30){
    c1X=random(70)+120;
c1Y=random(64)+5;
c1R=random(20)+10;
if(random(10)>=5){c1L=true;}
else{c1L=false;}
//rg=70;
}
if(c2X<=-30){
    c2X=random(70)+120;
c2Y=random(64)+5;
c2R=random(20)+10;
if(random(10)>=5){c2L=true;}
else{c2L=false;}
//rg=70;
}
if(c3X<=-30){
    c3X=random(70)+120;
c3Y=random(64)+5;
c3R=random(20)+10;
if(random(10)>=5){c3L=true;}
else{c3L=false;}
//rg=70;
}
if(c4X<=-30){
    c4X=random(70)+120;
c4Y=random(64)+5;
c4R=random(20)+10;
if(random(10)>=5){c4L=true;}
else{c4L=false;}
//rg=70;
}



if(T1X<=-30){
  T1X=random(70)+120;
T1Y=random(64)+5;
}

if(X<=P1X+5&&X>=P1X-5&&Y<=P1Y+5&&Y>=P1Y-5||P1X<=-30){
  score=score+1;
  P1X=random(70)+120;
P1Y=random(64)+5;
}


if(Y<=-10){eraseDisplay();
nxtDisplayBigStringAt(2,30,"XDs: %d",score);wait1Msec(10000);}


if(Y<=T1Y+5&&Y>=T1Y-5&&X<=T1X+5&&X>=T1X-5){J=0.9;}

  st=false;
  if(Y<=L1Y+2&&Y>=L1Y&&X<=L1X+L1R+1&&X>=L1X-L1R-1){st=true;}
  if(Y<=L2Y+2&&Y>=L2Y&&X<=L2X+L2R+1&&X>=L2X-L2R-1){st=true;}
  if(Y<=L3Y+2&&Y>=L3Y&&X<=L3X+L3R+1&&X>=L3X-L3R-1){st=true;}
  if(Y<=L4Y+2&&Y>=L4Y&&X<=L4X+L4R+1&&X>=L4X-L4R-1){st=true;}
  if(Y<=L5Y+2&&Y>=L5Y&&X<=L5X+L5R+1&&X>=L5X-L5R-1){st=true;}
  if(Y<=L6Y+2&&Y>=L6Y&&X<=L6X+L6R+1&&X>=L6X-L6R-1){st=true;}
  if(Y<=B1Y+B1H+2&&Y>=B1Y-B1H-1&&X<=B1X+B1W+1&&X>=B1X-B1W-1){if(Y>=B1Y+B1H){st=true;}
  else{if(Y<=B1Y-B1H+2){Y=Y-1;if(J>=0){J=0;}}else{if(X>=B1X){X=X+1;}else{X=X-1;}}}}
  if(Y<=B2Y+B2H+2&&Y>=B2Y-B2H-1&&X<=B2X+B2W+1&&X>=B2X-B2W-1){if(Y>=B2Y+B2H){st=true;}
  else{if(Y<=B2Y-B2H+2){Y=Y-1;if(J>=0){J=0;}}else{if(X>=B2X){X=X+1;}else{X=X-1;}}}}
  if(Y<=B3Y+B3H+2&&Y>=B3Y-B3H-1&&X<=B3X+B3W+1&&X>=B3X-B3W-1){if(Y>=B3Y+B3H){st=true;}
  else{if(Y<=B3Y-B3H+2){Y=Y-1;if(J>=0){J=0;}}else{if(X>=B3X){X=X+1;}else{X=X-1;}}}}
  if(Y<=B4Y+B4H+2&&Y>=B4Y-B4H-1&&X<=B4X+B4W+1&&X>=B4X-B4W-1){if(Y>=B4Y+B4H){st=true;}
  else{if(Y<=B4Y-B4H+2){Y=Y-1;if(J>=0){J=0;}}else{if(X>=B4X){X=X+1;}else{X=X-1;}}}}
  if(Y<=B5Y+B5H+2&&Y>=B5Y-B5H-1&&X<=B5X+B5W+1&&X>=B5X-B5W-1){if(Y>=B5Y+B5H){st=true;}
  else{if(Y<=B5Y-B5H+2){Y=Y-1;if(J>=0){J=0;}}else{if(X>=B5X){X=X+1;}else{X=X-1;}}}}
  if(Y<=B6Y+B6H+2&&Y>=B6Y-B6H-1&&X<=B6X+B6W+1&&X>=B6X-B6W-1){if(Y>=B6Y+B6H){st=true;}
  else{if(Y<=B6Y-B6H+2){Y=Y-1;if(J>=0){J=0;}}else{if(X>=B6X){X=X+1;}else{X=X-1;}}}}
  if(Y<=c1Y+2&&Y>=c1Y&&X<=c1X+c1R+1&&X>=c1X-c1R-1){st=true;if(c1L==true){X=X-0.3;}else{X=X+0.3;}}
  if(Y<=c2Y+2&&Y>=c2Y&&X<=c2X+c2R+1&&X>=c2X-c2R-1){st=true;if(c2L==true){X=X-0.3;}else{X=X+0.3;}}
  if(Y<=c3Y+2&&Y>=c3Y&&X<=c3X+c3R+1&&X>=c3X-c3R-1){st=true;if(c3L==true){X=X-0.3;}else{X=X+0.3;}}
  if(Y<=c4Y+2&&Y>=c4Y&&X<=c4X+c4R+1&&X>=c4X-c4R-1){st=true;if(c4L==true){X=X-0.3;}else{X=X+0.3;}}
if(Y<=F1Y+5+2&&Y>=F1Y-5-1&&X<=F1X+5+1&&X>=F1X-5-1){if(Y>=F1Y+5){st=true;F1U=false;Y=Y-0.1;if(F1R==true){X=X+0.1;}else{X=X-0.1;}}
  else{if(Y<=F1Y-3){F1U=true;Y=Y-1;if(J>=0){J=0;}}else{if(X>=F1X){X=X+1;F1R=false;}else{X=X-1;F1R=true;}}}}



  if(F1U==true){F1Y=F1Y+0.1;}
  else{F1Y=F1Y-0.1;}
  if(F1R==true){F1X=F1X+0.1;}
  else{F1X=F1X-0.1;}

  if(J>=0){st=false;}

  if(st==true){J=0;DJ=true;}

if(S<=0){
  if(X>=65){X=X-1;L1X=L1X-1;B1X=B1X-1;L2X=L2X-1;B2X=B2X-1;T1X=T1X-1;L3X=L3X-1;L4X=L4X-1;B3X=B3X-1;B4X=B4X-1;B5X=B5X-1;B6X=B6X-1;L5X=L5X-1;L6X=L6X-1;P1X=P1X-1;
  F1X=F1X-1;c1X=c1X-1;c2X=c2X-1;c3X=c3X-1;c4X=c4X-1;}
  if(X<=45){X=X+1;L1X=L1X+1;B1X=B1X+1;L2X=L2X+1;B2X=B2X+1;T1X=T1X+1;L3X=L3X+1;L4X=L4X+1;B3X=B3X+1;B4X=B4X+1;B5X=B5X+1;B6X=B6X+1;L5X=L5X+1;L6X=L6X+1;P1X=P1X+1;
F1X=F1X+1;c1X=c1X+1;c2X=c2X+1;c3X=c3X+1;c4X=c4X+1;}
  if(Y>=20){Y=Y-1;L1Y=L1Y-1;B1Y=B1Y-1;L2Y=L2Y-1;B2Y=B2Y-1;T1Y=T1Y-1;L3Y=L3Y-1;L4Y=L4Y-1;B3Y=B3Y-1;B4Y=B4Y-1;B5Y=B5Y-1;B6Y=B6Y-1;L5Y=L5Y-1;L6Y=L6Y-1;P1Y=P1Y-1;
F1Y=F1Y-1;c1Y=c1Y-1;c2Y=c2Y-1;c3Y=c3Y-1;c4Y=c4Y-1;}
  if(Y<=40){Y=Y+1;L1Y=L1Y+1;B1Y=B1Y+1;L2Y=L2Y+1;B2Y=B2Y+1;T1Y=T1Y+1;L3Y=L3Y+1;L4Y=L4Y+1;B3Y=B3Y+1;B4Y=B4Y+1;B5Y=B5Y+1;B6Y=B6Y+1;L5Y=L5Y+1;L6Y=L6Y+1;P1Y=P1Y+1;
F1Y=F1Y+1;c1Y=c1Y+1;c2Y=c2Y+1;c3Y=c3Y+1;c4Y=c4Y+1;}
}else{
  s=s-1;
  if(X+45>=65){X=X-1;L1X=L1X-1;B1X=B1X-1;L2X=L2X-1;B2X=B2X-1;T1X=T1X-1;L3X=L3X-1;L4X=L4X-1;B3X=B3X-1;B4X=B4X-1;B5X=B5X-1;B6X=B6X-1;L5X=L5X-1;L6X=L6X-1;P1X=P1X-1;
F1X=F1X-1;c1X=c1X-1;c2X=c2X-1;c3X=c3X-1;c4X=c4X-1;}
  if(X+45<=45){X=X+1;L1X=L1X+1;B1X=B1X+1;L2X=L2X+1;B2X=B2X+1;T1X=T1X+1;L3X=L3X+1;L4X=L4X+1;B3X=B3X+1;B4X=B4X+1;B5X=B5X+1;B6X=B6X+1;L5X=L5X+1;L6X=L6X+1;P1X=P1X+1;
F1X=F1X+1;c1X=c1X+1;c2X=c2X+1;c3X=c3X+1;c4X=c4X+1;}
  if(Y>=20){Y=Y-1;L1Y=L1Y-1;B1Y=B1Y-1;L2Y=L2Y-1;B2Y=B2Y-1;T1Y=T1Y-1;L3Y=L3Y-1;L4Y=L4Y-1;B3Y=B3Y-1;B4Y=B4Y-1;B5Y=B5Y-1;B6Y=B6Y-1;L5Y=L5Y-1;L6Y=L6Y-1;P1Y=P1Y-1;
F1Y=F1Y-1;c1Y=c1Y-1;c2Y=c2Y-1;c3Y=c3Y-1;c4Y=c4Y-1;}
  if(Y<=40){Y=Y+1;L1Y=L1Y+1;B1Y=B1Y+1;L2Y=L2Y+1;B2Y=B2Y+1;T1Y=T1Y+1;L3Y=L3Y+1;L4Y=L4Y+1;B3Y=B3Y+1;B4Y=B4Y+1;B5Y=B5Y+1;B6Y=B6Y+1;L5Y=L5Y+1;L6Y=L6Y+1;P1Y=P1Y+1;
F1Y=F1Y+1;c1Y=c1Y+1;c2Y=c2Y+1;c3Y=c3Y+1;c4Y=c4Y+1;}

}





  if(nNxtButtonPressed==1){X=X+0.25;}
  if(nNxtButtonPressed==2){X=X-0.25;}
  if(nNxtButtonPressed==3){if(st==true){J=0.7;E=true;}else{if(E==false){if(DJ==true){J=0.7;DJ=false;}}}E=true;}
  else{E=false;}
  if(nNxtButtonPressed==0){S=100;}


  wait1Msec(10);
}



}
