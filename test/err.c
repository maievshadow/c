#include <errno.h>
#include "apue.h"
int
main(int argc, char* argv[])
{
    fprintf(stderr, "EACCESS:%s\n", strerror(1));
    errno = ENOENT;
    perror(argv[0]);

    exit(0);
}
