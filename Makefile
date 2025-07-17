NAME := fractol
CC := cc
CFLAGS := -Wall -Werror -Wextra -g

# Library paths
MLX_DIR := MLX42
MLX_INC := $(MLX_DIR)/include
MLX_LIB := $(MLX_DIR)/build
MLX_LIBFILE := $(MLX_LIB)/libmlx42.a

LIBFT_DIR := Libft
LIBFT := $(LIBFT_DIR)/libft.a

PRINTF_DIR := Printf
PRINTF := $(PRINTF_DIR)/libftprintf.a

# Source files
SRCS := main.c hooks.c parsing.c init_fractol.c handle_error.c julia.c mandelbrot.c Burning_ship.c colors.c
OBJS := $(SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(MLX_LIBFILE) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(OBJS) $(LIBFT) $(PRINTF) -I $(MLX_INC) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -L $(MLX_LIB) -lmlx42 -lglfw \
		-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo \
		-o $(NAME)

%.o: %.c fractol.h
	@$(CC) $(CFLAGS) -I $(MLX_INC) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -c $< -o $@

$(MLX_LIBFILE):
	@git clone --recursive https://github.com/codam-coding-college/MLX42.git $(MLX_DIR) || true
	@cd $(MLX_DIR) && git submodule update --init --recursive
	@cmake -B $(MLX_LIB) -S $(MLX_DIR)
	@cmake --build $(MLX_LIB)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) -r $(MLX_DIR)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re