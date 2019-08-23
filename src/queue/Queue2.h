//
// Created by redredmaple on 2019/8/21.
//

#ifndef C_QUEUE2_H
#define C_QUEUE2_H
typedef int elemType;
#define CAPACITY 100

typedef struct QueueNode{
    elemType *node;
    int capacity;
    elemType rear;
    elemType front;
}Queue2, * Queue2Ptr;

void initQueue2(Queue2Ptr, int);
void pushQueue2(Queue2Ptr, elemType);
elemType popQueue2(Queue2Ptr);
int isEmptyQueue2(Queue2Ptr);
void visitQueue2(Queue2Ptr);
int lengthQueue2(Queue2Ptr);

#endif //C_QUEUE2_H
