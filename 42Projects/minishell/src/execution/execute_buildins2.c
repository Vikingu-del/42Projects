/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_buildins2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:31:10 by ipetruni          #+#    #+#             */
/*   Updated: 2023/11/25 18:31:13 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_curr_dir(void)
{
	char	*cwd;

	cwd = malloc(PATH_MAX);
	if (!cwd)
	{
		perror("minishell: cd: Cant get the current directory\n");
		return (NULL);
	}
	if (!getcwd(cwd, PATH_MAX))
	{
		free(cwd);
		return (NULL);
	}
	return (cwd);
}

char	*get_home_dir(void)
{
	return (getenv("HOME"));
}

int	execute_pwd(t_data *data)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		return (printf("%s\n", cwd), 0);
	else
		return (data->exit_status = 1, perror("pwd"), 1);
}

int	execute_exit(t_data *data, t_tree *tree)
{
	int	i;

	i = 0;
	if (tree->args_array[1])
	{
		if (!ft_has_only_digit(tree->args_array[1]))
		{
			data->exit_status = 255;
			printf("minishell: exit: %s: numeric argument required\n", \
			tree->args_array[1]);
		}
		else
		{
			i = ft_atoi(tree->args_array[1]);
			data->exit_status = i;
			exit_shell("exit", i, data);
		}
	}
	else
		exit_shell("exit", 0, data);
	exit(0);
}

void	execute_env(t_envir **env, int fd_out)
{
	ft_enviter(*env, fd_out, print_env_node);
}
