/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:33:28 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 23:03:23 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_UTILS_H
# define CONTROL_UTILS_H

void	angle_control(int key, t_meta *meta);
void	angle(float *ang, float value);
void	colorize(t_map *map);
int		terminate_program(void *param);
void	terminate(char *s);
void	control_colorscheme(int key, t_map *map);
#endif