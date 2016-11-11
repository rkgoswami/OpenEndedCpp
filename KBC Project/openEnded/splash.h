#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<dos.h>
#include<iostream>


void graphic(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "C:\\TC\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");

      getch();
      exit(1); /* terminate with an error code */
   }
}
int car()
{
    graphic();
    int k=0;
   setcolor(getmaxcolor());
   for(int i=0;i<380;++i)
   {
        setcolor(k);
       if(k>14)
        k=1;
        k++;
    rectangle(5,5,630,470);
    rectangle(8,8,627,467);
  // back portion of car
    line(64+i,206,136+i,206);
    line(16+i,206,0+i,200);
    line(0+i,200,0+i,170);
  //wheel 1
    arc(40+i,200,-10,190,24);  // cover of wheel 1
    circle(40+i,200,20);  // outer circle wheel 1

    arc(40+i,200,0+i,30+i,16);
    arc(40+i,200,60+i,90+i,16);
    arc(40+i,200,120+i,150+i,16);
    arc(40+i,200,180+i,210+i,16);
    arc(40+i,200,240+i,270+i,16);
    arc(40+i,200,300+i,330+i,16);
    circle(40+i,200,2);   // dot at center of wheel 1
  //wheel 2
    arc(160+i,200,-10,190,24); // cover of wheel 2
    circle(160+i,200,20); // wheel 2

    arc(160+i,200,0+i,30+i,16);
    arc(160+i,200,60+i,90+i,16);
    arc(160+i,200,120+i,150+i,16);
    arc(160+i,200,180+i,210+i,16);
    arc(160+i,200,240+i,270+i,16);
    arc(160+i,200,300+i,330+i,16);
    circle(160+i,200,2);  // dot at center of wheel 2
  // base line
    line(0,220,630,220);
  // middle design
    line(0+i,170,160+i,170);
  // top portion of car
    line(0+i,170,70+i,140); //slant line
    line(70+i,140,70+i,206); //vertical line
    line(70+i,140,120+i,140); // horizontal top roof
    line(120+i,140,160+i,170); //front slant glass
    line(120+i,140,120+i,206); //vertical line 2
    line(160+i,170,215+i,180); // front bonet
  //front portion of car
    line(184+i,206,215+i,206);
    line(215+i,206,215+i,180);

    settextstyle(6,0,1);
    outtextxy(20,50,"*********** OPEN ENDED PROJECT ***********");
    outtextxy(260,75,"ON");
    outtextxy(20,100,"********* KAUN BANEGA CROREPATI *********");
    outtextxy(290,350,"BY- ");
    outtextxy(290,370,"RISHAV  KUMAR  GOSWAMI");
    outtextxy(290,390,"1SI13CS135");
    outtextxy(290,410,"HIMANSHU  RNAJAN");
    outtextxy(290,430,"1SI13CS142");
    delay(5);
    cleardevice();
    }

   closegraph();

   return 0;
   }


