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
void add(ArrayList* list,void* val,size_t type);
void* get(ArrayList* list,int index);
void set(ArrayList* list ,int index,void* val);
void* pop(ArrayList* list);
bool isEmpty(ArrayList* list);
int size(ArrayList* list);