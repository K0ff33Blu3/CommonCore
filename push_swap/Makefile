NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c push.c rotate.c rrotate.c radix_sort.c swap.c utils.c list_parse.c check_error.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $^ -o $@ -Llibft -lft -Llibft/ft_printf -lftprintf
	@echo -e "\033[32m\n$(NAME) created successfully\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C libft
	rm -f *.o
	@echo -e "\033[32m\nObject files removed successfully\033[0m"

fclean: clean
	$(MAKE) fclean -C libft
	rm -f $(NAME)
	@echo -e "\033[32m\n$(NAME) removed successfully\033[0m"
	
re: fclean all

.PHONY: all clean fclean re