/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 02:11:42 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/26 16:39:18 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	leng;
	char	*dup;

	leng = ft_strlen(s1) + 1;
	dup = (char *)ft_calloc(leng, sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, leng);
	return (dup);
}
