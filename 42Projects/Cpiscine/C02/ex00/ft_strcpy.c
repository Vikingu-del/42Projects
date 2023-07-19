/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:23:12 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/07 15:26:04 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

// int	counter_size(char *src)
// {
// 	int	index;
// 	index = 0;

// 	while (src[index])
// 	{
// 		index++;
// 	}
// 	return (index);
// }

// int	main(void)
// {
// 	char name[] = "Albania";
// 	char country[counter_size(&name[0])];
// 	ft_strcpy(&country[0], &name[0]);
// 	printf("%s, %s", country, name);
// 	return (0);
// }
