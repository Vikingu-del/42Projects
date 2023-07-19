/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:48:09 by coder             #+#    #+#             */
/*   Updated: 2023/01/31 15:11:33 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int		i;
	int		j;

	if (x < 1 || y < 1)
		return ;
	i = 1;
	while (i <= y)
	{
		j = 1;
		while (j <= x)
		{
			if ((i == 1 || i == y) && (j == 1 || j =__DBL_HAS_QUIET_NAN__= x))
				ft_putchar('o');
			else if ((i == 1 || i == y) && j != x)
				ft_putchar('-');
			else if ((i != y && j == 1) || j == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
