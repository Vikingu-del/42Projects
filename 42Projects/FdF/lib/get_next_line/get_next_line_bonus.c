/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:55:09 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/27 15:44:08 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_print_line(char *str_static)
{
	int		i;
	char	*line;

	i = 0;
	if (!str_static[i])
		return (NULL);
	while (str_static[i] != '\0' && str_static[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str_static[i] && str_static[i] != '\n')
	{
		line[i] = str_static[i];
		i++;
	}
	if (str_static[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}
/*
	- != \0 && \n -> its a line we can print
	- index + 2 (\n + \0)is the amount of bytes we have to allocate
	- if line has \n add and it's not EOF + add \0 to return the string
*/

char	*ft_next_buffer(char *str_static)
{
	int		i;
	char	*line;

	i = 0;
	while (str_static[i] && str_static[i] != '\n')
		i++;
	if (!str_static[i])
		return (free(str_static), NULL);
	line = (char *)malloc(sizeof(char) * (ft_strlen(str_static) - i + 1));
	if (!line)
		return (NULL);
	i++;
	ft_strcpy(line, &str_static[i]);
	return (free(str_static), line);
}
/*
	- index stores after while end position of the first line, if there was one
	- memory to allocate for new string is whole string - already returned line
	- increment index to get to first position of the next line 
		-> will be stored in line, free (str_static) no usage for it anymore
	- returns the new static that begins with the next line + rest
*/

char	*ft_read_buffer(int fd, char *str_static)
{
	int		buflen;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buflen = 1;
	while (!ft_strchr(str_static, '\n') && buflen != 0)
	{
		buflen = read(fd, buffer, BUFFER_SIZE);
		if (buflen == -1)
			return (free(buffer), free(str_static), NULL);
		buffer[buflen] = '\0';
		str_static = ft_strjoin(str_static, buffer);
	}
	return (free(buffer), str_static);
}
/*
	- buflen 1 at start and not 0 because if read returns it's empty
	- while buflen bigger than 0 -> read() reads something, 0 -> EOF
	- while strchr doesnt find a \n keep reading 
	- if read() returns -1, there is an error and free everything, no usage
		anymore
	- add \0 because otherwise the buffer won't have none
	- return of strjoin() is the new static string, because it's attaches 
		the new red buffer to the static buffer/string
	- frees buffer no usage anymore + returns the new static string 
		(cotains recently red data)
*/

char	*get_next_line(int fd)
{
	static char	*str_static[1024];
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1023)
		return (0);
	str_static[fd] = ft_read_buffer(fd, str_static[fd]);
	if (!str_static[fd])
		return (NULL);
	s = ft_print_line(str_static[fd]);
	str_static[fd] = ft_next_buffer(str_static[fd]);
	return (s);
}
/*
	- static acts like a global variable between the functions
		because we don't know the size of the BUFFERSIZE, so we have to 
		assume that it won't be the perfect size of each line, therefore 
		we have to store the data somewhere and check if there is a new 
		line in it, if so return the line and update the static by cutting
		out the the line we recently displayed/returned, max amount of fd
		running the same time is 1024. The static is a 2D array where the index
		stores the the static of the related fd
	- if fd smaller 0 is an error and BUFFERSIZE can't be less than 0 and
		if fd bigger than 1023 more than the maximum (starts at 0)
	- it basically does the same as the regular GNL, but you always have the tell
		the maschine from which fd we are reading and using the static
		of the that specific fd to read the data into it. All oerations are the same
		but you only have be sure to use the right fd and the realted static of course
	- ft_next_buffer() updates the static 
	- returns the the line 
*/
