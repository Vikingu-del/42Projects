/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:07:49 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/27 01:36:10 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx/mlx.h"
#include "../inc/defines.h"
#include "../inc/utils.h"
#include "../inc/draw_utils.h"
#include <math.h>
#include <stdlib.h>

/*
*	This function fills 4 bytes of the given address whith the values of colors
*	depending the andian
*      endian = 1 --> Most significant (Alpha) byte first
*      endian = 0 --> Least significant (Blue) byte first
*/

void	set_color(char *buffer, int endian, int color, int alpha)
{
	if (endian == 1)
	{
		buffer[0] = alpha;
		buffer[1] = (color >> 16) & 0xFF;
		buffer[2] = (color >> 8) & 0xFF;
		buffer[3] = (color) & 0xFF;
	}
	else
	{
		buffer[0] = (color) & 0xFF;
		buffer[1] = (color >> 8) & 0xFF;
		buffer[2] = (color >> 16) & 0xFF;
		buffer[3] = alpha;
	}
}

/*
*	This function calculate the position of the pixel in the img array:
*		array_pixe_position = pixel.axis[y] * WINX * 4 + 4 * pixel.axis[y]
*	and fill the 4 colorbytes calling the set_color function
*/

int	my_putpixel(t_data *data, t_point pixel)
{
	int	mypixel;
	int	alpha;

	alpha = 0;
	if (pixel.coordinates[X] < MENU_WIDTH)
		alpha = -10;
	if (pixel.coordinates[X] >= WINX || pixel.coordinates[Y] >= WINY || \
		pixel.coordinates[X] < 0 || pixel.coordinates[Y] < 0)
		return (-1);
	mypixel = ((int)pixel.coordinates[Y] * WINX * 4) + ((int)pixel.coordinates[X] * 4);
	if (data->picture.bitxpixel != 32)
		pixel.color = mlx_get_color_value(data->vars.mlx, pixel.color);
	set_color(&data->picture.buffer[mypixel], \
		data->picture.endian, pixel.color, alpha);
	return (0);
}

/*
*	This function set the color value to 32bits value in case of need
*/

int	get_color(t_data *data, int color)
{	
	if (data->picture.bitxpixel != 32)
		color = mlx_get_color_value(data->vars.mlx, color);
	return (color);
}

/*
*	This function generate all the pixel colors and fill the img array propertly
*/

void	generate_background(t_data *data, int backcolor, int menucolor)
{
	int	coordinates[2];
	int	pixel;
	int	color;

	backcolor = get_color(data, backcolor);
	menucolor = get_color(data, menucolor);
	coordinates[X] = 0;
	coordinates[Y] = 0;
	while (coordinates[Y] < WINY)
	{
		while (coordinates[X] < WINX)
		{
			if (coordinates[X] < MENU_WIDTH)
				color = menucolor;
			else
				color = backcolor;
			pixel = (coordinates[Y] * data->picture.lines) + (coordinates[X] * 4);
			set_color(&data->picture.buffer[pixel], \
						data->picture.endian, color, 1);
			coordinates[X]++;
		}
		coordinates[Y]++;
		coordinates[X] = 0;
	}
}

void	generate_stars(t_data *data)
{
	int		i;
	t_point	star;
	int		lim_x[2];
	int		lim_y[2];

	if (data->map.b_geo == 0)
		return ;
	lim_x[0] = data->map.source.coordinates[X] - (data->map.radius * data->map.scale);
	lim_x[1] = data->map.source.coordinates[X] + (data->map.radius * data->map.scale);
	lim_y[0] = data->map.source.coordinates[Y] - (data->map.radius * data->map.scale);
	lim_y[1] = data->map.source.coordinates[Y] + (data->map.radius * data->map.scale);
	i = 0;
	while (i < 200)
	{
		star.coordinates[X] = rand() % WINX;
		star.coordinates[Y] = rand() % WINY;
		star.color = WHITE;
		if ((star.coordinates[X] < lim_x[0] || star.coordinates[X] > lim_x[1]) \
		|| ((star.coordinates[Y]) < lim_y[0] || star.coordinates[Y] > lim_y[1]))
			draw_dot(data, star, 2);
		i++;
	}
}