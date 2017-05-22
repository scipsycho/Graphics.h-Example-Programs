#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define DELAY 10
#define RAD 20
int draw(int,int,int xr,int yr,int w);
void initAndBackground();
int main()
{
	initAndBackground();
	int rx=RAD;
	int mx=getmaxx()/2;

	while(!kbhit())
	{
		for(;rx>=0;rx--)
		{
			draw(mx,RAD+1,rx,RAD,4);
		}
		for(;rx<=RAD;rx++)
		{
			draw(mx,RAD+1,rx,RAD,4);
		}
	}
	getch();
	closegraph();
return 0;
}
void initAndBackground()
{
	int gd=DETECT,md;
	initgraph(&gd,&md,"\\TC\\BGI");
	int mx=getmaxx()/2;
	int my=getmaxy()/2;
	setfillstyle(XHATCH_FILL,BROWN);
	bar(0,3*my/2,2*mx,2*my);
	setcolor(BROWN);
	setlinestyle(SOLID_LINE,0,3);
	line(0,3*my/2-1,2*mx,3*my/2-1);
	setlinestyle(SOLID_LINE,0,1);
	setviewport(0,(3*my/2-2*RAD-4),2*mx,(3*my/2-2),0);

}

int draw(int x,int y,int xr,int yr,int w)
{
 setfillstyle(SOLID_FILL,LIGHTGRAY);
 fillellipse(x,y,xr,yr);
 setcolor(DARKGRAY);
 ellipse(x,y,0,360,xr-w,yr-w);
 delay(DELAY);
 clearviewport();
 return 0;
}