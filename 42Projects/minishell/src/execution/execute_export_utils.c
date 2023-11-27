/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:52:02 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 12:55:00 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_no_equal_sign(t_data *data, char *arg)
{
	if (has_asterisk(arg) || ft_isdigit(arg[0]))
		return (printf("minishell: export: `%s': not a valid identifier\n", \
		arg), 1);
	export(&data->env_list, arg, "visible", data);
	return (0);
}

int	handle_equal_sign(t_data *data, char *arg)
{
	char	**temp;
	int		result;

	temp = ft_split_parenth(arg, '=');
	result = 0;
	if (temp[1] && !temp[2])
	{
		if (has_asterisk(temp[0]) || ft_isdigit(temp[0][0]))
			return (printf("minishell: export: `%s=%s'", temp[0], temp[1]), \
			printf(": not a valid identifier\n"), free_2darray(temp), 1);
		else
			export(&data->env_list, temp[0], temp[1], data);
	}
	else if (temp[0] && !temp[1])
	{
		if (has_asterisk(temp[0]) || ft_isdigit(temp[0][0]))
			return (printf("minishell: export: `%s': not a valid identifier\n", \
			temp[0]), free_2darray(temp), 1);
		else
			export(&data->env_list, temp[0], "", data);
	}
	free_2darray(temp);
	return (result);
}

int	has_equal_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	process_export_args(t_data *data, t_tree *tree)
{
	int	i;

	i = 0;
	while (tree->args_array[++i])
	{
		if (!has_equal_sign(tree->args_array[i]))
		{
			if (handle_no_equal_sign(data, tree->args_array[i]))
				return (1);
		}
		else
		{
			if (handle_equal_sign(data, tree->args_array[i]))
				return (1);
		}
	}
	return (0);
}
