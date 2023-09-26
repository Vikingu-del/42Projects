/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:33:28 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 17:39:41 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_UTILS_H
# define CONTROL_UTILS_H

void    angle_control(int keycode, t_meta *meta);
void    angle(float *angle, float value);
void    colorize(t_map *map);
int     terminate_program(void *param);
void    terminate(char *s);
void    control_colorscheme(int keycode, t_map *map);

#endif