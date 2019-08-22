#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

int
main(int argc, char ** argv)
{
    int i;
    elemType data = 10;
    QueueList list;
    initQueue(&list);
    isEmptyQueue(&list);
    for(;data < 20;)
        pushQueue(&list, ++data);
    visitQueue(&list);
    for(i = 0; i < 5 ; i++)
        printf("%d\r\n", popQueue(&list));
    visitQueue(&list);
	return 0;
}