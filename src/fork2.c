#include <stdio.h>
#include <unistd.h>

void f();
char buf[] = "this is a buf\r\n";
int global_var = 10;
int main(){
	int i = 0;
	
	printf("child_pid current_pid parent_pid \r\n");

	for(; i< 2;i++){
		pid_t pid = fork();
		printf("%4d %4d %4d \r\n", pid, getpid(), getppid());
	}

	while(1);
	return 0;


	/*
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
	*/

}

void f(){
	if( write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf)-1){
		perror("child write error");
	}
}
