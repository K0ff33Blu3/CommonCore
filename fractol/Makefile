NAME = fractol
BONUS = fractol_bonus

# ==== compiler ====
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3

# ==== source files ====
SRC = main.c mandelbrot.c init.c hooks.c nbr_utils.c julia.c error.c burning_ship.c render.c
SRC_BONUS = main_bonus.c mandelbrot.c init.c hooks.c nbr_utils.c julia.c error.c burning_ship.c render.c

OBJ		= $(SRC:.c=.o)
OBJ_BONUS	= $(SRC_BONUS:.c=.o)

# ==== library directory ====
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

# ==== libraries ====
LIBFT		= -L$(LIBFT_DIR) -lft
MLX		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES    = -I$(LIBFT_DIR) -I$(MLX_DIR)

# ==== rules ====
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $^ -o $@ $(MLX) $(LIBFT) $(INCLUDES)
	@echo -e "\033[32m$(NAME) created successfully\033[0m"

bonus: $(OBJ_BONUS) $(LIBFT)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $^ -o $(BONUS) $(MLX) $(LIBFT) $(INCLUDES)
	@echo -e "\033[32m$(BONUS) created successfully\033[0m"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "\033[90mCompiled $<\033[0m"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@echo -e "\033[32mObject files removed successfully\033[0m"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(NAME) $(BONUS)
	@echo -e "\033[32mExecutable removed successfully\033[0m"

re: fclean all

.PHONY: all bonus clean fclean re
