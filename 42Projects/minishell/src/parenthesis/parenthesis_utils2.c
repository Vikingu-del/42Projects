/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:38:11 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 16:10:00 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_parenth_token(t_data *data, char *str, int *i, t_token **head)
{
	int	parencount;
	int	start;

	parencount = 1;
	start = *i;
	(*i)++;
	while (str[*i] && parencount > 0)
	{
		if (str[*i] == '(' && !in_quotes(str, *i))
			parencount++;
		else if (str[*i] == ')' && !in_quotes(str, *i))
			parencount--;
		if (parencount == 0)
		{
			data->count = *i - start - 1;
			add_token(head, create_parenth_token(data, start, str));
		}
		if (parencount > 0)
			(*i)++;
	}
	return (parencount);
}

t_token	*create_parenth_token(t_data *data, int i, char *input)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		exit_shell("Error: malloc failed\n", 1, data);
	new->word = ft_substr(input, i + 1, data->count);
	if (!new->word)
		new->word = ft_strdup("");
	new->type = T_PARENTHESES;
	data->count = 0;
	return (new);
}

int	set_token_parenth(t_data *data)
{
	t_token	*head;

	head = data->token_list;
	while (data->token_list)
	{
		set_token_parenth2(data->token_list);
		data->token_list = data->token_list->next;
	}
	data->token_list = head;
	clean_null_tokens(&data->token_list);
	fix_tokens(&data->token_list, data);
	if (syntax_error_parenth(&data->token_list))
		return (1);
	return (0);
}

int	find_token3(t_data *data, char *str, int *i, t_token **head)
{
	if (is_chr_str(str[*i], " \t(") && !in_quotes(str, *i)
		&& !is_escaped(str, *i - 1))
	{
		add_token(head, create_token(data, *i));
		if (str[*i] == ' ' || str[*i] == '\t')
			add_token(head, create_arg_token(data, " ", T_SPACE));
		else if (str[*i] == '(')
			(*i)--;
		(*i)++;
		data->count = 0;
		return (0);
	}
	else if (is_chr_str(str[*i], "|<>&$") && !in_quotes(str, *i)
		&& !is_escaped(str, *i - 1) && *i > 0
		&& !is_chr_str(str[*i - 1], "|<>&$"))
		add_token(head, create_token(data, *i));
	return (1);
}

void	set_token_parenth2(t_token *token)
{
	t_token	*head;

	head = token;
	if (!ft_strcmp(token->word, "<"))
		token->type = T_RED_INP;
	else if (!ft_strcmp(token->word, ">"))
		token->type = T_RED_OUT;
	else if (!ft_strcmp(token->word, "|"))
		token->type = T_PIPE;
	else if (!ft_strcmp(token->word, "$"))
		token->type = T_DOLLAR;
	else if (!ft_strcmp(token->word, " "))
		token->type = T_SPACE;
	else if (!ft_strcmp(token->word, "&"))
		token->type = T_AMPER;
	else if (token->type != T_NEWLINE && token->type != T_PARENTHESES)
		token->type = T_WORD;
	token = head;
}
