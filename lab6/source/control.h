#ifndef CONTROL_H
#define CONTROL_H

#define WIDTH 1000
#define HIEGHT 648
#define SIZEBUTTONB 240
#define SIZEBUTTONS 70
#define INDENT 10

#define FRAMESIDE 40
#define FRAMELOWER 540


enum control_values { NONE = -1, EXIT, SAVE,
                      CCWROT, CWROT, MOVE, SCALE, N_CONTROLS};
enum type_function {TNONE, TMOVE, TSCALE};

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
void save();

#endif