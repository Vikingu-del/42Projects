/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:01:36 by eseferi           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/09/13 13:10:32 by eseferi          ###   ########.fr       */
=======
/*   Updated: 2023/06/13 22:17:35 by eseferi          ###   ########.fr       */
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //TODO
#include "ft_printf.h"
#include "libft/libft.h"

void	ft_refresh_flags(t_flags *flags)
{
	flags->zero_left_pad_sentinel = 0;
	flags->left_justified = 0;
	flags->plus_sign = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision_point = 0;
	flags->precision_value = 0;
	flags->is_upper = 0;
	flags->is_unsigned = 0;
	flags->specifier = 0;
	flags->hash = 0;
}

<<<<<<< HEAD
=======
/*
 * the % char is considered like a specifier
*/
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2
static int	ft_is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i'
		|| c == 'p' || c == 'x' || c == 'X' || c == 'u'
		|| c == '%')
		return (1);
	return (0);
}

<<<<<<< HEAD
=======
/*
 * a number in a flag has a different meaning 
 * depending by the position
 *
 *		 %[0_pad][width].[precision]
 * 
 * i handle 0 and other numbers separately
 *
*/
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2
static void	ft_handle_digits(char c, t_flags *flags)
{
	if ('0' == c && !(flags->width) && !(flags->precision_point))
		flags->zero_left_pad_sentinel = 1;
	else if ('0' == c && flags->width && !(flags->precision_point))
		flags->width = (flags->width *= 10);
	else if ('0' == c && flags->precision_point)
		flags->precision_value = (flags->precision_value *= 10);
	else if (ft_isdigit((int)c))
	{
		if (!(flags->precision_point))
			flags->width = (flags->width * 10) + (c - 48);
		else if (flags->precision_point)
			flags->precision_value = (flags->precision_value * 10) + (c - 48);
	}
}

int	ft_parse_flags(const char *format_str, int i, t_flags *flags)
{
	char	current_char;

	while (!(ft_is_specifier(format_str[++i])))
	{
		current_char = format_str[i];
		if (current_char == ' ')
			flags->space = 1;
		else if (current_char == '+')
			flags->plus_sign = 1;
		else if (current_char == '-')
			flags->left_justified = 1;
		else if (current_char == '#')
			flags->hash = 1;
		else if (current_char == '.')
			flags->precision_point = 1;
		else if (ft_isdigit(current_char))
			ft_handle_digits(current_char, flags);
	}
	if (format_str[i] >= 65 && format_str[i] <= 90)
		flags->is_upper = 1;
	if (format_str[i] == 'u')
		flags->is_unsigned = 1;
	flags->specifier = format_str[i];
	return (i);
}
