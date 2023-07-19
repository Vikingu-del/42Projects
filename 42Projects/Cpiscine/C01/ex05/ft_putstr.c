/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:10:22 by eseferi           #+#    #+#             */
/*   Updated: 2023/02/01 18:21:18 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		write(1, &str[count], 1);
		count = count + 1;
	}
}

/*int	main(void)
{
	ft_putstr("Albania");
	return (0);
}
*/