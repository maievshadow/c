#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define FLAGS O_CREAT | O_RDWR | O_TRUNC
#define MODE S_IRWXU | S_IXGRP | S_IROTH | S_IXOTH


int main(void)
{
    pid_t  pid;

    pid_t pid2[3];


    int fd;
    int status;
    int i = 0;
    char * buf;
    char *path = "/home/redredmaple/test/tt";

    /*
    fd = open(path, FLAGS, MODE);
    if (fd <= 0){
        perror("open");
        _exit(1);
    }

    pid = fork();

    if (pid < 0){
        perror("1st fork");
    }else if (pid == 0){
        sleep(5);
        pid = fork();

        if(pid < 0){
            perror("2nd fork2");
        } else if (pid == 0){
            printf("2nd fork %d\n", getpid());
            printf("2nd fork 's parent %d\n", getppid());
        }else {
            wait(NULL);
            printf("fork child %d\n", getpid());
            printf("fork child's parent in 1st fork %d\n", getppid());
        }
    }

    wait(NULL);
    printf("1st fork self %d\n", getpid());

    return 0;
    */

    for (; i < 2; i++) {
        pid = fork();
    }

    if (pid < 0){
        perror("1st fork");
    }else if (pid == 0){
        /*
        pid = fork();

        if(pid < 0){
            perror("2nd fork2");
        } else if (pid == 0){
            printf("parent %d and self  %d \n", getppid(), getpid());
        }else {
            printf("parent %d and self  %d \n", getppid(), getpid());
            wait(NULL);
        }
        */
        //exit(0);
    }else{
        printf("parent %d and self %d \n", getppid(), getpid());
        wait(NULL);
        //exit(0);
    }

    return 0;

    if (pid < 0) {
        perror("fork");
        _exit(2);
    }

    //ssize_t write(int fd, const void *buf, size_t count);
    if (pid == 0) {
        printf("child %d\n", getpid());
        printf("child's daddy %d\n", getppid());
        ssize_t size = write(fd, "child", 5);
        if (size == -1)
        {
            perror("write:");
        }
        exit(10);
    }

    pid = wait(&status);
    printf("parent %d\n", getpid());
    if (pid == -1) {
        perror("wait");
    }

    ssize_t size = write(fd, "parent", 6);
    if (size == -1) {
        perror("write");
    }

    /*
    if (WIFEXITED(status)) //WIFEXITED宏的释义： wait if exit ed
    {
        printf("子进程返回信息码:%d\n", WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status))
    {
        printf("子进程信号中断返回信息码:%d\n", WTERMSIG(status));
    }
    else if (WIFSTOPPED(status))
    {
        printf("子进程暂停返回信息码:%d\n", WSTOPSIG(status));
    }
    else
    {
        printf("其他退出信息！\n");
    }
    */

    return 0;
}