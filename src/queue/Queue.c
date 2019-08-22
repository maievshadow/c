//
// Created by redredmaple on 2019/8/21.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Queue.h"

void initQueue(QueueListPtr queue)
{
    /*
    list = malloc(sizeof(QueueList));
    if (NULL == list){
        printf("malloc error\n");
        return;
    }
     */

    queue->front = malloc(sizeof(QueueNode));
    if (NULL == queue->front){
        printf("malloc error\n");
        return;
    }

    queue->rear = queue->front;
    queue->front->next = NULL;

    return;
}
void pushQueue(QueueListPtr queue, elemType data)
{
    QueueNodePtr node = malloc(sizeof(QueueNode));
    if (NULL == node){
        printf("malloc error\n");
        return;
    }

    queue->rear->next = node;
    queue->rear = node;

    node->data =data;
    node->next = NULL;

    printf("push %d\r\n", data);
    return;
}

elemType popQueue(QueueListPtr queue)
{
    if (isEmptyQueue(queue)){
        printf("empty queue\r\n");
        return 0;
    }

    QueueNodePtr node = queue->front->next;
    elemType  data = node->data;

    queue->front->next = node->next;
    free(node);

    return data;
}

int isEmptyQueue(QueueListPtr queue)
{
    if (queue->front  == queue->rear) {
        return 1;
    } else {
        return 0;
    }
}

void visitQueue(QueueListPtr queue)
{
    printf("visit\r\n");
    QueueNodePtr node = queue->front->next;
    while(node != NULL){
        printf("%d\r\n", node->data);
        node = node->next;
    }
    return;
}

