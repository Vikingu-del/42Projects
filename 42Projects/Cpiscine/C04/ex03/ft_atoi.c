/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 20:34:30 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/14 21:42:52 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	ind;
	int	nr;
	int	neg_nr;

	ind = 0;
	nr = 0;
	neg_nr = 0;
	while ((str[ind] >= 9 && str[ind] <= 13) || str[ind] == ' ')
		ind++;
	while (str[ind] == '-' || str[ind] == '+')
		if (str[ind++] == '-')
			neg_nr++;
	while (str[ind] >= '0' && str[ind] <= '9')
		nr = nr * 10 + (str[ind++] - '0');
	if (neg_nr % 2 == 1)
		return (nr * -1);
	return (nr);
}

// #include <stdio.h>
// int main(void)
// {
// 	char str[] = " ---+--+1234ab567";
// 	printf("%d\n", ft_atoi(str));
// 	return (0);
// }