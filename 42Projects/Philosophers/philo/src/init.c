/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:51:50 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/01 19:36:07 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_data_mutexes(t_philo *philos)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_putendl_fd(MALLOC_FAIL, 2), NULL);
	data->dead_flag = 0;
	if (pthread_mutex_init(&data->dead_lock, NULL)
		|| pthread_mutex_init(&data->meal_lock, NULL)
		|| pthread_mutex_init(&data->write_lock, NULL))
		return (ft_putendl_fd(MALLOC_FAIL, 2), free(data), NULL);
	data->philos = philos;
	return (data);
}

void	destroy_data(char *str, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
		ft_putendl_fd(str, 2);
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
	while (i < data->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	if (data->philos)
		free(data->philos);
	if (forks)
		free(forks);
	if (data)
		free(data);
}

void init_philos(t_philo *philos, pthread_mutex_t *forks, t_data *data, char *argv[])
{
	int	i;
	int	philo_count;

	i = 0;
	philo_count = ft_atoi(argv[1]);
	while (i < philo_count)
	{
		philos->id = i + 1;
		philos->eating = 0;
		philos->meals_eaten = 0;
		philos->dead = &data->dead_flag;
		parse_input(philos, argv);
		philos->start_time = gettimeofday_custom();
		philos->last_meal = philos->start_time;
		philos->write_lock = &data->write_lock;
		philos->dead_lock = &data->dead_lock;
		philos->meal_lock = &data->meal_lock;
		philos->r_fork = &forks[i];
		if (i == 0)
			philos->l_fork = &forks[philo_count - 1];
		else
			philos->l_fork = &forks[i - 1];
		i++;
		philos++;
	}
}

void	parse_input(t_philo *philos, char *argv[])
{
	philos->num_of_philos = ft_atoi(argv[1]);
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philos->num_times_to_eat = ft_atoi(argv[5]);
	else
		philos->num_times_to_eat = -1;
}

void	init_forks(pthread_mutex_t *forks, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}
