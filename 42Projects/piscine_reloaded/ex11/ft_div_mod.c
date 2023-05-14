/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:17:28 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/09 18:22:40 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod);

int	main(void)
{
    int a = 17;
    int b = 5;
    int div, mod;

    ft_div_mod(a, b, &div, &mod);

    printf("%d divided by %d is %d with a remainder of %d\n", a, b, div, mod);

    return 0;
}
*/