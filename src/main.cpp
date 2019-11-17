#include <iostream>
#include "NoXG.hpp"
#include "NoXG_2D_simple_X.hpp"

int main(){
  TreeMetd_t met1;  met1.dif = 3;  met1.metd.foo = equally; met1.count_obj = 0; met1.Objs[0] = nullptr;
  TreeMetd_t met2;  met2.dif = 2;  met2.metd.foo = equally2; met2.count_obj = 0; met2.Objs[0] = nullptr;
  TreeMetd_t met3;  met3.dif = 1;  met3.metd.foo = equally2y; met3.count_obj = 0; met3.Objs[0] = nullptr;
  
  TreeObj_t obj; obj.count_metd = 3; obj.dif = 0; obj.obj.isOpred = 0; obj.obj.val = 0; obj.type = -1; 

  tree_t tree[MAXELEM];
  tree[0].type = 1; tree[0].Stru = &obj;  
  tree[1].type = 0; tree[1].Stru = &met1;
  tree[2].type = 0; tree[2].Stru = &met2;
  tree[3].type = 0; tree[3].Stru = &met3;
  
  int min; int min_i;
  TreeMetd_t* stuc = (TreeMetd_t*) tree[1].Stru;
  min = stuc->dif;
  min_i = 1;
  for(int i = 1; i <= 3; i++){
    stuc = (TreeMetd_t*) tree[i].Stru;
    if(min > stuc->dif){
    min = stuc->dif;
    min_i = i;  
    }
  }

  printf("Индекс самого не сложного метода %d, его сложность %d\n", min_i, min);

  input_t input; input.n = 1; std::cout << "Введите x : "; std::cin >> input.elem[0]; 
  TreeMetd_t* tempobj = (TreeMetd_t*) tree[min_i].Stru;
  
  output_t output = *(tempobj->metd.foo)(&input);

  printf("Ответ : %f\n", output.val[0]);
  return 0;
}

