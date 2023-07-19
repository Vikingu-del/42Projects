/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:26:00 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/12 01:08:44 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if ('a' <= str[0] && str[0] <= 'z')
	{
		str[0] -= 32;
	}
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z')
			&& !(str[i] >= 'A' && str[i] <= 'Z')
			&& !(str[i] >= '0' && str[i] <= '9'))
		{
			if ((str[i + 1] >= 'a') && (str[i + 1] <= 'z'))
				str[i + 1] -= 32;
		}
		else if (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
			str[i + 1] += 32;
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char s[] = "47ez30R7|<3.Kv#Sd9mw* $";
// 	ft_strcapitalize(s);
// 	printf("%s", s);
// 	return (0);
// }
