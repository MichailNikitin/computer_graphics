#include <vector>
#include <fstream>
#include <string>

using namespace std;

#ifndef TASK_H
#define TASK_H

#define COLOR_MAX 255
#define PI 3.14159265359

const int W = 600, H = 400;
struct Figure {
   int VertexNum, FaceNum;
   vector<vector<double>> vertices;
   vector<vector<int>> faces;
   double cx, cy, cz;
};
Figure Create();

void Rotate(Figure &A, int plot);
void Move(Figure &A, int plot);

void XoY(Figure f);
void XoZ(Figure f);
void YoZ(Figure f);
void save(Figure a);

#endif