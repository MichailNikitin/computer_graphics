#define _USE_MATH_DEFINES






using namespace std;
bool drawed=false;

Point points[4];

void makeColors(int x0,int y0, int seed_color) {
   int x,y;
   double df=M_PI/6, da=df/2;

   int color[7];
   int R1[3]= {30,180,280};
   int R2[4]= {30,110,160,250};
   for (int i=0; i<7; i++)
      color[i]=rand()%WHITE;
   for (int i=0; i<3; i++) {
      setfillstyle(SOLID_FILL,color[i]);
      for (int j=0; j<12; j++) {
         x=x0+R1[i]*cos(j*df);
         y=y0+R1[i]*sin(j*df);
         floodfill(x,y,COLOR_MAX);
      }
   }
   for (int i=0; i<4; i++) {
      setfillstyle(SOLID_FILL,color[3+i]);
      for (int j=0; j<12; j++) {
         x=x0+R2[i]*cos(j*df+da);
         y=y0+R2[i]*sin(j*df+da);
         floodfill(x,y,COLOR_MAX);
      }
   }
}


void cycles(int x0, int y0, int R) {
   cycle(x0,y0,R);

   for (int i=1; i<=12; i++)
      cycle(x0+R*cos((M_PI/6)*i), y0+R*sin((M_PI/6)*i),  R);
}


void repainting() {

   if (!drawed) return;

   while (mousebuttons()!=0);
   int seed_color=rand()%WHITE;
   setfillstyle(SOLID_FILL, seed_color);

   makeColors(WIDTH/2,(WIDTH-FRAMELOWER)/2, seed_color);
   cycle(3*WIDTH/5+INDENT, HIEGHT-INDENT-3*FRAMESIDE/2,INDENT+1);   // 3*FRAMELOWER-FRAMESIDE ,5*FRAMELOWER-FRAMESIDE ,INDENT-1
   floodfill(3*WIDTH/5+INDENT, HIEGHT-INDENT-3*FRAMESIDE/2,COLOR_MAX);
}

void generation() {
   
   for (int i = 0; i < 4; i++){
      _abracadabra_cast(points[i]);