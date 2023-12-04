#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

// chefs = threads
// stove = shared data (+mutex)

pthread_mutex_t stovemutex[4];
int stovefuel[4] = {100, 100, 100, 100};

void *routine(void *arg)
{
    for (int i = 0; i < 4; i++)
    {
        if (pthread_mutex_trylock(&stovemutex[i]) == 0)
        {
            int fuelneeded = (rand() % 30);
            if (stovefuel[i] - fuelneeded < 0)
            {
                printf("No more fuel\n");
            }
            else
            {
                stovefuel[i] -= fuelneeded;
                usleep(500000);
                printf("Fuel left: %d\n", stovefuel[i]);
            }
            pthread_mutex_unlock(&stovemutex[i]);
            break ;
        }
        else
        {
            if (i == 3)
            {
                printf("No stove available yet waiting...\n");
                usleep(300000);
                i = 0;
            }
        }
    }
}

int main(int argc, char *argv[])
{
	pthread_t th[10];
    for (int i = 0; i < 4; i++)
    {
        pthread_mutex_init(&stovemutex[i], NULL);
    }
	for (int i = 0; i < 10; i++)
	{
		if (pthread_create(&th[i], NULL, &routine, NULL))
			perror("Error at creating thread\n");
	}
	for (int i = 0; i < 10; i++)
	{
		if (pthread_join(th[i], NULL))
			perror("Error at joining thread\n");
	}
    for (int i = 0; i < 4; i++)
    {
        pthread_mutex_destroy(&stovemutex[i]);
    }
	return (0);
}