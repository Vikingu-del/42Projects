/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:31:46 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/01 18:21:12 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	box1;
	int	box2;

	box1 = *a / *b;
	box2 = *a % *b;
	*a = box1;
	*b = box2;
}

/*int	main(void)
{
	int	a;
	int	b;

	a = 20;
	b = 15;
	printf("Start a = %d --> b = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("After a = %d --> b = %d\n", a, b);
}
*/