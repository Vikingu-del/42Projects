/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:28:54 by codespace         #+#    #+#             */
/*   Updated: 2023/09/26 17:33:56 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_KEYS_H
# define CONTROL_KEYS_H

int key_press(int keycode, t_fdf *data);
int key_release(int keycode, t_fdf *data);

#endif