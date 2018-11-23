#ifndef __FUNC__H__
#define __FUNC__H__
#include <stdio.h>

void
pp();

void 
swap2(int**,int**);
void 
swap(int*,int*);

void 
pp()
{
    printf("lib pp");
}

void 
swap2(int ** a, int ** b)
{
    int *temp;
    temp = &a;
    a = b;
    b = &temp;
}

void 
swap(int * a, int * b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
#endif