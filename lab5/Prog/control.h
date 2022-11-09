#ifndef CONTROL_H
#define CONTROL_H

#define SIZEBUTTONB 170
#define SIZEBUTTONS 80

enum control_values { NONE = -1, EXIT, SAVE,
                      GEHERAT, BEZIE, CHAIKIN, N_CONTROLS};

struct Control
{
   int left;
   int top;
   int right;
   int bottom;
};

void create_control(int, int, int);
void create_control_S(int, int, int);
int select_control();

#endif