#ifndef C_STACK_H
#define C_STACK_H

typedef int ElementType;

typedef struct Stack{
    ElementType data;
    struct Stack * next;
}Stack, *pStack;

void init(pStack);

ElementType pop(pStack s);

void push(pStack ,ElementType e);

pStack top();

int len();

int isEmpty(pStack);

void trans(pStack);

#endif //C_STACK_H