/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:40:12 by eseferi           #+#    #+#             */
/*   Updated: 2023/08/08 16:40:14 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// Shifts the elements of a stack upwards, making the top element the bottom.
void	rotate(t_stack *stk)
{
	if (is_full(stk))
	{
		stk->bottom = stk->top;
		stk->top = next_down(stk, stk->top);
	}
	else
	{
		stk->bottom = next_down(stk, stk->bottom);
		stk->stack[stk->bottom] = stk->stack[stk->top];
		stk->stack[stk->top] = 0;
		stk->top = next_down(stk, stk->top);
	}
}

// Rotates stack a and logs the operation.
void	rotate_a(t_ps *data)
{
	rotate(&data->a);
	if (data->writing_mode)
		save_op(data, ra);
}

// Rotates stack b and logs the operation.
void	rotate_b(t_ps *data)
{
	rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rb);
}

// Rotates both stacks and logs the operation.
void	rotate_ab(t_ps *data)
{
	rotate(&data->a);
	rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rr);
}
