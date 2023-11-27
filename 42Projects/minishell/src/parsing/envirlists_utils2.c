/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirlists_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:17:03 by ipetruni          #+#    #+#             */
/*   Updated: 2023/11/23 18:17:40 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_enviter(t_envir *lst, int fd_out, void (*f)(t_envir *, int))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst, fd_out);
		lst = lst->next;
	}
}

t_envir	*ft_envlast(t_envir *lst)
{
	t_envir	*node;

	node = lst;
	if (node != NULL)
	{
		while (node->next != NULL)
			node = node->next;
	}
	return (node);
}

t_envir	*ft_envnew(void)
{
	t_envir	*head;

	head = malloc(sizeof(t_envir));
	if (!head)
		return (NULL);
	head->var_name = NULL;
	head->var_value = NULL;
	head->visible = 0;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

int	ft_envsize(t_envir *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
