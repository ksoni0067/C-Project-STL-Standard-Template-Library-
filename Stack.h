#include<stdbool.h>
#include<stddef.h>
typedef struct {
    void** arr;
    int n;
    int capacity;
    size_t type;
}Stack;

void stackInit(Stack* s,size_t type);
void stackFree(Stack* s);
void push(Stack* s ,void* val,size_t size);
void* pop(Stack* s);
int size(Stack* s);
bool isEmpty(Stack* s);
void* top(Stack* s);
