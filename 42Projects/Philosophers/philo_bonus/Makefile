# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eseferi <eseferi@student.42wolfsburg.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 12:33:07 by eseferi           #+#    #+#              #
#    Updated: 2023/12/06 06:44:58 by eseferi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETUP OF THE PROGRAM

NAME = philo_bonus

# FILES AND PATH TO THEM

OBJ_DIR = obj/
SRC_DIR = src/

SRC  =  init main monitor routine threads utils put_in_fd\

# start_threads \
# philo_life \
# philo_actions \
# philo_utils \

SRCS =  $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC)))

# COMMANDS

CC = gcc 
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address -fno-omit-frame-pointer
LDFLAGS = -lpthread -lrt
RM = rm -rf

# Valgrind and Leaks
VALGRIND  = valgrind #--track-fds=yes --trace-children=yes
LEAKS	  = leaks --atExit --

all: $(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
			@echo "$(GREEN)$(NAME) was successfully created!$(DEFAULT)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c 
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) -I./includes -c $< -o $@


clean:
		@$(RM) $(OBJS)
		@$(RM) $(OBJ_DIR)
		@echo "$(YELLOW)philo objects files deleted!$(DEFAULT)"

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(RED)philo program and objects deleted!$(DEFAULT)"

re:    fclean all

# Valgrind testing
valgrind: $(NAME)
	$(VALGRIND) ./$(NAME)

# Leaks at exit testing
leaks: $(NAME)
	$(LEAKS) ./$(NAME)

.PHONY: all clean fclean re valgrind leaks

# COLORS DEFENITIONS

RED = \033[1;31m
DEFAULT = \033[0m
GREEN = \033[1;32m
BOLD = \033[1m
YELLOW = \033[1;33m