/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:17:52 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/04 11:27:41 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_message(char *str, t_philo *philo)
{
	size_t	time;
	
	pthread_mutex_lock(philo->write_lock);
	time = gettimeofday_custom() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	check_if_all_ate(t_philo *philos)
{
	int	i;
	int	all_ate;

	i = 0;
	all_ate = 0;
	if (philos[0].num_times_to_eat == -1)
		return (0);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			all_ate++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (all_ate == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}


int	time_to_die(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (gettimeofday_custom() - philo->last_meal > philo->time_to_die && philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	return (pthread_mutex_unlock(philo->meal_lock), 0);
}

int	check_if_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (time_to_die(&philos[i], philos[i].time_to_die))
		{
			write(1, "💀", 1);
			display_message("died", &philos[i]);
			philos[i].dead = 1;
			pthread_mutex_unlock(philos[0].r_fork);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (1)
	{
		if (check_if_dead(philos) || check_if_all_ate(philos))
			break ;
	}
	return (arg);
}
