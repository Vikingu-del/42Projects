/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:47:48 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/31 11:50:41 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count ++;
		lst = lst -> next;
	}
	return (count);
}

// #include <stdio.h>
// int	main(void)
// {
// 	// a linked list with three nodes
// 	t_list	*node1 = ft_lstnew("Node 1");
// 	t_list	*node2 = ft_listnew("Node 2");
// 	t_list	*node3 = ft_listnew("Node 3");	
// 	// setting the next pointers
// 	node1 -> next = node2;
// 	node2 -> next = node3;
// 	node3 -> next = NULL;	
// 	// calculating the size of the linked list
// 	int	size = ft_lstsize(node1);
// 	// printing the size
// 	printf("Size of the linked list is %d\n", size);	
// 	// Freeing the memory
// 	ft_lstclear(&node1, free);
// 	return (0);
// }