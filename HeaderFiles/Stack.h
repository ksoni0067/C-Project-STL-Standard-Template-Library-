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
void stackPush(Stack* s ,void* val,size_t size);
void* stackPop(Stack* s);
int stackSize(Stack* s);
bool stackIsEmpty(Stack* s);
void* stackTop(Stack* s);
