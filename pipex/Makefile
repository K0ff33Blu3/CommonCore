NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c find_cmd_path.c str_split.c str_split_utils.c pipex_utils.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = pipex_bonus.c find_cmd_path.c str_split.c str_split_utils.c pipex_utils.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $^ -o $@ -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) -g -c $? -o $@

bonus : $(OBJS_BONUS)
	make -C libft
	$(CC) $(CFLAGS) $^ -o $@ -Llibft -lft

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re only