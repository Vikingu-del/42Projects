/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:09:55 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/01 16:25:00 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	res *= sign;
	return (res);
}

// #include <stdio.h>

// int	ft_atoi(const char *str);

// int	main(void)
// {
// 	char *test_cases[] = {
// 		"12345",
// 		"-9876",
// 		"0",
// 		"  42",
// 		"   +786",
// 		"   -999",
// 		"2147483647",
// 		"-2147483648",
// 		"12a34",
// 		"hello",
// 		"9876543210",
// 		"12345678901234567890",
// 		NULL
// 	};

// 	int i = 0;
// 	while (test_cases[i])
// 	{
// 		int result = ft_atoi(test_cases[i]);
// 		printf("String: \"%s\", Result: %d\n", test_cases[i], result);
// 		i++;
// 	}

// 	return 0;
// }