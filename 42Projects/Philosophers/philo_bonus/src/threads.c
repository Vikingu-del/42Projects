/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segfault <segfault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:03:11 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/04 15:01:23 by segfault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// Checks if the value of dead_flag changed

int	dead_loop(t_philo *philo)
{
	sem_wait(philo->dead_lock);
	if (*philo->dead == 1)
	{
		sem_post(philo->dead_lock);
		return (1);
	}
	sem_post(philo->dead_lock);
	return (0);
}

// Thread routine

void	philo_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
        usleep(1);
    while (!dead_loop(philo)) {
        eat(philo);
        dream(philo);
        think(philo);
    }
}

// // Creates all the threads

// int	thread_create(t_program *program, pthread_mutex_t *forks)
// {
// 	pthread_t	observer;
// 	int			i;

// 	if (pthread_create(&observer, NULL, &monitor, program->philos) != 0)
// 		destory_all("Thread creation error", program, forks);
// 	i = 0;
// 	while (i < program->philos[0].num_of_philos)
// 	{
// 		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
// 				&program->philos[i]) != 0)
// 			destory_all("Thread creation error", program, forks);
// 		i++;
// 	}
// 	i = 0;
// 	if (pthread_join(observer, NULL) != 0)
// 		destory_all("Thread join error", program, forks);
// 	while (i < program->philos[0].num_of_philos)
// 	{
// 		if (pthread_join(program->philos[i].thread, NULL) != 0)
// 			destory_all("Thread join error", program, forks);
// 		i++;
// 	}
// 	return (0);
// }

