/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:11:44 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/11 23:56:06 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 == *str2 && str1)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int	main(int argc, char **argv)
{
	int		i1;
	int		i2;
	char	*box;

	i2 = argc;
	i1 = 1;
	while (++i1 <= argc)
	{
		i2 = 1;
		while (++i2 <= argc -1)
		{
			if (ft_strcmp(argv[i2], argv[i2 - 1]) < 0)
			{
				box = argv[i2];
				argv[i2] = argv[i2 - 1];
				argv[i2 - 1] = box;
			}
		}
	}
	i1 = 0;
	while (++i1 < argc)
		ft_putstr(argv[i1]);
	return (0);
}
