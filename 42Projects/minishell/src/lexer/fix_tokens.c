/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:15:43 by ipetruni          #+#    #+#             */
/*   Updated: 2023/11/25 18:15:46 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	find_ortokens(t_token **head)
{
	t_token	*current;
	t_token	*tmp;
	t_token	*tmp2;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		if (tmp->type == T_PIPE && tmp->next->type == T_PIPE)
		{
			tmp->type = T_OR;
			ft_strdel(&tmp->word);
			tmp->word = ft_strdup("||");
			ft_strdel(&tmp->next->word);
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			tmp->next->prev = tmp;
			free(tmp2);
		}
		current = current->next;
	}
}

void	find_andtokens(t_token **head)
{
	t_token	*current;
	t_token	*tmp;
	t_token	*tmp2;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		if (tmp->type == T_AMPER && tmp->next->type == T_AMPER)
		{
			tmp->type = T_AND;
			ft_strdel(&tmp->word);
			tmp->word = ft_strdup("&&");
			ft_strdel(&tmp->next->word);
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			tmp->next->prev = tmp;
			free(tmp2);
		}
		current = current->next;
	}
}

void	find_threein(t_token **head)
{
	t_token	*current;
	t_token	*tmp;
	t_token	*tmp2;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		if (tmp->type == T_RED_INP && tmp->next->type == T_RED_INP)
			find_delim(tmp);
		if (tmp->type == T_DELIM && tmp->next->type == T_RED_INP)
		{
			tmp->type = T_THREE_IN;
			ft_strdel(&tmp->word);
			tmp->word = ft_strdup("<<<");
			ft_strdel(&tmp->next->word);
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			tmp->next->prev = tmp;
			free(tmp2);
		}
		current = current->next;
	}
}

void	find_delim(t_token *current)
{
	t_token	*tmp;
	t_token	*tmp2;

	tmp = current;
	if (tmp->type == T_RED_INP && tmp->next->type == T_RED_INP)
	{
		tmp->type = T_DELIM;
		ft_strdel(&tmp->word);
		tmp->word = ft_strdup("<<");
		tmp2 = tmp->next;
		tmp->next = tmp->next->next;
		tmp->next->prev = tmp;
		ft_strdel(&tmp2->word);
		free(tmp2);
	}
}

void	find_threeout(t_token **head)
{
	t_token	*current;
	t_token	*tmp;
	t_token	*tmp2;

	current = *head;
	while (current != NULL)
	{
		tmp = current;
		if (tmp->type == T_RED_OUT && tmp->next->type == T_RED_OUT)
			find_append(tmp);
		if (tmp->type == T_APPEND && tmp->next->type == T_RED_OUT)
		{
			tmp->type = T_THREE_OUT;
			ft_strdel(&tmp->word);
			tmp->word = ft_strdup(">>>");
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			tmp->next->prev = tmp;
			ft_strdel(&tmp2->word);
			free(tmp2);
		}
		current = current->next;
	}
}
