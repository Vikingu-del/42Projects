/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 00:45:06 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/01 19:38:46 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	mem;
	void	*ptr;

	mem = count * size;
	if (count > 0 && size > 0 && count <= SIZE_MAX / size)
	{
		ptr = malloc(mem);
		if (!ptr)
			return (NULL);
		ft_memset(ptr, 0, mem);
	}
	else if (count == 0 && size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ft_memset(ptr, 0, 1);
	}
	else
		ptr = NULL;
	return (ptr);
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
//     int *arr;
//     size_t count = 5;
//     size_t size = sizeof(int);

//     arr = (int *)ft_calloc(count, size);

//     if (arr != NULL)
//     {
//         for (size_t i = 0; i < count; i++)
//         {
//             printf("%d ", arr[i]);
//         }
//         printf("\n");

//         free(arr);
//     }

//     return 0;
// }