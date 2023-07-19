/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:07:10 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/01 18:21:07 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 25;
	b = 4;
	div = 15;
	mod = 30;
	printf("Star. values: a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
	ft_div_mod(a, b, &div, &mod);
	printf("Aft. values: a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
}
*/