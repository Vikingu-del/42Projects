/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_input_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 06:12:26 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 12:46:01 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_filename(t_data *data, t_copy_params *params)
{
	int	k;

	k = 0;
	(*params->new_input_line)[(*params->j)++] = \
	data->input_line[(*params->i)++];
	(*params->new_input_line)[(*params->j)++] = \
	data->input_line[(*params->i)++];
	if (data->input_line[*params->i] == ' ')
		(*params->new_input_line)[(*params->j)++] = \
		data->input_line[(*params->i)++];
	while ((*params->current_file)->filename[k])
		(*params->new_input_line)[(*params->j)++] = \
		(*params->current_file)->filename[k++];
	*params->i += k;
	*params->current_file = (*params->current_file)->next;
}

void	update_input_line(t_data *data)
{
	t_heredoc_file	*current_file;
	char			*new_input_line;
	int				i;
	int				j;
	t_copy_params	params;

	current_file = data->heredoc_file;
	i = 0;
	j = 0;
	if (!current_file)
		return ;
	new_input_line = ft_calloc(ft_strlen(data->input_line) + 10, sizeof(char));
	params.new_input_line = &new_input_line;
	params.i = &i;
	params.j = &j;
	params.current_file = &current_file;
	while (data->input_line[i])
	{
		if (data->input_line[i] == '<' && data->input_line[i + 1] == '<')
			copy_filename(data, &params);
		else
			new_input_line[j++] = data->input_line[i++];
	}
	ft_strdel(&data->input_line);
	data->input_line = new_input_line;
}
