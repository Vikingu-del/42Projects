/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 01:39:48 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/10 01:49:47 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
#include <stdio.h>

int ft_strcmp(char *s1, char *s2);

int main(void) {
    char str1[] = "hello";
    char str2[] = "world";
    char str3[] = "hello";
    
    printf("Comparing str1 and str2: %d\n", ft_strcmp(str1, str2));
    printf("Comparing str1 and str3: %d\n", ft_strcmp(str1, str3));
    printf("Comparing str3 and str2: %d\n", ft_strcmp(str2, str3));
    
    return 0;
}
*/