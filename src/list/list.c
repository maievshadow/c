#include <stdio.h>
#include <stdlib.h>

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

int
lenList(pList list)
{ 
    int len = 0;
    pList tmp = list;
    while (tmp->next != NULL){
        ++len;
        tmp = tmp->next;
    }
    
    printf("the list len is %d\n", len);
    return len;
}

int 
insert(pList list,  int locate, type elem)
{
    pList p = NULL;
    p = (pList)malloc(sizeof(List));
    if (NULL == p)
    {
        printf("malloc error\n");
        exit(0);
    }
    p->data = elem;
    p->next = NULL;

    pList tmp = list;




    int len = 0;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    p->next = tmp->next;
    tmp->next = p;

    return 1;
}

int update(pList list, int locate, type elem)
{
    int len = 0;
    pList tmp = list;
    while (tmp->next != NULL && len != locate)
    {
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

    if (p == NULL)
        printf("%d not found\n", elem);
    else
        printf("found elem is %d\n", i);
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
    pList tmp = list->next;
    int i = 0;
    while (tmp != NULL){
        printf(" %d --- %d \n", i++, tmp->data);
        tmp = tmp->next;
    }
}

void listTest()
{
    pList list;
    //list = init();
    init2(&list);
    insert2(&list, 1);
    int i = 0;
    for(; i < 3 ; i++)
        insert(list, i, i+1);
    search(list, 1);
    print(list);
    return;
}

 
