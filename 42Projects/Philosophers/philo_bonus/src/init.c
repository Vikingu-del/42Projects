/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:51:50 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/07 18:02:47 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// Initializing the input from user

void	init_input(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	philo->num_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

// Initializing the philosophers

void	init_philos(t_philo *philos, t_program *program, t_semaphores *sems,
		char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		init_input(&philos[i], argv);
		philos[i].start_time = get_current_time();
		philos[i].last_meal = get_current_time();
		philos[i].write_lock = program->write_lock;
		philos[i].meal_lock = sems->meal_lock;
		philos[i].dead_lock = program->dead_lock;
		philos[i].stop_lock = program->stop_lock;
		philos[i].dead = &program->dead_flag;
		philos[i].forks = sems->forks;
		i++;
	}
}

// Initializing the child processes

void	init_process(t_program *program)
{
	int	i;
	int	status;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	while (i < program->philos[0].num_of_philos)
	{
		program->philos[i].pid = fork();
		if (program->philos[i].pid < 0)
		{
			ft_putendl_fd(FORK_FAIL, 2);
			exit(1);
		}
		else if (program->philos[i].pid == 0)
		{
			philo_routine(&program->philos[i]);
			exit(0);
		}
		i++;
		usleep(100);
	}
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		waitpid(program->philos[i].pid, &status, 0);
		if (WEXITSTATUS(status) == 2)
			finished_eating++;
		else if (WEXITSTATUS(status) == 3)
			kill_all(program);
		i++;
	}
	if (program->philos[0].num_times_to_eat != -1 && finished_eating == program->philos[0].num_of_philos)
		sem_post(program->stop_lock);
	else if (program->philos[0].num_times_to_eat == -1)
		sem_post(program->stop_lock);
}

// Initializing the program structure

void init_program(t_program *program, t_philo *philos, t_semaphores *sems)
{
    program->dead_flag = 0;
    program->philos = philos;
    program->write_lock = sems->write_lock;
    program->dead_lock = sems->dead_lock;
    program->stop_lock = sems->stop_lock;
	program->meal_lock = sems->meal_lock;
}
