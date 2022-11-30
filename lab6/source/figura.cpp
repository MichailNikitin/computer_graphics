#include "graphics.h"
#include "figura.hpp"
#include "control.h"
#include <cmath>
#include <control.h>
#include <fstream>

#include <iostream>

const double PI = acos(0.0)*2.0;
using namespace std;
Figura::Figura()
{
   ifstream file;
   file.open("info_for_figure.txt");
   file >> count_vertices;
   
   plg_points = new Point[count_vertices];
   
   for (int i=0; i<count_vertices; i++) {
      file >> plg_points[i].x >> plg_points[i].y;
      
      printf("(%.2lf;%.2lf)-", plg_points[i].x, plg_points[i].y);
   }
   calc_center();
   draw();
}

void Figura::calc_center(){
   for(int i=0; i<count_vertices; i++){
      center.x += plg_points[i].x;
      center.y += plg_points[i].y;
   }
   center.x /= count_vertices;
   center.y /= count_vertices;
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
   int point4drow[2*count_vertices];
   putimage(0, 0, loadBMP("BrutalMagica.bmp"), COPY_PUT);
   for (int i = 0; i < count_vertices; i++)
   {
      points[i] = plg_points[i];
      
      // Перемещение
      
      points[i].x += plg_center.x;
      points[i].y += plg_center.y;
      calc_center();
      
      // Поворот
      //~ points[i].x = cos(plg_angle)*plg_points[i].x - sin(plg_angle)*plg_points[i].y;
      //~ points[i].y = sin(plg_angle)*plg_points[i].x + cos(plg_angle)*plg_points[i].y;
      points[i].x = center.x+(-center.x+plg_points[i].x)*cos(plg_angle)+(center.y-plg_points[i].y)*sin(plg_angle);
      points[i].y = center.y+(-center.x+plg_points[i].x)*sin(plg_angle)+(-center.y+plg_points[i].y)*cos(plg_angle);

      // 
      points[i].x *= plg_factor;
      points[i].y *= plg_factor;

      

      // Преобразование из декартовых в экранные
      points[i].x = points[i].x + WIDTH/2.0;
      points[i].y = HIEGHT/2.0 - points[i].y;
   }
   // Подготовка массива для постораениея многоугольника
   for (int i = 0; i < 2*count_vertices; i+=2){
      printf("(%.2lf;%.2lf)-", points[i/2].x, points[i/2].y);
      point4drow[i] =points[i/2].x;
      point4drow[i+1] = points[i/2].y;
   }
   cout << endl;
   
   setfillstyle(SOLID_FILL, BLACK);
   fillpoly(count_vertices, point4drow);

   setcolor(YELLOW);
   setfillstyle(SOLID_FILL, YELLOW);

}