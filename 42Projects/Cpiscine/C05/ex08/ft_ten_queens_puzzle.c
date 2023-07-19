/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:10:33 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/12 23:46:59 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	g_a[10];
int	g_count = 0;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	myabs(int n)
{
	if (n < 0)
		n = n * (-1);
	return (n);
}

int	ft_check_queen_pos(int pos)
{
	int	i;

	i = 1;
	while (i < pos)
	{
		if ((g_a[i] == g_a[pos])
			|| ((myabs (g_a[i] - g_a[pos]) == myabs (i - pos))))
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_queen_pos(void)
{
	int	i;
	int	j;

	i = 1;
	while (i <= 10)
	{
		j = 0;
		while (j < 10)
		{
			if (g_a[i] == j + 1)
				ft_putchar(j + '0');
			j++;
		}
		i++;
	}
	g_count = g_count + 1;
	ft_putchar('\n');
}

int	ft_ten_queens_puzzle(void)
{
	int	q;

	q = 1;
	g_a[q] = 0;
	while (q != 0)
	{
		g_a[q] = g_a[q] + 1;
		while ((g_a[q] <= 10) && !ft_check_queen_pos(q))
			g_a[q]++;
		if (g_a[q] <= 10)
		{
			if (q == 10)
				ft_print_queen_pos();
			else
			{
				q++;
				g_a[q] = 0;
			}
		}
		else
			q--;
	}
	return (g_count);
}

#include <stdio.h>

int ft_ten_queens_puzzle(void);

int	main(void)
{
	printf("\n%d solutions\n", ft_ten_queens_puzzle());
}