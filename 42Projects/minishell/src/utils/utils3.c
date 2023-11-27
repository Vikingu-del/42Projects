/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:41:54 by ipetruni          #+#    #+#             */
/*   Updated: 2023/11/23 13:04:30 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	only_spaces_parenth(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '(' && str[i] != ')')
			return (0);
		i++;
	}
	return (1);
}

int	token_len(t_token *token)
{
	int	len;

	len = 0;
	while (token)
	{
		if (token->type != T_NEWLINE)
			len++;
		token = token->next;
	}
	return (len);
}
