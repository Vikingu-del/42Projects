/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:12:27 by eseferi           #+#    #+#             */
/*   Updated: 2023/10/05 13:45:32 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx/mlx.h"
#include "../lib/ft_printf/include/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include "../inc/defines.h"
#include "../inc/errors.h"


void	print_nbr(t_data *data, int x, int y, int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	mlx_string_put(data->vars.mlx, data->vars.win, x, y, NUMBER_COLOR, str);
	free (str);
}

void	print_str(t_data *data, int x, int y, char *str)
{
	mlx_string_put(data->vars.mlx, data->vars.win, x, y, TEXT_COLOR, str);
}

void	free_2darray(char **ptr)
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

// setting all the values of the matrix to 0
void	init_matrix(float matrix[][3])
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

int	modified_atoi(const char *str)
{
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	while (ft_isdigit(*str))
		value = value * 10 + (*str++ - '0');
	if (*str != ' ' && *str != ',' && *str != '\0' && *str != '\n')
	{
		ft_putstr_fd("\n\n", 2);
		exit_with_error(ERR_MAP);
	}
	return (sign * value);
}