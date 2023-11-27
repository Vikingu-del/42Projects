/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_word_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:26:41 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 16:15:21 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	create_child_process(char **exec_path)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		ft_strdel(exec_path);
	}
	return (pid);
}

void	redirect_fds(int fd_inp, int fd_out)
{
	if (fd_inp != STDIN_FILENO)
	{
		dup2(fd_inp, STDIN_FILENO);
		if (fd_inp != 0)
			close(fd_inp);
	}
	if (fd_out != STDOUT_FILENO)
	{
		dup2(fd_out, STDOUT_FILENO);
		if (fd_out != 1)
			close(fd_out);
	}
}

void	execute_forked_command(t_data *data, t_tree *tree, char *exec_path)
{
	char	**envp;

	envp = env(&data->env_list);
	if (execve(exec_path, tree->args_array, envp) == -1)
	{
		printf("execve failed\n");
		ft_strdel(&exec_path);
		data->exit_status = 127;
		exit(127);
	}
	if (exec_path)
		ft_strdel(&exec_path);
	free_2darray(envp);
	exit(EXIT_SUCCESS);
}

int	handle_exit_status(t_data *data, pid_t pid, int status, char **exec_path)
{
	if (g_child_pid == pid + 1)
		return (data->exit_status = 130, g_child_pid = 0, \
		ft_strdel(exec_path), 1);
	else if (g_child_pid == pid + 2)
		return (data->exit_status = 131, g_child_pid = 0, \
		ft_strdel(exec_path), 1);
	if (WIFEXITED(status))
		return (data->exit_status = WEXITSTATUS(status), \
		g_child_pid = 0, ft_strdel(exec_path), 1);
	return (g_child_pid = 0, ft_strdel(exec_path), 0);
}

int	fork_command(t_command_args *args)
{
	pid_t	pid;
	int		status;

	pid = create_child_process(&args->exec_path);
	if (pid == 0)
	{
		redirect_fds(args->fd_inp, args->fd_out);
		execute_forked_command(args->data, args->tree, args->exec_path);
	}
	else
	{
		g_child_pid = pid;
		waitpid(pid, &status, 0);
		return (handle_exit_status(args->data, pid, status, &args->exec_path));
	}
	return (0);
}
