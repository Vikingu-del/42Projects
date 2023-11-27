/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:07:14 by eseferi           #+#    #+#             */
/*   Updated: 2023/08/06 20:40:17 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new_var;

	new_var = malloc(sizeof(t_list));
	if (!new_var)
		return (NULL);
	new_var->nr = value;
	new_var->next = NULL;
	return (new_var);
}
