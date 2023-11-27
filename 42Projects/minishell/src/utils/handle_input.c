/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:30:53 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/13 16:54:07 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_parsed_input(char *command)
{
	if (command != NULL)
		printf("Command: %s\n", command);
	else
		printf("Failed to parse the input.\n");
}

int	is_valid_env(char *str)
{
	int	i;
	int	eq_sign;

	i = 0;
	eq_sign = 0;
	while (str[i])
	{
		if (i == 0 && (ft_isdigit(str[i] || str[i] == '=')))
			return (0);
		if (!ft_isalnum(str[i] && str[i] != '_' && str[i] != '=')
			&& str[i] != '+' && str[i] != '\'' && str[i] != '\"')
			return (0);
		if ((str[i] == '\'' || str[i] == '\"') && eq_sign < 1)
			return (0);
		if (str[i] == '=')
			eq_sign++;
		i++;
	}
	if (eq_sign)
		return (1);
	return (0);
}

int	is_valid_env2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && ft_isdigit(str[i]))
			return (0);
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
