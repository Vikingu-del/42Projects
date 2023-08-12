/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:39:32 by eseferi           #+#    #+#             */
/*   Updated: 2023/08/11 20:15:49 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	data;
	char	**quotation_str;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_putendl_fd("Error", 2), 1);
	else if (argc == 2)
	{
		quotation_str = ft_split(argv[1], ' ');
		init_data(&data, ft_countwords(argv[1], ' '), quotation_str, true);
		free(quotation_str);
	}
	else
		init_data(&data, --argc, ++argv, true);
	sort(&data);
	print_operations(data.op_list);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
