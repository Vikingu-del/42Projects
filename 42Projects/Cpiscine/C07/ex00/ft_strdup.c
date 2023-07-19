/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:07:14 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/16 12:41:11 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(char *str)
{
	int		i;
	char	*copy;

	i = 0;
	while (str[i])
		i++;
	copy = (char *)malloc(sizeof(char) * (i + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// int	main(void)
// {
// 	int	i;
// 	char	str[] = "Erik";
// 	char	*copy;
// 	copy = ft_strdup(str);
// 	i = 0;
// 	while (copy[i])
// 	{
// 		write (1, &copy[i], 1);
// 		i++;
// 	}
// 	free(copy);
// }