/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:41:03 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/11 19:14:06 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_ps	data;
	char	**quotation_str;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_putendl_fd("Error", 2), 1);
	else if (argc == 2)
	{
		quotation_str = ft_split(argv[1], ' ');
		init_data(&data, ft_countwords(argv[1], ' '), quotation_str, false);
		free(quotation_str);
	}
	else
		init_data(&data, --argc, ++argv, false);
	if (data.a.size == 0)
		exit(EXIT_SUCCESS);
	read_op(&data);
	if (test_sort(&data))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_data(&data);
	exit(EXIT_SUCCESS);
}

void	read_op(t_ps *data)
{
	t_list	*new;
	int		gnl_status;
	char	*line;
	int		line_status;

	gnl_status = 0;
	line_status = 1;
	line = malloc(sizeof(char) * 5);
	if (!line)
		error_read_op(data, line);
	while (line_status)
	{
		gnl_status = get_next_line_ps(0, line);
		if (gnl_status == EXIT_FAILURE)
			error_read_op(data, line);
		line_status = ft_strlen(line);
		if (line_status == 0)
			break ;
		new = ft_lstnew((void *)(uintptr_t)string_to_op(line));
		if (!new)
			error_read_op(data, line);
		ft_lstadd_back(&data->op_list, new);
	}
	free(line);
}

bool	test_sort(t_ps *data)
{
	t_list	*reader;

	reader = data->op_list;
	while (reader)
	{
		call_op(data, (enum e_op)(uintptr_t)reader->content);
		reader = reader->next;
	}
	return (is_full(&data->a) && is_sorted(data));
}
