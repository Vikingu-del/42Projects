/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_combination_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:33:02 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/20 00:15:21 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_left_fir_combos(long nbr, t_flags *flags, int nbr_len)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_pad_char('0', flags->precision_value - nbr_len + 1, nbr);
		count += ft_putnbr_long_precision(nbr, nbr_len);
		count += ft_pad_char(' ', flags->width
				- flags->precision_value - 1, 0);
	}
	else
	{
		count += ft_pad_char('0', flags->precision_value - nbr_len, nbr);
		count += ft_putnbr_long_precision(nbr, nbr_len);
		if (flags->space || flags->plus_sign)
			count += ft_pad_char(' ', flags->width
					- flags->precision_value - 1, 0);
		else
			count += ft_pad_char(' ', flags->width - flags->precision_value, 0);
	}
	return (count);
}

int	ft_left_sec_combos(long nbr, t_flags *flags, int nbr_len)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += write (1, "-", 1);
		nbr = -nbr;
		count += ft_putnbr_long_precision(nbr, nbr_len);
		if (flags->width > nbr_len)
			count += ft_pad_char(' ', flags->width - nbr_len, nbr);
		else
			count += ft_pad_char(' ', flags->width - nbr_len - 1, nbr);
	}
	else
	{
		count += ft_putnbr_long_precision(nbr, nbr_len);
		if (!flags->space && !(flags->plus_sign && flags->left_justified))
			count += ft_pad_char(' ', flags->width - nbr_len, nbr);
		else
			count += ft_pad_char(' ', flags->width - nbr_len - 1, nbr);
	}
	return (count);
}

int	ft_lhex_first_combos(unsigned long hex_value, int len, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->hash && hex_value != 0)
	{
		count += ft_puthex(hex_value, flags);
		count += ft_pad_char(' ', flags->width - len - 2, 0);
	}
	else
	{
		count += ft_puthex(hex_value, flags);
		count += ft_pad_char(' ', flags->width - len, 0);
	}
	return (count);
}

int	ft_lhex_sec_combos(unsigned long hex_value, int len, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->is_upper)
		count += write (1, "0X", 2);
	else
		count += write (1, "0x", 2);
	flags->hash = 0;
	count += ft_pad_char('0', flags->precision_value - len, 0);
	count += ft_puthex(hex_value, flags);
	flags->hash = 1;
	if (flags->precision_value > len)
		count += ft_pad_char(' ', flags->width - flags->precision_value - 2, 0);
	else
		count += ft_pad_char(' ', flags->width - len - 2, 0);
	return (count);
}
