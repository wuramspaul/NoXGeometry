#ifndef NXG_MENU
#define NXG_MENU

#include <iostream>
#include <string>
#define MAX_ELEM_MENU 4

struct punkt_t{
  std::string msg;
  std::string searchIdx;
  void* next;
};

struct menu_t{
  int n;
  menu_t* prev;
  punkt_t msgs[MAX_ELEM_MENU];
};

menu_t initMenu();
void addToMenu(menu_t* menu, std::string msg, std::string idx, menu_t* next);
void printMenu(menu_t menu);
std::string startMenu(menu_t menu);

#endif