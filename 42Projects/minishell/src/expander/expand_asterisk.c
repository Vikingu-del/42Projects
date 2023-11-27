/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_asterisk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:35:05 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 12:50:21 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_asterisk_token(t_token *token, t_data *data)
{
	char	*temp;
	int		i;

	i = 0;
	ft_strdel(&token->word);
	while (data->root_directory[i])
	{
		if (!token->word)
			token->word = ft_strjoin("", data->root_directory[i]);
		else
		{
			temp = ft_strjoin(token->word, data->root_directory[i]);
			ft_strdel(&token->word);
			token->word = temp;
		}
		temp = ft_strjoin(token->word, " ");
		ft_strdel(&token->word);
		token->word = temp;
		i++;
	}
}

void	extend_asterisk(t_token *token, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (is_only_asterisks(token->word))
		update_asterisk_token(token, data);
	else if (has_asterisk(token->word))
		check_matches(token, data->root_directory);
}

int	match_pattern(const char *pattern, const char *string)
{
	if (*pattern == '\0' && *string == '\0')
		return (1);
	if (*pattern == '*' && *(pattern + 1) != '\0' && *string == '\0')
		return (0);
	if (*pattern == *string)
		return (match_pattern(pattern + 1, string + 1));
	if (*pattern == '*')
		return (match_pattern(pattern + 1, string)
			|| match_pattern(pattern, string + 1));
	return (0);
}
