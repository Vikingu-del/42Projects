/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:24:04 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/07 15:26:13 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if ('a' <= str[index] && str[index] <= 'z')
			index++;
		else if ('A' <= str[index] && str[index] <= 'Z')
			index++;
		else
			return (0);
	}
	return (1);
}

// int main(void)
// {
// 	char test[] = "erik12";
// 	printf("With numbers: %d", ft_str_is_alpha(&test[0]));
// 	char test1[] = "erik";
// 	printf("\nWith only alfabetical letters: %d", ft_str_is_alpha(&test1[0]));
// 	char test2[] = "";
// 	printf("\nWith an empty array: %d", ft_str_is_alpha(&test2[0]));
// 	printf("\n");
// }