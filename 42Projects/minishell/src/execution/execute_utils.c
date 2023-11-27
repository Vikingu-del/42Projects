/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:08:37 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 10:52:54 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_logic_root(t_tree *tree)
{
	return (tree->type == T_AND || tree->type == T_OR);
}

int	is_word_root(t_tree *tree)
{
	return (tree->type == T_WORD);
}

int	is_special_root(t_tree *tree)
{
	return (tree->type == T_RED_INP
		|| tree->type == T_RED_OUT
		|| tree->type == T_APPEND || tree->type == T_DELIM
		|| tree->type == T_THREE_IN);
}

int	is_only_asterisks(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i++] != '*')
			return (0);
	}
	return (1);
}
