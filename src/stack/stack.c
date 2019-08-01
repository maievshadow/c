#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


void init(pStack stack)
{
    stack = malloc(sizeof(Stack));
    if (NULL == stack){
        printf("malloc error");
        return;
    }

    stack->next = NULL;
    stack->data = 0;

    return;
}

void push(pStack s, ElementType e)
{
    pStack p = NULL;
    p = malloc(sizeof(Stack));
    if (NULL == p){
        printf("malloc error");
        return;
    }

    s->data += 1;
    p->data = e;
    p->next = s->next;
    s->next = p;

}

ElementType pop(pStack s)
{
    if (isEmpty(s)){
       printf("cause stack empty.so no pop\r\n");
       return 0;
    }

    ElementType  e = s->next->data;
    printf("pop %d \r\n", e);
    s->next = s->next->next;
    --s->data;
    return e;
}

int len(pStack p)
{
    return p->data;
}

int isEmpty(pStack p)
{
    return p->next == NULL ? 1 : 0;
}
