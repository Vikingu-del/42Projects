/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:17:44 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 06:50:15 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_quotes(t_quote_info *qi)
{
	if (qi->str[qi->i] == '\'' && qi->d_quo == 0)
		qi->s_quo = 1 - qi->s_quo;
	else if (qi->str[qi->i] == '\"' && qi->s_quo == 0)
		qi->d_quo = 1 - qi->d_quo;
	return (0);
}

static int	handle_un_q(t_quote_info *qi)
{
	if ((qi->s_quo == 1 && qi->str[qi->i] == '\''
			&& qi->i > 0 && qi->str[qi->i - 1] != '\\'
			&& qi->s_quo % 2 == 0)
		|| (qi->d_quo == 1 && qi->str[qi->i] == '\"'
			&& qi->i > 0 && qi->str[qi->i - 1] != '\\'
			&& qi->d_quo % 2 == 0))
	{
		printf("%s%s\n", "minishell: handling of unclosed quotes, ",
			"is not required by subject");
		ft_strdel(&qi->str);
		qi->data->exit_status = 255;
		return (1);
	}
	return (0);
}

static int	handle_rem_q(t_quote_info *qi)
{
	if (qi->s_quo != 0 || qi->d_quo != 0)
	{
		ft_strdel(&qi->str);
		printf("%s", "minishell: handling of unclosed quotes ");
		printf("%s\n", "is not required by subject");
		qi->data->exit_status = 255;
		return (1);
	}
	return (0);
}

int	odd_quote(char *str, t_data *data)
{
	int				i;
	t_quote_info	qi;

	i = 0;
	qi.s_quo = 0;
	qi.d_quo = 0;
	qi.str = str;
	qi.data = data;
	while (qi.str[i])
	{
		qi.i = i;
		check_quotes(&qi);
		if (handle_un_q(&qi))
			return (1);
		i++;
	}
	if (handle_rem_q(&qi))
		return (1);
	return (0);
}
