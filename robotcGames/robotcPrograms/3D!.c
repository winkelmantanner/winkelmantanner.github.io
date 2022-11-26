#include "JoystickDriver.c"
task main(){bool DDDDD;     int WWW;     float XD;
    float XX;
  float YY;
  float XX2;
  float YY2;
  float XX3;
  float YY3;
  float XX4;
  float YY4;
  float Xf;
  float Y;
  float Z;
    float X2;
  float Y2;
  float Z2;
      float X3;
  float Y3;
  float Z3;
      float X4;
  float Y4;
  float Z4;


  int Up;
int Down;

  Z = -5;

  Xf = 30;
  Y = 50;

  X2 = -30;
  Y2 = 50;
  Z2 = -5;
  X3 = -30;
  Y3 = 50;
  Z3 = -6;
  X4 = 30;
  Y4 = 50;
  Z4 = -6;

  while (1==1){eraseDisplay();getJoystickSettings(joystick);  Up = joystick.joy1_y1;
  Down =  joystick.joy1_x1;

    if(Z>=0) {XX = Xf*Z+50;
    YY = Y*Z+32;}else
    {YY = Y/Z+32;
      XX = Xf/Z+50;}
       if(Z2>=0) {XX2 = X2*Z2+50;
    YY2 = Y2*Z2+32;}else
    {YY2 = Y2/Z2+32;
      XX2 = X2/Z2+50;}
    if(Z3>=0) {XX3 = X3*Z3+50;
    YY3 = Y3*Z3+32;}else
    {YY3 = Y3/Z3+32;
      XX3 = X3/Z3+50;}
       if(Z4>=0) {XX4 = X4*Z4+50;
    YY4 = Y4*Z4+32;}else
    {YY4 = Y4/Z4+32;
      XX4 = X4/Z4+50;}
  if(Z<=0.0){if(Z2<=0.0){if(joy1btn(5)==1){Xf=Xf+XD;XD=XD+1;}nxtDrawLine(XX,YY,XX2,YY2);}}
  if(Z2<=0.0){if(Z3<=0.0){nxtDrawLine(XX2,YY2,XX3,YY3);}}
  if(Z3<=0.0){if(Z4<=0.0){nxtDrawLine(XX3,YY3,XX4,YY4);}}
  if(Z4<=0.0){if(Z<=0.0){nxtDrawLine(XX4,YY4,XX,YY);}}



    wait1Msec(8);

//   if(Up == -127){Z=Z+0.005;
//       Z2=Z2+0.005;
//   Z3=Z3+0.005;
//        Z4=Z4+0.005;  }
//    if(Up == 127){Z=Z-0.005;
//       Z2=Z2-0.005;
//   Z3=Z3-0.005;
//        Z4=Z4-0.005;  }
//        if(Down == -127){Xf=Xf+1;
//      X2=X2+1;X3=X3+1;X4=X4+1;}
//       if(Down == 127){Xf=Xf-1;
//      X2=X2-1;X3=X3-1;X4=X4-1;}
//   if(joy1Btn(9) == 1){DDDDD=true;}if(joy1Btn(10)==1){DDDDD=false;}
//      if(DDDDD==true){
//      if(joy1Btn(1) == 1){Y=Y+1;}
//  if(joy1Btn(2) == 1){Y2=Y2+1;}
//     if(joy1Btn(3)==1){Y3=Y3+1;}
//     if(joy1Btn(4)==1){Y4=Y4+1;}
//   }else{if(joy1Btn(1) == 1){Y=Y-1;}
//  if(joy1Btn(2) == 1){Y2=Y2-1;}
//     if(joy1Btn(3)==1){Y3=Y3-1;}
//     if(joy1Btn(4)==1){Y4=Y4-1;}}
     if(joy1Btn(5)==1){WWW=8;}
     if(joy1Btn(6)==1){WWW=7;}
     if(joy1Btn(7)==1){WWW=6;}
     if(joy1Btn(8)==1){WWW=5;}
     if(joy1Btn(9)==1){WWW=10;}
     if(joy1Btn(10)==1){WWW=9;}

     if(WWW==5){
     if(joy1Btn(1)==1){Xf=Xf-1;}
     if(joy1Btn(2)==1){X2=X2-1;}
     if(joy1Btn(3)==1){X3=X3-1;}
     if(joy1Btn(4)==1){X4=X4-1;}}
     if(WWW==6){
     if(joy1Btn(1)==1){Z=Z-0.01;}
     if(joy1Btn(2)==1){Z2=Z2-0.01;}
     if(joy1Btn(3)==1){Z3=Z3-0.01;}
     if(joy1Btn(4)==1){Z4=Z4-0.01;}}
     if(WWW==7){
     if(joy1Btn(1)==1){Z=Z+0.01;}
     if(joy1Btn(2)==1){Z2=Z2+0.01;}
     if(joy1Btn(3)==1){Z3=Z3+0.01;}
     if(joy1Btn(4)==1){Z4=Z4+0.01;}}
     if(WWW==8){
     if(joy1Btn(1)==1){Xf=Xf+1;}
     if(joy1Btn(2)==1){X2=X2+1;}
     if(joy1Btn(3)==1){X3=X3+1;}
     if(joy1Btn(4)==1){X4=X4+1;}}
     if(WWW==9){
     if(joy1Btn(1)==1){Y=Y-1;}
     if(joy1Btn(2)==1){Y2=Y2-1;}
     if(joy1Btn(3)==1){Y3=Y3-1;}
     if(joy1Btn(4)==1){Y4=Y4-1;}}
     if(WWW==10){
     if(joy1Btn(1)==1){Y=Y+1;}
     if(joy1Btn(2)==1){Y2=Y2+1;}
     if(joy1Btn(3)==1){Y3=Y3+1;}
     if(joy1Btn(4)==1){Y4=Y4+1;}}


     if(joy1btn(5)==1){XX=XX+1;}


     if(Down == -127){Xf=Xf+1;X2=X2+1;X3=X3+1;X4=X4+1;}
     if(Down == 127){Xf=Xf-1;X2=X2-1;X3=X3-1;X4=X4-1;}
     if(Up == 127){Z=Z-0.01;Z2=Z2-0.01;Z3=Z3-0.01;Z4=Z4-0.01;}
     if(Up == -127){Z=Z+0.01;Z2=Z2+0.01;Z3=Z3+0.01;Z4=Z4+0.01;}


   }































}
