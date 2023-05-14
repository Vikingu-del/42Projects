/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:44:24 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/10 01:36:48 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
#include <stdio.h>

int ft_strlen(char *str);

int main() {
    char str1[] = "Hello, world!";
    char str2[] = "";
    char str3[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";

    printf("Length of str1: %d\n", ft_strlen(str1));
    printf("Length of str2: %d\n", ft_strlen(str2));
    printf("Length of str3: %d\n", ft_strlen(str3));

    return 0;
}
*/