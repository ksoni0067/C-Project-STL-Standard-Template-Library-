#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"

int main() {
    // Create a max-heap priority queue for integers
    PriorityQueue* maxPQ = createPriorityQueue(false, sizeof(int));
    
    int a = 10, b = 20, c = 5;

    // Insert elements
    insert(maxPQ, &a, sizeof(int));
    insert(maxPQ, &b, sizeof(int));
    insert(maxPQ, &c, sizeof(int));

    // Display size
    printf("Max PQ size: %d\n", PQsize(maxPQ));  // Output: 3

    // Peek at the top element
    int *maxTop = (int *)peek(maxPQ);
    printf("Top of Max PQ: %d\n", *maxTop);  // Output: 20

    // Poll elements and print
    while (!PQisEmpty(maxPQ)) {
        int *maxElem = (int *)poll(maxPQ);
        printf("Polled from Max PQ: %d\n", *maxElem);  // Output: 20, 10, 5
    }

    // Free the max-heap priority queue
    freePriorityQueue(maxPQ);

    // Create a min-heap priority queue for integers
    PriorityQueue* minPQ = createPriorityQueue(true, sizeof(int));
    
    insert(minPQ, &a, sizeof(int));
    insert(minPQ, &b, sizeof(int));
    insert(minPQ, &c, sizeof(int));
    // char r='w';
    // insert(minPQ,&r,sizeof(r));

float f=23.34;
insert(minPQ,&f,sizeof(f));
    // Display size
    printf("Min PQ size: %d\n", PQsize(minPQ));  // Output: 3

    // Peek at the top element
    int *minTop = (int *)peek(minPQ);
    printf("Top of Min PQ: %d\n", *minTop);  // Output: 5

    // Poll elements and print
    while (PQsize(minPQ)>1) {
        int *minElem = (int *)poll(minPQ);
        printf("Polled from Min PQ: %d\n", *minElem);  // Output: 5, 10, 20
    }
        printf("Polled from Min PQ: %f\n", *(float*)poll(minPQ));  // Output: 5, 10, 20;


    // Free the min-heap priority queue
    freePriorityQueue(minPQ);

    return 0;
}
