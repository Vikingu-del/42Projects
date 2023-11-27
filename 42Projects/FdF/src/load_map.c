/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:10:56 by eseferi           #+#    #+#             */
/*   Updated: 2023/10/05 15:36:06 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/ft_printf/include/ft_printf.h"
#include "../lib/libft/include/libft.h"
#include "../inc/defines.h"
#include "../inc/utils.h"
#include "../inc/draw_utils.h"
#include "../inc/map_utils.h"
#include "../inc/errors.h"
#include "../inc/geometry.h"
#include <strings.h>
#include <math.h>
#include <fcntl.h>

#define BLOCK_READ 500000

static	void	count_map_len(t_map *map);
static	void	parse_points(t_map *map);
static	char	*read_map(int fd);

/* 
*	Inicialize the structure
*	Get the length of map
*	Check if the map is valid
*	Read the map
*	Load each point to the structure
*/

void	load_map(t_map *map, char *file)
{
	int		fd;
	char	*suffix;

	init_map(map, 1);
	suffix = ft_substr(file, ft_strlen(file) - 4, 4);
	if (ft_strcmp(suffix, ".fdf") != 0)
	{
		free(suffix);
		exit_with_error(ERR_OPEN);
	}
	free(suffix);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_with_error(ERR_OPEN);
	map->content = read_map(fd);
	close(fd);
	count_map_len(map);
	parse_points(map);
	apply_color_scheme(map);
	cart_to_pol(map);
	ft_printf("\nOpening Window\n");
}

static char	*read_map(int fd)
{
	static int	byte_read = BLOCK_READ;
	static int	total_bytes = 0;
	char		*buffer;
	char		*temp;
	char		*map;

	buffer = ft_calloc(BLOCK_READ, sizeof(char));
	if (buffer == NULL)
		exit_with_error(ERR_MEM);
	map = ft_strdup("");
	ft_printf("\nLoading map... Please wait.\n\n");
	while (byte_read == BLOCK_READ)
	{	
		ft_bzero (buffer, BLOCK_READ);
		byte_read = read(fd, buffer, BLOCK_READ);
		temp = map;
		map = ft_strjoin(map, buffer);
		total_bytes += byte_read;
		ft_printf("\r %d kb reading", total_bytes / 1024);
		free(temp);
	}
	printf("\r 👍 %d kb readed \n", total_bytes / 1024);
	free(buffer);
	return (map);
}

/* 
*	Splits the info of line to storage
*	the points in the map->point array. 
*	Using map->len as index of the array
*/

static int	load_points(char *line, t_map *map, int numline)
{
	char		**point_elements;
	int			i;
	static int	i_point = 0;

	point_elements = ft_split(line, ' ');
	i = 0;
	while (point_elements[i])
	{
		if (!point_is_valid(&point_elements[i][0]))
			exit_with_error(ERR_EMPTY);
		map->points[i_point].coords[Z] = modified_atoi(&point_elements[i][0]);
		map->points[i_point].coords[X] = i - map->limits.coords[X] / 2;
		map->points[i_point].coords[Y] = numline - map->limits.coords[Y] / 2;
		map->points[i_point].paint = 1;
		map->points[i_point].color = DEFAULT_COLOR;
		map->points[i_point].hex_color = has_hexcolors (point_elements[i]);
		if (map->limits.coords[Z] < map->points[i_point].coords[Z])
			map->limits.coords[Z] = map->points[i_point].coords[Z];
		if (map->zmin > map->points[i_point].coords[Z])
			map->zmin = map->points[i_point].coords[Z];
		i++;
		i_point++;
	}
	free_2darray(point_elements);
	return (i);
}

/* 
*	This function determinates the max values x, y, z of the map
*	and terminate if the maps has different line sizes.
*/

static	void	count_map_len(t_map *map)
{
	static int	i = -1;
	static int	row_size = 0;	

	while (map->content[++i])
	{
		if (map->content[i] == '\n' && map->content[i + 1] == '\0')
			break ;
		if (ft_isalnum(map->content[i]) && \
			(map->content[i + 1] == ' ' || map->content[i + 1] == '\n' || \
			map->content[i + 1] == '\0'))
				row_size++;
		if (map->content[i] == '\n')
		{
			map->limits.coords[Y]++;
			if (map->limits.coords[X] != 0 && (map->limits.coords[X] != row_size))
				exit_with_error(ERR_LINE);
			else
				map->limits.coords[X] = row_size;
			row_size = 0;
		}
	}
	if (row_size > 0 && (map->limits.coords[X] != row_size))
		exit_with_error(ERR_LINE);
	map->limits.coords[Y]++;
	map->len = map->limits.coords[X] * map->limits.coords[Y];
}

static	void	parse_points(t_map *map)
{
	int			i;
	char		*line;
	char		*last_line;
	static int	num_points = 0;
	static int	num_line = 0;

	last_line = map->content;
	line = NULL;
	i = 0;
	map->points = ft_calloc (map->len, sizeof(t_point));
	while (++i)
	{
		if (map->content[i] == '\n' || map->content[i] == '\0')
		{
			free (line);
			line = ft_substr(last_line, 0, &map->content[i] - last_line);
			last_line = &map->content[i + 1];
			num_points += load_points(line, map, num_line++);
			ft_printf("\r 🕑 %d points reading...", num_points);
			if (map->content[i] == '\0')
				break ;
		}
	}
	free (line);
	ft_printf("\r 👍 %d points readed	\n", num_points);
}
