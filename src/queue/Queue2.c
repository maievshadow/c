//
// Created by redredmaple on 2019/8/22.
//

#include <stdio.h>
#include <malloc.h>
#include "Queue2.h"

void initQueue2(Queue2Ptr queue, int capacity)
{
    //queue->capacity = CAPACITY;
    queue->node = malloc(sizeof(elemType) * capacity);
    if (NULL == queue->node){
        printf("Error\r\n");
        return ;
    }

    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;

    return ;
}

void pushQueue2(Queue2Ptr queue, elemType b)
{
    //@TODO
    /*
    if (queue->rear > queue->capacity){
        printf("full queue\r\n");
        return;
    }
    */

    queue->node[queue->rear] = b;
    queue->rear = (queue->rear + 1) % queue->capacity;

    return;
}

int lengthQueue2(Queue2Ptr queue)
{
    return (queue->rear - queue->front + queue->capacity) % queue->capacity;
}

elemType popQueue2(Queue2Ptr queue)
{
    if (queue->rear == queue->front){
        printf("empty queue\r\n");
        return 0;
    }
    elemType data = queue->node[queue->front];
    queue->front = (queue->front + 1 )% queue->capacity;
    return data;
}

int isEmptyQueue2(Queue2Ptr queue)
{
    if (queue->rear == queue->front)
        return 1;
    else
        return 0;
}

int isFullQueue2()
{
    return 1;
}

void visitQueue2(Queue2Ptr queue)
{
    printf("visit\r\n");
    elemType i = queue->front;
    while(i <= queue->rear){
        printf("%d\r\n", queue->node[i++]);
    }

    return;
}