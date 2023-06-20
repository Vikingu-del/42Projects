/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexcombos_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 23:44:31 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/20 00:26:06 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_rhex_fcom(unsigned long hex, t_flags *flags, int len, int count)
{
	if (flags->zero_left_pad_sentinel)
	{
		if (flags->hash && hex != 0)
		{
			count += ft_check_hash(flags);
			count += ft_pad_char('0', flags->width - len - 2, 0);
		}
		else
			count += ft_pad_char('0', flags->width - len, 0);
	}	
	else
	{
		if (flags->hash && hex != 0)
			count += ft_pad_char(' ', flags->width - len - 2, 0);
		else
			count += ft_pad_char(' ', flags->width - len, 0);
	}
	count += ft_puthex(hex, flags);
	return (count);
}

int	ft_rhex_scom(unsigned long hex, t_flags *flags, int len, int count)
{
	if (flags->precision_value >= len && !flags->hash)
		count += ft_pad_char(' ', flags->width - flags->precision_value, 0);
	else if (!flags->hash)
		count += ft_pad_char(' ', flags->width - len, 0);
	if (flags->hash)
	{
		if (hex != 0)
		{
			if (flags->precision_value > len)
		count += ft_pad_char(' ', flags->width - flags->precision_value - 2, 0);
			else
				count += ft_pad_char(' ', flags->width - len - 2, 0);
			if (flags->is_upper)
				count += write (1, "0X", 2);
			else
				count += write (1, "0x", 2);
		}
		else
			count += ft_pad_char(' ', flags->width - flags->precision_value, 0);
		flags->hash = 0;
	}
	count += ft_pad_char('0', flags->precision_value - len, 0);
	return (count);
}

int	ft_puthex_com(t_flags *flags, unsigned long hex)
{
	int	count;

	count = 0;
	if (flags->precision_value > ft_hex_len(hex))
	{
		if (flags->hash && hex != 0)
			count += ft_check_hash(flags);
		count += ft_pad_char('0', flags->precision_value - ft_hex_len(hex), 0);
		count += ft_puthex(hex, flags);
	}
	else
		count += ft_puthex(hex, flags);
	return (count);
}
