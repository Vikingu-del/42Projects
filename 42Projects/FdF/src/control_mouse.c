/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:06:48 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 23:06:55 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/map.h"
#include "../inc/keycodes.h"
#include "../inc/control_utils.h"

/* 
*	This function handle every time the mouse is moved
*/

int	mouse_move(int x, int y, void *param)
{
	t_meta	*data;

	data = (t_data *)param;
	if (x > WINX || x < 0 || y > WINY || y < 0)
		return (0);
	if (data->keys.b_mouse_l)
	{
		angle(&data->map.ang[X], (int)data->keys.last_click_l.coordinates[Y] - y);
		angle(&data->map.ang[Y], (int)data->keys.last_click_l.coordinates[X] - x);
		data->keys.last_click_l.coordinates[X] = x;
		data->keys.last_click_l.coordinates[Y] = y;
		draw_map(data, FREE);
	}
	if (data->keys.b_mouse_r)
	{
		data->map.source.coordinates[X] -= ((int)data->keys.last_click_r.coordinates[X] - x);
		data->map.source.coordinates[Y] -= ((int)data->keys.last_click_r.coordinates[Y] - y);
		data->map.source.coordinates[Z] = 0;
		data->keys.last_click_r.coordinates[X] = x;
		data->keys.last_click_r.coordinates[Y] = y;
		draw_map(data, FREE);
	}
	return (0);
}

/* 
*	This function handle every time a mouse button is relased
*/

int	mouse_release(int button, int x, int y, void *param)
{
	t_meta	*meta;

	(void)x;
	(void)y;
	meta = (t_meta *)param;
	if (button == 1)
		meta->keys.b_mouse_l = 0;
	if (button == 2)
		meta->keys.b_mouse_r = 0;
	return (0);
}

/* 
*	This function handle every time a mouse button is pressed
*/

int	mouse_press(int button, int x, int y, void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	if (button == 1)
	{
		meta->keys.b_mouse_l = 1;
		meta->keys.last_click_l.coordinates[X] = x;
		meta->keys.last_click_l.coordinates[Y] = y;
	}
	if (button == 2)
	{
		meta->keys.b_mouse_r = 1;
		meta->keys.last_click_r.coordinates[X] = x;
		meta->keys.last_click_r.coordinates[Y] = y;
	}	
	if (button == 5)
	{
		if (meta->map.scale > 2)
			meta->map.scale = meta->map.scale / 1.5;
	}
	if (button == 4)
		meta->map.scale = meta->map.scale * 1.5;
	draw_map(meta, FREE);
	return (0);
}