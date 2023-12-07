/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:36:18 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/07 03:44:17 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

// Main function

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		return (ft_putendl_fd(WRONG_NUM_ARGS, 2), 1);
	if (check_valid_args(argv) == 1)
		return (1);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &program, forks, argv);
	thread_create(&program, forks);
	destory_all(NULL, &program, forks);
	return (0);
}

