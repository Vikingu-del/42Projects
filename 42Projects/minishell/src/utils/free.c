/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:48:33 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 05:45:51 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->env_list)
		ft_envclear(&data->env_list);
	if (data->sorted_env_list)
		ft_envclear(&data->sorted_env_list);
	if (data->token_list)
		free_tokens(&data->token_list, free);
	if (data->curr_dir)
		ft_strdel(&data->curr_dir);
	if (data->input_line)
		ft_strdel(&data->input_line);
	if (data->root_directory && *data->root_directory)
		free_2darray(data->root_directory);
	if (data->heredoc_file)
		free_heredoc_files(data->heredoc_file);
	if (data->tree)
	{
		free_tree(&data->tree);
		data->tree = NULL;
	}
	free(data);
	data = NULL;
}

void	free_temp_data(t_data *data)
{
	if (!data)
		return ;
	if (data->input_line)
		ft_strdel(&data->input_line);
	if (data->token_list)
		free_tokens(&data->token_list, free);
	free(data);
	data = NULL;
}

void	free_tokens(t_token **begin, void (*del)(void *))
{
	t_token	*tmp;
	t_token	*tmp2;

	if (!begin || !del)
		return ;
	tmp = *begin;
	while (tmp)
	{
		ft_strdel(&tmp->word);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	*begin = NULL;
}

void	free_envir(t_envir *envir)
{
	t_envir	*tmp;

	if (!envir)
		return ;
	tmp = envir;
	if (tmp->var_name)
	{
		free(tmp->var_name);
		tmp->var_name = NULL;
	}
	if (tmp->var_value)
	{
		free(tmp->var_value);
		tmp->var_value = NULL;
	}
	free(tmp);
}

void	free_heredoc_files(t_heredoc_file *head)
{
	t_heredoc_file	*tmp;
	int				ret;

	while (head != NULL)
	{
		tmp = head->next;
		ret = unlink(head->filename);
		if (ret < 0)
			printf("minishell: %s\n", strerror(errno));
		free(head->filename);
		free(head);
		head = tmp;
	}
}
