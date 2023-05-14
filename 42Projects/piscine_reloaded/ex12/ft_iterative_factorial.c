/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:23:55 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/09 18:43:01 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0 || nb > 12)
		return (0);
	while (nb > 0)
	{
		result *= nb;
		nb--;
	}
	return (nb);
}

//We dont check for 12! because it would be overflowing
/*
#include <stdio.h>
#include <time.h>

int ft_iterative_factorial(int nb);

int main(void)
{
    int n, result;
    clock_t t1, t2;
    double time_taken;

    printf("Enter a number between 0 and 12: ");
    scanf("%d", &n);

    t1 = clock();
    result = ft_iterative_factorial(n);
    t2 = clock();

    time_taken = ((double)(t2 - t1)) / CLOCKS_PER_SEC;

    if (result == 0)
        printf("Error: The number should be between 0 and 12.\n");
    else
        printf("%d! = %d\n", n, result);

    printf("Time taken: %lf seconds.\n", time_taken);

    return 0;
}
*/