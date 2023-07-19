/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:49:00 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/08 19:23:51 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (index < n && ((s1[index] != '\0') && (s2[index] != '\0')))
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	if (index < n)
		return (s1[index] - s2[index]);
	else
		return (0);
}

// int main() {
//   char str1[] = "abcde", str2[] = "Abcd", str3[] = "abcdef";
//   int result;

//   // comparing strings str1 and str2
//   result = ft_strncmp(str1, str2, 4);
//   printf("ft_strncmp(str1, str2) = %d\n", result);

//   // comparing strings str1 and str3
//   result = ft_strncmp(str1, str3, 5);
//   printf("ft_strncmp(str1, str3) = %d\n", result);

//   return 0;
// }