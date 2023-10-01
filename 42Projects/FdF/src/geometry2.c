/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:09:05 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 23:09:12 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include <math.h>

void	spherize(t_map *map, t_point *points)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		points[i].coordinates[X] = (map->radius + points[i].coordinates[Z]) * \
		cos(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].coordinates[Y] = (map->radius + points[i].coordinates[Z]) * \
		sin(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].coordinates[Z] = (map->radius + points[i].coordinates[Z]) * \
		cos(points[i].polar[LAT]);
		i++;
	}
}

void	go_polar(t_map *map)
{
	int		i;
	float	steps_x;
	float	steps_y;

	steps_x = (M_PI * 2) / (map->limits.coordinates[X] - 1);
	steps_y = M_PI / (map->limits.coordinates[Y]);
	map->radius = map->limits.coordinates[X] / (M_PI * 2);
	i = 0;
	while (i < map->len)
	{
		map->points[i].polar[LONG] = -(map->points[i].coordinates[X]) * steps_x;
		if (map->points[i].coordinates[Y] > 0)
			map->points[i].polar[LAT] = ((map->points[i].coordinates[Y]) + \
			(map->limits.coordinates[Y] / 2)) * steps_y - 0.5 * steps_y;
		else
			map->points[i].polar[LAT] = (map->points[i].coordinates[Y] + \
			(map->limits.coordinates[Y] / 2) - 1) * steps_y + 0.5 * steps_y;
		i++;
	}
}