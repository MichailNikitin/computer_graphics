#include "graphics.h"
#include "control.h"
#include "task.h"

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
   int prom1 = get_rad();
   int prom2 = get_n();
   setbkcolor(TRANSPARENT);
   settextstyle(EMPTY_FILL, HORIZ_DIR, 37);
   outtextxy(264, 50, to_string(prom1).c_str());
   outtextxy(510, 50, to_string(prom2).c_str());
}

int main()
{
   initwindow(WIDTH, HEIGHT, "������ ������� � ����� ����� ��� ��� � �����������");
   putimage(0, 0, loadBMP("background.bmp"), COPY_PUT);

   create_control_B(CREATE,   10, 520);
   create_control_B(CLEAR,  230, 520);
   create_control_S(PLUS_R, 470, 550);
   create_control_S(MINUS_R, 530, 550);
   create_control_S(PLUS_N, 590, 550);
   create_control_S(MINUS_N, 650, 550);
   create_control_M(SAVE, 730, 520);
   create_control_M(EXIT, 820, 520);

   while (true)
   {
      setfillstyle(SOLID_FILL, 15);
      setbkcolor(BLACK);

      while (mousebuttons() != 1);
      switch (select_control())
      {
      case NONE:
         break;
      case CREATE:
         create(n, R);
         drawNum();
         break;
      case CLEAR:
         clear();
         R = 10;
         n = 5;
         break;
      case PLUS_R:
         R += 5;
         break;
      case MINUS_R:
         R -= 5;
         break;
      case PLUS_N:
         n += 1;
         break;
      case MINUS_N:
         n -= 1;
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