/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:09:29 by eseferi           #+#    #+#             */
/*   Updated: 2023/09/27 01:39:25 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/include/libft.h"

#define BUFFER_SIZE 1000

static int	ft_linelen(char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\n' && *(s + i) != '\0')
		i++;
	if (*(s + i) == '\0')
		return (i);
	return (i + 1);
}

static char	*ft_extract_line(char *buffer)
{
	char	*line;
	int		size;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	size = ft_linelen(buffer) + 1;
	line = ft_calloc(size, sizeof (char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, buffer, size);
	return (line);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*new_buffer;
	char	*reading;
	int		byte_read;

	if (ft_strchr(buffer, '\n') != 0)
		return (buffer);
	reading = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (reading == NULL)
		return (buffer);
	while (ft_strchr(reading, '\n') == 0)
	{
		byte_read = read(fd, reading, BUFFER_SIZE);
		if (byte_read < 1)
			break ;
		reading[byte_read] = '\0';
		new_buffer = ft_strjoin(buffer, reading);
		free (buffer);
		buffer = new_buffer;
	}
	free (reading);
	return (buffer);
}

static char	*ft_remove_line(char *buffer)
{
	int		start;
	char	*newbuffer;
	int		i;

	if (!buffer)
		return (NULL);
	if (buffer[0] == '\0')
	{
		free (buffer);
		return (NULL);
	}
	start = ft_linelen(buffer);
	newbuffer = ft_calloc (ft_strlen(buffer) - start + 1, sizeof (char));
	if (newbuffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[start + i] != '\0')
	{
		newbuffer[i] = buffer[start + i];
		i++;
	}
	newbuffer[i] = buffer[start + i];
	free (buffer);
	return (newbuffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	if (read(fd, 0, 0) < 0 && !buffer[fd])
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(1, 1);
	if (buffer[fd] == NULL)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	line = ft_extract_line(buffer[fd]);
	buffer[fd] = ft_remove_line(buffer[fd]);
	return (line);
}