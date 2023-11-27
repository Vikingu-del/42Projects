/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenise_for_tree_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 08:40:25 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 08:41:42 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initialize_vars(t_tokenise_tree *vars, t_token *t_parenth)
{
	vars->atach_left = t_parenth->prev;
	vars->atach_right = t_parenth->next;
	vars->temp_data = init_temp_data();
	vars->temp_data->input_line = ft_strdup(t_parenth->word);
}

int	handle_lexical_analysis(t_tokenise_tree *vars)
{
	if (lexical_analysis_tree(vars->temp_data, vars->temp_data->input_line))
		return (1);
	vars->new_tokens = copy_tokens(vars->temp_data->token_list);
	if (!vars->new_tokens)
	{
		printf("malloc error\n");
		return (1);
	}
	free_temp_data(vars->temp_data);
	vars->head = vars->new_tokens;
	vars->temp = vars->head;
	return (0);
}

void	find_tail(t_tokenise_tree *vars)
{
	while (vars->temp && vars->temp->type != T_NEWLINE)
		vars->temp = vars->temp->next;
	vars->tail = vars->temp->prev;
	ft_strdel(&vars->temp->word);
	free(vars->temp);
}

void	handle_atach_left(t_tokenise_tree *vars, t_data *data)
{
	if (!vars->atach_left && vars->head)
	{
		vars->head->prev = NULL;
		data->token_list = vars->head;
	}
	if (vars->atach_left && vars->head)
	{
		ft_strdel(&vars->atach_left->next->word);
		free(vars->atach_left->next);
		vars->atach_left->next = vars->head;
		vars->head->prev = vars->atach_left;
	}
}

void	handle_atach_right(t_tokenise_tree *vars)
{
	if (vars->atach_right->type && vars->tail)
	{
		if (!vars->atach_left)
		{
			ft_strdel(&vars->atach_right->prev->word);
			free(vars->atach_right->prev);
		}
		vars->atach_right->prev = vars->tail;
		vars->tail->next = vars->atach_right;
	}
	else
	{
		ft_strdel(&vars->atach_right->prev->word);
		vars->atach_right->prev = vars->tail;
		vars->tail->next = vars->atach_right;
	}
}
