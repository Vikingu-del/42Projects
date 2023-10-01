/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:08:31 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 23:08:33 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
#include "../inc/draw_utils.h"
#include "../inc/utils.h"
#include <math.h>

/*
*	Auxiliar function to draw a circle
*/

static void	dot_util(t_data *data, t_point pixel, t_point point, int coord)
{
	int	i;

	i = point.coordinates[X];
	while (i <= point.coordinates[X] + coord)
	{
		pixel.coordinates[X] = i;
		pixel.coordinates[Y] = (int)point.coordinates[Y] + coord;
		my_putpixel(data, pixel);
		pixel.coordinates[X] = i;
		pixel.coordinates[Y] = (int)point.coordinates[Y] - coord;
		my_putpixel(data, pixel);
		i++;
	}
}

/*
*	This function draw a circule in t_point position and with r radius
*/

void	draw_dot(t_data *data, t_point point, int radius)
{
	int		coordinates[2];
	int		change[2];
	int		radius_error;
	t_point	pixel;

	coordinates[X] = radius;
	coordinates[Y] = 0;
	change[X] = 1 - (radius << 1);
	change[Y] = 0;
	radius_error = 0;
	pixel.color = point.color;
	while (coordinates[X] >= coordinates[Y])
	{
		dot_util(data, pixel, point, coordinates[Y]);
		dot_util(data, pixel, point, coordinates[X]);
		coordinates[Y]++;
		radius_error += change[Y];
		change[Y] += 2;
		if (((radius_error << 1) + change[X]) > 0)
		{
			coordinates[X]--;
			radius_error += change[X];
			change[X] += 2;
		}
	}
}

/*
*	This function generates the color of each pixel between starcolor and endcolor
*	To do that get the RGB chanels independtly and create a 
*	linear escale between each channel.
*	The function return the color number "pix" of line "0->len".
*/

int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((endcolor >> 16) - \
					(startcolor >> 16)) / (double)len;
	increment[1] = (double)(((endcolor >> 8) & 0xFF) - \
					((startcolor >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((endcolor & 0xFF) - (startcolor & 0xFF)) \
					/ (double)len;
	new[0] = (startcolor >> 16) + ft_round(pix * increment[0]);
	new[1] = ((startcolor >> 8) & 0xFF) + ft_round(pix * increment[1]);
	new[2] = (startcolor & 0xFF) + ft_round(pix * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}

void	shadow(t_point *points, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (points[i].coordinates[Z] < 0)
			points[i].paint = 0;
		else
			points[i].paint = 1;
		i++;
	}
}

/*
*	This function checks if the whole line is out of the window to avoid the 
*	operations and getting better the performance.
*	Then calculate all the point of the line with the Bresenham's line algorithm
*/

int	draw_line(t_data *data, t_point start, t_point end)
{
	t_point	delta;
	t_point	pixel;
	int		pixels;
	int		len;

	if (valid_pixel(start) == 0 && valid_pixel(end) == 0)
		return (0);
	delta.coordinates[X] = end.coordinates[X] - start.coordinates[X];
	delta.coordinates[Y] = end.coordinates[Y] - start.coordinates[Y];
	pixels = sqrt((delta.coordinates[X] * delta.coordinates[X]) + \
			(delta.coordinates[Y] * delta.coordinates[Y]));
	len = pixels;
	delta.coordinates[X] /= pixels;
	delta.coordinates[Y] /= pixels;
	pixel.coordinates[X] = start.coordinates[X];
	pixel.coordinates[Y] = start.coordinates[Y];
	while (pixels > 0)
	{
		pixel.color = gradient(start.color, end.color, len, len - pixels);
		my_putpixel(data, pixel);
		pixel.coordinates[X] += delta.coordinates[X];
		pixel.coordinates[Y] += delta.coordinates[Y];
		pixels = pixels - 1;
	}
	return (1);
}