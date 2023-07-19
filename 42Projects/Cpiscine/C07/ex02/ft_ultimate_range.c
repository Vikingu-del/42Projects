/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:24:14 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/15 13:53:52 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*between;
	int	i;

	i = 0;
	if (min >= max)
	{
		between = NULL;
		return (0);
	}
	between = (int *)malloc(sizeof(int) * (max - min));
	if (!between)
		return (-1);
	while (min < max)
	{
		between[i] = min;
		min++;
		i++;
	}
	*range = between;
	return (i);
}
