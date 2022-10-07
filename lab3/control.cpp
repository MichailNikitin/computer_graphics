#include "graphics.h"
#include "control.h"

Control controls[N_CONTROLS];

void create_control_B(int i, int left, int top)
{
   controls[i].left = left;
   controls[i].top = top;
   controls[i].right = left + 200;
   controls[i].bottom = top + 70;
}

void create_control_M(int i, int left, int top)
{
   controls[i].left = left;
   controls[i].top = top;
   controls[i].right = left + 70;
   controls[i].bottom = top  + 70;
}

void create_control_S(int i, int left, int top)
{
   controls[i].left = left;
   controls[i].top = top;
   controls[i].right = left + 40;
   controls[i].bottom = top  + 40;
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