/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:10:18 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/27 01:36:47 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx/mlx.h"
#include "../inc/defines.h"
#include "../inc/map.h"
#include "../inc/matrix.h"
#include "../inc/geometry.h"
#include "../inc/errors.h"
#include "../inc/map_utils.h"
#include "../inc/draw_utils.h"
#include "../inc/utils.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>

/* 
*	Call all the functions to modify the points in the space
*/

static void	parse_map(t_data *data, t_point *projections)
{
	z_scaling(projections, data->map.z_scale, data->map.len);
	curving(projections, data->map.len, data->map.curve_range);
	if (data->map.sphere)
		sphering(&data->map, projections);
	rotate_x(projections, projections, data->map.ang[X], data->map.len);
	rotate_y(projections, projections, data->map.ang[Y], data->map.len);
	rotate_z(projections, projections, data->map.ang[Z], data->map.len);
	if (data->map.sphere && data->map.shadows)
		apply_shadow (projections, data->map.len);
	orthographic_projection (projections, projections, data->map.len);
	scale (projections, data->map.scale, data->map.len);
	traslate(projections, data->map.source, data->map.len);
}

/* 
*	This function checks if any point is out of the limits of the screen
*/

static int	limits(t_point *points, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (points[i].coordinates[X] < (MENU_WIDTH + FIT_MARGIN) || \
			points[i].coordinates[X] > (WINX - FIT_MARGIN))
			return (1);
		if (points[i].coordinates[Y] < FIT_MARGIN || \
			points[i].coordinates[Y] > (WINY - FIT_MARGIN))
			return (1);
		i++;
	}
	return (0);
}

/* 
*	This function iterate n times until get the scale needed
*	to fit the screen.
*/

static void	go_fit(t_data *data, t_point *proyect)
{
	data->map.source.coordinates[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
	data->map.source.coordinates[Y] = WINY / 2;
	data->map.source.coordinates[Z] = 0;
	data->map.scale = 1;
	copy_map(data->map.points, proyect, data->map.len);
	parse_map(data, proyect);
	while (!(limits(proyect, data->map.len)))
	{
		copy_map(data->map.points, proyect, data->map.len);
		parse_map(data, proyect);
		data->map.scale = data->map.scale + 0.2;
	}
}

void	draw_map_points(t_data *data, t_point *proyect, int fit)
{
	if (data->map.b_stars)
		generate_stars(data);
	if (fit)
		go_fit(data, proyect);
	if (data->map.b_lines)
		wired(data, proyect);
	if (data->map.b_dots)
		doted(data, proyect);
}

/* 
*	This function draw the proyection of map->points acording all
*	the modifiers (x,y,z, scale..). If fit = 1, will caculate the 
*	scale needed to fit the screen.
*/

int draw_map(t_data *data, int should_fit_window)
{
    t_point *projected_points;
    clock_t start_time;

    start_time = clock();
    projected_points = malloc(data->map.len * sizeof(t_point));
    if (projected_points == NULL)
        exit_with_error(ERR_MEM);
    data->map.renders++;
    generate_background(data, data->map.palette.backcolor, \
        data->map.palette.menucolor);
    copy_map_points(data->map.points, projected_points, data->map.len);
    parse_map(data, projected_points);
    draw_map_points(data, projected_points, should_fit_window);
    mlx_put_image_to_window(data->vars.mlx, data->vars.win, \
        data->bitmap.img, 0, 0);
    draw_menu(data);
    free(projected_points);
    clock_t end_time = clock();
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    data->map.performance = elapsed_time;
    return (1);
}
