#include<stdio.h>
#include"BasicSTL.h"
#include <stdlib.h>
#include<time.h>
int main() {
    srand(time(0));
    int n;
    n=rand()%40;
    int* arr=(int*)malloc(sizeof(int)*n);
    for ( int i=0;i<n;i++){
       arr[i]=rand()%200;
    } 
    printf("Before Sort\n");
    for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    MergeSort(arr,0,n-1);
     for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    for ( int i=0;i<n;i++){
       arr[i]=rand()%200;
    } 
    BubbleSort(arr,n);
     for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    for ( int i=0;i<n;i++){
       arr[i]=rand()%200;
    } 
    SelectionSort(arr,n);
     for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    for ( int i=0;i<n;i++){
       arr[i]=rand()%200;
    } 
    QuickSort (arr,0,n-1);
    printf("\nAfter Sort\n");
    for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
    printf("min : %d\n",min(23,4));
    printf("max : %d\n",max(7827,293));
    printf("abs of -89 : %d\n",abs(-89));
    printf("power of 3^4 : %d\n",power(3,4));
    printf("sqrt  of 56 ,64 :%d %d \n",sqroot(56),sqroot(64));

    return 0;
}