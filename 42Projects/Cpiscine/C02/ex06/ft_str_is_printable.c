/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:25:05 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/07 15:26:54 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if ((32 <= str[index]) && (str[index] < 127))
			index++;
		else
			return (0);
	}
	return (1);
}

// int main(void)
// {
// 	char test[] = " sp!\"#$\%&'()*+,-./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ
// 	[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
// 	printf("With all the ascii char: %d", ft_str_is_printable(&test[0]));
// 	char test1[] = "AStrikdsÖ";
// 	printf("\nWith other char: %d", ft_str_is_printable(&test1[0]));
// 	char test2[] = "";
// 	printf("\nWith empty string: %d", ft_str_is_printable(&test2[0]));
// 	printf("\n");
// 	return (0);
// }