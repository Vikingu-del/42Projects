/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delim_append_errors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:10:34 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/04 20:11:32 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_first_half_delim(t_token *token)
{
	if ((token->next->type == T_SPACE && token->next->next->type == T_WORD)
		|| token->next->type == T_WORD)
		return (0);
	if (token->next->type != T_SPACE)
	{
		if (token->next->type == T_IN_OUT)
		{
			if (token->next->next->type == T_AMPER
				|| token->next->next->type == T_AND)
				return (printf("minishell: syntax error near %s\n", \
				"unexpected token `>&'"), 1);
			if (token->next->next->type == T_PIPE
				|| token->next->next->type == T_OR)
				return (printf("minishell: syntax error near %s\n", \
				"unexpected token `>|'"), 1);
			if (token->next->next->type != T_NEWLINE
				&& token->next->next->type != T_SPACE)
				return (printf("minishell: syntax error near %s\n", \
				"unexpected token `>>'"), 1);
			else
				return (printf("minishell: syntax error near %s\n", \
				"unexpected token `>'"), 1);
		}
	}
	return (0);
}

int	check_second_half_delim(t_token *token)
{
	if (token->next->type == T_SPACE)
	{
		if (check_red_general(token->next))
			return (1);
	}
	else
		if (check_red_general(token))
			return (1);
	return (0);
}

int	check_delim(t_token *token)
{
	int	result;

	if (token->type == T_DELIM)
	{
		result = check_first_half_delim(token);
		if (result != 0)
			return (result);
		result = check_second_half_delim(token);
		if (result != 0)
			return (result);
	}
	return (0);
}

int	check_append(t_token *token)
{
	if (token->type == T_APPEND)
	{
		if ((token->next->type == T_SPACE && token->next->next->type == T_WORD)
			|| token->next->type == T_WORD)
			return (0);
		if (token->next->type != T_SPACE)
			if (check_red_general(token))
				return (1);
		if (check_red_general(token->next))
			return (1);
	}
	return (0);
}
