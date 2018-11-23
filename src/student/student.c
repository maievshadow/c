#include <stdio.h>
#include <stdlib.h>

#include "student.h"

typedef pStu pstu;
int
run(void);

int 
run(void)
{
    /*
    Stu ptr;
    ptr = create();
    init(ptr);
    print(ptr);
    del(ptr);
    */

    Student stu1;
    Student stu2;

    stu1.age = 100;
    strcpy(stu1.name, "maiev22");
    strcpy(stu1.sex, "M");
    /*
    print(&stu1);
    */

    /*
    Stu p2 = (Stu) malloc(sizeof(Student));
    copyStu(&stu1, &p2);
    print(&p2);

    copyStu(&stu1, &stu2);
    print(&stu2);
    
    printf("age is %d\n", stu1.age);
    */
    int a = 1;
    int b = 2;

    printf("%p\n", &a);
    printf("%p\n", &b);

    int *pa = &a;
    int *pb = &b;
    swap(pa,pb);
    swap2(&pa,&pb);
    printf("%d\n", b);
    printf("%d\n", *pb);
}