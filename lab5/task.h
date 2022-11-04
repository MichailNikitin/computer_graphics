#ifndef TASK_H
#define TASK_H

#define COLOR_MAX 255
#define WIDTH 800
#define HIEGHT 600
#define FRAMESIDE 40
#define FRAMELOWER 100
#define INDENT 10

struct Point{
   int x, y;
};

void coords(int, int );
void generation();
void bezie();
void chaikin();
void save();

#endif