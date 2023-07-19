/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debizhan <debizhan@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:34:17 by debizhan          #+#    #+#             */
/*   Updated: 2023/02/05 20:01:26 by debizhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_case(int tab[4][4], int pos, int entry[16]);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
int		check(int ac, char **av);
int		*get_numbers(char *str);
void	ft_putstr(char *str);

int	check_double(int tab[4][4], int pos, int num)
{
	int	i;

	i = -1;
	while (++i < pos / 4)
		if (tab[i][pos % 4] == num)
			return (1);
	i = -1;
	while (++i < pos % 4)
		if (tab[pos / 4][i] == num)
			return (1);
	return (0);
}

int	solve(int tab[4][4], int entry[16], int pos)
{
	int	size;

	if (pos == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (check_double(tab, pos, size) == 0)
		{
			tab[pos / 4][pos % 4] = size;
			if (check_case(tab, pos, entry) == 0)
			{
				if (solve(tab, entry, pos + 1) == 1)
					return (1);
			}
			else
				tab[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}

void	display_solution(int tab[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnbr(tab[i][j]);
			if (j < 3)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	main(int ac, char **av)
{
	int	tab[4][4];
	int	i;
	int	j;
	int	*entry;

	i = -1;
	j = 0;
	while (++i < 4)
		while (j < 4)
			tab[i][j++] = 0;
	if (check(ac, av) == 1)
		return (0);
	entry = get_numbers(av[1]);
	if (solve(tab, entry, 0) == 1)
		display_solution(tab);
	else
		ft_putstr("Did not find any solutions\n");
	return (0);
}
