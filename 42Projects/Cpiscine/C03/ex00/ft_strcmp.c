/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:54:05 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/08 12:45:38 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>
// #include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while ((s1[index] != '\0') && (s2[index] != '\0'))
	{
		if (s1[index] != s2[index])
			return (s1[index] - s2[index]);
		index++;
	}
	return (s1[index] - s2[index]);
}

// int main() {
//   char str1[] = "abcd", str2[] = "AbCd", str3[] = "abcd";
//   int result;

//   // comparing strings str1 and str2
//   result = ft_strcmp(str1, str2);
//   printf("ft_strcmp(str1, str2) = %d\n", result);

//   // comparing strings str1 and str3
//   result = ft_strcmp(str1, str3);
//   printf("ft_strcmp(str1, str3) = %d\n", result);

//   return 0;
// }
// The code compares two strings, and returns the difference 
// in characters. The code starts by comparing the first character 
// of each string, then compares every other character until it 
// finds a 0 at the end of one string or another. Then it returns 
// that number as its result.