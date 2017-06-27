#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>

#define doit(name) pr_limit(#name, name)
static void pr_limit(char *, int );

int main(int argc, char **argv){
	
#ifdef RLIMIT_MEMLOCK
	doit(RLIMIT_MEMLOCK);
#endif
#ifdef RLIMIT_NOFILE
	doit(RLIMIT_NOFILE);
#endif
#ifdef RLIMIT_OFILE
	doit(RLIMIT_OFILE);
#endif
#ifdef RLIMIT_NPROC
	doit(RLIMIT_NPROC);
#endif

	doit(RLIMIT_STACK);
#ifdef RLIMIT_RSS
	doit(RLIMIT_RSS);
#endif
#ifdef RLIMIT_VMEM
	doit(RLIMIT_VMEM);
#endif

	return 1;
}

static void pr_limit(char*name, int resource){
	struct rlimit limit;
	if (getrlimit(resource, &limit) < 0)
		perror("getrlimit error");
	printf("%-14s	", name);

	if (limit.rlim_cur == RLIM_INFINITY)
		printf("(infinite)	");
	else
		printf("%10llu	", limit.rlim_cur);

	if (limit.rlim_max == RLIM_INFINITY)
		printf("(infinite)\n");
	else
		printf("%10llu\n", limit.rlim_max);
}

