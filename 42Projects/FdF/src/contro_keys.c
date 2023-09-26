/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contro_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 21:55:55 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/26 22:10:29 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// handling pressing b, 


// handle key presses
int key_press(int key, void *param)
{
    t_meta *meta;

    meta = (t_meta *)param;
    angle_control(key, meta);
    control_keys
}