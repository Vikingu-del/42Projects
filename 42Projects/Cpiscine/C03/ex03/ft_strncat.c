/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:49:59 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/08 19:23:43 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	src_index;
	unsigned int	dest_index;

	src_index = 0;
	dest_index = 0;
	while (dest[dest_index] != '\0')
	{
		dest_index++;
	}
	while ((src[src_index] != '\0') && (src_index < nb))
	{
		dest[dest_index] = src[src_index];
		src_index++;
		dest_index++;
	}
	dest[dest_index] = '\0';
	return (dest);
}

// #include <stdio.h>
// int main(void)
// {
// 	char sstring[] = "Hello";
// 	char dstring[] = "world";
// 	printf("%s", ft_strncat(dstring, sstring, 4));
// 	return (0);
// }