/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:05:23 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/15 16:29:39 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * get the figures
 * in a digit
*/
int	ft_nbr_len(long nbr)
{
	if (nbr < 0)
		return (ft_nbr_len(nbr *= -1) + 1);
	else if (0 == nbr || (nbr > 0 && nbr < 10))
		return (1);
	else
		return (ft_nbr_len(nbr / 10) + 1);
}

/*
 * recursion that puts a long
 * returning the chars written
 * can handle how many bytes to write
 * '-' is considered a char(byte)
*/
int	ft_putnbr_long_precision(long nbr, int bytes)
{
	int	count;

	count = 0;
	if ((!bytes) || bytes <= 0)
		return (0);
	else if (nbr < 0 && bytes)
		return (ft_putnbr_long_precision(nbr *= -1, bytes - 1));
	else if (0 == nbr && bytes)
		return (write(1, "0", 1));
	else if ((nbr > 0 && nbr < 10) && bytes)
		return (ft_putchar(nbr + 48));
	else
	{
		count += ft_putnbr_long_precision(nbr / 10, bytes);
		if (bytes - (ft_nbr_len(nbr) - 1) > 0)
			bytes -= (ft_nbr_len(nbr) - 1);
		else
			return (count);
		ft_putnbr_long_precision(nbr % 10, bytes);
		return (count + 1);
	}
}
