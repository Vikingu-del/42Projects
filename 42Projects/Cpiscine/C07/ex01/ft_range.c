/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:00:57 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/15 13:53:43 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*between;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	between = (int *)malloc(sizeof(int) * (max - min));
	if (between == NULL)
		return (NULL);
	while (min < max)
	{
		between[i] = min;
		min++;
		i++;
	}
	return (between);
}

// int main()
// {
// 	int	num = -41;
// 	int num1 = 41;
// 	int *arrint;
// 	int i;
// 	i = 0;
// 	arrint = ft_range(num, num1);
// 	while(i < (num1 - num))
// 	{
// 		printf("%d", arrint[i]);
// 		i++;
// 	}
// 	free(arrint);
// 	return (0);
// }