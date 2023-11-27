/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redin_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:10:44 by ipetruni          #+#    #+#             */
/*   Updated: 2023/11/25 18:10:47 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_red(t_token *token, char *str)
{
	if (!ft_strcmp(str, ">>>"))
		if (check_threeout(token))
			return (1);
	if (!ft_strcmp(str, "<<<"))
		if (check_threein(token))
			return (1);
	if (!ft_strcmp(str, "<<"))
		if (check_delim(token))
			return (1);
	if (!ft_strcmp(str, ">>"))
		if (check_append(token))
			return (1);
	if (!ft_strcmp(str, "<"))
		if (check_red_in(token))
			return (1);
	if (!ft_strcmp(str, ">"))
		if (check_red_out(token))
			return (1);
	if (!ft_strcmp(str, "<>"))
		if (check_inout(token))
			return (1);
	return (0);
}

int	check_redin_first_half(t_token *token)
{
	if (token->next->type == T_IN_OUT)
	{
		if (token->next->next->type == T_PIPE
			|| token->next->next->type == T_OR)
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `<|'"), 1);
		if (token->next->next->type == T_AND
			|| token->next->next->type == T_AMPER)
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `<&'"), 1);
		if (token->next->next->type == T_RED_OUT
			|| token->next->next->type == T_APPEND
			|| token->next->next->type == T_THREE_OUT)
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `>>'"), 1);
		else
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `>'"), 1);
	}
	return (0);
}

int	check_redin_second_half(t_token *token)
{
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

int	check_redin_last_part(t_token *token)
{
	if (token->next->type == T_AMPER && token->next->next->type == T_SPACE
		&& token->next->next->next->type == T_WORD
		&& !ft_has_only_digit(token->next->next->next->word))
		return (printf("minishell: %s: ambiguous redirect\n", \
		token->next->next->next->word), 1);
	if (token->next->type == T_AMPER && token->next->next->type == T_WORD
		&& !ft_has_only_digit(token->next->next->word))
		return (printf("minishell: %s: ambiguous redirect\n", \
		token->next->next->word), 1);
	if (token->next->type == T_AMPER && token->next->next->type == T_SPACE)
		if (check_red_general(token->next->next))
			return (1);
	if (token->next->type == T_SPACE)
		if (check_red_general(token->next))
			return (1);
	if (token->next->type == T_AMPER && token->next->next->type != T_WORD)
		if (check_red_general(token->next))
			return (1);
	if (check_red_general(token))
		return (1);
	return (0);
}

int	check_red_in(t_token *token)
{
	int	result;

	result = 0;
	if (token->type == T_RED_INP)
	{
		if ((token->next->type == T_SPACE && token->next->next->type == T_WORD)
			|| token->next->type == T_WORD)
			return (0);
		result = check_redin_first_half(token);
		if (result != 0)
			return (result);
		result = check_redin_second_half(token);
		if (result != 0)
			return (result);
		result = check_redin_last_part(token);
		if (result != 0)
			return (result);
	}
	return (result);
}
