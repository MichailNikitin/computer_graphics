#include "graphics.h"
#include "figure.hpp"
#include "control.h"
#include <cmath>

int p[30];

int dx[3] = {1, 0, 0};
int dy[3] = {0, 1, 0};
int dz[3] = {0, 0, 1};

Figure::Figure() { 
   ifstream in("data.txt");
   
   in >> VertexNum >> FaceNum;
   
   vertices.resize(VertexNum, vector <double> (3));
   for (int i = 0; i < VertexNum; i++)
      for (int j = 0; j < 3; j++)
         in >> vertices[i][j];
   
   faces.resize(FaceNum, vector <int> (VertexNum));
   for (int i = 0; i < FaceNum; i++)
      for (int j = 0; j < 4; j++)
         in >> faces[i][j];
   
   in.close();
   cx = 0;
   cy = 0;
   cz = 0;
}

void Figure::Rotate(int plot){
   for (int i = 0; i < VertexNum; i++){
      vertices[i][0] -= cx;
      vertices[i][1] -= cy;
      vertices[i][2] -= cz;
   }
   if(plot == 0){
      for (int i = 0; i < VertexNum; i++){
         vertices[i][0] = vertices[i][0]*cos(acos(-1)/24) + 
                                 vertices[i][1]*sin(acos(-1)/24);
         vertices[i][1] = (-1)*vertices[i][0]*sin(acos(-1)/24) + 
                                 vertices[i][1]*cos(acos(-1)/24);
      }
   }
   if(plot == 1){
      for (int i = 0; i < VertexNum; i++){
         vertices[i][0] = vertices[i][0]*cos(acos(-1)/24) - 
                                 vertices[i][2]*sin(acos(-1)/24);
         vertices[i][2] = vertices[i][0]*sin(acos(-1)/24) + 
                                 vertices[i][2]*cos(acos(-1)/24);
      }
   }
   if(plot == 2){
      for (int i = 0; i < VertexNum; i++){
         vertices[i][1] = vertices[i][1]*cos(acos(-1)/24) + 
                                 vertices[i][2]*sin(acos(-1)/24);
         vertices[i][2] = (-1)*vertices[i][1]*sin(acos(-1)/24) + 
                                 vertices[i][2]*cos(acos(-1)/24);
      }
   }
   for (int i = 0; i < VertexNum; i++){
      vertices[i][0] += cx;
      vertices[i][1] += cy;
      vertices[i][2] += cz;
   }
}

void Figure::Move(int plot){
   cx += dx[plot];
   cy += dy[plot];
   cz += dz[plot];
   for (int i = 0; i < VertexNum; i++){
      vertices[i][0] += dx[plot];
      vertices[i][1] += dy[plot];
      vertices[i][2] += dz[plot];
   }
}

void Figure::draw() {
putimage(0, 0, loadBMP("hologram.bmp"), COPY_PUT);
   for (int i = 0; i < FaceNum; i++) {
      int k = 0;
      for (int j = 0; j < 4; j++) {
         p[2 * k] = WIDTH / 4 + vertices[faces[i][j]][0];
         p[2 * k + 1] = HIEGHT / 2 - 
                              vertices[faces[i][j]][1];
         k++;
      }
      drawpoly(k, p);
   }
}

void Figure::XoZ() {
   for (int i = 0; i < FaceNum; i++) {
      int k = 0;
      for (int j = 0; j < 4; j++) {
         p[2 * k] = WIDTH / 2 + vertices[faces[i][j]][0];
         p[2 * k + 1] = 5 * HIEGHT / 8 - 
                              vertices[faces[i][j]][2];
         k++;
      }
      drawpoly(k, p);
   }
}

void Figure::YoZ() {
   for (int i = 0; i < FaceNum; i++) {
      int k = 0;
      for (int j = 0; j < 4; j++) {
         p[2 * k] = 3 * WIDTH / 4 + vertices[faces[i][j]][1];
         p[2 * k + 1] = 5 * HIEGHT / 8 - vertices[faces[i][j]][2];
         k++;
      }
      drawpoly(k, p);
   }
}