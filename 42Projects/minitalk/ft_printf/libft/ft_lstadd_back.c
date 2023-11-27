/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 04:18:46 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/01 16:30:02 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!lst || !new)
		return ;
	if (temp != NULL)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
	else
		*lst = new;
}

// #include <stdio.h>
// #include <stdlib.h>

// void printList(t_list *lst)
// {
//     while (lst != NULL)
//     {
//         printf("%s ", (char *)lst->content);
//         lst = lst->next;
//     }
//     printf("\n");
// }

// int main()
// {
//     t_list *lst = NULL;
//     t_list *new1 = ft_lstnew("one");
//     t_list *new2 = ft_lstnew("two");
//     t_list *new3 = ft_lstnew("three");

//     ft_lstadd_back(&lst, new1);
//     ft_lstadd_back(&lst, new2);
//     ft_lstadd_back(&lst, new3);

//     printf("List: ");
//     printList(lst);

//     // Freeing the list
//     ft_lstclear(&lst, free);

//     return 0;
// }