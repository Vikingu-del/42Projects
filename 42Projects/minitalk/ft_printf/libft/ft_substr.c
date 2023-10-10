/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:31:01 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/26 16:40:09 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	lenofs;
	char	*substring;

	lenofs = ft_strlen(s);
	if (start >= lenofs)
		return (ft_calloc(1, sizeof(char)));
	if (len > lenofs - start)
		len = lenofs - start;
	substring = (char *)ft_calloc((len + 1), sizeof(char));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, &s[start], len + 1);
	substring[len] = '\0';
	return (substring);
}
