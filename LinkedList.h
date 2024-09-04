#include<stdbool.h>
#include<stdio.h>
typedef struct Node{
  void* data;
  struct Node* next;
} Node;

typedef struct{
    Node* head;
    Node* tail;
    int size;
    size_t type;
 } LinkedList;
LinkedList* createLinkedList(size_t type);
void insertAtHead(LinkedList* list ,void* data,size_t type);
void insertAtTail(LinkedList* list,void* data,size_t type);
void* peek(LinkedList* list);
void* pop(LinkedList* list);
int size(LinkedList* list);
bool isEmpty(LinkedList* list);
