/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:02:59 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/08 17:09:42 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	str_index;
	int	ndle_index;

	str_index = 0;
	ndle_index = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[str_index] != '\0')
	{
		while ((str[str_index + ndle_index] == to_find[ndle_index])
			&& (str[str_index + ndle_index] != '\0'))
		{
			ndle_index++;
		}
		if (to_find[ndle_index] == '\0')
			return (&str[str_index]);
		str_index++;
		ndle_index = 0;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	char str[] = "Hello World";
// 	char to_find[] = "or";
// 	printf("%s", ft_strstr(str, to_find));
// 	return (0);
// }