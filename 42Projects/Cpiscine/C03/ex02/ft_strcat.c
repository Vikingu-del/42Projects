/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:29:37 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/08 13:47:41 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	src_index;
	int	dest_index;

	src_index = 0;
	dest_index = 0;
	while (dest[dest_index] != '\0')
	{
		dest_index++;
	}
	while (src[src_index] != '\0')
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
// 	printf("%s", ft_strcat(dstring, sstring));
// 	return (0);
// }
