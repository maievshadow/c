#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct nlist{
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s){
	unsigned hashval;
	for(hashval=0;*s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval * HASHSIZE;
}

struct nlist *lookup(char *s){
	struct nlist *np;
	for(np=hashtab[hash(s)]; np != NULL;np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

char *sstrdup(char *s){
	char *p;
	p = (char *) malloc(strlen(s)+1); 
	if (p != NULL)
		strcpy(p, s);
	return p;
}

struct nlist *install(char *name, char *defn){
	struct nlist *np;
	unsigned hashval;
	if ((np=lookup(name)) == NULL){
		np = (struct nlist *) malloc(sizeof(*np));
		if (NULL == np  || (np->name = strdup(name)) == NULL){
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
		}
	}else
		free((void*)np->defn);

	if ((np->defn = strdup(defn)) == NULL)
		return NULL;
	return np;
}


int main(void){
	install("maiev", "maiev");
	return 0;
}

double* xx(){
	double x = 1.1;
	double *px = &x;
	printf("px in xx is %p\n", px);
	printf("x in xx is %f\n", *px);
	return px;
}
