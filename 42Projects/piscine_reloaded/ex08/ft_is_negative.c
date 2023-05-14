/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:05:53 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/09 17:30:01 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar('N');
	else
		ft_putchar('P');
}

/*
int main(void)
{
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    printf("The sign of %d is: ", n);
    fflush(stdout); // flush the output buffer
	ft_is_negative(n);
    printf("\n");

    return 0;
}
*/