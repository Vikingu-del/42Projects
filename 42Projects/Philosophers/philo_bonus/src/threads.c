/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:03:11 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/07 18:30:12 by eseferi          ###   ########.fr       */
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
	pthread_t	check_if_dead;

	pthread_create(&check_if_dead, NULL, monitor, philo);
	pthread_detach(check_if_dead);
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		eat(philo);
		if (philo->meals_eaten == philo->num_times_to_eat)
		{
			exit(2);
		}
		ft_usleep(10);
		dream(philo);
		think(philo);
	}
	if (*philo->dead == 1)
		exit(3);
}