#include "NoXGMenu.hpp"

menu_t initMenu(){
  menu_t menu; 
  menu.n = 0;
  menu.prev = nullptr;
  return menu;
}

void addToMenu(menu_t* menu, std::string msg, std::string idx, menu_t* next){
  if(menu->n == MAX_ELEM_MENU) return;
  menu->msgs[menu->n].msg= msg;
  menu->msgs[menu->n].searchIdx = idx;
  menu->msgs[menu->n].next = next;
  menu->n++;
}

void printMenu(menu_t menu){
  std::cout << std::endl;
  int n = 1; 
  while(n != menu.n) {
    std::cout << n <<". "<<  menu.msgs[n].msg << std::endl;
    n++;
  }
  std::cout << 0 <<". "<<  menu.msgs[0].msg << std::endl;
  std::cout << std::endl;
}

std::string startMenu(menu_t menu){
  printMenu(menu);
  int c; std::cin >> c;
  if(menu.msgs[c].next == nullptr){
    return menu.msgs[c].searchIdx;
  } else {
    return startMenu(*(menu_t*) (menu.msgs[c].next));
  }
}