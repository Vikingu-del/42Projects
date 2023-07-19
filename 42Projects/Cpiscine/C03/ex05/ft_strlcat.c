/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:18:11 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/12 20:21:43 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_in;
	unsigned int	dest_in;
	unsigned int	src_len;
	unsigned int	dest_len;

	src_in = 0;
	dest_in = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	dest_in = dest_len;
	if ((size == 0) || (size <= dest_len))
		return (src_len + size);
	while ((src[src_in] != '\0') && (src_in < size - dest_len -1))
	{
		dest[dest_in] = src[src_in];
		dest_in++;
		src_in++;
	}
	dest[dest_in] = '\0';
	return (dest_len + src_len);
}

// #include <stdio.h>
// int main(void)
// {
// 	char sstring[] = " world";
// 	char dstring[] = "Hello";
// 	printf("%d \n", ft_strlcat(dstring, sstring, 5));
// 	return (0);
// }