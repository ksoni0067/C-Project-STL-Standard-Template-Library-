#include <stdlib.h>
#include <stdio.h>
 typedef struct Node {
    void* key;
    void* value;
    struct Node* next;
} Node;

typedef struct Hash {
    int n;     
    int N;     
    Node** bucket; 
    int (*hashFunction)(void* key, int N); 
    int (*compareKeys)(void* key1, void* key2); 
} Hash;

Hash* createHash(int (*hashFunction)(void* key, int N), int (*compareKeys)(void* key1, void* key2));
int containsKey(Hash* hashTable,void* key);
void* get(Hash* hashTable,void* key);
void put(Hash* hashTable,void* key,void* value);
void removeKey(Hash* hashTable,void* key);
int stringHashFunction(void* key,int N);
int IntegerHashFunction(void* key,int N);
int hashSize(Hash* hashTable);
int hashIsEmpty(Hash* hashTable);
int stringCompareKeys(void* key1, void* key2);
int integerCompare(void* key1,void* key2);
