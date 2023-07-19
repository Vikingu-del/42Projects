/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 04:57:04 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/01 18:21:03 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	box;

	box = *a;
	*a = *b;
	*b = box;
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 4;
	b = 8;
	printf("In the beggining: \n a: %d, b: %d\n", a, b);
	ft_swap(&a, &b);
	printf("After swapping: \n a: %d, b: %d\n", a, b);
}
*/