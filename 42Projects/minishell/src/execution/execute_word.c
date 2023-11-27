/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:40:22 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 18:22:18 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_word(t_data *data, t_tree *tree, int fd_inp, int fd_out)
{
	if (tree == NULL || tree->value == NULL || tree->args_array == NULL)
		return (1);
	if (is_builtin(tree->args_array[0]))
	{
		if (execute_builtin(data, tree, fd_out))
			return (data->exit_status);
	}
	else
	{
		if (ft_strlen(tree->value) == 0)
			return (1);
		if (execute_command(data, tree, fd_inp, fd_out))
			return (1);
	}
	return (0);
}

int	execute_command(t_data *data, t_tree *tree, int fd_inp, int fd_out)
{
	char			*exec_path;
	t_command_args	args;

	exec_path = find_executable_path(data, tree->args_array[0]);
	if (exec_path == NULL)
	{
		ft_putstr_fd("minishell: ", 0);
		ft_putstr_fd(tree->args_array[0], 0);
		ft_putstr_fd(": command not found\n", 0);
		data->exit_status = 127;
		return (1);
	}
	args.data = data;
	args.tree = tree;
	args.exec_path = exec_path;
	args.fd_inp = fd_inp;
	args.fd_out = fd_out;
	return (fork_command(&args));
}

char	**env(t_envir **lst)
{
	char	**envp;
	t_envir	*tmp;
	int		i;

	if (!lst)
		return (NULL);
	i = 0;
	tmp = *lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	envp = malloc(sizeof(char *) * (i + 1));
	fill_envp(envp, lst);
	return (envp);
}

void	fill_envp(char **envp, t_envir **lst)
{
	int		i;
	int		len;
	t_envir	*tmp;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		len = ft_strlen(tmp->var_name) + ft_strlen(tmp->var_value) + 2;
		envp[i] = malloc(len);
		ft_strcpy(envp[i], tmp->var_name);
		ft_strcat(envp[i], "=");
		ft_strcat(envp[i], tmp->var_value);
		i++;
		tmp = tmp->next;
	}
	envp[i] = NULL;
}

void	print2darray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
}
