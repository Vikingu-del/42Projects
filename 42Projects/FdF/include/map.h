/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:56:47 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 20:03:15 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

/* DEFINES NORMINETTE REFUSED
#define XCENTER		((WINX - MENU_WIDTH) / 2) + MENU_WIDTH
#define YCENTER		(WINY / 2)
*/

int	draw_map(t_meta *meta, int fit);
void load_map(t_meta *meta, char *path);
void generate_background(t_meta *meta, int backcolor, int menucolor);
void draw_menu(t_meta *meta);
void load_color(int max, int min, t_point *point, t_colors colors);
void generate_stars(t_meta *meta);

#endif