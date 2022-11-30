#ifndef Figura_H
#define Figura_H

struct Point
{
   double x = 0;
   double y = 0;
};

class Figura
{
   int count_vertices;
   Point *plg_points;
   Point plg_center;
   Point center;
   double plg_angle = 0;
   double plg_factor = 1;

public:
   Figura();
   ~Figura() = default;
   void calc_center();
   void move(double x, double y);
   void rotate(double angle);
   void scale(double factor);
   void draw();
};

#endif
