#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    void** arr;   
    int size;     
    int capacity; 
    size_t type;
} ArrayList;

ArrayList* createArrayList(size_t type);
void addList(ArrayList* list,void* val,size_t type);
void* getList(ArrayList* list,int index);
void setList(ArrayList* list ,int index,void* val);
void* popList(ArrayList* list);
bool isEmptyList(ArrayList* list);
int sizeList(ArrayList* list);