/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 00:22:30 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/10 00:28:52 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

/*
#include <stdio.h>

int ft_sqrt(int nb);

int main(void)
{
    int nb;

    printf("Enter a number: ");
    scanf("%d", &nb);

    int result = ft_sqrt(nb);

    if (result == 0)
        printf("The square root of %d is irrational.\n", nb);
    else
        printf("The square root of %d is %d.\n", nb, result);

    return 0;
}
*/