#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashMap.h"

Node* createNode(void* key, void* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

int stringHashFunction(void* key, int N) {
    char* str = (char*)key;
    unsigned long hash = 0;
    int c=*str++;
    while (c>0) {
        hash = hash * 31 + c;
        c=*str++;
    }
    return hash % N;
}
int IntegerHashFunction(void* key, int N) {
    int temp = *(int*)key; 
    return abs(temp) % N;  
}

int stringCompareKeys(void* key1, void* key2) {
    return strcmp((char*)key1, (char*)key2) == 0;
}
int integerCompare(void* key1,void* key2){
    return (*(int*)key1==*(int*)key2);
}

Hash* createHash(int (*hashFunction)(void* key, int N), int (*compareKeys)(void* key1, void* key2)) {
    Hash* hashTable = (Hash*)malloc(sizeof(Hash));
    hashTable->n = 0;
    hashTable->N = 4;
    hashTable->bucket = (Node**)malloc(sizeof(Node*) * hashTable->N);
    for (int i = 0; i < hashTable->N; i++) {
        hashTable->bucket[i] = NULL;
    }
    hashTable->hashFunction = hashFunction;
    hashTable->compareKeys = compareKeys;
    return hashTable;
}

void rehash(Hash* hashTable) {
    int oldN = hashTable->N;
    Node** oldBuckets = hashTable->bucket;
    
    hashTable->N *= 2;
    hashTable->bucket = (Node**)malloc(sizeof(Node*) * hashTable->N);
    for (int i = 0; i < hashTable->N; i++) {
        hashTable->bucket[i] = NULL;
    }
    
    hashTable->n = 0;
    
    for (int i = 0; i < oldN; i++) {
        Node* current = oldBuckets[i];
        while (current) {
            Node* nextNode = current->next;
            int newIndex = hashTable->hashFunction(current->key, hashTable->N);
            current->next = hashTable->bucket[newIndex];
            hashTable->bucket[newIndex] = current;
            hashTable->n++;
            current = nextNode;
        }
    }
    free(oldBuckets);
}

void put(Hash* hashTable, void* key, void* value) {
    int index = hashTable->hashFunction(key, hashTable->N);
    Node* current = hashTable->bucket[index];
    Node* prev = NULL;
    
    while (current != NULL && !hashTable->compareKeys(current->key, key)) {
        prev = current;
        current = current->next;
    }
    
    if (current != NULL) {
        current->value = value;
    } else {
        Node* newNode = createNode(key, value);
        newNode->next = hashTable->bucket[index];
        hashTable->bucket[index] = newNode;
        hashTable->n++;
    }
    
    double loadFactor = (double)hashTable->n / hashTable->N;
    if (loadFactor > 2.0) {
        rehash(hashTable);
    }
}

void* get(Hash* hashTable, void* key) {
    int index = hashTable->hashFunction(key, hashTable->N);
    Node* current = hashTable->bucket[index];
    
    while (current != NULL) {
        if (hashTable->compareKeys(current->key, key)) {
            return current->value;
        }
        current = current->next;
    }
    fprintf(stderr,"Key is not found\n");
    exit(1);
    return NULL ; // Key not found
}

int containsKey(Hash* hashTable, void* key) {
     int index = hashTable->hashFunction(key, hashTable->N);
    Node* current = hashTable->bucket[index];
    
    while (current != NULL) {
        if (hashTable->compareKeys(current->key, key)) {
            return 1;
        }
        current = current->next;
    }
    return 0 ; 
}
void removeKey(Hash* hashTable, void* key) {
    int index = hashTable->hashFunction(key, hashTable->N);
    Node* current = hashTable->bucket[index];
    Node* prev = NULL;
    
    while (current != NULL && !hashTable->compareKeys(current->key, key)) {
        prev = current;
        current = current->next;
    }
    
    if (current != NULL) {
        if (prev != NULL) {
            prev->next = current->next;
        } else {
            hashTable->bucket[index] = current->next;
        }
        free(current);
        hashTable->n--;
    }
}
int hashSize(Hash* hashTable){
    return hashTable->n;
}
int hashIsEmpty(Hash* hashTable){
    return hashTable->n==0;
}

