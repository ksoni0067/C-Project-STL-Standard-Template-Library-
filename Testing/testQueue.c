#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main() {
    // Create a Queue for integers
    Queue* intQueue = createQueue(sizeof(int));

    // Test queuePush
    int a = 10, b = 20, c = 30;
    enqueue(intQueue, &a, sizeof(int));
    enqueue(intQueue, &b, sizeof(int));
    enqueue(intQueue, &c, sizeof(int));

    // Test queueSize
    printf("Queue size after 3 pushes: %d\n", queueSize(intQueue));

    // Test queuePeek
    int* peeked = (int*)first(intQueue);
    printf("Peeked value: %d\n", *peeked);

    // Test queuePop
    int* popped = (int*)dequeue(intQueue);
    printf("Popped value: %d\n", *popped);

    // Test queueSize after pop
    printf("Queue size after 1 pop: %d\n", queueSize(intQueue));

    // Test queueIsEmpty
    printf("Is queue empty? %s\n", queueIsEmpty(intQueue) ? "Yes" : "No");

    // Test popping all elements
    popped = (int*)dequeue(intQueue);
    printf("Popped value: %d\n", *popped);
    popped = (int*)dequeue(intQueue);
    printf("Popped value: %d\n", *popped);

    // Check if the queue is empty now
    printf("Queue size after popping all elements: %d\n", queueSize(intQueue));
    printf("Is queue empty? %s\n", queueIsEmpty(intQueue) ? "Yes" : "No");

    // Clean up
    free(intQueue);

    return 0;
}
