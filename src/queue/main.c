#include <stdlib.h>
#include <stdio.h>
//#include "Queue.h"
#include "Queue2.h"

int
main(int argc, char ** argv)
{
    int i;
    /*
    QueueList list;
    initQueue(&list);
    printf("%d\r\n", isEmptyQueue(&list));
    elemType data = 10;
    for(;data < 20;)
        pushQueue(&list, ++data);
    visitQueue(&list);
    for(i = 0; i < 5 ; i++)
        printf("%d\r\n", popQueue(&list));
    visitQueue(&list);
    */

    Queue2Ptr queue = malloc(sizeof(Queue2));
    if (NULL == queue){
        printf("ERROR MALLOC\r\n");
        return 1;
    }

    initQueue2(queue, 100);
    isEmptyQueue2(queue);

    elemType data = 10;
    for(;data < 20;)
        pushQueue2(queue, ++data);
    visitQueue2(queue);
    for(i = 0; i < 5 ; i++)
        printf("%d\r\n", popQueue2(queue));
    visitQueue2(queue);

    printf("len of queue :%d\r\n", lengthQueue2(queue));
	return 0;
}