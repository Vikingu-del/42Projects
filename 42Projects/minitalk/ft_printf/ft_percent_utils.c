/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:23:44 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/19 22:32:17 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent_format(char c, t_flags *flags)
{
	int	count;

	count = 0;
	if (c == '%')
	{
		if (flags->width > 1)
		{
			if (flags->left_justified)
			{
				count += write(1, "%", 1);
				count += ft_pad_char(' ', flags->width - 1, 0);
			}
			else
			{
				count += ft_pad_char(' ', flags->width - 1, 0);
				count += write(1, "%", 1);
			}
		}
		else
			count += write(1, "%", 1);
	}
	return (count);
}
