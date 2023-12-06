/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:03:11 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/06 23:55:55 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// Checks if the value of dead_flag changed

int	dead_loop(t_philo *philo)
{
	sem_wait(philo->dead_lock);
	if (*philo->dead == 1)
		return (sem_post(philo->dead_lock), 1);
	return (sem_post(philo->dead_lock), 0);
}

// Thread routine

void	philo_routine(t_philo *philo, t_program *program)
{
	pthread_t	monitor_thread;

	if (philo->id % 2 == 0)
		ft_usleep(1);
	// Create the monitor thread
	printf("philos %d last meal: %zu\n",philo->id, philo->last_meal);
	pthread_create(&monitor_thread, NULL, monitor, philo);
	pthread_detach(monitor_thread);
	while (!dead_loop(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	printf("philos %d last meal: %zu\n",philo->id, philo->last_meal);
	if (*philo->dead == 1)
    {
        for (int i = 0; i < program->philos[0].num_of_philos; i++)
        {
            if (program->philos[i].pid != philo->pid)
            {
                kill(program->philos[i].pid, SIGTERM);
            }
        }
    }
}
