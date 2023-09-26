/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:11:13 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 20:13:51 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

void    orto_projection(t_point *points, t_point *projection, int len);
void    rotate_x(t_point *points, t_point *projection, float angle, int len);
void    rotate_y(t_point *points, t_point *projection, float angle, int len);
void    rotate_z(t_point *points, t_point *projection, float angle, int len);

#endif