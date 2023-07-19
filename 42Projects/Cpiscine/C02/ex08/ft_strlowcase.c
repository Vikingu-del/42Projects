/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:25:49 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/07 15:27:03 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	index;
	int	asc_val_low;
	int	asc_val_up;

	asc_val_low = 97;
	asc_val_up = 65;
	index = 0;
	while (str[index])
	{
		if (('A' <= str[index]) && ('Z' >= str[index]))
		{
			while ((asc_val_low <= 122) && (asc_val_up <= 90))
			{
				if (str[index] == asc_val_up)
					str[index] = asc_val_low;
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
// char test[] = "ALBANIA";
// printf("With lowercase: %s", ft_strlowcase(&test[0]));
// return (0);
// }