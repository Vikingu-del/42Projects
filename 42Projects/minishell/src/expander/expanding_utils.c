/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 06:40:25 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 12:59:38 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*process_squote(char *s, int *i, char *result)
{
	if (s[*i + 1] == '\'')
	{
		(*i)++;
		result = ft_strdup("");
	}
	else
		result = expand_single_quotes(s, i, result);
	return (result);
}

char	*process_dquote(t_data *data, char *s, int *i, char *result)
{
	if (s[*i + 1] == '\"')
	{
		(*i)++;
		result = ft_strdup("");
	}
	else
		result = expand_double_quotes(data, s, i, result);
	return (result);
}

int	has_asterisk(char *str)
{
	while (*str)
	{
		if (*str == '*')
			return (1);
		str++;
	}
	return (0);
}

char	*update_aster_temp(char *temp, char *root_directory_k)
{
	char	*old_temp;

	if (!temp)
		return (ft_strjoin("", root_directory_k));
	else
	{
		old_temp = temp;
		temp = ft_strjoin(temp, " ");
		ft_strdel(&old_temp);
		old_temp = temp;
		temp = ft_strjoin(temp, root_directory_k);
		ft_strdel(&old_temp);
	}
	return (temp);
}

void	check_matches(t_token *token, char **root_directory)
{
	char	*temp;
	int		k;

	temp = NULL;
	k = -1;
	if (!token || !root_directory)
		return ;
	while (root_directory[++k])
	{
		if (token->word && match_pattern(token->word, root_directory[k]))
			temp = update_aster_temp(temp, root_directory[k]);
	}
	if (temp)
	{
		if (token->word)
			ft_strdel(&token->word);
		token->word = ft_strdup(temp);
		ft_strdel(&temp);
	}
}
