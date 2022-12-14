#include "graphics.h"
#include "control.h"
#include "figure.hpp"



int main() {
   initwindow(WIDTH, HIEGHT);
   clearviewport(); 
   

   create_control (MOVEZ, 80, 490);
   create_control (MOVEX, 220, 490);
   create_control (MOVEY, 360, 490);
   create_control (TURNXY, 500, 490);
   create_control (TURNXZ, 640, 490);
   create_control (TURNYZ, 780, 490);
      create_control (SAVE, 940, 490);
   create_control (EXIT, 1060, 490);
   
   putimage(0, 0, loadBMP("hologram.bmp"), COPY_PUT);
   
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

