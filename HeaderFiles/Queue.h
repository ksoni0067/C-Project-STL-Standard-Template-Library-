#include<stdbool.h>
#include "LinkedList.h"

typedef struct{
    LinkedList* list;
} Queue;
Queue* createQueue(size_t type);
void enqueue(Queue* q ,void* data,size_t type);
void* first(Queue* q);
void* dequeue(Queue* q);
int queueSize(Queue* q);
bool queueIsEmpty(Queue* q);
