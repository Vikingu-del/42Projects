/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:48:30 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/01 16:20:20 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_new;
	t_list	*node_new;
	void	*cont;

	if (!lst || !f)
		return (NULL);
	list_new = NULL;
	while (lst)
	{
		cont = f(lst->content);
		node_new = ft_lstnew(cont);
		if (!node_new)
		{
			ft_lstclear(&list_new, del);
			del(cont);
			return (NULL);
		}
		ft_lstadd_back(&list_new, node_new);
		lst = lst->next;
	}
	return (list_new);
}
