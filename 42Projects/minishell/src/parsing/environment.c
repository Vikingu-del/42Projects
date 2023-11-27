/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:58:54 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/23 18:14:01 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_node(t_envir *env_node, int fd_out)
{
	t_envir	*env;
	int		i;

	if (!env_node)
		return ;
	env = env_node;
	i = 0;
	if (!env->visible)
	{
		ft_putstr_fd(env->var_name, fd_out);
		ft_putstr_fd("=", fd_out);
		ft_putstr_fd(env->var_value, fd_out);
		ft_putstr_fd("\n", fd_out);
	}
	else
		return ;
}

void	print_env_node_sorted(t_envir *env_node, int fd_out)
{
	t_envir	*env;
	int		i;

	if (!env_node)
		return ;
	env = env_node;
	i = 0;
	if (env->visible)
	{
		ft_putstr_fd("declare -x ", fd_out);
		ft_putstr_fd(env->var_name, fd_out);
		ft_putstr_fd("\n", fd_out);
	}
	else
	{
		ft_putstr_fd("declare -x ", fd_out);
		ft_putstr_fd(env->var_name, fd_out);
		ft_putstr_fd("=\"", fd_out);
		ft_putstr_fd(env->var_value, fd_out);
		ft_putstr_fd("\"\n", fd_out);
	}
}

void	free_envir_array(char **env_array)
{
	int	i;

	i = 0;
	while (env_array[i])
	{
		free(env_array[i]);
		i++;
	}
	free(env_array);
	env_array = NULL;
}
