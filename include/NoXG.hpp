#ifndef NoXG
#define NoXG

#define MAXELEM   16
#define MAXNAME   256
#define MAXATRB   4 /* 0 - isOpred?, 1 - isPrint?, 2 - isInput?, 3 - isList? */ 
#define MAXVALUE  1000
#define MAXDEF    1000
#define MINVALUE  0
#define MINDEF    0

#define METODTYPE 2 // Значение метода
#define OBJECTYPE 1 // Значение обекта
#define HZNAITYPE 0 // Неопределенный тип

#define OPRED_FLAG  0
#define OUTPUT_FLAG 1
#define INPUT_FLAG  2
#define LIST_FLAG   3

struct tree_t{
  bool atrib[MAXATRB];
  short int type; // 0 - neopred; 1 - obj; 2 - metd
  void* Stru;
  float dif; // сложность 
};

struct finalTree_t{
  bool atrib[MAXATRB];
  short int type; // 0 - neopred; 1 - obj; 2 - metd
  void* Stru;
  void (*foooutput)(TreeMetd_t* Stru);
  input_t* (*fooinput)(TreeInput_t* metd);
};

struct input_t{
  int n; // количество элементов для ввода
  float elem[MAXELEM];
};

struct output_t{
  int n; // количество элементов для вывода
  float val[MAXELEM];
};

struct TreeInput_t{
  int n; // количество элементов для ввода
  input_t (*foo_input);
};

struct TreeOutput_t{
  int n; // количество элементов для вывода
  void (*foo_output)(output_t);
};

struct TreeMetd_t{
  output_t* (*metd)(input_t*);
  int count_obj; // количество обектов для метода
  tree_t* Objs[MAXELEM];
};

struct TreeObj_t{
  void* obj; // объект 
  short int type; // тип обекта 
  char name[MAXNAME]; // имя
  int count_metd; // количество методов для обекта
  tree_t* Mets[MAXELEM]; // указатели на методы 
};

#endif /* NoXG */ 
