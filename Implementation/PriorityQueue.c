#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PriorityQueue.h"

int MaxComparator(const void *a, const void *b) {
    int intA = *(int*)a;
    int intB = *(int*)b;
    return (intA > intB) - (intA < intB);  // Returns 1 if intA > intB, -1 if intA < intB, 0 otherwise
}

int MinComparator(const void *a, const void *b) {
    int intA = *(int*)a;
    int intB = *(int*)b;
    return (intA < intB) - (intA > intB);  // Returns 1 if intA < intB, -1 if intA > intB, 0 otherwise
}

PriorityQueue* createPriorityQueue(bool min_heap, size_t type) {
    PriorityQueue* q = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    q->pq = (void**)malloc(sizeof(void*) * 2);  
    q->n = 0;
    q->capacity = 2;
    q->type = type;
    if (min_heap)
        q->comparator = MinComparator;
    else
        q->comparator = MaxComparator;
    return q;
}

void resizePQ(PriorityQueue* q, int new_capacity) {
    void** arr = (void**)malloc(sizeof(void*) * new_capacity);
    if (arr == NULL) {
        perror("Error: Memory allocation failed");
        exit(1);
    }
    for (int i = 1; i <= q->n; i++) {
        arr[i] = q->pq[i];
    }
    free(q->pq);
    q->pq = arr;
    q->capacity = new_capacity;
}

void exch(void** pq, int i, int j) {
    void *temp = pq[i];
    pq[i] = pq[j];
    pq[j] = temp;
}

void swim(PriorityQueue* q, int k) {
    while (k > 1 && q->comparator(q->pq[k / 2], q->pq[k]) < 0) {
        exch(q->pq, k / 2, k);
        k = k / 2;
    }
}

void sink(PriorityQueue* q, int k) {
    while (2 * k <= q->n) {
        int j = 2 * k;
        if (j < q->n && q->comparator(q->pq[j], q->pq[j + 1]) < 0) j++;
        if (q->comparator(q->pq[k], q->pq[j]) >= 0) break;
        exch(q->pq, k, j);
        k = j;
    }
}

void insert(PriorityQueue* q, void* x, size_t type) {
    if (q->type != type) {
        fprintf(stderr, "Error: Datatype Mismatched\n");
        exit(1);
    }
    if (q->n + 1 == q->capacity) {
        resizePQ(q, q->capacity * 2);
    }
    q->pq[++q->n] = x;
    swim(q, q->n);
}

void* poll(PriorityQueue* q) {
    if (q->n == 0) {
        printf("Priority queue underflow\n");
        exit(1);
    }
    void* item = q->pq[1];
    exch(q->pq, 1, q->n--);
    sink(q, 1);
    q->pq[q->n + 1] = NULL; 
    if (q->n > 0 && q->n <= q->capacity / 4) {
        resizePQ(q, q->capacity / 2);
    } 
    return item;
}

void* peek(PriorityQueue* q) {
    if (q->n == 0) {
        printf("Priority queue underflow\n");
        exit(1);
    }
    return q->pq[1];
}

bool PQisEmpty(PriorityQueue* pq) {
    return pq->n == 0;
}

int PQsize(PriorityQueue* pq) {
    return pq->n;
}

void freePriorityQueue(PriorityQueue* pq) {
    free(pq->pq);
    free(pq);
}
