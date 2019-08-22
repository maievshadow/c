#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include <string.h>
#include <dirent.h>
#include <stdio.h>

void pr(char*);

#define NEWPATHSIZE        1024

int64_t mydudir (const char *path)
{
    int64_t sum = 0;
    struct stat buf;
    struct dirent *de;
    struct stat subbuf;
    char newpath[NEWPATHSIZE];

    if (lstat(path, &buf) < 0)
    {
        perror("lstat");
        _exit(1);
    }

    if (S_ISDIR(buf.st_mode)) // 文件夹
    {
        sum = buf.st_blocks;
        DIR *dirp = opendir(path);
        if (NULL == dirp)
        {
            perror("opendir");
            //exit(1);
            return sum;
        }

        while (NULL != (de = readdir(dirp)))
        {
            if (NULL != de)
            {
                snprintf(newpath, NEWPATHSIZE, "%s/%s", path, de->d_name);
                if (DT_DIR == de->d_type) // 文件夹
                {
                    if (strcmp(".", de->d_name) && strcmp("..", de->d_name))
                    {
                        strncat(newpath, "/", NEWPATHSIZE);
                        sum += mydudir(newpath);
                    }
                }
                else // 文件
                {
                    if (lstat(newpath, &subbuf) < 0)
                    {
                        perror("lstat-sub");
                        //exit(1);
                        return sum;
                    }
                    sum += subbuf.st_blocks;
                }
            }
        }
        closedir(dirp);
    }
    else // 文件
    {
        sum = buf.st_blocks;
    }

    return sum;
}


int main(void)
{
    struct stat st;

    char *path = "/home/redredmaple/test/t1";

    int flag = stat(path, &st);

    if (flag == -1){
        perror("stat:");
    }


    /*
     *
           S_IFMT     0170000   bit mask for the file type bit field
           S_IFSOCK   0140000   socket
           S_IFLNK    0120000   symbolic link
           S_IFREG    0100000   regular file
           S_IFBLK    0060000   block device
           S_IFDIR    0040000   directory
           S_IFCHR    0020000   character device
           S_IFIFO    0010000   FIFO
     *
     *
     */

    /*
    switch(st.st_mode & S_IFMT){
        case S_IFIFO:
            printf("fifo\n");
            break;
        case S_IFDIR:
            printf("dir\n");
            break;
        case S_IFCHR:
            printf("chr\n");
            break;
        case S_IFSOCK:
            printf("socket\n");
            break;
        case S_IFBLK:
            printf("block\n");
            break;
        case S_IFREG:
            printf("regular\n");
            break;
        case S_IFLNK:
            printf("symbolic\n");
            break;
        default:
            printf("error\n");
            break;
    }

    */


    /*
     *  S_ISREG(m)  is it a regular file?

           S_ISDIR(m)  directory?

           S_ISCHR(m)  character device?

           S_ISBLK(m)  block device?

           S_ISFIFO(m) FIFO (named pipe)?

           S_ISLNK(m)  symbolic link?  (Not in POSIX.1-1996.)

           S_ISSOCK(m) socket?  (Not in POSIX.1-1996.)
     *
     *
     */

    if (S_ISREG(st.st_mode)){
        printf("yes, is regular file\n");
    }else{
        printf("not\n");
    }

    mydudir("/home/redredmaple/test/");

    return 0;

    char ch;
    char * buf = malloc(sizeof(char) * 10);

    while((ch = getchar()) != 'q'){
        *(buf++) = ch;
    }

    *buf = '\0';
    pr(buf);//@Todo bug-[buf is end ]

    return 0;
}

void pr( char * buf)
{
    char * ptr;

    for(ptr=buf; *ptr != '\0';)
        printf("%c", *(ptr++));
    return ;
}