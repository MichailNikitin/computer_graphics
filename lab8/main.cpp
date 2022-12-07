#include "graphics.h"
#include "control.h"
#include "figure.hpp"



int main() {
   initwindow(500, 450);
   clearviewport();

   create_control (SAVE, 300, 400, "interface/save.bmp");
   create_control (EXIT, 400, 400, "interface/exit.bmp");
   create_control (MOVEX, 0, 400, "interface/move_x.bmp");
   create_control (MOVEY, 50, 400, "interface/move_y.bmp");
   create_control (MOVEZ, 100, 400, "interface/move_z.bmp");
   create_control (TURNXY, 150, 400, "interface/turn_xy.bmp");
   create_control (TURNXZ, 200, 400, "interface/turn_xz.bmp");
   create_control (TURNYZ, 250, 400, "interface/turn_zy.bmp");
   

   setfillstyle(1, BLACK);
   bar(0, 0, 600, 400);
   
   Figure figure;
   figure.draw();

   while (true) {
      while (mousebuttons() != 1);
      switch (select_control()) {
         case NONE: break;
         case MOVEX : figure.Move(0); figure.draw(); break;
         case MOVEY : figure.Move(1); figure.draw(); break;
         case MOVEZ : figure.Move(2); figure.draw(); break;
         case TURNXY: figure.Rotate(0); figure.draw(); break;
         case TURNXZ: figure.Rotate(1); figure.draw(); break;
         case TURNYZ: figure.Rotate(2); figure.draw(); break;
         case SAVE: save(); break;
         case EXIT: closegraph(); return 0;
      }
      
      delay(50);
   }
}

