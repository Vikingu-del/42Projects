/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:05:13 by eseferi           #+#    #+#             */
/*   Updated: 2023/10/05 12:53:03 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILS_H
# define MAP_UTILS_H

void	apply_color_scheme(t_map *map);
void	wiring(t_data *data, t_point *wire);
void	doted(t_data *data, t_point *proyect);
void	z_scaling(t_point *proyect, float divisor, int len);
void	init_map(t_map *map, int clean_state);
void	show_info(t_map *map);
void	z_limits(char **splited, t_map *map);
int		point_is_valid(char *str_point);
int		has_hexcolors(char *line);
void	load_color(int max, int min, t_point *point, t_palette palette);
#endif