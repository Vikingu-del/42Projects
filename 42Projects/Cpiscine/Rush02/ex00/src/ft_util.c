/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsievier <hsievier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:29:59 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/12 17:57:05 by hsievier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dst;

	len = 0;
	while (src[len] != '\0')
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_atoi(const char *str)
{
	int	ind;
	int	nr;
	int	neg_nr;

	ind = 0;
	nr = 0;
	neg_nr = 0;
	while ((str[ind] >= 9 && str[ind] <= 13) || str[ind] == ' ')
		ind++;
	while (str[ind] == '-' || str[ind] == '+')
		if (str[ind++] == '-')
			neg_nr++;
	while (str[ind] >= '0' && str[ind] <= '9')
		nr = nr * 10 + (str[ind++] - '0');
	if (neg_nr % 2 == 1)
		return (nr * -1);
	return (nr);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
