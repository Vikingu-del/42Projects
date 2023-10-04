/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:08:48 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 23:08:50 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <math.h>

/*
*	Iterates all the points and add the "move" traslation
*/

void	traslate(t_point *points, t_point move, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].coordinates[X] = points[i].coordinates[X] + move.coordinates[X];
		points[i].coordinates[Y] = points[i].coordinates[Y] + move.coordinates[Y];
		points[i].coordinates[Z] = points[i].coordinates[Z] + move.coordinates[Z];
		i++;
	}
}

/*
*	Iterates all the points and multiply by scale
*/

void	scale(t_point *points, int scale, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].coordinates[X] = points[i].coordinates[X] * scale;
		points[i].coordinates[Y] = points[i].coordinates[Y] * scale;
		points[i].coordinates[Z] = points[i].coordinates[Z] * scale;
		i++;
	}
}

/*
*	Set the values to draw ISOMETRIC view
*/

void	isometric(t_map *map)
{
	map->sphere = 0;
	map->ang[X] = 30;
	map->ang[Y] = 330;
	map->ang[Z] = 30;
	map->curve_range = 0;
	map->source.coordinates[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.coordinates[Y] = WINY / 2;
}

/*
*	Set the values to draw PARALLEL view
*/

void	parallel(t_map *map)
{
	map->sphere = 0;
	map->ang[X] = 90;
	map->ang[Y] = 0;
	map->ang[Z] = 0;
	map->curve_range = 0;
	map->source.coordinates[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.coordinates[Y] = WINY / 2;
}

/*
*	Iterate all the point to move the z value depending the range 
*	and the x and y position
*/

void	curving(t_point *points, int len, float curve_range)
{
	int		i;
	float	x_squared;
	float	y_squared;

	x_squared = 0;
	y_squared = 0;
	i = 0;
	while (i < len)
	{
		x_squared = pow(points[i].coordinates[X], 2);
		y_squared = pow(points[i].coordinates[Y], 2);
		points[i].coordinates[Z] -= curve_range * (x_squared + y_squared);
		i++;
	}
}