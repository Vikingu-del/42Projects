/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:13:54 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/01 19:37:53 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_valid_input(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
		return (ft_putendl_fd(WRONG_NUM_ARGS, 2), 1);
	if (!ft_is_all_digits(argv[1]) || !ft_is_all_digits(argv[2])
		|| !ft_is_all_digits(argv[3]) || !ft_is_all_digits(argv[4]) || (argv[5]
		&& !ft_is_all_digits(argv[5])))
		return (ft_putendl_fd(WRONG_ARG_TYPE, 2), 1);
	if (ft_atoi(argv[1]) < 1)
		return (ft_putendl_fd(NUM_PHILO, 2), 1);
	if (ft_atoi(argv[2]) < 0)
		return (ft_putendl_fd(DIE_TIME, 2), 1);
	if (ft_atoi(argv[3]) < 0)
		return (ft_putendl_fd(EAT_TIME, 2), 1);
	if (ft_atoi(argv[4]) < 0)
		return (ft_putendl_fd(SLEEP_TIME, 2), 1);
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (ft_putendl_fd(NUM_EAT, 2), 1);
	return (0);
}