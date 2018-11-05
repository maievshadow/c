#include <stdio.h>
#include <stdlib.h>

#include "student.h"

int run(void)
{
    Stu ptr;
    ptr = create();
    init(ptr);
    print(ptr);
    del(ptr);

    Student stu1;

    stu1.age = 100;
    strcpy(stu1.name, "maiev22");
    strcpy(stu1.sex, "M");

    print(&stu1);
}