/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:51 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 10:33:00 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute(t_data *data)
{
	int	result;

	result = evaluate_execution(data, data->tree);
	data->exit_status = result;
	return (result);
}

int	execute_and_handle_files(t_data *data, t_tree *tree)
{
	int	fd_out;
	int	fd_inp;

	fd_out = get_output_file(tree);
	fd_inp = get_input_file(tree);
	if (fd_inp == -1)
	{
		if (fd_out != 1)
			close(fd_out);
		return (1);
	}
	if (execute_word(data, tree, fd_inp, fd_out))
	{
		if (fd_inp != 0)
			close(fd_inp);
		if (fd_out != 1)
			close(fd_out);
		return (data->exit_status);
	}
	if (fd_inp != 0)
		close(fd_inp);
	if (fd_out != 1)
		close(fd_out);
	return (0);
}

int	evaluate_execution(t_data *data, t_tree *tree)
{
	int	fd_inp;
	int	fd_out;
	int	result;

	fd_inp = 0;
	fd_out = 1;
	if (is_logic_root(tree))
		if (execute_logic(data, tree))
			return (1);
	if (tree->type == T_PIPE)
		if (execute_pipe(data, tree))
			return (1);
	if (is_word_root(tree))
	{
		result = execute_and_handle_files(data, tree);
		return (result);
	}
	return (0);
}

int	execute_logic(t_data *data, t_tree *tree)
{
	if (tree->type == T_AND)
		if (execute_and(data, tree))
			return (1);
	if (tree->type == T_OR)
		if (execute_or(data, tree))
			return (1);
	return (0);
}
