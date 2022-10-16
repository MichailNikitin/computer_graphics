#define _USE_MATH_DEFINES 
#include <cmath>
#include "graphics.h"
#include "task.h"
#include "cstdlib"
#include "ctime"

using namespace std;
bool drawed=false;

void cycle(int x0, int y0, int R) {
   int color=COLOR_MAX ;

   int x=0;
   int y=R;
   int p=3-2*R;

   while (x<=y) {

      putpixel(x0 + x, y0 + y,color);
      putpixel(x0 + x, y0 - y,color);
      putpixel(x0 - x, y0 + y,color);
      putpixel(x0 - x, y0 - y,color);
      putpixel(x0 + y, y0 + x,color);
      putpixel(x0 + y, y0 - x,color);
      putpixel(x0 - y, y0 + x,color);
      putpixel(x0 - y, y0 - x,color);

      if (p>0) {
         p+=4*(x-y)+10;
         y--;
      }
      else {
         p+=4*x+6;
      }
      x++;
   }
}

void makeColors(int x0,int y0) {
   int x,y;
   double df=M_PI/6, da=df/2;

   int color[7];
   int R1[3]= {30,180,280};
   int R2[4]= {30,110,160,250};
   for (int i=0; i<7; i++)
      color[i]=rand()%WHITE;
   for (int i=0; i<3; i++) {
      setfillstyle(SOLID_FILL,color[i]);
      for (int j=0; j<12; j++) {
         x=x0+R1[i]*cos(j*df);
         y=y0+R1[i]*sin(j*df);
         floodfill(x,y,COLOR_MAX);
      }
   }
   for (int i=0; i<4; i++) {
      setfillstyle(SOLID_FILL,color[3+i]);
      for (int j=0; j<12; j++) {
         x=x0+R2[i]*cos(j*df+da);
         y=y0+R2[i]*sin(j*df+da);
         floodfill(x,y,COLOR_MAX);
      }
   }
}


void cycles(int x0, int y0, int R) {
   cycle(x0,y0,R);

   for (int i=1; i<=12; i++)
      cycle(x0+R*cos((M_PI/6)*i), y0+R*sin((M_PI/6)*i),  R);
}

void generation(){
   cycles(WIDTH,350,150);
   drawed=true;
}
void repainting() {
   if (!drawed) return;
      while (mousebuttons()!=0);
   
      makeColors(400,350);
   
}

void save()
{
   int width, height;
   IMAGE *output;

   width  = getmaxx() + 1;
   height = getmaxy() + 1;
   output = createimage(width, height);

   getimage(0, 0, width - 1, height - 1, output);
   saveBMP("output.bmp", output);
   freeimage(output);
}