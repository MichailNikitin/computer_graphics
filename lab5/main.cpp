#include "graphics.h"
#include "control.h"
#include "task.h"


int main()
{
   initwindow(WIDTH, HIEGHT, "ya_karta");
   putimage(0, 0, loadBMP("ya_karta_ya_karta.bmp"), COPY_PUT);
   create_control(GEHERAT,  FRAMESIDE, HIEGHT-FRAMELOWER);
   create_control(BEZIE, INDENT+SIZEBUTTONB+FRAMESIDE, HIEGHT-FRAMELOWER);
   create_control(CHAIKIN,  2*INDENT+2*SIZEBUTTONB+FRAMESIDE, HIEGHT-FRAMELOWER);
   create_control_S(SAVE, 4*INDENT+3*SIZEBUTTONB+FRAMESIDE, HIEGHT-FRAMELOWER);
   create_control_S(EXIT, 5*INDENT+3*SIZEBUTTONB+SIZEBUTTONS+FRAMESIDE, HIEGHT-FRAMELOWER);

   while (true)
   {
      while (mousebuttons() != 1)
         coords(mousex(), mousey());

      switch (select_control())
      {
      case NONE:
         break;
      case GEHERAT:
         generation();
         break;
      case BEZIE:
         bezie();
         break;
      case CHAIKIN:
         chaikin();
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