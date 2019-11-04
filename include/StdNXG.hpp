#ifndef NXG
#define NXG
#define MAXELEM 100

struct tree_t{
  short int type;
  void* Stru;
};

struct input_t{
  int n; // количество элементов для ввода
  float elem[MAXELEM];
};

struct output_t{
  int n; // количество элементов для вывода
  float val[MAXELEM];
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
#endif // 
