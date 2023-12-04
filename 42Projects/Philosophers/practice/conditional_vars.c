#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

int fuel = 0;
pthread_cond_t cond_fuel;
pthread_mutex_t mutexFuel;

void *fuel_filling(void *arg)
{
    for (int i = 0; i < 6; i++)
    {
        pthread_mutex_lock(&mutexFuel);
        fuel += 30;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_broadcast(&cond_fuel);
        sleep(1);
    }
}

void *car(void *arg)
{
    pthread_mutex_lock(&mutexFuel);
    while (fuel < 40)
    {
        printf("No fuel, waiting...\n");
        pthread_cond_wait(&cond_fuel, &mutexFuel);
        // Equivalent to:
        // pthread_mutex_unlock(&mutexFuel);
        // wait for signal on condfuel
        // pthread_mutex_lock(&mutexFuel);
    }
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}

int main(int argc, char *argv[])
{
    pthread_t th[6];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&cond_fuel, NULL);
    for (int i = 0; i < 6; i++)
    {
        if (i == 4 || i == 5)
        {
            if (pthread_create(&th[i], NULL, &fuel_filling, NULL))
                perror("Error at creating thread\n");
        }
        else
        {
            if (pthread_create(&th[i], NULL, &car, NULL))
                perror("Error at creating thread\n");
        }        
    }
    for (int i = 0; i < 6; i++)
    {
        if (pthread_join(th[i], NULL))
            perror("Error at joining thread\n");
    }
    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&cond_fuel);
    return (0);
}