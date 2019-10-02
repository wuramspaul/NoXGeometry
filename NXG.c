#include <stdio.h>
#define MAXNODE 100

typedef struct objNode
{
  int data;
} objNode_t;

typedef struct metNode 
{
  void* Objs;
  int (*foo)(void*);  
} metNode_t;

typedef struct treeNode
{
  short int type;
  void* node;
  struct treeNode* root;
  struct treeNode* nodes[MAXNODE];
} treeNode_t;

objNode_t ObjCreate(int);
void initObj(objNode_t);

metNode_t MetCreate();
void initMet(metNode_t);

treeNode_t treeNodeCreate();
void initNodeCreate(treeNode_t);

int main(){
  printf("Hello world???\n");
  return 0;
}