#include<bits/stdc++.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
using namespace std;
void road();
void car();
void collision();
int x = 320,l;
int car_x1,car_y1,car_x2,car_y2;
int l1x1,l1x2,l1y,l2x1,l2x2,l2y,l3x1,l3x2,l3y,l4x1,l4x2,l4y;
int carcl=0;
int cl=0;
int c=1;
bool pattern1 = true;
bool pattern2= false;
bool pattern3=false;
bool END = true;
int main()
{
int i, j = 0, gd = DETECT, gm;
char ch;

   initgraph(&gd,&gm,"C:\\TC\\BGI");
   int K=0,score=0;
   char c;

    cleardevice();

    mainmenu:
    {
            cleardevice();

            char c;
            //PlaySound("sound4.wav",NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
            sndPlaySound("sound4.wav", SND_FILENAME | SND_ASYNC );
            while(1)
            {
            //start screen



            setcolor(1);
            settextstyle(8,0,9);
            outtextxy(60,60,"SPEEDSTAR");
            settextstyle(8,0,5);
            setcolor(15);
            outtextxy(90,220,"PLAY          [ENTER]");
            outtextxy(90,260,"INSTRUCTIONS  [i]");
            outtextxy(90,300,"CREDIT        [c]");
            outtextxy(90,340,"EXIT          [ESC]");



            if(kbhit())
            {
            c=getch();
            if(c==13)
                goto cs;
            else if(c==27)
                exit(0);
            else if(c=='i')
                goto instruction;
            else if(c=='c')
                goto credit;
            }
        }
    }
    cs:
    {
        while(1)
        {
            cleardevice();



            setcolor(15);
            settextstyle(8,0,4);
            outtextxy(150,40,"SELECT CAR COLOUR");
            settextstyle(8,0,3);
            setcolor(14);
            outtextxy(150,100,"BLUE       [1]");
            outtextxy(150,130,"GREEN      [2]");
            outtextxy(150,160,"CYAN       [3]");
            outtextxy(150,190,"RED        [4]");
            outtextxy(150,220,"YELLOW     [5]");
            outtextxy(150,250,"BROWN      [6]");
            outtextxy(150,340,"WHITE      [0]");
            outtextxy(150,280,"GRAY       [7]");
            outtextxy(150,310,"MAGENTA    [8]");
            outtextxy(5,400,"#Press the adjacent numbers to select colour");
            char colo;

            colo=getch();
            if(colo=='1'){
                carcl=1;
            }
            else if(colo=='2')
                carcl=2;
               //goto level1;
             else if(colo=='3')
                carcl=3;
                //goto level1;
                 else if(colo=='4')
                carcl=4;
                //goto level1;
                 else if(colo=='5')
                carcl=14;
                //goto level1;
                 else if(colo=='6')
                carcl=6;
                //goto level1;
                 else if(colo=='0')
                carcl=15;
                //goto level1;
                 else if(colo=='7')
                carcl=8;
                  else if(colo=='8')
                carcl=5;
                 else
                    carcl=15;
                goto level1;

        }
    }
    instruction:
    {
        while(1)
        {
            cleardevice();
            setcolor(9);
            settextstyle(6,0,5);
            outtextxy(100,40,"INSTRUCTIONS");
            setcolor(12);
            settextstyle(4,0,1);

            outtextxy(20,120,"#MOVE VEHICLE WITH SIDE ARROW KEYS");
            outtextxy(20,150,"#DON'T HIT THE INCOMING BLOCKS");
            outtextxy(20,180,"#SPEED INCREASES AS YOU LEVEL UP");
            outtextxy(20,210,"#PRESS 'ALT' TO PAUSE THE GAME");
            setcolor(WHITE);
            outtextxy(150,400,"Press Esc to main menu");
            char ch;
            ch=getch();
            if(ch==27)
                goto mainmenu;
        }
    }

    credit:
    {
        while(1)
        {
            cleardevice();
            setcolor(7);
            settextstyle(4,0,4);
            outtextxy(90,20,"PROJECT WORK-2");
            settextstyle(6,0,2);
            setcolor(7);
            outtextxy(00,80," Submitted by:");
            outtextxy(20,140,"Maksudur Rahman Munif");
            outtextxy(20,160,"Registration No: 2016831003");
            outtextxy(20,250,"Asif Mohammed Samir Sir ");
            outtextxy(20,270,"Assistant Professor");
            outtextxy(20,290,"IICT,SUST");
            setcolor(6);
            outtextxy(150,350,"Press Esc to main menu");
            char cha=getch();
            if(cha==27)
                goto mainmenu;
            }

    }
    level1:

    cleardevice();
    //blocks
    i=-300;
    int k=1,l=1;
    while(1)
    {
          setcolor(9);
          settextstyle(3,0,3);
          char ar[100];
          char ar1[100];
          sprintf(ar,"SCORE: %d",score);
          outtextxy(20,20,ar);
          sprintf(ar1,"LEVEL: %d",l);
          outtextxy(20,50,ar1);
         road();
          car();

        setcolor(1);
      if(pattern1){
       setlinestyle(15, 8, 30);
      line(232,50+i, 272, 50+i);
      setlinestyle(15, 8, 30);
      line(322,200+i, 362, 200+i);
       setlinestyle(15, 8, 30);
      line(412,50+i, 452, 50+i);
      l1x1 = 232;
      l1x2 = 272;
      l1y=50+i;
      l2x1=322;
      l2x2 = 362;
      l2y=200+i;
      l3x1=412;
      l3x2 = 452;
      l3y=50+i;

      }
      if(pattern2)
      {
      setlinestyle(15, 8, 30);
      line(232,50+i, 272, 50+i);
      setlinestyle(15, 8, 30);
      line(322,200+i, 362, 200+i);
       setlinestyle(15, 8, 30);
      line(412,350+i, 452, 350+i);
      l1x1 = 232;
      l1x2 = 272;
      l1y=50+i;
      l2x1=322;
      l2x2 = 362;
      l2y=200+i;
      l4x1 = 412;
      l4x2 = 452;
      l4y = 350 + i;


      }
      if(pattern3){
             setlinestyle(15, 8, 30);
      line(412,50+i, 452, 50+i);
       setlinestyle(15, 8, 30);
      line(322,200+i, 362, 200+i);
         setlinestyle(15, 8, 30);
      line(232,350+i, 272, 350+i);
      l2x1=322;
      l2x2 = 362;
      l2y=200+i;
      l3x1=412;
      l3x2 = 452;
      l3y=50+i;
      }


      delay(40);
      cleardevice();
      i+=10;
      if(i>470)
      {
        score=score+30;
        if(score==90){
            l++;
            goto level2;
        }
        i=-300;
        k++;
        if(k%2==0){
        pattern1= false;
        pattern2 =true;
        pattern3=false;
        }
        else if(k%3==0){
        pattern1 = false;
        pattern2 =false;
        pattern3= true;
        }
        else{
        pattern1 = true;
        pattern2 = false;
        pattern3 = false;
        }
        }

       if(kbhit())
       {
       ch=getch();
        if(ch==77){
        if(x<=399)
        x+=80;
        }
      if(ch==75){
        if(x>=241)

        x-=80;
           }
       }
     collision();
    if(cl==1){
     cl=0;
     sndPlaySound("sound3.wav", SND_FILENAME | SND_ASYNC );
    goto gameover;
    }

       }




    level2:

    cleardevice();
    //blocks
    i=-300;
    k=1;
    while(1)
    {
          setcolor(10);
          settextstyle(3,0,3);
          char ar[100];
          char ar1[100];
          sprintf(ar,"SCORE: %d",score);
          outtextxy(20,20,ar);
          sprintf(ar1,"LEVEL: %d",l);
          outtextxy(20,50,ar1);
         road();
          car();

        setcolor(2);
      if(pattern1){
       setlinestyle(15, 8, 30);
      line(232,50+i, 272, 50+i);
      setlinestyle(15, 8, 30);
      line(322,200+i, 362, 200+i);
       setlinestyle(15, 8, 30);
      line(412,50+i, 452, 50+i);
      l1x1 = 232;
      l1x2 = 272;
      l1y=50+i;
      l2x1=322;
      l2x2 = 362;
      l2y=200+i;
      l3x1=412;
      l3x2 = 452;
      l3y=50+i;

      }
      if(pattern2)
      {
      setlinestyle(15, 8, 30);
      line(232,50+i, 272, 50+i);
      setlinestyle(15, 8, 30);
      line(322,200+i, 362, 200+i);
       setlinestyle(15, 8, 30);
      line(412,350+i, 452, 350+i);
      l1x1 = 232;
      l1x2 = 272;
      l1y=50+i;
      l2x1=322;
      l2x2 = 362;
      l2y=200+i;
      l4x1 = 412;
      l4x2 = 452;
      l4y = 350 + i;


      }
      if(pattern3){
             setlinestyle(15, 8, 30);
      line(412,50+i, 452, 50+i);
       setlinestyle(15, 8, 30);
      line(322,200+i, 362, 200+i);
         setlinestyle(15, 8, 30);
      line(232,350+i, 272, 350+i);
      l2x1=322;
      l2x2 = 362;
      l2y=200+i;
      l3x1=412;
      l3x2 = 452;
      l3y=50+i;
      }


      delay(30);
      cleardevice();
      i+=10;
      if(i>470)
      {
        score=score+30;
        if(score==240){
            l++;
            goto level3;
        }
        i=-300;
        k++;
        if(k%2==0){
        pattern1= false;
        pattern2 =true;
        pattern3=false;
        }
        else if(k%3==0){
        pattern1 = false;
        pattern2 =false;
        pattern3= true;
        }
        else{
        pattern1 = true;
        pattern2 = false;
        pattern3 = false;
        }
        }

       if(kbhit())
       {
       ch=getch();
        if(ch==77){
        if(x<=399)
        x+=80;
        }
      if(ch==75){
        if(x>=241)

        x-=80;
           }
       }
     collision();
    if(cl==1){
     cl=0;
     sndPlaySound("sound3.wav", SND_FILENAME | SND_ASYNC );
    goto gameover;
    }

       }
level3:

    cleardevice();
    //blocks
    i=-300;
    k=1;
    while(1)
    {
          setcolor(5);
          settextstyle(3,0,3);
          char ar[100];
          char ar1[100];
          sprintf(ar,"SCORE: %d",score);
          outtextxy(20,20,ar);
          sprintf(ar1,"LEVEL: %d",l);
          outtextxy(20,50,ar1);
         road();
          car();

        setcolor(13);
      if(pattern1){
       setlinestyle(15, 8, 30);
      line(232,50+i, 272, 50+i);
      setlinestyle(15, 8, 30);
      line(322,200+i, 362, 200+i);
       setlinestyle(15, 8, 30);
      line(412,50+i, 452, 50+i);
      l1x1 = 232;
      l1x2 = 272;
      l1y=50+i;
      l2x1=322;
      l2x2 = 362;
      l2y=200+i;
      l3x1=412;
      l3x2 = 452;
      l3y=50+i;

      }
      if(pattern2)
      {
      setlinestyle(15, 8, 30);
      line(232,50+i, 272, 50+i);
      setlinestyle(15, 8, 30);
      line(322,200+i, 362, 200+i);
       setlinestyle(15, 8, 30);
      line(412,350+i, 452, 350+i);
      l1x1 = 232;
      l1x2 = 272;
      l1y=50+i;
      l2x1=322;
      l2x2 = 362;
      l2y=200+i;
      l4x1 = 412;
      l4x2 = 452;
      l4y = 350 + i;


      }
      if(pattern3){
             setlinestyle(15, 8, 30);
      line(412,50+i, 452, 50+i);
       setlinestyle(15, 8, 30);
      line(322,200+i, 362, 200+i);
         setlinestyle(15, 8, 30);
      line(232,350+i, 272, 350+i);
      l2x1=322;
      l2x2 = 362;
      l2y=200+i;
      l3x1=412;
      l3x2 = 452;
      l3y=50+i;
      }


      delay(25);
      cleardevice();
      i+=10;
      if(i>470)
      {
        score=score+30;
        if(score==450){
            l++;
            goto level4;
        }
        i=-300;
        k++;
        if(k%2==0){
        pattern1= false;
        pattern2 =true;
        pattern3=false;
        }
        else if(k%3==0){
        pattern1 = false;
        pattern2 =false;
        pattern3= true;
        }
        else{
        pattern1 = true;
        pattern2 = false;
        pattern3 = false;
        }
        }

       if(kbhit())
       {
       ch=getch();
        if(ch==77){
        if(x<=399)
        x+=80;
        }
      if(ch==75){
        if(x>=241)

        x-=80;
           }
       }
     collision();
    if(cl==1){
     cl=0;
     sndPlaySound("sound3.wav", SND_FILENAME | SND_ASYNC );
    goto gameover;
    }

       }

level4:

    cleardevice();
    //blocks
    i=-300;
    k=1;
    while(1)
    {
          setcolor(12);
          settextstyle(3,0,3);
          char ar[100];
          char ar1[100];
          sprintf(ar,"SCORE: %d",score);
          outtextxy(20,20,ar);
          sprintf(ar1,"LEVEL: %d",l);
          outtextxy(20,50,ar1);
         road();
          car();

        setcolor(4);
      if(pattern1){
       setlinestyle(15, 8, 30);
      line(232,50+i, 272, 50+i);
      setlinestyle(15, 8, 30);
      line(322,250+i, 362, 250+i);
       setlinestyle(15, 8, 30);
      line(412,50+i, 452, 50+i);
      l1x1 = 232;
      l1x2 = 272;
      l1y=50+i;
      l2x1=322;
      l2x2 = 362;
      l2y=250+i;
      l3x1=412;
      l3x2 = 452;
      l3y=50+i;

      }
      if(pattern2)
      {
      setlinestyle(15, 8, 30);
      line(232,50+i, 272, 50+i);
      setlinestyle(15, 8, 30);
      line(322,250+i, 362, 250+i);
       setlinestyle(15, 8, 30);
      line(412,400+i, 452, 400+i);
      l1x1 = 232;
      l1x2 = 272;
      l1y=50+i;
      l2x1=322;
      l2x2 = 362;
      l2y=250+i;
      l4x1 = 412;
      l4x2 = 452;
      l4y = 400 + i;


      }
      if(pattern3){
             setlinestyle(15, 8, 30);
      line(412,50+i, 452, 50+i);
       setlinestyle(15, 8, 30);
      line(322,250+i, 362, 250+i);
         setlinestyle(15, 8, 30);
      line(232,400+i, 272, 400+i);
      l2x1=322;
      l2x2 = 362;
      l2y=250+i;
      l3x1=412;
      l3x2 = 452;
      l3y=50+i;
      }


      delay(16);
      cleardevice();
      i+=10;
      if(i>470)
      {
        score=score+30;
        if(score==1500){
            l++;
            goto level5;
        }
        i=-300;
        k++;
        if(k%2==0){
        pattern1= false;
        pattern2 =true;
        pattern3=false;
        }
        else if(k%3==0){
        pattern1 = false;
        pattern2 =false;
        pattern3= true;
        }
        else{
        pattern1 = true;
        pattern2 = false;
        pattern3 = false;
        }
        }

       if(kbhit())
       {
       ch=getch();
        if(ch==77){
        if(x<=399)
        x+=80;
        }
      if(ch==75){
        if(x>=241)

        x-=80;
           }
       }
     collision();
    if(cl==1){
     cl=0;
     sndPlaySound("sound3.wav", SND_FILENAME | SND_ASYNC );
    goto gameover;
    }

       }

level5:

    cleardevice();
    //blocks
    i=-300;
    k=1;
    while(1)
    {
          setcolor(14);
          settextstyle(3,0,3);
          char ar[100];
          char ar1[100];
          sprintf(ar,"SCORE: %d",score);
          outtextxy(20,20,ar);
          sprintf(ar1,"LEVEL: %d",l);
          outtextxy(20,50,ar1);
         road();
          car();

        setcolor(14);
     if(pattern1){
       setlinestyle(15, 8, 30);
      line(232,50+i, 272, 50+i);
      setlinestyle(15, 8, 30);
      line(322,250+i, 362, 250+i);
       setlinestyle(15, 8, 30);
      line(412,50+i, 452, 50+i);
      l1x1 = 232;
      l1x2 = 272;
      l1y=50+i;
      l2x1=322;
      l2x2 = 362;
      l2y=250+i;
      l3x1=412;
      l3x2 = 452;
      l3y=50+i;

      }
      if(pattern2)
      {
      setlinestyle(15, 8, 30);
      line(232,50+i, 272, 50+i);
      setlinestyle(15, 8, 30);
      line(322,250+i, 362, 250+i);
       setlinestyle(15, 8, 30);
      line(412,400+i, 452, 400+i);
      l1x1 = 232;
      l1x2 = 272;
      l1y=50+i;
      l2x1=322;
      l2x2 = 362;
      l2y=250+i;
      l4x1 = 412;
      l4x2 = 452;
      l4y = 400 + i;


      }
      if(pattern3){
             setlinestyle(15, 8, 30);
      line(412,50+i, 452, 50+i);
       setlinestyle(15, 8, 30);
      line(322,250+i, 362, 250+i);
         setlinestyle(15, 8, 30);
      line(232,400+i, 272, 400+i);
      l2x1=322;
      l2x2 = 362;
      l2y=250+i;
      l3x1=412;
      l3x2 = 452;
      l3y=50+i;
      }


      delay(13);
      cleardevice();
      i+=10;
      if(i>470)
      {
        score=score+30;
        if(score==3000){
            l++;
            goto level1;
        }
        i=-300;
        k++;
        if(k%2==0){
        pattern1= false;
        pattern2 =true;
        pattern3=false;
        }
        else if(k%3==0){
        pattern1 = false;
        pattern2 =false;
        pattern3= true;
        }
        else{
        pattern1 = true;
        pattern2 = false;
        pattern3 = false;
        }
        }

       if(kbhit())
       {
       ch=getch();
        if(ch==77){
        if(x<=399)
        x+=80;
        }
      if(ch==75){
        if(x>=241)

        x-=80;
           }
       }
     collision();
    if(cl==1){
     cl=0;
     sndPlaySound("sound3.wav", SND_FILENAME | SND_ASYNC );
    goto gameover;
    }
    }


    gameover:
    {

        cleardevice();
                char c;
                score=0;
                while(1)
                {
                //start screen

                setcolor(rand()%9+1);
                settextstyle(6,0,8);
                outtextxy(130,80,"GAME");
                setcolor(rand()%9+1);
                settextstyle(6,0,8);
                outtextxy(130,200,"OVER");
                setcolor(WHITE);
                settextstyle(4,0,1);
                outtextxy(20,350," PRESS ENTER TO GO TO MAIN MENU");

                if(kbhit())
                {
                c=getch();
                    if(c==13)
                        goto mainmenu;
                }
            }
    }

    getch();
    closegraph();
    return 0;
}


void road()
{
    //road
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    rectangle(180,0,200,475);
    floodfill(190,50,WHITE);
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    rectangle(500,0,520,475);
    floodfill(501,50,WHITE);

    //

}
void car()
{
   //car1
 //body
   setcolor(carcl);
   setfillstyle(SOLID_FILL,carcl);
   bar(x,370,x+50,450);
//window
   setcolor(0);
   setfillstyle(SOLID_FILL,0);
    bar(x+5,395,x+45,430);
//roof
    setcolor(carcl);
   setfillstyle(SOLID_FILL,carcl);
   bar(x+10,405,x+40,420);
//danda
   setlinestyle(15, 8, 5);
   line(x+5,395,x+10,405);
   line(x+45,395,x+40,405);
   line(x+45,430,x+40,420);
   line(x+5,430,x+10,420);
   //lights
   //front left
   setcolor(15);
   setfillstyle(SOLID_FILL,15);
   bar(x+10,368,x+20,375);
   //front right
   setcolor(15);
   setfillstyle(SOLID_FILL,15);
   bar(x+30,368,x+40,375);
   //rear right
   setcolor(4);
   setfillstyle(SOLID_FILL,4);
   bar(x+30,448,x+40,455);
    //rear left
   setcolor(4);
   setfillstyle(SOLID_FILL,4);
   bar(x+10,448,x+20,455);




   car_x1=x;
   car_x2=x+50;
   car_y1=370;
   car_y2=450;

}
void collision()
{

if(((l1x1 >= car_x1 && l1x1 <= car_x2) || (l1x2 >= car_x1 && l1x2 <= car_x2)) && (l1y >= car_y1 && l1y <= car_y2))
{
    cl=1;

}
else if(((l2x1 >= car_x1 && l2x1 <= car_x2) || (l2x2 >= car_x1 && l2x2 <= car_x2)) && (l2y >= car_y1 && l2y <= car_y2))
{
     cl=1;
}
else if(((l3x1 >= car_x1 && l3x1 <= car_x2) || (l3x2 >= car_x1 && l3x2 <= car_x2)) && (l3y >= car_y1 && l3y <= car_y2))
{
     cl=1;
}
else if(((l4x1 >= car_x1 && l4x1 <= car_x2) || (l4x2 >= car_x1 && l4x2 <= car_x2)) && (l4y >= car_y1 && l4y <= car_y2))
{
     cl=1;
}

}
