/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:36:18 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/07 16:52:33 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// closes the sempahores and unlinks them

void close_semaphores(t_semaphores *sems)
{
	sem_close(sems->forks);
	sem_unlink("forks");
	sem_close(sems->write_lock);
	sem_unlink("write_lock");
	sem_close(sems->dead_lock);
	sem_unlink("dead_lock");
	sem_close(sems->stop_lock);
	sem_unlink("stop_lock");
}

// open the semaphores

int	open_semaphores(t_semaphores *sems, int num)
{
	int i;

	i = 0;
	close_semaphores(sems);
	sems->forks = sem_open("forks", O_CREAT, 0644, num);
	sems->write_lock = sem_open("write_lock", O_CREAT, 0644, 1);
	sems->dead_lock = sem_open("dead_lock", O_CREAT, 0644, 1);
	sems->stop_lock = sem_open("stop_lock", O_CREAT, 0644, 1);
	if (sems->forks == SEM_FAILED || sems->write_lock == SEM_FAILED 
		|| sems->dead_lock == SEM_FAILED || sems->stop_lock == SEM_FAILED)
		return (ft_putendl_fd(SEM_OPEN_FAIL, 2), 1);
	return (0);
}

// Checks that the input is only numbers

int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

// Checks if the program input is correct

int	check_valid_args(char **argv)
{
	if (!has_only_digits(argv[1]) || !has_only_digits(argv[2])
		|| !has_only_digits(argv[3]) || !has_only_digits(argv[4])
		|| (argv[5] && !has_only_digits(argv[5])))
		return (ft_putendl_fd(WRONG_ARG_TYPE, 2), 1);
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
		return (ft_putendl_fd(NUM_PHILO, 2), 1);
	if (ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
		return (ft_putendl_fd(DIE_TIME, 2), 1);
	if (ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
		return (ft_putendl_fd(EAT_TIME, 2), 1);
	if (ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
		return (ft_putendl_fd(SLEEP_TIME, 2), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
		return (ft_putendl_fd(NUM_EAT, 2), 1);
	return (0);
}

void	kill_all(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		kill(program->philos[i].pid, SIGKILL);
		i++;
	}
}

int main(int argc, char *argv[])
{
    t_program		program;
	t_philo			philos[PHILO_MAX];
    t_semaphores    sems;

    if (argc != 5 && argc != 6)
        return (ft_putendl_fd(WRONG_NUM_ARGS, 2), 1);
    if (check_valid_args(argv) == 1)
        return (1);
    if (open_semaphores(&sems, ft_atoi(argv[1])) == 1)
		return (1);
    init_program(&program, philos, &sems);
    init_philos(philos, &program, &sems, argv);
	sem_wait(sems.stop_lock);
	init_process(&program);
	sem_wait(sems.stop_lock);
	kill_all(&program);
    close_semaphores(&sems);
    return (0);
}
