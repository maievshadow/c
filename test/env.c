#include <stdlib.h>
#include <stdio.h>
int
main(void)
{
    char *ptr = getenv("JAVA_ROOT");
    puts(ptr);
}
