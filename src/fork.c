#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

void
pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("normal terminateion exit status =%d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, status=%d%s\n", WTERMSIG(status),
#ifdef WCOREDDUMP
	WCOREDUMP(status) ? "(core file.generated)" : "");
#else
	"");
#endif
	else if(WIFSTOPPED(status))
		printf("child stoppen, singal number= %d\n", WSTOPSIG(status));
}

int
main(void)
{
	pid_t pid;
	int status;

	if ((pid = fork()) < 0)
		perror("fork error");
	else if (pid == 0) //child
		exit(7);

	if (wait(&status) != pid)
		perror("wait error");
	pr_exit(status);

	if ((pid = fork()) < 0)
		perror("fork error");
	else if (pid == 0) //child
		abort();

	if (wait(&status) != pid)
		perror("wait error");
	pr_exit(status);

	if ((pid = fork()) < 0)
		perror("fork error");
	else if (pid == 0) //child
		status /= 0;

	if (wait(&status) != pid)
		perror("wait error");
	pr_exit(status);

	exit(0);
}
