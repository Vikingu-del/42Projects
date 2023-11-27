#include "../minilibx/mlx.h"
#include "../inc/defines.h"
#include "../inc/map.h"
#include "../inc/keycodes.h"
#include "../inc/geometry.h"
#include "../inc/control_utils.h"
#include "../inc/map_utils.h"

void	spherize(t_map *map, t_point *points)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		points[i].axis[X] = (map->radius + points[i].axis[Z]) * \
		cos(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].axis[Y] = (map->radius + points[i].axis[Z]) * \
		sin(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].axis[Z] = (map->radius + points[i].axis[Z]) * \
		cos(points[i].polar[LAT]);
		i++;
	}
}

void	go_polar(t_map *map)
{
	int		i;
	float	steps_x;
	float	steps_y;

	steps_x = (M_PI * 2) / (map->limits.axis[X] - 1);
	steps_y = M_PI / (map->limits.axis[Y]);
	map->radius = map->limits.axis[X] / (M_PI * 2);
	i = 0;
	while (i < map->len)
	{
		map->points[i].polar[LONG] = -(map->points[i].axis[X]) * steps_x;
		if (map->points[i].axis[Y] > 0)
			map->points[i].polar[LAT] = ((map->points[i].axis[Y]) + \
			(map->limits.axis[Y] / 2)) * steps_y - 0.5 * steps_y;
		else
			map->points[i].polar[LAT] = (map->points[i].axis[Y] + \
			(map->limits.axis[Y] / 2) - 1) * steps_y + 0.5 * steps_y;
		i++;
	}
}
