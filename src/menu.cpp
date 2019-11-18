#include <iostream>
#include "NoXG.hpp"
#include "NoXGMenu.hpp"

using namespace std;

int main(){
  menu_t mm = initMenu();
  menu_t mcre = initMenu();
  menu_t mcong = initMenu();
  menu_t mexemp = initMenu();

  addToMenu(&mm,"EXIT PROGRAMM","exit",nullptr);
  addToMenu(&mm,"CREATE FIGURE","create",&mcre);
  addToMenu(&mm,"CONFIG PROGRAMM","cong",&mcong);
 
  addToMenu(&mcre,"BACK","back",&mm);
  addToMenu(&mcre,"EXEMPLE FIGURE","exemp",&mexemp);
  addToMenu(&mcre,"NEW FIGURE","newfig",nullptr);

  addToMenu(&mcong,"BACK","create",&mm);
  addToMenu(&mcong,"SET MAXELEM","setMAXELEM",nullptr);
  addToMenu(&mcong,"SET MAXINPUTS","setMAXINPUTS",nullptr);
  addToMenu(&mcong,"SET MAXDEF","setMAXDEF",nullptr);

  addToMenu(&mexemp,"BACK","create",&mm);
  addToMenu(&mexemp,"PIFAGOR","primer_pifagor",nullptr);
  addToMenu(&mexemp,"KUB","primer_kub",nullptr);
  addToMenu(&mexemp,"VECTOR","primer_vector",nullptr);
  addToMenu(&mexemp,"OKR","primer_okr",nullptr);

  startMenu(mm);
}

