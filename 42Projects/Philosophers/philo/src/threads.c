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

#include "philo.h"

int	create_threads(t_data *data, pthread_mutex_t *forks)
{
	int			i;
	pthread_t	*controller;

	if (pthread_create(&controller, NULL, &monitor, data->philos) != 0)
		return (destroy_data(THREAD_CREATE_FAIL, data, forks), 1);
	i = 0;
	while (i < data->philos[0].num_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine, &data->philos[i]) != 0)
			return (destroy_data(THREAD_CREATE_FAIL, data, forks), 1);
		i++;
	}
	i = 0;
	if (pthread_join(controller, NULL) != 0)
		return (destroy_data(THREAD_JOIN_FAIL, data, forks), 1);
	while (i < data->philos[0].num_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (destroy_data("failed to join thread", data, forks), 1);
		i++;
	}
	return (0);		
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->dead)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	else
		return (pthread_mutex_unlock(philo->dead_lock), 0);
}
