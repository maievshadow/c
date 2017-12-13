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
 
 int main(void)
 {
     pthread_t tid;
 
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
 
         sleep(1);
     }
 
     return 0;
 }

