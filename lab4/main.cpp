#include "graphics.h"
#include "control.h"
#include "task.h"


int main()
{
   initwindow(WIDTH, HIEGHT, "abs");
   IMAGE *back;
   back = loadBMP("vitrazh-1.bmp");
   putimage(0, 0, back, COPY_PUT);

   create_control(GEHERAT,   FRAMESIDE, HIEGHT-FRAMELOWER);
   create_control(SOLVE,  3*WIDTH/5, HIEGHT-FRAMELOWER);
   create_control_S(SAVE, WIDTH-2*FRAMELOWER, HIEGHT-FRAMELOWER);
   create_control_S(EXIT, WIDTH-FRAMELOWER, HIEGHT-FRAMELOWER);

   while (true)
   {
      while (mousebuttons() != 1);
      switch (select_control())
      {
      case NONE:
         break;
      case GEHERAT:
         generation();
         break;
      case SOLVE:
         repainting();
         break;
      case SAVE:
         save();
         break;
      case EXIT:
         closegraph();
         return 0;
      }
   }
}