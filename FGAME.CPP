#include<fstream.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


void track()
{
    setbkcolor(34);
    setcolor(1);
    line(150,90,450,90);
    line(150,140,450,140);
    line(150,190,450,190);
    line(150,290,450,290);
    line(150,340,450,340);
    line(150,390,450,390);
    setfillstyle(SOLID_FILL,RED);
    setcolor(BLUE);
    rectangle(150,190,450,290);
    floodfill(200,250,1);
    arc(150,240,90,270,50);
    arc(150,240,90,270,100);
    arc(150,240,90,270,150);
    arc(450,240,270,90,50);
    arc(450,240,270,90,100);
    arc(450,240,270,90,150);
    circle(150,315,15);
    circle(150,365,15);
    circle(450,115,15);
    circle(450,315,15);
    circle(450,365,15);
    circle(450,115,15);
    circle(150,115,15);
    circle(150,165,15);
    circle(450,165,15);
}
void hero(int i,int j, int r)     //the user moves the circle
{
    setcolor(4);
    circle(i,j,r);
    setcolor(0);
    circle(i-1,j,5);
    setcolor(4);

}
void en1(int a, int b, int c)   //displays enemy 1
{
       setcolor(63);
       circle(a,b,c);
       setcolor(0);
       circle(a+1,b,c);
       setcolor(63);
}
void en2(int h,int k,int l)
{
       setcolor(63);
       circle(h,k,l);
       setcolor(0);
       circle(h+1,k,l);
       setcolor(63);
}
void hdelay(int lap)
{
	 if(lap>=0 && lap<4)
	 delay(3);
	 if(lap>=4 && lap<7)
	 delay(2);
	 if(lap>=7 && lap<9)
	 delay(1);
	 if(lap>9)
	 delay(0);
}



class player
{
  char name[20];

  public:
    int lap;

    int rtnl()
    {
       return lap;
    }
    void input()
    {
       cout<<"\n\n\n\n\n\n\n                    Enter name :";
       gets(name);
    }
    char *rtnname()
    {
       return name;
    }
    void output()
    {
       cout<<name<<"\t\t"<<lap<<endl;
    }
};

void hidc(int z)
{
if(z==0)
{   fstream f;
   cleardevice();
   player s1[80],t;int i=0;
   rectangle(400,390,470,450);
   outtextxy(405,400,"back");
   settextstyle(0,0,3);
   outtextxy(400,200,"Highscores");
   settextstyle(0,0,1);
   outtextxy(400,230,"Number of laps");
   f.open("final.dat",ios::in|ios::out|ios::app);
   while(f.read((char*)&s1[i],sizeof(s1[i])))
   {
     i++;
   };
   for(int x=0; x<i; x++)
     for(int y=0;y<i-x-1;y++)
     {
       if(s1[y].lap<s1[y+1].lap)
       {
	  t=s1[y];
	  s1[y]=s1[y+1];
	  s1[y+1]=t;
       }
     }
   for(x=0;x<i;x++)
   s1[x].output();

}
else
{   fstream f;
   cleardevice();
   player s1[80],t;int i=0;
   settextstyle(0,0,3);
   outtextxy(400,200,"Highscores");
   settextstyle(0,0,1);
   outtextxy(400,230,"Number of laps");
   f.open("final.dat",ios::in|ios::out|ios::app);
   while(f.read((char*)&s1[i],sizeof(s1[i])))
   {
     i++;
   };
   for(int x=0; x<i; x++)
     for(int y=0;y<i-x-1;y++)
     {
       if(s1[y].lap<s1[y+1].lap)
       {
	  t=s1[y];
	  s1[y]=s1[y+1];
	  s1[y+1]=t;
       }
     }
   for(x=0;x<i;x++)
   s1[x].output();
   getch();
   cleardevice();
}
}
void newgame()
{

player s;
s.input();
fstream f;
  f.open("final.dat",ios::in|ios::out|ios::app);


		      int i=298,j=315,x=0,y=0,ch;
		      int a=315,b=365,h=300,k=365;
		      int xe=0,ye=0,lap=0,sp[4],d;


     int gd=DETECT,gm;
     initgraph(&gd,&gm,"c:\\turboc3\\bgi");


     setcolor(RED);
     settextstyle(SANS_SERIF_FONT,0,7);
     outtextxy(5,5,"Do Not Crash");

     track();
     lap=0;

while(1)
{    hero(i,j,5);
     en1(a,b,5);
     en2(h,k,5);


if(kbhit())                          //check if a key is pressed
{
ch=getch();
		 if(ch==72 && j==365)               //to switch tracks also to replace the previous frame
		 {   j-=50;
		     setcolor(0);
		     circle(i,j+50,5);
		     setcolor(63);
		 }
		 else if (ch==72 && j==165)
		 {   j-=50;
		     setcolor(0);
		     circle(i,j+50,5);
		     setcolor(63);
		 }
		 else if (ch==80 && j==115)
		 {   j+=50;
		     setcolor(0);
		     circle(i,j-50,5);
		     setcolor(63);
		 }
		 else if (ch==80 && j==315)
		 {   j+=50;
		     setcolor(0);
		     circle(i,j-50,5);
		     setcolor(63);
		 }
		 else if (ch==80 && j==365)    //exits if you press arrow key which makes the circle move out of the tracks
		     {cleardevice();goto g;}
		 else if (ch==72 && j==115)
		     {cleardevice();goto g;}




		 if(ch==77)                           //move right continuously
		 {
		   x=1;
		   y=0;
		   xe=-1;
		   ye=0;
		 }


		 if(ch==27)                           //exit when esc pressed
		 exit(0);
}

   i=i+x;
   j=j+y;
   a=a+xe;  // X Coordinate of Enemy 1
   b=b+ye;  // Y Coordinate of Enemy 1
   h=h+xe;  // X Coordinate of Enemy 2
   k=k+ye;  // Y Coordinate of Enemy 2

   if(i==450 && j==365)      //Portal Entry of Hero Circle
   {i=150;j=115;}
   if(i==450 && j==115)
   {i=150;j=365;}
   if(i==450 && j==165)
   {i=150;j=315;}
   if(i==450  &&j==315)
   {i=150;j=165;}

   if(a==150 && b==365)      //Portal Entry of Enemy 1
   {a=450;b=115;cleardevice();track();}
   if(a==150 && b==315)
   {a=450;b=165;cleardevice();track();}
   if(a==150 && b==115)
   {a=450;b=365;cleardevice();track();}
   if(a==150 && b==165)
   {a=450;b=315;cleardevice();track();}

    randomize();         //Randomises the position tof the enemy
    int l[4];
    l[0]=365;
    l[1]=315;
    l[2]=115;
    l[3]=165;
    b=l[random(4)];




   if(h==150 && k==365)      //Portal Entry of Enemy 2
   {h=450;k=115;cleardevice();track();}
   if(h==150 && k==315)
   {h=450;k=165;cleardevice();track();}
   if(h==150 && k==115)
   {h=450;k=365;cleardevice();track();}
   if(h==150 && k==165)
   {h=450;k=315;cleardevice();track();}



   if(i==300 && j>=315)
   {++lap;cleardevice();track();}

   if(i+5== a-5 && j==b )
   { cleardevice(); goto g; }
   else if(i+5== h-5 && j==k)
   { cleardevice(); goto g; }


     hdelay(lap);
     char li[50];;
     settextstyle(SANS_SERIF_FONT,0,1);
     outtextxy(200,250,"No of laps completed :");

     sprintf(li,"%d",lap);
     outtextxy(400,250,li);




}
g:
       setfillstyle(SOLID_FILL, 0);
       s.lap=lap;
       cout<<s.lap;
       f.write((char*)&s,sizeof(s));
       f.close();
       floodfill(1,1,0);
       setcolor(YELLOW);
       settextstyle(0,0,7);
       outtextxy(80,50,"Game Over");
       settextstyle(0,0,6);
       outtextxy(70,175,"You Crashed");
       getch();
       cleardevice();
       hidc(1);


}