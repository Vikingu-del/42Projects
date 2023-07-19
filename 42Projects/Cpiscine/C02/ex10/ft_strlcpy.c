/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:26:12 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/07 15:27:15 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	ssize;

	index = 0;
	ssize = 0;
	while (src[ssize])
		ssize++;
	if (size < 1)
		return (ssize);
	while (src[index] && index < size - 1)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (ssize);
}

// ssize size of the source
// int	main(void)
// {
// 	char name[] = "Albania";
// 	char country[2]; 
// 	unsigned int size;
// 	size = 7; //size of the destionation
// 	printf("%d", ft_strlcpy(&country[0], &name[0], size));
// 	printf("\n%s", country);
// 	return (0);
// }