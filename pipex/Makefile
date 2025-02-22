NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c find_cmd_path.c str_split.c str_split_utils.c pipex_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $^ -o $@ -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) -g -c $? -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

only: re clean

.PHONY: all clean fclean re only