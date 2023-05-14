/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:12:50 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/10 17:47:12 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*range;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	size = max - min;
	range = (int *)malloc(size * sizeof(int));
	if (range == NULL)
		return (NULL);
	while (i < size)
	{
		range[i] = min++;
		i++;
	}
	return (range);
}

/*
#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max);

int main(void)
{
    int min = -5;
    int max = 10;
    int *range = ft_range(min, max);

    if (range == NULL)
    {
        printf("Invalid range: min is greater than or equal to max.\n");
        return 0;
    }

    int size = max - min;
    printf("Range: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", range[i]);
    }
    printf("\n");

    free(range);

    return 0;
}
*/