#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"LinkedList.h"

LinkedList* createLinkedList(size_t type){
    LinkedList* temp=(LinkedList*)malloc(sizeof(LinkedList));
    if( temp==NULL){
        fprintf(stderr," Error : Memory Allocation is Fail\n");
        exit(1);
    }
    temp->head=NULL;
    temp->tail=NULL;
    temp->type=type;
    temp->size=0;
    return temp;
}
void insertAtHead(LinkedList* list,void* data,size_t type){
    if( list->type!=type){
        fprintf(stderr,"Error : Datatype Mismatched\n");
        exit(1);
    }
    Node* temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL){
        fprintf(stderr," Error : Node is not Created\n");
        exit(1);
    }
    temp->data=data;
    temp->data = data;
    temp->next = list->head;  

    list->head = temp;
    if (list->tail == NULL) {
        list->tail = temp;  
    }
    list->size++;
}
void insertAtTail(LinkedList* list,void* data,size_t type){
    if( list->type!=type){
        fprintf(stderr,"Error : Datatype Mismatched\n");
        exit(1);
    }
    Node* temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL){
        fprintf(stderr," Error : Node is not Created\n");
        exit(1);
    }
    temp->data=data;
    temp->next=NULL;
    list->size++;
    if( list->head==NULL){
        list->head=temp;
        list->tail=temp;
    }
    else{
       list->tail->next=temp;
       list->tail=temp;
    }
}
void* peek(LinkedList* list){
    if(list->size==0){
        fprintf(stderr,"Error : List isEmpty\n");
        exit(1);
    }
    void* item=list->head->data;
    return item;
}
void* pop(LinkedList* list){
     if(list->size==0){
        fprintf(stderr,"Error : List isEmpty\n");
        exit(1);
    }
    Node* temp=list->head;
    list->head=list->head->next;
    void* item=temp->data;
    temp->next=NULL;
    free(temp);
    list->size--;
    if(list->head==NULL){
        list->tail=NULL;
    }
    return item;
}

int size(LinkedList* list){
    return list->size;
}
bool isEmpty(LinkedList* list){
    return list->size==0;
}