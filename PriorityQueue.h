#include<stdbool.h>
#include<stdio.h>
typedef struct {
    void **pq;
    int n;                   
    int capacity;  
    int type;
    int (*comparator)(const void *, const void *);  // Comparator function

} PriorityQueue;

PriorityQueue* createPriorityQueue(bool min ,size_t type);
void insert(PriorityQueue *q, void *x,size_t type);
void* poll(PriorityQueue* q);
void* peek(PriorityQueue* q);
bool isEmpty(PriorityQueue* q);
int size(PriorityQueue* q);
void freePriorityQueue(PriorityQueue* q);

