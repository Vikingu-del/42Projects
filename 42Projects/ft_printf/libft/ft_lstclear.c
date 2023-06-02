/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:57:25 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/31 18:04:21 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i_lst;
	t_list	*temp;

	i_lst = *lst;
	if (!*lst || !del)
		return ;
	while (i_lst)
	{
		temp = i_lst -> next;
		del(i_lst -> content);
		free(i_lst);
		i_lst = temp;
	}
	*lst = NULL;
}
