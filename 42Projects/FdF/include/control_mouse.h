/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_mouse.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:29:29 by codespace         #+#    #+#             */
/*   Updated: 2023/09/26 17:38:22 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_MOUSE_H
# define CONTROL_MOUSE_H

int mouse_move(int x, int y, void *param);
int mouse_release(int button, int x, int y, void *paran);
int mouse_move(int x, int y, void *data);

#endif