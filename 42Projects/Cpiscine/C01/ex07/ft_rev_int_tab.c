/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:13:34 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/01 18:21:30 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	box1;
	int	box2;
	int	index;

	index = 0;
	while (index < size / 2)
	{
		box1 = tab[index];
		box2 = tab[size - 1 - index];
		tab[index] = box2;
		tab[size - 1 - index] = box1;
		index++;
	}
}

/*int	main(void)
{
	int	numb[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int	index = 0;
	printf("Start Value: ");
	while (index < 10)
	{
		printf("%d ", numb[index]);
		index++;
	}

	index = 0;
	ft_rev_int_tab(&numb[0], 10);
	printf("\nEnd Value: ");
	while (index < 10)
	{
		printf("%d ", numb[index]);
		index++;
	}
	printf("\n");
	return (0);
}
*/