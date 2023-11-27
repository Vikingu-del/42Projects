/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_tree2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 08:23:01 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 08:23:29 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fix_tree(t_tree **tree)
{
	fix_command(tree);
	fix_redirection(tree);
}

void	connect_nodes(t_tree **temp_redir, t_tree *temp2)
{
	t_tree	*last_redir;

	if (*temp_redir == NULL)
	{
		*temp_redir = temp2;
		(*temp_redir)->right = NULL;
	}
	else
	{
		last_redir = *temp_redir;
		while (last_redir->right)
			last_redir = last_redir->right;
		last_redir->right = temp2;
		temp2->right = NULL;
	}
}

void	process_tree_nodes(t_tree **tree)
{
	t_tree	*temp;
	t_tree	*temp_redir;
	t_tree	*temp2;

	temp = *tree;
	temp_redir = (*tree)->left;
	while (temp && temp->right && temp->right->type != T_NEWLINE)
	{
		if (temp->right->type == T_DELIM || temp->right->type == T_RED_INP)
		{
			temp2 = temp->right;
			temp->right = temp2->right;
			connect_nodes(&temp_redir, temp2);
		}
		else
			temp = temp->right;
	}
	(*tree)->left = temp_redir;
}

void	fix_redirection(t_tree **tree)
{
	t_tree	*temp;
	t_tree	*temp_redir;

	temp = NULL;
	temp_redir = NULL;
	if (!tree || !*tree)
		return ;
	if ((*tree)->type == T_WORD)
		process_tree_nodes(tree);
	else
	{
		fix_redirection(&(*tree)->left);
		fix_redirection(&(*tree)->right);
	}
}

void	fix_command(t_tree **tree)
{
	if (!tree || !*tree)
		return ;
	if ((*tree)->type == T_APPEND || (*tree)->type == T_DELIM
		|| (*tree)->type == T_RED_INP || (*tree)->type == T_RED_OUT
		|| (*tree)->type == T_WORD)
		process_fix_com(tree);
	else
	{
		fix_command(&(*tree)->left);
		fix_command(&(*tree)->right);
	}
}
