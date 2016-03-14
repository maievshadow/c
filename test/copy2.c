#include <unistd.h>
#include <stdio.h>
int
main(void)
{
    int c;
    while ((c = getc(stdin)) != EOF)
        if (putc(c, STDOUT_FILENO) == EOF)
            err_sys("opuput error");
    if (ferror(stdin))
        err_sys("input error");
    exit(0);
}
