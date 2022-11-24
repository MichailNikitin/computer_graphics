#include "graphics.h"
#include "polygon.hpp"
#include "control.h"
#include <cmath>

#include <control.h>
#include <fstream>
const double PI = acos(0.0)*2.0;
using namespace std;
Polygon::Polygon()
{
   
   plg_points = new Point[count_vertices];

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
   Point points[count_vertices];

   for (int i = 0; i < count_vertices; i++)
   {
      points[i] = plg_points[i];

      // �������
      points[i].x = cos(plg_angle)*plg_points[i].x - sin(plg_angle)*plg_points[i].y;
      points[i].y = sin(plg_angle)*plg_points[i].x + cos(plg_angle)*plg_points[i].y;

      // ��������
      points[i].x *= plg_factor;
      points[i].y *= plg_factor;

      // �����������
      points[i].x += plg_center.x;
      points[i].y += plg_center.y;

      // �������������� �� ���������� � ��������
      points[i].x = points[i].x + WIDTH/2.0;
      points[i].y = HIEGHT/2.0 - points[i].y;
   }

   // �������������� � 5 ��������������� (������� ���������� ���� +)
   
   // ���������

   setfillstyle(SOLID_FILL, BLACK);


   setcolor(YELLOW);
   setfillstyle(SOLID_FILL, YELLOW);

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