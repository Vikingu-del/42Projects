/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:11:10 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/27 01:44:35 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/map.h"
#include "../inc/draw_utils.h"
#include "../lib/ft_printf/include/ft_printf.h"

void	wire_line(t_point *point, t_data *data, int density, int line);

/* 
*	This function iterate all the points of the wire array and draw a line between:
*	--> wire[i] and wire [i + density]
*	--> wire[i] and wire [i + x_max * density]
*/

void	wired(t_data *data, t_point *wire)
{
	int	i;
	int	density;

	density = 8 / data->map.scale;
	if (density == 0)
		density = 1;
	i = 0;
	while (i < data->map.len)
	{
		wire_line (&wire[i], data, density, i / data->map.limits.coordinates[X]);
		i = i + data->map.limits.coordinates[X] * density;
	}
}

void	wire_line(t_point *point, t_data *data, int density, int line)
{
	int	i;
	int	x_end;
	int	y_end;

	i = 0;
	while (i < (int)data->map.limits.coordinates[X])
	{
		x_end = i + density;
		if (x_end >= (int)data->map.limits.coordinates[X])
			x_end = (int)data->map.limits.coordinates[X] - 1;
		y_end = i + (int)data->map.limits.coordinates[X] * density;
		if (point[i].paint)
		{
			draw_line(data, point[i], point[x_end]);
			if (line + density < (int)data->map.limits.coordinates[Y])
				draw_line(data, point[i], point[y_end]);
		}
		i += density;
	}
}

/* 
*	Colorize all the points of the map
*/

void	apply_color_scheme(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		load_color((int)map->limits.coordinates[Z], map->zmin, \
		&map->points[i], map->palette);
		i++;
	}
}

/* 
*	This function iterate all the points of the array and draw a dot for each point
*/

void	doted(t_data *data, t_point *proyect)
{
	int	i;

	i = 0;
	while (i < data->map.len)
	{
		if (proyect[i].paint)
			draw_dot(data, proyect[i], 1);
		i++;
	}
}

/* 
*	This function iterate len points of the array and 
*	divide de z axis by divisor
*/

void	z_division(t_point *proyect, float divisor, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		proyect[i].coordinates[Z] = proyect[i].coordinates[Z] / divisor;
		i++;
	}
}