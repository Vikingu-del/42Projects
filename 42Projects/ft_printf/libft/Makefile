# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/19 16:06:16 by eseferi           #+#    #+#              #
#    Updated: 2023/06/01 15:36:43 by eseferi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
FLAGS = -c -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c ft_striteri.c
BON = ft_lstadd_front.c ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)
OBJ_BON = $(BON:.c=.o)
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

bonus: clean
	$(CC) $(FLAGS) $(BON)
	ar rc $(NAME) *.o
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BON)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re