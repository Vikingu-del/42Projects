/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:12:49 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 23:12:53 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"
/* 
*	This function copy len points of the array from src to dst
*/

void	copy_map(t_point *src, t_point *dst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

/*
*	This function checks if the point is in the windows limit to avoid draw it
*/

int	valid_pixel(t_point pixel)
{
	if (pixel.axis[X] < 0 || pixel.axis[X] > WINX)
		return (0);
	if (pixel.axis[Y] < 0 || pixel.axis[Y] > WINY)
		return (0);
	return (1);
}