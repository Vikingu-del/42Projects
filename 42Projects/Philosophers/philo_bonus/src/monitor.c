/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:17:52 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/06 13:04:38 by eseferi          ###   ########.fr       */
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
	size_t	time;

	sem_wait(philo->meal_lock);
	time = get_current_time() - philo->last_meal;
	if (time >= time_to_die && philo->eating == 0)
		return (sem_post(philo->meal_lock), 1);
	sem_post(philo->meal_lock);
	return 0;
}

// Check if any philo died

int	check_if_dead(t_philo *philos)
{
    int	i;

    i = 0;
    while (i < philos[0].num_of_philos)
    {
        if (philosopher_dead(&philos[i], philos[i].time_to_die))
        {
            print_message("died", &philos[i], philos[i].id);
			sem_wait(philos[0].dead_lock);
            *philos->dead = 1;
			sem_post(philos[0].dead_lock);
            return (1);
        }
        i++;
    }
    return (0);
}

// Checks if all the philos ate the num_of_meals

int	check_if_all_ate(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].num_times_to_eat == -1)
		return (0);
	while (i < philos[0].num_of_philos)
	{
		sem_wait(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			finished_eating++;
		sem_post(philos[i].meal_lock);
		i++;
	}
	if (finished_eating == philos[0].num_of_philos)
	{
		sem_wait(philos[0].dead_lock);
		*philos->dead = 1;
		sem_post(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

// Monitor routine

void	monitor(void *philos_void)
{
    t_philo	*philos;
    
    philos = (t_philo *)philos_void;
    while (1)
    {
        if (check_if_dead(philos) == 1 || check_if_all_ate(philos) == 1)
            exit(0);
    }
}
