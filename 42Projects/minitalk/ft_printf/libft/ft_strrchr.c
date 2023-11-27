/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:55:25 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/26 16:00:55 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occurrence = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (last_occurrence);
}
