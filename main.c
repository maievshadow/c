#include <stdio.h>
#include <string.h>
#include "src/stack/stack.h"

int main(void)
{
    Stack s;
    memset(&s, 0 , sizeof(Stack));

    init(&s);
    int i = 0;
    for(; i < 10;i ++)
        push(&s, i);
    printf("len of stack  %d\r\n", len(&s));

    printf("stack empty or not ? %d\r\n", isEmpty(&s));
    pop(&s);

    printf("len of stack  %d\r\n", len(&s));

    pop(&s);

    printf("len of stack  %d\n", len(&s));

    printf("stack empty or not ? %d\r\n", isEmpty(&s));

    pop(&s);
    //free(&s);
    return 0;
}