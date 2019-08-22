#include <stdlib.h>
#include <stdio.h>
#include "Queue.h"

int
main(int argc, char ** argv)
{
    int i;
    QueueList list;
    initQueue(&list);
    printf("%d\r\n", isEmptyQueue(&list));
    /*
    elemType data = 10;
    for(;data < 20;)
        pushQueue(&list, ++data);
        */
    visitQueue(&list);
    for(i = 0; i < 5 ; i++)
        printf("%d\r\n", popQueue(&list));
    visitQueue(&list);

	return 0;
}