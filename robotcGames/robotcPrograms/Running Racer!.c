
task main(){   float PX=50;float PY;float J;float l1X;float l1Y;float AVX;float AVY; int AAA;  float st;
float L1X=70; float L1Y=20;float W1X=100; float W1Y=10;float W2X=100; float W2Y=10;  float W3X=100; float W3Y=10;float W4X=100; float W4Y=10;
float C1X; float C1Y;float C1J;float C1st;float C2X=-50; float C2Y;float C2J;float C2st;int ra;float I1X;float I1Y;int PPP;int C1PPP;int C2PPP;
float TPX;float TPY;float TC1X;float TC1Y;float TC2X;float TC2Y;int plc;int score=100;int scnt;float B1X;float B1Y;int sec; int tme;int total;int bsts;
int bstsP;

while(1==1){eraseDisplay();ra=random(200);scnt=scnt+1;
if(scnt>=75){score=score-1;scnt=0;}

nxtFillRect(AVX+2000,-1,110,65);

nxtDrawRect(B1X+10,B1Y+10,B1X-10,B1Y-10);

nxtDrawRect(I1X-5,I1Y-5,I1X+5,I1Y+5);
nxtDrawLine(I1X-5,I1Y-5,I1X+5,I1Y+5);
nxtDrawLine(I1X+5,I1Y-5,I1X-5,I1Y+5);

nxtDrawLine(L1X-7,L1Y,L1X+7,L1Y);
nxtFillRect(W1X,W1Y+10,w1X+1,W1Y-10);
nxtFillRect(W2X,W2Y+10,w2X+1,W2Y-10);
nxtFillRect(W3X,W3Y+10,w3X+1,W3Y-10);
nxtFillRect(W4X,W4Y+10,w4X+1,W4Y-10);

  if(AAA==1){
     nxtDrawLine(PX+4,PY,PX,PY+4);
     nxtDrawLine(PX-4,PY,PX,PY+4);
     nxtDrawLine(PX,PY+4,PX,PY+8);
     nxtDrawLine(PX,PY+8,PX+5,PY+8);
     nxtDrawLine(PX,PY+8,PX-5,PY+8);
     nxtDrawLine(PX+2,PY+8,PX+2,PY+11);
     nxtDrawLine(PX-2,PY+8,PX-2,PY+11);
     nxtDrawLine(PX+2,PY+12,PX-2,PY+12);
  }
  if(AAA==2){
     nxtDrawLine(PX+3,PY,PX,PY+4);
     nxtDrawLine(PX-6,PY+2,PX,PY+4);
     nxtDrawLine(PX,PY+4,PX,PY+8);
     nxtDrawLine(PX,PY+8,PX+4,PY+8);
     nxtDrawLine(PX,PY+8,PX-4,PY+8);
     nxtDrawLine(PX+2,PY+8,PX+2,PY+11);
     nxtDrawLine(PX-2,PY+8,PX-2,PY+11);
     nxtDrawLine(PX+2,PY+12,PX-2,PY+12);
  }
if(AAA==3){
     nxtDrawLine(PX-3,PY,PX,PY+4);
     nxtDrawLine(PX+6,PY+2,PX,PY+4);
     nxtDrawLine(PX,PY+4,PX,PY+8);
     nxtDrawLine(PX,PY+8,PX+4,PY+8);
     nxtDrawLine(PX,PY+8,PX-4,PY+8);
     nxtDrawLine(PX+2,PY+8,PX+2,PY+11);
     nxtDrawLine(PX-2,PY+8,PX-2,PY+11);
     nxtDrawLine(PX+2,PY+12,PX-2,PY+12);
  }

   nxtDrawLine(C1X+3,C1Y,C1X,C1Y+4);
     nxtDrawLine(C1X-6,C1Y+2,C1X,C1Y+4);
     nxtDrawLine(C1X,C1Y+4,C1X,C1Y+8);
     nxtDrawLine(C1X,C1Y+8,C1X+4,C1Y+8);
     nxtDrawLine(C1X,C1Y+8,C1X-4,C1Y+8);
     nxtDrawLine(C1X+2,C1Y+8,C1X+2,C1Y+11);
     nxtDrawLine(C1X-2,C1Y+8,C1X-2,C1Y+11);
     nxtDrawLine(C1X+2,C1Y+12,C1X-2,C1Y+12);

     nxtDrawLine(C2X+3,C2Y,C2X,C2Y+4);
     nxtDrawLine(C2X-6,C2Y+2,C2X,C2Y+4);
     nxtDrawLine(C2X,C2Y+4,C2X,C2Y+8);
     nxtDrawLine(C2X,C2Y+8,C2X+4,C2Y+8);
     nxtDrawLine(C2X,C2Y+8,C2X-4,C2Y+8);
     nxtDrawLine(C2X+2,C2Y+8,C2X+2,C2Y+11);
     nxtDrawLine(C2X-2,C2Y+8,C2X-2,C2Y+11);
     nxtDrawLine(C2X+2,C2Y+12,C2X-2,C2Y+12);

  PPP=PPP-1;C1PPP=C1PPP-1;C2PPP=C2PPP-1;
     if(PX<=I1X+8){if(PX>=I1X-8){if(PY<=I1Y+5){if(PY>=I1Y-14){PPP=100;I1X=random(200)+155;I1Y=random(40);bsts=bsts+1;}}}}
     if(C1X<=I1X+8){if(C1X>=I1X-8){if(c1Y<=I1Y+5){if(C1Y>=I1Y-14){C1PPP=100;I1X=random(200)+155;I1Y=random(40);}}}}
     if(C2X<=I1X+8){if(C2X>=I1X-8){if(c2Y<=I1Y+5){if(C2Y>=I1Y-14){C2PPP=100;I1X=random(200)+155;I1Y=random(40);}}}}

     if(PPP>=0){PX=PX+0.3;}
     if(C1PPP>=0){C1X=C1X+0.3;}
     if(C2PPP>=0){C2X=C2X+0.3;}


  if(PX>=60){AVX=AVX-1;PX=PX-1;L1X=L1X-1;W1X=W1X-1;W2X=W2X-1;W3X=W3X-1;W4X=W4X-1;C1X=C1X-1;C2X=C2X-1;I1X=I1X-1;B1X=B1X-1;}
  if(PX<=40){AVX=AVX+1;PX=PX+1;L1X=L1X+1;W1X=W1X+1;W2X=W2X+1;W3X=W3X+1;W4X=W4X+1;C1X=C1X+1;C2X=C2X+1;I1X=I1X+1;B1X=B1X+1;}


if(C1X>=150){C1X=C1X-0.3;}
if(C2X>=150){C2X=C2X-0.3;}


if(PY<=C1Y+7){if(PY>=C1Y-7){if(PX<=C1X){if(((C1X-PX)/-1)+30>=0){PX=PX+(((C1X-PX)/-1)+30)/50;}}}}
if(PY<=C2Y+7){if(PY>=C2Y-7){if(PX<=C2X){if(((C2X-PX)/-1)+30>=0){PX=PX+(((C2X-PX)/-1)+30)/50;}}}}
if(C1Y<=PY+7){if(C1Y>=PY-7){if(C1X<=PX){if(AAA==2){if(((PX-C1X)/-1)+30>=0){C1X=C1X+(((PX-C1X)/-1)+30)/50;}}}}}
if(C1Y<=C2Y+7){if(C1Y>=C2Y-7){if(C1X<=C2X){if(((C2X-C1X)/-1)+30>=0){C1X=C1X+(((C2X-C1X)/-1)+30)/50;}}}}
if(C2Y<=PY+7){if(C2Y>=PY-7){if(C2X<=PX){if(AAA==2){if(((PX-C2X)/-1)+30>=0){C2X=C2X+(((PX-C2X)/-1)+30)/50;}}}}}
if(C2Y<=C1Y+7){if(C2Y>=C1Y-7){if(C2X<=C1X){if(((C1X-C2X)/-1)+30>=0){C2X=C2X+(((C1X-C2X)/-1)+30)/50;}}}}



tme=tme+1;
if(tme>=111){sec=sec+1;tme=0;}


PY=PY+j;
C1Y=C1Y+C1j;
C2Y=C2Y+C2j;


TPX=PX;
TC1X=C1X;
TC2X=C2X;

st=false;

if(PX>=C1X-5){if(PX<=C1X+5){if(PY>=C1Y-9){if(PY<=C1Y+9){if(PY>=C1Y+7){if(J<=0){st=true;}}else{if(PY<=C1Y-7){}else{if(PX<=C1X){TPX=PX-1;}else{TPX=PX+1;}}}}}}}
if(PX>=C2X-5){if(PX<=C2X+5){if(PY>=C2Y-9){if(PY<=C2Y+9){if(PY>=C2Y+7){if(J<=0){st=true;}}else{if(PY<=C2Y-7){}else{if(PX<=C2X){TPX=PX-1;}else{TPX=PX+1;}}}}}}}

if(PX>=B1X-13){if(PX<=B1X+13){if(PY<=B1Y+10){if(PY>=B1Y-19){
  if(PY>=B1Y+8){if(J<=0){st=true;}}else{if(PY<=B1Y-18){TPY=B1Y-19;if(J>=0){J=0;}}else{if(PX>=B1X){TPX=TPX+1;}else{TPX=TPX-1;}}}}}}}


if(PX>=L1X-7){if(PX<=L1X+7){if(PY>=L1Y-1){if(PY<=L1Y+1){if(j<=0){st=true;}}}}}
if(PY<=AVY+1){st=true;}
if(st==true){j=0;}else{j=j-0.02;}


if(PX>=W1X-1){if(PX<=W1X+1){if(PY>=W1Y-19){if(PY<=W1Y+9){if(PX>=w1X){TPX=TPX+1;}else{TPX=TPX-1;}}}}}
if(PX>=W2X-1){if(PX<=W2X+1){if(PY>=W2Y-19){if(PY<=W2Y+9){if(PX>=w2X){TPX=TPX+1;}else{TPX=TPX-1;}}}}}
if(PX>=W3X-1){if(PX<=W3X+1){if(PY>=W3Y-19){if(PY<=W3Y+9){if(PX>=w3X){TPX=TPX+1;}else{TPX=TPX-1;}}}}}
if(PX>=W4X-1){if(PX<=W4X+1){if(PY>=W4Y-19){if(PY<=W4Y+9){if(PX>=w4X){TPX=TPX+1;}else{TPX=TPX-1;}}}}}


C1st=false;

if(C1X>=PX-5){if(C1X<=PX+5){if(C1Y>=PY-9){if(C1Y<=PY+9){if(C1Y>=PY+7){C1st=true;}else{if(C1Y<=PY-7){}else{if(C1X<=PX){TC1X=C1X-1;}else{TC1X=C1X+1;}}}}}}}
if(C1X>=C2X-5){if(C1X<=C2X+5){if(C1Y>=C2Y-9){if(C1Y<=C2Y+9){if(C1Y>=C2Y+7){C1st=true;}else{if(C1Y<=C2Y-7){}else{if(C1X<=C2X){TC1X=C1X-1;}else{TC1X=C1X+1;}}}}}}}

if(C1X>=L1X-7){if(C1X<=L1X+7){if(C1Y>=L1Y-1){if(C1Y<=L1Y+1){if(C1j<=0){C1st=true;}}}}}
if(C1Y<=AVY+1){C1st=true;}

if(C1X>=B1X-13){if(C1X<=B1X+13){if(C1Y<=B1Y+10){if(C1Y>=B1Y-19){
  if(C1Y>=B1Y+8){if(C1J<=0){C1st=true;}}else{if(C1Y<=B1Y-18){TC1Y=B1Y-19;if(C1J>=0){C1J=0;}}else{if(C1X>=B1X){TC1X=TC1X+1;}else{TC1X=TC1X-1;if(C1st==true){C1J=1.1;TC1Y=TC1Y+1;}}}}}}}}

  if(C1st==true){C1j=0;}else{C1j=C1j-0.02;}

  if(C1X>=B1X-13){if(C1X<=B1X+13){if(C1Y<=B1Y+10){if(C1Y>=B1Y-19){
  if(C1Y>=B1Y+8){if(C1J<=0){C1st=true;}}else{if(C1Y<=B1Y-18){TC1Y=B1Y-19;if(C1J>=0){C1J=0;}}else{if(C1X>=B1X){TC1X=TC1X+1;}else{TC1X=TC1X-1;if(C1st==true){C1J=1.1;TC1Y=TC1Y+1;}}}}}}}}

  if(C1X>=W1X-1){if(C1X<=W1X+1){if(C1Y>=W1Y-19){if(C1Y<=W1Y+9){if(C1X>=w1X){TC1X=TC1X+1;}else{TC1X=TC1X-1;if(C1st==true){if(ra<=5){C1j=1.1;}}}}}}}
if(C1X>=W2X-1){if(C1X<=W2X+1){if(C1Y>=W2Y-19){if(C1Y<=W2Y+9){if(C1X>=w2X){TC1X=TC1X+1;}else{TC1X=TC1X-1;if(C1st==true){if(ra<=5){C1j=1.1;}}}}}}}
if(C1X>=W3X-1){if(C1X<=W3X+1){if(C1Y>=W3Y-19){if(C1Y<=W3Y+9){if(C1X>=w3X){TC1X=TC1X+1;}else{TC1X=TC1X-1;if(C1st==true){if(ra<=5){C1j=1.1;}}}}}}}
if(C1X>=W4X-1){if(C1X<=W4X+1){if(C1Y>=W4Y-19){if(C1Y<=W4Y+9){if(C1X>=w4X){TC1X=TC1X+1;}else{TC1X=TC1X-1;if(C1st==true){if(ra<=5){C1j=1.1;}}}}}}}





  C2st=false;

if(C2X>=PX-5){if(C2X<=PX+5){if(C2Y>=PY-9){if(C2Y<=PY+9){if(C2Y>=PY+7){C2st=true;}else{if(C2Y<=PY-7){}else{if(C2X<=PX){TC2X=C2X-1;}else{TC2X=C2X+1;}}}}}}}
if(C2X>=C1X-5){if(C2X<=C1X+5){if(C2Y>=C1Y-9){if(C2Y<=C1Y+9){if(C2Y>=C1Y+7){C2st=true;}else{if(C2Y<=C1Y-7){}else{if(C2X<=C1X){TC2X=C2X-1;}else{TC2X=C2X+1;}}}}}}}



if(C2X>=L1X-7){if(C2X<=L1X+7){if(C2Y>=L1Y-1){if(C2Y<=L1Y+1){if(C2j<=0){C2st=true;}}}}}
if(C2Y<=AVY+1){C2st=true;}

if(C2X>=B1X-14){if(C2X<=B1X+14){if(C2Y<=B1Y+10){if(C2Y>=B1Y-19){
  if(C2Y>=B1Y+8){if(C2J<=0){C2st=true;}}else{if(C2Y<=B1Y-18){TC2Y=B1Y-19;if(C2J>=0){C2J=0;}}else{if(C2X>=B1X){TC2X=TC2X+1;}else{TC2X=TC2X-1;if(C2st==true){C2J=1.1;TC2Y=TC2Y+1;}}}}}}}}

  if(C2st==true){C2j=0;}else{C2j=C2j-0.02;}

  if(C2X>=B1X-14){if(C2X<=B1X+14){if(C2Y<=B1Y+10){if(C2Y>=B1Y-19){
  if(C2Y>=B1Y+8){if(C2J<=0){C2st=true;}}else{if(C2Y<=B1Y-18){TC2Y=B1Y-19;if(C2J>=0){C2J=0;}}else{if(C2X>=B1X){TC2X=TC2X+1;}else{TC2X=TC2X-1;if(C2st==true){C2J=1.1;TC2Y=TC2Y+1;}}}}}}}}

  if(C2X>=W1X-1){if(C2X<=W1X+1){if(C2Y>=W1Y-19){if(C2Y<=W1Y+9){if(C2X>=w1X){TC2X=TC2X+1;}else{TC2X=TC2X-1;if(C2st==true){C2j=1.1;}}}}}}
if(C2X>=W2X-1){if(C2X<=W2X+1){if(C2Y>=W2Y-19){if(C2Y<=W2Y+9){if(C2X>=w2X){TC2X=TC2X+1;}else{TC2X=TC2X-1;if(C2st==true){C2j=1.1;}}}}}}
if(C2X>=W3X-1){if(C2X<=W3X+1){if(C2Y>=W3Y-19){if(C2Y<=W3Y+9){if(C2X>=w3X){TC2X=TC2X+1;}else{TC2X=TC2X-1;if(C2st==true){C2j=1.1;}}}}}}
if(C2X>=W4X-1){if(C2X<=W4X+1){if(C2Y>=W4Y-19){if(C2Y<=W4Y+9){if(C2X>=w4X){TC2X=TC2X+1;}else{TC2X=TC2X-1;if(C2st==true){C2j=1.1;}}}}}}





  PX=TPX;
C1X=TC1X;
C2X=TC2X;

if(L1X<=-10){L1X=random(50)+105;L1Y=random(60);}if(W1X<=-10){W1X=random(50)+150;W1Y=random(60);}
if(W2X<=-10){W2X=random(50)+150;W2Y=random(60);}if(W3X<=-10){W3X=random(50)+150;W3Y=random(60);}
if(W4X<=-10){W4X=random(50)+150;W4Y=random(60);}if(B1X<=-10){B1X=random(50)+150;B1Y=random(60);}

if(L1X>=210){L1X=random(50)+105;L1Y=random(60);}if(W1X>=210){W1X=random(50)+150;W1Y=random(60);}
if(W2X>=210){W2X=random(50)+150;W2Y=random(60);}if(W3X>=210){W3X=random(50)+150;W3Y=random(60);}
if(W4X>=210){W4X=random(50)+150;W4Y=random(60);}

if(I1X<=-20){I1X=random(200)+155;I1Y=random(40);}



AAA=1;
if(nNxtButtonPressed==1){AAA=2;PX=PX+0.5;}
if(nNxtButtonPressed==2){AAA=3;PX=PX-0.5;}
if(nNxtButtonPressed==3){if(st==true){J=1.1;}}
C1X=C1X+0.5;
C2X=C2X+0.5;

wait1Msec(9);

plc=1;
if(C1X>=PX){plc=plc+1;}
if(C2X>=PX){plc=plc+1;}


if(PX>=AVX+2000){eraseDisplay();
bstsP=bsts+bsts+bsts+bsts+bsts;
nxtDisplayTextLine(2,"finish");
nxtDisplayTextLine(4," boosts");
nxtDisplayTextLine(5," place");
nxtDisplayStringAt(45,24,"%d",plc);
if(plc==1){nxtDisplayStringAt(51,24,"st");
nxtDisplayStringAt(80,24,"+30");total=30+score+bstsP;}
if(plc==2){nxtDisplayStringAt(51,24,"nd");
nxtDisplayStringAt(80,24,"+15");total=15+score+bstsP;}
if(plc==3){nxtDisplayStringAt(51,24,"rd");
nxtDisplayStringAt(80,24,"+5");total=5+score+bstsP;}
nxtDisplayTextLine(6," time");
nxtDisplayStringAt(45,14,"%d",sec);
nxtDisplayStringAt(80,14,"+");
nxtDisplayStringAt(86,14,"%d",score);
nxtDisplayTextLine(7," total score");
nxtDisplayStringAt(80,6,"%d",total);
nxtDisplayStringAt(45,33,"%d",bsts);
nxtDisplayStringAt(80,33,"+");
nxtDisplayStringAt(85,33,"%d",bstsP);
wait1Msec(10000);}


}
}
