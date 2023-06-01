/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:37:48 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/26 16:00:09 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;

	ptrdst = (unsigned char *)dst;
	ptrsrc = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (len-- > 0)
		*(ptrdst + len) = *(ptrsrc + len);
	return (dst);
}
