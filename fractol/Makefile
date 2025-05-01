NAME        = fractol
BONUS       = fractol_bonus

# ==== Compiler ====
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -O3

# ==== Sources ====
SRC         = main.c mandelbrot.c init.c hooks.c utils.c julia.c error.c burning_ship.c render.c
SRC_BONUS   = main_bonus.c mandelbrot.c init.c hooks.c utils.c julia.c error.c burning_ship.c render.c

OBJ         = $(SRC:.c=.o)
OBJ_BONUS   = $(SRC_BONUS:.c=.o)

# ==== Library Directories ====
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux

# ==== Libraries ====
LIBFT_A     = $(LIBFT_DIR)/libft.a
LIBFT       = -L$(LIBFT_DIR) -lft
MLX         = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDES    = -I$(LIBFT_DIR) -I$(MLX_DIR)

# ==== Silence Entering/Leaving ====
MAKEFLAGS  += --no-print-directory

# ==== Rules ====
all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJ) $(LIBFT_A)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(MLX) $(LIBFT) $(INCLUDES)
	@echo -e "\033[32m✔ $(NAME) created successfully\033[0m"

$(BONUS): $(OBJ_BONUS) $(LIBFT_A)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS) $(MLX) $(LIBFT) $(INCLUDES)
	@echo -e "\033[32m✔ $(BONUS) created successfully\033[0m"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo -e "\033[36m✔ libft.a built\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "\033[90m• Compiled $<\033[0m"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJ) $(OBJ_BONUS)
	@echo -e "\033[33m✘ $(NAME) object files removed\033[0m"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@echo -e "\033[33m✘ Executables removed\033[0m"

re: fclean all

.PHONY: all bonus clean fclean re
