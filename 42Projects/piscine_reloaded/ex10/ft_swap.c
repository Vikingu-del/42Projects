/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:12:53 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/09 18:16:16 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
#include <stdio.h>

void ft_swap(int *a, int *b);

int main(void)
{
    int a = 5;
    int b = 10;

    printf("Before swap: a = %d, b = %d\n", a, b);
    ft_swap(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);

    return 0;
}
*/