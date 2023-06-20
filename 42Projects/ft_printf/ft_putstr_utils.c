/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:11:41 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/15 16:06:36 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Put a string 
 * Return the chars written
*/
static int	ft_putstr(char *str, int bytes)
{	
	if (!*str || !bytes)
		return (0);
	else
	{
		write(1, str, 1);
		return (ft_putstr(++str, --bytes) + 1);
	}	
}

static int	ft_str_justify(char *str, int chars_to_write, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->left_justified)
	{
		count += ft_putstr(str, chars_to_write);
		count += ft_pad_char(32, flags->width - chars_to_write, 0);
	}
	else if (!flags->left_justified)
	{
		count += ft_pad_char(32, flags->width - chars_to_write, 0);
		count += ft_putstr(str, chars_to_write);
	}
	return (count);
}

int	ft_putstr_format(char *str, t_flags *flags)
{
	int	count;

	count = 0;
	if (NULL == str)
		str = "(null)";
	if (flags->precision_point)
	{
		if (flags->precision_value > ft_strlen(str))
			flags->precision_value = ft_strlen(str);
		if (flags->width - flags->precision_value > 0)
			count += ft_str_justify(str, flags->precision_value, flags);
		else
			count += ft_putstr(str, flags->precision_value);
	}
	else if (!flags->precision_point)
	{
		if (flags->width > (int)ft_strlen((const char *)str))
			count += ft_str_justify(str, ft_strlen((const char *)str), flags);
		else
			count += ft_putstr(str, ft_strlen((const char *)str));
	}
	return (count);
}
