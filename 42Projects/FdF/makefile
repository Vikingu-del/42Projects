#Variables

NAME		:= fdf

SRC_DIR		:= src/
OBJ_DIR		:= obj/
CC			:= gcc
CFLAGS		:= -g -O3 -Wall -Werror -Wextra
#FSANITIZE	:= -fsanitize=address -g3
FSANITIZE	:= 
NOFLAGS		:= -g
RM			:= rm -f

INC		 		:= inc/
LIB				:= lib/
PRINTF_DIR		:= $(LIB)ft_printf/
PRINTF			:= $(PRINTF_DIR)libftprintf.a
MLX_DIR	:= $(LIB)minilibx_macos/
MLX		:= $(MLX_DIR)libmlx.dylib
MLXCC		:= -I mlx -L $(MLX_DIR) -lmlx
LIBFT_DIR	:= $(LIB)libft/
LIBFT	:= $(LIBFT_DIR)libft.a
HEADER := -I$(INC) -I$(PRINTF_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)
OPENGL			:= -framework OpenGL -framework AppKit

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	control_keys control_mouse control_utils draw_map draw_utils \
				draw_utils2 geometry geometry2 get_next_line load_map main   \
				map_utils map_utils2 matrix menu utils utils2

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS		= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
###

OBJF		=	.cache_exists

all:	makelibs
		@$(MAKE) $(NAME)

makelibs:	
	@$(MAKE) -C $(PRINTF_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)

-include 	${DEPS}
$(NAME):	$(OBJ)		
			@$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(PRINTF) $(LIBFT) $(MLXCC) $(OPENGL) -o $(NAME)		
			@echo "👉 $(BLUE)$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(PRINTF) $(MLXCC) $(OPENGL) -o $(NAME)$(DEF_COLOR)"
			@echo "$(GREEN)✨ FDF compiled!$(DEF_COLOR)"

bonus:		
			@$(MAKE) all
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
			@echo "🍩 $(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"	

$(LIBFT):
	@make -C $(LIBFT_DIR)
	

$(MLX):
	@make -C $(MLX_DIR)
	@echo "$(GREEN)MLX compiled!$(DEF_COLOR)"			

clean:
			@make clean -sC $(PRINTF_DIR)
			@echo "$(CYAN)ft_printf object and dependency files cleaned.$(DEF_COLOR)"
			@make clean -C $(MLX_DIR)
			@echo "$(CYAN)MLX object files cleaned.$(DEF_COLOR)"	
			$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)Fdf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			$(RM) -f $(NAME)
			@echo "$(CYAN)Fdf executable files cleaned!$(DEF_COLOR)"
			$(RM) -f $(MLX_DIR)libmlx.a
			@echo "$(CYAN)libmlx.a lib cleaned!$(DEF_COLOR)"			
			$(RM) -f $(LIBFT_DIR)libft.a
			@echo "$(CYAN)libft.a lib cleaned!$(DEF_COLOR)"


re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for Fdf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm