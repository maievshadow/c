#include <stdio.h>
#include <stdlib.h>

#include "list.h"

/**
 *  no head and head node
 *  start loop attention
 * 
 **/

void 
init(pList *head)
{
    pList p = NULL;
    p =(pList)malloc(sizeof(List));

    if (p == NULL)
        perror("malloc error\n");
    
    p->data = 0;
    p->next = NULL;

    *head = p;

    printf("init\n");
   //@TODO
   //*head = NULL;
}

int
lenList(pList list)
{ 
    int len = 0;
    pList tmp = list;
    while (tmp != NULL){
        ++len;
        tmp = tmp->next;
    }
    
    printf("the list len is %d\n", len);
    return len;
}

int 
insert(pList *head,  int locate, type elem)
{
    pList p = NULL;
    p = (pList)malloc(sizeof(List));
    if (NULL == p) {
        printf("malloc error\n");
        exit(0);
    }
    p->data = elem;
    p->next = NULL;

    if (NULL == head) {
        *head = p;
    } else {
        pList tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }

        tmp->next = p;
        p->next = NULL;

        return 1;
    }
}

int update(pList list, int locate, type elem)
{
    int len = 0;
    pList tmp = list;
    while (tmp->next != NULL && len != locate) {
        ++len;
        tmp = tmp->next;
    }

    tmp->data = elem;

    printf("update %d locate %d\n", elem, len);
}

int 
search(pList list, type elem)
{
    pList p = list;
    int i = 0;
    while (p->next != NULL && p->data != elem)
    {
        p = p->next;
        ++i;
    }

    //@TODO
    printf("found elem is %d\n", i);
    /*
    if (p == NULL)
        printf("%d not found\n", elem);
    else
        printf("found elem is %d\n", i);
        */
    return i;
}

int 
del(pList list, int locate)
{
    int len = 0;
    pList tmp = list;
    while (tmp->next != NULL && len != locate)
    {
        ++len;
        tmp = tmp->next;
    }

    if (len < locate){
        printf("del fail for locate is %d not found and len list is %d \n ", locate, len);
    }else{
        printf("del success list %d locate %d\n", len, tmp->data);
        free(tmp);
    }
}

void print(pList list)
{
    pList tmp = list;
    int i = 0;
    while (tmp != NULL){
        printf(" %d --- %d \n", i++, tmp->data);
        tmp = tmp->next;
    }
}

void listTest()
{
    pList list;
    init(&list);
    int i = 0;
    for(;i < 3 ; i++) {
        insert(&list, i, i+1);
        lenList(list);
    }

    search(list, 2);
    print(list);
}

 
