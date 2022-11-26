

task main(){int TTTTT=60;int WWWWWWWWWW=100;
while(WWWWWWWWWW>=0){eraseDisplay();
  nxtDisplayStringAt(1,TTTTT,"Supa Shoot!");
  if(TTTTT>=20){TTTTT=TTTTT-1;}
  WWWWWWWWWW=WWWWWWWWWW-1;
wait1Msec(50);
}





while(1==1){
int mun=0;int W=0;int T=50;int R;float B1X;float B1Y=100;float B2X=100;float B2Y=100;
float B3X=100;float B3Y=100;float B4X=100;float B4Y=100;int B5X=100;float B5Y=100;int B6X;float B6Y=100;int B7X;float B7Y=100;float BTN;
float E1X=250;float E1Y=50;int E1D=0;float EB1X=500;float EB1Y;float E2X=100;float E2Y=50;int E2D=0;float EB2X=500;float EB2Y;
float E3X=200;float E3Y=50;int E3D=0;float EB3X=500;float EB3Y;float E4X=150;float E4Y=50;int E4D=0;float EB4X=500;float EB4Y;
float ES1X=120;float ES1Y=50;float ESB1X=500;float ESB1Y;float ES1J;
float E5X=150;float E5Y=50;int E5D=0;float EB5X=500;float EB5Y;float E5H;
float E6X=150;float E6Y=50;int E6D=0;float EB6X=500;float EB6Y;float E6H;
float S1X;float S1Y=50;int S1D;bool BOOM; int CCCCC=50;

while(W==0){eraseDisplay();
nxtDrawLine(CCCCC,15,CCCCC,25);
nxtDrawLine(CCCCC,15,CCCCC+4,19);
nxtDrawLine(CCCCC,15,CCCCC-4,19);
nxtDisplayCenteredTextLine(7,"PLAY");

if(nNxtButtonPressed==1){CCCCC=CCCCC+1;}
if(nNxtButtonPressed==2){CCCCC=CCCCC-1;}
if(nNxtButtonPressed==3){W=1;}
wait1Msec(50);
}
while(T<=700){eraseDisplay();

  nxtDrawLine(T+5,4,T-5,4);
  nxtDrawLine(T+5,4,T+5,0);
  nxtDrawLine(T-5,4,T-5,0);
  nxtDrawLine(T+1,4,T+1,6);
  nxtDrawLine(T-1,4,T-1,6);
  nxtDrawLine(T+1,6,T-1,6);
  nxtDrawLine(T+2,1,T+3,1);
  nxtDrawLine(T-2,1,T-3,1);
  nxtDrawLine(T+2,0,T+3,0);
  nxtDrawLine(T-2,0,T-3,0);

nxtDrawLine(B1X,B1Y-2,B1X,B1Y+1);
nxtDrawLine(B1X-1,B1Y-2,B1X-1,B1Y+1);
nxtDrawLine(B1X+1,B1Y-2,B1X+1,B1Y+1);

nxtDrawLine(B2X,B2Y-2,B2X,B2Y+1);
nxtDrawLine(B2X-1,B2Y-2,B2X-1,B2Y+1);
nxtDrawLine(B2X+1,B2Y-2,B2X+1,B2Y+1);

nxtDrawLine(B3X,B3Y-2,B3X,B3Y+1);
nxtDrawLine(B3X-1,B3Y-2,B3X-1,B3Y+1);
nxtDrawLine(B3X+1,B3Y-2,B3X+1,B3Y+1);

nxtDrawLine(B4X,B4Y-2,B4X,B4Y+1);
nxtDrawLine(B4X-1,B4Y-2,B4X-1,B4Y+1);
nxtDrawLine(B4X+1,B4Y-2,B4X+1,B4Y+1);

nxtDrawLine(B5X,B5Y-2,B5X,B5Y+1);
nxtDrawLine(B5X-1,B5Y-2,B5X-1,B5Y+1);
nxtDrawLine(B5X+1,B5Y-2,B5X+1,B5Y+1);

nxtDrawLine(B6X,B6Y-2,B6X,B6Y+1);
nxtDrawLine(B6X-1,B6Y-2,B6X-1,B6Y+1);
nxtDrawLine(B6X+1,B6Y-2,B6X+1,B6Y+1);

nxtDrawLine(B7X,B7Y-2,B7X,B7Y+1);
nxtDrawLine(B7X-1,B7Y-2,B7X-1,B7Y+1);
nxtDrawLine(B7X+1,B7Y-2,B7X+1,B7Y+1);

nxtDrawLine(E1X+7,E1Y,E1X-7,E1Y);
nxtDrawLine(E1X+7,E1Y-1,E1X-7,E1Y-1);

nxtDrawLine(EB1X,EB1Y,EB1X,EB1Y-2);
nxtDrawLine(EB1X+1,EB1Y+1,EB1X-1,EB1Y+1);

nxtDrawLine(E2X+7,E2Y,E2X-7,E2Y);
nxtDrawLine(E2X+7,E2Y-1,E2X-7,E2Y-1);

nxtDrawLine(EB2X,EB2Y,EB2X,EB2Y-2);
nxtDrawLine(EB2X+1,EB2Y+1,EB2X-1,EB2Y+1);

nxtDrawLine(E3X+7,E3Y,E3X-7,E3Y);
nxtDrawLine(E3X+7,E3Y-1,E3X-7,E3Y-1);

nxtDrawLine(EB3X,EB3Y,EB3X,EB3Y-2);
nxtDrawLine(EB3X+1,EB3Y+1,EB3X-1,EB3Y+1);

nxtDrawLine(E4X+7,E4Y,E4X-7,E4Y);
nxtDrawLine(E4X+7,E4Y-1,E4X-7,E4Y-1);

nxtDrawLine(EB4X,EB4Y,EB4X,EB4Y-2);
nxtDrawLine(EB4X+1,EB4Y+1,EB4X-1,EB4Y+1);

nxtDrawLine(ES1X+7,ES1Y,ES1X-7,ES1Y);
nxtDrawLine(ES1X+7,ES1Y-1,ES1X-7,ES1Y-1);
nxtDrawLine(ES1X+7,ES1Y,ES1X,ES1Y+5);
nxtDrawLine(ES1X-7,ES1Y,ES1X,ES1Y+5);

nxtDrawLine(ESB1X,ESB1Y,ESB1X,ESB1Y-2);
nxtDrawLine(ESB1X+1,ESB1Y+1,ESB1X-1,ESB1Y+1);

if(E5H>=1){nxtDrawLine(E5X+7,E5Y,E5X-7,E5Y);
nxtDrawLine(E5X+7,E5Y-1,E5X-7,E5Y-1);}
if(E5H>=2){nxtDrawLine(E5X+7,E5Y-2,E5X-7,E5Y-2);
nxtDrawLine(E5X+7,E5Y-3,E5X-7,E5Y-3);}
if(E5H>=3){nxtDrawLine(E5X+7,E5Y-4,E5X-7,E5Y-4);
nxtDrawLine(E5X+7,E5Y-5,E5X-7,E5Y-5);}
if(E5H>=4){nxtDrawLine(E5X+7,E5Y-6,E5X-7,E5Y-6);
nxtDrawLine(E5X+7,E5Y-7,E5X-7,E5Y-7);}
if(E5H>=5){nxtDrawLine(E5X+7,E5Y-8,E5X-7,E5Y-8);
nxtDrawLine(E5X+7,E5Y-8,E5X-7,E5Y-8);}


nxtDrawLine(EB5X,EB5Y,EB5X,EB5Y-2);
nxtDrawLine(EB5X+1,EB5Y+1,EB5X-1,EB5Y+1);

if(E6H>=1){nxtDrawLine(E6X+7,E6Y,E6X-7,E6Y);
nxtDrawLine(E6X+7,E6Y-1,E6X-7,E6Y-1);}
if(E6H>=2){nxtDrawLine(E6X+7,E6Y-2,E6X-7,E6Y-2);
nxtDrawLine(E6X+7,E6Y-3,E6X-7,E6Y-3);}
if(E6H>=3){nxtDrawLine(E6X+7,E6Y-4,E6X-7,E6Y-4);
nxtDrawLine(E6X+7,E6Y-5,E6X-7,E6Y-5);}
if(E6H>=4){nxtDrawLine(E6X+7,E6Y-6,E6X-7,E6Y-6);
nxtDrawLine(E6X+7,E6Y-7,E6X-7,E6Y-7);}
if(E6H>=5){nxtDrawLine(E6X+7,E6Y-8,E6X-7,E6Y-8);
nxtDrawLine(E6X+7,E6Y-8,E6X-7,E6Y-8);}


nxtDrawLine(EB6X,EB6Y,EB6X,EB6Y-2);
nxtDrawLine(EB6X+1,EB6Y+1,EB6X-1,EB6Y+1);


nxtSetPixel(S1X+2,S1Y+2);
nxtSetPixel(S1X-2,S1Y+2);
nxtSetPixel(S1X+2,S1Y-2);
nxtSetPixel(S1X-2,S1Y-2);
nxtSetPixel(S1X+1,S1Y+1);
nxtSetPixel(S1X-1,S1Y+1);
nxtSetPixel(S1X+1,S1Y-1);
nxtSetPixel(S1X-1,S1Y-1);
nxtSetPixel(S1X,S1Y);
nxtDrawRect(S1X-3,S1Y-3,S1X+3,S1Y+3);

nxtDisplayStringAt(3,55,"%d",mun);

ES1X=ES1X+ES1J/2;

if(ES1X>=T){ES1J=ES1J-0.15;if(ES1J>=0){ES1J=ES1J-0.1;}}else{ES1J=ES1J+0.15;if(ES1J<=0){ES1J=ES1J+0.1;}}
if(ES1J>=1.5){ES1J=ES1J-0.05;}
if(ES1J<=-1.5){ES1J=ES1J+0.05;}
if(ES1J>=3){ES1J=ES1J-0.05;}
if(ES1J<=-3){ES1J=ES1J+0.05;}
if(ES1J>=4.5){ES1J=ES1J-0.05;}
if(ES1J<=-4.5){ES1J=ES1J+0.05;}


if(E5H<=0){E5H=5;E5X=random(100)-110;E5Y=random(30)+25;}
if(E6H<=0){E6H=5;E6X=random(100)+110;E6Y=random(30)+25;}

EB1Y=EB1Y-0.75;
EB2Y=EB2Y-0.75;
EB3Y=EB3Y-0.75;
EB4Y=EB4Y-0.75;
ESB1Y=ESB1Y-0.75;
EB5Y=EB5Y-0.75;
EB6Y=EB6Y-0.75;

B1Y=B1Y+0.5;
B2Y=B2Y+0.5;
B3Y=B3Y+0.5;
B4Y=B4Y+0.5;
B5Y=B5Y+0.5;
B6Y=B6Y+0.5;
B7Y=B7Y+0.5;

if(S1D==0){S1X=S1X-0.15;}
if(S1D==1){S1X=S1X+0.15;}

if(S1X>=150){S1D=0;}
if(S1X<=-50){S1D=1;}


if(BOOM==true){S1X=-100;}

BOOM=false;
if(B1X>=S1X-3){if(B1X<=S1X+3){if(B1Y>=S1Y-3){if(B1Y<=S1Y+3){BOOM=true;}}}}
if(B2X>=S1X-3){if(B2X<=S1X+3){if(B2Y>=S1Y-3){if(B2Y<=S1Y+3){BOOM=true;}}}}
if(B3X>=S1X-3){if(B3X<=S1X+3){if(B3Y>=S1Y-3){if(B3Y<=S1Y+3){BOOM=true;}}}}
if(B4X>=S1X-3){if(B4X<=S1X+3){if(B4Y>=S1Y-3){if(B4Y<=S1Y+3){BOOM=true;}}}}
if(B5X>=S1X-3){if(B5X<=S1X+3){if(B5Y>=S1Y-3){if(B5Y<=S1Y+3){BOOM=true;}}}}
if(B6X>=S1X-3){if(B6X<=S1X+3){if(B6Y>=S1Y-3){if(B6Y<=S1Y+3){BOOM=true;}}}}
if(B7X>=S1X-3){if(B7X<=S1X+3){if(B7Y>=S1Y-3){if(B7Y<=S1Y+3){BOOM=true;}}}}

if(EB1Y>=-3){if(EB1Y<=5){if(EB1X<=T+5){if(EB1X>=T-5){T=1000;}}}}
if(EB2Y>=-3){if(EB2Y<=5){if(EB2X<=T+5){if(EB2X>=T-5){T=1000;}}}}
if(EB3Y>=-3){if(EB3Y<=5){if(EB3X<=T+5){if(EB3X>=T-5){T=1000;}}}}
if(EB4Y>=-3){if(EB4Y<=5){if(EB4X<=T+5){if(EB4X>=T-5){T=1000;}}}}
if(ESB1Y>=-3){if(ESB1Y<=5){if(ESB1X<=T+5){if(ESB1X>=T-5){T=1000;}}}}
if(EB5Y>=-3){if(EB5Y<=5){if(EB5X<=T+5){if(EB5X>=T-5){T=1000;}}}}
if(EB6Y>=-3){if(EB6Y<=5){if(EB6X<=T+5){if(EB6X>=T-5){T=1000;}}}}

if(E1D==0){E1X=E1X-0.25;}else{E1X=E1X+0.25;}
if(E2D==0){E2X=E2X-0.25;}else{E2X=E2X+0.25;}
if(E3D==0){E3X=E3X-0.25;}else{E3X=E3X+0.25;}
if(E4D==0){E4X=E4X-0.25;}else{E4X=E4X+0.25;}
if(E5D==0){E5X=E5X-0.25;}else{E5X=E5X+0.25;}
if(E6D==0){E6X=E6X-0.25;}else{E6X=E6X+0.25;}

if(E1X<=1){E1D=1;}if(E1X>=100){E1D=0;}
if(E2X<=1){E2D=1;}if(E2X>=100){E2D=0;}
if(E3X<=1){E3D=1;}if(E3X>=100){E3D=0;}
if(E4X<=1){E4D=1;}if(E4X>=100){E4D=0;}
if(E5X<=1){E5D=1;}if(E5X>=100){E5D=0;}
if(E6X<=1){E6D=1;}if(E6X>=100){E6D=0;}

if(EB1Y<=1){if(E1X<=T+2){if(E1X>=T-2){EB1X=E1X;EB1Y=E1Y;}}}
if(EB2Y<=1){if(E2X<=T+2){if(E2X>=T-2){EB2X=E2X;EB2Y=E2Y;}}}
if(EB3Y<=1){if(E3X<=T+2){if(E3X>=T-2){EB3X=E3X;EB3Y=E3Y;}}}
if(EB4Y<=1){if(E4X<=T+2){if(E4X>=T-2){EB4X=E4X;EB4Y=E4Y;}}}
if(ESB1Y<=1){if(ES1X<=T+2){if(ES1X>=T-2){ESB1X=ES1X;ESB1Y=ES1Y;}}}
if(EB5Y<=1){if(E5X<=T+2){if(E5X>=T-2){EB5X=E5X;EB5Y=E5Y;}}}
if(EB6Y<=1){if(E6X<=T+2){if(E6X>=T-2){EB6X=E6X;EB6Y=E6Y;}}}


if(B1X<=E1X+7){if(B1X>=E1X-7){if(B1Y<=E1Y+2){if(B1Y>=E1Y-2){E1X=random(100)+110;E1Y=random(50)+10;B1Y=100; MUN = MUN+1; }}}}
if(B2X<=E1X+7){if(B2X>=E1X-7){if(B2Y<=E1Y+2){if(B2Y>=E1Y-2){E1X=random(100)+110;E1Y=random(50)+10;B2Y=100; MUN = MUN+1; }}}}
if(B3X<=E1X+7){if(B3X>=E1X-7){if(B3Y<=E1Y+2){if(B3Y>=E1Y-2){E1X=random(100)+110;E1Y=random(50)+10;B3Y=100; MUN = MUN+1; }}}}
if(B4X<=E1X+7){if(B4X>=E1X-7){if(B4Y<=E1Y+2){if(B4Y>=E1Y-2){E1X=random(100)+110;E1Y=random(50)+10;B4Y=100; MUN = MUN+1; }}}}
if(B5X<=E1X+7){if(B5X>=E1X-7){if(B5Y<=E1Y+2){if(B5Y>=E1Y-2){E1X=random(100)+110;E1Y=random(50)+10;B5Y=100; MUN = MUN+1; }}}}
if(B6X<=E1X+7){if(B6X>=E1X-7){if(B6Y<=E1Y+2){if(B6Y>=E1Y-2){E1X=random(100)+110;E1Y=random(50)+10;B6Y=100; MUN = MUN+1; }}}}
if(B7X<=E1X+7){if(B7X>=E1X-7){if(B7Y<=E1Y+2){if(B7Y>=E1Y-2){E1X=random(100)+110;E1Y=random(50)+10;B7Y=100; MUN = MUN+1; }}}}
if(BOOM==true){E1X=random(100)+110;E1Y=random(50)+10; MUN = MUN+1; }

if(B1X<=E2X+7){if(B1X>=E2X-7){if(B1Y<=E2Y+2){if(B1Y>=E2Y-2){E2X=random(100)-110;E2Y=random(50)+10;B1Y=100;MUN = MUN+1;  }}}}
if(B2X<=E2X+7){if(B2X>=E2X-7){if(B2Y<=E2Y+2){if(B2Y>=E2Y-2){E2X=random(100)-110;E2Y=random(50)+10;B2Y=100;MUN = MUN+1;  }}}}
if(B3X<=E2X+7){if(B3X>=E2X-7){if(B3Y<=E2Y+2){if(B3Y>=E2Y-2){E2X=random(100)-110;E2Y=random(50)+10;B3Y=100;MUN = MUN+1;  }}}}
if(B4X<=E2X+7){if(B4X>=E2X-7){if(B4Y<=E2Y+2){if(B4Y>=E2Y-2){E2X=random(100)-110;E2Y=random(50)+10;B4Y=100;MUN = MUN+1;  }}}}
if(B5X<=E2X+7){if(B5X>=E2X-7){if(B5Y<=E2Y+2){if(B5Y>=E2Y-2){E2X=random(100)-110;E2Y=random(50)+10;B5Y=100;MUN = MUN+1;  }}}}
if(B6X<=E2X+7){if(B6X>=E2X-7){if(B6Y<=E2Y+2){if(B6Y>=E2Y-2){E2X=random(100)-110;E2Y=random(50)+10;B6Y=100;MUN = MUN+1;  }}}}
if(B7X<=E2X+7){if(B7X>=E2X-7){if(B7Y<=E2Y+2){if(B7Y>=E2Y-2){E2X=random(100)-110;E2Y=random(50)+10;B7Y=100;MUN = MUN+1;  }}}}
if(BOOM==true){E2X=random(100)-110;E2Y=random(50)+10;B7Y=100;MUN = MUN+1;  }

if(B1X<=E3X+7){if(B1X>=E3X-7){if(B1Y<=E3Y+2){if(B1Y>=E3Y-2){E3X=random(100)-110;E3Y=random(50)+10;B1Y=100; MUN = MUN+1; }}}}
if(B2X<=E3X+7){if(B2X>=E3X-7){if(B2Y<=E3Y+2){if(B2Y>=E3Y-2){E3X=random(100)-110;E3Y=random(50)+10;B2Y=100; MUN = MUN+1; }}}}
if(B3X<=E3X+7){if(B3X>=E3X-7){if(B3Y<=E3Y+2){if(B3Y>=E3Y-2){E3X=random(100)-110;E3Y=random(50)+10;B3Y=100; MUN = MUN+1; }}}}
if(B4X<=E3X+7){if(B4X>=E3X-7){if(B4Y<=E3Y+2){if(B4Y>=E3Y-2){E3X=random(100)-110;E3Y=random(50)+10;B4Y=100; MUN = MUN+1; }}}}
if(B5X<=E3X+7){if(B5X>=E3X-7){if(B5Y<=E3Y+2){if(B5Y>=E3Y-2){E3X=random(100)-110;E3Y=random(50)+10;B5Y=100; MUN = MUN+1; }}}}
if(B6X<=E3X+7){if(B6X>=E3X-7){if(B6Y<=E3Y+2){if(B6Y>=E3Y-2){E3X=random(100)-110;E3Y=random(50)+10;B6Y=100; MUN = MUN+1; }}}}
if(B7X<=E3X+7){if(B7X>=E3X-7){if(B7Y<=E3Y+2){if(B7Y>=E3Y-2){E3X=random(100)-110;E3Y=random(50)+10;B7Y=100; MUN = MUN+1; }}}}
if(BOOM==true){E3X=random(100)-110;E3Y=random(50)+10;B7Y=100; MUN = MUN+1; }

if(B1X<=E4X+7){if(B1X>=E4X-7){if(B1Y<=E4Y+2){if(B1Y>=E4Y-2){E4X=random(100)+110;E4Y=random(50)+10;B1Y=100;MUN = MUN+1;  }}}}
if(B2X<=E4X+7){if(B2X>=E4X-7){if(B2Y<=E4Y+2){if(B2Y>=E4Y-2){E4X=random(100)+110;E4Y=random(50)+10;B2Y=100; MUN = MUN+1; }}}}
if(B3X<=E4X+7){if(B3X>=E4X-7){if(B3Y<=E4Y+2){if(B3Y>=E4Y-2){E4X=random(100)+110;E4Y=random(50)+10;B3Y=100; MUN = MUN+1; }}}}
if(B4X<=E4X+7){if(B4X>=E4X-7){if(B4Y<=E4Y+2){if(B4Y>=E4Y-2){E4X=random(100)+110;E4Y=random(50)+10;B4Y=100; MUN = MUN+1; }}}}
if(B5X<=E4X+7){if(B5X>=E4X-7){if(B5Y<=E4Y+2){if(B5Y>=E4Y-2){E4X=random(100)+110;E4Y=random(50)+10;B5Y=100; MUN = MUN+1; }}}}
if(B6X<=E4X+7){if(B6X>=E4X-7){if(B6Y<=E4Y+2){if(B6Y>=E4Y-2){E4X=random(100)+110;E4Y=random(50)+10;B6Y=100; MUN = MUN+1; }}}}
if(B7X<=E4X+7){if(B7X>=E4X-7){if(B7Y<=E4Y+2){if(B7Y>=E4Y-2){E4X=random(100)+110;E4Y=random(50)+10;B7Y=100; MUN = MUN+1; }}}}
if(BOOM==true){E4X=random(100)+110;E4Y=random(50)+10;B7Y=100; MUN = MUN+1; }

if(B1X<=ES1X+7){if(B1X>=ES1X-7){if(B1Y<=ES1Y+2){if(B1Y>=ES1Y-2){ES1X=random(500)+510;ES1Y=random(30)+30;B1Y=100; MUN = MUN+1;  }}}}
if(B2X<=ES1X+7){if(B2X>=ES1X-7){if(B2Y<=ES1Y+2){if(B2Y>=ES1Y-2){ES1X=random(500)+510;ES1Y=random(30)+30;B2Y=100; MUN = MUN+1; }}}}
if(B3X<=ES1X+7){if(B3X>=ES1X-7){if(B3Y<=ES1Y+2){if(B3Y>=ES1Y-2){ES1X=random(500)+510;ES1Y=random(30)+30;B3Y=100; MUN = MUN+1; }}}}
if(B4X<=ES1X+7){if(B4X>=ES1X-7){if(B4Y<=ES1Y+2){if(B4Y>=ES1Y-2){ES1X=random(500)+510;ES1Y=random(30)+30;B4Y=100; MUN = MUN+1; }}}}
if(B5X<=ES1X+7){if(B5X>=ES1X-7){if(B5Y<=ES1Y+2){if(B5Y>=ES1Y-2){ES1X=random(500)+510;ES1Y=random(30)+30;B5Y=100; MUN = MUN+1; }}}}
if(B6X<=ES1X+7){if(B6X>=ES1X-7){if(B6Y<=ES1Y+2){if(B6Y>=ES1Y-2){ES1X=random(500)+510;ES1Y=random(30)+30;B6Y=100; MUN = MUN+1; }}}}
if(B7X<=ES1X+7){if(B7X>=ES1X-7){if(B7Y<=ES1Y+2){if(B7Y>=ES1Y-2){ES1X=random(500)+510;ES1Y=random(30)+30;B7Y=100; MUN = MUN+1; }}}}
if(BOOM==true){ES1X=random(500)+510;ES1Y=random(30)+30;B7Y=100; MUN = MUN+1; }

if(B1X<=E5X+7){if(B1X>=E5X-7){if(B1Y<=E5Y+2){if(B1Y>=E5Y+2- E5H- E5H){E5H=E5H-1; B1Y=100;MUN = MUN+1;  }}}}
if(B2X<=E5X+7){if(B2X>=E5X-7){if(B2Y<=E5Y+2){if(B2Y>=E5Y+2- E5H- E5H){E5H=E5H-1; B2Y=100; MUN = MUN+1; }}}}
if(B3X<=E5X+7){if(B3X>=E5X-7){if(B3Y<=E5Y+2){if(B3Y>=E5Y+2- E5H- E5H){E5H=E5H-1; B3Y=100; MUN = MUN+1; }}}}
if(B4X<=E5X+7){if(B4X>=E5X-7){if(B4Y<=E5Y+2){if(B4Y>=E5Y+2- E5H- E5H){E5H=E5H-1; B4Y=100; MUN = MUN+1; }}}}
if(B5X<=E5X+7){if(B5X>=E5X-7){if(B5Y<=E5Y+2){if(B5Y>=E5Y+2- E5H- E5H){E5H=E5H-1; B5Y=100; MUN = MUN+1; }}}}
if(B6X<=E5X+7){if(B6X>=E5X-7){if(B6Y<=E5Y+2){if(B6Y>=E5Y+2- E5H- E5H){E5H=E5H-1; B6Y=100; MUN = MUN+1; }}}}
if(B7X<=E5X+7){if(B7X>=E5X-7){if(B7Y<=E5Y+2){if(B7Y>=E5Y+2- E5H- E5H){E5H=E5H-1; B7Y=100; MUN = MUN+1; }}}}
if(BOOM==true){E5H=E5H-1; B7Y=100; MUN = MUN+1; }

if(B1X<=E6X+7){if(B1X>=E6X-7){if(B1Y<=E6Y+2){if(B1Y>=E6Y+2- E6H- E6H){E6H=E6H-1; B1Y=100;MUN = MUN+1;  }}}}
if(B2X<=E6X+7){if(B2X>=E6X-7){if(B2Y<=E6Y+2){if(B2Y>=E6Y+2- E6H- E6H){E6H=E6H-1; B2Y=100; MUN = MUN+1; }}}}
if(B3X<=E6X+7){if(B3X>=E6X-7){if(B3Y<=E6Y+2){if(B3Y>=E6Y+2- E6H- E6H){E6H=E6H-1; B3Y=100; MUN = MUN+1; }}}}
if(B4X<=E6X+7){if(B4X>=E6X-7){if(B4Y<=E6Y+2){if(B4Y>=E6Y+2- E6H- E6H){E6H=E6H-1; B4Y=100; MUN = MUN+1; }}}}
if(B5X<=E6X+7){if(B5X>=E6X-7){if(B5Y<=E6Y+2){if(B5Y>=E6Y+2- E6H- E6H){E6H=E6H-1; B5Y=100; MUN = MUN+1; }}}}
if(B6X<=E6X+7){if(B6X>=E6X-7){if(B6Y<=E6Y+2){if(B6Y>=E6Y+2- E6H- E6H){E6H=E6H-1; B6Y=100; MUN = MUN+1; }}}}
if(B7X<=E6X+7){if(B7X>=E6X-7){if(B7Y<=E6Y+2){if(B7Y>=E6Y+2- E6H- E6H){E6H=E6H-1; B7Y=100; MUN = MUN+1; }}}}
if(BOOM==true){E6H=E6H-1; B7Y=100; MUN = MUN+1; }



if(nNxtButtonPressed==1){T=T+1;}
if(nNxtButtonPressed==2){T=T-1;}
if(nNxtButtonPressed==3){if(BTN==0){if(B1Y>=66){B1X=T;B1Y=3;}else{if(B2Y>=66){B2X=T;B2Y=3;}else{if(B3Y>=66){B3X=T;B3Y=3;}else{if(B4Y>=66){B4X=T;B4Y=3;}
else{if(B5Y>=66){B5X=T;B5Y=3;}else{if(B6Y>=66){B6X=T;B6Y=3;}else{if(B7Y>=66){B7X=T;B7Y=3;}}}}}}}}BTN=1;}else{BTN=0;}

wait1Msec(20);
}
eraseDisplay();
nxtDisplayCenteredBigTextLine(2,"Game");
nxtDisplayCenteredBigTextLine(4,"Over!!!");
nxtDisplayTextLine(7,"score");
nxtDisplayStringAt(60,8,"%d",mun);
wait1Msec(5000);
}
}
