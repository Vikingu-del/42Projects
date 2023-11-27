/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_double_free.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:03:07 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 09:52:34 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_double_free(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !*s1)
	{
		str = ft_strdup(s2);
		free((void *)s2);
		return (str);
	}
	if (!s2 || !*s2)
	{
		str = ft_strdup(s1);
		free((void *)s1);
		return (str);
	}
	str = (char *)ft_calloc(1, sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	free((void *)s1);
	ft_strcat(str, s2);
	free((void *)s2);
	return (str);
}
