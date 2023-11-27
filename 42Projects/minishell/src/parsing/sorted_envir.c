/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_envir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:08:09 by ipetruni          #+#    #+#             */
/*   Updated: 2023/11/23 18:09:20 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_envir	*copy_envir_list(t_envir *original)
{
	t_envir	*copy;
	t_envir	*node;
	t_envir	*prev;

	copy = NULL;
	node = NULL;
	prev = NULL;
	while (original)
	{
		node = ft_envnew();
		node->var_name = strdup(original->var_name);
		node->var_value = strdup(original->var_value);
		node->visible = original->visible;
		node->prev = prev;
		if (prev)
			prev->next = node;
		else
			copy = node;
		prev = node;
		original = original->next;
	}
	return (copy);
}

void	swap_nodes(t_envir *a, t_envir *b)
{
	char	*temp_name;
	char	*temp_value;

	temp_name = a->var_name;
	temp_value = a->var_value;
	a->var_name = b->var_name;
	a->var_value = b->var_value;
	b->var_name = temp_name;
	b->var_value = temp_value;
}

void	sort_envir_list(t_envir *list)
{
	int		swapped;
	t_envir	*ptr1;
	t_envir	*lptr;

	if (list == NULL)
		return ;
	swapped = 1;
	ptr1 = NULL;
	lptr = NULL;
	while (swapped)
	{
		swapped = 0;
		ptr1 = list;
		while (ptr1->next != lptr)
		{
			if (strcmp(ptr1->var_name, ptr1->next->var_name) > 0)
			{
				swap_nodes(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}
}

t_envir	*copy_and_sort_envir_list(t_envir *original)
{
	t_envir	*copy;

	copy = copy_envir_list(original);
	sort_envir_list(copy);
	return (copy);
}
