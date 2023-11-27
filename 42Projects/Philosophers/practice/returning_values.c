#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void	*roll_dice()
{
	int value = (rand() % 6) + 1;
	int	*result = malloc(sizeof(int));
	*result = value;
	printf("Thread result %p\n", result);
	return ((void *)result);
}

int main(int argc, char *argv[])
{
	int	*result;
	srand(time(NULL));
	pthread_t	th;

	if (pthread_create(&th, NULL, &roll_dice, NULL))
		return 1;
	if (pthread_join(th, (void **)&result))
		return (2);
	printf("Main result %p\n", result);
	printf("RESULT: %d\n", *result);
	free(result);
	return (0);
}