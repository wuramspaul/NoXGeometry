#include <iostream>
#include <math.h>
#define MAXELEM 10

struct input_t{
  int n; // количество элементов для ввода
  float elem[MAXELEM];
};

struct output_t{
  int n; // количество элементов для вывода
  float val[MAXELEM];
};

struct tree_t{
  short int type;
  void* Stru;
};

struct inputdata_t{
  short int type; // тип(номер) метода для ввода значенией
  input_t (*foo_input);
};

struct outpudata_t{
  short int type; // тип(номер) метода для вывода значенией
  void (*foo_output)(output_t);
};

struct metoddata_t{
  short int type; // тип(номер) метода 
  output_t (*foo)(input_t*);
};

struct objectdata_t{
  bool isOpred;
  float val;
};

struct TreeMetd_t{
  int dif; // сложность 
  metoddata_t metd;
  int count_obj; // количество методов для обекта
  tree_t* Objs[MAXELEM];
};

struct TreeObj_t{
  int dif; // сложность 
  objectdata_t obj; // объект 
  int count_metd; // количество методов для обекта
  tree_t* Mets[MAXELEM];
  short int type;
};

tree_t BGTMain(tree_t* root); // Самая главная функция для обхода Большого Геометрического Дерева (.BGT)
tree_t SGTMain(tree_t* root); // Функция для нахождения значений в Малом Геометрическом Дереве (.SGT)

output_t equally(input_t*); // 0 - x
output_t equally2(input_t* input);  // 0 - x
output_t equally2y(input_t* input); // 0 - x
output_t Pifagor_katet(input_t* input); // 0 - gip; 1 - katet1; 2 - katet2   
output_t SideOfSqere_ForS(input_t* input); // 0 - sqere; 1 - side  

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
  
  output_t output = (tempobj->metd.foo)(&input);

  printf("Ответ : %f\n", output.val[0]);
  return 0;
}

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