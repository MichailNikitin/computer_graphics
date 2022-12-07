#include <vector>
#include <fstream>
#include <string>

using namespace std;

#ifndef TASK_H
#define TASK_H

#define COLOR_MAX 255
#define PI 3.14159265359

class Figure {
   int VertexNum, FaceNum;
   vector<vector<double>> vertices;
   vector<vector<int>> faces;
   double cx, cy, cz;

public:
   
   void Rotate(int plot);
   void Move(int plot);
   void draw();
   void XoZ();
   void YoZ();
};


#endif