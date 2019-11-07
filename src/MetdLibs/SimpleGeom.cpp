#include <iostream>
#include <math.h>
#include "StdNXG.hpp"

output_t equally(input_t* input){ // Функция испольуется если обекты равны
  int n = input->n;
  output_t output; 
  printf(" Функция Эквевалентно \n");
  output.val[0] = input->elem[0];
  return output;
}

output_t equally2(input_t* input){ 
  int n = input->n;
  output_t output; 
  printf(" Функция Эквевалентности умноженное на 2 \n");
  output.val[0] = input->elem[0] * 2;
  return output;
}

output_t equally2y(input_t* input){ // Функция испольуется если обекты равны
  int n = input->n;
  output_t output; 

  std::cout << "Введите Y :"; int y; std::cin >> y; 
  printf(" Функция Эквевалентности умноженное на 2Y\n");
  output.val[0]= input->elem[0] * y;
  return output;
}

output_t Pifagor_katet(input_t* input){

  float gip = input->elem[0];
  float kat = input->elem[1];
  float kat2 = sqrt(gip*gip - kat*kat); 
  output_t output; 
  output.val[0] = gip;
  output.val[1] = kat;
  output.val[2] = kat2;
  return output;

}

output_t SideOfSqere_ForS(input_t* input){
  float sqvere = input->elem[0];
  float side = sqrt(sqvere);
  output_t output;
  output.val[0] = sqvere;
  output.val[1] = side;
  return output;
}