/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:45:14 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/04 22:16:10 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(const char *s, int c)
{
	if (!s || !c)
		return (0);
	while (*s && *s != (char)c)
	{
		if (*s == (char)c || !c)
			return (1);
		s++;
	}
	return (0);
}
