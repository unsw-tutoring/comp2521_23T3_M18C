#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdbool.h>
#include <stdio.h>

typedef struct hashTable *HashTable;

HashTable HashTableNew(void);
void HashTableFree(HashTable ht);
void HashTableInsert(HashTable ht, int key, int value);
bool HashTableContains(HashTable ht, int key);
int HashTableGet(HashTable ht, int key);
void HashTableDelete(HashTable ht, int key);
int HashTableSize(HashTable ht);

#endif
