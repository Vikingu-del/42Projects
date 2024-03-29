/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:14:23 by eseferi           #+#    #+#             */
/*   Updated: 2023/10/05 13:43:23 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	free_2darray(char **ptr);
void	print_nbr(t_data *data, int x, int y, int nbr);
void	print_str(t_data *data, int x, int y, char *str);
void	copy_map_points(t_point *map_points, t_point *projection, int len);
int		valid_pixel(t_point pixel);
int		modified_atoi(const char *str);
#endif