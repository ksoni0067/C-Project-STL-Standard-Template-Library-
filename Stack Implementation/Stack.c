#include<stdio.h>
#include<assert.h>
#include<stdbool.h>
#include "Stack.h"
#include<stdlib.h>

void stackInit(Stack* s){
    s->arr=NULL;
    s->capacity=0;
    s->n=0;
}
void stackFree(Stack* s){
    free(s->arr);
    s->arr=NULL;
    s->capacity=0;
    s->n=0;
}
void resize(Stack* s,int new_capacity){
    if(new_capacity==0) new_capacity=1;
    int* arr=(int*)malloc(sizeof(int)*new_capacity);
    if(arr==NULL){
        perror("Error : Memory Allocation is failed");
        exit(1);
    }
    for(int i=0;i<s->n;i++){
        arr[i]=s->arr[i];
    }
    free(s->arr);
    s->arr=arr;
    s->capacity=new_capacity;

}
void push(Stack* s,int data){
    if(s->n==s->capacity){
        resize(s,s->capacity*2);
    }
    s->arr[s->n++]=data;

}
int top(Stack* s){
    if(s->n==0){
        fprintf(stderr,"Error: Stack is Empty\n");
        exit(1);
    }
    return s->arr[s->n-1];
}
int pop(Stack* s){
    if(s->n==0){
        fprintf(stderr,"Error: Stack is Empty\n");
        exit(1);
    }
    int item=s->arr[s->n-1];
    s->n--;
    if( s->n>0 && s->n<=s->capacity/4) resize(s,s->capacity/2);
    return item;
}
bool isEmpty(Stack* s){
    return s->n==0;
}
int size(Stack* s){
    return s->n;
}
