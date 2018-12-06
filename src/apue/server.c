#include <stdio.h>
#include <unistd.h>

typedef size_t (*compare_equal)(int *, int *);

#define BUFSIZE 100

int main()
{
    int a = 1;
    int b = 2;

    int *pa = &a;
    int *pb = &b;

    compare_equal ce = &comp;

    (*ce)(pa,pb);
    printf("server\r\n");
    return 0;
}

size_t comp(int *a, int *b)
{
    size_t a = 0;
    printf("compare function\r\n");
    return a;
}
