#define BUFFSIZE 4096
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int apue_test(void)
{
   int n;
    char buf[BUFFSIZE];

    while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");
    if (n < 0)
        err_sys("read error");
    exit(0);
}

int 
fork_test()
{
    pid_t pid;

    printf("%d start !\n", getpid());

    fflush(NULL);
    int i = 0;
    int Len = 1;

    while(i++ < Len){
        pid = fork();

        if (pid < 0)
        {
            perror("fork()");
            exit(1);
        }
        else if (pid == 0)
        {
            //execl("/bin/date","date","+%s",NULL);
            printf("%d child process\n", getpid());
            //exit(0);
        }
    }

    printf("%d waiting!\n", getpid());

    for(i = 0; i< Len; i++)
        wait(NULL);
    printf("%d end!\n", getpid());

    return 0;
}