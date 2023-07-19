/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:28:43 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/01 18:21:26 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		count = count + 1;
	}
	return (count);
}

/*int main(void)
{
	int num;
	num = 0;
	printf("Start value of num = %d\n", num);
	num = ft_strlen("Erik Seferi");
	printf("After value of num = %d\n", num);
	return (0);
}
*/