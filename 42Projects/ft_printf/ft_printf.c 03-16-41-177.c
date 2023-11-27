/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:55:26 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/13 00:35:42 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(va_list ap, t_flags *flags, char specifier)
{	
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar_format(va_arg(ap, int), flags);
	else if (specifier == 's')
		count += ft_putstr_format(va_arg(ap, char *), flags);
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr_format((long)(va_arg(ap, int)), flags);
	else if (specifier == 'u')
		count += ft_putunsigned_format(va_arg(ap, unsigned int), flags);
	else if (specifier == 'x' || specifier == 'X')
		count += ft_puthex_format((long)(va_arg(ap, unsigned int)), flags);
	else if (specifier == 'p')
		count += ft_putptr_format(va_arg(ap, void *), flags);
	else if (specifier == '%')
		count += write(1, "%", 1);
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *format_str, ...)
{
	va_list	ap;
	int		count;
	int		i;
	t_flags	flags;

	i = -1;
	count = 0;
	va_start(ap, format_str);
	while (format_str[++i])
	{
		ft_refresh_flags(&flags);
		if (format_str[i] == '%')
		{
			i = ft_parse_flags(format_str, i, &flags);
		}
		if (flags.specifier)
		{
			count += ft_print_format(ap, &flags, flags.specifier);
		}
		else
			count += (write(1, (format_str + i), 1));
	}
	va_end(ap);
	return (count);
}
