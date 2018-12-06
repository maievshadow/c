#include <stdlib.h>
#include <stdio.h>
#include "hash2.h"


size_t hash(void * key){
	size_t hash = 0;
	const char * k = (const char *)key;
	
	while (*k) {
		hash = hash*37 + *k++;
	}
	return hash;
}

size_t mycompare_equal(void * key1, void * key2){
	if((const char *)key1 == (const char *)key2)
		return(1);
	else
		return(0);
}

int
main(int argc, char ** argv)
{
    HashTable *ht ;

    ht = hashtable_initialize(5, hash, mycompare_equal);

	/*
    hashtable_add(ht, (void *)"1", (void *)"ONE");
    hashtable_add(ht, (void *)"3", (void *)"THREE");
    hashtable_add(ht, (void *)"2", (void *)"TWO");
    hashtable_add(ht, (void *)"4", (void *)"FOUR");
	*/

	hashtable_add(ht, "L", "80");
	hashtable_add(ht, "M", "50");
	hashtable_add(ht, "N", "60");

	printf("%s", (char*)hashtable_get(ht, "L"));
    printf("\nend\r\n");

	return 0;
}