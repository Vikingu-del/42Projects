/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 00:03:01 by coder             #+#    #+#             */
/*   Updated: 2023/01/29 03:23:37 by coder            ###   ########.fr       */
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
			if ((i == 1 && (j == 1 || j == x)))
				ft_putchar('A');
			else if (i == y && (j == 1 || j == x))
				ft_putchar('C');
			else if ((j == 1 || j == x) || ((i == 1 || i == y) && (j != x)))
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}	
		i++;
		ft_putchar('\n');
	}
}
