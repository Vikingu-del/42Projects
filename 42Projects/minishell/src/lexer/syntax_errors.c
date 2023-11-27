/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:25:43 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/19 16:21:52 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	syntax_errors(t_token *token, t_data *data)
{
	char	*str;
	int		i;

	i = 0;
	while (token)
	{
		str = check_first_token(&data->input_line[i], &i);
		if (str == NULL)
			return (0);
		while (token->type == T_WORD || token->type == T_SPACE)
			token = token->next;
		if (check_and(token, str))
			return (1);
		if (check_red(token, str))
			return (1);
		if (check_pipe_or(token))
			return (1);
		token = token->next;
	}
	return (0);
}

char	*check_first_half(char *str, int *i)
{
	if (*str == '|' && *(str + 1) == '|')
		return (*i += 2, "||");
	if (*str == '|')
		return (*i += 1, "|");
	if (*str == '<' && *(str + 1) == '>')
		return (*i += 2, "<>");
	if (*str == '<' && *(str + 1) == '<' && *(str + 2) == '<'
		&& *(str + 3) != '>')
		return (*i += 3, "<<<");
	if (*str == '>' && *(str + 1) == '>' && *(str + 2) == '>')
		return (*i += 3, ">>>");
	if (*str == '>' && *(str + 1) == '>')
		return (*i += 2, ">>");
	return (NULL);
}

char	*check_second_half(char *str, int *i)
{
	if (*str == '>')
		return (*i += 1, ">");
	if (*str == '<' && *(str + 1) == '<' && *(str + 2) != '>')
		return (*i += 2, "<<");
	if (*str == '<')
		return (*i += 1, "<");
	if (*str == '&' && *(str + 1) == '&')
		return (*i += 2, "&&");
	if (*str == '&')
		return (*i += 1, "&");
	return (NULL);
}

char	*check_first_token(char *str, int *i)
{
	char	*result;

	while (*str)
	{
		result = check_first_half(str, i);
		if (result != NULL)
			return (result);
		result = check_second_half(str, i);
		if (result != NULL)
			return (result);
		str++;
		(*i)++;
	}
	return (NULL);
}

int	check_and(t_token *token, char *str)
{
	if (!ft_strcmp(str, "&"))
	{
		if (token->next->type == T_RED_OUT
			&& token->next->next->type == T_SPACE)
			if (check_red_general(token->next->next))
				return (1);
		if (token->next->type == T_RED_OUT)
			if (check_red_general(token->next))
				return (1);
		return (printf("minishell: syntax error near %s\n", \
		"unexpected token `&'"), 1);
	}
	if (!ft_strcmp(str, "&&"))
		if ((token->type == T_AND && token->prev->type == T_AND)
			|| (token->type == T_AND && token->next->type == T_AND))
			return (printf("minishell: syntax error near %s\n", \
			"unexpected token `&&'"), 1);
	return (0);
}
