#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>


int main()
{
	
//int open(const char *pathname, int flags);
	int fd = open("CMakeCache.txt", O_RDONLY);
	if (fd == -1){
		perror("open");
	}

	int a = 1;

	pid_t pid;

	pid = fork();

	if (pid > 0){
		exit(0);
	}

	pid = setsid();
	//pid = fork();
	if (pid == -1){
		exit(0);
	}

	chdir("/");

	for(a;a<3;a++){
		close(a);
	}

	open("/dev/null", O_RDONLY);
	dup(0);
	dup(0);

	while(1)
	{
		sleep(1);
	}
		
	return 0;
}