CC			:= gcc
CFLAGS		:= -g -O3 -Wall -Werror -Wextra
CLIENT_C	:= client.c
SERVER_C	:= server.c
CLIENT		:= client
SERVER		:= server
LIBFT_DIR	:= ft_printf
LIBFT		:= ft_printf/libftprintf.a
MAKE		:= make -C $(LIBFT_DIR)
MAKE_FCLEAN	:= make fclean -C $(LIBFT_DIR)
MAKE_CLEAN	:= make clean -C $(LIBFT_DIR)

# Colors:
DEF_COLOR	:= \033[0;39m
GRAY		:= \033[0;90m
RED			:= \033[0;91m
GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
MAGENTA		:= \033[0;95m
CYAN		:= \033[0;96m
WHITE		:= \033[0;97m

all:		$(LIBFT) $(CLIENT) $(SERVER)
$(LIBFT):
			@$(MAKE)

$(SERVER):	$(CLIENT)
			@$(CC) $(SERVER_C) $(LIBFT) -o $(SERVER)
			@printf "$(CYAN)$(GREEN)[SUCCESS]$(END) $(SERVER) ready. 🐣\n$(DEF_COLOR)"

$(CLIENT):
			@$(CC) $(CLIENT_C) $(LIBFT) -o $(CLIENT)
			@printf "$(GREEN)[SUCCESS]$(END) $(CLIENT) ready. 🐣\n"

fclean:
			@$(MAKE_FCLEAN)
			@rm -fr $(SERVER) $(CLIENT)
			@printf "$(MAGENTA)[INFO]$(END) $(CLIENT) and $(SERVER) removed.\n"

clean:
			@$(MAKE_CLEAN)
			@printf "$(MAGENTA)[INFO]$(END) object files removed.\n"

re:			fclean all

.PHONY:		all clean fclean re