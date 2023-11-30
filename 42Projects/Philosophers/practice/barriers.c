#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_barrier_t	barrier;

void	*routine(void *args) {
	(void)args;
	printf("Waiting at the barrier...\n");
	sleep(1);
	pthread_barrier_wait(&barrier);
	printf("Passed the barrier!\n");
	sleep(1);
	return (NULL);
}

int	main(void)
{
	pthread_t th[10];
	int i;

	pthread_barrier_init(&barrier, NULL, 7);
	for(i = 0; i < 10; i++) {
		if (pthread_create(&th[i], NULL, &routine, NULL) != 0)
			perror("Failed to create thread\n");
	}
	for(i = 0; i < 10; i++) {
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread\n");
	}
	pthread_barrier_destroy(&barrier);
	return (0);
}
