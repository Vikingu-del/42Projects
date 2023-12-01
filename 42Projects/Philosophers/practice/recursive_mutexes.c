#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define THREAD_NUM 8

pthread_mutex_t	mutex_fuel;
int				fuel = 50;

void	*routine(void *arg)
{
	pthread_mutex_lock(&mutex_fuel);
	pthread_mutex_lock(&mutex_fuel);
	pthread_mutex_lock(&mutex_fuel);
	pthread_mutex_lock(&mutex_fuel);
	pthread_mutex_lock(&mutex_fuel);
	fuel += 50;
	printf("Incremented fuel to: %d\n", fuel);
	pthread_mutex_unlock(&mutex_fuel);
	pthread_mutex_unlock(&mutex_fuel);
	pthread_mutex_unlock(&mutex_fuel);
	pthread_mutex_unlock(&mutex_fuel);
	pthread_mutex_unlock(&mutex_fuel);
	return (NULL);
}

int main(int argc, char *argv[]) {
    pthread_t th[THREAD_NUM];
    pthread_mutexattr_t recursiveMutexAttributes;
    pthread_mutexattr_init(&recursiveMutexAttributes);
    pthread_mutexattr_settype(&recursiveMutexAttributes, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex_fuel, &recursiveMutexAttributes);
    int i;
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_create(&th[i], NULL, &routine, NULL) != 0) {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    printf("Fuel: %d\n", fuel);
    pthread_mutexattr_destroy(&recursiveMutexAttributes);
    pthread_mutex_destroy(&mutex_fuel);
    return 0;
}
