#include <NoXG_2D_simple.hpp>
#include <string.h>

point_t* NoXG_Init_Point(char* name){
  point_t* p = new point_t;
  strcpy(p->name,name);
  return p;
}

line_t* NoXG_Init_Line(char* name, point_t* firstpoint, point_t* secondpoint, float long_line){
  line_t* p = new line_t;
  p->first_point = firstpoint;
  p->second_point = secondpoint;
  strcpy(p->name,name);
  p->long_line = long_line;
  return p;
}