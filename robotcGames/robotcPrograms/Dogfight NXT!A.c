#pragma config(Sensor, S1,     S1,                  sensorTouch)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float X=50;float Y=30;float XJ;float YJ;int CCC;bool cont;int An;bool DJ;bool DJA;int L1X=50;int L1Y=-40;int L2X=50;int L2Y=-20;int L3X=110;int L3Y=-30;int L4X=-10;int L4Y=-30;
float L5X=50;float L5Y=-35;bool L5D;float L6X=50;float L6Y=-25;bool L6D;float B1X=-100;float B1Y=-50;bool B1D;float spX=50;float spY;bool st;int A1r;int DA1r;int A2r;int DA2r;int A3r;int DA3r;int A4r;int DA4r;bool Dv;
float SHX;float SHY;bool SHD;bool D;float C1X=10;float C1Y;float C1XJ;float C1YJ;int C1An;bool C1DJ;bool C1DJA;bool C1st;int C1A1r;int C1A2r;int C1A3r;int C1A4r;bool C1Dv;float C1SHX;float C1SHY;bool C1SHD;bool C1D;
int HT;int C1HT;bool AAA;bool c1AAA;int lf=10;int C1lf=10;float CL1X=35;float CL1Y;bool CLN;float C2X=90;float C2Y;float C2XJ;float C2YJ;int C2An;bool C2DJ;bool C2DJA;bool C2st;int C2A1r;int C2A2r;int C2A3r;int C2A4r;bool C2Dv;float C2SHX;float C2SHY;bool C2SHD;bool C2D;            //now thats a lot of variables!!!!!!!!!!
int C2HT;bool c2AAA;int C2lf=10;float C3X=50;float C3Y;float C3XJ;float C3YJ;int C3An;bool C3DJ;bool C3DJA;bool C3st;int C3A1r;int C3A2r;int C3A3r;int C3A4r;bool C3Dv;float C3SHX;float C3SHY;bool C3SHD;bool C3D;
int C3HT;bool c3AAA;int C3lf=10;bool rsp;bool OS;int S;int XD;


void standOnLine (float LX,float LY,float YJ,float X,float Y,int w,int l)
{if(X<=LX+l&&X>=LX-l&&Y<=LY+1&&Y>=LY-1&&YJ<=0){if(w==0){st=true;}if(w==1){C1st=true;}if(w==2){C2st=true;}if(w==3){C3st=true;}}}


task main(){
  nxtDisplayStringAt(2,30,"Dogfight NXT");
wait1Msec(1000);

S=0;

while(1==1){

cont=false;

while(cont==false){
  eraseDisplay();
  nxtDisplayCenteredTextLine(0,"select arena");
  nxtDrawLine(0,56,100,56);
  nxtDrawLine(CCC,11,CCC,21);
  nxtDrawLine(CCC,11,CCC+5,16);
  nxtDrawLine(CCC,11,CCC-5,16);

  nxtDrawLine(10,0,10,10);
  nxtDrawLine(20,0,20,10);
  nxtDrawLine(30,0,30,10);
  nxtDrawLine(50,0,50,10);

XD=random(100)-50;

nxtDisplayCenteredTextLine(2,"locked");if(CCC<=10){nxtDisplayCenteredTextLine(2,"action stadium");}else{if(ccc<=20){if(S>=1){nxtDisplayCenteredTextLine(2,"tall stadium");}}else{if(S>=3&&CCC<=30){nxtDisplayCenteredTextLine(2,"push stadium");}else{if(S>=6&&CCC<=50){nxtDisplayCenteredTextLine(2,"random stadium");}}}}


if(nNxtButtonPressed==1){CCC=CCC+1;}
if(nNxtButtonPressed==2){CCC=CCC-1;}
  if(nNxtButtonPressed==3){if(ccc<=10){cont=true;}else{if(S>=1){if(ccc<=20){spX=50;spY=-75;L1X=50;L2X=50;L2Y=-40;L3X=50;L4X=50;L3Y=-90;L1Y=-60;L5Y=-20;L5X=50;L6X=50;L6Y=-25;B1Y=-115;Cl1X=50;Cl1Y=0;
  cont=true;}else{if(S>=3){if(CCC<=30){spX=50;spY=50;L1X=50;L2X=50;L2Y=-40;L3X=100;L4X=0;L3Y=-20;L4Y=-20;L1Y=-15;L5Y=-70;L5X=50;L6X=50;L6Y=-75;B1Y=0;Cl1X=50;Cl1Y=0;
  cont=true;}else{if(S>=6){if(CCC<=50){spX=random(100)-50;spY=random(100)-50;L1X=spX;L2X=random(100)-50;L1Y=spY-30;L2Y=random(100)-50;L3X=random(100)-50;L4X=random(100)-50;L3Y=random(100)-50;L4Y=random(100)-50;
  L5Y=random(100)-50;L5X=random(100)-50;L6X=random(100)-50;L6Y=random(100)-50;B1Y=random(100)-50;Cl1X=spX;Cl1Y=spY;
  cont=true;}}}}}}}}

  wait1Msec(50);
}

nxtFillRect(-1,-1,101,65);
nxtDisplayCenteredBigTextLine(3,"3");
wait1Msec(500);
nxtDisplayCenteredBigTextLine(3,"2");
wait1Msec(500);
nxtDisplayCenteredBigTextLine(3,"1");
wait1Msec(500);
nxtDisplayCenteredBigTextLine(3,"fight!");
wait1Msec(500);

cont=false;

lf=10;
C1lf=10;
C2lf=10;
C3lf=10;

HT=5;

if(SensorValue(S1)==1&&CCC<=0){C1lf=0;C2lf=0;C3lf=0;}

nNxtExitClicks=3;

while(cont==false){
  eraseDisplay();


  if(A3r>=350){An=6;YJ=0.2;}

  if(C1A3r>=350){C1YJ=0.2;C1An=6;}

  if(C2A3r>=350){C2YJ=0.2;C2An=6;}

  if(C3A3r>=350){C3YJ=0.2;C3An=6;}


  if(An==0){nxtFillRect(X+2,Y+3,X-4,Y+5);
nxtFillRect(X+2,Y+4,X+4,Y+6);
nxtFillRect(X+2,Y+3,X+2,Y);
nxtFillRect(X-4,Y+3,X-4,Y);
nxtFillRect(X-4,Y+5,X-6,Y+5);
D=true;
}
if(An==1){nxtFillRect(X-2,Y+3,X+4,Y+5);
nxtFillRect(X-2,Y+4,X-4,Y+6);
nxtFillRect(X-2,Y+3,X-2,Y);
nxtFillRect(X+4,Y+3,X+4,Y);
nxtFillRect(X+4,Y+5,X+6,Y+5);
D=false;
}
if(An==2){
nxtFillRect(X+2,Y+3,X,Y+8);
nxtFillRect(X+2,Y+7,X+4,Y+9);
nxtFillRect(X+2,Y,X+2,Y+3);
nxtFillRect(X,Y+3,X,Y);
D=true;
}
if(An==3){
nxtFillRect(X-2,Y+3,X,Y+8);
nxtFillRect(X-2,Y+7,X-4,Y+9);
nxtFillRect(X-2,Y,X-2,Y+3);
nxtFillRect(X,Y+3,X,Y);
D=false;
}
if(An==4){
nxtFillRect(X-2,Y+3,X,Y+8);
nxtFillRect(X-2,Y+7,X-4,Y+9);
nxtFillRect(X-2,Y,X-2,Y+3);
nxtFillRect(X,Y+3,X,Y);
nxtDrawLine(X+5,Y,X+7,Y+4);
nxtDrawLine(X+5,Y+8,X+7,Y+4);
D=true;
}
if(An==5){
nxtFillRect(X+2,Y+3,X,Y+8);
nxtFillRect(X+2,Y+7,X+4,Y+9);
nxtFillRect(X+2,Y,X+2,Y+3);
nxtFillRect(X,Y+3,X,Y);
nxtDrawLine(X-5,Y,X-7,Y+4);
nxtDrawLine(X-5,Y+8,X-7,Y+4);
D=false;
}
if(An==6){
nxtFillRect(X+1,Y+3,X-1,Y+8);
nxtFillRect(X+1,Y+7,X-1,Y+9);
nxtFillRect(X+1,Y,X+1,Y+3);
nxtFillRect(X-1,Y+3,X-1,Y);
nxtDrawLine(X-5,Y+10,X,Y+11);
nxtDrawLine(X+5,Y+10,X,Y+11);
}
if(An==7){
nxtFillRect(X+1,Y+3,X-1,Y+8);
nxtFillRect(X+1,Y+7,X-1,Y+9);
nxtFillRect(X+1,Y,X+1,Y+3);
nxtFillRect(X-1,Y+3,X-1,Y);
nxtDrawLine(X-5,Y-2,X,Y-3);
nxtDrawLine(X+5,Y-2,X,Y-3);
}




if(C1An==0){nxtFillRect(C1X+2,C1Y+3,C1X-4,C1Y+5);
nxtFillRect(C1X+2,C1Y+4,C1X+4,C1Y+6);
nxtFillRect(C1X+2,C1Y+3,C1X+2,C1Y);
nxtFillRect(C1X-4,C1Y+3,C1X-4,C1Y);
nxtFillRect(C1X-4,C1Y+5,C1X-6,C1Y+5);
C1D=true;
}
if(C1An==1){nxtFillRect(C1X-2,C1Y+3,C1X+4,C1Y+5);
nxtFillRect(C1X-2,C1Y+4,C1X-4,C1Y+6);
nxtFillRect(C1X-2,C1Y+3,C1X-2,C1Y);
nxtFillRect(C1X+4,C1Y+3,C1X+4,C1Y);
nxtFillRect(C1X+4,C1Y+5,C1X+6,C1Y+5);
C1D=false;
}
if(C1An==2){
nxtFillRect(C1X+2,C1Y+3,C1X,C1Y+8);
nxtFillRect(C1X+2,C1Y+7,C1X+4,C1Y+9);
nxtFillRect(C1X+2,C1Y,C1X+2,C1Y+3);
nxtFillRect(C1X,C1Y+3,C1X,C1Y);
C1D=true;
}
if(C1An==3){
nxtFillRect(C1X-2,C1Y+3,C1X,C1Y+8);
nxtFillRect(C1X-2,C1Y+7,C1X-4,C1Y+9);
nxtFillRect(C1X-2,C1Y,C1X-2,C1Y+3);
nxtFillRect(C1X,C1Y+3,C1X,C1Y);
C1D=false;
}
if(C1An==4){
nxtFillRect(C1X-2,C1Y+3,C1X,C1Y+8);
nxtFillRect(C1X-2,C1Y+7,C1X-4,C1Y+9);
nxtFillRect(C1X-2,C1Y,C1X-2,C1Y+3);
nxtFillRect(C1X,C1Y+3,C1X,C1Y);
nxtDrawLine(C1X+5,C1Y,C1X+7,C1Y+4);
nxtDrawLine(C1X+5,C1Y+8,C1X+7,C1Y+4);
C1D=true;
}
if(C1An==5){
nxtFillRect(C1X+2,C1Y+3,C1X,C1Y+8);
nxtFillRect(C1X+2,C1Y+7,C1X+4,C1Y+9);
nxtFillRect(C1X+2,C1Y,C1X+2,C1Y+3);
nxtFillRect(C1X,C1Y+3,C1X,C1Y);
nxtDrawLine(C1X-5,C1Y,C1X-7,C1Y+4);
nxtDrawLine(C1X-5,C1Y+8,C1X-7,C1Y+4);
C1D=false;
}
if(C1An==6){
nxtFillRect(C1X+1,C1Y+3,C1X-1,C1Y+8);
nxtFillRect(C1X+1,C1Y+7,C1X-1,C1Y+9);
nxtFillRect(C1X+1,C1Y,C1X+1,C1Y+3);
nxtFillRect(C1X-1,C1Y+3,C1X-1,C1Y);
nxtDrawLine(C1X-5,C1Y+10,C1X,C1Y+11);
nxtDrawLine(C1X+5,C1Y+10,C1X,C1Y+11);
}
if(C1An==7){
nxtFillRect(C1X+1,C1Y+3,C1X-1,C1Y+8);
nxtFillRect(C1X+1,C1Y+7,C1X-1,C1Y+9);
nxtFillRect(C1X+1,C1Y,C1X+1,C1Y+3);
nxtFillRect(C1X-1,C1Y+3,C1X-1,C1Y);
nxtDrawLine(C1X-5,C1Y-2,C1X,C1Y-3);
nxtDrawLine(C1X+5,C1Y-2,C1X,C1Y-3);
}



if(C2An==0){nxtFillRect(C2X+2,C2Y+3,C2X-4,C2Y+5);
nxtFillRect(C2X+2,C2Y+4,C2X+4,C2Y+6);
nxtFillRect(C2X+2,C2Y+3,C2X+2,C2Y);
nxtFillRect(C2X-4,C2Y+3,C2X-4,C2Y);
nxtFillRect(C2X-4,C2Y+5,C2X-6,C2Y+5);
C2D=true;
}
if(C2An==1){nxtFillRect(C2X-2,C2Y+3,C2X+4,C2Y+5);
nxtFillRect(C2X-2,C2Y+4,C2X-4,C2Y+6);
nxtFillRect(C2X-2,C2Y+3,C2X-2,C2Y);
nxtFillRect(C2X+4,C2Y+3,C2X+4,C2Y);
nxtFillRect(C2X+4,C2Y+5,C2X+6,C2Y+5);
C2D=false;
}
if(C2An==2){
nxtFillRect(C2X+2,C2Y+3,C2X,C2Y+8);
nxtFillRect(C2X+2,C2Y+7,C2X+4,C2Y+9);
nxtFillRect(C2X+2,C2Y,C2X+2,C2Y+3);
nxtFillRect(C2X,C2Y+3,C2X,C2Y);
C2D=true;
}
if(C2An==3){
nxtFillRect(C2X-2,C2Y+3,C2X,C2Y+8);
nxtFillRect(C2X-2,C2Y+7,C2X-4,C2Y+9);
nxtFillRect(C2X-2,C2Y,C2X-2,C2Y+3);
nxtFillRect(C2X,C2Y+3,C2X,C2Y);
C2D=false;
}
if(C2An==4){
nxtFillRect(C2X-2,C2Y+3,C2X,C2Y+8);
nxtFillRect(C2X-2,C2Y+7,C2X-4,C2Y+9);
nxtFillRect(C2X-2,C2Y,C2X-2,C2Y+3);
nxtFillRect(C2X,C2Y+3,C2X,C2Y);
nxtDrawLine(C2X+5,C2Y,C2X+7,C2Y+4);
nxtDrawLine(C2X+5,C2Y+8,C2X+7,C2Y+4);
C2D=true;
}
if(C2An==5){
nxtFillRect(C2X+2,C2Y+3,C2X,C2Y+8);
nxtFillRect(C2X+2,C2Y+7,C2X+4,C2Y+9);
nxtFillRect(C2X+2,C2Y,C2X+2,C2Y+3);
nxtFillRect(C2X,C2Y+3,C2X,C2Y);
nxtDrawLine(C2X-5,C2Y,C2X-7,C2Y+4);
nxtDrawLine(C2X-5,C2Y+8,C2X-7,C2Y+4);
C2D=false;
}
if(C2An==6){
nxtFillRect(C2X+1,C2Y+3,C2X-1,C2Y+8);
nxtFillRect(C2X+1,C2Y+7,C2X-1,C2Y+9);
nxtFillRect(C2X+1,C2Y,C2X+1,C2Y+3);
nxtFillRect(C2X-1,C2Y+3,C2X-1,C2Y);
nxtDrawLine(C2X-5,C2Y+10,C2X,C2Y+11);
nxtDrawLine(C2X+5,C2Y+10,C2X,C2Y+11);
}
if(C2An==7){
nxtFillRect(C2X+1,C2Y+3,C2X-1,C2Y+8);
nxtFillRect(C2X+1,C2Y+7,C2X-1,C2Y+9);
nxtFillRect(C2X+1,C2Y,C2X+1,C2Y+3);
nxtFillRect(C2X-1,C2Y+3,C2X-1,C2Y);
nxtDrawLine(C2X-5,C2Y-2,C2X,C2Y-3);
nxtDrawLine(C2X+5,C2Y-2,C2X,C2Y-3);
}



if(C3An==0){nxtFillRect(C3X+2,C3Y+3,C3X-4,C3Y+5);
nxtFillRect(C3X+2,C3Y+4,C3X+4,C3Y+6);
nxtFillRect(C3X+2,C3Y+3,C3X+2,C3Y);
nxtFillRect(C3X-4,C3Y+3,C3X-4,C3Y);
nxtFillRect(C3X-4,C3Y+5,C3X-6,C3Y+5);
C3D=true;
}
if(C3An==1){nxtFillRect(C3X-2,C3Y+3,C3X+4,C3Y+5);
nxtFillRect(C3X-2,C3Y+4,C3X-4,C3Y+6);
nxtFillRect(C3X-2,C3Y+3,C3X-2,C3Y);
nxtFillRect(C3X+4,C3Y+3,C3X+4,C3Y);
nxtFillRect(C3X+4,C3Y+5,C3X+6,C3Y+5);
C3D=false;
}
if(C3An==2){
nxtFillRect(C3X+2,C3Y+3,C3X,C3Y+8);
nxtFillRect(C3X+2,C3Y+7,C3X+4,C3Y+9);
nxtFillRect(C3X+2,C3Y,C3X+2,C3Y+3);
nxtFillRect(C3X,C3Y+3,C3X,C3Y);
C3D=true;
}
if(C3An==3){
nxtFillRect(C3X-2,C3Y+3,C3X,C3Y+8);
nxtFillRect(C3X-2,C3Y+7,C3X-4,C3Y+9);
nxtFillRect(C3X-2,C3Y,C3X-2,C3Y+3);
nxtFillRect(C3X,C3Y+3,C3X,C3Y);
C3D=false;
}
if(C3An==4){
nxtFillRect(C3X-2,C3Y+3,C3X,C3Y+8);
nxtFillRect(C3X-2,C3Y+7,C3X-4,C3Y+9);
nxtFillRect(C3X-2,C3Y,C3X,C3Y+3);
nxtFillRect(C3X,C3Y+3,C3X,C3Y);
nxtDrawLine(C3X+5,C3Y,C3X+7,C3Y+4);
nxtDrawLine(C3X+5,C3Y+8,C3X+7,C3Y+4);
C3D=true;
}
if(C3An==5){
nxtFillRect(C3X+2,C3Y+3,C3X,C3Y+8);
nxtFillRect(C3X+2,C3Y+7,C3X+4,C3Y+9);
nxtFillRect(C3X+2,C3Y,C3X+2,C3Y+3);
nxtFillRect(C3X,C3Y+3,C3X,C3Y);
nxtDrawLine(C3X-5,C3Y,C3X-7,C3Y+4);
nxtDrawLine(C3X-5,C3Y+8,C3X-7,C3Y+4);
C3D=false;
}
if(C3An==6){
nxtFillRect(C3X+1,C3Y+3,C3X-1,C3Y+8);
nxtFillRect(C3X+1,C3Y+7,C3X-1,C3Y+9);
nxtFillRect(C3X+1,C3Y,C3X+1,C3Y+3);
nxtFillRect(C3X-1,C3Y+3,C3X-1,C3Y);
nxtDrawLine(C3X-5,C3Y+10,C3X,C3Y+11);
nxtDrawLine(C3X+5,C3Y+10,C3X,C3Y+11);
}
if(C3An==7){
nxtFillRect(C3X+1,C3Y+3,C3X-1,C3Y+8);
nxtFillRect(C3X+1,C3Y+7,C3X-1,C3Y+9);
nxtFillRect(C3X+1,C3Y,C3X+1,C3Y+3);
nxtFillRect(C3X-1,C3Y+3,C3X-1,C3Y);
nxtDrawLine(C3X-5,C3Y-2,C3X,C3Y-3);
nxtDrawLine(C3X+5,C3Y-2,C3X,C3Y-3);
}




nxtDisplayStringAt(2,55,"%d",DA1r);
nxtDisplayStringAt(20,55,"%d",DA2r);
nxtDisplayStringAt(40,55,"%d",DA3r);
nxtDisplayStringAt(60,55,"%d",DA4r);
nxtDisplayStringAt(80,55,"%d",HT);


nxtDrawRect(L1X+20,L1Y,L1X-20,L1Y);
nxtDrawRect(L2X+10,L2Y,L2X-10,L2Y);
nxtDrawRect(L3X+10,L3Y,L3X-10,L3Y);
nxtDrawRect(L4X+10,L4Y,L4X-10,L4Y);
nxtDrawRect(L5X+10,L5Y,L5X-10,L5Y);
nxtDrawRect(L6X+15,L6Y,L6X-15,L6Y);
nxtDrawRect(B1X+5,B1Y-40,B1X-5,B1Y+40);
nxtDrawRect(spX+5,spY+5,spX-5,spY-5);
nxtDrawLine(spX+5,spY,spX-5,spY);
nxtDrawLine(spX,spY+5,spX,spY-5);
nxtDrawLine(spX+5,spY+5,spX-5,spY-5);
nxtDrawLine(spX+5,spY-5,spX-5,spY+5);
nxtFillRect(SHX+1,SHY+1,SHX-1,SHY-1);
nxtFillRect(C1SHX+1,C1SHY+1,C1SHX-1,C1SHY-1);
nxtFillRect(C2SHX+1,C2SHY+1,C2SHX-1,C2SHY-1);
nxtFillRect(C3SHX+1,C3SHY+1,C3SHX-1,C3SHY-1);


if(CLN==true){nxtDrawLine(CL1X+30,CL1Y,CL1X+29,CL1Y+5);
nxtDrawLine(CL1X+29,CL1Y+5,CL1X+20,CL1Y+6);
nxtDrawLine(CL1X+20,CL1Y+6,CL1X+19,CL1Y+10);
nxtDrawLine(CL1X+19,CL1Y+10,CL1X+12,CL1Y+10);
nxtDrawLine(CL1X+12,CL1Y+10,CL1X+11,CL1Y+6);
nxtDrawLine(CL1X+11,CL1Y+6,CL1X+6,CL1Y+5);
nxtDrawLine(CL1X+6,CL1Y+5,CL1X+6,CL1Y);
nxtDrawLine(CL1X+6,CL1Y,CL1X+30,CL1Y);CLN=false;}
else{CLN=true;}

A1r=A1r-1;
A2r=A2r-1;
A3r=A3r-1;
A4r=A4r-1;

C1A1r=C1A1r-1;
C1A2r=C1A2r-1;
C1A3r=C1A3r-1;
C1A4r=C1A4r-1;

C2A1r=C2A1r-1;
C2A2r=C2A2r-1;
C2A3r=C2A3r-1;
C2A4r=C2A4r-1;

C3A1r=C3A1r-1;
C3A2r=C3A2r-1;
C3A3r=C3A3r-1;
C3A4r=C3A4r-1;




DA1r=A1r/100;
DA2r=A2r/100;
DA3r=A3r/100;
DA4r=A4r/100;





X=X+XJ;Y=Y+YJ;
XJ=XJ*0.9;

C1X=C1X+C1XJ;C1Y=C1Y+C1YJ;
C1XJ=C1XJ*0.9;

C2X=C2X+C2XJ;C2Y=C2Y+C2YJ;
C2XJ=C2XJ*0.9;

C3X=C3X+C3XJ;C3Y=C3Y+C3YJ;
C3XJ=C3XJ*0.9;


if(A1r>=350){if(D==true){An=4;XJ=0.1;}else{An=5;XJ=-0.1;}}else{if(st==true){if(D==false){An=1;}if(D==true){An=0;}}else{if(D==false){An=3;}if(D==true){An=2;}}}

if(C1A1r>=350){if(C1D==true){C1An=4;C1XJ=0.1;}else{C1An=5;C1XJ=-0.1;}}else{if(C1st==true){if(C1D==false){C1An=1;}if(C1D==true){C1An=0;}}else{if(C1D==false){C1An=3;}if(C1D==true){C1An=2;}}}

if(C2A1r>=350){if(C2D==true){C2An=4;C2XJ=0.1;}else{C2An=5;C2XJ=-0.1;}}else{if(C2st==true){if(C2D==false){C2An=1;}if(C2D==true){C2An=0;}}else{if(C2D==false){C2An=3;}if(C2D==true){C2An=2;}}}

if(C3A1r>=350){if(C3D==true){C3An=4;C3XJ=0.1;}else{C3An=5;C3XJ=-0.1;}}else{if(C3st==true){if(C3D==false){C3An=1;}if(C3D==true){C3An=0;}}else{if(C3D==false){C3An=3;}if(C3D==true){C3An=2;}}}



if(Dv==true){An=7;YJ=-0.75;}
if(st==true){Dv=false;}

if(C1Dv==true){C1An=7;C1YJ=-0.75;}
if(C1st==true){C1Dv=false;}

if(C2Dv==true){C2An=7;C2YJ=-0.75;}
if(C2st==true){C2Dv=false;}

if(C3Dv==true){C3An=7;C3YJ=-0.75;}
if(C3st==true){C3Dv=false;}


if(AAA==true){A1r=50;AAA=false;}
if(C1AAA==true){C1A1r=50;C1AAA=false;}
if(C2AAA==true){C2A1r=50;C2AAA=false;}
if(C3AAA==true){C3A1r=50;C3AAA=false;}


if(SHD==true){SHX=SHX+0.2;}else{SHX=SHX-0.2;}

if(C1SHD==true){C1SHX=C1SHX+0.2;}else{C1SHX=C1SHX-0.2;}

if(C2SHD==true){C2SHX=C2SHX+0.2;}else{C2SHX=C2SHX-0.2;}

if(C3SHD==true){C3SHX=C3SHX+0.2;}else{C3SHX=C3SHX-0.2;}


st=false;
standOnLine (L1X,L1Y,YJ,X,Y,0,20);
standOnLine (L2X,L2Y,YJ,X,Y,0,10);
standOnLine (L3X,L3Y,YJ,X,Y,0,10);
standOnLine (L4X,L4Y,YJ,X,Y,0,10);
if(X<=L5X+10){if(X>=L5X-10){if(Y<=L5Y+1){if(Y>=L5Y-1){if(YJ<=0){st=true;if(L5D==true){X=X+0.1;}else{X=X-0.1;}}}}}}
if(X<=L6X+15){if(X>=L6X-15){if(Y<=L6Y+1){if(Y>=L6Y-1){if(YJ<=0){st=true;if(L6D==true){X=X+0.1;}else{X=X-0.1;}}}}}}
if(X<=B1X+5){if(X>=B1X-5){if(Y<=B1Y+41){if(Y>=B1Y-41){if(Y>=B1Y+38){if(YJ<=0){st=true;if(B1D==true){X=X+0.1;}else{X=X-0.1;}}}
else{if(X>=B1X){X=X+1;}else{X=X-1;}if(Y<=B1Y-40){if(YJ>=0){YJ=0;Y=Y-1;}}}}}}}


if(st==true){YJ=0;DJ=true;}else{YJ=YJ-0.005;}



C1st=false;
standOnLine (L1X,L1Y,C1YJ,C1X,C1Y,1,20);
standOnLine (L2X,L2Y,C1YJ,C1X,C1Y,1,10);
standOnLine (L3X,L3Y,C1YJ,C1X,C1Y,1,10);
standOnLine (L4X,L4Y,C1YJ,C1X,C1Y,1,10);
if(C1X<=L5X+10){if(C1X>=L5X-10){if(C1Y<=L5Y+1){if(C1Y>=L5Y-1){if(C1YJ<=0){C1st=true;if(L5D==true){C1X=C1X+0.1;}else{C1X=C1X-0.1;}}}}}}
if(C1X<=L6X+15){if(C1X>=L6X-15){if(C1Y<=L6Y+1){if(C1Y>=L6Y-1){if(C1YJ<=0){C1st=true;if(L6D==true){C1X=C1X+0.1;}else{C1X=C1X-0.1;}}}}}}
if(C1X<=B1X+5){if(C1X>=B1X-5){if(C1Y<=B1Y+41){if(C1Y>=B1Y-41){if(C1Y>=B1Y+38){if(C1YJ<=0){C1st=true;if(B1D==true){C1X=C1X+0.1;}else{C1X=C1X-0.1;}}}
else{if(C1X>=B1X){C1X=C1X+1;}else{C1X=C1X-1;}if(C1Y<=B1Y-38){if(C1YJ>=0){C1YJ=0;C1Y=C1Y-1;}}}}}}}


if(C1st==true){C1YJ=0;C1DJ=true;}else{C1YJ=C1YJ-0.005;}



C2st=false;
standOnLine (L1X,L1Y,C2YJ,C2X,C2Y,2,20);
standOnLine (L2X,L2Y,C2YJ,C2X,C2Y,2,10);
standOnLine (L3X,L3Y,C2YJ,C2X,C2Y,2,10);
standOnLine (L4X,L4Y,C2YJ,C2X,C2Y,2,10);
if(C2X<=L5X+10){if(C2X>=L5X-10){if(C2Y<=L5Y+1){if(C2Y>=L5Y-1){if(C2YJ<=0){C2st=true;if(L5D==true){C2X=C2X+0.1;}else{C2X=C2X-0.1;}}}}}}
if(C2X<=L6X+15){if(C2X>=L6X-15){if(C2Y<=L6Y+1){if(C2Y>=L6Y-1){if(C2YJ<=0){C2st=true;if(L6D==true){C2X=C2X+0.1;}else{C2X=C2X-0.1;}}}}}}
if(C2X<=B1X+5){if(C2X>=B1X-5){if(C2Y<=B1Y+41){if(C2Y>=B1Y-41){if(C2Y>=B1Y+38){if(C2YJ<=0){C2st=true;if(B1D==true){C2X=C2X+0.1;}else{C2X=C2X-0.1;}}}
else{if(C2X>=B1X){C2X=C2X+1;}else{C2X=C2X-1;}if(C2Y<=B1Y-38){if(C2YJ>=0){C2YJ=0;C2Y=C2Y-1;}}}}}}}


if(C2st==true){C2YJ=0;C2DJ=true;}else{C2YJ=C2YJ-0.005;}



C3st=false;
standOnLine (L1X,L1Y,C3YJ,C3X,C3Y,3,20);
standOnLine (L2X,L2Y,C3YJ,C3X,C3Y,3,10);
standOnLine (L3X,L3Y,C3YJ,C3X,C3Y,3,10);
standOnLine (L4X,L4Y,C3YJ,C3X,C3Y,3,10);
if(C3X<=L5X+10){if(C3X>=L5X-10){if(C3Y<=L5Y+1){if(C3Y>=L5Y-1){if(C3YJ<=0){C3st=true;if(L5D==true){C3X=C3X+0.1;}else{C3X=C3X-0.1;}}}}}}
if(C3X<=L6X+15){if(C3X>=L6X-15){if(C3Y<=L6Y+1){if(C3Y>=L6Y-1){if(C3YJ<=0){C3st=true;if(L6D==true){C3X=C3X+0.1;}else{C3X=C3X-0.1;}}}}}}
if(C3X<=B1X+5){if(C3X>=B1X-5){if(C3Y<=B1Y+41){if(C3Y>=B1Y-41){if(C3Y>=B1Y+38){if(C3YJ<=0){C3st=true;if(B1D==true){C3X=C3X+0.1;}else{C3X=C3X-0.1;}}}
else{if(C3X>=B1X){C3X=C3X+1;}else{C3X=C3X-1;}if(C3Y<=B1Y-38){if(C3YJ>=0){C3YJ=0;C3Y=C3Y-1;}}}}}}}


if(C3st==true){C3YJ=0;C3DJ=true;}else{C3YJ=C3YJ-0.005;}




if(A1r>=350){if(C1Dv==false){if(D==true){if(C1Y<=Y+7){if(C1Y>=Y-7){if(C1X<=X+9){if(C1X>=X-1){C1XJ=5;C1YJ=0.5;C1HT=C1HT-1;C1AAA=true;}}}}}
else{if(C1Y>=Y-7){if(C1Y<=Y+7){if(C1X>=X-9){if(C1X<=X+1){C1XJ=-5;C1YJ=0.5;C1A1r=350;C1HT=C1HT-1;C1A1r=348;}}}}}}}

if(A1r>=350){if(C2Dv==false){if(D==true){if(C2Y<=Y+7){if(C2Y>=Y-7){if(C2X<=X+9){if(C2X>=X-1){C2XJ=5;C2YJ=0.5;C2HT=C2HT-1;C2AAA=true;}}}}}
else{if(C2Y>=Y-7){if(C2Y<=Y+7){if(C2X>=X-9){if(C2X<=X+1){C2XJ=-5;C2YJ=0.5;C2A1r=350;C2HT=C2HT-1;C2A1r=348;}}}}}}}

if(A1r>=350){if(C3Dv==false){if(D==true){if(C3Y<=Y+7){if(C3Y>=Y-7){if(C3X<=X+9){if(C3X>=X-1){C3XJ=5;C3YJ=0.5;C3HT=C3HT-1;C3AAA=true;}}}}}
else{if(C3Y>=Y-7){if(C3Y<=Y+7){if(C3X>=X-9){if(C3X<=X+1){C3XJ=-5;C3YJ=0.5;C3A1r=350;C3HT=C3HT-1;C3A1r=348;}}}}}}}

if(C1A1r>=350){if(Dv==false){if(C1D==true){if(Y<=C1Y+7){if(Y>=C1Y-7){if(X<=C1X+9){if(X>=C1X-1){XJ=5;YJ=0.5;HT=HT-1;AAA=true;C1A1r=50;}}}}}
else{if(Y>=C1Y-7){if(Y<=C1Y+7){if(X>=C1X-9){if(X<=C1X+1){XJ=-5;YJ=0.5;HT=HT-1;A1r=50;}}}}}}}

if(C2A1r>=350){if(Dv==false){if(C2D==true){if(Y<=C2Y+7){if(Y>=C2Y-7){if(X<=C2X+9){if(X>=C2X-1){XJ=5;YJ=0.5;HT=HT-1;AAA=true;C2A1r=50;}}}}}
else{if(Y>=C2Y-7){if(Y<=C2Y+7){if(X>=C2X-9){if(X<=C2X+1){XJ=-5;YJ=0.5;HT=HT-1;A1r=50;}}}}}}}

if(C3A1r>=350){if(Dv==false){if(C3D==true){if(Y<=C3Y+7){if(Y>=C3Y-7){if(X<=C3X+9){if(X>=C3X-1){XJ=5;YJ=0.5;HT=HT-1;AAA=true;C3A1r=50;}}}}}
else{if(Y>=C3Y-7){if(Y<=C3Y+7){if(X>=C3X-9){if(X<=C3X+1){XJ=-5;YJ=0.5;HT=HT-1;A1r=50;}}}}}}}




if(C1Dv==false){if(C1X<=SHX+6){if(C1X>=SHX-6){if(C1Y+4<=SHY+6){if(C1Y+4>=SHY-6){if(C1X>=SHX){C1XJ=6;C1YJ=0.5;SHY=-555;C1HT=C1HT-1;}else{C1XJ=-6;C1YJ=0.5;SHY=-555;C1HT=C1HT-1;C1A1r=348;}}}}}}

if(C2Dv==false){if(C2X<=SHX+6){if(C2X>=SHX-6){if(C2Y+4<=SHY+6){if(C2Y+4>=SHY-6){if(C2X>=SHX){C2XJ=6;C2YJ=0.5;SHY=-555;C2HT=C2HT-1;}else{C2XJ=-6;C2YJ=0.5;SHY=-555;C2HT=C2HT-1;C2A1r=348;}}}}}}

if(C3Dv==false){if(C3X<=SHX+6){if(C3X>=SHX-6){if(C3Y+4<=SHY+6){if(C3Y+4>=SHY-6){if(C3X>=SHX){C3XJ=6;C3YJ=0.5;SHY=-555;C3HT=C3HT-1;}else{C3XJ=-6;C3YJ=0.5;SHY=-555;C3HT=C3HT-1;C3A1r=348;}}}}}}

if(Dv==false){if(X<=C1SHX+6){if(X>=C1SHX-6){if(Y+4<=C1SHY+6){if(Y+4>=C1SHY-6){if(X>=C1SHX){XJ=6;YJ=0.5;C1SHY=-555;HT=HT-1;}else{XJ=-6;YJ=0.5;C1SHY=-555;HT=HT-1;A1r=348;}}}}}}

if(Dv==false){if(X<=C2SHX+6){if(X>=C2SHX-6){if(Y+4<=C2SHY+6){if(Y+4>=C2SHY-6){if(X>=C2SHX){XJ=6;YJ=0.5;C2SHY=-555;HT=HT-1;}else{XJ=-6;YJ=0.5;C2SHY=-555;HT=HT-1;A1r=348;}}}}}}

if(Dv==false){if(X<=C3SHX+6){if(X>=C3SHX-6){if(Y+4<=C3SHY+6){if(Y+4>=C3SHY-6){if(X>=C3SHX){XJ=6;YJ=0.5;C3SHY=-555;HT=HT-1;}else{XJ=-6;YJ=0.5;C3SHY=-555;HT=HT-1;A1r=348;}}}}}}



if(A3r>=350){if(C1Dv==false){if(C1X<=X+6){if(C1X>=X-6){if(C1Y<=Y+6){if(C1Y>=Y-1){if(C1X>=X){C1XJ=5;C1YJ=0.5;C1AAA=true;C1HT=C1HT-1;}else{C1XJ=-5;C1YJ=0.5;C1AAA=true;C1HT=C1HT-1;}}}}}}}

if(A3r>=350){if(C2Dv==false){if(C2X<=X+6){if(C2X>=X-6){if(C2Y<=Y+6){if(C2Y>=Y-1){if(C2X>=X){C2XJ=5;C2YJ=0.5;C2AAA=true;C2HT=C2HT-1;}else{C2XJ=-5;C2YJ=0.5;C2AAA=true;C2HT=C2HT-1;}}}}}}}

if(A3r>=350){if(C3Dv==false){if(C3X<=X+6){if(C3X>=X-6){if(C3Y<=Y+6){if(C3Y>=Y-1){if(C3X>=X){C3XJ=5;C3YJ=0.5;C3AAA=true;C3HT=C3HT-1;}else{C3XJ=-5;C3YJ=0.5;C3AAA=true;C3HT=C3HT-1;}}}}}}}

if(C1A3r>=350){if(Dv==false){if(X<=C1X+6){if(X>=C1X-6){if(Y<=C1Y+6){if(Y>=C1Y-1){if(X>=C1X){XJ=5;YJ=0.5;AAA=true;HT=HT-1;}else{XJ=-5;YJ=0.5;AAA=true;HT=HT-1;}}}}}}}

if(C2A3r>=350){if(Dv==false){if(X<=C2X+6){if(X>=C2X-6){if(Y<=C2Y+6){if(Y>=C2Y-1){if(X>=C2X){XJ=5;YJ=0.5;AAA=true;HT=HT-1;}else{XJ=-5;YJ=0.5;AAA=true;HT=HT-1;}}}}}}}

if(C3A3r>=350){if(Dv==false){if(X<=C3X+6){if(X>=C3X-6){if(Y<=C3Y+6){if(Y>=C3Y-1){if(X>=C3X){XJ=5;YJ=0.5;AAA=true;HT=HT-1;}else{XJ=-5;YJ=0.5;AAA=true;HT=HT-1;}}}}}}}



if(Dv==true){if(C1X<=X+6){if(C1X>=X-6){if(C1Y<=Y+1){if(C1Y>=Y-6){if(C1X>=X){C1XJ=5;C1YJ=0.5;C1HT=C1HT-1;C1AAA=true;}else{C1XJ=-5;C1YJ=0.5;C1HT=C1HT-1;C1AAA=true;}}}}}}

if(Dv==true){if(C2X<=X+6){if(C2X>=X-6){if(C2Y<=Y+1){if(C2Y>=Y-6){if(C2X>=X){C2XJ=5;C2YJ=0.5;C2HT=C2HT-1;C2AAA=true;}else{C2XJ=-5;C2YJ=0.5;C2HT=C2HT-1;C2AAA=true;}}}}}}

if(Dv==true){if(C3X<=X+6){if(C3X>=X-6){if(C3Y<=Y+1){if(C3Y>=Y-6){if(C3X>=X){C3XJ=5;C3YJ=0.5;C3HT=C3HT-1;C3AAA=true;}else{C3XJ=-5;C3YJ=0.5;C3HT=C3HT-1;C3AAA=true;}}}}}}

if(C1Dv==true){if(X<=C1X+6){if(X>=C1X-6){if(Y<=C1Y+1){if(Y>=C1Y-6){if(X>=C1X){XJ=5;YJ=0.5;HT=HT-1;AAA=true;}else{XJ=-5;YJ=0.5;HT=HT-1;AAA=true;}}}}}}

if(C2Dv==true){if(X<=C2X+6){if(X>=C2X-6){if(Y<=C2Y+1){if(Y>=C2Y-6){if(X>=C2X){XJ=5;YJ=0.5;HT=HT-1;AAA=true;}else{XJ=-5;YJ=0.5;HT=HT-1;AAA=true;}}}}}}

if(C3Dv==true){if(X<=C3X+6){if(X>=C3X-6){if(Y<=C3Y+1){if(Y>=C3Y-6){if(X>=C3X){XJ=5;YJ=0.5;HT=HT-1;AAA=true;}else{XJ=-5;YJ=0.5;HT=HT-1;AAA=true;}}}}}}




if(lf<=0){nxtDisplayCenteredBigTextLine(3,"You Lose!");wait1Msec(10000);cont=true;}
if(C1lf<=0){if(C2lf<=0){if(C3lf<=0){nxtDisplayCenteredBigTextLine(3,"You Win!");nxtDisplayTextLine(6,"continuing");nxtDisplayTextLine(7,"in 5");wait1Msec(1000);nxtDisplayTextLine(7,"in 4");wait1Msec(1000);nxtDisplayTextLine(7,"in 3");wait1Msec(1000);
nxtDisplayTextLine(7,"in 2");wait1Msec(1000);nxtDisplayTextLine(7,"in 1");wait1Msec(1000);if(CCC>=10){S=S+2;if(CCC>=20){S=S+1;}}else{S=S+1;}cont=true;}}}
if(C1lf<=0){C1Y=spy+500;}
if(C2lf<=0){C2Y=spy+500;}
if(C3lf<=0){C3Y=spy+500;}



if(A1r<=0){A1r=0;}
if(A2r<=0){A2r=0;}
if(A3r<=0){A3r=0;}
if(A4r<=0){A4r=0;}

if(C1A1r<=0){C1A1r=0;}
if(C1A2r<=0){C1A2r=0;}
if(C1A3r<=0){C1A3r=0;}
if(C1A4r<=0){C1A4r=0;}

if(C2A1r<=0){C2A1r=0;}
if(C2A2r<=0){C2A2r=0;}
if(C2A3r<=0){C2A3r=0;}
if(C2A4r<=0){C2A4r=0;}

if(C3A1r<=0){C3A1r=0;}
if(C3A2r<=0){C3A2r=0;}
if(C3A3r<=0){C3A3r=0;}
if(C3A4r<=0){C3A4r=0;}



rsp=false;
if(Y<=-10){X=spX;Y=spY;XJ=0;YJ=0;HT=5;lf=lf-1;if(lf>=1){rsp=true;}}if(Y>=64){X=spX;Y=spY;XJ=0;YJ=0;HT=5;}
if(Y<=spY-300){X=spX;Y=spY;XJ=0;YJ=0;HT=5;lf=lf-1;if(lf>=1){rsp=true;}}
if(HT<=0){X=spX;Y=spY;XJ=0;YJ=0;HT=5;lf=lf-1;if(lf>=1){rsp=true;}}

if(rsp==true){eraseDisplay();nxtDisplayStringAt(2,55,"you died");nxtDisplayStringAt(1,35,"lives remaining");nxtDisplayStringAt(93,35,"%d",lf);OS=false;while(YJ!=0.123){OS=true;
if(X>=55){OS=false;X=X-1;L1X=L1X-1;L2X=L2X-1;L3X=L3X-1;L4X=L4X-1;L5X=L5X-1;L6X=L6X-1;B1X=B1X-1;spX=spX-1;SHX=SHX-1;C1X=C1X-1;C1SHX=C1SHX-1;CL1X=CL1X-0.5;C2X=C2X-1;
C2SHX=C2SHX-1;C3X=C3X-1;C3SHX=C3SHX-1;}
if(X<=45){OS=false;X=X+1;L1X=L1X+1;L2X=L2X+1;L3X=L3X+1;L4X=L4X+1;L5X=L5X+1;L6X=L6X+1;B1X=B1X+1;spX=spX+1;SHX=SHX+1;C1X=C1X+1;C1SHX=C1SHX+1;CL1X=CL1X+0.5;C2X=C2X+1;
C2SHX=C2SHX+1;C3X=C3X+1;C3SHX=C3SHX+1;}
if(Y>=35){OS=false;Y=Y-1;L1Y=L1Y-1;L2Y=L2Y-1;L3Y=L3Y-1;L4Y=L4Y-1;L5Y=L5Y-1;L6Y=L6Y-1;B1Y=B1Y-1;spY=spY-1;SHY=SHY-1;C1Y=C1Y-1;C1SHY=C1SHY-1;CL1Y=CL1Y-0.5;C2Y=C2Y-1;
C2SHY=C2SHY-1;C3Y=C3Y-1;C3SHY=C3SHY-1;}
if(Y<=25){OS=false;Y=Y+1;L1Y=L1Y+1;L2Y=L2Y+1;L3Y=L3Y+1;L4Y=L4Y+1;L5Y=L5Y+1;L6Y=L6Y+1;B1Y=B1Y+1;spY=spY+1;SHY=SHY+1;C1Y=C1Y+1;C1SHY=C1SHY+1;CL1Y=CL1Y+0.5;C2Y=C2Y+1;
C2SHY=C2SHY+1;C3Y=C3Y+1;C3SHY=C3SHY+1;}if(OS==true){YJ=0.123;}}
nxtDisplayStringAt(2,15,"respawning in 5");wait1Msec(1000);nxtDisplayStringAt(2,15,"respawning in 4");wait1Msec(1000);nxtDisplayStringAt(2,15,"respawning in 3");wait1Msec(1000);nxtDisplayStringAt(2,15,"respawning in 2");wait1Msec(1000);nxtDisplayStringAt(2,15,"respawning in 1");wait1Msec(1000);}


if(C1Y<=spY-200){C1X=spX;C1Y=spY;C1XJ=0;C1YJ=0;C1HT=5;C1lf=C1lf-1;}
if(C1HT<=0){C1X=spX;C1Y=spY;C1XJ=0;C1YJ=0;C1HT=5;C1lf=C1lf-1;}

if(C2Y<=spY-200){C2X=spX;C2Y=spY;C2XJ=0;C2YJ=0;C2HT=5;C2lf=C2lf-1;}
if(C2HT<=0){C2X=spX;C2Y=spY;C2XJ=0;C2YJ=0;C2HT=5;C2lf=C2lf-1;}

if(C3Y<=spY-200){C3X=spX;C3Y=spY;C3XJ=0;C3YJ=0;C3HT=5;C3lf=C3lf-1;}
if(C3HT<=0){C3X=spX;C3Y=spY;C3XJ=0;C3YJ=0;C3HT=5;C3lf=C3lf-1;}


if(C1A1r<=350){if(C1Dv==false){if(Y<=spY-70){if(C1A3r<=0){C1A3r=500;}}}}

if(C2A1r<=350){if(C2Dv==false){if(Y<=spY-70){if(C2A3r<=0){C2A3r=500;}}}}

if(C3A1r<=350){if(C3Dv==false){if(Y<=spY-70){if(C3A3r<=0){C3A3r=500;}}}}


if(L5D==true){L5X=L5X+0.1;}else{L5X=L5X-0.1;}
if(L6D==true){L6X=L6X+0.1;}else{L6X=L6X-0.1;}
if(B1D==true){B1X=B1X+0.1;}else{B1X=B1X-0.1;}

if(L5X<=L4X){L5D=true;}
if(L5X>=L3X){L5D=false;}
if(L6X<=L4X-30){L6D=true;}
if(L6X>=L3X+30){L6D=false;}
if(B1X<=L4X-50){B1D=true;}
if(B1X>=L3X+50){B1D=false;}


if(X>=55){X=X-1;L1X=L1X-1;L2X=L2X-1;L3X=L3X-1;L4X=L4X-1;L5X=L5X-1;L6X=L6X-1;B1X=B1X-1;spX=spX-1;SHX=SHX-1;C1X=C1X-1;C1SHX=C1SHX-1;CL1X=CL1X-0.5;C2X=C2X-1;C2SHX=C2SHX-1;
C3X=C3X-1;C3SHX=C3SHX-1;}
if(X<=45){X=X+1;L1X=L1X+1;L2X=L2X+1;L3X=L3X+1;L4X=L4X+1;L5X=L5X+1;L6X=L6X+1;B1X=B1X+1;spX=spX+1;SHX=SHX+1;C1X=C1X+1;C1SHX=C1SHX+1;CL1X=CL1X+0.5;C2X=C2X+1;C2SHX=C2SHX+1;
C3X=C3X+1;C3SHX=C3SHX+1;}
if(Y>=35){Y=Y-1;L1Y=L1Y-1;L2Y=L2Y-1;L3Y=L3Y-1;L4Y=L4Y-1;L5Y=L5Y-1;L6Y=L6Y-1;B1Y=B1Y-1;spY=spY-1;SHY=SHY-1;C1Y=C1Y-1;C1SHY=C1SHY-1;CL1Y=CL1Y-0.5;C2Y=C2Y-1;C2SHY=C2SHY-1;
C3Y=C3Y-1;C3SHY=C3SHY-1;}
if(Y<=25){Y=Y+1;L1Y=L1Y+1;L2Y=L2Y+1;L3Y=L3Y+1;L4Y=L4Y+1;L5Y=L5Y+1;L6Y=L6Y+1;B1Y=B1Y+1;spY=spY+1;SHY=SHY+1;C1Y=C1Y+1;C1SHY=C1SHY+1;CL1Y=CL1Y+0.5;C2Y=C2Y+1;C2SHY=C2SHY+1;
C3Y=C3Y+1;C3SHY=C3SHY+1;}




if(A1r<=350){if(Dv==false){
if(nNxtButtonPressed==1){XJ=XJ+0.025;if(st==true){An=0;}else{An=2;}}
if(nNxtButtonPressed==2){XJ=XJ-0.025;if(st==true){An=1;}else{An=3;}}
if(nNxtButtonPressed==3){if(st==true){YJ=0.5;}else{if(An==0){An=2;}if(An==1){An=3;}}if(DJ==true){if(YJ<=0.3){if(DJA==true){DJ=false;YJ=0.5;}}}DJA=false;}else{DJA=true;}
if(SensorValue(S1)==1){if(nNxtButtonPressed==0){if(A4r<=0){A4r=500;DV=true;}}if(nNxtButtonPressed>=1){if(nNxtButtonPressed!=3){if(A1r<=0){if(D==true){A1r=500;YJ=0;}else{A1r=500;YJ=0;}}}else{if(st==false){if(A3r<=0){A3r=500;}}}}
else{if(A2r<=0){if(Dv==false){SHX=X;SHY=Y+4;SHD=D;A2r=500;}}}}
}}


if(C1A1r<=350){if(C1Dv==false){if(Y>=spY-125){
if(X>=C1X){C1XJ=C1XJ+0.025;if(C1st==true){C1An=0;}else{C1An=2;}}
if(X<=C1X){C1XJ=C1XJ-0.025;if(C1st==true){C1An=1;}else{C1An=3;}}
if(Y>=C1Y-2){if(C1st==true){C1YJ=0.5;}else{if(C1An==0){C1An=2;}if(C1An==1){C1An=3;}}if(C1DJ==true){if(C1YJ<=0.3){if(C1DJA==true){C1DJ=false;C1YJ=0.5;}}}C1DJA=false;}else{C1DJA=true;}
if(X<=C1X+50){if(X>=C1X-50){if(Y>=C1X-50){if(Y<=C1X+50){if(C1Y>=Y+5){if(X<=C1X+10){if(X>=C1X-10){if(C1A4r<=0){C1A4r=500;C1DV=true;}}}}
if(C1Y<=Y+5){if(C1Y>=Y-3){if(C1A1r<=0){if(C1D==true){C1A1r=500;C1YJ=0;}
else{C1A1r=500;C1YJ=0;}}}else{if(C1st==false){if(C1A3r<=0){C1A3r=500;}}}}
}}}}if(Y<=C1Y+5){if(Y>=C1Y-5){if(C1A2r<=0){if(C1Dv==false){C1SHX=C1X;C1SHY=C1Y+4;C1SHD=C1D;C1A2r=500;}}}}}
}}

if(C2A1r<=350){if(C2Dv==false){if(Y>=spY-125){
if(X>=C2X){C2XJ=C2XJ+0.025;if(C2st==true){C2An=0;}else{C2An=2;}}
if(X<=C2X){C2XJ=C2XJ-0.025;if(C2st==true){C2An=1;}else{C2An=3;}}
if(Y>=C2Y-2){if(C2st==true){C2YJ=0.5;}else{if(C2An==0){C2An=2;}if(C2An==1){C2An=3;}}if(C2DJ==true){if(C2YJ<=0.3){if(C2DJA==true){C2DJ=false;C2YJ=0.5;}}}C2DJA=false;}else{C2DJA=true;}
if(X<=C2X+50){if(X>=C2X-50){if(Y>=C2X-50){if(Y<=C2X+50){if(C2Y>=Y+5){if(X<=C2X+10){if(X>=C2X-10){if(C2A4r<=0){C2A4r=500;C2DV=true;}}}}
if(C2Y<=Y+5){if(C2Y>=Y-3){if(C2A1r<=0){if(C2D==true){C2A1r=500;C2YJ=0;}
else{C2A1r=500;C2YJ=0;}}}else{if(C2st==false){if(C2A3r<=0){C2A3r=500;}}}}
}}}}if(Y<=C2Y+5){if(Y>=C2Y-5){if(C2A2r<=0){if(C2Dv==false){C2SHX=C2X;C2SHY=C2Y+4;C2SHD=C2D;C2A2r=500;}}}}}
}}

if(C3A1r<=350){if(C3Dv==false){if(Y>=spY-125){
if(X>=C3X){C3XJ=C3XJ+0.025;if(C3st==true){C3An=0;}else{C3An=2;}}
if(X<=C3X){C3XJ=C3XJ-0.025;if(C3st==true){C3An=1;}else{C3An=3;}}
if(Y>=C3Y-2){if(C3st==true){C3YJ=0.5;}else{if(C3An==0){C3An=2;}if(C3An==1){C3An=3;}}if(C3DJ==true){if(C3YJ<=0.3){if(C3DJA==true){C3DJ=false;C3YJ=0.5;}}}C3DJA=false;}else{C3DJA=true;}
if(X<=C3X+50){if(X>=C3X-50){if(Y>=C3X-50){if(Y<=C3X+50){if(C3Y>=Y+5){if(X<=C3X+10){if(X>=C3X-10){if(C3A4r<=0){C3A4r=500;C3DV=true;}}}}
if(C3Y<=Y+5){if(C3Y>=Y-3){if(C3A1r<=0){if(C3D==true){C3A1r=500;C3YJ=0;}
else{C3A1r=500;C3YJ=0;}}}else{if(C3st==false){if(C3A3r<=0){C3A3r=500;}}}}
}}}}if(Y<=C3Y+5){if(Y>=C3Y-5){if(C3A2r<=0){if(C3Dv==false){C3SHX=C3X;C3SHY=C3Y+4;C3SHD=C3D;C3A2r=500;}}}}}
}}





wait1Msec(5);
}
}
}
