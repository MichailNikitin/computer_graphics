#include <math.h>
#include "graphics.h"
#include "task.h"
#include "cstdlib"
#include "ctime"

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
            imageputpixel(p, x, y, BLACK);
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

struct point {
   int x;
   int y;
};

point lions[11];
int count_lion, k = 0;

void generation(int left, int top, int width, int height)
{
   k = 1;
   IMAGE *pic, *m, *back;
   pic = loadBMP("lion1min.bmp");
   back = loadBMP("arena.bmp");
   m = createmask(pic);

   putimage(0, 0, back, COPY_PUT);

   srand(time(0));
   count_lion = rand() % 6 + 2;
   for (int i = 0; i < count_lion; i++)
   {
      lions[i].x = rand() % (730 - 280 + 1) + 280;
      lions[i].y = rand() % (500 - 80 + 1) + 80;
      drawimage(lions[i].x, lions[i].y, m, pic);
   }
}

point points_max[2];
void solve(int top, int left, int width, int height)
{
   if (k == 1)
   {
      points_max[0].x=width;
      points_max[0].y=height;
      points_max[1].x= -1;
      points_max[1].y= -1;

      for (int i = 0; i < count_lion; i++)
      {
         if (lions[i].x < points_max[0].x)
            points_max[0].x = lions[i].x;
         if (lions[i].x > points_max[1].x)
            points_max[1].x = lions[i].x;
         if (lions[i].y < points_max[0].y)
            points_max[0].y = lions[i].y;
         if (lions[i].y > points_max[1].y)
            points_max[1].y = lions[i].y;
      }
      setcolor(COLOR(rand() % 255, rand() % 255, rand() % 255));
      setlinestyle(SOLID_LINE, 1, 4);
      rectangle(points_max[0].x,
         points_max[0].y,
         points_max[1].x + imagewidth(loadBMP("lion1min.bmp")),
         points_max[1].y + imageheight(loadBMP("lion1min.bmp")));
   }
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