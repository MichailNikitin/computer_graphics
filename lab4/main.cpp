#include "graphics.h"
#include "control.h"
#include "task.h"


int main()
{
   initwindow(WIDTH, HIEGHT);
    IMAGE *back;
    back = loadBMP("vitrazh.bmp");
    putimage(0, 0, back, COPY_PUT);
   
   create_control(GEHERAT,   60, HIEGHT-FRAMELOWER);
   create_control(SOLVE,  370, HIEGHT-FRAMELOWER);
   create_control_S(SAVE, 740, HIEGHT-FRAMELOWER);
   create_control_S(EXIT, WIDTH-3*FRAMELOWER, HIEGHT-FRAMELOWER);
   
   while (true)
   {
      while (mousebuttons() != 1);
      switch (select_control())
      {
         case NONE: break;
         case GEHERAT: generation(); break;
         case SOLVE: repainting(); break;
         case SAVE: save(); break;
         case EXIT: closegraph(); return 0;
      }
   }
}