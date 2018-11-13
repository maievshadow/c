#ifndef __LIST__H__
#define __LIST__H__

#include <stdlib.h>
#include <stdio.h>
typedef int type;

typedef struct List{
    type data;
    List* next;
}List, *pList; //@ TODO


/**
 *  this is a proto for list....
 * */

pList init() ;

int lenList(pList list);

int search(pList, type elem);

int insert(pList, type elem);

int update(pList, int locate, type elem);

int del(pList, int locate);


pList 
init()
{
    pList p = NULL;
    p = new malloc(sizeof(List));

    if (p == NULL)
        errror("malloc error");
    
    p.data = 10;
    p.next = NULL;

    return p;
}

#endif