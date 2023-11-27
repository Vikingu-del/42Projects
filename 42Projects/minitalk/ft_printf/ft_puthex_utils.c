/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:09:20 by eseferi           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/10/11 00:13:50 by eseferi          ###   ########.fr       */
=======
/*   Updated: 2023/06/20 00:25:40 by eseferi          ###   ########.fr       */
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_rigthjustified(unsigned long hex_value, t_flags *flags)
{
	int	count;
	int	len;

	len = ft_hex_len(hex_value);
	count = 0;
	if (!flags->precision_point)
		count += ft_rhex_fcom(hex_value, flags, len, 0);
	else if (flags->precision_point)
	{
		if (flags->precision_value >= flags->width)
		{
			if (flags->hash && hex_value != 0)
				count += ft_check_hash(flags);
			count += ft_pad_char('0', flags->precision_value - len, 0);
		}
		else if (flags->precision_value < flags->width)
			count += ft_rhex_scom(hex_value, flags, len, count);
		count += ft_puthex(hex_value, flags);
	}
	return (count);
}

static int	ft_hex_leftjustified(unsigned long hex_value, t_flags *flags)
{
	int	count;
	int	len;

	len = ft_hex_len(hex_value);
	count = 0;
	if (!flags->precision_point)
		count += ft_lhex_first_combos(hex_value, len, flags);
	else if (flags->precision_point)
	{
		if (flags->hash && hex_value != 0)
			count += ft_lhex_sec_combos(hex_value, len, flags);
		else
		{
			count += ft_pad_char('0', flags->precision_value - len, 0);
			count += ft_puthex(hex_value, flags);
			if (flags->precision_value > len)
<<<<<<< HEAD
				count += ft_pad_char(' ', flags->width - \
			flags->precision_value, 0);
=======
		count += ft_pad_char(' ', flags->width - flags->precision_value, 0);
>>>>>>> d1aa95c9132cd0a4997d0e4fae446bae872b58e2
			else
				count += ft_pad_char(' ', flags->width - len, 0);
		}
	}
	return (count);
}

int	ft_puthex_format(long hex_value_to_justf, t_flags *flags)
{
	int				count;
	unsigned long	hex_value;

	hex_value = (unsigned long)hex_value_to_justf;
	count = 0;
	if (flags->precision_point && !flags->precision_value && hex_value == 0)
	{
		if (flags->width != 0)
			return (ft_pad_char(' ', flags->width, 0));
		return (0);
	}
	if (flags->width > ft_hex_len(hex_value))
	{
		if (flags->left_justified)
			count += ft_hex_leftjustified(hex_value, flags);
		else if (!flags->left_justified)
			count += ft_hex_rigthjustified(hex_value, flags);
	}
	else if (flags->width <= ft_hex_len(hex_value))
		count += ft_puthex_com(flags, hex_value);
	return (count);
}
