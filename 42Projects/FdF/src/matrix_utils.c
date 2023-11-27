/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 01:10:38 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/27 03:14:55 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../lib/mlx/mlx.h"
#include "../inc/defines.h"
#include "../inc/map.h"
#include "../inc/geometry.h"
#include "../inc/errors.h"
#include "../inc/map_utils.h"
#include "../inc/draw_utils.h"
#include "../inc/utils.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>

void	orto_proyection(t_point *points, t_point *proyection, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		proyection[i].axis[X] = points[i].axis[X];
		proyection[i].axis[Y] = points[i].axis[Y];
		i++;
	}
}

void    rotate_x(t_point *points, t_point_proyection, float ang, int len)
{
    int	i;
    float	rot_matrix[3][3];

    i = 0;
    matrix_init(rot_matrix);
    rot_matrix[1][1] = cos(ang);
    rot_matrix[1][2] = -sin(ang);
    rot_matrix[2][1] = sin(ang);
    rot_matrix[2][2] = cos(ang);
    while (i < len)
    {
        proyection[i].axis[X] = points[i].axis[X] * rot_matrix[0][0] + \
                                points[i].axis[Y] * rot_matrix[0][1] + \
                                points[i].axis[Z] * rot_matrix[0][2];
        proyection[i].axis[Y] = points[i].axis[X] * rot_matrix[1][0] + \
                                points[i].axis[Y] * rot_matrix[1][1] + \
                                points[i].axis[Z] * rot_matrix[1][2];
        proyection[i].axis[Z] = points[i].axis[X] * rot_matrix[2][0] + \
                                points[i].axis[Y] * rot_matrix[2][1] + \
                                points[i].axis[Z] * rot_matrix[2][2];
        i++;
    }
}

void    rotate_y(t_point *points, t_point_proyection, float ang, int len)
{
    int	i;
    float	rot_matrix[3][3];

    i = 0;
    matrix_init(rot_matrix);
    rot_matrix[0][0] = cos(ang);
    rot_matrix[0][2] = sin(ang);
    rot_matrix[2][0] = -sin(ang);
    rot_matrix[2][2] = cos(ang);
    while (i < len)
    {
        proyection[i].axis[X] = points[i].axis[X] * rot_matrix[0][0] + \
                                points[i].axis[Y] * rot_matrix[0][1] + \
                                points[i].axis[Z] * rot_matrix[0][2];
        proyection[i].axis[Y] = points[i].axis[X] * rot_matrix[1][0] + \
                                points[i].axis[Y] * rot_matrix[1][1] + \
                                points[i].axis[Z] * rot_matrix[1][2];
        proyection[i].axis[Z] = points[i].axis[X] * rot_matrix[2][0] + \
                                points[i].axis[Y] * rot_matrix[2][1] + \
                                points[i].axis[Z] * rot_matrix[2][2];
        i++;
    }
}

void    rotate_z(t_point *points, t_point_proyection, float ang, int len)
{
    int	i;
    float	rot_matrix[3][3];

    i = 0;
    matrix_init(rot_matrix);
    rot_matrix[0][0] = cos(ang);
    rot_matrix[0][1] = -sin(ang);
    rot_matrix[1][0] = sin(ang);
    rot_matrix[1][1] = cos(ang);
    while (i < len)
    {
        proyection[i].axis[X] = points[i].axis[X] * rot_matrix[0][0] + \
                                points[i].axis[Y] * rot_matrix[0][1] + \
                                points[i].axis[Z] * rot_matrix[0][2];
        proyection[i].axis[Y] = points[i].axis[X] * rot_matrix[1][0] + \
                                points[i].axis[Y] * rot_matrix[1][1] + \
                                points[i].axis[Z] * rot_matrix[1][2];
        proyection[i].axis[Z] = points[i].axis[X] * rot_matrix[2][0] + \
                                points[i].axis[Y] * rot_matrix[2][1] + \
                                points[i].axis[Z] * rot_matrix[2][2];
        i++;
    }
}