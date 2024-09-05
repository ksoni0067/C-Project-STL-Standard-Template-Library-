#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ArrayList.h"

void printArrayList(ArrayList* list) {
    printf("[");
    for (int i = 0; i < list->size; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%d", *(int*)list->arr[i]);
    }
    printf("]\n");
}

// Main function to test the ArrayList
int main() {
    ArrayList* arr = createArrayList(sizeof(int));
    
    int val1 = 12;
    int val2 = 23;
    int val3 = 45;
    int val4 = 34;
    
    addList(arr, &val1,sizeof(int));
    addList(arr, &val2,sizeof(int));
    addList(arr, &val3,sizeof(int));
    addList(arr, &val4,sizeof(int));

    
    for (int i = 0; i < sizeList(arr); i++) {
        printf("%d  ", *(int*)getList(arr, i));
    }
    printf("\n");
    float f=839.9992;

    addList(arr,&f ,sizeof(f));
     printf("%f   ", *(float*)popList(arr));
    printf(" empty :%d\n" ,isEmptyList(arr));
    printf(" size :%d\n" ,sizeList(arr));
    printArrayList(arr);
    addList(arr, &val2,sizeof(int));
    addList(arr, &val3,sizeof(int));
    addList(arr, &val4,sizeof(int));
    setList(arr,3,&val1);
    printArrayList(arr);

    // Free allocated memory
    free(arr->arr);
    free(arr);
    
    return 0;
}