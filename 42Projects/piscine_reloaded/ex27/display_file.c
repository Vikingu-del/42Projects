/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:56:12 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/12 15:04:09 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (argc > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	display_file(argv[1]);
	return (0);
}
