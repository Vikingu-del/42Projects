/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:08:39 by eseferi           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/06/07 17:13:39 by eseferi          ###   ########.fr       */
=======
/*   Updated: 2023/10/10 09:00:36 by eseferi          ###   ########.fr       */
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//TODO
#include "ft_printf.h"

/*
 * With the char type only
 * 	~width
 * 	~left_justify
 * flags make sense.
*/

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/*
 * Handles the flag '-'
*/
static int	ft_char_justify(char c, t_flags *flags)
{
	int	count;

	count = 0;
	if (!(flags->left_justified))
	{
		while (--(flags->width))
			count += ft_putchar(32);
		count += (ft_putchar(c));
		return (count);
	}
	else
	{
		count += (ft_putchar(c));
		while (--(flags->width))
			count += ft_putchar(32);
		return (count);
	}
}

int	ft_putchar_format(char c, t_flags *flags)
{
<<<<<<< HEAD
	int	count;

	count = 0;
=======
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2
	if (flags->width > 1)
		return (ft_char_justify(c, flags));
	return (ft_putchar(c));
}
