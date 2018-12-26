#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "hash.h"

HashTable * hashtable_initialize(size_t size, size_t mc, size_t gf, hash_function fn, compare_equal efn){
	size_t i;
	HashTable * ht = (HashTable *) malloc( sizeof(HashTable) );

    if (ht == NULL) {
        printf("\nERROR: Cannot create hash table. Terminating...");
        exit(EXIT_FAILURE); // well... any other implementation could be added, instead of this.
    }

    ht->hf = fn;
	ht->eq = efn;
	ht->size = size;
	ht->maxCollisions = mc;
	ht->growthFactor = gf;

	ht->table = (Item **) malloc(size * sizeof( Item * ));

    if (ht->table == NULL) {
        printf("\nERROR: Cannot create hash table. Terminating...");
        exit(EXIT_FAILURE); // well... any other implementation could be added, instead of this.
    }

    for(i=0; i<size; i++){
		ht->table[i] = 0;
	}

	return(ht);
}

int hashtable_resize(HashTable * ht, size_t size){
	HashTable * newht = hashtable_initialize(size, ht->maxCollisions, ht->growthFactor, ht->hf, ht->eq);
	int i;
	Item * next;

	// Re-enter all the items again into the new hashtable 
	// with the new size.
	for(i=0; i<ht->size; i++){
		if(ht->table[i]){
			for(next=ht->table[i]; next; next=next->next){
				hashtable_add(newht, next->key, next->value);
			}
		}

		hashtable_remove(ht, ht->table[i]->key);
	}

	free(ht->table);
	newht->size = ht->size;
	newht->table = ht->table;

	return(1);
}

int hashtable_remove(HashTable * ht, void * key){
	size_t hash = ht->hf(key);
	Item * next = ht->table[ hash % ht->size ];
	Item * prev = 0;

	while(next){
		if(ht->eq( next->key, key )){
			if(prev){
				prev->next = next->next;
			}else{
				ht->table[ hash % ht->size ] = next->next;
			}

			free(next);

			return(1);
		}

		prev = next;
		next = next->next;
	}

	return(0);
}


int hashtable_add(HashTable * ht, void * key, void * value){
	size_t hash = ht->hf(key);
	Item * next = ht->table[ hash % ht->size ];
	size_t i = 0;

	while(next){
		// Replace data if key is same
		if(ht->eq( next->key, key )){
			next->value = value;
			return(1);
		}

		next = next->next;
		i++;
	}

	next = (Item *)malloc( sizeof(Item) );
        
        // Making sure that memory was properly allocated for 'next'.
    if (next == NULL) {
        printf("\nERROR: Insufficient memory. Terminating....");
        exit(EXIT_FAILURE); // some other implementation could be used here.
    }

    next->key = key;
	next->value = value;
	next->next = ht->table[ hash % ht->size ];
	ht->table[ hash % ht->size ] = next;

	if(i >= ht->maxCollisions){
		hashtable_resize(ht, ht->size + ht->growthFactor);
	}

	return(1);
}