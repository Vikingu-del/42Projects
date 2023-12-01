#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define THREAD_NUM 2

pthread_mutex_t mutex_fuel = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_fuel = PTHREAD_COND_INITIALIZER;

void *routine(void *arg)
{
    return (NULL);
}

int main(void) {
    pthread_t th[THREAD_NUM];
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
            perror("Failed to create thread\n");
    }
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0)
            perror("Failed to join thread\n");
    }
    return (NULL);
}
