#include "graphics.h"
#include "control.h"

Control controls[N_CONTROLS];

void create_control(int i, int left, int top) {
   
   controls[i].left = left;
   controls[i].top = top;
   controls[i].right = left + 80;
   controls[i].bottom = top  + 60;
}

int select_control() {
   int x, y;
   
   x = mousex();
   y = mousey();
   
   for (int i = 0; i < N_CONTROLS; i++) {
      if (x > controls[i].left && x < controls[i].right &&
          y > controls[i].top  && y < controls[i].bottom) {
         return i;
      }
   }
   return NONE;
}

void save()
{
   IMAGE *output;
   output = createimage(WIDTH, HIEGHT);

   getimage(0, 0, WIDTH - 1, HIEGHT - 1, output);
   getimage(0, 0, WIDTH - 1, HIEGHT - 1, output);
   saveBMP("output.bmp", output);
   freeimage(output);
}