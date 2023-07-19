# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 01:21:58 by eseferi           #+#    #+#              #
#    Updated: 2023/02/16 04:02:31 by eseferi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c  srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OUTPUTS = srcs/ft_putchar.o srcs/ft_putstr.o  srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
HEAD = ./includes/
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rc
RM = rm -f
LIB = ranlib

all: ${NAME}

.c.o: 
				${CC} ${CFLAGS} -c -I ${HEAD}  $< -o ${<:.c=.o}

${NAME} : ${OUTPUTS}
				${AR} ${NAME} ${OUTPUTS}
				${LIB} ${NAME}

clean :
				rm -f ${OUTPUTS}

fclean : clean
				rm -f ${NAME}
				
re:				fclean all
				
.PHONY:			all clean fclean re