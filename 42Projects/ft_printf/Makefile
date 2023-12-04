# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 16:39:31 by eseferi           #+#    #+#              #
#    Updated: 2023/12/04 17:51:41 by eseferi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -O3
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MAKE_LIB = ar -rcs

#-I <dir> Add directory to include search path
#By default, GCC will search for header files in the following directories:
#The directories specified in the built-in include directories (e.g. /usr/include or /usr/local/include on Linux systems).
#The current directory (.).
#The directories specified in the CPATH environment variable.
#"include directories"
INCS = .


SRCS = ft_printf.c \
	   ft_putchar_utils.c \
	   ft_putstr_utils.c \
	   ft_flags_utils.c \
	   ft_format_utils.c \
	   ft_hex_utils.c \
	   ft_puthex_utils.c \
	   ft_putnbr_utils.c \
	   ft_putptr_utils.c \
	   ft_long_utils.c \
	   ft_percent_utils.c \
	   ft_right_combination_utils.c \
	   ft_left_combination_utils.c \
	   ft_hexcombos_utils.c \

OBJS = $(SRCS:.c=.o)

bonus : all

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) 
	$(MAKE_LIB) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -I$(INCS) 
	
$(LIBFT) :
	cd $(LIBFT_PATH) && make 
	cp $(LIBFT) $(NAME) 

clean :
	rm -rf $(OBJS)
	cd $(LIBFT_PATH) && make clean

fclean : clean
	rm -rf $(NAME)
	cd $(LIBFT_PATH) && make fclean

clout :
	rm -rf a.out

re: fclean all

.PHONY: all bonus clean fclean re clout
