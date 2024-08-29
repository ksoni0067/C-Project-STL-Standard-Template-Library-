#include<stdbool.h>

typedef struct {
    int * arr;
    int n;
    int capacity;
}Stack;

void stackInit(Stack* s);
void stackFree(Stack* s);
void resize(Stack* s,int new_capacity);
void push(Stack* s ,int val);
int pop(Stack* s);
int size(Stack* s);
bool isEmpty(Stack* s);
int top(Stack* s);
