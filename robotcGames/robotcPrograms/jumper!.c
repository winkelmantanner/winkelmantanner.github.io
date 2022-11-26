task main(){
int H=151;
 float XX=50;
  float YY=-1;
  float JJ;
  bool st;
  float LX;
  float LY=21;
  bool L;
   float LX2;
  float LY2=42;
  bool L2;
  float LX3;
  float LY3=63;
  bool L3;
  int SSS;
  wait1Msec(1000);
  while(1==1){eraseDisplay();int YYY=YY+2;
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
nxtDrawLine(LX,LY,LX+10,LY);
nxtDrawLine(LX2,LY2,LX2+10,LY2);
nxtDrawLine(LX3,LY3,LX3+10,LY3);
nxtDisplayStringAt(2,62,"%d",H);
if (YY<=1){ H=H-1}
if(L==true){LX=LX+0.5;}
if(L==false){LX=LX-0.5;}
if(LX>=90){L=false}
if(LX<=0){L=true}

if(L2==true){LX2=LX2+0.37;}
if(L2==false){LX2=LX2-0.37;}
if(LX2>=90){L2=false}
if(LX2<=0){L2=true}

if(L3==true){LX3=LX3+0.22;}
if(L3==false){LX3=LX3-0.22;}
if(LX3>=90){L3=false}
if(LX3<=0){L3=true}
LY=LY-0.25;LY2=LY2-0.25;LY3=LY3-0.25;

if(LY<=0){LY=64}if(LY2<=0){LY2=64}if(LY3<=0){LY3=64}

wait1Msec(30);
int JJJ=JJ+3;
YY=YY+JJJ;
if(YY<=0){st=true;}else{st=false;}
if(YY>=LY-1){if(YY<=LY+1){if(XX>=LX){if(XX<=LX+10){YY=YY-0.25;st=true;if(L==true){XX=XX+0.5;}else{XX=XX-0.5;}}}}}
if(YY>=LY2-1){if(YY<=LY2+1){if(XX>=LX2){if(XX<=LX2+10){YY=YY-0.25;st=true;if(L2==true){XX=XX+0.37;}else{XX=XX-0.37;}}}}}
if(YY>=LY3-1){if(YY<=LY3+1){if(XX>=LX3){if(XX<=LX3+10){YY=YY-0.25;st=true;if(L3==true){XX=XX+0.22;}else{XX=XX-0.22;}}}}}
if(st==true){JJ=-3;}
else{JJ=JJ-0.11;}

if(H<=0){eraseDisplay();nxtDisplayBigTextLine(2,"GameOver");nxtDisplayBigStringAt(2,25,"%d",SSS);wait1Msec(10000);}

if(nNxtButtonPressed==1){XX=XX+1;}
if(nNxtButtonPressed==2){XX=XX-1;}
if(nNxtButtonPressed==3){if(st==true){JJ=0;}}else{}



SSS=SSS+1;



}
}
