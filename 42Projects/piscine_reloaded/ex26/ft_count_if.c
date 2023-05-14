/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:47:37 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/12 14:15:21 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	count;

	count = 0;
	while (*tab)
	{
		if (f(*tab))
			count++;
		tab++;
	}
	return (count);
}

/*
#include <stdio.h>

int starts_with_a(char *str)
{
	return (str[0] == 'a');
}

int main(void)
{
	char *words[] = {"apple", "orange", "asterisk", "planets", "physics", NULL};
	int count = ft_count_if(words, &starts_with_a);
	printf("Number of words starting with 'a': %d\n", count);
	return(0);
}
*/