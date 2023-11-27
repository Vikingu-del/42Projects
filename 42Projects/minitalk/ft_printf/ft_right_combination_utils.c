/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_combination_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:41:36 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/19 22:29:47 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_firstcombo_check(t_flags *flags, int count)
{
	if (flags->space && flags->width <= 1)
		return (ft_putchar(' '));
	if (flags->width)
	{
		if (flags->plus_sign)
		{
			if (!flags->left_justified)
				count += ft_pad_char(' ', flags->width - 1, 0);
			count += ft_putchar('+');
			if (flags->left_justified)
				count += ft_pad_char(' ', flags->width - 1, 0);
		}
		else
			count += ft_pad_char(' ', flags->width, 0);
	}
	else if (flags->plus_sign)
		count += ft_putchar('+');
	return (count);
}

int	ft_secondcombo_check(long nbr, t_flags *flags, int count)
{
	if (flags->width > ft_nbr_len(nbr))
	{
		if (flags->left_justified)
			count += ft_left_justify_nbr(nbr, flags);
		else
			count += ft_rigth_justify_nbr(nbr, flags);
	}
	else if (flags->width <= ft_nbr_len(nbr))
	{
		count += ft_handle_plus_space(nbr, 1, flags);
		if (nbr < 0)
		{
			count += write(1, "-", 1);
			nbr = -nbr;
		}
		if (flags->precision_value > ft_nbr_len(nbr))
			count += ft_pad_char('0', flags->precision_value
					- ft_nbr_len(nbr), nbr);
		count += ft_putnbr_long_precision(nbr, ft_nbr_len(nbr));
	}
	return (count);
}

int	ft_rightnbr_first_combos(long nbr, t_flags *flags, int count)
{
	if (flags->plus_sign)
	{
		if (nbr < 0)
			count += ft_pad_char('0', flags->width - ft_nbr_len(nbr), nbr);
		else
		{
			count += ft_handle_plus_space(nbr, 1, flags);
			count += ft_pad_char('0', flags->width
					- ft_nbr_len(nbr) - 1, nbr);
		}
	}
	else
		count += ft_pad_char('0', flags->width - ft_nbr_len(nbr), nbr);
	return (count);
}

int	ft_rightnbr_sec_combos(long nbr, t_flags *flags, int count)
{
	count += ft_handle_plus_space(nbr, 1, flags);
	if (nbr < 0)
		count += ft_pad_char('0', flags->width - ft_nbr_len(nbr), nbr);
	else
		count += ft_pad_char('0', flags->width - ft_nbr_len(nbr) - 1, nbr);
	return (count);
}

int	ft_rightnbr_full_combos(long nbr, t_flags *flags, int count)
{
	if (flags->zero_left_pad_sentinel && !flags->space)
		count += ft_rightnbr_first_combos(nbr, flags, count);
	else if (flags->zero_left_pad_sentinel && flags->space)
		count += ft_rightnbr_sec_combos(nbr, flags, count);
	else
	{
		if (flags->plus_sign && nbr >= 0)
		{
			count += ft_pad_char(' ', flags->width - ft_nbr_len(nbr) - 1, 0);
			count += ft_handle_plus_space(nbr, 1, flags);
		}
		else
			count += ft_pad_char(' ', flags->width - ft_nbr_len(nbr), 0);
	}
	if (nbr < 0 && !flags->zero_left_pad_sentinel)
		count += write (1, "-", 1);
	count += ft_putnbr_long_precision(nbr, ft_nbr_len(nbr));
	return (count);
}
