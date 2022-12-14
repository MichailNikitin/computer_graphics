#include "graphics.h"
#include "task.h"
#include <cmath>

int p[30];

int dx[3] = {1, 0, 0};
int dy[3] = {0, 1, 0};
int dz[3] = {0, 0, 1};

Figure Create() {
   Figure A;
   
   ifstream in("data.txt");
   
   in >> A.VertexNum >> A.FaceNum;
   
   A.vertices.resize(A.VertexNum, vector <double> (3));
   for (int i = 0; i < A.VertexNum; i++)
      for (int j = 0; j < 3; j++)
         in >> A.vertices[i][j];
   
   A.faces.resize(A.FaceNum, vector <int> (A.VertexNum));
   for (int i = 0; i < A.FaceNum; i++)
      for (int j = 0; j < 4; j++)
         in >> A.faces[i][j];
   
   in.close();
   A.cx = 0;
   A.cy = 0;
   A.cz = 0;
   return A;
}

void Rotate(Figure &A, int plot){
   for (int i = 0; i < A.VertexNum; i++){
      A.vertices[i][0] -= A.cx;
      A.vertices[i][1] -= A.cy;
      A.vertices[i][2] -= A.cz;
   }
   if(plot == 0){
      for (int i = 0; i < A.VertexNum; i++){
         A.vertices[i][0] = A.vertices[i][0]*cos(acos(-1)/24) + 
                                 A.vertices[i][1]*sin(acos(-1)/24);
         A.vertices[i][1] = (-1)*A.vertices[i][0]*sin(acos(-1)/24) + 
                                 A.vertices[i][1]*cos(acos(-1)/24);
      }
   }
   if(plot == 1){
      for (int i = 0; i < A.VertexNum; i++){
         A.vertices[i][0] = A.vertices[i][0]*cos(acos(-1)/24) - 
                                 A.vertices[i][2]*sin(acos(-1)/24);
         A.vertices[i][2] = A.vertices[i][0]*sin(acos(-1)/24) + 
                                 A.vertices[i][2]*cos(acos(-1)/24);
      }
   }
   if(plot == 2){
      for (int i = 0; i < A.VertexNum; i++){
         A.vertices[i][1] = A.vertices[i][1]*cos(acos(-1)/24) + 
                                 A.vertices[i][2]*sin(acos(-1)/24);
         A.vertices[i][2] = (-1)*A.vertices[i][1]*sin(acos(-1)/24) + 
                                 A.vertices[i][2]*cos(acos(-1)/24);
      }
   }
   for (int i = 0; i < A.VertexNum; i++){
      A.vertices[i][0] += A.cx;
      A.vertices[i][1] += A.cy;
      A.vertices[i][2] += A.cz;
   }
}

void Move(Figure &A, int plot){
   A.cx += dx[plot];
   A.cy += dy[plot];
   A.cz += dz[plot];
   for (int i = 0; i < A.VertexNum; i++){
      A.vertices[i][0] += dx[plot];
      A.vertices[i][1] += dy[plot];
      A.vertices[i][2] += dz[plot];
   }
}

void XoY(Figure f) {
   for (int i = 0; i < f.FaceNum; i++) {
      int k = 0;
      for (int j = 0; j < 4; j++) {
         p[2 * k] = W / 4 + f.vertices[f.faces[i][j]][0];
         p[2 * k + 1] = H / 2 - 
                              f.vertices[f.faces[i][j]][1];
         k++;
      }
      drawpoly(k, p);
   }
}

void XoZ(Figure f) {
   for (int i = 0; i < f.FaceNum; i++) {
      int k = 0;
      for (int j = 0; j < 4; j++) {
         p[2 * k] = W / 2 + f.vertices[f.faces[i][j]][0];
         p[2 * k + 1] = 5 * H / 8 - 
                              f.vertices[f.faces[i][j]][2];
         k++;
      }
      drawpoly(k, p);
   }
}

void YoZ(Figure f) {
   for (int i = 0; i < f.FaceNum; i++) {
      int k = 0;
      for (int j = 0; j < 4; j++) {
         p[2 * k] = 3 * W / 4 + f.vertices[f.faces[i][j]][1];
         p[2 * k + 1] = 5 * H / 8 - 
                              f.vertices[f.faces[i][j]][2];
         k++;
      }
      drawpoly(k, p);
   }
}

void save(Figure a)
{
   int W, H;
   IMAGE *output;

   W = getmaxx() + 1;
   H = getmaxy() + 1;
   output = createimage(W, H);

   getimage(0, 0, W - 1, H - 1, output);
   getimage(0, 0, W - 1, H - 1, output);
   saveBMP("output.bmp", output);
   freeimage(output);
}
