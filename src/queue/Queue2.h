//
// Created by redredmaple on 2019/8/21.
//

#ifndef C_QUEUE2_H
#define C_QUEUE2_H
typedef int elemType

typedef struct Queue2Node {
    elemType data;
    //int current;
    int capacity;
}Queue2Node, * Queue2NodePtr;

typedef struct Queue2{
    struct Queue2NodePtr * rear;
    struct Queue2NodePtr * front;
}Queue2, * Queue2Ptr;

Queue2Ptr initQueue2();
void pushQueue2(Queue2Ptr, elemType);
elemType popQueue2(Queue2Ptr);
int isEmptyQueue2(Queue2Ptr);
void visitQueue2(Queue2Ptr);

#endif //C_QUEUE2_H
