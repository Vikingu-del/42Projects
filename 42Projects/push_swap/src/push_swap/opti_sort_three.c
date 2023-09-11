/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_sort_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:39:23 by eseferi           #+#    #+#             */
/*   Updated: 2023/08/08 16:39:25 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Based on the location of a chunk of 3 elements,sends the chunk to the top of 
// stack a, finds the maximum value of the chunk, it sends to the third position
// and then after, uses sort_two to sort the first two elements.
void	sort_three(t_ps *data, t_chunk *to_sort)
{
	t_stack	*stk;
	int		max;

	stk = loc_to_stack(data, to_sort->loc);
	max = chunk_max_value(data, to_sort);
	if (to_sort->loc == TOP_A)
		sort_three_top_a(data, to_sort, stk, max);
	else if (to_sort->loc == BOTTOM_A)
		sort_three_bottom_a(data, to_sort, stk, max);
	else if (to_sort->loc == TOP_B)
		sort_three_top_b(data, to_sort, stk, max);
	else if (to_sort->loc == BOTTOM_B)
		sort_three_bottom_b(data, to_sort, stk, max);
}

void	sort_three_top_a(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	if (stk->stack[stk->top] == max)
	{
		swap_a(data);
		rotate_a(data);
		swap_a(data);
		r_rotate_a(data);
	}
	else if (stk->stack[next_down(stk, stk->top)] == max)
	{
		rotate_a(data);
		swap_a(data);
		r_rotate_a(data);
	}
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	sort_three_top_b(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	push_a(data);
	if (stk->stack[stk->top] == max)
	{
		push_a(data);
		swap_a(data);
	}
	else if (stk->stack[next_down(stk, stk->top)] == max)
	{
		swap_b(data);
		push_a(data);
		swap_a(data);
	}
	else
		push_a(data);
	push_a(data);
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	sort_three_bottom_a(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	r_rotate_a(data);
	r_rotate_a(data);
	if (stk->stack[stk->top] == max)
	{
		swap_a(data);
		r_rotate_a(data);
	}
	else if (stk->stack[next_down(stk, stk->top)] == max)
		r_rotate_a(data);
	else
	{
		push_b(data);
		r_rotate_a(data);
		swap_a(data);
		push_a(data);
	}
	to_sort->loc = TOP_A;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}

void	sort_three_bottom_b(t_ps *data, t_chunk *to_sort, t_stack *stk, int max)
{
	r_rotate_b(data);
	r_rotate_b(data);
	if (stk->stack[stk->top] == max)
	{
		push_a(data);
		r_rotate_b(data);
	}
	else if (stk->stack[next_down(stk, stk->top)] == max)
	{
		swap_b(data);
		push_a(data);
		r_rotate_b(data);
	}
	else
	{
		r_rotate_b(data);
		push_a(data);
	}
	to_sort->loc = TOP_B;
	to_sort->size -= 1;
	sort_two(data, to_sort);
}
