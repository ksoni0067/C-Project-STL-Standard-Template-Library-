#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h>
#include "LinkedList.h"


int main() {
    
    LinkedList* list = createLinkedList(sizeof(int));
    if (list == NULL) {
        printf("Failed to create list\n");
        return 1;
    }

    
    if (isEmptyLL(list)) {
        printf("List is initially empty.\n");
    } else {
        printf("List is not empty initially.\n");
    }

    
    int data1 = 10;
    int data2 = 20;
    float f=20.223;
    insertAtHead(list, &data1, sizeof(int));
    insertAtHead(list, &data2, sizeof(int));
    // insertAtHead(list, &f, sizeof(f));
    // char c='k';
    // insertAtHead(list,&c ,sizeof(c));        // show error of datatype mismatch

    
    printf("Size after inserting two elements at head: %d\n", sizeLL(list));

    
    // float* peekedData = (float*)peekLL(list);
    // printf("Peeked element: %f\n", *peekedData);
    int* peekedData = (int*)peekLL(list);
    printf("Peeked element: %d\n", *peekedData);

    
    int data3 = 30;
    insertAtTail(list, &data3, sizeof(int));

    
    printf("Size after inserting one element at tail: %d\n", sizeLL(list));

    
    int* poppedData1 = (int*)popLL(list);
    printf("Popped element: %d\n", *poppedData1);

    int* poppedData2 = (int*)popLL(list);
    printf("Popped element: %d\n", *poppedData2);

    int* poppedData3 = (int*)popLL(list);
    printf("Popped element: %d\n", *poppedData3);

   
    if (isEmptyLL(list)) {
        printf("List is empty after popping all elements.\n");
    } else {
        printf("List is not empty after popping all elements.\n");
    }

    // Try peeking from an empty list (should give an error)
    // Commented out to prevent the program from stopping
    // peekLL(list);

    // Try popping from an empty list (should give an error)
    // Commented out to prevent the program from stopping
    // popLL(list);

    // Clean up
    free(list);

    return 0;
}
