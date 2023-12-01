//
// Created by segfault on 28.11.23.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>

#define THREAD_NUM 2

void *routine(void *arg)
{
    pthread_t th = pthread_self();
    printf("%lu\n", th);
    printf("%d\n", (pid_t)syscall(SYS_gettid));


}

int main(void) {
    pthread_t th[THREAD_NUM];
    int i;
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread\n");
        printf("Thread %lu created\n", th[i]);
    }
    for (i = 0; i < THREAD_NUM; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
            perror("Failed to join thread\n");
    }
    return (0);
}
