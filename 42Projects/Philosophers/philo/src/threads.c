/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:03:11 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/04 11:28:27 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	*thread;

	i = 0;
	while (i < philos[0]. num_of_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, &routine, &philos[i]))
			return (destroy_data("failed to create thread", data, forks), 1);
		i++;
	}
	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (pthread_join(philos[i].thread, (void **)&thread))
			return (destroy_data("failed to join thread", data, forks), 1);
		i++;
	}
	return (0);		
}

void	sleep(int time, t_philo *philo)
{
	size_t	start;

	start = gettimeofday_custom();
	while (gettimeofday_custom() - start < time)
	{
		if (philo->dead)
			return ;
		else
			printf("%zu %d is sleeping\n", gettimeofday_custom() - philo->start_time, philo->id);
		usleep(100);
	}
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->dead)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	else
		return (pthread_mutex_unlock(philo->dead_lock), 0);
}
