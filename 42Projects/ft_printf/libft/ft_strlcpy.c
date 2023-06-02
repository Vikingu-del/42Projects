/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 03:16:06 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/26 16:00:39 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	result;

	srclen = ft_strlen(src);
	result = srclen;
	if (dstsize > 0)
	{
		if (srclen >= dstsize)
			srclen = dstsize - 1;
		ft_memcpy(dst, src, srclen);
		dst[srclen] = '\0';
	}
	return (result);
}
