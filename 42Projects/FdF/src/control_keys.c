/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:55:55 by eseferi           #+#    #+#             */
/*   Updated: 2023/10/04 22:43:14 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx/mlx.h"
#include "../inc/defines.h"
#include "../inc/map.h"
#include "../inc/keycodes.h"
#include "../inc/geometry.h"
#include "../inc/control_utils.h"
#include "../inc/map_utils.h"

/* 
*	This function handle some key press events
*/

void	control_keys3(int key, t_data *data)
{
	if (key == KEY_B)
	{
		if (data->keys.b_keyctrl)
			data->map.curve_range -= 0.0001;
		else
			data->map.curve_range += 0.0001;
	}
	if (key == KEY_SUM || key == KEY_SUM2)
	{
		if (data->keys.b_keyctrl)
			data->map.scale *= 1.5;
		if (data->map.z_scale > 1)
			data->map.z_scale -= 1;
	}
	if (key == KEY_RES || key == KEY_RES2)
	{
		if (data->keys.b_keyctrl)
			data->map.scale = data->map.scale / 1.5;
		data->map.z_scale += 1;
	}
	if (key == KEY_I)
	{
		isometric(&data->map);
		draw_map(data, FIT);
	}			
}

/* 
*	This function handle some key press events
*/

void	control_keys2(int key, t_data *data)
{
	if (key == KEY_D)
		data->map.b_dots = !data->map.b_dots;
	if (key == KEY_L)
		data->map.b_lines = !data->map.b_lines;
	if (key == KEY_X)
		data->map.b_pluslines = !data->map.b_pluslines;
	if (key == KEY_G)
		data->map.sphere = !data->map.sphere;
	if (key == KEY_S)
		data->map.b_stars = !data->map.b_stars;
	if (key == KEY_H)
		data->map.shadows = !data->map.shadows;
	if (key == KEY_F)
		draw_map(data, FIT);
	if (key == KEY_CMD)
		data->keys.b_keyctrl = 1;
}

/* 
*	This function handle some key press events
*/

void	control_keys1(int key, t_data *data)
{
	if (key == KEY_ESC)
		terminate_program(data);
	if (key == KEY_R)
	{
		init_map(&data->map, 0);
		data->map.scale = \
		data->map.limits.coordinates[Z] / data->map.limits.coordinates[X];
		if (data->map.scale > 0.5)
			data->map.z_scale = data->map.scale * 30;
		apply_color_scheme(&data->map);
		draw_map(data, FIT);
	}	
	if (key == KEY_C)
	{
		data->map.source.coordinates[X] = ((WINX - MENU_WIDTH) / 2) + MENU_WIDTH;
		data->map.source.coordinates[Y] = WINY / 2;
	}
	if (key == KEY_P)
	{
		parallel(&data->map);
		draw_map(data, FIT);
	}			
}

/* 
*	This function handle when a key is pressed
*/

int	key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	angle_control(key, data);
	control_keys1(key, data);
	control_keys2(key, data);
	control_keys3(key, data);
	if (key >= KEY_1 && key <= KEY_4)
		control_colorscheme(key, &data->map);
	draw_map(data, FREE);
	return (0);
}

/* 
*	This function handle when a key is relased
*/

int	key_release(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == KEY_CMD)
		data->keys.b_keyctrl = 0;
	return (0);
}