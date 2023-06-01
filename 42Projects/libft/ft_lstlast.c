/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 02:32:11 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/31 11:50:24 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	if (lst->next == NULL)
		return (lst);
	else
		return (ft_lstlast(lst->next));
}

// #include <stdio.h>

// int main(void)
// {
// 	// Creating a linked list
// 	t_list *node1 = ft_lstnew("Node 1");
// 	t_list *node2 = ft_lstnew("Node 2");
// 	t_list *node3 = ft_lstnew("Node 3");
// 	// Connecting the nodes
// 	node1->next = node2;
// 	node2->next = node3;
// 	// Get the last node
// 	t_list *lastNode = ft_lstlast(node1)	
// 	// Print the content of the last node
// 	if (lastNode != NULL)
// 		printf("Last node: %s\n", (char *)lastNode->content);
// 	else
// 		printf("List is empty.\n");
// 	// Free the memory
// 	ft_lstclear(&node1, free);	
// 	return (0);
// }
