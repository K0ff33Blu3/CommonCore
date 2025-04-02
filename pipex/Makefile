NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = pipex.c find_cmd_path.c str_split.c str_split_utils.c pipex_utils.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = pipex_bonus.c find_cmd_path.c str_split.c str_split_utils.c pipex_utils.c docs.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $^ -o $@ -Llibft -lft
	@echo -e "\033[32m$(NAME) created successfully\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) -g -c $? -o $@


clean:
	make -C libft clean
	rm -f $(OBJS) $(OBJS_BONUS)
	@echo -e "\033[32mObject files removed successfully\033[0m"

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	@echo -e "\033[32m$(NAME) removed successfully\033[0m"

bonus : fclean
	make -C libft
	$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME) -Llibft -lft
	@echo -e "\033[32m$(NAME) created successfully\033[0m"

re: fclean all

.PHONY: all clean fclean re only