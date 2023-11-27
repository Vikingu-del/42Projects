/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:33:16 by ipetruni          #+#    #+#             */
/*   Updated: 2023/11/25 18:33:18 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo_handle_option(char **args)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (args[i] && args[i][j] == '-')
	{
		j++;
		while (args[i][j] == 'n')
		{
			j++;
		}
		if (args[i][j] == '\0')
			return (1);
	}
	return (0);
}

int	execute_echo(char *args[], int fd_out)
{
	int		no_newline;
	int		i;
	int		first_arg_printed;

	i = 1;
	first_arg_printed = 0;
	no_newline = echo_handle_option(args);
	if (no_newline)
		i++;
	while (args[i])
	{
		if (args[i][0] != '\0')
		{
			if (first_arg_printed)
				ft_putstr_fd(" ", fd_out);
			ft_putstr_fd(args[i], fd_out);
			first_arg_printed = 1;
		}
		i++;
	}
	if (!no_newline)
		ft_putstr_fd("\n", fd_out);
	return (0);
}
