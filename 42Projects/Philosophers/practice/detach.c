#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h>

#define THREAD_NUM 2

void	*routine(void *arg) {
	sleep(1);
	printf("Finished execution\n");
}

int	main(void) {
	pthread_t th[THREAD_NUM];
	pthread_attr_t detached_thread;
	pthread_attr_init(&detached_thread);
	pthread_attr_setdetachstate(&detached_thread, PTHREAD_CREATE_DETACHED);

	int i;
	for (i = 0; i < THREAD_NUM; i++)
	{
		if (pthread_create(&th[i], &detached_thread, &routine, NULL) != 0)
			perror("Failed to create thread");
		// pthread_detach(th[i]);
	}
	// for (i = 0; i < THREAD_NUM; i++)
	// {
	// 	if (pthread_join(th[i], NULL) != 0)
	// 		perror("Failed to join thread");
	// }
	pthread_attr_destroy(&detached_thread);
	pthread_exit(0);
}
