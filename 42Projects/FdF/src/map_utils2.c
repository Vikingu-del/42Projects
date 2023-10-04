/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:11:34 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/27 01:39:36 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../lib/libft/include/libft.h"
#include "../inc/utils.h"
#include "../inc/draw_utils.h"

/*
*	Acording the z value of the point and de max and min values of the map
*	this function set the color needed of the point received.
*	All the colors are defined in fdf.h 
*/

void	load_color(int max, int min, t_point *point, t_palette	palette)
{
	point->color = DEFAULT_COLOR;
	if (point->hex_color > 0)
	{
		point->color = point->hex_color;
		return ;
	}
	if (point->coordinates[Z] == max)
		point->color = palette.topcolor;
	else if (point->coordinates[Z] == 0)
		point->color = palette.groundcolor;
	else if (point->coordinates[Z] == min && min != 0)
		point->color = palette.bottomcolor;
	else if (point->coordinates[Z] > 0)
		point->color = gradient(palette.groundcolor, palette.topcolor, \
		max, point->coordinates[Z]);
	else
		point->color = gradient(palette.bottomcolor, palette.groundcolor, \
		-min, - (min - point->coordinates[Z]));
	point->paint = 1;
}

int	has_hexcolors(char *str_point)
{
	char	**color;
	int		color_nr;

	if (ft_strchr(str_point, ',') != 0)
	{
		color = ft_split(str_point, ',');
		color_nr = ft_atoi_base(color[1] + 2, "0123456789ABCDEF");
		free_2darray(color);
		return (color_nr);
	}
	else
		return (0);
}

int	point_is_valid(char *str_point)
{
	int	true_false;

	true_false = false;
	if (*str_point == '-' || *str_point == '+' || ft_isdigit(*str_point))
		true_false++;
	str_point++;
	while (ft_isdigit(*str_point))
	{
		str_point++;
		true_false++;
	}
	if (true_false == false)
		return (false);
	else
		return (true);
}

static void	init_map_colors(t_map *map)
{
	map->palette.backcolor = BACK_COLOR;
	map->palette.menucolor = MENU_COLOR;
	map->palette.bottomcolor = BOTTOM_COLOR;
	map->palette.groundcolor = GROUND_COLOR;
	map->palette.topcolor = TOP_COLOR;
}

void	init_map(t_map *map, int clean_state)
{
	if (clean_state)
	{
		map->len = 0;
		map->limits.coordinates[X] = 0;
		map->limits.coordinates[Y] = 0;
		map->limits.coordinates[Z] = 0;
		map->zmin = 0;
	}
	map->z_scale = 1;
	map->scale = 1;
	map->curve_range = 0;
	map->b_lines = 1;
	map->b_dots = 0;
	map->b_pluslines = 0;
	map->sphere = 0;
	map->b_stars = 0;
	map->shadows = 1;
	map->source.coordinates[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.coordinates[Y] = WINY / 2;
	map->source.coordinates[Z] = 0;
	map->ang[X] = 0;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
	init_map_colors(map);
}