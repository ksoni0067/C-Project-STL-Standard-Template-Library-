
# C Data Structures and Algorithms Library

## Project Description


This project aims to create a collection of custom-built libraries in C for fundamental data structures and algorithms. It provides a simple, lightweight, and efficient implementation of various data structures like Hash Maps, PriorityQueue, LinkedList, ArrayList, Stacks, and Queues, along with essential algorithms for sorting, searching. This library is designed to be easily integrated into other C projects, allowing developers to utilize these data structures and algorithms without relying on external dependencies.
## Goals

* Educational Value: To provide an educational tool for understanding the implementation details of common data structures and algorithms in C.
* Efficiency: To implement these data structures and algorithms in a manner that ensures optimal performance.
* Reusability: To create reusable and modular code that can be easily integrated into other C projects.
* Flexibility: To allow customization and extension of the library to cater to different use cases and requirements.
## Specifications
### 1. Priority Queue
* Objective: Implement Priority Queue Data Structure with basic riorityQueue operations.
* Functions:
    * PriorityQueue* createPriorityQueue(bool min ,size_t type);          
    * void insert(PriorityQueue *q, void *x,size_t type);                 
    * void* poll(PriorityQueue* q);                                        
    * void* peek(PriorityQueue* q);                                        
    * bool PQisEmpty(PriorityQueue* q);
    * int PQsize(PriorityQueue* q);
    * void freePriorityQueue(PriorityQueue* q);

### 2. Sorting
* Objective: Implement various sorting algorithms, such as Bubble Sort, Quick Sort, Merge Sort, and Selection Sort.
* Functions:
    * void BubbleSort(int* arr, int size);
    * void MergeSort(int* arr,int left,int right);
    * void QuickSort(int* arr,int low ,int high);
    * void SelectionSort(int* arr,int size);
### 3. Searching
* Objective: Implement searching algorithms like Linear Search and Binary Search.
* Functions:
    * int BinarySearch(int* arr,int size,int target);
    * int LinearSearch(int* arr,int size,int target);
### 4. Hash Map
* Objective: Implement a hash map data structure using open addressing or chaining.
* Functions:
    * Hash* createHash(int (*hashFunction)(void* key, int N), int (*compareKeys)(void* key1, void* key2));        
    * int containsKey(Hash* hashTable,void* key);
    * void* get(Hash* hashTable,void* key);
    * void put(Hash* hashTable,void* key,void* value);
    * void removeKey(Hash* hashTable,void* key);
    * int stringHashFunction(void* key,int N);               
    * int IntegerHashFunction(void* key,int N);            
    * int hashSize(Hash* hashTable);
    * int hashIsEmpty(Hash* hashTable);
    * int stringCompareKeys(void* key1, void* key2);         
    * int integerCompare(void* key1,void* key2);            

### 5. Stack
* Objective: Implement a stack data structure with basic operations.
* Functions:
    * void stackInit(Stack* s,size_t type);
    * void stackPush(Stack* s ,void* val,size_t size);
    * void* stackPop(Stack* s);
    * void* stackTop(Stack* s);
    * int stackSize(Stack* s);
    * bool stackIsEmpty(Stack* s);
    * void stackFree(Stack* s);
### 7. Queue
* Objective: Implement a queue data structure with basic operations.
* Functions:
    * Queue* createQueue(size_t type);
    * void enqueue(Queue* q ,void* data,size_t type);
    * void* first(Queue* q);
    * void* dequeue(Queue* q);
    * int queueSize(Queue* q);
    * bool queueIsEmpty(Queue* q);
### 8. LinkedList 
* Objective:Implement a LinkedList Data Structure with basic operations.
* Functions:
   * LinkedList* createLinkedList(size_t type);
   * void insertAtHead(LinkedList* list ,void* data,size_t type);
   * void insertAtTail(LinkedList* list,void* data,size_t type);
   * void* peekLL(LinkedList* list);
   * void* popLL(LinkedList* list);
   * int sizeLL(LinkedList* list);
   * bool isEmptyLL(LinkedList* list);
 ### 9. ArrayList
 * Objective:Implement a ArrayList or Dynamic array Data Structure with basic operations.
 * Functions:
      * ArrayList* createArrayList(size_t type);
      * void addList(ArrayList* list,void* val,size_t type);
      * void* getList(ArrayList* list,int index);
      * void setList(ArrayList* list ,int index,void* val);
      * void* popList(ArrayList* list);
      * bool isEmptyList(ArrayList* list);
      * int sizeList(ArrayList* list);
##   Other Basic Functions :-
   * int abs(int num);
   * int min(int a,int b);
   * int max(int a,int b);
   * int power(int x,int n);
   * int sqroot(int num);

## Design

The design of the library focuses on modularity, reusability, and efficiency. Each data structure and algorithm is implemented in a separate file, with a corresponding header file to provide the necessary interface for other programs.

* Data Structures: Implemented using structures in C to encapsulate the data and provide operations as functions.
* Algorithms: Provided as standalone functions to be used with standard C arrays or custom data structures.
* Memory Management: Each function and data structure will manage memory efficiently, ensuring that there are no memory leaks or unnecessary memory usage.

## Commands to run 
* First download header file as your requirement from headerfiles folder
* Then in your main.c file include header file ,like:-
     * #include "HashMap.h"
     * #include "PriorityQueue.h"
* Run file in command line using command with linking library keshavSTL.a 
   * gcc main.c -L. keshavSTL.a
* You can see the output
  * ./a.out 
