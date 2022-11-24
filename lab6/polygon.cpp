#include "graphics.h"
#include "polygon.hpp"

#include <cmath>

const double PI = acos(0.0)*2.0;

Polygon::Polygon()
{
   
   plg_points = new Point[count_vertices]

}

void Polygon::rotate(double angle)
{
   plg_angle += angle*(PI/180.0);
   draw();
}

void Polygon::move(double x, double y)
{
   plg_center.x += x;
   plg_center.y += y;
   draw();
}

void Polygon::scale(double factor)
{
   plg_factor *= factor;
   draw();
}

void Polygon::draw()
{
   Point points[12];

   for (int i = 0; i < 12; i++)
   {
      points[i] = plg_points[i];

      // Поворот
      points[i].x = cos(plg_angle)*plg_points[i].x - sin(plg_angle)*plg_points[i].y;
      points[i].y = sin(plg_angle)*plg_points[i].x + cos(plg_angle)*plg_points[i].y;

      // Скейлинг
      points[i].x *= plg_factor;
      points[i].y *= plg_factor;

      // Перемещение
      points[i].x += plg_center.x;
      points[i].y += plg_center.y;

      // Преобразование из декартовых в экранные
      points[i].x = points[i].x + width/2.0;
      points[i].y = height/2.0 - points[i].y;
   }

   // Преобразование в 5 прямоугольников (которые составляют знак +)
   int arr1[8] = {points[0].x,points[0].y,points[1].x,points[1].y,points[2].x,points[2].y,points[3].x,points[3].y};
   int arr2[8] = {points[3].x,points[3].y,points[4].x,points[4].y,points[5].x,points[5].y,points[6].x,points[6].y};
   int arr3[8] = {points[6].x,points[6].y,points[7].x,points[7].y,points[8].x,points[8].y,points[9].x,points[9].y};
   int arr4[8] = {points[9].x,points[9].y,points[10].x,points[10].y,points[11].x,points[11].y,points[0].x,points[0].y};
   int arr5[8] = {points[0].x,points[0].y,points[3].x,points[3].y,points[6].x,points[6].y,points[9].x,points[9].y};

   // Отрисовка

   setfillstyle(SOLID_FILL, BLACK);
   bar(0, 0, width, height);

   setcolor(YELLOW);
   setfillstyle(SOLID_FILL, YELLOW);

   fillpoly(4, arr1);
   fillpoly(4, arr2);
   fillpoly(4, arr3);
   fillpoly(4, arr4);
   fillpoly(4, arr5);
}

void Polygon::read_info()
{
   ifstream file;
   file.open("info_for_figure.txt");
   file >> count_vertices;
   for (int i=0; i<count_vertices; i++) {
      file >> plg_points[i].x >> plg_points[i].y;
   }
}