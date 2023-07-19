# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 18:21:43 by eseferi           #+#    #+#              #
#    Updated: 2023/02/12 16:40:57 by eseferi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

SRCS = src/main.c src/ft_util.c src/ft_rush02.c

OBJS = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra 

${NAME}: ${OBJS}
		@cc -o ${NAME} ${SRCS} -Iincludes ${CFLAGS}

clean:
		@rm -f ${OBJC}  

fclean: clean   
		@rm -f ${NAME}

re: fclean all  

.PHONY: all clean fclean
