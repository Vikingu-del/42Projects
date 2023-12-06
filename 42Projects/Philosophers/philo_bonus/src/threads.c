/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:03:11 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/06 10:57:36 by eseferi          ###   ########.fr       */
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

void	philo_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		ft_usleep(1);
    while (!dead_loop(philo))
	{
        eat(philo);
        dream(philo);
        think(philo);
    }
}

