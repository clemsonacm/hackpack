#include<graphics.h>   /* for the graphics packages */
#include<time.h>        /* for the sleep() function */
#include<cmath>
#include<iostream>
using namespace std;

void floodfill(int x, int y, int newcolor,int oldcolor)
{
if (getpixel(x,y)==oldcolor)
{
putpixel(x,y,newcolor);
floodfill( x+1, y,  newcolor, oldcolor);
floodfill( x-1,  y,  newcolor, oldcolor);
floodfill( x,  y+1,  newcolor, oldcolor);
floodfill( x,  y-1,  newcolor, oldcolor);
}
}

int main()
{
int gm,gd;
gd=DETECT;
/* initialize the graphics drivers */
initgraph(&gd,&gm,” “);

int oldcolor=BLACK, newcolor=WHITE;
setcolor(newcolor);
circle(200,200,100);
floodfill(200,200,newcolor,oldcolor);

sleep(5);
closegraph();
return 0;
}
