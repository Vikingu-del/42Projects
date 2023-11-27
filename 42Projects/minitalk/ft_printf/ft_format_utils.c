/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:03:35 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/19 22:15:52 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pad_char(char c, int bytes, long nbr)
{
	int	count;

	count = 0;
	if (bytes < 0)
		bytes = 0;
	if (nbr < 0)
		count += write (1, "-", 1);
	while (bytes--)
		count += ft_putchar(c);
	return (count);
}

int	ft_handle_plus_space(long nbr, int bytes, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->plus_sign && bytes && nbr >= 0)
		count += ft_putchar('+');
	else if (flags->space && !(flags->plus_sign) && nbr >= 0)
		count += ft_putchar(' ');
	return (count);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}
