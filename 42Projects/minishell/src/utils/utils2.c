/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:45:36 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/23 13:02:55 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ignore_spaces(char *input)
{
	while (*input == ' ' || (*input >= 9 && *input <= 13))
		input++;
	return (input);
}

int	is_only_ascii(char *str)
{
	while (*str)
		if (!ft_isascii(*str++))
			return (0);
	return (1);
}

char	**dup_2darray(char **array)
{
	int		i;
	char	**dup;

	i = 0;
	while (array[i] != NULL)
		i++;
	dup = (char **)malloc(sizeof(char *) * (i + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (array[i] != NULL)
	{
		dup[i] = ft_strdup(array[i]);
		if (dup[i] == NULL)
		{
			free_2darray(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

int	len_2darray(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	is_char_in_str(char c, char *str)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}
