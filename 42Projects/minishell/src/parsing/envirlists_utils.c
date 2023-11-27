/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envirlists_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:58:22 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/23 18:17:21 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_envadd_back(t_envir **lst, t_envir *new)
{
	t_envir	*tmp;

	if (!*lst)
		*lst = new;
	else
	{
		tmp = ft_envlast(*lst);
		if (tmp)
		{
			tmp->next = new;
			new->prev = tmp;
		}
		else
			ft_envadd_front(lst, new);
	}
}

void	ft_envadd_front(t_envir **lst, t_envir *new)
{
	new->next = *lst;
	if (*lst != NULL)
		(*lst)->prev = new;
	*lst = new;
}

void	ft_envclear(t_envir **lst)
{
	t_envir	*next;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_envdelone(*lst, free);
		*lst = next;
	}
}

void	ft_envdelone(t_envir *lst, void (*del))
{
	if (!lst || !del)
		return ;
	if (lst->var_name)
		free(lst->var_name);
	if (lst->var_value)
		free(lst->var_value);
	free(lst);
}
