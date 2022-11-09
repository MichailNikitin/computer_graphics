#define _USE_MATH_DEFINES
#include <cmath>
#include "graphics.h"
#include "task.h"
#include "control.h"
#include "cstdlib"
#include "ctime"
#include <format>

using namespace std;
bool drawed=false;

Point points[4];

void coords(int x, int y)
{
   string text;
   text = format("X:{} Y:{}", to_string(x), to_string(y));
   setbkcolor(COLOR(225,227,239));
   setcolor(BROWN);
   outtextxy(WIDTH-2*FRAMESIDE, 0, text.c_str());
}

IMAGE *createmask(IMAGE *p)
{
   int w = imagewidth(p);
   int h = imageheight(p);
   IMAGE *m = createimage(w, h);
   int c = imagegetpixel(p, 0, 0);
   for (int x = 0; x < w; ++x)
   {
      for (int y = 0; y < h; ++y)
      {
         int d = imagegetpixel(p, x, y);

         if (c == d)
         {
            imageputpixel(m, x, y, WHITE);
            imageputpixel(p, x, y,BLACK );
         }
         else imageputpixel(m, x, y, BLACK);
      }
   }
   return m;
}

void drawimage(int x, int y, IMAGE *m,IMAGE *p)
{
   putimage(x, y, m, AND_PUT);
   putimage(x, y, p, OR_PUT);
}

void generation() {
   IMAGE *m;
   m = createmask(loadBMP("island.bmp"));

   putimage(0, 0, loadBMP("ya_karta_ya_karta.bmp"), COPY_PUT);

   for (int i = 0; i < 4; i++) {
points[i].x = rand()%(3*(INDENT+SIZEBUTTONB)) +(INDENT+FRAMESIDE);
points[i].y = rand()%(HIEGHT-FRAMELOWER-2*FRAMESIDE) +(INDENT+FRAMESIDE);
      drawimage(points[i].x-16, points[i].y-16, m, loadBMP("island.bmp"));
   }
}

void chaikin() {
   double x, y;
   for (double t = 0.0; t<=1.0; t += 0.00001)
   {
      x = pow((1-t),3)*points[0].x+3*t*pow((1-t),2)*
points[1].x+3*t*t*(1-t)*points[2].x+pow(t,3)*points[3].x;
      y = pow((1-t),3)*points[0].y+3*t*pow((1-t),2)*
points[1].y+3*t*t*(1-t)*points[2].y+pow(t,3)*points[3].y;
      putpixel(x,y,COLOR(195,60,84));
   }
}

void bezie() {
   setcolor(COLOR(131,33,97));
   int vertex = 4, lines_num = 3;
   Point *temp, *temp2;
   temp = new Point[vertex];
   for (int i = 0; i<vertex; i++)
   {
      temp[i] = points[i];
   }
   for (int i = 0; i < 6; i++)
   {
      temp2 = new Point[2*lines_num];
      for (int j = 0, k = 0; k < lines_num; j++, k++)
      {
         temp2[j].x = temp[k].x*0.75+temp[k+1].x*0.25;
         temp2[j].y = temp[k].y*0.75+temp[k+1].y*0.25;
         ++j;
         temp2[j].x = temp[k].x*0.25+temp[k+1].x*0.75;
         temp2[j].y = temp[k].y*0.25+temp[k+1].y*0.75;
      }
      delete[] temp;
      temp = temp2;
      vertex = lines_num*2;
      lines_num = vertex-1;
   }
   temp[0] = points[0];
   temp[lines_num-1] = points[3];
   for (int i = 0; i < lines_num-1; i++)
   {
      line(temp[i].x, temp[i].y, temp[i+1].x, temp[i+1].y);
   }
   delete[] temp;
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