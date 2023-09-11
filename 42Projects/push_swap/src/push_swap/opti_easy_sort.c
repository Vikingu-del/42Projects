/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_easy_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:38:54 by eseferi           #+#    #+#             */
/*   Updated: 2023/08/08 16:38:57 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// It checks the top of the stack and compares it with the smallest and second 
// smallest elements of the chunk. If a straightforward sort is possible, it 
// performs it; otherwise, it exits the loop.
void	easy_sort(t_ps *data, t_chunk *to_sort)
{
	while (to_sort->loc != TOP_A && to_sort->size)
	{
		if (value(&data->a, 1) == chunk_value(data, to_sort, 1) + 1
			&& to_sort->size > 0)
			sort_one(data, to_sort);
		else if (value(&data->a, 1) == chunk_value(data, to_sort, 2) + 1
			&& to_sort->size > 1)
			easy_sort_second(data, to_sort);
		else
			break ;
	}
}

void	easy_sort_second(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->loc == TOP_B)
		handle_top_b(data, to_sort);
	else if (to_sort->loc == BOTTOM_A)
		handle_bottom_a(data, to_sort);
	else if (to_sort->loc == BOTTOM_B)
		handle_bottom_b(data, to_sort);
	to_sort->size--;
}

void	handle_top_b(t_ps *data, t_chunk *to_sort)
{
	swap_b(data);
	push_a(data);
	if (value(&data->b, 1) == value(&data->a, 1) - 1)
	{
		push_a(data);
		to_sort->size--;
	}
}

void	handle_bottom_a(t_ps *data, t_chunk *to_sort)
{
	r_rotate_a(data);
	r_rotate_a(data);
	swap_a(data);
	if (value(&data->a, 1) == value(&data->a, 2) - 1)
		to_sort->size--;
	else
		rotate_a(data);
}

void	handle_bottom_b(t_ps *data, t_chunk *to_sort)
{
	r_rotate_b(data);
	r_rotate_b(data);
	push_a(data);
	if (value(&data->b, 1) == value(&data->a, 1) - 1)
	{
		push_a(data);
		to_sort->size--;
	}
	else
		rotate_b(data);
}
