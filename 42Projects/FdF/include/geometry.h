/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:39:08 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 19:52:00 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

void	translate(t_point *points, t_point move, int len);
void	scale(t_point *points, int scale, int len);
void	isometric(t_map *map);
void	bending(t_point *points, int len, float range);
void	parallel(t_map *map);
void	spherize(t_map *map, t_point *points);
void	go_polar(t_map *map);

#endif