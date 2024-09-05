#include<stdio.h>
#include <stdlib.h>
#include "HashMap.h"
void printString(Hash* hashTable) {
    printf("[");
    for (int i = 0; i < hashTable->N; i++) {
        Node* current = hashTable->bucket[i];
        while (current != NULL) {
            printf("%s = %d, ", (char*)current->key, *(int*)current->value);
            current = current->next;
        }
    }
    printf("]\n");
}
void printInteger(Hash* hashTable) {
    printf("[");
    for (int i = 0; i < hashTable->N; i++) {
        Node* current = hashTable->bucket[i];
        while (current != NULL) {
            printf("%d = %d, ", *(int*)current->key, *(int*)current->value);
            current = current->next;
        }
    }
    printf("]\n");
}

int main() {
    Hash* hashTable = createHash(stringHashFunction, stringCompareKeys);
    Hash* m=createHash(IntegerHashFunction,integerCompare);
    

    int value1 = 2;
    int value2 = 42;
    int value3 = 34;
    int value4 = 920;
    int value5 = 43;
    int key1 = 73;
    int key2 = 383;
    int key3 = 3993;
    int key4 = 393;
    int key5 = 3939;
    printf("Integer map is empty :%s\n",hashIsEmpty(m)? "Yes" :"No");

    put(hashTable, "keshav", &value1);
    put(hashTable, "king", &value2);
    put(m, &key1, &value1);
    put(m, &key2, &value2);
    printf("%d\n", *(int*)get(hashTable, "keshav"));
   // printf("%d\n", *(int*)get(hashTable, "jack")); // Should print 0 or NULL since 'jack' is not in the hash table
    printf("%d\n", hashTable->n);
    put(hashTable, "singh", &value3);
    put(hashTable, "ks", &value4);
    put(hashTable, "kj", &value5);
     put(m, &key3, &value3);
    put(m, &key4, &value4);
    put(m, &key5, &value5);
      printf("key4 is %d\n", *(int*)get(m, &key4));
        printf("key5 is%d\n", *(int*)get(m, &key5));
    printf("%d\n", containsKey(hashTable, "kj"));
    printf("%d\n", containsKey(m, &key3));
    printf("size of Integer mao is %d\n",hashSize(m));
    
    removeKey(hashTable, "kj");
     printf("%d\n", containsKey(hashTable, "kj"));
    printString(hashTable);
    printInteger(m);

    return 0;
}
