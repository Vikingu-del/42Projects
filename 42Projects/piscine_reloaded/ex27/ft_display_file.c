/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:56:34 by eseferi           #+#    #+#             */
/*   Updated: 2023/05/12 15:08:34 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

void	display_file(char *filename)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while ((bytes_read) > 0)
	{
		write(1, buffer, bytes_read);
	}
	if (bytes_read == -1)
	{
		write(2, "Cannot read file.\n", 18);
	}
	close(fd);
}
