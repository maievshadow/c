#ifndef __LIST__H__
#define __LIST__H__

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

typedef int type;

typedef struct List{
    type data;
    List* next;
}List, *pList; //@ TODO


/**
 *  this is a proto for list....
 * */

pList init() ;

int 
lenList(pList );

int 
search(pList, type);

int 
insert(pList, type);

int 
update(pList, int, type);

int 
del(pList, int);

pList 
init()
{
    pList p = NULL;
    p = (p)malloc(sizeof(List));

    if (p == NULL)
        perror("malloc error");
    
    p->data = 0;
    p->next = NULL;

    return p;
}

/*
pList
head(pList p)
{
    pList head = NULL;
    head = (p)malloc(sizeof(List)); 

    head->data = 0;
    head->next = NULL;

    p->next = head;
}
*/

int
lenList(pList p)
{ 
    return 1;
}

int 
insert(plist list, type elem)
{
    pList p = NULL;
    p = (p)malloc(sizeof(List));

    p->data = elem;
    p->next = NULL;
    
    pList tmp;

    while (list->next != NULL)
    {
        list = list->next;
    }

    list->next = p;
}

int 
update(pList list, int locate, type elem)
{
    int len = 0;
    pList tmp;
    while (tmp->next != NULL && len == locate)
    {
        tmp = list->next;
    }

    list->data = elem;
}

int 
search(pList list, type elem)
{
    pList p = list->next;
    while (p->next != NULL && p->data != elem)
    {
        p = list->next;
    }

    return 1; 
}

int 
del(pList list, int locate)
{
    int len = 0;
    pList tmp = list->next;
    while (tmp->next != NULL && len == locate)
    {
        tmp = list->next;
    }

    free(tmp);
}

#endif