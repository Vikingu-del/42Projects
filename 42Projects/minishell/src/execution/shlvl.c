/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:54:40 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/25 10:52:01 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_envir_value(t_envir *envir, char *new_value)
{
	ft_strdel(&envir->var_value);
	envir->var_value = new_value;
}

void	incr_shell_lvl(t_data *data)
{
	int		level;
	t_envir	*envir;

	if (!data->env_list)
		return ;
	envir = find_envir_variable(data, "SHLVL", ft_strlen("SHLVL"));
	if (envir->var_value)
	{
		level = ft_atoi(envir->var_value) + 1;
		if (level <= 999)
			update_envir_value(envir, ft_itoa(level));
		else if (level == 1000)
			update_envir_value(envir, ft_strdup(""));
		else
			update_envir_value(envir, ft_strdup("1"));
	}
}
