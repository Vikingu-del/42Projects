/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 01:20:36 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/01 16:28:28 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digitlen(long int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	i = ft_digitlen(nb);
	str = ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (0);
	str[i--] = 0;
	if (nb == 0)
	{
		str[0] = '0';
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int num = 12345;
//     char *str;

//     str = ft_itoa(num);

//     if (str != NULL)
//     {
//         printf("Number: %d\n", num);
//         printf("String: %s\n", str);

//         free(str);
//     }

//     return 0;
// }