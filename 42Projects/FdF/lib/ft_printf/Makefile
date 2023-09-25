# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 16:42:00 by eseferi           #+#    #+#              #
#    Updated: 2023/08/08 16:42:02 by eseferi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME		= ft_printf.a
CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -Isrc -Iinclude

# Paths and Files
VPATH		= src
SRCS		= ft_printf.c ft_print_nbr.c

OBJS		= $(addprefix obj/, $(SRCS:.c=.o))

# Rules
$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

obj:
			mkdir -p obj

obj/%.o:	%.c | obj
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			$(RM) obj

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.SILENT:

.PHONY:		all clean fclean re
