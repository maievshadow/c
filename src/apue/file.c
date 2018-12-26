#include <stdio.h>
#include <unistd.h>

#define FILE_SIZE 1000

int
main(void)
{
    //FILE *fopen(const char *path, const char *mode);

    FILE * file = fopen("/home/redredmaple/test/zf", "r");

    fseek(file, 0, SEEK_END); //

    size_t filesize = ftell(file);

    rewind(file);
    char *ptr= (char *)malloc(FILE_SIZE);

    /*
    char * ptr = NULL;
    size_t size_t2;
    while(getline(&ptr, &size_t2, file) > 0){
        printf("%s\n", ptr);
    }
    */

   /* bbaa????????????
    putchar('a');
    write(1, "b", 1);
    putchar('a');
    write(1, "b", 1);
    */
   
   //STDIN -- 0 error
	while(NULL != fgets(ptr, FILE_SIZE, stdin)){
		printf("%s", ptr);
	}	

    fclose(file);

}