#ifndef CONTROL_H
#define CONTROL_H
#define WIDTH 900
#define HEIGHT 600
#define FRAME 20

#define W 70
#define H 40
#define HEIGHTB 45
#define WIDTHB 185
#define GAP_1 60
#define GAP_2 50



enum control_values { NONE = -1, CREATE, CLEAR, EXIT, SAVE, PLUS_R, 
                   MINUS_R, PLUS_N, MINUS_N, N_CONTROLS};

struct Control
{
   int left;
   int top;
   int right;
   int bottom;
};

void create_control_B(int, int, int);
void create_control_M(int, int, int);
void create_control_S(int, int, int);
int select_control();

#endif