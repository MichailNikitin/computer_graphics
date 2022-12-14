#ifndef CONTROL_H
#define CONTROL_H

#define WIDTH 1200
#define HIEGHT 600
#define SIZEBUTTONS 120
#define INDENT 10

enum control_values { NONE = -1, EXIT, SAVE,
   MOVEX, MOVEY, MOVEZ,
   TURNXY, TURNXZ, TURNYZ,
   N_CONTROLS };
                     
struct Control {
   int left;
   int top;
   int right;
   int bottom;
};

void create_control(int, int, int);
int select_control();
void save();
#endif