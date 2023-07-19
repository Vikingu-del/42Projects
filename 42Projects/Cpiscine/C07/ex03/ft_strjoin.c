/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:22:23 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/16 12:58:31 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_size_strings(int size, char **strs)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < size)
	{
		sum += ft_strlen(strs[i]);
		i++;
	}
	return (sum);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*fstr;
	int		i;
	int		j;
	int		k;

	fstr = (char *)malloc(sizeof(char)
			* ((ft_strlen(sep) * (size - 1)) + ft_size_strings(size, strs)) + 1);
	if (fstr == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			fstr[k++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
			fstr[k++] = sep[j++];
		i++;
	}
	fstr[k] = '\0';
	return (fstr);
}
int main(void)
{
	char *strs[] = {"hello worldahpfaowiggslk ", "the fucking word", "Wayne", "erik", "Arpit"};
	char sep[] = "{Arpit_erik_ivan_denis}";
	char *final_str = ft_strjoin(0, strs, sep);
	printf("%s", final_str);
	free(final_str);
	return (0);
}