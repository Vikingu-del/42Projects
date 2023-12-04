/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segfault <segfault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:36:18 by eseferi           #+#    #+#             */
/*   Updated: 2023/12/04 15:14:52 by segfault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	t_data			*data;
	
	if (check_valid_input(argc, argv))
		return (0);
	else
	{
		philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
		forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
		if (!philos || !forks)
			return (ft_putendl_fd(MALLOC_FAIL, 2), 1);
		data = init_data_mutexes(philos);
		if (!data)
			return (free(philos), free(forks), 1);
		init_forks(forks, ft_atoi(argv[1]));
		init_philos(philos, forks, data, argv);
		if (create_threads(data, forks))
			return (1);
	}
	return (destroy_data("finished", data, forks), 0);
}
