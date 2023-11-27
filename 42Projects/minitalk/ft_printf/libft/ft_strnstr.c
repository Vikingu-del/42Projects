/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:23:43 by eseferi           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/11 00:15:29 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
=======
/*   Updated: 2023/05/23 19:08:55 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	haylen;

	haylen = ft_strlen(haystack);
	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)(&haystack[0]));
	if (haylen < len)
		len = haylen;
	while (i < len && haystack[i] != '\0')
	{
		while (haystack[i + j] == needle[j] && (i + j) < len)
<<<<<<< HEAD
		{
=======
		{	
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2
			j++;
		}
		i++;
		if (needle[j] == '\0')
			return ((char *)(&haystack[i - 1]));
		else
			j = 0;
	}
	return (NULL);
}
