#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
/* 定义互斥量 */
pthread_mutex_t mtx;
/* 互斥量属性 */
pthread_mutexattr_t mtx_attr;
/* 全局资源 */
int money;

int global_num = 10;

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

/* 初始化读写锁 */
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

void err_exit(const char *err_msg)
{
	printf("error:%s\n", err_msg);
	exit(1);
}

/* 线程函数 */
void *thread_fun(void *arg)
{
	while (1)
	{
		/* 加锁 */
		pthread_mutex_lock(&mtx);

		while(money > 0){
			printf("子进程坐等money=0\r\n");
			pthread_cond_wait(&cond, &mtx);
		}

		printf("子线程进入临界区查看money\n");
		if (money == 0)
		{
			money += 200;
			printf("子线程:money = %d\n", money);
		}

		/* 解锁 */
		pthread_mutex_unlock(&mtx);

		sleep(1);
	}

	return NULL;
}

void *thread_read_lock(void *arg){
	char *pthr_name = (char*) arg;
	while(1){
		pthread_rwlock_rdlock(&rwlock);

		printf("线程%s进入临界区，global_num = %d\n", pthr_name, global_num);
		sleep(1);
		printf("线程%s离开临界区...\n", pthr_name);

		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
}

void *thread_write_lock(void *arg){
	char *pthr_name = (char*) arg;
	while(1){
		pthread_rwlock_wrlock(&rwlock);

		global_num++;
		printf("线程%s进入临界区，global_num = %d\n", pthr_name, global_num);
		sleep(1);
		printf("线程%s离开临界区...\n", pthr_name);

		pthread_rwlock_unlock(&rwlock);
		sleep(2);
	}
}

int main(void)
{
	pthread_t tid;



	pthread_t tid_read_1, tid_read_2, tid_write_1, tid_write_2;

	if (pthread_create(&tid_read_1, NULL, thread_read_lock, "read_1") != 0)
		err_exit("create tid_read_1");
	if (pthread_create(&tid_read_2, NULL, thread_read_lock, "read_2") != 0)
		err_exit("create tid_read_1");
	if (pthread_create(&tid_write_1, NULL, thread_write_lock, "write_1") != 0)
		err_exit("create tid_read_1");
	if (pthread_create(&tid_write_2, NULL, thread_write_lock, "write_2") != 0)
		err_exit("create tid_read_1");

	/* 随便等待一个线程，防止main结束 */
	if (pthread_join(tid_read_1, NULL) != 0)
		err_exit("pthread_join()");

	return 0;


	/* 初始化互斥量属性 */
	if (pthread_mutexattr_init(&mtx_attr) == -1)
		err_exit("pthread_mutexattr_init()");

	/* 设置互斥量属性 */
	if (pthread_mutexattr_settype(&mtx_attr, PTHREAD_MUTEX_NORMAL) == -1)
		err_exit("pthread_mutexattr_settype()");

	/* 初始化互斥量 */
	if (pthread_mutex_init(&mtx, &mtx_attr) == -1)
		err_exit("pthread_mutex_init()");

	/* 创建一个线程 */
	if (pthread_create(&tid, NULL, thread_fun, NULL)== -1)
		err_exit("pthread_create()");

	money = 1000;
	while (1)
	{
		/* 加锁 */
		pthread_mutex_lock(&mtx);

		if (money > 0)
		{
			money -= 100;
			printf("主线程:money = %d\n", money);
		}

		/* 解锁 */
		pthread_mutex_unlock(&mtx);

		if (money == 0){
			printf("通知子线程\r\n");
			pthread_cond_signal(&cond);
		}

		sleep(1);
	}

	return 0;
}


