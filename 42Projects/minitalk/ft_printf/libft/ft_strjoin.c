/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:56:43 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/26 16:36:41 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	lentot;
	char	*s3;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	lentot = len1 + len2 + 1;
	s3 = (char *)ft_calloc(lentot, sizeof(char));
	if (!s3)
		return (NULL);
	ft_memcpy(s3, s1, len1);
	ft_strlcat(&s3[len1], s2, lentot);
	return (s3);
}
