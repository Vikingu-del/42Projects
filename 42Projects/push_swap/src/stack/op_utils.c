/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:40:22 by eseferi           #+#    #+#             */
/*   Updated: 2023/08/08 16:40:24 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// Saves a given operation to the operation list in the main data structure.
void	save_op(t_ps *data, enum e_op op)
{
	t_list	*new;

	new = ft_lstnew((void *)(uintptr_t)op);
	if (!new)
		error(data);
	ft_lstadd_back(&data->op_list, new);
}

// Iterates through the operation list and prints each operation.
void	print_operations(t_list *head)
{
	t_list	*reader;

	reader = head;
	while (reader)
	{
		ft_printf("%s\n", op_to_string(op_from(reader)));
		reader = reader->next;
	}
}

// Converts an operation to its string representation.
const char	*op_to_string(enum e_op op)
{
	static const char	*strings[12];

	strings[0] = "null_op";
	strings[1] = "pa";
	strings[2] = "pb";
	strings[3] = "ra";
	strings[4] = "rb";
	strings[5] = "rr";
	strings[6] = "rra";
	strings[7] = "rrb";
	strings[8] = "rrr";
	strings[9] = "sa";
	strings[10] = "sb";
	strings[11] = "ss";
	return (strings[op]);
}

// Converts a list node's content to its corresponding operation.
enum e_op	op_from(t_list *node)
{
	return ((enum e_op)(uintptr_t)node->content);
}
