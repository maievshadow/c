#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <malloc.h>

typedef struct
{
    int age;
    char name[20];
    char sex[2];
} Student, *Stu;

Stu create();

void init(Stu ptr);
void print(Stu ptr);


Stu create()
{
   Stu ptr = (Stu)malloc(sizeof(Student)); 
   printf("the create address is %p\n", ptr);
   return ptr;
}

void init(Stu ptr)
{
    ptr->age = 20;
    strcpy(ptr->name, "maiev");
    strcpy(ptr->sex, "M");
   printf("the init address is %p\n", ptr);
}

void print(Stu ptr)
{
    printf("age is %d\n", ptr->age);
    printf("name is %s\n", ptr->name);
    printf("sex is %s\n", ptr->sex);
   printf("the print address is %p\n", ptr);
}

void del(Stu ptr)
{
    free(ptr);
   printf("the del address is %p\n", ptr);
    printf("del ptr\n");
}

#endif