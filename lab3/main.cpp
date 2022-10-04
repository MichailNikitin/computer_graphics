#include "graphics.h"
#include "control.h"
#include "task.h"


int main()
{
   initwindow(1000, 700);
    IMAGE *back;
    back = loadBMP("arena.bmp");
    putimage(0, 0, back, COPY_PUT);
   
   create_control(GEHERAT,   60, 620);
   create_control(SOLVE,  370, 620);
   create_control_2(SAVE, 740, 620);
   create_control_2(EXIT, 900, 620);
   
   int left = 0, top = 0, width = 1000, height =700;
   
   while (true)
   {
      while (mousebuttons() != 1);
      switch (select_control())
      {
         case NONE: break;
         case GEHERAT: generation(left, top, width, height); break;
         case SOLVE: solve(left, top, width, height); break;
         case SAVE: save(); break;
         case EXIT: closegraph(); return 0;
      }
   }
}