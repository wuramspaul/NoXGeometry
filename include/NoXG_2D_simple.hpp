#ifndef NoXG_2D_SIMP
#define NoXG_2D_SIMP 1 // version 
#include "NoXG.hpp"

// dedine max size name 
#ifndef MAXNAME 
#define MAXNAME 256
#endif

struct point_t{
  char name[MAXNAME];
};

struct line_t{
  point_t* first_point;
  point_t* second_point;
  char name[MAXNAME*2];
  float long_line;
};

point_t* NoXG_Init_Point(char* name);
line_t* NoXG_Init_Line(char* name, point_t* firstpoint, point_t* secondpoint, float val);

output_t ecvalToK(input_t); // 0 - x , 1 - K, 2 - y

#endif /* NoXG_2D_SIMP */