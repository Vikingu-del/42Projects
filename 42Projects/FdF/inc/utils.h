/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 20:14:23 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 23:05:34 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	dbl_free(char **ptr);
int		ft_round(double num);
void	matrix_init(float (*matrix)[3]);
void	print_nbr(t_meta *meta, int x, int y, int nbr);
void	print_str(t_meta *meta, int x, int y, char *str);
void	copy_map(t_point *src, t_point *dst, int len);
int		valid_pixel(t_point pixel);
#endif