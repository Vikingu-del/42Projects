/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:17:52 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/07 17:49:03 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// Print message funtion

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	sem_wait(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	sem_post(philo->write_lock);
}

// Checks if the philosopher is dead

int	philosopher_dead(t_philo *philo, size_t time_to_die)
{
	sem_wait(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die 
		&& philo->eating == 0)
	{
		sem_post(philo->meal_lock);
		return (1);
	}
	sem_post(philo->meal_lock);
	return (0);
}

// Check if any philo died

int	check_if_dead(t_philo *philos)
{
	if (philosopher_dead(philos, philos->time_to_die))
	{
		print_message("died", philos, philos->id);
		sem_wait(philos->dead_lock);
		*philos->dead = 1;
		sem_post(philos->dead_lock);
		sem_post(philos->stop_lock);
		return (1);
	}
    return (0);
}

// Checks if all the philos ate the num_of_meals

int	check_if_ated_all_meals(t_philo *philos)
{
	sem_wait(philos->meal_lock);
	if (philos->num_times_to_eat != -1 
		&& philos->meals_eaten >= philos->num_times_to_eat)
	{
		sem_post(philos->meal_lock);
		return (1);
	}
	return (sem_post(philos->meal_lock), 0);
}

// Monitor routine

void	*monitor(void *philos_void)
{
	t_philo	*philos;
	
	philos = (t_philo *)philos_void;
	while (1)
	{
		if (check_if_dead(philos) == 1)
			break ;
		if (check_if_ated_all_meals(philos) == 1)
			break ;
		usleep(100);
	}
	return (NULL);
}
