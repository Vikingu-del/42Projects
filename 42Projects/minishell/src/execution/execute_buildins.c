/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_buildins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:05:06 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 13:09:49 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 4) || !ft_strncmp(cmd, "ECHO", 4))
		return (1);
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "pwd") || !ft_strncmp(cmd, "PWD", 4))
		return (1);
	if (!ft_strcmp(cmd, "export"))
		return (1);
	if (!ft_strcmp(cmd, "unset"))
		return (1);
	if (!ft_strcmp(cmd, "env") || !ft_strncmp(cmd, "ENV", 4))
		return (1);
	if (!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

static int	execute_builtin_first_half(t_data *data, t_tree *tree, int fd_out)
{
	if (!ft_strncmp(tree->args_array[0], "echo", 4)
		|| !ft_strncmp(tree->args_array[0], "ECHO", 4))
	{
		if (check_echo(data, tree, fd_out))
			return (data->exit_status = 1, 1);
	}
	if (!ft_strcmp(tree->args_array[0], "cd")
		|| !ft_strcmp(tree->args_array[0], "CD"))
	{
		if (tree->args_array[1])
		{
			if (execute_cd(data, tree->args_array[1]))
				return (data->exit_status = 1, 1);
		}
		else if (execute_cd(data, NULL))
			return (data->exit_status = 1, 1);
	}
	if (!ft_strcmp(tree->args_array[0], "pwd")
		|| !ft_strcmp(tree->args_array[0], "PWD"))
		if (execute_pwd(data))
			return (data->exit_status = 1, 1);
	return (0);
}

static int	execute_builtin_second_half(t_data *data, t_tree *tree, int fd_out)
{
	if (!ft_strcmp(tree->args_array[0], "export")
		|| !ft_strcmp(tree->args_array[0], "EXPORT"))
		if (execute_export(data, tree, fd_out))
			return (data->exit_status = 1, 1);
	if (!ft_strcmp(tree->args_array[0], "unset")
		|| !ft_strcmp(tree->args_array[0], "UNSET"))
		if (execute_unset(data, tree))
			return (data->exit_status = 1, 1);
	if (!ft_strcmp(tree->args_array[0], "env")
		|| !ft_strcmp(tree->args_array[0], "ENV"))
		execute_env(&data->env_list, fd_out);
	if (!ft_strcmp(tree->args_array[0], "exit")
		|| !ft_strcmp(tree->args_array[0], "EXIT"))
		if (execute_exit(data, tree))
			return (data->exit_status = 1, 1);
	return (0);
}

int	execute_builtin(t_data *data, t_tree *tree, int fd_out)
{
	if (execute_builtin_first_half(data, tree, fd_out))
		return (1);
	if (execute_builtin_second_half(data, tree, fd_out))
		return (1);
	return (0);
}

int	check_echo(t_data *data, t_tree *tree, int fd_out)
{
	char	**cmd;

	cmd = NULL;
	if (!ft_strcmp(tree->args_array[0], "echo")
		|| !ft_strcmp(tree->args_array[0], "ECHO"))
	{
		if (execute_echo(tree->args_array, fd_out))
			return (1);
	}
	else
	{
		if (!ft_strncmp(tree->args_array[0], "echo", 4))
		{
			ft_putstr_fd("minishell: ", fd_out);
			ft_putstr_fd(tree->args_array[0], fd_out);
			ft_putstr_fd(": command not found\n", fd_out);
			data->exit_status = 127;
			return (1);
		}
	}
	return (0);
}
