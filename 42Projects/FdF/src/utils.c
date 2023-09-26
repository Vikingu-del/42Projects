/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:12:27 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 23:12:28 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/miniliblx/minilibx_macos/mlx.h"
#include "../lib/ft_printf/inc/ft_printf.h"
#include "../inc/defines.h"

void	print_nbr(t_meta *meta, int x, int y, int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	mlx_string_put(meta->vars.mlx, meta->vars.win, x, y, NUMBER_COLOR, str);
	free (str);
}

void	print_str(t_meta *meta, int x, int y, char *str)
{
	mlx_string_put(meta->vars.mlx, meta->vars.win, x, y, TEXT_COLOR, str);
}

void	dbl_free(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free (ptr);
}

int	ft_round(double num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= .5)
		rounded++;
	return (rounded);
}

void	matrix_init(float (*matrix)[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}