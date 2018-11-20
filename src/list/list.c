#include <stdlib.h>
#include <stdio.h>
#include <sys/malloc.h>

#include "list.h"

pList 
init(void)
{
    pList p = NULL;
    p =(pList)malloc(sizeof(List));

    if (p == NULL)
        perror("malloc error\n");
    
    p->data = 0;
    p->next = NULL;

    printf("init\n");
    return p;
}

pList
init2(pList p)
{
   p = NULL; 
}

int
lenList(pList list)
{ 
    int len = 0;
    pList tmp = list;
    while (tmp->next != NULL){
        ++len;
        tmp = list->next;
    }
    
    printf("the list len is %d\n", len);
    return len;
}

int 
insert(pList list, int locate, type elem)
{
    pList p = NULL;
    p = (pList)malloc(sizeof(List));

    if ( NULL == p){
        printf("malloc error\n");
        exit(0);
    }

    pList tmp = list;
    while (tmp->next != NULL)
        tmp = tmp->next;

    p->data = elem;
    p->next = tmp->next;
    tmp->next = p;
}

int 
update(pList list, int locate, type elem)
{
    int len = 0;
    pList tmp = list;
    while (tmp->next != NULL && len == locate)
    {
        tmp = list->next;
    }

    list->data = elem;
}

int 
search(pList list, type elem)
{
    pList p = list;
    int i = 0;
    while (p != NULL && p->data != elem)
    {
        ++i;
        p = p->next;
    }

    if (p == NULL)
        printf("not found\n");
    else
        printf("found elem is %d\n", i);
    return i;
}

int 
del(pList list, int locate)
{
    int len = 0;
    pList tmp = list;
    while (tmp->next != NULL && len == locate)
    {
        tmp = list->next;
    }

    free(tmp);
}

void listTest()
{
    pList list;
    list = init();
    //type a = 1;
    insert(list, 0, 1);
    lenList(list);
    search(list, 1);
}

 
