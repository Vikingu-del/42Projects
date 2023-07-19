/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:45:58 by eseferi           #+#    #+#             */
/*   Updated: 2023/07/18 21:37:50 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	box1;
	int	box2;
	int	index;
	int	index1;

	index = 0;
	index1 = 0;
	while (index1 < size)
	{
		while (index < size)
		{
			if (tab[index] > tab[index + 1])
			{
				box1 = tab[index];
				box2 = tab[index + 1];
				tab[index] = box2;
				tab[index + 1] = box1;
			}
			index++;
		}
		index = 0;
		index1++;
	}
}

// int main()
// {
//     int arr[5] = {-10, 2, -3, 1, 0};
// 	printf("Start values: ");
// 	for (int i = 0; i < 5; i++)
//     {
//         printf("%d, ", arr[i]);
//     }
//     ft_sort_int_tab(arr, 5);
// 	printf("\nEnd values: ");
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d, ", arr[i]);
//     }
// 	printf("\n");
// }