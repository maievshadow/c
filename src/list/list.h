#ifndef __LIST__H__
#define __LIST__H__

typedef int type;

typedef struct List{
    type data;
    struct List* next;
}List, *pList; //@ TODO

pList 
init(void);

pList
init2(pList*);

int 
lenList(pList );

int 
search(pList, type);

int 
insert(pList, int, type);

int
insert2(pList *, type);

int 
update(pList, int, type);

int 
del(pList, int);

#endif