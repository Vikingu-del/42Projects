/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:37:12 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/14 21:42:57 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	double_char(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (*(base + i))
	{
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb, int bval, char *base)
{
	long	lnb;

	lnb = nb;
	if (lnb < 0)
	{
		lnb = -lnb;
		ft_putchar('-');
	}
	if (lnb >= bval)
	{
		ft_putnbr(lnb / bval, bval, base);
	}
	ft_putchar(base[lnb % bval]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	bval;

	bval = 0;
	while (base[bval])
	{
		if (base[bval] == '+'
			|| base[bval] == '-'
			|| base[bval] == ' '
			|| (base[bval] >= 9 && base[bval] <= 13))
			return ;
		bval++;
	}
	if (bval < 2)
		return ;
	if (double_char(base))
		return ;
	ft_putnbr(nbr, bval, base);
}

// #include <unistd.h>
// #include <limits.h>

// void	ft_putnbr_base(int nbr, char *base);

// int		main(void)
// {
// 	write(1, "42:", 3);
// 	ft_putnbr_base(42, "0123456789");
// 	write(1, "\n2a:", 4);
// 	ft_putnbr_base(42, "0123456789abcdef");
// }