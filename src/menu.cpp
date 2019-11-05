#include <iostream>
#include <string>
#include <assert.h>
#include "StdNXG.hpp"

using namespace std;

string inputmenu(int N){

  string inputs[MAXELEM][2]; int num = 1;
  inputs[num][0] = "EXIT FIGURE"; inputs[num][1] = "save"; num++;
  inputs[num][0] = "NEW FIGURE";  inputs[num][1] = "new"; num++;
  inputs[num][0] = "LOAD PRIMERS FIGURE"; inputs[num][1] = "primers"; num++;
  inputs[num][0] = "LOAD FIGURE"; inputs[num][1] = "load"; num++;
  inputs[num][0] = "SAVE FIGURE"; inputs[num][1] = "save"; num++;
  inputs[num][0] = "INPUT VALUE"; inputs[num][1] = "input"; num++;
  inputs[num][0] = "NEW VALUE"; inputs[num][1] = "ninput"; num++;
  inputs[num][0] = "START PROGRAMM"; inputs[num][1] = "start"; num++;
  inputs[num][0] = "CONFIGURE PROGRAMM"; inputs[num][1] = "conf"; num++;

  return inputs[1][1];
}

int expmenu(){
  string chose = inputmenu(1);
  
  if(chose == "exit") return 0;
  cout << "****************\n";
  cout << chose << endl;  
  cout << "****************\n";
  return 1;
}

int main(){

  while(expmenu());
}

