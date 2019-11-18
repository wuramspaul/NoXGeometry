#include "NoXG.hpp"

struct nameOBJ{
  char name[256];
  TreeObj_t obj;
};

nameOBJ objectsname[MAXELEM];
char SUMBALS[] = {'A','B','C','D'};
extern unsigned int __name_int = 1;

char* getnamepoint(){ // TODO : доделать генератор имен
  char name[MAXNAME];
  
  for(int temp = __name_int;temp != 0;){

  }
  return name;
}

tree_t* initNewRootBGTree(){
  tree_t* root = new tree_t;
  for(int i = 0; i != MAXATRB; i++) root->atrib[i] = false;
  root->dif = 0;
  root->type = 0;
  root->Stru = nullptr;
  return root;
}

tree_t* newNodeBGTree(short int type, bool atrib[MAXATRB], float dif, void* stru){
  tree_t* node = new tree_t;
  for(int i = 0; i != MAXATRB; i++)
  node->atrib[i] = atrib[i];
  node->dif = dif;
  node->Stru = stru;
  node->type = type;
  return node; 
}

TreeMetd_t* newTreeMetd(int count_obj, output_t* (*metd)(input_t*), tree_t* Objs[MAXELEM]){
  TreeMetd_t* node = new TreeMetd_t;
  node->count_obj = count_obj;
  node->metd = metd;
  for(int i = 0; i != MAXELEM; i++) node->Objs[i] = Objs[i];
  return node;
}


float opredMinMetd(tree_t* node);
float opredObj(tree_t* node);
void* getInputfoo(TreeObj_t* obj);
void* getOutputfoo(TreeObj_t* obj);

float opredDif_obj(TreeMetd_t* metd);
float opredDif_metd(TreeMetd_t* metd);

float opredDif_obj(TreeObj_t* obj){
  int kol = obj->count_metd;
  float* difs_metd = new float[kol];
  float min_i = -1;
  float min = MAXDEF;
  for(int i = 0; i != kol; i++){
    difs_metd[i] = opredDif_metd((TreeMetd_t*) obj->Mets[i]);
    if(min > difs_metd[i]){
      min = difs_metd[i];
      min_i = i;
    }  
  }  
  float DEF;
  min_i != -1 ? DEF = min : DEF = 0;
  return DEF;
}

float opredDif_metd(TreeMetd_t* metd){
  int kol = metd->count_obj;
  float* difs_obj = new float[kol];
  float DEF;
  for(int i = 0; i != kol; i++){
    difs_obj[i] = opredDif_obj((TreeObj_t*) metd->Objs[i]);
    DEF += difs_obj[i]; 
  } 
  return DEF;
}

finalTree_t* opredNext_Metd(finalTree_t* rootnode){ // определяем новый метод, на основе сложности
  TreeObj_t* obj = (TreeObj_t*) rootnode->Stru;
  int kol = obj->count_metd;
  float* dif_metds = new float[kol];
  float min = MAXDEF;
  int min_i = 1;
  for(int i = 0; i != kol; i++){
    dif_metds[i] = opredDif_metd((TreeMetd_t*) obj->Mets[i]);
    if(min > dif_metds[i]){
      min = dif_metds[i];
      min_i = i;
    }
  }
  // obj->Mets[min_i] - оптимальный метод

  TreeMetd_t* NextMetd = new TreeMetd_t;
  NextMetd->count_obj = ((TreeMetd_t* ) obj->Mets[min_i])->count_obj; 
  NextMetd->metd = ((TreeMetd_t* ) obj->Mets[min_i])->metd;
  for(int i = 0; i != NextMetd->count_obj; i++){
    NextMetd->Objs[i] = ((TreeMetd_t* ) obj->Mets[min_i])->Objs[i];
  }

  finalTree_t* SGTmetd = new finalTree_t;
  SGTmetd->Stru = (void*) NextMetd;
  SGTmetd->type = METODTYPE; 
  for(int i = 0; i != MAXATRB; i++){
    SGTmetd->atrib[i] = obj->Mets[min_i]->atrib[i];
  }
  SGTmetd->fooinput = nullptr;
  SGTmetd->foooutput = nullptr;
  
  return SGTmetd;
}

finalTree_t* newNodeSGT(tree_t* treenode){ // TODO: доделать еще оди метод обхода 
  finalTree_t* node = new finalTree_t;
  // Если этот обект исходный 
  // Если обект не определен
  // Определить обект
  // Записываем в структуру и сложность 

  // Если это элемент ветки
  // Если не определен, то определить
  // Записать в структуру и вернуть    
  return node;
}

finalTree_t* Convert_Obj_BGT_TO_SGT(tree_t* BGT){
  finalTree_t* SGT = new finalTree_t;
  for(int i = 0; i != MAXATRB; i++) {
    SGT->atrib[i] = BGT->atrib[i];
  }
  SGT->type = OBJECTYPE;   

  SGT->Stru = BGT->Stru;
  SGT->atrib[OUTPUT_FLAG] ? SGT->foooutput = (void (*)(TreeMetd_t*)) getOutputfoo((TreeObj_t*) SGT->Stru) : SGT->foooutput = nullptr;
  SGT->atrib[INPUT_FLAG] ? SGT->fooinput = (input_t* (*)(TreeInput_t*)) getInputfoo((TreeObj_t*) SGT->Stru) : SGT->fooinput = nullptr;

  return SGT;
}

void opredBETKI(finalTree_t* root){
  TreeMetd_t* metd = (TreeMetd_t*) opredNext_Metd(root);
  for(int i = 0; i != metd->count_obj; i++){
    opredBETKI(Convert_Obj_BGT_TO_SGT(metd->Objs[i]));
  }
}

finalTree_t* newSGTree(tree_t* rootBGT){
  finalTree_t* rootSGT = new finalTree_t;
  for(int i = 0; i != MAXATRB; i++) rootSGT->atrib[i] = rootBGT->atrib[i]; 

  rootSGT->type = rootBGT->type;
  rootSGT->atrib[1] ? rootSGT->foooutput = (void (*)(TreeMetd_t*)) getOutputfoo((TreeObj_t*) rootBGT->Stru) : rootSGT->foooutput = nullptr;
  rootSGT->atrib[2] ? rootSGT->fooinput = (input_t* (*)(TreeInput_t*)) getInputfoo((TreeObj_t*) rootBGT->Stru) : rootSGT->fooinput = nullptr;

  opredBETKI(rootSGT);

  return rootSGT;
}