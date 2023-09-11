/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:38:19 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/11 18:25:55 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunk_sort(t_ps *data)
{
	t_chunk	chunk_all;

	chunk_all.loc = TOP_A;
	chunk_all.size = data->a.size;
	rec_chunk_sort(data, &chunk_all);
}

void	rec_chunk_sort(t_ps *data, t_chunk *to_sort)
{
	t_split_dest	dest;

	chunk_to_the_top(data, to_sort);
	easy_sort(data, to_sort);
	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
			sort_three(data, to_sort);
		else if (to_sort->size == 2)
			sort_two(data, to_sort);
		else if (to_sort->size == 1)
			sort_one(data, to_sort);
		return ;
	}
	chunk_split(data, to_sort, &dest);
	rec_chunk_sort(data, &dest.max);
	rec_chunk_sort(data, &dest.mid);
	rec_chunk_sort(data, &dest.min);
}

void	sort_two(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B
		|| to_sort->loc == TOP_B)
	{
		move_from_to(data, to_sort->loc, TOP_A);
		move_from_to(data, to_sort->loc, TOP_A);
	}
	if (value(&data->a, 1) > value(&data->a, 2))
		swap_a(data);
	to_sort->size -= 2;
}

// move a single element from its current location (to_sort->loc) to the top of 
// Stack A (TOP_A). After the move,the size of the chunk to_sort is decremented 
// by 1, indicating that one element has been sorted. 
void	sort_one(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->loc == BOTTOM_A || to_sort->loc == BOTTOM_B
		|| to_sort->loc == TOP_B)
		move_from_to(data, to_sort->loc, TOP_A);
	to_sort->size -= 1;
}
