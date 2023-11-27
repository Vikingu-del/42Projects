/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:20:50 by ipetruni          #+#    #+#             */
/*   Updated: 2023/11/23 13:22:02 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_2darray(char **array)
{
	int	i;

	i = -1;
	if (!array)
		return ;
	while (array[++i])
		ft_strdel(&array[i]);
	free(array);
	array = NULL;
}

void	free_tree(t_tree **tree)
{
	int		i;
	t_tree	*temp_tree;
	t_tree	*left;
	t_tree	*right;

	temp_tree = *tree;
	left = NULL;
	right = NULL;
	i = 0;
	if (!temp_tree)
		return ;
	if (temp_tree->value)
		ft_strdel(&temp_tree->value);
	if (temp_tree->args_array && *temp_tree->args_array)
		free_2darray(temp_tree->args_array);
	left = temp_tree->left;
	right = temp_tree->right;
	free(temp_tree);
	free_tree(&left);
	free_tree(&right);
}
