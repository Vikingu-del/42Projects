/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:28:43 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 23:03:55 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_UTILS_H
# define DRAW_UTILS_H

int		draw_line(t_meta *meta, t_point start, t_point end);
void	draw_dot(t_meta *meta, t_point point, int radius);
int		gradient(int startcolor, int endcolor, int len, int pix);
int		my_putpixel(t_meta *meta, t_point pixel);
void	shadow(t_point *points, int len);
#endif