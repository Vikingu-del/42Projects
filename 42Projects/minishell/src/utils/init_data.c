/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:33:01 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/22 03:19:42 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data **data, char **envp)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		exit(EXIT_FAILURE);
	(*data)->env_list = NULL;
	(*data)->heredoc_file = NULL;
	(*data)->sorted_env_list = NULL;
	(*data)->token_list = NULL;
	(*data)->input_line = NULL;
	(*data)->tree = NULL;
	(*data)->root_directory = NULL;
	(*data)->exit_status = 0;
	(*data)->input_minishell = "minishell>> ";
	(*data)->pid = getpid();
	(*data)->curr_dir = getcwd(NULL, 0);
	fill_env(envp, *data);
	incr_shell_lvl(*data);
}
