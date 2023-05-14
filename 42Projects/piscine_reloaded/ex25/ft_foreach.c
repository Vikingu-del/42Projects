/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:31:02 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/10 22:33:28 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}

/*
#include <stdio.h>

void print_int(int num)
{
	printf("%d ", num);
}

int main(void)
{
    int tab[] = {1, 2, 3, 4, 5};
    int length = sizeof(tab) / sizeof(tab[0]);

    ft_foreach(tab, length, &print_int);

    return 0;
}
*/