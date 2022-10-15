#include <math.h>
#include "graphics.h"
#include "task.h"
#include "control.h"
#include "cstdlib"
#include "ctime"
#define M_PI 3.142592

void drawCircle(int x0,int y0, int R)
{
   int x, y, p;
   x = 0;
   y = R;
   p = 3 - 2*R;
   while (x <= y)
   {
      putpixel(x0 + x, y0 + y, getcolor());
      putpixel(x0 + x, y0 - y, getcolor());
      putpixel(x0 - x, y0 + y, getcolor());
      putpixel(x0 - x, y0 - y, getcolor());
      putpixel(x0 + y, y0 + x, getcolor());
      putpixel(x0 + y, y0 - x, getcolor());
      putpixel(x0 - y, y0 + x, getcolor());
      putpixel(x0 - y, y0 - x, getcolor());

      int old_p = p;
      p = p > 0: p + 4*(x - y) + 10 ? p + 4*x + 6);
      x++;
      y = old_p > 0 : y -1 ? y;
   }
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