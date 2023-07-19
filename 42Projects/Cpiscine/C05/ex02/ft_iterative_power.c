/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:09:06 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/12 23:22:45 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	basenum;

	basenum = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (--power > 0)
		nb *= basenum;
	return (nb);
}

#include <stdio.h>

int ft_iterative_power(int nb, int power);

int	main(void)
{
	printf("0:%d\n", ft_iterative_power(1, -10));
	printf("0:%d\n", ft_iterative_power(1, -1));
	printf("1:%d\n", ft_iterative_power(10, 0));
	printf("10:%d\n", ft_iterative_power(10, 1));
	printf("100:%d\n", ft_iterative_power(10, 2));
	printf("216:%d\n", ft_iterative_power(6, 3));
}