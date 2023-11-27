/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis_errors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:53:32 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/13 10:48:09 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_error_parenth(t_token **token)
{
	t_token	*head;
	int		result;

	head = *token;
	while (*token)
	{
		if ((*token)->type == T_PARENTHESES)
		{
			if (only_parenth((*token)->word))
				return (operand_error_parenth(only_parenth((*token)->word)));
			result = check_prev_token(token);
			if (result != 0)
				return (result);
			result = check_next_token(token);
			if (result != 0)
				return (result);
		}
		*token = (*token)->next;
	}
	*token = head;
	return (0);
}

int	check_prev_token(t_token **token)
{
	if ((!ft_strcmp((*token)->word, "") && (!(*token)->prev
				|| (*token)->prev->type != T_DOLLAR))
		|| ((*token)->prev && (*token)->prev->type == T_SPACE
			&& (*token)->prev->prev->type != T_OR
			&& (*token)->prev->prev->type != T_AND
			&& (*token)->prev->prev->type != T_PIPE
			&& (*token)->prev->prev->type != T_WORD))
		return (printf("minishell: syntax error near %s", \
		"unexpected token `)'\n"), 1);
	if ((*token)->prev && (((*token)->prev->type == T_SPACE
				&& (*token)->prev->prev->type == T_WORD)
			|| ((*token)->prev->type == T_WORD)))
		return (printf("minishell: syntax error near unexpected token `%s'\n", \
		(*token)->word), 1);
	return (0);
}

int	check_next_token(t_token **token)
{
	if ((*token)->next->type == T_PARENTHESES
		|| ((*token)->next->type == T_SPACE
			&& (*token)->next->next->type == T_PARENTHESES))
		return (printf("minishell: syntax error near %s", \
		"unexpected token `)'\n"), 1);
	if ((*token)->next->type == T_WORD)
		return (printf("minishell: syntax error near unexpected token `%s'\n", \
		(*token)->next->word), 1);
	if ((*token)->next->type == T_SPACE && (*token)->next->next->type == T_WORD)
		return (printf("minishell: syntax error near unexpected token `%s'\n", \
		(*token)->next->next->word), 1);
	return (0);
}
