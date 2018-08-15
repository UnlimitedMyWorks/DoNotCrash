#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<process.h>
#include<stdio.h>
#include"fgame.cpp"




union REGS in,out;

       int callmouse()
       {
	      in.x.ax=1;
	      int86(51,&in,&out);
	      return 1;
       }
       void mouseposi(int &xpos,int &ypos,int &click)
       {
	      in.x.ax=3;
	      int86(51,&in,&out);
	      click=out.x.bx;
	      xpos=out.x.cx;
	      ypos=out.x.dx;
	}
       int mousehide()
       {
	      in.x.ax=2;
	      int86(51,&in,&out);
	      return 1;
       }
      void setposi(int &xpos,int &ypos)
      {
	     in.x.ax=4;
	     in.x.cx=xpos;
	     in.x.dx=ypos;
	     int86(51,&in,&out);
      }



       void rules()
       {setcolor(1);
      settextstyle(TRIPLEX_FONT,0,5);
    outtextxy(120,50,"RULES");
    setcolor(4);
    settextstyle(TRIPLEX_FONT,0,2);
    outtextxy(120,120,"1. You are the hero- the red circle.");
    outtextxy(120,160,"2. You have to make sure that you don't ");
    outtextxy(120,180,"   crash into the white circles- they are your");
    outtextxy(120,200,"   villains! ");
    outtextxy(120,240,"3. Use the up and down arrow keys to change ");
    outtextxy(120,260,"   tracks");
    outtextxy(120,300,"4. You also lose if you jump out of the tracks!");
    outtextxy(120,340,"5. Now, just go on and PLAY!");
    setcolor(3);
    rectangle(400,390,453,450);
    outtextxy(405,400,"back");


    }


void main()
{
    int gdriver = DETECT,gmode,errcode;
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    int i,x,y,cl;
    f:
    cleardevice();
    setcolor(1);
    settextstyle(GOTHIC_FONT,0,7);
    outtextxy(120,50,"Do Not Crash");
    setcolor(4);
    settextstyle(GOTHIC_FONT,0,4);
    rectangle(250,200,400,250);
    outtextxy(300,200,"Play");
    rectangle(250,275,400,325);
    outtextxy(290,275,"Rules");
    rectangle(248,350,400,400);
    outtextxy(253,350,"Highscores");
    int a=100,b=400;char o;
    setposi(a,b);
    callmouse();
    do
    {
	mouseposi(x,y,cl);
	if( x>250 && x<400 && cl==1 && y>200 &&y<250)
	{ newgame();


	 }
	else if(x>250 && x<400 && cl==1 && y>275 && y<325)
	{ cleardevice();
	    rules();
	    do
	    { mouseposi(x,y,cl);
	  if( x>400 && x<450 && cl==1 && y>390 &&y<450)
	  {goto f;}
	  } while(!kbhit());}
	  if( x>250 && x<400 && cl==1 && y>350 &&y<400)
	  {cleardevice();
	  hidc(0);
	  do
	  { mouseposi(x,y,cl);
	  if( x>400 && x<450 && cl==1 && y>390 &&y<450)
	  {goto f;}

	  }while(!kbhit());}
    }while(!kbhit());
    getch();
}