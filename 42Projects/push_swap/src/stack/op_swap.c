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

void	swap(t_stack *stk)
{
	int	tmp;

	if (stk->stack[next_down(stk, stk->top)] == 0)
		return ;
	tmp = stk->stack[next_down(stk, stk->top)];
	stk->stack[next_down(stk, stk->top)] = stk->stack[stk->top];
	stk->stack[stk->top] = tmp;
}

void	swap_a(t_ps *data)
{
	swap(&data->a);
	if (data->writing_mode)
		save_op(data, sa);
}

void	swap_b(t_ps *data)
{
	swap(&data->b);
	if (data->writing_mode)
		save_op(data, sb);
}

void	swap_ab(t_ps *data)
{
	swap(&data->a);
	swap(&data->b);
	if (data->writing_mode)
		save_op(data, ss);
}
