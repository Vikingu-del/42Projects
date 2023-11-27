/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:13:32 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/23 18:04:31 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_env_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

void	find_quotes(char **str, t_data *data)
{
	char	*temp;

	temp = NULL;
	while (*str)
	{
		if (has_quotes(*str) || has_dollar(*str))
		{
			temp = expand_quotes(data, *str);
			if (!temp)
				return ;
			ft_strdel(&(*str));
			*str = ft_strdup(temp);
			ft_strdel(&temp);
		}
		str++;
	}
}

int	check_double_quote(char *s, int *i, int pos)
{
	int	double_q;
	int	j;

	j = *i + 1;
	double_q = 1;
	while (s[j])
	{
		if (s[j] == '\"')
		{
			double_q = 0;
			if (pos > *i && pos < j)
				return (2);
			else
				break ;
		}
		else
			j++;
	}
	*i = j;
	return (double_q);
}

int	check_single_quote(char *s, int *i, int pos)
{
	int	single_q;
	int	j;

	j = *i + 1;
	single_q = 1;
	while (s[j])
	{
		if (s[j] == '\'')
		{
			single_q = 0;
			if (pos > *i && pos < j)
				return (1);
			else
				break ;
		}
		else
			j++;
	}
	*i = j;
	return (single_q);
}

int	in_quotes(char *s, int pos)
{
	int	i;
	int	result;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\"' || s[i] == '\'')
		{
			if (s[i] == '\"')
			{
				result = check_double_quote(s, &i, pos);
				if (result != 0)
					return (result);
			}
			else if (s[i] == '\'')
			{
				result = check_single_quote(s, &i, pos);
				if (result != 0)
					return (result);
			}
		}
		i++;
	}
	return (0);
}
