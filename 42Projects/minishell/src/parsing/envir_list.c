/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envir_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:20:21 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/23 18:29:58 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int	find_equal_sign(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (i);
}

void	extract_env_var(t_envir *envir, char *env)
{
	unsigned int	i;
	size_t			len;

	i = find_equal_sign(env);
	len = ft_strlen(env);
	envir->var_name = ft_substr(env, 0, i);
	envir->var_value = ft_substr(env, i + 1, len - i);
}

t_envir	*fill_env(char **env, t_data *data)
{
	t_envir			*envir;
	t_envir			*head;

	if (!*env)
		return (NULL);
	envir = ft_envnew();
	head = envir;
	while (*env)
	{
		extract_env_var(envir, *env);
		env++;
		if (*env)
		{
			envir->next = ft_envnew();
			envir->next->prev = envir;
			envir = envir->next;
		}
	}
	data->env_list = head;
	return (head);
}
