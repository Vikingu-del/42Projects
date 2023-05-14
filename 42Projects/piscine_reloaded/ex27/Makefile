# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 14:56:43 by eseferi           #+#    #+#              #
#    Updated: 2023/05/12 14:56:45 by eseferi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = ft_display_file

all: $(TARGET)

$(TARGET): ft_display_file.o display_file.o
	$(CC) $(CFLAGS) -o $(TARGET) ft_display_file.o display_file.o

ft_display_file.o: ft_display_file.c display_file.h
	$(CC) $(CFLAGS) -c ft_display_file.c

display_file.o: display_file.c display_file.h
	$(CC) $(CFLAGS) -c display_file.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
