/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:35:49 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/04 20:19:18 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_threein(t_token *token)
{
	if (token->type == T_THREE_IN)
	{
		if ((token->next->type == T_SPACE && token->next->next->type == T_WORD)
			|| token->next->type == T_WORD)
			return (0);
		if (token->next->type == T_SPACE)
			if (check_red_general(token->next))
				return (1);
		if (check_red_general(token))
			return (1);
	}
	return (0);
}

int	check_threeout(t_token *token)
{
	if (token->type == T_THREE_OUT)
	{
		if (token->next->type == T_APPEND || token->next->type == T_THREE_OUT
			|| token->next->type == T_RED_OUT)
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `>>'"), 1);
		else if (token->next->type == T_AMPER || token->next->type == T_AND)
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `>&'"), 1);
		else if (token->next->type == T_PIPE || token->next->type == T_OR)
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `>|'"), 1);
		else
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `>'"), 1);
	}
	return (0);
}

int	check_first_half_pipe_or(t_token *tmp)
{
	if (tmp->prev != NULL && tmp->type == T_OR && tmp->next->type == T_PIPE)
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `|'"), 1);
	if (tmp->type == T_OR && (tmp->next->type == T_NEWLINE
			|| tmp->prev == NULL))
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `||'"), 1);
	if (tmp->type == T_PIPE && (tmp->next->type == T_NEWLINE
			|| tmp->prev == NULL))
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `|'"), 1);
	if ((tmp->type == T_PIPE && tmp->prev->type == T_WORD
			&& tmp->prev->prev == NULL))
	{
		if (tmp->next->type == T_SPACE)
		{
			if (tmp->next->next->type == T_OR)
				return (printf("minishell: syntax error near %s\n", \
				"unexpected token `||'"), 1);
			if (tmp->next->next->type == T_PIPE)
				return (printf("minishell: syntax error near %s\n", \
				"unexpected token `|'"), 1);
		}
	}
	return (0);
}

int	check_second_half_pipe_or(t_token *tmp)
{
	if (tmp->type == T_OR && (tmp->prev->type == T_OR || tmp->next == NULL
			|| tmp->next->type == T_PIPE || tmp->next->type == T_OR))
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `||'"), 1);
	if ((tmp->type == T_APPEND || tmp->type == T_DELIM)
		&& tmp->next->type == T_OR && tmp->next->next->type == T_RED_OUT)
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `||'"), 1);
	return (0);
}

int	check_pipe_or(t_token *tmp)
{
	int	result;

	result = check_first_half_pipe_or(tmp);
	if (result != 0)
		return (result);
	result = check_second_half_pipe_or(tmp);
	if (result != 0)
		return (result);
	return (0);
}
