/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:32:51 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/22 11:03:47 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	reset_data(t_data *data)
{
	data->single_quote = 0;
	data->double_quote = 0;
	data->forked = 0;
	if (data->root_directory && *data->root_directory)
		free_2darray(data->root_directory);
	if (data->heredoc_file)
	{
		free_heredoc_files(data->heredoc_file);
		data->heredoc_file = NULL;
	}
	data->root_directory = get_root_directory();
	if (data->input_line && ft_strlen(data->input_line) > 0)
		ft_strdel(&data->input_line);
	if (data->tree)
	{
		free_tree(&data->tree);
		data->tree = NULL;
	}
	if (data->token_list)
		free_tokens(&data->token_list, free);
}
