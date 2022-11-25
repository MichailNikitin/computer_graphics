#include "graphics.h"
#include "figura.hpp"
#include "control.h"
#include <cmath>

#include <control.h>
#include <fstream>
const double PI = acos(0.0)*2.0;
using namespace std;
Figura::Figura()
{
   
   plg_points = new Point[count_vertices];
   
   ifstream file;
   file.open("info_for_figure.txt");
   file >> count_vertices;
   for (int i=0; i<count_vertices; i++) {
      file >> plg_points[i].x >> plg_points[i].y;
   }
}

void Figura::rotate(double angle)
{
   plg_angle += angle*(PI/180.0);
   draw();
}

void Figura::move(double x, double y)
{
   plg_center.x += x;
   plg_center.y += y;
   draw();
}

void Figura::scale(double factor)
{
   plg_factor *= factor;
   draw();
}

void Figura::draw()
{
   Point points[count_vertices];
   int *point4drow = new int[count_vertices*2];
   for (int i = 0; i < count_vertices; i++)
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
      points[i].x = points[i].x + WIDTH/2.0;
      points[i].y = HIEGHT/2.0 - points[i].y;
   }
   
   for (int i = 0; i < 2*count_vertices; i+=2){
      point4drow[i] =points[i].x;
      point4drow[i+1] = points[i].y;
   }
   
   
   setfillstyle(SOLID_FILL, BLACK);
   fillpoly(count_vertices, point4drow);

   setcolor(YELLOW);
   setfillstyle(SOLID_FILL, YELLOW);

}