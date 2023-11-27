#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int				mails = 0;
pthread_mutex_t	mutex;

void	*thread(void *arg)
{
	for (long int i = 0; i < 100000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
		// read mails
		// increment
		// write mails
	return (NULL);
}

// void	*thread2(void *arg)
// {
// 	i--;
// 	sleep(2);
// 	printf("value of i = %d\n", i);
// 	return (NULL);
// }

int	main(int argc, char *argv[])
{
	pthread_t	th[8];

	pthread_mutex_init(&mutex, NULL);
	for (int i = 0; i < 8; i++)
	{
		if (pthread_create(&th[i], NULL, thread, NULL))
		{
			perror("Failed to create thread\n");
			return (1);
		}
		printf("Thread %d has started execution\n", i);
	}
	for (int i = 0; i < 8; i++)
	{
		if (pthread_join(th[i], NULL))
		{
			perror("Failed to join the thread\n");
			return (2);
		}
		printf("Thread %d has finished execution\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("Number of mails = %d\n", mails);
	return (0);
}