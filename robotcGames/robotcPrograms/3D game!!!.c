#pragma config(Sensor, S1,     S1,                  sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){

eraseDisplay();

nxtDisplayCenteredTextLine(3,"press");
nxtDisplayCenteredTextLine(4,"touch sensor");
nxtDisplayCenteredTextLine(5,"in port 1");
nxtDisplayCenteredTextLine(6,"to start");

while(SensorValue(S1)==0){}

  float XX;
  float YYY;
  float J;
  float PX=0;
  float PY=20;
  float Z=3;

  float XXr;
  float YYYr;
  float PXr=0;
  float PYr=20;
  float Zr=3;
bool Pst;

float Xf=30;
float Yf=-20;
float X2=30;
float Y2=-20;
float X3=-30;
float Y3=-20;
float X4=-30;
float Y4=-20;
float XXf;
float YYf;
float XX2;
float YY2;
float XX3;
float YY3;
float XX4;
float YY4;
float Zf=2.5;
float Z2=3.5;
float Z3=3.5;
float Z4=2.5;

float Xfr=30;
float Yfr=-20;
float X2r=30;
float Y2r=-20;
float X3r=-30;
float Y3r=-20;
float X4r=-30;
float Y4r=-20;
float XXfr;
float YYfr;
float XX2r;
float YY2r;
float XX3r;
float YY3r;
float XX4r;
float YY4r;
float Zfr=2.5;
float Z2r=3.5;
float Z3r=3.5;
float Z4r=2.5;


float X5=30;
float Y5=-5;
float X6=30;
float Y6=-5;
float X7=-30;
float Y7=-5;
float X8=-30;
float Y8=-5;
float XX5;
float YY5;
float XX6;
float YY6;
float XX7;
float YY7;
float XX8;
float YY8;
float Z5=4;
float Z6=5;
float Z7=5;
float Z8=4;




while(1==1){eraseDisplay();


nxtSetPixel(-2/Z+XX,YYY);
  nxtSetPixel(2/Z+XX,YYY);
  nxtSetPixel(-1/Z+XX,1/Z+YYY);
  nxtSetPixel(1/Z+XX,1/Z+YYY);
   nxtSetPixel(XX,2/Z+YYY);
   nxtSetPixel(XX,3/Z+YYY);
  nxtSetPixel(XX,4/Z+YYY);
  nxtSetPixel(XX,5/Z+YYY);
  nxtSetPixel(-1/Z+XX,4/Z+YYY);
  nxtSetPixel(1/Z+XX,4/Z+YYY);
  nxtSetPixel(-2/Z+XX,4/Z+YYY);
  nxtSetPixel(2/Z+XX,4/Z+YYY);
  nxtSetPixel(-3/Z+XX,4/Z+YYY);
  nxtSetPixel(3/Z+XX,4/Z+YYY);
  nxtSetPixel(-1/Z+XX,5/Z+YYY);
  nxtSetPixel(1/Z+XX,5/Z+YYY);
  nxtSetPixel(-1/Z+XX,6/Z+YYY);
  nxtSetPixel(1/Z+XX,6/Z+YYY);
nxtSetPixel(-1/Z+XX,7/Z+YYY);
  nxtSetPixel(1/Z+XX,7/Z+YYY);
nxtSetPixel(XX,7/Z+YYY);

if(Zf>=0.01){if(Z2>=0.01){nxtDrawLine(XXf,YYf,XX2,YY2);}}
if(Z2>=0.01){if(Z3>=0.01){nxtDrawLine(XX2,YY2,XX3,YY3);}}
if(Z3>=0.01){if(Z4>=0.01){nxtDrawLine(XX3,YY3,XX4,YY4);}}
if(Z4>=0.01){if(Zf>=0.01){nxtDrawLine(XX4,YY4,XXf,YYf);}}

if(Z5>=0.01){if(Z6>=0.01){nxtDrawLine(XX5,YY5,XX6,YY6);}}
if(Z6>=0.01){if(Z7>=0.01){nxtDrawLine(XX6,YY6,XX7,YY7);}}
if(Z7>=0.01){if(Z8>=0.01){nxtDrawLine(XX7,YY7,XX8,YY8);}}
if(Z8>=0.01){if(Z5>=0.01){nxtDrawLine(XX8,YY8,XX5,YY5);}}






XX=PX/Z;
YYY=PY/Z;
XX=XX+50;
YYY=YYY+50;

XXf=Xf/Zf;
XXf=XXf+50;
YYf=Yf/Zf;
YYf=YYf+50;
XX2=X2/Z2;
XX2=XX2+50;
YY2=Y2/Z2;
YY2=YY2+50;
XX3=X3/Z3;
XX3=XX3+50;
YY3=Y3/Z3;
YY3=YY3+50;
XX4=X4/Z4;
XX4=XX4+50;
YY4=Y4/Z4;
YY4=YY4+50;

XX5=X5/Z5;
XX5=XX5+50;
YY5=Y5/Z5;
YY5=YY5+50;
XX6=X6/Z6;
XX6=XX6+50;
YY6=Y6/Z6;
YY6=YY6+50;
XX7=X7/Z7;
XX7=XX7+50;
YY7=Y7/Z7;
YY7=YY7+50;
XX8=X8/Z8;
XX8=XX8+50;
YY8=Y8/Z8;
YY8=YY8+50;


if(YYY<=25){Yf=Yf+1;Y2=Y2+1;Y3=Y3+1;Y4=Y4+1;Y5=Y5+1;Y6=Y6+1;Y7=Y7+1;Y8=Y8+1;PY=PY+1;}
if(YYY>=35){Yf=Yf-1;Y2=Y2-1;Y3=Y3-1;Y4=Y4-1;Y5=Y5-1;Y6=Y6-1;Y7=Y7-1;Y8=Y8-1;PY=PY-1;}
if(XX<=20){Xf=Xf+1;X2=X2+1;X3=X3+1;X4=X4+1;X5=X5+1;X6=X6+1;X7=X7+1;X8=X8+1;PX=PX+1;}
if(XX>=80){Xf=Xf-1;X2=X2-1;X3=X3-1;X4=X4-1;X5=X5-1;X6=X6-1;X7=X7-1;X8=X8-1;PX=PX-1;}
if(Z>=2){Zf=Zf-0.01;Z2=Z2-0.01;Z3=Z3-0.01;Z4=Z4-0.01;Z5=Z5-0.01;Z6=Z6-0.01;Z7=Z7-0.01;Z8=Z8-0.01;Z=Z-0.01;}
if(Z<=1){Zf=Zf+0.01;Z2=Z2+0.01;Z3=Z3+0.01;Z4=Z4+0.01;Z5=Z5+0.01;Z6=Z6+0.01;Z7=Z7+0.01;Z8=Z8+0.01;Z=Z+0.01;}



PY=PY+J;




Pst=false;
if(Z<=Z2){if(Z>=Zf){if(PX<=Xf){if(PX>=X3){if(PY<=Yf+1){if(PY>=Yf-1){Pst=true;}}}}}}
if(Z<=Z6){if(Z>=Z5){if(PX<=X5){if(PX>=X7){if(PY<=Y5+1){if(PY>=Y5-1){Pst=true;}}}}}}

if(Pst==false){J=J-0.01;}else{J=0;}

nNxtExitClicks = 5;

if(nNxtButtonPressed==2){PX=PX-1;}
if(nNxtButtonPressed==1){PX=PX+1;}
if(nNxtButtonPressed==3){Z=Z+0.01;}
if(nNxtButtonPressed==0){Z=Z-0.01;}
if(SensorValue(S1)==1){if(Pst==true){J=1;}}
wait1Msec(10);
}
}