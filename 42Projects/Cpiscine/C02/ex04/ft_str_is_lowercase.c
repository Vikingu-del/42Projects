/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:24:36 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/07 15:26:21 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if ('a' <= str[index] && 'z' >= str[index])
			index++;
		else
			return (0);
	}
	return (1);
}

// int main(void)
// {
// 	char test[] = "erik";
// 	printf("With lowercase: %d", ft_str_is_lowercase(&test[0]));
// 	char test1[] = "Erik";
// 	printf("\nWith also other characters: %d", ft_str_is_lowercase(&test1[0]));
// 	char test2[] = "";
// 	printf("\nWith an empty array: %d", ft_str_is_lowercase(&test2[0]));
// 	printf("\n");
// }