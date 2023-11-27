/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:16:49 by ipetruni          #+#    #+#             */
/*   Updated: 2023/11/25 17:16:58 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_token(t_data *data, char *str, int *i, t_token **head)
{
	if (is_chr_str(str[*i], " \t") && !in_quotes(str, *i))
	{
		add_token(head, create_token(data, *i));
		if (str[*i] == ' ' || str[*i] == '\t')
			add_token(head, create_arg_token(data, " ", T_SPACE));
		(*i)++;
		data->count = 0;
		return (0);
	}
	else if (is_chr_str(str[*i], "|<>&") && !in_quotes(str, *i) && *i > 0
		&& !is_chr_str(str[*i - 1], "|<>&"))
		add_token(head, create_token(data, *i));
	return (1);
}

int	find_token2(int i, char *str, char *splt)
{
	if (is_chr_str(str[i], splt) && !in_quotes(str, i)
		&& !is_escaped(str, i - 1))
		return (1);
	return (0);
}
