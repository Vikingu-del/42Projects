/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:15:25 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/26 16:00:14 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, unsigned long len)
{
	unsigned char	*ptrsrc;
	unsigned char	*ptrdst;

	ptrsrc = (unsigned char *)src;
	ptrdst = (unsigned char *)dst;
	if (ptrsrc == ptrdst)
		return (dst);
	else if (ptrsrc < ptrdst)
	{
		ptrsrc += len;
		ptrdst += len;
		while (len--)
			*--ptrdst = *--ptrsrc;
	}
	else
		while (len--)
			*ptrdst++ = *ptrsrc++;
	return (dst);
}
