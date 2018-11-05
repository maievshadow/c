#include <stdio.h>
#include <stdlib.h>

#include "student.h"

int main(void)
{
    Student stu1;

    Stu ptr;

    ptr = create();

    init(ptr);
    print(ptr);
    del(ptr);
}