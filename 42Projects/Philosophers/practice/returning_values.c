#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*roll_dice(void *arg)
{
	(void)arg;
	int value = (rand() % 6) + 1;
	int	*result = malloc(sizeof(int));
	*result = value;
	sleep(2);
	printf("Thread result %d\n", value);
	// pthread_exit((void *)result);
	return ((void *)result);
}

int main(void)
{
	pthread_t	th;
	int			*result;

	srand(time(NULL));
	if (pthread_create(&th, NULL, &roll_dice, NULL))
		return (1);
	// pthread_exit(0);
	if (pthread_join(th, (void **)&result))
		return (2);
	printf("RESULT: %d\n", *result);
	free(result);
	return (0);
}
