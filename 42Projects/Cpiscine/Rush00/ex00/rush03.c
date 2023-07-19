/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:03:17 by coder             #+#    #+#             */
/*   Updated: 2023/01/29 03:27:39 by coder            ###   ########.fr       */
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
			if ((j == 1 && (i == 1 || i == y)))
				ft_putchar('A');
			else if (j == x && (i == 1 || i == y))
				ft_putchar('C');
			else if ((i == 1 || i == y) || ((j == 1 || j == x) && (i != y)))
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
