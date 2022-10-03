#include <math.h>
#include "graphics.h"
#include "task.h"

void fill_1(int left, int top, int width, int height)
{
   double x, y;
   int c;

   for (x = 0; x < width; x++)
   {
      for (y = 0; y < height; y++)
      {
         c = y / height * COLOR_MAX;
         putpixel(left + x, top + y, COLOR(0, c / 2, c));
      }
   }

}

void fill_2(int left, int top, int width, int height)
{
   double x, y;
   int c;

   for (x = 0; x < width; x++)
   {
      for (y = 0; y < height; y++)
      {
         c = x / width * COLOR_MAX;
         putpixel(left + x, top + y, COLOR(0, c / 2, c));
      }
   }

}

void fill_3(int left, int top, int width, int height)
{
   double x, y;
   int c;

   for (x = 0; x < width; x++)
   {
      for (y = 0; y < height; y++)
      {
         c = (1 - fabs(2*y/height - 1)) * COLOR_MAX;
         putpixel(left + x, top + y, COLOR(0, c / 2, c));
      }
   }

}

void fill_4(int left, int top, int width, int height)
{
   double x, y;
   int c;

   for (x = 0; x < width; x++)
   {
      for (y = 0; y < height; y++)
      {
         c = fabs(1 - x / width - y / height) * COLOR_MAX;
         putpixel(left + x, top + y, COLOR(0, c / 2, c));
      }
   }

}

void fill_5(int left, int top, int width, int height)
{
   double x, y;
   int c;

   for (x = 0; x < width; x++)
   {
      for (y = 0; y < height; y++)
      {
         c = (1 - fabs((1 - 2*fabs(x / width - y / height)) )) 
         * COLOR_MAX;
         putpixel(left + x, top + y, COLOR(0, c / 2, c));
      }
   }

}

void fill_6(int left, int top, int width, int height)
{
   double x, y;
   int c;

   for (x = 0; x < width; x++)
   {
      for (y = 0; y < height; y++)
      {
         c = (1 - (fabs(2*x/width -1) + fabs(2*y/width - 1))) * COLOR_MAX;
         c = (c < 0) ? 0 : c;
         putpixel(left + x, top + y, COLOR(0, c / 2, c));
      }
   }

}


void fill_7(int left, int top, int width, int height)
{
   double x, y, d, r;
   int c;

   r = (width > height ? height : width) / 2;

   for (x = 0; x < width; x++)
   {
      for (y = 0; y < height; y++)
      {
         d = sqrt((x - width / 2) * (x - width / 2) +
                  (y - height / 2) * (y - height / 2)) / r;
         c = d < 1 ? (1 - d) * COLOR_MAX : 0;
         putpixel(left + x, top + y, COLOR(0, c / 2, c));
      }
   }
}

void fill_8(int left, int top, int width, int height)
{
   double x, y, d, r;
   int c;

   r = (width > height ? height : width) / 2;

   for (x = 0; x < width; x++)
   {
      for (y = 0; y < height; y++)
      {
         d = sqrt((x - width / 2) * (x - width / 2) +
                  (y - height / 2) * (y - height / 2)) / r;
         c = fabs(1 - d) * COLOR_MAX;
         putpixel(left + x, top + y, COLOR(0, c / 2, c));
      }
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