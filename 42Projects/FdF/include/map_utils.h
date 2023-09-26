/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:05:13 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 20:11:58 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

void    colorize(t_map *map);
void    wired(t_meta *meta, t_point *wire);
void    doted(t_meta *meta, t_point *project);
void    z_division(t_point *pryect, float divisor, int len);
void    map_init(t_map *map, int total);
void    show_info(t_map *map);
void    z_limits(char **splited, t_map *map);
int     valid_point(char *value);
int     has_hexcolors(char *line);
void    load_colors(int max, int min, t_point *point, t_colors colors);

#endif