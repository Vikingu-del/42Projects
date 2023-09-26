# Variables
# to test memory problems -g -fsanitize=address -fno-omit-frame-pointer
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Iinclude -Isrc -O3

RM					=	rm -rf
FDF					=	fdf
NAME				=	$(FDF)

# Libraries
LIBFT				=	libft.a
LIBFT_DIR			=	lib/libft
LIBFT_FILE			=	$(LIBFT_DIR)/$(LIBFT)
CFLAGS				+=	-I $(LIBFT_DIR)/include

FT_PRINTF			=	ft_printf.a
FT_PRINTF_DIR		=	lib/ft_printf
FT_PRINTF_FILE		=	$(FT_PRINTF_DIR)/$(FT_PRINTF)
CFLAGS				+=	-I $(FT_PRINTF_DIR)/include

MLX					=	libmlx.dylib
MLX_DIR				=	lib/mlx
MLX_FILE			=	$(MLX_DIR)/$(MLX)
CFLAGS				+=	-I $(MLX_DIR)
LDFLAGS				+=	-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

MAKE_LIB			=	make --no-print-directory -C

# Source and Object Files
FDF_INC				=	fdf.h
SRC_DIR				=	src
FDF_SRC				=	$(wildcard $(SRC_DIR)/*.c)
FDF_OBJ       = 		$(FDF_SRC:$(SRC_DIR)/%.c=obj/%.o)

# Rules
all:				$(FDF)

obj:
					mkdir -p obj

LIB					=	$(LIBFT_FILE) $(FT_PRINTF_FILE) $(MLX_FILE)

$(LIBFT_FILE):
					$(MAKE_LIB) $(LIBFT_DIR)

$(FT_PRINTF_FILE):
					$(MAKE_LIB) $(FT_PRINTF_DIR)

$(MLX_FILE):
					$(MAKE_LIB) $(MLX_DIR)

$(FDF):				obj $(LIB) $(FDF_OBJ)
					$(CC) $(CFLAGS) $(FDF_OBJ) $(LIB) -o $(FDF) $(LDFLAGS)

clean:
					$(MAKE_LIB) $(MLX_DIR) clean
					$(MAKE_LIB) $(LIBFT_DIR) clean
					$(MAKE_LIB) $(FT_PRINTF_DIR) clean
					$(RM) obj
fclean:
					$(MAKE_LIB) $(MLX_DIR) clean
					$(MAKE_LIB) $(LIBFT_DIR) fclean
					$(MAKE_LIB) $(FT_PRINTF_DIR) fclean
					$(RM) obj
					$(RM) $(FDF)


re:					fclean all

.PHONY:				all clean fclean re