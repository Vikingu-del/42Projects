/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:21:49 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 18:05:13 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token(t_token **head, t_token *new)
{
	t_token	*tmp;

	if (!new || !head)
		return ;
	if (*head)
	{
		tmp = *head;
		while (tmp->next)
		{
			tmp->next->prev = tmp;
			tmp = tmp->next;
		}
		tmp->next = new;
		new->prev = tmp;
		new->next = NULL;
	}
	else
	{
		*head = new;
		new->prev = NULL;
		new->next = NULL;
	}
}

t_token	*last_token(t_token *lst)
{
	t_token	*node;

	node = lst;
	if (node != NULL)
	{
		while (node->next != NULL)
			node = node->next;
	}
	return (node);
}

void	add_token_front(t_token **head, t_token *new)
{
	if (*head)
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}
	else
		*head = new;
}

int	tokens_len(t_token **head)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = *head;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
