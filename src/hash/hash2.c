#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hash2.h"

HashTable * hashtable_initialize(size_t size, hash_function fn, compare_equal efn){
	size_t i;
	HashTable * ht = (HashTable *) malloc( sizeof(HashTable) );

    if (ht == NULL) {
        printf("\nERROR: Cannot create hash table. Terminating...");
        exit(EXIT_FAILURE); // well... any other implementation could be added, instead of this.
    }

    ht->hf = fn;
	ht->eq = efn;
	ht->size = size;

	ht->table = (Item **) malloc(size * sizeof( Item * ));

    if (ht->table == NULL) {
        printf("\nERROR: Cannot create hash table. Terminating...");
        exit(EXIT_FAILURE); // well... any other implementation could be added, instead of this.
    }

    for(i=0; i<size; i++){
		ht->table[i] = NULL;
	}

	return(ht);
}

int hashtable_add(HashTable * ht, void * key, void * value){
	size_t hash = ht->hf(key);
	size_t hvalue = hash % ht->size;

	Item * newNode = NULL;
	Item * prevNode = NULL;
	Item * curNode = ht->table[hvalue];

    while (curNode && ht->eq(key, curNode->key) > 0) {
        prevNode = curNode;
        curNode = curNode->next;
    }

	if (curNode && (ht->eq(key, curNode->key) == 0))
		return -1;

	newNode = (Item *)malloc( sizeof(Item) ); //itemnext;
        
        // Making sure that memory was properly allocated for 'next'.
    if (newNode == NULL) {
        printf("\nERROR: Insufficient memory. Terminating....");
        exit(EXIT_FAILURE); // some other implementation could be used here.
    }

    newNode->key = key;
	newNode->value = value;

	if (prevNode) {
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    } else {
        newNode->next = ht->table[hvalue];
        ht->table[hvalue] = newNode;
    }

	printf("add key %s and locate %d success\n", (char*)key, hvalue);

	return(1);
}

int
hashtable_size(HashTable *ht)
{
	return ht->size;
}

void * hashtable_get(HashTable * ht, void * key)
{
	size_t hash = ht->hf(key);
	Item * cur = ht->table[ hash % ht->size ];

	while(cur){
		if(ht->eq( cur->key, key )){
			return( cur->value );
		}else{
			cur = cur->next;
		}
	}

	return NULL;
}