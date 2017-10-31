#include <stdio.h>
#include <unistd.h>

void f();
char buf[] = "this is a buf\r\n";
int global_var = 10;
int main(){
	pid_t pid = fork();
	int i = 0;

	if (pid < 0){
		perror("fork error");
	}else if (pid == 0){
		//child
		++i;
		++global_var;
		printf("child %d %d \r\n", i, global_var);
	}else if (pid > 0){
		//parent
		sleep(3);
		printf("parent %d %d \r\n", i, global_var);
	}

	return 0;
}

void f(){
	if( write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf)-1){
		perror("child write error");
	}
}
