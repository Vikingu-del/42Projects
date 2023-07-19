/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:25:36 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/07 15:26:58 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	index;
	int	asc_val_low;
	int	asc_val_up;

	asc_val_low = 97;
	asc_val_up = 65;
	index = 0;
	while (str[index])
	{
		if (('a' <= str[index]) && ('z' >= str[index]))
		{
			while ((asc_val_low <= 122) && (asc_val_up <= 90))
			{
				if (str[index] == asc_val_low)
					str[index] = asc_val_up;
				asc_val_low++;
				asc_val_up++;
			}	
		}
		index++;
		asc_val_low = 97;
		asc_val_up = 65;
	}
	return (str);
}

// int main(void)
// {
// char test[] = "albania";
// printf("With uppercase: %s", ft_strupcase(&test[0]));
// return (0);
// }