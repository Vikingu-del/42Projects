/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tree_roots.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 08:45:24 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 08:55:50 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*handle_token_type(t_token *token, int *pipe, t_token **pipetoken)
{
	if (token->type == T_OR || token->type == T_AND || token->type == T_PIPE)
	{
		if (token->type == T_OR)
			return (token);
		if (token->type == T_AND)
			return (token);
		if (token->type == T_PIPE)
		{
			*pipe = 1;
			*pipetoken = token;
		}
	}
	return (NULL);
}

t_token	*find_first_root(t_token **root_token)
{
	t_token	*token;
	t_token	*pipetoken;
	t_token	*result;
	int		pipe;

	token = *root_token;
	pipetoken = NULL;
	pipe = 0;
	while (token && token->next && token->next->type != T_NEWLINE)
	{
		result = handle_token_type(token, &pipe, &pipetoken);
		if (result != NULL)
			return (result);
		token = token->next;
	}
	if (pipe)
		return (pipetoken);
	return (*root_token);
}

t_token	*find_tree_root_right(t_token **root_token)
{
	t_token	*token;
	t_token	*pipetoken;
	t_token	*result;
	int		pipe;

	token = *root_token;
	pipetoken = NULL;
	pipe = 0;
	if (!token || !ft_strcmp(token->word, "boundary"))
		return (NULL);
	while (token && token->next && token->next->type != T_NEWLINE
		&& ft_strcmp(token->next->word, "boundary"))
	{
		result = handle_token_type(token, &pipe, &pipetoken);
		if (result != NULL)
			return (result);
		token = token->next;
	}
	if (pipe)
		return (pipetoken);
	return (*root_token);
}

t_token	*find_tree_root_left(t_token **root_token)
{
	t_token	*token;
	t_token	*pipetoken;
	t_token	*result;
	int		pipe;

	token = *root_token;
	pipetoken = NULL;
	pipe = 0;
	if (!token || !ft_strcmp(token->word, "boundary"))
		return (NULL);
	while (token != NULL && token->prev != NULL
		&& ft_strcmp(token->prev->word, "boundary"))
	{
		result = handle_token_type(token, &pipe, &pipetoken);
		if (result != NULL)
			return (result);
		token = token->prev;
	}
	if (pipe)
		return (pipetoken);
	return (token);
}
