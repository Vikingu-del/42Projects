/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:55:53 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 17:54:49 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_paths(char **paths, char **original_paths)
{
	paths = original_paths;
	while (*paths)
	{
		ft_strdel(paths);
		paths++;
	}
	free(original_paths);
}

static char	*duplicate_cmd_and_free_paths(char *cmd, char **paths)
{
	char	*command;

	command = ft_strdup(cmd);
	free_2darray(paths);
	return (command);
}

static char	*free_paths_and_return_cmd(char **paths, char **orig_p, char *cmd)
{
	free_paths(paths, orig_p);
	return (cmd);
}

char	*find_executable_path(t_data *data, char *cmd)
{
	char	*tmp;
	char	*command;
	char	**paths;
	t_envir	*path;
	char	**original_paths;

	path = find_envir_variable(data, "PATH", 4);
	if (!path)
		return (NULL);
	paths = ft_split(path->var_value, ':');
	original_paths = paths;
	while (*paths)
	{
		if (access(cmd, X_OK) == 0)
			return (duplicate_cmd_and_free_paths(cmd, paths));
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		ft_strdel(&tmp);
		if (access(command, F_OK) == 0)
			return (free_paths_and_return_cmd(paths, original_paths, command));
		ft_strdel(&command);
		paths++;
	}
	free_paths(paths, original_paths);
	return (NULL);
}

t_envir	*find_envir_variable(t_data *data, char *var_name, int len)
{
	t_envir	*current;

	current = data->env_list;
	while (current)
	{
		if (ft_strncmp(current->var_name, var_name, len) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
