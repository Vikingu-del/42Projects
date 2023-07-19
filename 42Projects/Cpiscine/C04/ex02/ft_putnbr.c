/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:36:18 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/14 21:42:47 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	nb_long;

	nb_long = nb;
	if (nb_long < 0)
	{
		nb_long = -nb_long;
		ft_putchar('-');
	}
	if (nb_long > 9)
	{
		ft_putnbr(nb_long / 10);
	}
	ft_putchar(nb_long % 10 + 48);
}

// #include <string.h>
// #include <stdio.h>
// #include <unistd.h>
// #include <limits.h>

// void	ft_putnbr(int nb);

// int main() {
// 	ft_putnbr(0);
// 	write(1, "\n", 1);
// 	ft_putnbr(10);
// 	write(1, "\n", 1);
// 	ft_putnbr(-10);
// 	write(1, "\n", 1);
// 	ft_putnbr(INT_MAX);
// 	write(1, "\n", 1);
// 	ft_putnbr(INT_MIN);
// 	write(1, "\n", 1);
// }