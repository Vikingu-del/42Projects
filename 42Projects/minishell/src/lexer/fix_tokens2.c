/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_tokens2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:09:22 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 12:48:44 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fix_tokens(t_token **head, t_data *data)
{
	find_ortokens(head);
	find_andtokens(head);
	find_inout(head);
	find_threeout(head);
	find_threein(head);
	find_asterisk(head, data);
}

void	find_append(t_token *current)
{
	t_token	*tmp;
	t_token	*tmp2;

	tmp = current;
	if (tmp->type == T_RED_OUT && tmp->next->type == T_RED_OUT)
	{
		tmp->type = T_APPEND;
		ft_strdel(&tmp->word);
		tmp->word = ft_strdup(">>");
		tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		tmp->next->prev = tmp;
		ft_strdel(&tmp2->word);
		free(tmp2);
	}
}

void	find_inout(t_token **head)
{
	t_token	*current;
	t_token	*tmp;
	t_token	*tmp2;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		if (tmp->type == T_RED_INP && tmp->next->type == T_RED_OUT)
		{
			tmp->type = T_IN_OUT;
			ft_strdel(&tmp->word);
			tmp->word = ft_strdup("<>");
			ft_strdel(&tmp->next->word);
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			tmp->next->prev = tmp;
			free(tmp2);
		}
		current = current->next;
	}
}

void	clean_null_tokens(t_token **head)
{
	t_token	*current;
	t_token	*tmp;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		if (ft_strlen(tmp->word) == 0 && tmp->type != T_PARENTHESES)
		{
			if (tmp->prev != NULL)
				tmp->prev->next = tmp->next;
			else
				*head = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			current = tmp->next;
			ft_strdel(&tmp->word);
			free(tmp);
		}
		else
			current = current->next;
	}
}

void	find_asterisk(t_token **head, t_data *data)
{
	t_token	*current;
	t_token	*tmp;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		if (tmp->type == T_WORD)
		{
			if ((tmp->prev && tmp->prev->type == T_DELIM)
				|| (has_asterisk(tmp->word) && tmp->prev \
				&& tmp->prev->prev && tmp->prev->type == T_SPACE \
				&& tmp->prev->prev->type == T_DELIM))
				current = current->next;
			else if (has_asterisk(tmp->word))
				extend_asterisk(tmp, data);
		}
		current = current->next;
	}
}
