#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    Stack stack;
    stackInit(&stack,sizeof(int));

    // Set the type for the stack to hold integers
 

    // Push integers onto the stack
    for (int i = 0; i < 5; i++) {
        int* value = (int*)malloc(sizeof(int));
        *value = i;
        stackPush(&stack, value,sizeof(int));
    }printf("size is %d",stackSize(&stack));

    // Set the type for the stack to hold strings
    // stack.type = sizeof(char*);    
    // // Allocate and push a string onto the stack
    // char* temp = (char*)malloc(sizeof(char) * 2); // Allocate memory for the string
    // temp[0] = 'k';
    // temp[1] = '\0'; // Null-terminate the string
    // stackPush(&stack, temp,sizeof(char));

    // Pop and print all elements
    while (!stackIsEmpty(&stack)) {
        void* item = stackPop(&stack);
        
        if (stack.type == sizeof(int)) {
            printf("Integer: %d\n", *(int*)item);
            free(item); // Free the allocated integer
        } else if (stack.type == sizeof(char*)) {
            printf("String: %s\n", (char*)item);
            free(item); // Free the allocated string
        }
    }

    stackFree(&stack);
    return 0;
}
