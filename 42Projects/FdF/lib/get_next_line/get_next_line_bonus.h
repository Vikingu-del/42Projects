/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:55:20 by eseferi           #+#    #+#             */
/*   Updated: 2023/06/27 15:36:05 by eseferi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t			ft_strlen(char *str);

char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *str_static, char *buffer);
char			*get_next_line(int fd);
char			*ft_print_line(char *str_static);
char			*ft_next_buffer(char *str_static);
char			*ft_strcpy(char *dest, char *src);
char			*ft_read_buffer(int fd, char *str_static);

#endif
