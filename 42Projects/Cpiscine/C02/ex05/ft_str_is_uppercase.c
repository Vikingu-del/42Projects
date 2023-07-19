/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:24:48 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/07 15:26:25 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if ('A' <= str[index] && 'Z' >= str[index])
			index++;
		else
			return (0);
	}
	return (1);
}

// int main(void)
// {
// char test[] = "ERIK";
// printf("With uppercase: %d", ft_str_is_uppercase(&test[0]));
// char test1[] = "Erik";
// printf("\nWith also other characters: %d", ft_str_is_uppercase(&test1[0]));
// char test2[] = "";
// printf("\nWith an empty array: %d", ft_str_is_uppercase(&test2[0]));
// printf("\n");
// }