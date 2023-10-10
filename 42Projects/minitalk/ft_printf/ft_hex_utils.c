/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:13:05 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/19 22:22:09 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long hex_value)
{
	if (hex_value >= 0 && hex_value < 16)
		return (1);
	return (ft_hex_len(hex_value / 16) + 1);
}

int	ft_check_hash(t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->is_upper)
		count += write(1, "0X", 2);
	else
		count += write(1, "0x", 2);
	flags->hash = 0;
	return (count);
}

int	ft_puthex(unsigned long hex_value, t_flags *flags)
{
	char	*symbols;
	int		count;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (flags->hash && hex_value != 0)
		count += ft_check_hash(flags);
	if (hex_value >= 0 && hex_value < 16)
	{
		if (flags->is_upper || hex_value < 10)
			count += ft_putchar(symbols[hex_value]);
		else
			count += ft_putchar(symbols[hex_value] + 32);
	}
	else
	{	
		count += ft_puthex(hex_value / 16, flags);
		count += ft_puthex(hex_value % 16, flags);
	}
	return (count);
}
