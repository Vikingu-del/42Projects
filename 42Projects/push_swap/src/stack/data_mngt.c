/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_mngt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:39:56 by eseferi           #+#    #+#             */
/*   Updated: 2023/08/09 13:00:42 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// Initializes the main data structure, including both stacks 
// and the operations list.
void	init_data(t_ps *data, int argc, char **argv, bool writing_mode)
{
	init_stack(data, &data->a, argc);
	init_stack(data, &data->b, argc);
	fill_stack(data, &data->a, argc, argv);
	data->writing_mode = writing_mode;
	data->op_list = NULL;
}

// Initializes a stack, setting its initial size and filling it with zeros,
// for ensuring memory safety and establishing a consistent starting state.
void	init_stack(t_ps *data, t_stack *stk, int size)
{
	stk->stack = malloc(sizeof(int) * size);
	if (!stk->stack)
		error(data);
	stk->top = 0;
	stk->bottom = 0;
	stk->size = size;
	ft_memset(stk->stack, 0, sizeof(int) * size);
}

// Checks if a given stack is in sorted order 
// by comparing values to their ranks
bool	is_sorted(t_ps *data)
{
	int	i;
	int	rank;

	i = data->a.top;
	rank = 1;
	while (rank <= data->a.size)
	{
		if (data->a.stack[i] != rank)
			return (false);
		rank++;
		i = next_down(&data->a, i);
	}
	return (true);
}

// Frees allocated memory and exits the program with an error message.
void	error(t_ps *data)
{
	free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

// Frees allocated memory for stacks and the operations list.
void	free_data(t_ps *data)
{
	if (data->a.stack)
		free(data->a.stack);
	if (data->b.stack)
		free(data->b.stack);
	if (data->op_list)
		ft_lstclear(&data->op_list, NULL);
}
