#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ArrayList.h"


ArrayList* createArrayList(size_t type) {
    ArrayList* list = (ArrayList*)malloc(sizeof(ArrayList));
    list->arr = (void**)malloc(sizeof(void*) * 1);
    list->size = 0;
    list->capacity = 1;
    list->type=type;
    return list;
}

void resize(ArrayList* list, int new_capacity) {
    if (new_capacity == 0) new_capacity = 1;
    void** arr = (void**)malloc(sizeof(void*) * new_capacity);
    if (arr == NULL) {
        perror("Error: Memory allocation failed");
        exit(1);
    }
    for (int i = 0; i <list->size; i++) {
        arr[i] = list->arr[i];
    }
    free(list->arr);
    list->arr = arr;
    list->capacity = new_capacity;
}


void add(ArrayList* list, void* val,size_t type) {
    if(list->type!=type){
        fprintf(stderr,"Error : Datatype is Mismatched\n");
        exit(1);
    }
    if (list->size == list->capacity) {
        resize(list,list->capacity*2);
    }
    list->arr[list->size++] = val;
}


void* get(ArrayList* list, int index) {
    if (index >= list->size) {
        fprintf(stderr,"Error : Index out of Bound");
        exit(1);
    }
    return list->arr[index];
}


void set(ArrayList* list, int index, void* val) {
    if (index >= list->size) {
        printf("Not Found in List\n");
        return;
    }
    list->arr[index] = val;
}

void* pop(ArrayList* list){
    if(list->size==0){
        fprintf(stderr, "Error: ArrayList is Empty\n");
        exit(1);
    }
    void* item=list->arr[--list->size];
    if( list->size >0 && list->size <=list->capacity/2){
        resize(list,list->capacity/2);
    }
    return item;

}
 
bool isEmpty(ArrayList* list) {
    return list->size == 0;
}


int size(ArrayList* list) {
    return list->size;
}

