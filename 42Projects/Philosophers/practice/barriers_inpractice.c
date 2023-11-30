//
// Created by segfault on 28.11.23.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_NUM 8
int                 dice_values[8];
int                 status[8] = { 0 };
pthread_barrier_t   barrierRolledDice;
pthread_barrier_t   barrierCalculated;

void    *roll(void *args) {
    int index = *(int*)args;
    while (1) {
        dice_values[index] = rand() % 32 + 1;
        pthread_barrier_wait(&barrierRolledDice);
        pthread_barrier_wait(&barrierCalculated);
        if (status[index] == 1) {
            printf("(%d rolled %d) I won\n", index, dice_values[index]);
        } else {
            printf("(%d rolled %d) I lost\n", index, dice_values[index]);
        }
    }
    free(args);
    return (NULL);
}

int main(void) {
    srand(time(NULL));
    pthread_t th[THREAD_NUM];
    int i;
    pthread_barrier_init(&barrierRolledDice, NULL, THREAD_NUM + 1);
    pthread_barrier_init(&barrierCalculated, NULL, THREAD_NUM + 1);
    for (i = 0; i < THREAD_NUM; i++) {
        int* a = malloc(sizeof(int));
        *a = i;
        if (pthread_create(&th[i], NULL, &roll, (void*) a) != 0) {
            perror("Failed to create thread");
        }
    }
    while (1) {
        pthread_barrier_wait(&barrierRolledDice);
        // Calculate winner
        int max = 0;
        for (i = 0; i < THREAD_NUM; i++) {
            if (dice_values[i] > max) {
                max = dice_values[i];
            }
        }

        for (i = 0; i < THREAD_NUM; i++) {
            if (dice_values[i] == max) {
                status[i] = 1;
            } else {
                status[i] = 0;
            }
        }
        sleep(1);
        printf("==== New round starting ====\n");
        pthread_barrier_wait(&barrierCalculated);
    }
    for (i = 0; i < THREAD_NUM; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }
    pthread_barrier_destroy(&barrierRolledDice);
    pthread_barrier_destroy(&barrierCalculated);
    return (0);
}
