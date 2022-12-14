#include "graphics.h"
#include "control.h"
#include "task.h"

void putimg(int left, int top, int i) {
   IMAGE *image;

}

void draw(Figure a){
   setfillstyle(1, BLACK);
   bar(0, 0, 600, 400);
   XoY(a);

}

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
   
   Figure a = Create();
   draw(a);

   while (true) {
      while (mousebuttons() != 1);
      switch (select_control()) {
         case NONE: break;
         case MOVEX : Move(a, 0); draw(a); break;
         case MOVEY : Move(a, 1); draw(a); break;
         case MOVEZ : Move(a, 2); draw(a); break;
         case TURNXY: Rotate(a, 0); draw(a); break;
         case TURNXZ: Rotate(a, 1); draw(a); break;
         case TURNYZ: Rotate(a, 2); draw(a); break;
         case SAVE: save(a); break;
         case EXIT: closegraph(); return 0;
      }
      
      delay(50);
   }
}

