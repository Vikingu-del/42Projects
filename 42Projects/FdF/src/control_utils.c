/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:07:24 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/27 01:39:16 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx/mlx.h"
#include "../lib/libft/include/libft.h"
#include "../inc/defines.h"
#include "../inc/keycodes.h"
#include "../inc/map.h"
#include "../inc/map_utils.h"
#include <errno.h>

/* 
*	This function increment the ang value by value, checking is under the limits
*/

void	angle(float *ang, float value)
{
	*ang += value;
	if (*ang < 0)
			*ang = 360 + *ang;
	if (*ang >= 360)
			*ang = *ang - 360;
}

/* 
*	This function add grades to the control structure depends the key pressed
*/

void	angle_control(int key, t_data *data)
{
	int	ang;

	ang = 1;
	if (data->keys.b_keyctrl)
		ang = 90;
	if (key == KEY_DOWN)
		angle(&data->map.ang[X], ang);
	if (key == KEY_UP)
		angle(&data->map.ang[X], -ang);
	if (key == KEY_LEFT)
		angle(&data->map.ang[Y], ang);
	if (key == KEY_RIGHT)
		angle(&data->map.ang[Y], -ang);
	if (key == KEY_Q)
		angle(&data->map.ang[Z], ang);
	if (key == KEY_W)
		angle(&data->map.ang[Z], -ang);
}

/* 
*	This function handle the program shut down
*/

int	terminate_program(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_destroy_window(data->vars.mlx, data->vars.win);
	free(data->map.points);
	exit(0);
}

/* 
*	This function handle the program shut down when a error happends
*/

void	exit_with_error(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

/* 
*	This function handle the colorscheme dependig the key pressed
*/

void	control_colorscheme(int key, t_map *map)
{
	map->palette.backcolor = CARBON;
	map->palette.bottomcolor = AZUL;
	map->palette.topcolor = BRICK_RED;
	map->palette.groundcolor = SAFFRON;
	if (key == KEY_2)
	{
		map->palette.backcolor = WHITE;
		map->palette.bottomcolor = CARBON;
		map->palette.topcolor = CARBON;
		map->palette.groundcolor = CARBON;
	}
	if (key == KEY_3)
	{
		map->palette.bottomcolor = WHITE;
		map->palette.topcolor = WHITE;
		map->palette.groundcolor = WHITE;
	}
	if (key == KEY_4)
	{
		map->palette.bottomcolor = SUPERAZUL;
		map->palette.topcolor = ROJO;
		map->palette.groundcolor = VERDE;
	}
	colorize(map);
}