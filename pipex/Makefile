NAME        = pipex
BONUS_NAME  = pipex_bonus

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g

LIBFT_DIR   = libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

SRCS        = pipex.c find_cmd_path.c str_split.c str_split_utils.c pipex_utils.c docs.c
SRCS_BONUS  = pipex_bonus.c find_cmd_path.c str_split.c str_split_utils.c pipex_utils.c docs.c

OBJS        = $(SRCS:.c=.o)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

# Default
all: $(NAME)

# Compile base version
$(NAME): $(OBJS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $^ -o $@ -L$(LIBFT_DIR) -lft
	@echo -e "\033[32m$(NAME) created successfully!\033[0m"

# Compile bonus version
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT_LIB)
	@$(CC) $(CFLAGS) $^ -o $@ -L$(LIBFT_DIR) -lft
	@echo -e "\033[36m$(BONUS_NAME) compiled with bonus powers!\033[0m"

# Object compilation
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo -e "\033[90mCompiled $<\033[0m"

# Libft build
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

# Clean .o files
clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo -e "\033[33mObject files removed.\033[0m"

# Full clean
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) $(BONUS_NAME)
	@echo -e "\033[31mBinaries wiped.\033[0m"

# Full rebuild
re: fclean all

.PHONY: all clean fclean re bonus