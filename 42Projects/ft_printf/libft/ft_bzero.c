/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:59:12 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/01 16:26:34 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (len > 0)
	{
		*ptr = '\0';
		ptr++;
		len--;
	}
}

// #include <stdio.h>
// #include <string.h>

// void	ft_bzero(void *s, size_t len);

// int	main(void)
// {
// 	char str[10] = "Hello";
// 	printf("Before ft_bzero: \"%s\"\n", str);

// 	ft_bzero(str, sizeof(str));
// 	printf("After ft_bzero: \"%s\"\n", str);

// 	return 0;
// }