//
// Created by redredmaple on 2019/8/22.
//

#include <stdio.h>
#include <malloc.h>
#include "Queue2.h"
define CAPACITY 100

Queue2Ptr initQueue2()
{
    Queue2NodePtr queue = NULL;
    Queue2NodePtr node = malloc(sizeof(Queue2Node) * CAPACITY);
    if (NULL == node){
        printf("Error\r\n");
        exit;
    }

    node->capacity = CAPACITY;

    queue->front = head->rear;
    queue->rear = node;

    return queue;
}

void pushQueue2(Queue2Ptr queue, elemType b)
{

    return;
}
