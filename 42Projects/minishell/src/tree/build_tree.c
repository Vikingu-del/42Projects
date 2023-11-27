/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:31:42 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 11:22:05 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	process_tree_left(t_tree **tree, t_token *tmp_left, t_data *data)
{
	t_tree	*tmp_tree;

	tmp_tree = *tree;
	tmp_tree->left = init_tree_root();
	if (tmp_left->type)
		tmp_tree->left->type = tmp_left->type;
	if (tmp_left->word)
		tmp_tree->left->value = ft_strdup(tmp_left->word);
	ft_strdel(&tmp_left->word);
	tmp_left->word = ft_strdup("boundary");
	if (tmp_tree->left->type == T_WORD)
	{
		tmp_tree->left->args_array = ft_split_args(tmp_tree->left->value, ' ');
		find_quotes(tmp_tree->left->args_array, data);
	}
	if (built_tree(&tmp_tree->left, tmp_left, data))
		return (1);
	return (0);
}

static int	process_tree_right(t_tree **tree, t_token *tmp_right, t_data *data)
{
	t_tree	*tmp_tree;

	tmp_tree = *tree;
	tmp_tree->right = init_tree_root();
	tmp_tree->right->type = tmp_right->type;
	if (tmp_right->word)
	{
		tmp_tree->right->value = ft_strdup(tmp_right->word);
		ft_strdel(&tmp_right->word);
	}
	tmp_right->word = ft_strdup("boundary");
	if (tmp_tree->right->type == T_WORD)
	{
		tmp_tree->right->args_array = \
		ft_split_args(tmp_tree->right->value, ' ');
		find_quotes(tmp_tree->right->args_array, data);
	}
	if (built_tree(&tmp_tree->right, tmp_right, data))
		return (1);
	return (0);
}

static int	handle_right_node(t_tree **tree, t_token **address, t_data *data)
{
	t_token	*tmp_right;
	t_tree	*tmp_tree;

	tmp_right = find_tree_root_right(&(*address)->next);
	tmp_tree = *tree;
	if (tmp_right && tmp_right->type == T_PARENTHESES)
	{
		if (tokenise_for_tree(tmp_right, data))
			return (1);
		tmp_right = find_tree_root_right(&(*address)->next);
	}
	if (tmp_right && ft_strcmp(tmp_right->word, "boundary"))
	{
		if (process_tree_right(&tmp_tree, tmp_right, data))
			return (1);
	}
	else
		tmp_tree->right = NULL;
	return (0);
}

static int	handle_left_node(t_tree **tree, t_token **address, t_data *data)
{
	t_token	*tmp_left;
	t_tree	*tmp_tree;

	tmp_left = find_tree_root_left(&(*address)->prev);
	tmp_tree = *tree;
	if (tmp_left && tmp_left->type == T_PARENTHESES)
	{
		if (tokenise_for_tree(tmp_left, data))
			return (1);
		tmp_left = find_tree_root_left(&(*address)->prev);
	}
	if (tmp_left && ft_strcmp(tmp_left->word, "boundary"))
	{
		if (process_tree_left(&tmp_tree, tmp_left, data))
			return (1);
	}
	else
		tmp_tree->left = NULL;
	return (0);
}

int	built_tree(t_tree **tree, t_token *address, t_data *data)
{
	t_tree	*tmp_tree;

	tmp_tree = *tree;
	if (!address || address->type == T_NEWLINE)
		return (0);
	if (handle_left_node(&tmp_tree, &address, data))
		return (1);
	if (handle_right_node(&tmp_tree, &address, data))
		return (1);
	return (0);
}
