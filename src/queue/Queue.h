//
// Created by redredmaple on 2019/8/21.
//

#ifndef C_QUEUE_H
#define C_QUEUE_H
typedef int elemType;
typedef struct QueueNode{
    elemType data;
    struct QueueNode * next;
}QueueNode, *QueueNodePtr;

typedef struct QueueList{
    QueueNodePtr rear;
    QueueNodePtr front;
    //int queueCapacity;
}QueueList, *QueueListPtr;

void initQueue(QueueListPtr);
void pushQueue(QueueListPtr, elemType);
elemType popQueue(QueueListPtr);
int isEmptyQueue(QueueListPtr);
//int isFullQueue(QueueListPtr);
void visitQueue(QueueListPtr);

#endif //C_QUEUE_H
