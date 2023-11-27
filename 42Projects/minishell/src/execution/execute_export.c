/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:20:00 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 12:58:26 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_export(t_data *data, t_tree *tree, int fd_out)
{
	t_envir	*sorted;

	if (!tree->args_array[1])
	{
		sorted = copy_and_sort_envir_list(data->env_list);
		ft_enviter(sorted, fd_out, print_env_node_sorted);
		return (ft_envclear(&sorted), 0);
	}
	else
		return (process_export_args(data, tree));
}

void	handle_existing_variable(t_envir *temp, char *var_value)
{
	ft_strdel(&temp->var_value);
	temp->var_value = ft_strdup(var_value);
	if (temp->visible == 1)
		temp->visible = 0;
}

void	handle_visible_variable(t_envir *temp)
{
	if (temp->visible == 0)
		temp->visible = 1;
	ft_strdel(&temp->var_value);
	temp->var_value = ft_strdup("");
}

void	handle_new_variable(t_envir **env_list, char *var_name, char *var_value)
{
	t_envir	*new_envir;

	new_envir = ft_envnew();
	new_envir->var_name = ft_strdup(var_name);
	if (!ft_strcmp(var_value, "visible"))
	{
		new_envir->visible = 1;
		new_envir->var_value = ft_strdup("");
		ft_envadd_back(env_list, new_envir);
	}
	else
	{
		new_envir->var_value = ft_strdup(var_value);
		ft_envadd_back(env_list, new_envir);
		new_envir->visible = 0;
	}
}

void	export(t_envir **env_list, char *var_name, char *var_value, \
	t_data *data)
{
	t_envir	*temp;

	temp = find_envir_variable(data, var_name, ft_strlen(var_name));
	if (temp && ft_strcmp(var_value, "visible"))
		handle_existing_variable(temp, var_value);
	else if (temp && !ft_strcmp(var_value, "visible"))
		handle_visible_variable(temp);
	else if (!temp)
		handle_new_variable(env_list, var_name, var_value);
}
