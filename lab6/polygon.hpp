#ifndef Polygon_H
#define Polygon_H

struct Point
{
   double x = 0;
   double y = 0;
};

class Polygon
{
   int count_vertices;
   Point *plg_points;
   Point plg_center;
   double plg_angle = 0;
   double plg_factor = 1;

public:
   Polygon();
   void move(double x, double y);
   void rotate(double angle);
   void scale(double factor);
   void draw();
   void read_info();
};

#endif
