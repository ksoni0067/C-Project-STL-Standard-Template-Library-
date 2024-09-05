#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Queue.h"
Queue* createQueue(size_t type){
    Queue* q=(Queue*)malloc(sizeof(Queue));
    if(q==NULL){
        fprintf(stderr,"Error : Queue is not Initialized\n");
        exit(1);
    }
    q->list=createLinkedList(type);
    return q;
}
void enqueue(Queue* q,void* data,size_t type){
    insertAtTail(q->list,data,type);
}
void* first(Queue* q){
    return peekLL(q->list);
}
void* dequeue(Queue* q){
    return popLL(q->list);
}
int queueSize(Queue* q){
    return sizeLL(q->list);
}
bool queueIsEmpty(Queue* q){
    return isEmptyLL(q->list);
}


