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

// inits the t_ps *data that will has stack a, b a bool value and the linked 
// lists which will store all the operations
void	init_data(t_ps *data, int argc, char **argv, bool writing_mode)
{
	init_stack(data, &data->a, argc);
	init_stack(data, &data->b, argc);
	fill_stack(data, &data->a, argc, argv);
	data->writing_mode = writing_mode;
	data->op_list = NULL;
}

// it will init the stacks with the size of the nr of arguments and sets 
// top and bottom to 0 since we dont have any for the moment
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

void	error(t_ps *data)
{
	free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	free_data(t_ps *data)
{
	if (data->a.stack)
		free(data->a.stack);
	if (data->b.stack)
		free(data->b.stack);
	if (data->op_list)
		ft_lstclear(&data->op_list, NULL);
}
