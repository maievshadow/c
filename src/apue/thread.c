#include <stdio.h>
#include <pthread.h>

pthread_t tid1, tid2;
struct foo{
    int a;
    int b;
    int c;
}f;

void pf()
{
    printf("a:%d, b:%d, c:%d", f.a, f.b, f.c);
}

void * p1() {
    f.a = 1;
    f.b = 1;
    f.c = 1;
    printf("tcrae1\n");
    pthread_cancel(tid2);
    printf("hehe\n");
    pthread_exit(NULL);
}

void * p2()
{
    f.a = 2;
    f.b = 2;
    f.c = 2;
    printf("tcrae2\n");
    sleep(1);
    printf("cancel tid1\n");
    printf("exit\n");
    pthread_exit(NULL);
}

int main(void)
{
    int err1 = pthread_create(&tid1, NULL, p1, NULL);
    if (err1 != 0)
    {
        perror("thread1 create:");
        exit(1);
    }

    int err2 = pthread_create(&tid2, NULL, p2, NULL);
    if (err2 != 0)
    {
        perror("thread2 create:");
        exit(1);
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
