# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/08 16:46:23 by eseferi           #+#    #+#              #
#    Updated: 2023/11/04 22:54:41 by eseferi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME			=	libft.a
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -Isrc -Iinclude
RM				=	rm -rf

# Paths and Files
VPATH			=	src:src/conversion:src/list:src/memory:src/output:src/string
SRCS 			= 	$(wildcard src/*.c src/conversion/*.c src/list/*.c src/memory/*.c src/output/*.c src/string/*.c)
							
OBJS			=	$(addprefix obj/,$(SRCS:.c=.o))

# Rules
$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)

obj:
				mkdir -p obj

obj/%.o:		%.c | obj
				mkdir -p $(dir $@)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) obj

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.SILENT:

.PHONY:			all clean fclean re
