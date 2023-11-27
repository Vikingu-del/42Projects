/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_general_errors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:47:59 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 12:10:42 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_first_half_general(t_token *tmp)
{
	if (check_numbers(tmp))
		return (1);
	if (tmp->next->type == T_THREE_OUT)
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `>>'"), 1);
	if (tmp->next->type == T_AMPER && tmp->next->next->type == T_RED_OUT)
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `&>'"), 1);
	if (tmp->next->type == T_APPEND && tmp->next->next->type == T_RED_OUT)
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `&>'"), 1);
	if (tmp->next->type == T_APPEND && tmp->next->next->type == T_RED_INP)
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `&'"), 1);
	return (0);
}

int	check_second_half_general(t_token *tmp)
{
	if (tmp->next->type == T_RED_INP && (tmp->next->next->type == T_AMPER
			|| tmp->next->next->type == T_AND))
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `<&'"), 1);
	if (tmp->next->type == T_RED_OUT && (tmp->next->next->type == T_AMPER
			|| tmp->next->next->type == T_AND))
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `>&'"), 1);
	if (tmp->next->type == T_RED_INP && tmp->next->next->type == T_RED_OUT)
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `<>'"), 1);
	if (tmp->next->type == T_RED_OUT && (tmp->next->next->type == T_PIPE
			|| tmp->next->next->type == T_OR))
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `>|'"), 1);
	if (tmp->next->type != T_WORD && tmp->type != T_OR && tmp->type != T_AND)
	{
		return (printf("minishell: syntax error near unexpected token `%s'\n", \
		tmp->next->word), 1);
	}
	return (0);
}

int	check_red_general(t_token *tmp)
{
	int	result;

	result = check_first_half_general(tmp);
	if (result != 0)
		return (result);
	result = check_second_half_general(tmp);
	if (result != 0)
		return (result);
	return (0);
}

int	check_inout(t_token *token)
{
	if (token->type == T_IN_OUT)
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

int	check_numbers(t_token *tmp)
{
	if (tmp->next->type == T_SPACE && tmp->next->next->type == T_WORD
		&& ft_has_only_digit(tmp->next->next->word)
		&& tmp->next->next->next->type != T_WORD)
		return (printf("minishell: syntax error near unexpected token `%s'\n", \
		tmp->next->next->word), 1);
	if (tmp->next->type == T_WORD && ft_has_only_digit(tmp->next->word)
		&& tmp->next->next->type != T_WORD)
		return (printf("minishell: syntax error near unexpected token `%s'\n", \
		tmp->next->word), 1);
	return (0);
}
