#ifndef NoXG_2D_SIMP_X 
#define NoXG_2D_SIMP_X 1 // NoXG2DGLS version = 1  NoXG2DGLS_X  version = 1

#include "NoXG_2D_simple.hpp"

struct area_t{
  float area;
};

struct pirimetr_t{
  float pirimetr;
};

struct ray_t{
  point_t* main;
  float long_ray;
};

struct angle_t{
  float angle;
};

struct circle_t{
  point_t centre;
  ray_t radius;
  area_t area;
  pirimetr_t pirimetr;
};

struct square_t{
  point_t* vertex[4];
  line_t sides[4];
  area_t* area;
  pirimetr_t pirimetr;
};

struct triangle_t{
  point_t* vertex[3];
  line_t sides[3];
  angle_t angles[3];
  area_t* area;
  pirimetr_t pirimetr;
};

output_t* equally(input_t*); // 0 - x
output_t* equally2(input_t* input);  // 0 - x
output_t* equally2y(input_t* input); // 0 - x
output_t* Pifagor_katet(input_t* input); // 0 - gip; 1 - katet1; 2 - katet2   
output_t* SideOfSqere_ForS(input_t* input); // 0 - sqere; 1 - side 

#endif /* NoXG_2D_SIMP_X */ 