#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack.h"
#include<stdlib.h>

void stackInit(Stack* s,size_t type) {
    s->arr = NULL;
    s->capacity = 0;
    s->n = 0;
    s->type = type;
}

void stackFree(Stack* s) {
    free(s->arr);
    s->arr = NULL;
    s->capacity = 0;
    s->n = 0;
    s->type = 0;
}

void resize(Stack* s, int new_capacity) {
    if (new_capacity == 0) new_capacity = 1;
    void** arr = (void**)malloc(sizeof(void*) * new_capacity);
    if (arr == NULL) {
        perror("Error: Memory allocation failed");
        exit(1);
    }
    for (int i = 0; i < s->n; i++) {
        arr[i] = s->arr[i];
    }
    free(s->arr);
    s->arr = arr;
    s->capacity = new_capacity;
}

void push(Stack* s, void* data,size_t size) {
    if (s->type != size) {
        fprintf(stderr, "Error: Data type mismatch\n");
        exit(1);
    }
    if (s->n == s->capacity) {
        resize(s,  s->capacity * 2);
    }
    s->arr[s->n++] = data;
}

void* top(Stack* s) {
    if (s->n == 0) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(1);
    }
    return s->arr[s->n - 1];
}

void* pop(Stack* s) {
    if (s->n == 0) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(1);
    }
    void* item = s->arr[--s->n];
    if (s->n > 0 && s->n <= s->capacity / 4) {
        resize(s, s->capacity / 2);
    }
    return item;
}

bool isEmpty(Stack* s) {
    return s->n == 0;
}

int size(Stack* s) {
    return s->n;
}
