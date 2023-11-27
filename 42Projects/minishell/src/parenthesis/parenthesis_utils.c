/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parentheses_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:20:05 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/04 18:36:59 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	only_parenth(char *str)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	if (only_spaces_parenth(str))
		flag = 1;
	while (*str)
	{
		if (*str == '(')
			count++;
		str++;
	}
	if (count == 1)
		return (0);
	else if (flag == 1)
		return (count);
	else
		return (0);
}

int	operand_error_parenth(int i)
{
	int	j;
	int	z;

	i -= 2;
	j = i;
	z = i;
	printf("minishell: ((: ");
	while (i-- >= 0)
		printf("%c", '(');
	while (z-- >= 0)
		printf("%c", ')');
	printf(": syntax error: operand expected (error token is \"");
	while (j-- >= 0)
		printf("%c", ')');
	printf("\")\n");
	return (1);
}

int	count_parenthesis(char *str, int *parenCount, int *parenth_total)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '(' && !in_quotes(str, i))
		{
			(*parenth_total)++;
			(*parenCount)++;
		}
		else if (str[i] == ')' && !in_quotes(str, i))
		{
			(*parenCount)--;
			(*parenth_total)++;
		}
		i++;
	}
	return (i);
}

int	check_parenthesis(int parenCount, int parenth_total)
{
	if (parenth_total > 0)
	{
		if (parenCount == 0)
			return (1);
		else
			return (printf("minishell: we don't have to handle unclose %s\n", \
			"parenthesis"), 2);
	}
	return (0);
}

int	find_parenthesis(char *str)
{
	int	paren_count;
	int	parenth_total;

	paren_count = 0;
	parenth_total = 0;
	count_parenthesis(str, &paren_count, &parenth_total);
	return (check_parenthesis(paren_count, parenth_total));
}
