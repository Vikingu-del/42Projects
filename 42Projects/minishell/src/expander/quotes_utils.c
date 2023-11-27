/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:04:19 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/23 17:43:57 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_escaped(char *s, int pos)
{
	int	n;

	n = 0;
	while (pos >= 0 && s[pos] == '\\')
	{
		n++;
		pos--;
	}
	return (n % 2);
}

char	first_quote(char *str)
{
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
			return (*str);
		str++;
	}
	return (0);
}

int	special_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '\\' || str[i] == ';') && !in_quotes(str, i))
		{
			printf("minishell: we should not handle `%c'\n", str[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

int	has_quotes(char *str)
{
	while (*str)
	{
		if (*str == '\"' || *str == '\'')
			return (1);
		str++;
	}
	return (0);
}

int	has_dollar(char *str)
{
	while (*str)
	{
		if (*str == '$')
			return (1);
		str++;
	}
	return (0);
}
