/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:55:32 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/27 15:41:08 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}
/*
	if string contains only a \0, then return the size of
	the string, which is 1
*/

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *str_static, char *buffer)
{
	unsigned int	len;
	char			*str;

	if (!str_static)
	{
		str_static = (char *)malloc(1 * sizeof(char));
		str_static[0] = '\0';
	}
	if (!str_static || !buffer)
		return (0);
	len = ft_strlen(str_static) + ft_strlen(buffer);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	ft_strcpy(str, str_static);
	len = ft_strlen(str_static);
	ft_strcpy(&str[len], buffer);
	return (free(str_static), str);
}
/*
	- a regular strjoin with some additional extras
		- if str_static empty or has an error, allocate memory of size 1 and put in 
		that string \0 inside, str_static is always the static string, for the 
		beginning it's empty
		- free (str_static) because we dont need it anymore, ft_strjoin returns the 
		string, that will be the new static string, buffer will be freed in
		ft_read_buffer
	- free(str_static) is str in ft_read_buffer that should be freed
*/
