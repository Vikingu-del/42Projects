/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:07:24 by eseferi           #+#    #+#             */
/*   Updated: 2023/10/04 22:50:02 by eseferi          ###   ########.fr       */
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
	map->colors.backcolor = BLACK;
	map->colors.bottomcolor = BLUE;
	map->colors.topcolor = DARK_RED;
	map->colors.groundcolor = YELLOW;
	if (key == KEY_2)
	{
		map->colors.backcolor = GRAY;
		map->colors.bottomcolor = BLACK;
		map->colors.topcolor = BLACK;
		map->colors.groundcolor = BLACK;
	}
	if (key == KEY_3)
	{
		map->colors.bottomcolor = GRAY;
		map->colors.topcolor = GRAY;
		map->colors.groundcolor = GRAY;
	}
	if (key == KEY_4)
	{
		map->colors.bottomcolor = LIGHT_BLUE;
		map->colors.topcolor = RED;
		map->colors.groundcolor = GREEN;
	}
	apply_color_scheme(map);
}