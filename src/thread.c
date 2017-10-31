//
// Created by maievshabu on 2017/10/11.
//

#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

#define CUSTOMER_NUM 10
#define THREAD_NUM 3
#define REPEAT_NUM 3
#define DELAY_TIME_LEVELS 5.0

//sem_t sem;
pthread_mutex_t mutex;


/* 每个线程要运行的例程 */
//void * get_service(void *thread_id)
//{
//    /* 注意：立即保存thread_id的值，因为thread_id是对主线程中循环变量i的引用，它可能马上被修改 */
//    int customer_id = *((int *)thread_id);
//
//    if(sem_wait(&sem) == 0) {
//        usleep(100);                /* service time: 100ms */
//        printf("customer %d receive service ...\n", customer_id);
//        sem_post(&sem);
//    }
//}

void *thread_fun(void *arg)
{
    int no = (int) arg;
    int delay;
    int ret,i;

    ret = pthread_mutex_lock(&mutex);  //返回0为成功
    if(ret)
    {
        printf("Thread %d lock failed\n",no);
        pthread_exit(NULL);
    }

    for(i=0;i<REPEAT_NUM;i++)
    {
        delay = (int)(rand()*DELAY_TIME_LEVELS/(RAND_MAX))+1;
        sleep(delay);
        printf("Thread %d: job %d delay = %d\n",no,i,delay);
    }
    printf("Thread %d finished\n",no);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread[THREAD_NUM];
    int i,ret;
    void *thrd;

    srand(time(NULL));

    pthread_mutex_init(&mutex,NULL);

    for(i=0;i<THREAD_NUM;i++)
    {
        ret = pthread_create(&thread[i],NULL,thread_fun,(void *)i);
        if(ret!=0)
        {
            printf("Create %d failed\n",i);
            exit(ret);
        }
    }

    printf("Create thread success!\n Waiting for threads to finish ...\n");

    for(int j=0;j<THREAD_NUM;j++)
    {
        ret = pthread_join(thread[j],&thrd);
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_destroy(&mutex);
    return 0;

    /*
    pthread_t customers[CUSTOMER_NUM];

    int i, ret;
    for(i = 0; i < CUSTOMER_NUM; i++){
        int customer_id = i;
        ret = pthread_create(&customers[i], NULL, get_service, &customer_id);
        if(ret != 0){
            perror("pthread_create");
            exit(1);
        }
        else {
            printf("Customer %d arrived.\n", i);
        }
        usleep(10);
    }

    int j;
    for(j = 0; j < CUSTOMER_NUM; j++) {
        pthread_join(customers[j], NULL);
    }

    sem_destroy(&sem);
    */
}

