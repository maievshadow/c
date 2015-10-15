#include "a.h"
#include <stdio.h>
#include <unistd.h>
int main(void)
{
	extern char fred;
	extern int bob;
	extern float jimmy;
	extern double tom;

	float _xy;


	printf("size of char is %d\n", sizeof(char));
	printf("size of fred is %d\n", sizeof(fred));
	printf("&fred is %p\n", &fred);
	printf("&bob is %p\n", &bob);
	printf("&jimmy is %p\n", &jimmy);
	printf("&tom is %p\n", &tom);

	write(STDOUT_FILENO, "the end is \n", 120);
	return 1;
}
