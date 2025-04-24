NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c mandelbrot.c init.c hooks.c utils.c julia.c

OBJ = $(SRC:.c=.o)

LIB_DIR = minilibx-linux

LIBFLAGS = -L$(LIB_DIR) -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIB_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBFLAGS)
	@echo -e "\033[32m$(NAME) created successfully\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -g -c $? -o $@

clean:
	rm -f $(OBJ)
	@echo -e "\033[32mObject files removed successfully\033[0m"

fclean: clean
	rm -f $(LIB_DIR)/*.a
	rm -f $(NAME)
	@echo -e "\033[32m$(NAME) removed successfully\033[0m"

re: fclean all

.PHONY: all clean fclean re