/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:07:14 by eseferi           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/06 20:40:17 by eseferi          ###   ########.fr       */
=======
/*   Updated: 2023/05/31 11:22:02 by eseferi          ###   ########.fr       */
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
t_list	*ft_lstnew(int value)
=======
t_list	*ft_lstnew(void *content)
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2
{
	t_list	*new_var;

	new_var = malloc(sizeof(t_list));
	if (!new_var)
		return (NULL);
<<<<<<< HEAD
	new_var->nr = value;
=======
	new_var->content = content;
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2
	new_var->next = NULL;
	return (new_var);
}
