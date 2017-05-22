#include <graphics.h>
#include <iostream.h>
#include <dos.h>
#include <conio.h>
#define RAD 20
#define DELAY 10
#define ACCEL 0.1

void draw(int,int,int,int);
int main()
{
	float fs=0;
	int gd=DETECT,md;
	initgraph(&gd,&md,"//TC//BGI");

	int mx=getmaxx()/2;
	int my=getmaxy()/2;

	int x=RAD+1;
	float y=1+RAD;
	int i;
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	setcolor(WHITE);
	line(0,3*my/2,2*mx,3*my/2);
	floodfill(2*mx,2*my,WHITE);
	setviewport(mx-RAD-1,0,mx+RAD+1,(3*my/2-1),0);
	setfillstyle(SOLID_FILL,RED);
	my=(3*my/2 -1);
	while(!kbhit())
	{
		fs=0;
		for(;y<=my-RAD;y+=int(fs)+1)
		{
			draw(x,y,RAD,RAD);
			fs+=ACCEL;
		}
		for(;y<=my-RAD/2;y+=int(fs)+1)
		{
			draw(x,y,RAD,my-y);
		      //	fs+=ACCEL;
		}
		for(;y>=my-RAD;y-=int(fs)+1)
		{
			draw(x,y,RAD,my-y);
		 //	fs-=ACCEL;
		}
		for(;y>=1+RAD;y-=int(fs)+1)
		{
			draw(x,y,RAD,dRAD);
			fs-=ACCEL;
		}
	 }
		getch();
		closegraph();
return 0;
}

void draw(int x,int y,int xr,int yr)
{
	fillellipse(x,y,xr,yr);

	delay(DELAY);
	//cleardevice();
	clearviewport();
}
