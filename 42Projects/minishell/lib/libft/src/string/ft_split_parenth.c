/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_parenth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:05:49 by eseferi           #+#    #+#             */
/*   Updated: 2023/11/26 09:49:57 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countarr(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static int	ft_arrarr(char **arr, const char *s, char c, int str)
{
	int	ai;
	int	zi;

	ai = 0;
	zi = 0;
	while (s[zi])
	{
		if (s[zi] == c)
			ai = zi + 1;
		if (s[zi] != c && (s[zi + 1] == c || !s[zi + 1]))
		{
			arr[str] = ft_calloc((zi - ai + 2), sizeof(char));
			if (!arr[str])
			{
				while (str--)
					free(arr[str]);
				return (0);
			}
			ft_strlcpy(arr[str], s + ai, zi - ai + 2);
			str++;
		}
		zi++;
	}
	arr[str] = NULL;
	return (1);
}

static void	process_array_element(char **arr, int *i)
{
	char	*temp;

	if (arr[*i][0] == '\"' || arr[*i][0] == '\'')
	{
		temp = ft_substr(arr[*i], 1, ft_strlen(arr[*i]) - 2);
		ft_strdel(&arr[*i]);
		arr[*i] = ft_strdup(temp);
		free(temp);
	}
	(*i)++;
}

char	**ft_split_parenth(char const *s, char c)
{
	char	**arr;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	if (!s)
		return (NULL);
	arr = ft_calloc((ft_countarr(s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	if (!ft_arrarr(arr, s, c, 0))
	{
		free(arr);
		return (NULL);
	}
	while (arr[i])
		process_array_element(arr, &i);
	return (arr);
}
