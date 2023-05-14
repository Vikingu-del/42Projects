/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 02:18:38 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/10 13:01:58 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*new_str;

	len = 0;
	while (src[len])
		len++;
	len++;
	new_str = (char *) malloc(len * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (*(src + i))
	{
		*(new_str + i) = *(src + i);
		i++;
	}
	*(new_str + i) = '\0';
	return (new_str);
}

/*
#include <stdio.h>

int main(void) {
    char *str = "Hello, world!";
    char *new_str = ft_strdup(str);
    
    if (new_str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Original string: %s\n", str);
    printf("Duplicated string: %s\n", new_str);
    
    free(new_str);
    
    return 0;
}
*/