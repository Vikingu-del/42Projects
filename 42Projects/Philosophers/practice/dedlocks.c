#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>

#define THREAD_NUM 8

pthread_mutex_t	mutex_fuel;
pthread_mutex_t	mutex_water;
int				fuel = 50;
int				water = 10;

void	*routine(void *arg)
{
	if (rand() % 2 == 0) {
		pthread_mutex_lock(&mutex_fuel);
		sleep(1);
		pthread_mutex_lock(&mutex_water);
	} else {
		pthread_mutex_lock(&mutex_water);
		sleep(1);
		pthread_mutex_lock(&mutex_fuel);
	}
	fuel += 50;
	water = fuel;
	printf("Incremented fuel to: %d set water to %d\n", fuel, water);
	pthread_mutex_unlock(&mutex_fuel);
	pthread_mutex_unlock(&mutex_water);
	return (NULL);
}

int main(void) {
	pthread_t	th[THREAD_NUM];
	int			i;
	pthread_mutex_init(&mutex_fuel, NULL);
	pthread_mutex_init(&mutex_water, NULL);
	for (i = 0; i < THREAD_NUM; i++) {
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread\n");
	}
	for (i = 0; i < THREAD_NUM; i++) {
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread\n");
	}
	printf("Fuel: %d\n", fuel);
	printf("Water: %d\n", water);
	pthread_mutex_destroy(&mutex_fuel);
	pthread_mutex_destroy(&mutex_water);
	return (0);
}
