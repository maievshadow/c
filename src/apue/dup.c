#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define FLAGS O_CREAT | O_RDWR | O_TRUNC
#define MODE S_IRWXU | S_IXGRP | S_IROTH | S_IXOTH


int main(void)
{
    int fd;
    char *path = "/home/redredmaple/test/t1";

    fd = open(path, FLAGS, MODE);
    if (fd <= 0){
        perror("open");
        _exit(1);
    }

    close(1);
    /*
    dup2(fd, 1);
    close(fd);
    puts("xxucanbi");
    */

    fcntl(fd, F_DUPFD, 1); //
    puts("xxucanbi2");
    puts("xxucanbi3");

    return 0;
}