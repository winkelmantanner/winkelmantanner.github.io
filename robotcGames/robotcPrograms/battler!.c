#include "JoystickDriver.c"
task main(){float XX;float YYY;float XX2=50;float YYY2;float J;float JJ;float J2;float JJ2;int Up;int Down;int o;float XX3=50;float YYY3;;float J3;float JJ3;;;int o2;float XX4=50;float YYY4;;float J4;float JJ4;;;int o3;float XX5=50;float YYY5;;float J5;float JJ5;;;int o4;int score;int b1;int Dd;
int Bd;int BX; int BY;int Bc;int Bcc;int PX;int PY;int PD;int PDD;bool a3a;int b3b;bool AD;int Ac;bool Acc;
while(1==1){ getJoystickSettings(joystick);  Up = joystick.joy1_y1;
  Down =  joystick.joy1_x1;
  eraseDisplay();

  nxtDisplayStringAt(3,55,"%d",score);

  if(a3a==true){if(Dd==0){AD=false;}else{AD=true} if(AD==true){nxtDrawLine(XX+3,YYY,XX+8,YYY+7);nxtDrawLine(XX+3,YYY+7,XX+8,YYY);}
if(AD==false){nxtDrawLine(XX-3,YYY,XX-8,YYY+7);nxtDrawLine(XX-3,YYY+7,XX-8,YYY);}}//////////////////

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


   nxtSetPixel(XX2+2,YYY2);
  nxtSetPixel(XX2-2,YYY2);
  nxtSetPixel(XX2+1,YYY2+1);
  nxtSetPixel(XX2-1,YYY2+1);
   nxtSetPixel(XX2,YYY2+2);
   nxtSetPixel(XX2,YYY2+3);
  nxtSetPixel(XX2,YYY2+4);
  nxtSetPixel(XX2,YYY2+5);
  nxtSetPixel(XX2+1,YYY2+4);
  nxtSetPixel(XX2-1,YYY2+4);
  nxtSetPixel(XX2+2,YYY2+4);
  nxtSetPixel(XX2-2,YYY2+4);
  nxtSetPixel(XX2+3,YYY2+4);
  nxtSetPixel(XX2-3,YYY2+4);
  nxtSetPixel(XX2+1,YYY2+5);
  nxtSetPixel(XX2-1,YYY2+5);
  nxtSetPixel(XX2+1,YYY2+6);
  nxtSetPixel(XX2-1,YYY2+6);
nxtSetPixel(XX2+1,YYY2+7);
  nxtSetPixel(XX2-1,YYY2+7);
nxtSetPixel(XX2,YYY2+7);

   nxtSetPixel(XX3+2,YYY3);
  nxtSetPixel(XX3-2,YYY3);
  nxtSetPixel(XX3+1,YYY3+1);
  nxtSetPixel(XX3-1,YYY3+1);
   nxtSetPixel(XX3,YYY3+2);
   nxtSetPixel(XX3,YYY3+3);
  nxtSetPixel(XX3,YYY3+4);
  nxtSetPixel(XX3,YYY3+5);
  nxtSetPixel(XX3+1,YYY3+4);
  nxtSetPixel(XX3-1,YYY3+4);
  nxtSetPixel(XX3+2,YYY3+4);
  nxtSetPixel(XX3-2,YYY3+4);
  nxtSetPixel(XX3+3,YYY3+4);
  nxtSetPixel(XX3-3,YYY3+4);
  nxtSetPixel(XX3+1,YYY3+5);
  nxtSetPixel(XX3-1,YYY3+5);
  nxtSetPixel(XX3+1,YYY3+6);
  nxtSetPixel(XX3-1,YYY3+6);
nxtSetPixel(XX3+1,YYY3+7);
  nxtSetPixel(XX3-1,YYY3+7);
nxtSetPixel(XX3,YYY3+7);


nxtSetPixel(XX4+2,YYY4);
  nxtSetPixel(XX4-2,YYY4);
  nxtSetPixel(XX4+1,YYY4+1);
  nxtSetPixel(XX4-1,YYY4+1);
   nxtSetPixel(XX4,YYY4+2);
   nxtSetPixel(XX4,YYY4+3);
  nxtSetPixel(XX4,YYY4+4);
  nxtSetPixel(XX4,YYY4+5);
  nxtSetPixel(XX4+1,YYY4+4);
  nxtSetPixel(XX4-1,YYY4+4);
  nxtSetPixel(XX4+2,YYY4+4);
  nxtSetPixel(XX4-2,YYY4+4);
  nxtSetPixel(XX4+3,YYY4+4);
  nxtSetPixel(XX4-3,YYY4+4);
  nxtSetPixel(XX4+1,YYY4+5);
  nxtSetPixel(XX4-1,YYY4+5);
  nxtSetPixel(XX4+1,YYY4+6);
  nxtSetPixel(XX4-1,YYY4+6);
nxtSetPixel(XX4+1,YYY4+7);
  nxtSetPixel(XX4-1,YYY4+7);
nxtSetPixel(XX4,YYY4+7);

nxtSetPixel(XX5+2,YYY5);
  nxtSetPixel(XX5-2,YYY5);
  nxtSetPixel(XX5+1,YYY5+1);
  nxtSetPixel(XX5-1,YYY5+1);
   nxtSetPixel(XX5,YYY5+2);
   nxtSetPixel(XX5,YYY5+3);
  nxtSetPixel(XX5,YYY5+4);
  nxtSetPixel(XX5,YYY5+5);
  nxtSetPixel(XX5+1,YYY5+4);
  nxtSetPixel(XX5-1,YYY5+4);
  nxtSetPixel(XX5+2,YYY5+4);
  nxtSetPixel(XX5-2,YYY5+4);
  nxtSetPixel(XX5+3,YYY5+4);
  nxtSetPixel(XX5-3,YYY5+4);
  nxtSetPixel(XX5+1,YYY5+5);
  nxtSetPixel(XX5-1,YYY5+5);
  nxtSetPixel(XX5+1,YYY5+6);
  nxtSetPixel(XX5-1,YYY5+6);
nxtSetPixel(XX5+1,YYY5+7);
  nxtSetPixel(XX5-1,YYY5+7);
nxtSetPixel(XX5,YYY5+7);

nxtSetPixel(BX,BY);
nxtSetPixel(BX+1,BY);
nxtSetPixel(BX-1,BY);
nxtSetPixel(BX,BY+1);
nxtSetPixel(BX,BY-1);
nxtSetPixel(BX+1,BY+1);
nxtSetPixel(BX-1,BY-1);
nxtSetPixel(BX+1,BY-1);
nxtSetPixel(BX-1,BY+1);

nxtDisplayStringAt(30,55,"%d",Bcc);
nxtDisplayStringAt(57,55,"%d",Bc);
nxtDisplayStringAt(80,55,"%d",Ac);




if(nNxtButtonPressed==1){Down=127;}
if(nNxtButtonPressed==2){Down=-127;}

if(joy1Btn(1)==1){b1=1;}
if(joy1Btn(1)==0){b1=0;}
if(nNxtButtonPressed==3){b1=1;}

if(joy1Btn(2)==1){if(Bcc>=1){Bx=XX;By=YYY+4;Bd=Dd;Bcc=Bcc-1;}}

if(Bd==1){BX=BX+1;}if(Bd==0){BX=BX-1;}

  if(b1==1){if(YYY<=1){J=3;}}
  if (o==0){XX2=XX2+1;} if (o==1){XX2=XX2-1;}

  if(YYY<=1){if(b1==0){J=0;}}else{J=J-0.13;}
  YYY=YYY+J;
  if(XX2>=100){o=1;} if(XX2<=0){o=0;}

  if(down==127){XX=XX+1;Dd=1;}
  if(down==-127){XX=XX-1;Dd=0;}

if(Bcc==0){Bc=Bc-1;}if(Bc<=0){Bcc=Bcc+1;Bc=100;}

   if(XX2>=XX-30){if(XX2<=XX+30){if(YYY2<=1){J2=3;}}}
 YYY2=YYY2+J2;
 if(YYY2<=1){J2=0;}else{J2=J2-0.13;}


 if(XX3>=XX-40){if(XX3<=XX+40){if(YYY3<=1){J3=3;}}}
 YYY3=YYY3+J3;
 if(YYY3<=1){J3=0;}else{J3=J3-0.13;}

  if(XX3>=100){o2=1;} if(XX3<=0){o2=0;} if (o2==0){XX3=XX3+1;} if (o2==1){XX3=XX3-1;}


  if(XX4>=XX-7){if(XX4<=XX+7){if(YYY4<=1){J4=3;}}}
 YYY4=YYY4+J4;
 if(YYY4<=1){J4=0;}else{J4=J4-0.13;}

  if(XX4>=100){o3=1;} if(XX4<=0){o3=0;} if (o3==0){XX4=XX4+1;} if (o3==1){XX4=XX4-1;}



  if(XX5>=XX-20){if(XX5<=XX+20){if(YYY5<=1){J5=3;}}}
 YYY5=YYY5+J5;
 if(YYY5<=1){J5=0;}else{J5=J5-0.13;}

  if(XX5>=100){o4=1;} if(XX5<=0){o4=0;} if (o4==0){XX5=XX5+1;} if (o4==1){XX5=XX5-1;}

if(BX>=110){BY=300;}
if(BX<=-10){BY=300;}

if(joy1Btn(3)==1){if(Acc==false){Ac=Ac-1;}}if(Ac>=100){Acc=false;}if(Ac<=1){Acc=true;}if(Acc==true){Ac=Ac+1;}

if(joy1Btn(3)==1){if(Acc==false){a3a==true;}else{a3a=false;}}else{a3a=false;}



if(XX2>=XX-5){if(XX2<=XX+5){if(YYY2<=YYY){if(YYY>=YYY2-7){if(YYY<=YYY2+7) {XX2=150;score=score+1;J=2;PlaySound(soundBlip);}}}else{if(YYY>=YYY2-7){if(YYY<=YYY2+7){XX=1000;}}}}}

  if(XX3>=XX-5){if(XX3<=XX+5){if(YYY3<=YYY){if(YYY>=YYY3-7){if(YYY<=YYY3+7) {XX3=-50;score=score+1;J=2;PlaySound(soundBlip);}}}else{if(YYY>=YYY3-7){if(YYY<=YYY3+7){XX=1000;}}}}}

  if(XX4>=XX-5){if(XX4<=XX+5){if(YYY4<=YYY){if(YYY>=YYY4-7){if(YYY<=YYY4+7) {XX4=-100;score=score+1;J=2;PlaySound(soundBlip);}}}else{if(YYY>=YYY4-7){if(YYY<=YYY4+7){XX=1000;}}}}}

   if(XX5>=XX-5){if(XX5<=XX+5){if(YYY5<=YYY){if(YYY>=YYY5-7){if(YYY<=YYY5+7) {XX5=200;score=score+1;J=2;PlaySound(soundBlip);}}}else{if(YYY>=YYY5-7){if(YYY<=YYY5+7){XX=1000;}}}}}


   if(XX2>=BX-5){if(XX2<=BX+5){if(YYY2<=BY+7){if(BY>=YYY2){if(BY<=YYY2+7) {XX2=-50;score=score+1;PlaySound(soundBlip);}}}else{}}}
   if(XX3>=BX-5){if(XX3<=BX+5){if(YYY3<=BY+7){if(BY>=YYY3){if(BY<=YYY3+7) {XX3=-100;score=score+1;PlaySound(soundBlip);}}}else{}}}
   if(XX4>=BX-5){if(XX4<=BX+5){if(YYY4<=BY+7){if(BY>=YYY4){if(BY<=YYY4+7) {XX4=150;score=score+1;PlaySound(soundBlip);}}}else{}}}
   if(XX5>=BX-5){if(XX5<=BX+5){if(YYY5<=BY+7){if(BY>=YYY5){if(BY<=YYY5+7) {XX5=200;score=score+1;PlaySound(soundBlip);}}}else{}}}

   if(Acc==false){if(joy1Btn(3)==1){a3a=true;if(AD==true){if(XX2<=XX+11){if(XX2>=XX+1){if(YYY2<=YYY+8){if(YYY2>=YYY-8){score=score+1;XX2=150;}}}}}}}
   if(Acc==false){if(joy1Btn(3)==1){a3a=true;if(AD==false){if(XX2>=XX-11){if(XX2<=XX-1){if(YYY2<=YYY+8){if(YYY2>=YYY-8){score=score+1;XX2=150;}}}}}}  }
   if(Acc==false){if(joy1Btn(3)==1){a3a=true;if(AD==true){if(XX3<=XX+11){if(XX3>=XX+1){if(YYY3<=YYY+8){if(YYY3>=YYY-8){score=score+1;XX3=200;}}}}}}}
   if(Acc==false){if(joy1Btn(3)==1){a3a=true;if(AD==false){if(XX3>=XX-11){if(XX3<=XX-1){if(YYY3<=YYY+8){if(YYY3>=YYY-8){score=score+1;XX3=200;}}}}}}  }
   if(Acc==false){if(joy1Btn(3)==1){a3a=true;if(AD==true){if(XX4<=XX+11){if(XX4>=XX+1){if(YYY4<=YYY+8){if(YYY4>=YYY-8){score=score+1;XX4=-50;}}}}}}}
   if(Acc==false){if(joy1Btn(3)==1){a3a=true;if(AD==false){if(XX4>=XX-11){if(XX4<=XX-1){if(YYY4<=YYY+8){if(YYY4>=YYY-8){score=score+1;XX4=-50;}}}}}}}
   if(Acc==false){if(joy1Btn(3)==1){a3a=true;if(AD==true){if(XX5<=XX+11){if(XX5>=XX+1){if(YYY5<=YYY+8){if(YYY5>=YYY-8){score=score+1;XX5=-100;}}}}}}}
   if(Acc==false){if(joy1Btn(3)==1){a3a=true;if(AD==false){if(XX5>=XX-11){if(XX5<=XX-1){if(YYY5<=YYY+8){if(YYY5>=YYY-8){score=score+1;XX5=-100;}}}}}}}




   wait10Msec(3);
}






}
