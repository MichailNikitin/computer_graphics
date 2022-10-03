#include "graphics.h"
#include "control.h"

Control controls[N_CONTROLS];

void create_control(int i, int left, int top)
{
   controls[i].left = left;
   controls[i].top = top;
   controls[i].right = left + 280;
   controls[i].bottom = top + 50;
}

void create_control_2(int i, int left, int top)
{
   controls[i].left = left;
   controls[i].top = top;
   controls[i].right = left + 50;
   controls[i].bottom = top  + 50;
}
int select_control()
{
   int x, y;
   
   x = mousex();
   y = mousey();
   
   for (int i = 0; i < N_CONTROLS; i++)
   {
      if (x > controls[i].left && x < controls[i].right &&
          y > controls[i].top  && y < controls[i].bottom)
      {
         return i;
      }
   }
   
   return NONE;
}