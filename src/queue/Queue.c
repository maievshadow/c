//
// Created by redredmaple on 2019/8/21.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "Queue.h"

void initQueue(QueueListPtr list)
{
    /*
    list = malloc(sizeof(QueueList));
    if (NULL == list){
        printf("malloc error\n");
        return;
    }
     */

    list->front = malloc(sizeof(QueueNode));
    if (NULL == list->front){
        printf("malloc error\n");
        return;
    }

    list->rear = list->front;
    list->front->next = NULL;

    return;
}
void pushQueue(QueueListPtr list, elemType data)
{
    QueueNodePtr node = malloc(sizeof(QueueNode));
    if (NULL == node){
        printf("malloc error\n");
        return;
    }

    list->rear->next = node;
    list->rear = node;

    node->data =data;
    node->next = NULL;

    printf("push %d\r\n", data);
    return;
}

elemType popQueue(QueueListPtr list)
{
    if (isEmptyQueue(list)){
        printf("empty queue\r\n");
        return 0;
    }

    QueueNodePtr node = list->front->next;
    elemType  data = node->data;

    list->front->next = node->next;
    free(node);

    return data;
}

int isEmptyQueue(QueueListPtr list)
{
    if (list->front  == list->rear) {
        return 1;
    } else {
        return 0;
    }
}

void visitQueue(QueueListPtr queue)
{
    QueueNodePtr node = queue->front->next;
    while(node != NULL){
        printf("visit - %d\r\n", node->data);
        node = node->next;
    }
    return;
}

