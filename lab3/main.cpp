#include "graphics.h"
#include "control.h"
#include "task.h"
#include <stdio.h>
#include "ctime"

int R = 10, n = 5;
using namespace std;
int get_rad()
{
   if (R < 10)
      R = 10;
   if (R > 90)
      R = 90;
   return R;
}

int get_n()
{
   if (n < 5)
      n = 5;
   return n;
}

void drawNum()
{
   int prom1 = get_n();
   int prom2 = get_rad();
   settextstyle(EMPTY_FILL, HORIZ_DIR, 37);
   outtextxy(510, 470, to_string(prom1).c_str());
   outtextxy(620, 470, to_string(prom2).c_str());
}

int main()
{
   initwindow(WIDTH, HEIGHT, "Призыв демонов и выгон попов без СМС и регистрации");
   putimage(0, 0, loadBMP("dizayn-8.bmp"), COPY_PUT);

   create_control_B(CREATE,   10, 520);
   create_control_B(CLEAR,  230, 520);
   create_control_S(MINUS_N, 470, 550);
   create_control_S(PLUS_N, 530, 550);
   create_control_S(MINUS_R, 590, 550);
   create_control_S(PLUS_R, 650, 550);
   create_control_M(SAVE, 730, 520);
   create_control_M(EXIT, 820, 520);

   while (true)
   {
      setcolor(RED);
      while (mousebuttons() == 1){
      printf("r = %d, n = %d", R, n);
      switch (select_control())
      {
      case NONE:
         break;
      case CREATE:
         create(R, n);
         drawNum();
         break;
      case CLEAR:
         clear();
         R = 10;
         n = 5;
         break;
      case PLUS_R:
         R += 5;
         R=get_rad();
         delay(10);
         break;
      case MINUS_R:
         R -= 5;
         R=get_rad();
         delay(10);
         break;
      case PLUS_N:
         n++;
         n = get_n();
         delay(30);
         break;
      case MINUS_N:
         n--;
         n = get_n();
         delay(30);
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
}