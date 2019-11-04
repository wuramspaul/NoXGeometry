#include <iostream>

int menuinput(int numer);
int menu(int code);

int menuinput(int numer){
  int num = 1;
  switch (numer)
  {
  case 0:
    std::cout << num++ << "1. Create and Load BGT" << std::endl;
    std::cout << num++ << "2. Edit and Load Segings" << std::endl;
    std::cout << num++ << "3. Load SGT" << std::endl;
    std::cout << std::endl;
    std::cout << 0 << "0. Exit" << std::endl;
    break;
  case 1:
    std::cout << num++ << "1. Bild SGT" << std::endl;
    std::cout << num++ << "2. Edit BGT" << std::endl;
    std::cout << num++ << "3. Edit and Load Segings" << std::endl;
    std::cout << num++ << "4. Save BGT" << std::endl;
    std::cout << num++ << "5. Load SGT" << std::endl;    
    std::cout << std::endl;
    std::cout << 0 << "0. Exit" << std::endl;
    break;  
  case 2:
    std::cout << num++ << "1. Bild SGT" << std::endl;
    std::cout << num++ << "2. Edit BGT" << std::endl;
    std::cout << num++ << "3. Edit and Load Segings" << std::endl;
    std::cout << num++ << "3. Save BGT" << std::endl;   
    std::cout << num++ << "3. Save SGT" << std::endl;       
    std::cout << std::endl;
    std::cout << 0 << "0. Exit" << std::endl;
    break; 
  case 3:
    std::cout << num++ << "1. Includes Liberis to Bild" << std::endl;
    std::cout << num++ << "2. Optimization to Bild" << std::endl;  
    std::cout << num++ << "3. Optimization Setings to Bild" << std::endl;      
    std::cout << num++ << "4. Load Segings" << std::endl;
    std::cout << std::endl;
    std::cout << 0 << "0. Return" << std::endl;
    break; 
  case 4:
    std::cout << num++ << "1. Includes Liberis to Bild" << std::endl;
    std::cout << num++ << "2. Optimization to Bild" << std::endl;  
    std::cout << num++ << "3. Optimization Setings to Bild" << std::endl;      
    std::cout << num++ << "4. Save Segings" << std::endl;
    std::cout << num++ << "5. Load Segings" << std::endl;
    std::cout << std::endl;
    std::cout << 0 << "0. Return" << std::endl;
    break;   
  case 5:
    std::cout << num++ << "1. Create new Big Geomety Tree" << std::endl;
    std::cout << num++ << "2. Load Primers" << std::endl;
    std::cout << num++ << "3. Tree.bgt" << std::endl;
    std::cout << num++ << "4. Tree1.bgt" << std::endl;  
    std::cout << num++ << "5. TreeN.bgt" << std::endl;  
    std::cout << std::endl;
    std::cout << 0 << "0. Return" << std::endl;
    break;
  case 6:
    std::cout << num++ << "1. EgyptianTriangle.bgt" << std::endl;
    std::cout << num++ << "2. Cube.bgt" << std::endl;
    std::cout << num++ << "3. Primer3.bgt" << std::endl; 
    std::cout << num++ << "4. PrimerN.bgt" << std::endl;   
    std::cout << std::endl;
    std::cout << 0 << "0. Return" << std::endl;
    break;  
  case 7:
    std::cout << num++ << "1. KEY1 [ ]" << std::endl;
    std::cout << num++ << "2. KEY2 [x]" << std::endl;  
    std::cout << num++ << "3. KEY3 [*]" << std::endl;  
    std::cout << std::endl;
    std::cout << 0 << "0. Return" << std::endl;
    break;
  case 8:
    std::cout << num++ << "1. [ ] geometry_simple" << std::endl;
    std::cout << num++ << "2. [x] geometry_advanse " << std::endl;  
    std::cout << num++ << "3. [*] geometry_full " << std::endl;  
    std::cout << std::endl;
    std::cout << 0 << "0. Return" << std::endl;
    break;
  }
  std::cout << std::endl;
  std::cout << "Enter you chose >> "<<std::endl; int chose; std::cin >> chose; return chose;
}

int menu(int code){
  int chose = menuinput(code);

  switch (code)
  {
  case 1:
    switch (chose)
    {
    case 1:
      chose = menuinput(5);
      menu(chose);
      break;
    case 2:
      menuinput(5);
      return 0;
      break;
    case 3:
      menuinput(5);
      return 0;
      break;
    case 0:
      menuinput(5);
      return 0;
      break;
    } 
    break;
  }

  
  return -1;
}