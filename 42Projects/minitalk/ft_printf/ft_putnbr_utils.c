/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:09:53 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/19 22:11:54 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cornercase_precision(long nbr, t_flags *flags)
{
	int	count;
	int	corner;

	if (flags->precision_value <= ft_nbr_len(nbr))
		corner = flags->width - ft_nbr_len(nbr);
	else
		corner = flags->width - flags->precision_value;
	if ((flags->precision_value >= ft_nbr_len(nbr) && nbr < 0)
		|| (flags->precision_value > ft_nbr_len(nbr) && flags->space)
		|| (flags->precision_value <= ft_nbr_len(nbr)
			&& flags->space && nbr >= 0)
		|| (flags->plus_sign && nbr >= 0))
		corner--;
	count = 0;
	count += ft_pad_char(' ', corner, 0);
	count += ft_handle_plus_space(nbr, 1, flags);
	if (nbr < 0)
		count += ft_pad_char('0', flags->precision_value
				- (ft_nbr_len(nbr) - 1), nbr);
	else
		count += ft_pad_char('0', flags->precision_value
				- ft_nbr_len(nbr), nbr);
	count += ft_putnbr_long_precision(nbr, ft_nbr_len(nbr));
	return (count);
}

int	ft_rigth_justify_nbr(long nbr, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->precision_point)
	{
		if (flags->precision_value >= flags->width)
		{
			count += ft_handle_plus_space(nbr, 1, flags);
			count += ft_pad_char('0', flags->precision_value
					- ft_nbr_len(nbr) + (nbr < 0), nbr);
			count += ft_putnbr_long_precision(nbr, ft_nbr_len(nbr));
		}
		else
			count += ft_cornercase_precision(nbr, flags);
	}
	else if (!flags->precision_point)
		count += ft_rightnbr_full_combos(nbr, flags, count);
	return (count);
}

int	ft_left_justify_nbr(long nbr, t_flags *flags)
{
	int	count;
	int	nbr_len;

	count = 0;
	nbr_len = ft_nbr_len(nbr);
	count += ft_handle_plus_space(nbr, 1, flags);
	if (flags->precision_point && flags->precision_value >= nbr_len)
		count += ft_left_fir_combos(nbr, flags, nbr_len);
	else
		count += ft_left_sec_combos(nbr, flags, nbr_len);
	return (count);
}

int	ft_putnbr_format(long nbr, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->precision_point && !flags->precision_value && nbr == 0)
		return (ft_firstcombo_check(flags, count));
	else
		return (ft_secondcombo_check(nbr, flags, count));
}

int	ft_putunsigned_format(unsigned int nbr, t_flags *flags)
{
	return (ft_putnbr_format((long)nbr, flags));
}
