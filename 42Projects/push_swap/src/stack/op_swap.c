/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:40:17 by eseferi           #+#    #+#             */
/*   Updated: 2023/08/08 16:40:19 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// Exchanges the positions of the top two elements of a given stack.
void	swap(t_stack *stk)
{
	int	tmp;

	if (stk->stack[next_down(stk, stk->top)] == 0)
		return ;
	tmp = stk->stack[next_down(stk, stk->top)];
	stk->stack[next_down(stk, stk->top)] = stk->stack[stk->top];
	stk->stack[stk->top] = tmp;
}

// Exchanges the positions of the top two elements of stack a,
// and logs the operation.
void	swap_a(t_ps *data)
{
	swap(&data->a);
	if (data->writing_mode)
		save_op(data, sa);
}

// Exchanges the positions of the top two elements of stack b,
// and logs the operation.
void	swap_b(t_ps *data)
{
	swap(&data->b);
	if (data->writing_mode)
		save_op(data, sb);
}

// Does the swap for both stacks in the same time and logs 
// the operation
void	swap_ab(t_ps *data)
{
	swap(&data->a);
	swap(&data->b);
	if (data->writing_mode)
		save_op(data, ss);
}
