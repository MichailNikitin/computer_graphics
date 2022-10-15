#include <math.h>
#include "graphics.h"
#include "task.h"
#include "control.h"
#include "cstdlib"
#include "ctime"
#define M_PI 3.141592

void drawLine(int x1,int y1)
{
   int x0 = getx(), y0 = gety();
   int sx, sy, dx, dy, p;
   
   sx = x0 > x1 ? -1 : 1;
   sy = y0 > y1 ? -1 : 1;
   dx = abs(x1 - x0);
   dy = abs(y1 - y0);

   if (dx >= dy)
   {
      p = 2 * dy - dx;
      for (int i = x0; i != x1; i += sx)
      {
         putpixel(i, y0, getcolor());
         y0 = p > 0 ? y0 + sy : y0;
         p = p > 0 ? p + 2 * (dy - dx) : p + 2 * dy;
      }
   }
   else
   {
      p = 2 * dx - dy;
      for (int i= y0; i != y1; i += sy)
      {
         putpixel(x0, i, getcolor());
         x0 = p > 0 ? x0 + sx : x0;
         p = p > 0 ? p + 2 * (dx - dy) : p + 2 * dx;
      }
   }
    putpixel(x1, y1, getcolor());
}

void drawStar(int x0, int y0, int R, int n)
{
   setcolor(RED);
    double r = (R * cos(2 * M_PI / n)) / cos(M_PI / n);
    double da = M_PI / n;
    
    for (int k = 0; k < 2 * n + 1; k++)
    {
        int l = k % 2 == 0 ? R : r;
        double x = (x0 + l * cos(k * da));
        double y = (y0 + l * sin(k * da));
        if (k == 0) moveto(x, y);
        drawLine(x, y);
        moveto(x, y);
    }
   delay(10);
   floodfill(x0, y0, getcolor());
}

void create(int R, int n)
{
   
   srand(time(0));
   int x, y;
   int count_demons = rand() % (n-2) + 2;
   for (int i = 0; i < count_demons; i++)
   {
      x = rand() % (600 - 100 + 1) + 100;
      y = rand() % (400 - 80 + 1) + 80;
      drawStar(x, y, R, n);
   }
}

void clear()
{
  putimage(0, 0, loadBMP("dizayn-7.bmp"), COPY_PUT);
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