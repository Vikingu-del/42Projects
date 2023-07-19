/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:24:20 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/07 15:26:17 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if ('0' <= str[index] && str[index] <= '9')
			index++;
		else
			return (0);
	}
	return (1);
}

// int main(void)
// {
// 	char test[] = "0123456789";
// 	printf("With numbers: %d", ft_str_is_numeric(&test[0]));
// 	char test1[] = "0123456E";
// 	printf("\nWith also other characters: %d", ft_str_is_numeric(&test1[0]));
// 	char test2[] = "";
// 	printf("\nWith an empty array: %d", ft_str_is_numeric(&test2[0]));
// 	printf("\n");
// }