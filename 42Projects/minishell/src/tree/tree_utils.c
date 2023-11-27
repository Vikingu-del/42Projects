/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 08:46:15 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 09:29:42 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree	*init_tree_root(void)
{
	t_tree	*tree;

	tree = malloc(sizeof(t_tree));
	if (!tree)
		return (NULL);
	tree->type = 0;
	tree->value = NULL;
	tree->args_array = NULL;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}

int	is_special_type(t_token *address)
{
	return (address->type == T_RED_INP
		|| address->type == T_RED_OUT
		|| address->type == T_APPEND
		|| address->type == T_DELIM
		|| address->type == T_THREE_IN);
}

// void print_tree(t_tree *tree, int depth)
// {
// 	if (!tree)
// 		return;
// 	for (int i = 0; i < depth; i++)
// 		printf("\t");
// 	printf("Node word: :%s:, type: %d\n", tree->value, tree->type);
// 	if (tree->parenth == 1)
//     {
//         for (int i = 0; i < depth; i++)
//             printf("\t");
//         printf("Parenth on\n");
//     }
// 	if (tree->type == T_WORD || tree->type == T_DELIM) 
// 	{
// 		if (tree->args_array)
// 		{
// 			printf("Args array: ");
// 			for (int i = 0; tree->args_array[i] != NULL; i++) {
// 				printf("arg[%d] = %s ", i, tree->args_array[i]);
// 			}
// 			printf("\n");
// 		}
// 	}
// 	if (tree->left)
// 	{
// 		for (int i = 0; i <= depth; i++)
// 			printf("\t");
// 		printf("Left child of above node:\n");
// 		print_tree(tree->left, depth + 1);
// 	}
// 	if (tree->right)
// 	{
// 		for (int i = 0; i <= depth; i++)
// 			printf("\t");
// 		printf("Right child of above node:\n");
// 		print_tree(tree->right, depth + 1);
// 	}
// }
