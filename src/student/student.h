#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <stdlib.h>

typedef struct
{
    int age;
    char *name;
    char sex[1];
} Student, *pStu;

pStu create();

void init(pStu ptr);
void print(pStu ptr);

void copyStu(pStu st1, pStu st2);

pStu create()
{
   pStu ptr = (pStu)malloc(sizeof(Student)); 
   printf("the create address is %p\n", ptr);
   return ptr;
}

void init(pStu ptr)
{
    ptr->age = 20;
    strcpy(ptr->name, "maiev");
    strcpy(ptr->sex, "M");
   printf("the init address is %p\n", ptr);
}

void print(pStu ptr)
{
    printf("age is %d\n", ptr->age);
    printf("name is %s\n", ptr->name);
    printf("sex is %s\n", ptr->sex);
    printf("the print address is %p\n", ptr);
}

void del(pStu ptr)
{
    free(ptr);
    printf("the del address is %p\n", ptr);
    printf("del ptr\n");
}

void copyStu(pStu st1, pStu st2)
{
    st2->age = st1->age;
    strcpy(st2->name, st1->name);
    strcpy(st2->sex, st1->sex);

    st1->age = 1;
}

void copyStu2(Student st1, Student st2)
{
    st2.age = st1.age;
    strcpy(st2.name, st1.name);
    strcpy(st2.sex, st1.sex);
}

#endif