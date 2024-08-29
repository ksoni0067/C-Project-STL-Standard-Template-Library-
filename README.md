
# C Data Structures and Algorithms Library

## Project Description


This project aims to create a collection of custom-built libraries in C for fundamental data structures and algorithms. It provides a simple, lightweight, and efficient implementation of various data structures like Hash Maps, Hash Sets, Stacks, and Queues, along with essential algorithms for sorting, searching, encoding, and decoding. This library is designed to be easily integrated into other C projects, allowing developers to utilize these data structures and algorithms without relying on external dependencies.
## Goals

* Educational Value: To provide an educational tool for understanding the implementation details of common data structures and algorithms in C.
* Efficiency: To implement these data structures and algorithms in a manner that ensures optimal performance.
* Reusability: To create reusable and modular code that can be easily integrated into other C projects.
* Flexibility: To allow customization and extension of the library to cater to different use cases and requirements.
## Specifications
### 1. Encoding and Decoding
* Objective: Implement basic encoding and decoding algorithms such as Base64, URL encoding, and simple ciphers.
* Functions:
    * char* encode_base64(const char* input);
    * char* decode_base64(const char* input);
### 2. Sorting
* Objective: Implement various sorting algorithms, such as Bubble Sort, Quick Sort, Merge Sort, and Insertion Sort.
* Functions:
    * void bubble_sort(int* array, int size);
    * void quick_sort(int* array, int low, int high);
    * void merge_sort(int* array, int left, int right);
    * void insertion_sort(int* array, int size);
### 3. Searching
* Objective: Implement searching algorithms like Linear Search and Binary Search.
* Functions:
    * int linear_search(int* array, int size, int target);
    * int binary_search(int* array, int size, int target);
### 4. Hash Map
* Objective: Implement a hash map data structure using open addressing or chaining.
* Functions:
    * void put(HashMap* map, const char* key, int value);
    * int get(HashMap* map, const char* key);
    * void remove(HashMap* map, const char* key);
    * int size();

### 5. Stack
* Objective: Implement a stack data structure with basic operations.
* Functions:
    * void push(Stack* stack, int value);
    * int pop(Stack* stack);
    * bool isEmpty(Stack* stack);
    * int size(Stack* stack);
    * int top(Stack* stack);
    * void stackInit(Stack* stack);
    * void stackFree(Stack* stack);
### 7. Queue
* Objective: Implement a queue data structure with basic operations.
* Functions:
    * void add(Queue* queue, int value);
    * int poll(Queue* queue);
    * bool isEmpty(Queue* queue);
## Design

The design of the library focuses on modularity, reusability, and efficiency. Each data structure and algorithm is implemented in a separate file, with a corresponding header file to provide the necessary interface for other programs.

* Data Structures: Implemented using structures in C to encapsulate the data and provide operations as functions.
* Algorithms: Provided as standalone functions to be used with standard C arrays or custom data structures.
* Memory Management: Each function and data structure will manage memory efficiently, ensuring that there are no memory leaks or unnecessary memory usage.
