//
// Created by redredmaple on 1/3/19.
//

/*

int setjmp(jmp_buf env);

int sigsetjmp(sigjmp_buf env, int savesigs);
 */
#include <setjmp.h>
#include <stdio.h>

jmp_buf evn;
int globalVal = 1;

void f()
{
    globalVal = 2;

    if (0){
        longjmp(evn, 8);
    }
}


int main(int argc, char ** argv)
{

    auto int autoVal = 100;
    register int regVal = 1;
    static int staticVal = 2;

    switch(setjmp(evn)){
        case 0:
            f();
            printf("normal\n");
            break;
        case 8:
            printf("f()\n");
            break;
        default:
            printf("error\n");
            break;
    }

    return 0;
}
