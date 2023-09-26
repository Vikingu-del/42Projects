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
	t_meta	*meta;

	meta = (t_meta *)param;
	if (x > WINX || x < 0 || y > WINY || y < 0)
		return (0);
	if (meta->keys.b_mouse_l)
	{
		angle(&meta->map.ang[X], (int)meta->keys.last_click_l.axis[Y] - y);
		angle(&meta->map.ang[Y], (int)meta->keys.last_click_l.axis[X] - x);
		meta->keys.last_click_l.axis[X] = x;
		meta->keys.last_click_l.axis[Y] = y;
		draw_map(meta, FREE);
	}
	if (meta->keys.b_mouse_r)
	{
		meta->map.source.axis[X] -= ((int)meta->keys.last_click_r.axis[X] - x);
		meta->map.source.axis[Y] -= ((int)meta->keys.last_click_r.axis[Y] - y);
		meta->map.source.axis[Z] = 0;
		meta->keys.last_click_r.axis[X] = x;
		meta->keys.last_click_r.axis[Y] = y;
		draw_map(meta, FREE);
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
		meta->keys.last_click_l.axis[X] = x;
		meta->keys.last_click_l.axis[Y] = y;
	}
	if (button == 2)
	{
		meta->keys.b_mouse_r = 1;
		meta->keys.last_click_r.axis[X] = x;
		meta->keys.last_click_r.axis[Y] = y;
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