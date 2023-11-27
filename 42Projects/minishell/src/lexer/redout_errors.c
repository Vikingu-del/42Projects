/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redout_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:17:23 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/04 19:45:59 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_first_half_out(t_token *token)
{
	if (token->next->type == T_IN_OUT)
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `<>'"), 1);
	if (token->next->type == T_AND)
	{
		if (token->next->next->type == T_AMPER
			|| token->next->next->type == T_AND)
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `&&'"), 1);
		if (token->next->next->type == T_RED_OUT)
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `&>'"), 1);
		if (token->next->next->type != T_AMPER
			|| token->next->next->type == T_AND)
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `&'"), 1);
	}
	return (0);
}

int	check_second_half_out(t_token *token)
{
	if (token->next->type == T_OR && (token->next->next->type == T_PIPE
			|| token->next->next->type == T_OR))
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `||'"), 1);
	if (token->next->type == T_OR)
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `|'"), 1);
	return (0);
}

int	check_last_part_out(t_token *token)
{
	if (token->next->type == T_PIPE)
	{
		if (token->next->next->type == T_SPACE)
			if (check_red_general(token->next->next))
				return (1);
		if (check_red_general(token->next))
			return (1);
	}
	if (token->next->type == T_AMPER)
		if (check_red_general(token->next))
			return (1);
	if (token->next->type == T_SPACE)
		if (check_red_general(token->next))
			return (1);
	if (check_red_general(token))
		return (1);
	return (0);
}

int	check_red_out(t_token *token)
{
	int	result;

	result = 0;
	if (token->type == T_RED_OUT)
	{
		if ((token->next->type == T_SPACE && token->next->next->type == T_WORD)
			|| token->next->type == T_WORD)
			return (0);
		result = check_first_half_out(token);
		if (result != 0)
			return (result);
		result = check_second_half_out(token);
		if (result != 0)
			return (result);
		result = check_last_part_out(token);
		if (result != 0)
			return (result);
	}
	return (result);
}
