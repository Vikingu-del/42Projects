/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:38:39 by eseferi           #+#    #+#             */
/*   Updated: 2023/08/08 16:38:42 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// It returns the value at the n-th position within the specified chunk.
// if the chunk is at the top, the function moves "down" the stack (next_down) 
// to find the n-th element. If the chunk is at the bottom, the function moves 
// "up" (next_up) to find the n-th element. 
int	chunk_value(t_ps *data, t_chunk *chunk, int n)
{
	enum e_loc	loc;
	t_stack		*stk;
	int			i;

	loc = chunk->loc;
	stk = loc_to_stack(data, loc);
	if (loc == TOP_A || loc == TOP_B)
		i = stk->top;
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		i = stk->bottom;
	if (loc == TOP_A || loc == TOP_B)
		while (--n > 0)
			i = next_down(stk, i);
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		while (--n > 0)
			i = next_up(stk, i);
	return (stk->stack[i]);
}

// calculates and returns the maximum value within a specified chunk of a stack.
int	chunk_max_value(t_ps *data, t_chunk *chunk)
{
	t_stack	*stk;
	int		size;
	int		max_value;
	int		i;

	stk = loc_to_stack(data, chunk->loc);
	size = chunk->size;
	max_value = 0;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		i = stk->top;
	else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		i = stk->bottom;
	while (size--)
	{
		if (stk->stack[i] > max_value)
			max_value = stk->stack[i];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			i = next_down(stk, i);
		else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
			i = next_up(stk, i);
	}
	return (max_value);
}

// Maps a location (loc) to the appropriate stack (t_stack). 
t_stack	*loc_to_stack(t_ps *data, enum e_loc loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
		return (&data->a);
	else
		return (&data->b);
}
