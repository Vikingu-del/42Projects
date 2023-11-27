/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_redin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:59:13 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 11:11:03 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_redirection(char *file_name, int last_fd)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd >= 0)
	{
		if (last_fd != 0)
			close(last_fd);
		ft_strdel(&file_name);
		return (fd);
	}
	else
	{
		printf("minishell: %s: No such file or directory\n", file_name);
		ft_strdel(&file_name);
		return (-1);
	}
}

int	get_input_file(t_tree *tree)
{
	int		last_fd;
	char	*file_name;
	t_tree	*curr;

	curr = tree->left;
	last_fd = 0;
	while (curr != NULL)
	{
		file_name = ft_strdup(curr->value);
		if (curr->type == T_RED_INP || curr->type == T_DELIM)
		{
			last_fd = handle_redirection(file_name, last_fd);
			if (last_fd == -1)
				return (-1);
		}
		curr = curr->right;
	}
	return (last_fd);
}
