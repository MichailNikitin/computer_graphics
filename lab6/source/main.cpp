#include "graphics.h"
#include "control.h"
#include "figura.hpp"


int main()
{
   initwindow(WIDTH, HIEGHT, "BrutalMagica");
   putimage(0, 0, loadBMP("BrutalMagica.bmp"), COPY_PUT);
   create_control_S(CCWROT,  FRAMESIDE, FRAMELOWER);
   create_control_S(CWROT, INDENT+3*FRAMESIDE,
                    FRAMELOWER);
   create_control(MOVE,  SIZEBUTTONB - 2*INDENT,
                  FRAMELOWER);
   create_control(SCALE,  2*SIZEBUTTONB,
                  FRAMELOWER);
   create_control_S(SAVE, WIDTH - SIZEBUTTONB+ FRAMESIDE,
                    FRAMELOWER);
   create_control_S(EXIT, WIDTH-3*FRAMESIDE+INDENT,
                    FRAMELOWER);
   int type = TNONE;

   Figura figura;

   while (true)
   {
      while (mousebuttons() != 1) {}
         switch (select_control()) {
         case NONE:
            break;
         case CCWROT:
            figura.rotate(-1);
            type = TNONE;
            break;
         case CWROT:
            figura.rotate(1);
            type = TNONE;
            break;
         case SCALE:
            type = TSCALE;
            break;
         case MOVE:
            type = TMOVE;
            break;
         case SAVE:
            save();
            type = TNONE;
            break;
         case EXIT:
            return 0;
         }
         switch (type) {
         case TMOVE:
            switch (getch(kbhit())) {
            case TNONE:
               break;
            case KEY_UP:
               figura.move(0, 1);
               break;
            case KEY_DOWN:
               figura.move(0, -1);
               break;
            case KEY_LEFT:
               figura.move(-1, 0);
               break;
            case KEY_RIGHT:
               figura.move(1, 0);
               break;
            }
            break;
         case TSCALE:
            switch (getch(kbhit())) {
            case KEY_LEFT:
               figura.scale(1.025);
               break;
            case KEY_RIGHT:
               figura.scale(0.975);
               break;
            }
         case TNONE:
            break;
         }
      
   }
}
