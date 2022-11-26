
task main(){float X;float Y;float DX=0;float DY=0;float D;float JX;float JY;float DS;float S;bool m;
float XE;float YE;float DXE=0;float DYE=0;float DE=18;float JXE;float JYE;float DSE;float SE;bool mE=true;float DER;
bool TE;float BOXX;float BOXY;float C1;float C2;float C3;float C4;int score;float P1X=200;float P1Y;bool P1XD;
int scor;int scoreE;bool pwr;int pwrcnt;int tpwrcnt;float bX;float bY=100;bool EDA;


while(1==1){eraseDisplay();



nxtDrawRect(DX+5,DY+5,DX-5,DY-5);
nxtDrawRect(DXE+5,DYE+5,DXE-5,DYE-5);
if(pwr==true){nxtfillRect(DX+5,DY+5,DX-5,DY-5);}
else{nxtfillRect(DXE+5,DYE+5,DXE-5,DYE-5);}

nxtDrawRect(P1X+2,P1Y+2,P1X-2,P1Y-2);

nxtDrawLine(BX+3,BY+3,BX-3,BY-3);
nxtDrawLine(BX-3,BY+3,BX+3,BY-3);

nxtDisplayStringAt(3,54,"%d",scor);
nxtDisplayStringAt(80,54,"%d",scoreE);
nxtDisplayStringAt(40,54,"%d",tpwrcnt);


pwrcnt=pwrcnt+1;
if(pwrcnt>=100){pwrcnt=0;tpwrcnt=tpwrcnt+1;}
if(tpwrcnt>=5){if(pwr==true){pwr=false;}else{pwr=true;}tpwrcnt=0;}

if(DX>=70){DX=DX-1;DXE=DXE-1;BOXX=BOXX-1;P1X=P1X-1;bX=bX-1;}
if(DX<=30){DX=DX+1;DXE=DXE+1;BOXX=BOXX+1;P1X=P1X+1;bX=bX+1;}
if(DY>=40){DY=DY-1;DYE=DYE-1;BOXY=BOXY-1;P1Y=P1Y-1;bY=bY-1;}
if(DY<=20){DY=DY+1;DYE=DYE+1;BOXY=BOXY+1;P1Y=P1Y+1;bY=bY+1;}

if(P1XD==true){P1X=P1X+1;}else{P1X=P1X-1;}
if(P1X>=200){P1XD=false;P1Y=random(100)+C2;}if(P1X<=-200){P1XD=true;P1Y=random(100)+C2;}


C1=BOXX-50;
C2=BOXY-50;
C3=BOXX+50;
C4=BOXY+50;

nxtDrawRect(C1,C2,C3,C4);

if(DX>=C3){DX=DX-1;}
if(DX<=C1){DX=DX+1;}
if(DY>=C4){DY=DY-1;}
if(DY<=C2){DY=DY+1;}

if(DXE>=C3){DXE=DXE-1;}
if(DXE<=C1){DXE=DXE+1;}
if(DYE>=C4){DYE=DYE-1;}
if(DYE<=C2){DYE=DYE+1;}

if(pwr==true){if(DX>=bX){bX=bX+0.25;}if(DX<=bX){bX=bX-0.25;}if(DY<=bY){bY=bY-0.25;}if(DY>=bY){bY=bY+0.25;}}
if(pwr==false){if(DXE>=bX){bX=bX+0.25;}if(DXE<=bX){bX=bX-0.25;}if(DYE<=bY){bY=bY-0.25;}if(DYE>=bY){bY=bY+0.25;}}

if(bX<=DX+8){if(bX>=DX-8){if(bY<=DY+8){if(bY>=DY-8){scoreE=scoreE+1;}}}}
EDA=false;
if(bX<=DXE+8){if(bX>=DXE-8){if(bY<=DYE+8){if(bY>=DYE-8){scor=scor+1;EDA=true;}}}}

if(m==true){

if(D==1){DX=DX+1;DY=DY+0;}
if(D==2){DX=DX+0.8;DY=DY-0.2;}
if(D==3){DX=DX+0.6;DY=DY-0.4;}
if(D==4){DX=DX+0.4;DY=DY-0.6;}
if(D==5){DX=DX+0.2;DY=DY-0.8;}
if(D==6){DX=DX+0.0;DY=DY-1;}
if(D==7){DX=DX-0.2;DY=DY-0.8;}
if(D==8){DX=DX-0.4;DY=DY-0.6;}
if(D==9){DX=DX-0.6;DY=DY-0.4;}
if(D==10){DX=DX-0.8;DY=DY-0.2;}
if(D==11){DX=DX-1;DY=DY-0;}

if(D==12){DX=DX-0.8;DY=DY+0.2;}
if(D==13){DX=DX-0.6;DY=DY+0.4;}
if(D==14){DX=DX-0.4;DY=DY+0.6;}
if(D==15){DX=DX-0.2;DY=DY+0.8;}
if(D==16){DX=DX-0;DY=DY+1;}
if(D==17){DX=DX+0.2;DY=DY+0.8;}
if(D==18){DX=DX+0.4;DY=DY+0.6;}
if(D==19){DX=DX+0.6;DY=DY+0.4;}
if(D==20){DX=DX+0.8;DY=DY+0.2;}
}


if(DX>=DXE){if(DY>=DYE){DER=18.5;}else{DER=2.5;}}else{if(DY<=DYE){DER=7.5;}else{DER=12.5;}}
if(pwr==true){if(DER>=10){DER=DER-10;}else{DER=DER+10;}}
if(DXE<=bX+25){if(DXE>=bX-25){if(DYE<=bY+25){if(DYE>=bY-25){
if(bX>=DXE){if(bY>=DYE){DER=18.5;}else{DER=2.5;}}else{if(bY<=DYE){DER=7.5;}else{DER=12.5;}}
if(DER>=10){DER=DER-10;}else{DER=DER+10;}
}}}}

if(EDA==true){
if(DXE<=C1+5){if(DYE<=C2+5){DER=17.5;}if(DYE>=C4-5){DER=2.5;}}
if(DXE>=C3-5){if(DYE<=C2+5){DER=12.5;}if(DYE>=C4-5){DER=7.5;}}
}

if(DE>=DER+10){DE=DE+1;}else{if(DE>=DER){DE=DE-1;}else{if(DE>=DER-10){DE=DE+1;}else{DE=DE-1;}}}

if(mE==true){


if(DE==1){DXE=DXE+1;DYE=DYE+0;}
if(DE==2){DXE=DXE+0.8;DYE=DYE-0.2;}
if(DE==3){DXE=DXE+0.6;DYE=DYE-0.4;}
if(DE==4){DXE=DXE+0.4;DYE=DYE-0.6;}
if(DE==5){DXE=DXE+0.2;DYE=DYE-0.8;}
if(DE==6){DXE=DXE+0.0;DYE=DYE-1;}
if(DE==7){DXE=DXE-0.2;DYE=DYE-0.8;}
if(DE==8){DXE=DXE-0.4;DYE=DYE-0.6;}
if(DE==9){DXE=DXE-0.6;DYE=DYE-0.4;}
if(DE==10){DXE=DXE-0.8;DYE=DYE-0.2;}
if(DE==11){DXE=DXE-1;DYE=DYE-0;}

if(DE==12){DXE=DXE-0.8;DYE=DYE+0.2;}
if(DE==13){DXE=DXE-0.6;DYE=DYE+0.4;}
if(DE==14){DXE=DXE-0.4;DYE=DYE+0.6;}
if(DE==15){DXE=DXE-0.2;DYE=DYE+0.8;}
if(DE==16){DXE=DXE-0;DYE=DYE+1;}
if(DE==17){DXE=DXE+0.2;DYE=DYE+0.8;}
if(DE==18){DXE=DXE+0.4;DYE=DYE+0.6;}
if(DE==19){DXE=DXE+0.6;DYE=DYE+0.4;}
if(DE==20){DXE=DXE+0.8;DYE=DYE+0.2;}


}



if(DX<=P1X+8){if(DX>=P1X-8){if(DY<=P1Y+8){if(DY>=P1Y-8){scor = scor+100;P1X=random(500)+DX;P1X=P1X+100;}}}}
if(DXE<=P1X+8){if(DXE>=P1X-8){if(DYE<=P1Y+8){if(DYE>=P1Y-8){scoreE = scoreE+100;P1X=random(500)+DX;P1X=P1X+100;}}}}




if(DE>=21){DE=1;}
if(DE<=0){DE=20;}

if(nNxtButtonPressed==3){
  m=true;
}

if(nNxtButtonPressed==0){
  m=false;
}

nNxtExitClicks=3;

if(D>=21){D=1;}
if(D<=0){D=20;}

if(nNxtButtonPressed==1){DS=DS+0.9;}
if(nNxtButtonPressed==2){DS=DS-0.9;}

if(DS>=3){D=D+1;DS=0.5;}
if(DS<=0){D=D-1;DS=2.5;}

wait1Msec(30);

if(scor>=1000){nxtDisplayCenteredBigTextLine(2,"You Win!");wait1Msec(30000);}
if(scoreE>=1000){nxtDisplayCenteredBigTextLine(2,"You Lose!");wait1Msec(30000);}

}




























}
