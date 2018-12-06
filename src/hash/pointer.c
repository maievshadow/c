#include <stdio.h>
#include <stdlib.h>

/**
 * 
 *  
    二维数组的几个符号的测试
    1、a等同于&a[0]
    2、a[0]等同于&a[0][0]
    3、在数值上 a、&a、a[0]、&a[0]、&a[0][0] 是相等的，但是在类型上面是有区别的。
    int a[2][5] = {{1,2,3,4,5},{6,7,8,9,10}};
    
    printf("a        = %p.\n", a);        // a       类型是 int (*)[5]
    printf("&a       = %p.\n", &a);       // &a      类型是 int (*)[2][5]
    printf("a[0]     = %p.\n", a[0]);     // a[0]    类型是 int *
    printf("&a[0]    = %p.\n", &a[0]);    // &a[0]   类型是 int (*)[5]
    printf("a[0][0]  = %d.\n", a[0][0]);  // a[0][0] 类型是 int 
    printf("&a[0][0] = %p.\n", &a[0][0]); // &a[0][0]类型是 int *
 * 
 **/


int
main(void)
{
    //int *pa;
    int (*p)[3];

    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int **ppa;

    int j = 0;
    int i = 0;
    printf("%d\n", ppa[1]);

    exit(0);

    int (*p2)[3];
    int b[2][3] = {{1, 2, 3}, {4, 5, 6}};
    i = 0;

    p = b;
    for(; i < 2; i++){
        int j = 0;
        //pa = b[i];
        for(;j < 3 ;j++){
            //printf("%d--", *(pa + j));
            //printf("%d--", *(*(p + i) +j));
            printf("%d--", p[i][j]);
        }
        printf("\n");
    }

    /* zheli mei li jie .....
    i = 0;
    p2 = &b[1];
    printf("%d\n", p2[1][1]);
    */
    return 0;
}